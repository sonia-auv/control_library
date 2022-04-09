#ifndef PROC_CONTROL__VISIBILITY_CONTROL_H_
#define PROC_CONTROL__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PROC_CONTROL_EXPORT __attribute__ ((dllexport))
    #define PROC_CONTROL_IMPORT __attribute__ ((dllimport))
  #else
    #define PROC_CONTROL_EXPORT __declspec(dllexport)
    #define PROC_CONTROL_IMPORT __declspec(dllimport)
  #endif
  #ifdef PROC_CONTROL_BUILDING_LIBRARY
    #define PROC_CONTROL_PUBLIC PROC_CONTROL_EXPORT
  #else
    #define PROC_CONTROL_PUBLIC PROC_CONTROL_IMPORT
  #endif
  #define PROC_CONTROL_PUBLIC_TYPE PROC_CONTROL_PUBLIC
  #define PROC_CONTROL_LOCAL
#else
  #define PROC_CONTROL_EXPORT __attribute__ ((visibility("default")))
  #define PROC_CONTROL_IMPORT
  #if __GNUC__ >= 4
    #define PROC_CONTROL_PUBLIC __attribute__ ((visibility("default")))
    #define PROC_CONTROL_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PROC_CONTROL_PUBLIC
    #define PROC_CONTROL_LOCAL
  #endif
  #define PROC_CONTROL_PUBLIC_TYPE
#endif
#endif  // PROC_CONTROL__VISIBILITY_CONTROL_H_
// Generated 07-Apr-2022 23:11:56
// Copyright 2019-2020 The MathWorks, Inc.
