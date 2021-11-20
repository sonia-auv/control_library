//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node_data.cpp
//
// Code generated for Simulink model 'proc_control_node'.
//
// Model version                  : 1.194
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Fri Nov 19 15:03:01 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LLP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "proc_control_node.h"
#include "proc_control_node_private.h"

// Block parameters (default storage)
proc_control_nodeModelClass::P_proc_control_node_T proc_control_nodeModelClass::
  proc_control_node_P = {
  // Variable: MPC
  //  Referenced by:
  //    '<S7>/Saturation'
  //    '<S132>/Constant1'
  //    '<S132>/Constant3'
  //    '<S133>/Constant1'
  //    '<S133>/Constant3'
  //    '<S136>/MPC manager'
  //    '<S286>/Constant3'
  //    '<S288>/Constant3'
  //    '<S289>/Constant3'

  {
    13.0,
    13.0,
    8.0,
    0.1,
    10.0,
    2.0,
    10.0,
    40.0,
    -30.0,

    {
      {
        { 70.0, 60.0, 70.0, 90.0, 90.0, 90.0, 90.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        },

        { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 },

        { 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 }
      },

      {
        { 30.0, 30.0, 30.0, 45.0, 45.0, 45.0, 45.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        },

        { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 },

        { 0.4, 0.4, 0.4, 0.4, 0.5, 0.5, 0.5, 0.5 }
      },

      {
        { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0
        },

        { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 },

        { 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 }
      }
    }
  },

  // Variable: physics
  //  Referenced by:
  //    '<S16>/Constant'
  //    '<S72>/Constant'
  //    '<S135>/MATLAB System'
  //    '<S238>/Constant'

  {
    31.0,
    0.0315,
    998.0,
    9.81,
    0.1435,
    0.3,

    { 0.4756, 0.008, 0.004, 0.008, 1.3735, -0.001, 0.004, -0.001, 1.5371 },

    { 0.001, 0.002, 0.018 },

    { 0.0, 0.0, -0.006 },

    { 15.0, 20.0, 23.333333333333332, 3.3333333333333335, 2.3333333333333335,
      5.0 },

    { 1.17, 0.82, 0.756, 0.167, 0.1, 0.102 },

    { 0.12, 0.22, 0.292 },

    { -1.4648, -12.6156, -15.7695, -0.1164, -0.3493, -0.3493 },

    { 0.0, -0.136, 0.178 }
  },

  // Variable: simulation
  //  Referenced by:
  //    '<S72>/ '
  //    '<S72>/  '

  {
    { 119U, 111U, 114U, 108U, 100U },

    { 97U, 117U, 118U, 56U }
  },

  // Variable: Config10
  //  Referenced by: '<S136>/MPC manager'

  { 30.0, 30.0, 30.0, 45.0, 45.0, 45.0, 45.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.2,
    0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.4, 0.4, 0.4, 0.4, 0.5, 0.5, 0.5, 0.5 },

  // Variable: Config19
  //  Referenced by: '<S136>/MPC manager'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 20.0, 20.0, 20.0, 20.0, 20.0, 20.0, 0.2,
    0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 },

  // Variable: N
  //  Referenced by:
  //    '<S7>/N to PWM'
  //    '<S13>/ PWM to N'

  { -39.921561783600005, -39.7361560536, -39.4691718024, -38.8907059248,
    -38.267742672, -37.956261045599994, -37.5112872936, -37.288800417600008,
    -36.7993292904, -36.4433502888, -35.8648844112, -35.1974237832,
    -34.5299631552, -33.8625025272, -33.328534024800007, -32.483083896000004,
    -31.9046180184, -31.4151468912, -30.480702012000002, -29.813241384,
    -29.368267632, -28.834299129600005, -28.077843751199996, -27.6773673744,
    -27.1878962472, -26.5649329944, -26.075461867200005, -25.319006488800007,
    -25.0075248624, -24.6070484856, -24.073079983200003, -23.361121980000004,
    -23.094137728800003, -22.337682350399998, -21.937205973599998,
    -21.5367295968, -20.780274218400002, -20.4242952168, -19.8458293392,
    -19.400855587200002, -19.0448765856, -18.243923832, -17.79895008,
    -17.309478952800003, -16.6865157, -16.375034073600002, -15.796568196,
    -15.262599693600002, -14.8621233168, -14.5951390656, -14.1056679384,
    -13.705191561600001, -13.215720434400001, -12.7707466824, -12.3257729304,
    -11.791804428, -11.3913280512, -10.9908516744, -10.812862173600001,
    -10.3233910464, -10.011909420000002, -9.6114330432000017, -9.2554540416,
    -8.8549776648, -8.5434960384, -8.0540249112, -7.6980459095999993,
    -7.2975695328, -7.0305852816000005, -6.67460628, -6.3631246536,
    -6.0516430272000008, -5.6956640256, -5.2951876488, -5.0282033976,
    -4.7167217712000005, -4.3607427696, -4.0937585184000005, -3.782276892,
    -3.4707952656000005, -3.1593136392, -2.8923293880000003, -2.5363503863999997,
    -2.3138635104, -2.0468792592000002, -1.7798950080000002, -1.4684133816000002,
    -1.2459265056000004, -1.0234396296000001, -0.84545012880000014, -0.667460628,
    -0.4894711272, -0.3559790016, -0.0007, -0.0006, -0.0005, -0.0004, -0.0003,
    -0.0002, -0.0001, 0.0, 0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006,
    0.0007, 0.4004763768, 0.5339685024, 0.7564553784000001, 0.9789422544,
    1.2459265056, 1.5129107568, 1.779895008, 2.1358740096, 2.4473556359999997,
    2.8478320128, 3.1593136392, 3.5152926408000003, 3.9157690176, 4.2717480192,
    4.6277270208, 5.0282033976, 5.4731771496, 5.9181509016, 6.2741299032,
    6.67460628, 7.0750826568, 7.6090511592000007, 8.009527536, 8.5434960384,
    8.89947504, 9.299951416799999, 9.7449251688, 10.145401545599999,
    10.7683647984, 11.213338550400001, 11.6138149272, 12.1477834296,
    12.5482598064, 13.037730933600002, 13.6161968112, 14.1056679384,
    14.5506416904, 15.084610192800001, 15.574081320000001, 16.197044572800003,
    16.5975209496, 17.2649815776, 17.887944830400002, 18.421913332800003,
    18.955881835200003, 19.534347712800002, 20.068316215200003,
    20.824771593600005, 21.358740096000005, 21.759216472800002,
    22.337682350400005, 23.361121980000004, 23.8505931072, 24.696043236000005,
    25.274509113600004, 26.030964492000006, 26.787419870400004,
    27.054404121600005, 27.855356875200005, 28.3448280024, 29.190278131200003,
    29.9467335096, 30.480702012000005, 31.103665264800004, 31.548639016800003,
    32.394089145600006, 33.1060471488, 33.5510209008, 34.4409684048,
    35.375413284000004, 36.1318686624, 36.6658371648, 37.4667899184,
    38.134250546400004, 38.801711174400005, 39.825150804, 40.670600932800006,
    41.738537937600007, 42.228009064800005, 42.984464443200004,
    44.230390948800007, 44.4083804496, 45.609809580000004, 46.188275457600007,
    46.944730836000005, 47.434201963199996, 48.368646842400004,
    49.169599596000005, 49.7925628488, 50.4600234768, 50.771505103200006,
    51.2164788552, 51.4537981896 },

  // Variable: Ui
  //  Referenced by: '<S136>/MPC manager'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Variable: binv
  //  Referenced by: '<S135>/MATLAB System'

  { 0.35355339059327379, 0.35355339059327379, 0.35355339059327384,
    0.35355339059327379, -0.11325966850828753, -0.11325966850828727,
    0.11325966850828718, 0.11325966850828745, -0.35355339059327384,
    0.35355339059327373, -0.35355339059327373, 0.35355339059327379,
    -0.12893081761006281, 0.128930817610063, 0.12893081761006286,
    -0.12893081761006295, 1.4543065414234989E-16, 1.6807543137987495E-16,
    1.73485928288418E-16, 1.3535796391773632E-16, -0.25000000000000611,
    0.24999999999999409, -0.24999999999999403, 0.25000000000000616,
    -1.5725561596033818E-16, 6.0446858017370254E-16, -9.9780905568484218E-17,
    -3.3355427083706572E-16, -1.5723270440251562, 1.5723270440251569,
    1.5723270440251567, -1.5723270440251562, 5.9525353991634417E-16,
    -4.3894899494290382E-16, -7.5899831345297663E-16, 5.3283447436302194E-16,
    1.3812154696132604, 1.3812154696132601, -1.3812154696132597,
    -1.3812154696132601, -0.76032987224359927, -0.76032987224359938,
    0.76032987224359916, 0.76032987224359971, -9.1672645525390172E-15,
    8.6123292209463532E-15, 9.14324666311198E-15, -9.1054869706790153E-15 },

  // Variable: constValues
  //  Referenced by: '<S136>/MPC manager'

  { 31.0, 0.0315, 0.3, 0.12, 0.22, 0.292, 0.4756, 0.008, 0.004, 0.008, 1.3735,
    -0.001, 0.004, -0.001, 1.5371, 0.001, 0.002, 0.018, 0.0, 0.0, -0.006, 15.0,
    20.0, 23.333333333333332, 3.3333333333333335, 2.3333333333333335, 5.0, 1.17,
    0.82, 0.756, 0.167, 0.1, 0.102, -1.4648, -12.6156, -15.7695, -0.1164,
    -0.3493, -0.3493, 998.0, 9.81 },

  // Variable: dMaxX
  //  Referenced by: '<S14>/X Drift'

  0.08263861448911336,

  // Variable: dMaxY
  //  Referenced by: '<S14>/Y Drift'

  1.2913940044227377,

  // Variable: dMinX
  //  Referenced by: '<S14>/X Drift'

  -0.094034493388244267,

  // Variable: dMinY
  //  Referenced by: '<S14>/Y Drift'

  -1.4548181822330102,

  // Variable: dSeedX
  //  Referenced by: '<S14>/X Drift'

  9.0,

  // Variable: dSeedY
  //  Referenced by: '<S14>/Y Drift'

  2.0,

  // Variable: dampA
  //  Referenced by: '<S14>/Constant'

  -0.4,

  // Variable: dampB
  //  Referenced by: '<S14>/Constant1'

  1.0,

  // Variable: ratioMax
  //  Referenced by: '<S14>/Saturation'

  1.0,

  // Variable: ratioMin
  //  Referenced by: '<S14>/Saturation'

  0.2,

  // Variable: waPhi
  //  Referenced by: '<S14>/Roll Wave'

  0.25,

  // Variable: waPsi
  //  Referenced by: '<S14>/Yaw Wave'

  0.25,

  // Variable: waTheta
  //  Referenced by: '<S14>/Pitch Wave'

  0.25,

  // Variable: waX
  //  Referenced by: '<S14>/X Wave'

  0.5,

  // Variable: waY
  //  Referenced by: '<S14>/Y Wave'

  1.0,

  // Variable: waZ
  //  Referenced by: '<S14>/Z Wave'

  1.5,

  // Variable: wfPhi
  //  Referenced by: '<S14>/Roll Wave'

  1.0471975511965976,

  // Variable: wfPsi
  //  Referenced by: '<S14>/Yaw Wave'

  1.0471975511965976,

  // Variable: wfTheta
  //  Referenced by: '<S14>/Pitch Wave'

  1.0471975511965976,

  // Variable: wfX
  //  Referenced by: '<S14>/X Wave'

  1.5707963267948966,

  // Variable: wfY
  //  Referenced by: '<S14>/Y Wave'

  1.5707963267948966,

  // Variable: wfZ
  //  Referenced by: '<S14>/Z Wave'

  1.5707963267948966,

  // Variable: wn_l
  //  Referenced by: '<S292>/Gain'

  1.5557249463348581,

  // Variable: wpPhi
  //  Referenced by: '<S14>/Roll Wave'

  0.0,

  // Variable: wpPsi
  //  Referenced by: '<S14>/Yaw Wave'

  3.1415926535897931,

  // Variable: wpTheta
  //  Referenced by: '<S14>/Pitch Wave'

  1.5707963267948966,

  // Variable: wpX
  //  Referenced by: '<S14>/X Wave'

  0.0,

  // Variable: wpY
  //  Referenced by: '<S14>/Y Wave'

  1.5707963267948966,

  // Variable: wpZ
  //  Referenced by: '<S14>/Z Wave'

  3.1415926535897931,

  // Variable: zeta_l
  //  Referenced by: '<S292>/Gain'

  0.99,

  // Variable: PWM
  //  Referenced by:
  //    '<S7>/N to PWM'
  //    '<S13>/ PWM to N'

  { 1100U, 1104U, 1108U, 1112U, 1116U, 1120U, 1124U, 1128U, 1132U, 1136U, 1140U,
    1144U, 1148U, 1152U, 1156U, 1160U, 1164U, 1168U, 1172U, 1176U, 1180U, 1184U,
    1188U, 1192U, 1196U, 1200U, 1204U, 1208U, 1212U, 1216U, 1220U, 1224U, 1228U,
    1232U, 1236U, 1240U, 1244U, 1248U, 1252U, 1256U, 1260U, 1264U, 1268U, 1272U,
    1276U, 1280U, 1284U, 1288U, 1292U, 1296U, 1300U, 1304U, 1308U, 1312U, 1316U,
    1320U, 1324U, 1328U, 1332U, 1336U, 1340U, 1344U, 1348U, 1352U, 1356U, 1360U,
    1364U, 1368U, 1372U, 1376U, 1380U, 1384U, 1388U, 1392U, 1396U, 1400U, 1404U,
    1408U, 1412U, 1416U, 1420U, 1424U, 1428U, 1432U, 1436U, 1440U, 1444U, 1448U,
    1452U, 1456U, 1460U, 1464U, 1468U, 1472U, 1476U, 1480U, 1484U, 1488U, 1492U,
    1496U, 1500U, 1504U, 1508U, 1512U, 1516U, 1520U, 1524U, 1528U, 1532U, 1536U,
    1540U, 1544U, 1548U, 1552U, 1556U, 1560U, 1564U, 1568U, 1572U, 1576U, 1580U,
    1584U, 1588U, 1592U, 1596U, 1600U, 1604U, 1608U, 1612U, 1616U, 1620U, 1624U,
    1628U, 1632U, 1636U, 1640U, 1644U, 1648U, 1652U, 1656U, 1660U, 1664U, 1668U,
    1672U, 1676U, 1680U, 1684U, 1688U, 1692U, 1696U, 1700U, 1704U, 1708U, 1712U,
    1716U, 1720U, 1724U, 1728U, 1732U, 1736U, 1740U, 1744U, 1748U, 1752U, 1756U,
    1760U, 1764U, 1768U, 1772U, 1776U, 1780U, 1784U, 1788U, 1792U, 1796U, 1800U,
    1804U, 1808U, 1812U, 1816U, 1820U, 1824U, 1828U, 1832U, 1836U, 1840U, 1844U,
    1848U, 1852U, 1856U, 1860U, 1864U, 1868U, 1872U, 1876U, 1880U, 1884U, 1888U,
    1892U, 1896U, 1900U },

  // Mask Parameter: BandLimitedWhiteNoise_Cov
  //  Referenced by: '<S25>/Output'

  2.5E-10,

  // Mask Parameter: BandLimitedWhiteNoise1_Cov
  //  Referenced by: '<S26>/Output'

  4.0E-10,

  // Mask Parameter: BandLimitedWhiteNoise2_Cov
  //  Referenced by: '<S27>/Output'

  4.0E-10,

  // Mask Parameter: SecondOrderFilter_FilterType
  //  Referenced by: '<S292>/Constant4'

  1.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S213>/UD'

  0.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScal_m
  //  Referenced by: '<S244>/UD'

  0.0,

  // Mask Parameter: LowPassFilterDiscreteorContinuo
  //  Referenced by: '<S245>/K'

  1.0,

  // Mask Parameter: LowPassFilterDiscreteorContin_b
  //  Referenced by: '<S249>/Time constant'

  0.1,

  // Mask Parameter: BandLimitedWhiteNoise_seed
  //  Referenced by: '<S25>/White Noise'

  23341.0,

  // Mask Parameter: BandLimitedWhiteNoise1_seed
  //  Referenced by: '<S26>/White Noise'

  23341.0,

  // Mask Parameter: BandLimitedWhiteNoise2_seed
  //  Referenced by: '<S27>/White Noise'

  23341.0,

  // Mask Parameter: MinMaxRunningResettable_vinit
  //  Referenced by:
  //    '<S67>/Initial Condition'
  //    '<S67>/Memory'

  false,

  // Mask Parameter: MinMaxRunningResettable1_vinit
  //  Referenced by:
  //    '<S68>/Initial Condition'
  //    '<S68>/Memory'

  false,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S105>/Constant'

  {
    {
      {
        {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        }, {
          {
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
            0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
          ,                            // Label

          {
            0U,                        // CurrentLength
            0U                         // ReceivedLength
          },                           // Label_SL_Info
          0U,                          // Size
          0U                           // Stride
        } }
      ,                                // Dim

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      },                               // Dim_SL_Info
      0U                               // DataOffset
    },                                 // Layout

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // Data

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Data_SL_Info
  },

  // Computed Parameter: Constant_Value_f
  //  Referenced by: '<S117>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // ChildFrameId

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // ChildFrameId_SL_Info

    {
      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Position

        {
          0.0,                         // X
          0.0,                         // Y
          0.0,                         // Z
          0.0                          // W
        }                              // Orientation
      },                               // Pose

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      // Covariance
    },                                 // Pose

    {
      {
        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        },                             // Linear

        {
          0.0,                         // X
          0.0,                         // Y
          0.0                          // Z
        }                              // Angular
      },                               // Twist

      {
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
        0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
      // Covariance
    }                                  // Twist
  },

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S61>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    },                                 // Orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // OrientationCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // AngularVelocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // AngularVelocityCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // LinearAcceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // LinearAccelerationCovariance
  },

  // Computed Parameter: Constant_Value_i
  //  Referenced by: '<S58>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    },                                 // Orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // OrientationCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // AngularVelocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // AngularVelocityCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // LinearAcceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // LinearAccelerationCovariance
  },

  // Computed Parameter: Out1_Y0_l
  //  Referenced by: '<S55>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    },                                 // Orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // OrientationCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // AngularVelocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // AngularVelocityCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // LinearAcceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // LinearAccelerationCovariance
  },

  // Computed Parameter: Constant_Value_l
  //  Referenced by: '<S52>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    },                                 // Orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // OrientationCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // AngularVelocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // AngularVelocityCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // LinearAcceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // LinearAccelerationCovariance
  },

  // Computed Parameter: Constant_Value_g
  //  Referenced by: '<S79>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    },                                 // Orientation

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // OrientationCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // AngularVelocity

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    ,                                  // AngularVelocityCovariance

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // LinearAcceleration

    {
      0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 }
    // LinearAccelerationCovariance
  },

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S82>/Constant'

  {
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // ModelName

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // ModelName_SL_Info

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Position

      {
        0.0,                           // X
        0.0,                           // Y
        0.0,                           // Z
        0.0                            // W
      }                                // Orientation
    },                                 // Pose

    {
      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      },                               // Linear

      {
        0.0,                           // X
        0.0,                           // Y
        0.0                            // Z
      }                                // Angular
    },                                 // Twist

    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // ReferenceFrame

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // ReferenceFrame_SL_Info
  },

  // Computed Parameter: Out1_Y0_m
  //  Referenced by: '<S62>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // XVelBtm
    0.0,                               // YVelBtm
    0.0,                               // ZVelBtm
    0.0,                               // EVelBtm
    0.0,                               // Velocity1
    0.0,                               // Velocity2
    0.0,                               // Velocity3
    0.0                                // Velocity4
  },

  // Computed Parameter: Constant_Value_k
  //  Referenced by: '<S59>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // XVelBtm
    0.0,                               // YVelBtm
    0.0,                               // ZVelBtm
    0.0,                               // EVelBtm
    0.0,                               // Velocity1
    0.0,                               // Velocity2
    0.0,                               // Velocity3
    0.0                                // Velocity4
  },

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S56>/Out1'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // XVelBtm
    0.0,                               // YVelBtm
    0.0,                               // ZVelBtm
    0.0,                               // EVelBtm
    0.0,                               // Velocity1
    0.0,                               // Velocity2
    0.0,                               // Velocity3
    0.0                                // Velocity4
  },

  // Computed Parameter: Constant_Value_f2
  //  Referenced by: '<S53>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // XVelBtm
    0.0,                               // YVelBtm
    0.0,                               // ZVelBtm
    0.0,                               // EVelBtm
    0.0,                               // Velocity1
    0.0,                               // Velocity2
    0.0,                               // Velocity3
    0.0                                // Velocity4
  },

  // Computed Parameter: Constant_Value_h
  //  Referenced by: '<S74>/Constant'

  {
    {
      0U,                              // Seq

      {
        0.0,                           // Sec
        0.0                            // Nsec
      },                               // Stamp

      {
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
        0U, 0U }
      ,                                // FrameId

      {
        0U,                            // CurrentLength
        0U                             // ReceivedLength
      }                                // FrameId_SL_Info
    },                                 // Header
    0.0,                               // XVelBtm
    0.0,                               // YVelBtm
    0.0,                               // ZVelBtm
    0.0,                               // EVelBtm
    0.0,                               // Velocity1
    0.0,                               // Velocity2
    0.0,                               // Velocity3
    0.0                                // Velocity4
  },

  // Computed Parameter: Output_Y0
  //  Referenced by: '<S6>/Output'

  {
    {
      0.0, 0.0, 0.0 }
    ,                                  // World_Position

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  // qS2W

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  // qW2S

    {
      0.0, 0.0, 0.0 }
    ,                                  // Body_Velocity

    {
      0.0, 0.0, 0.0 }
    // Angular_Rate
  },

  // Computed Parameter: CleanOutput_Y0
  //  Referenced by: '<S1>/Clean Output'

  {
    {
      0.0, 0.0, 0.0 }
    ,                                  // World_Position

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  // Quaternion

    {
      0.0, 0.0, 0.0 }
    ,                                  // Linear_Acceleration

    {
      0.0, 0.0, 0.0 }
    ,                                  // Body_Velocity

    {
      0.0, 0.0, 0.0 }
    // Angular_Rate
  },

  // Computed Parameter: Output_Y0_k
  //  Referenced by: '<S4>/Output'

  {
    {
      0.0, 0.0, 0.0 }
    ,                                  // World_Position

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  // Quaternion

    {
      0.0, 0.0, 0.0 }
    ,                                  // Linear_Acceleration

    {
      0.0, 0.0, 0.0 }
    ,                                  // Body_Velocity

    {
      0.0, 0.0, 0.0 }
    // Angular_Rate
  },

  // Computed Parameter: SensorsOutput_Y0
  //  Referenced by: '<S1>/Sensors Output'

  {
    0.0,                               // Pressure_Depth

    {
      0.0, 0.0, 0.0, 0.0 }
    ,                                  // Quaternion

    {
      0.0, 0.0, 0.0 }
    ,                                  // Angular_Rate

    {
      0.0, 0.0, 0.0 }
    // DVL_Velocity
  },

  // Computed Parameter: Out1_Y0_d
  //  Referenced by: '<S305>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Position

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Orientation
    0U,                                // Frame
    0U,                                // Speed
    0.0,                               // Fine
    false                              // Rotation
  },

  // Computed Parameter: Constant_Value_lq
  //  Referenced by: '<S302>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Position

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Orientation
    0U,                                // Frame
    0U,                                // Speed
    0.0,                               // Fine
    false                              // Rotation
  },

  // Computed Parameter: Constant_Value_oj
  //  Referenced by: '<S101>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Position

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    }                                  // Orientation
  },

  // Computed Parameter: Out1_Y0_g
  //  Referenced by: '<S313>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Position

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    }                                  // Orientation
  },

  // Computed Parameter: Constant_Value_b
  //  Referenced by: '<S307>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Position

    {
      0.0,                             // X
      0.0,                             // Y
      0.0,                             // Z
      0.0                              // W
    }                                  // Orientation
  },

  // Computed Parameter: Out1_Y0_pb
  //  Referenced by: '<S298>/Out1'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Constant_Value_hg
  //  Referenced by: '<S293>/Constant'

  {
    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    },                                 // Linear

    {
      0.0,                             // X
      0.0,                             // Y
      0.0                              // Z
    }                                  // Angular
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S314>/Out1'

  {
    false                              // State
  },

  // Computed Parameter: Constant_Value_ok
  //  Referenced by: '<S308>/Constant'

  {
    false                              // State
  },

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S104>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S107>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S115>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_e
  //  Referenced by: '<S316>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_kd
  //  Referenced by: '<S310>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_o
  //  Referenced by: '<S317>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S311>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S318>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_p
  //  Referenced by: '<S312>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S63>/Out1'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S60>/Constant'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Out1_Y0_nb
  //  Referenced by: '<S57>/Out1'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_oz
  //  Referenced by: '<S54>/Constant'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_bv
  //  Referenced by: '<S77>/Constant'

  {
    0.0F                               // Data
  },

  // Computed Parameter: Constant_Value_ly
  //  Referenced by: '<S106>/Constant'

  {
    0                                  // Data
  },

  // Computed Parameter: Out1_Y0_k
  //  Referenced by: '<S315>/Out1'

  {
    0U                                 // Data
  },

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S309>/Constant'

  {
    0U                                 // Data
  },

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<S17>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<S17>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_j
  //  Referenced by: '<S18>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_m
  //  Referenced by: '<S18>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_h
  //  Referenced by: '<S19>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_l
  //  Referenced by: '<S19>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_i
  //  Referenced by: '<S20>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_f
  //  Referenced by: '<S20>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_jp
  //  Referenced by: '<S21>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_n
  //  Referenced by: '<S21>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_l
  //  Referenced by: '<S22>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_nr
  //  Referenced by: '<S22>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_p
  //  Referenced by: '<S23>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_h
  //  Referenced by: '<S23>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_n
  //  Referenced by: '<S24>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_fa
  //  Referenced by: '<S24>/Transfer Fcn'

  6.666666666666667,

  // Expression: 0
  //  Referenced by: '<S14>/Z Drift'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/X Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Y Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Z Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Roll Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Pitch Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S14>/Yaw Wave'

  0.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Body velocity '

  { 0.0, 0.0, 0.0 },

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Angular Rates'

  { 0.0, 0.0, 0.0 },

  // Expression: [0,pi,pi/2]
  //  Referenced by: '<S16>/ y devant Z haut'

  { 0.0, 3.1415926535897931, 1.5707963267948966 },

  // Expression: 0
  //  Referenced by: '<S25>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev
  //  Referenced by: '<S25>/White Noise'

  1.0,

  // Expression: 0
  //  Referenced by: '<S26>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev_d
  //  Referenced by: '<S26>/White Noise'

  1.0,

  // Expression: 0
  //  Referenced by: '<S27>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev_e
  //  Referenced by: '<S27>/White Noise'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S33>/1//2'

  0.5,

  // Expression: 0.5
  //  Referenced by: '<S43>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S43>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S43>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S43>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S44>/Gain'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S44>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S44>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S44>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S45>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S45>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S45>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S45>/Gain2'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S39>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S39>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S39>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S39>/Gain2'

  2.0,

  // Computed Parameter: y_Y0
  //  Referenced by: '<S51>/y'

  0.0,

  // Expression: 0
  //  Referenced by: '<S51>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S51>/Constant1'

  0.0,

  // Expression: 0
  //  Referenced by: '<S3>/Delay'

  0.0,

  // Expression: [pi,0,0]
  //  Referenced by: '<S72>/ENU 2 NED'

  { 3.1415926535897931, 0.0, 0.0 },

  // Expression: 0.5
  //  Referenced by: '<S88>/1//2'

  0.5,

  // Expression: 0.5
  //  Referenced by: '<S96>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S96>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S96>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S96>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S97>/Gain'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S97>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S97>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S97>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S98>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S98>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S98>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S98>/Gain2'

  2.0,

  // Expression: 0.0
  //  Referenced by: '<S5>/Delay'

  0.0,

  // Expression: 1
  //  Referenced by: '<S127>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S128>/Constant'

  1.0,

  // Expression: 180/pi
  //  Referenced by: '<S123>/Gain'

  57.295779513082323,

  // Expression: 180/pi
  //  Referenced by: '<S122>/Gain'

  57.295779513082323,

  // Expression: 0
  //  Referenced by: '<S136>/MPC manager'

  0.0,

  // Expression: [0,0,0,0,0,0,0,0].'
  //  Referenced by: '<S136>/Delay'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S215>/md_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S215>/mv.target_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S215>/y.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S215>/y.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S215>/dmv.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S215>/dmv.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S215>/x.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S215>/x.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S215>/ecr.wt_zero'

  0.0,

  // Expression: zeros(1,1)
  //  Referenced by: '<S215>/params_zero'

  0.0,

  // Expression: 1
  //  Referenced by: '<S136>/Pulse Generator'

  1.0,

  // Expression: 20
  //  Referenced by: '<S136>/Pulse Generator'

  20.0,

  // Expression: 10
  //  Referenced by: '<S136>/Pulse Generator'

  10.0,

  // Expression: 0
  //  Referenced by: '<S136>/Pulse Generator'

  0.0,

  // Expression: 40
  //  Referenced by: '<S135>/MATLAB System'

  40.0,

  // Expression: 0
  //  Referenced by: '<S135>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S135>/Constant1'

  0.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S213>/TSamp'

  10.0,

  // Expression: 1
  //  Referenced by: '<S175>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S176>/Constant'

  1.0,

  // Expression: zeros(1,8)
  //  Referenced by: '<S137>/E_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,12)
  //  Referenced by: '<S137>/F_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S137>/G_zero'

  0.0,

  // Expression: lastPcov
  //  Referenced by: '<S141>/LastPcov'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12,1)
  //  Referenced by: '<S137>/y.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/u.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/du.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/ext.mv_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S141>/ext.mv_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: lastu+uoff
  //  Referenced by: '<S141>/last_mv'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,8)
  //  Referenced by: '<S132>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(nym,1)
  //  Referenced by: '<S141>/ym_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S137>/md_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/umin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/umax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12,1)
  //  Referenced by: '<S137>/ymin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12,1)
  //  Referenced by: '<S137>/ymax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S141>/umin_scale4'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: Yscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S141>/ymin_scale1'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S137>/S_zero'

  0.0,

  // Expression: MDscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S141>/ymin_scale2'

  1.0,

  // Expression: zeros(1,1)
  //  Referenced by: '<S137>/switch_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S137>/mv.target_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S141>/uref_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S137>/ecr.wt_zero'

  0.0,

  // Expression: [0,0,0,0,0,0,0,0].'
  //  Referenced by: '<S132>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale
  //  Referenced by: '<S141>/u_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S132>/Pulse Generator'

  1.0,

  // Expression: 2
  //  Referenced by: '<S132>/Pulse Generator'

  2.0,

  // Expression: 1
  //  Referenced by: '<S132>/Pulse Generator'

  1.0,

  // Expression: 0
  //  Referenced by: '<S132>/Pulse Generator'

  0.0,

  // Expression: zeros(1,8)
  //  Referenced by: '<S180>/E_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,13)
  //  Referenced by: '<S180>/F_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S180>/G_zero'

  0.0,

  // Expression: lastPcov
  //  Referenced by: '<S183>/LastPcov'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S180>/y.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/u.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/du.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/ext.mv_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S183>/ext.mv_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: lastu+uoff
  //  Referenced by: '<S183>/last_mv'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,8)
  //  Referenced by: '<S133>/Constant'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(nym,1)
  //  Referenced by: '<S183>/ym_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S180>/md_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/umin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/umax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S180>/ymin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S180>/ymax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S183>/umin_scale4'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: Yscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S183>/ymin_scale1'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S180>/S_zero'

  0.0,

  // Expression: MDscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S183>/ymin_scale2'

  1.0,

  // Expression: zeros(1,1)
  //  Referenced by: '<S180>/switch_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S180>/mv.target_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S183>/uref_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S180>/ecr.wt_zero'

  0.0,

  // Expression: [0,0,0,0,0,0,0,0].'
  //  Referenced by: '<S133>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale
  //  Referenced by: '<S183>/u_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S133>/Pulse Generator'

  1.0,

  // Expression: 2
  //  Referenced by: '<S133>/Pulse Generator'

  2.0,

  // Expression: 1
  //  Referenced by: '<S133>/Pulse Generator'

  1.0,

  // Expression: 0
  //  Referenced by: '<S133>/Pulse Generator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S134>/Constant'

  0.0,

  // Expression: zeros(1,8)
  //  Referenced by: '<S134>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S134>/Constant2'

  0.0,

  // Expression: 2
  //  Referenced by: '<S260>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S260>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S260>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S260>/Gain2'

  2.0,

  // Computed Parameter: TSamp_WtEt_d
  //  Referenced by: '<S244>/TSamp'

  20.0,

  // Expression: 0
  //  Referenced by: '<S252>/Constant'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S254>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S254>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S254>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S254>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S254>/Saturation'

  0.0,

  // Computed Parameter: Quat_Y0
  //  Referenced by: '<S266>/Quat'

  0.0,

  // Expression: [0,pi,pi/2]
  //  Referenced by: '<S266>/si y devant'

  { 0.0, 3.1415926535897931, 1.5707963267948966 },

  // Expression: 0.5
  //  Referenced by: '<S267>/1//2'

  0.5,

  // Computed Parameter: enable_Y0
  //  Referenced by: '<S239>/enable'

  0.0,

  // Computed Parameter: error_Y0
  //  Referenced by: '<S239>/error'

  0.0,

  // Computed Parameter: BodyVelocity_Y0
  //  Referenced by: '<S239>/Body Velocity'

  0.0,

  // Expression: 10
  //  Referenced by: '<S239>/Constant1'

  10.0,

  // Expression: 0
  //  Referenced by: '<S263>/Constant6'

  0.0,

  // Expression: 1
  //  Referenced by: '<S263>/Delay'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S269>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S269>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S269>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S269>/Gain2'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S270>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S270>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S270>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S270>/Gain2'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S271>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S271>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S271>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S271>/Gain2'

  2.0,

  // Computed Parameter: xhat_Y0
  //  Referenced by: '<S242>/xhat'

  0.0,

  // Expression: 1
  //  Referenced by: '<S242>/Constant'

  1.0,

  // Expression: p.Q
  //  Referenced by: '<S277>/Q'

  { 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 10.0 },

  // Expression: p.R{2}
  //  Referenced by: '<S277>/R2'

  { 0.31622776601683794, 0.0, 0.0, 0.0, 0.31622776601683794, 0.0, 0.0, 0.0,
    0.31622776601683794 },

  // Expression: 1
  //  Referenced by: '<S277>/MeasurementFcn2Inputs'

  1.0,

  // Expression: p.R{1}
  //  Referenced by: '<S277>/R1'

  { 0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.31622776601683794 },

  // Expression: 0
  //  Referenced by: '<S277>/MeasurementFcn1Inputs'

  0.0,

  // Expression: p.InitialCovariance
  //  Referenced by: '<S277>/DataStoreMemory - P'

  { 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.1622776601683795, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.1622776601683795 },

  // Expression: p.InitialState
  //  Referenced by: '<S277>/DataStoreMemory - x'

  { 0.0, 0.0, 0.3, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0,0,0,0,0,0]
  //  Referenced by: '<S243>/ '

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0 0 0 1 0 0 0]
  //  Referenced by: '<S289>/Constant7'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S288>/Constant'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: .25
  //  Referenced by: '<S290>/MATLAB System'

  0.25,

  // Expression: .22
  //  Referenced by: '<S290>/MATLAB System'

  0.22,

  // Expression: 2
  //  Referenced by: '<S290>/MATLAB System'

  2.0,

  // Computed Parameter: linWpts_Y0
  //  Referenced by: '<S301>/linWpts'

  0.0,

  // Computed Parameter: RotWpts_Y0
  //  Referenced by: '<S301>/RotWpts'

  0.0,

  // Computed Parameter: time_Y0
  //  Referenced by: '<S301>/time'

  0.0,

  // Computed Parameter: Input_Y0
  //  Referenced by: '<S301>/Input'

  0.0,

  // Computed Parameter: target_Y0
  //  Referenced by: '<S301>/target'

  0.0,

  // Expression: 0
  //  Referenced by: '<S301>/Constant1'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S303>/Out1'

  0.0,

  // Expression: zeros( 3, 2 )
  //  Referenced by: '<S306>/Polynomial Trajectory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S304>/Constant'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S304>/Discrete-Time Integrator'

  0.05,

  // Expression: 0
  //  Referenced by: '<S304>/Discrete-Time Integrator'

  0.0,

  // Expression: 0
  //  Referenced by: '<S290>/Constant'

  0.0,

  // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S286>/Constant'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S10>/MATLAB System'

  0.0,

  // Expression: 0
  //  Referenced by: '<S10>/Delay'

  0.0,

  // Expression: 0
  //  Referenced by: '<S292>/Constant'

  0.0,

  // Expression: x0
  //  Referenced by: '<S292>/Constant3'

  0.0,

  // Computed Parameter: Integrator_gainval_o
  //  Referenced by: '<S296>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S296>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S296>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S296>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S296>/Saturation'

  0.0,

  // Expression: (2*pi*fn).^2
  //  Referenced by: '<S292>/Gain3'

  95.5488288487489,

  // Expression: -1
  //  Referenced by: '<S287>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S292>/Constant1'

  0.0,

  // Expression: xdot0
  //  Referenced by: '<S292>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S297>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S297>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S297>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S297>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S297>/Saturation'

  0.0,

  // Expression: Ndis
  //  Referenced by: '<S169>/FixedHorizonOptimizer'

  0,

  // Expression: Ndis
  //  Referenced by: '<S211>/FixedHorizonOptimizer'

  0,

  // Computed Parameter: mv_Y0
  //  Referenced by: '<S5>/mv'

  0U,

  // Computed Parameter: depthnew_Y0
  //  Referenced by: '<S50>/depth new'

  false,

  // Computed Parameter: depthnew_Y0_l
  //  Referenced by: '<S49>/depth new'

  false,

  // Expression: iA
  //  Referenced by: '<S141>/Memory'

  { false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false },

  // Expression: iA
  //  Referenced by: '<S183>/Memory'

  { false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false },

  // Computed Parameter: yBlockOrdering_Y0
  //  Referenced by: '<S278>/yBlockOrdering'

  false,

  // Computed Parameter: yBlockOrdering_Y0_o
  //  Referenced by: '<S279>/yBlockOrdering'

  false,

  // Expression: true()
  //  Referenced by: '<S277>/BlockOrdering'

  true,

  // Expression: true()
  //  Referenced by: '<S277>/Enable1'

  true,

  // Computed Parameter: Delay1_InitialCondition_k
  //  Referenced by: '<S290>/Delay1'

  false,

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<S9>/Merge1'

  false
};

//
// File trailer for generated code.
//
// [EOF]
//
