// Copyright 2019-2021 The MathWorks, Inc.
// Generated 08-Sep-2021 14:46:35

#ifdef _MSC_VER

#pragma warning(push)
#pragma warning(disable : 4244)
#pragma warning(disable : 4265)
#pragma warning(disable : 4458)
#pragma warning(disable : 4100)
#pragma comment(lib, "Ws2_32.lib")

#else

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wredundant-decls"
#pragma GCC diagnostic ignored "-Wnon-virtual-dtor"
#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wshadow"

#endif                                 //_MSC_VER

#include "proc_control_node.h"
#include "rosnodeinterface.h"
#include <thread>
#include <chrono>
#include <utility>

namespace ros
{
  namespace matlab
  {
    NodeInterface::NodeInterface()
      : mNode()
      , mBaseRateSem()
      , mBaseRateThread()
      , mSchedulerThread()
      , mExtModeThread()
      , mStopSem()
      , mRunModel(true)
    {
    }

    NodeInterface::~NodeInterface()
    {
      terminate();
    }

    void NodeInterface::initialize(int argc, char ** argv)
    {
      try {
        mNode = std::make_shared<ros::NodeHandle>();
        ROS_INFO("** Starting the model \"proc_control_node\" **\n");

        {
          char* extmodeArg[] = { "-port", "17725", "-blocking", "1", "-verbose",
            "0" };

          rtExtModeParseArgs(6, (const char_T **)extmodeArg, NULL);
        }

        // initialize the model which will initialize the publishers and subscribers
        rtmSetErrorStatus(proc_control_node_M, (NULL));
        proc_control_node_initialize();

        /* External mode */
        rtSetTFinalForExtMode(&rtmGetTFinal(proc_control_node_M));
        rtExtModeCheckInit(5);

        {
          boolean_T rtmStopReq = false;
          rtExtModeWaitForStartPkt(proc_control_node_M->extModeInfo, 5,
            &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(proc_control_node_M, true);
          }
        }

        rtERTExtModeStartMsg();
        mExtModeThread = std::make_shared<std::thread>(&NodeInterface::
          extmodeBackgroundTask, this);

        // create the threads for the rates in the Model
        mBaseRateThread = std::make_shared<std::thread>(&NodeInterface::
          baseRateTask, this);

        // create scheduler thread
        mSchedulerThread = std::make_shared<std::thread>(&NodeInterface::
          schedulerThread, this);
      } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
        throw ex;
      }
    }

    int NodeInterface::run()
    {
      ros::spin();
      mRunModel = false;
      return 0;
    }

    boolean_T NodeInterface::getStopRequestedFlag(void)
    {

#ifndef rtmGetStopRequested

      return (!(rtmGetErrorStatus(proc_control_node_M)
                == (NULL)));

#else

      return (!(rtmGetErrorStatus(proc_control_node_M)
                == (NULL)) || rtmGetStopRequested(proc_control_node_M));

#endif

    }

    void NodeInterface::terminate(void)
    {
      if (mBaseRateThread.get()) {
        mBaseRateSem.notify();
        mBaseRateThread->join();
        mRunModel = false;
        mBaseRateThread.reset();
        if (mSchedulerThread.get()) {
          mSchedulerThread->join();
          mSchedulerThread.reset();
        }

        proc_control_node_terminate();
        rtExtModeShutdown(5);
        mNode.reset();
      }
    }

    //
    // Scheduler Task using ROS Wall clock timer to run base-rate
    //
    void NodeInterface::schedulerThread(void)
    {
      while (mRunModel) {
        std::this_thread::sleep_until(std::chrono::system_clock::now() + std::
          chrono::nanoseconds(16666667));
        mBaseRateSem.notify();
      }
    }

    // Base-rate task
    void NodeInterface::baseRateTask(void)
    {
      mRunModel = (rtmGetErrorStatus(proc_control_node_M) ==
                   (NULL));
      while (mRunModel) {
        mBaseRateSem.wait();

#ifdef MW_DEBUG_LOG

        ROS_INFO("** Base rate task semaphore received\n");

#endif

        if (!mRunModel)
          break;

        /* External mode */
        {
          boolean_T rtmStopReq = false;
          rtExtModePauseIfNeeded(proc_control_node_M->extModeInfo, 5,
            &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(proc_control_node_M, true);
          }

          if (rtmGetStopRequested(proc_control_node_M) == true) {
            rtmSetErrorStatus(proc_control_node_M, "Simulation finished");
            mRunModel = false;
            break;
          }
        }

        proc_control_node_step();
        rtExtModeCheckEndTrigger();
        mRunModel = !NodeInterface::getStopRequestedFlag();
      }

      // Shutdown the ROS node
      ros::shutdown();
    }

    void NodeInterface::extmodeBackgroundTask(void)
    {
      while (mRunModel) {
        /* External mode */
        {
          boolean_T rtmStopReq = false;
          rtExtModeOneStep(proc_control_node_M->extModeInfo, 5,
                           &rtmStopReq);
          if (rtmStopReq) {
            rtmSetStopRequested(proc_control_node_M, true);
          }
        }
      }
    }
  }                                    //namespace matlab
}                                      //namespace ros

#ifdef _MSC_VER

#pragma warning(pop)

#else

#pragma GCC diagnostic pop

#endif                                 //_MSC_VER
