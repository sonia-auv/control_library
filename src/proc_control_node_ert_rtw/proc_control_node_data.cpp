//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: proc_control_node_data.cpp
//
// Code generated for Simulink model 'proc_control_node'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Sep  8 14:46:24 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 64-bit (LP64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "proc_control_node.h"
#include "proc_control_node_private.h"

// Block parameters (default storage)
P_proc_control_node_T proc_control_node_P = {
  // Variable: MPC
  //  Referenced by:
  //    '<S9>/Saturation'
  //    '<S110>/Constant3'
  //    '<S188>/Constant3'
  //    '<S190>/Constant3'
  //    '<S191>/Constant3'

  {
    13.0,
    13.0,
    8.0,
    0.1,
    10.0,
    4.0,
    50.0,
    -40.0,

    {
      {
        { 70.0, 60.0, 70.0, 90.0, 90.0, 90.0, 90.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        },

        { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 },

        { 0.1, 0.1, 0.1, 0.1, 0.3, 0.3, 0.3, 0.3 }
      },

      {
        { 45.0, 45.0, 45.0, 45.0, 45.0, 45.0, 45.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0
        },

        { 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2 },

        { 0.4, 0.4, 0.4, 0.4, 0.6, 0.6, 0.6, 0.6 }
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
  //  Referenced by: '<S109>/MATLAB System'

  {
    31.0,
    0.0315,
    998.0,
    9.81,
    0.1435,
    0.3,

    { 0.4756, 0.008, 0.004, 0.008, 1.3735, -0.001, 0.004, -0.001, 1.5371 },

    { 0.001, 0.002, 0.018 },

    { 0.0, 0.0, 0.006 },

    { 11.25, 15.0, 17.5, 2.5, 1.75, 3.75 },

    { 1.17, 0.82, 0.756, 0.167, 0.1, 0.102 },

    { 0.12, 0.22, 0.292 },

    { -1.4648, -12.6156, -15.7695, -0.1164, -0.3493, -0.3493 }
  },

  // Variable: N
  //  Referenced by:
  //    '<S9>/N to PWM'
  //    '<S15>/ PWM to N'
  //    '<S15>/N to RPM'

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

  // Variable: RPM
  //  Referenced by: '<S15>/N to RPM'

  { 3464.7133333333336, 3468.01, 3449.07, 3421.12, 3409.95, 3394.78, 3373.93,
    3356.28, 3323.16, 3306.57, 3282.25, 3247.62, 3223.24, 3207.09, 3176.96,
    3152.96, 3111.45, 3086.3, 3061.4, 3049.78, 3003.32, 2987.73, 2952.33, 2918.2,
    2895.86, 2864.72, 2845.12, 2821.23, 2792.39, 2758.52, 2736.37, 2712.08,
    2681.26, 2660.64, 2629.0, 2598.64, 2575.93, 2547.87, 2517.32, 2482.17,
    2440.17, 2418.69, 2369.48, 2345.45, 2306.38, 2277.85, 2248.15, 2222.36,
    2198.72, 2156.96, 2140.15, 2105.77, 2081.37, 2039.83, 2001.27, 1968.2,
    1935.5, 1902.76, 1869.56, 1839.98, 1807.39, 1773.08, 1737.6, 1704.96,
    1667.06, 1630.35, 1589.17, 1553.88, 1518.54, 1481.78, 1448.45, 1409.65,
    1362.08, 1324.67, 1284.84, 1246.14, 1199.38, 1152.94, 1112.71, 1064.11,
    1016.48, 969.68, 916.03, 868.6, 809.94, 758.15, 697.28, 641.26, 577.81,
    513.25, 449.5, 388.48, 317.17, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 308.25, 374.8, 440.8, 508.01, 572.86, 630.43,
    688.25, 749.32, 803.61, 859.4, 906.13, 961.53, 1007.38, 1056.66, 1104.32,
    1147.5, 1194.61, 1237.07, 1278.89, 1319.08, 1359.21, 1408.65, 1443.5,
    1479.63, 1516.03, 1548.64, 1583.02, 1628.86, 1668.42, 1699.09, 1739.95,
    1766.18, 1802.32, 1835.1, 1865.47, 1900.85, 1929.78, 1960.82, 1994.08,
    2030.99, 2071.37, 2106.28, 2128.7, 2160.39, 2189.6, 2219.18, 2243.76,
    2266.35, 2305.35, 2341.59, 2391.8, 2415.81, 2445.98, 2475.13, 2497.91,
    2537.88, 2583.51, 2608.66, 2639.26, 2663.25, 2688.12, 2710.8, 2735.48,
    2765.9, 2809.4, 2822.46, 2853.6, 2888.0, 2903.17, 2933.63, 2973.17, 3001.72,
    3041.86, 3065.09, 3107.61, 3124.51, 3153.38, 3180.33, 3204.34, 3242.32,
    3260.1, 3299.33, 3307.84, 3351.13, 3378.76, 3405.6, 3427.86, 3437.91,
    3454.99, 3493.84, 3515.95, 3527.23, 3533.445 },

  // Variable: binv
  //  Referenced by: '<S109>/MATLAB System'

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

  // Variable: dMaxX
  //  Referenced by: '<S16>/X Drift'

  0.29631497357681658,

  // Variable: dMaxY
  //  Referenced by: '<S16>/Y Drift'

  0.49975841223368422,

  // Variable: dMinX
  //  Referenced by: '<S16>/X Drift'

  -0.25509047885001257,

  // Variable: dMinY
  //  Referenced by: '<S16>/Y Drift'

  -0.24830212206435187,

  // Variable: dSeedX
  //  Referenced by: '<S16>/X Drift'

  3.0,

  // Variable: dSeedY
  //  Referenced by: '<S16>/Y Drift'

  9.0,

  // Variable: waPhi
  //  Referenced by: '<S16>/Roll Wave'

  0.5,

  // Variable: waPsi
  //  Referenced by: '<S16>/Yaw Wave'

  0.5,

  // Variable: waTheta
  //  Referenced by: '<S16>/Pitch Wave'

  0.5,

  // Variable: waX
  //  Referenced by: '<S16>/X Wave'

  1.0,

  // Variable: waY
  //  Referenced by: '<S16>/Y Wave'

  2.0,

  // Variable: waZ
  //  Referenced by: '<S16>/Z Wave'

  3.0,

  // Variable: wfPhi
  //  Referenced by: '<S16>/Roll Wave'

  1.0471975511965976,

  // Variable: wfPsi
  //  Referenced by: '<S16>/Yaw Wave'

  1.0471975511965976,

  // Variable: wfTheta
  //  Referenced by: '<S16>/Pitch Wave'

  1.0471975511965976,

  // Variable: wfX
  //  Referenced by: '<S16>/X Wave'

  1.5707963267948966,

  // Variable: wfY
  //  Referenced by: '<S16>/Y Wave'

  1.5707963267948966,

  // Variable: wfZ
  //  Referenced by: '<S16>/Z Wave'

  1.5707963267948966,

  // Variable: wn_l
  //  Referenced by: '<S194>/Gain'

  1.5557249463348581,

  // Variable: wpPhi
  //  Referenced by: '<S16>/Roll Wave'

  0.0,

  // Variable: wpPsi
  //  Referenced by: '<S16>/Yaw Wave'

  3.1415926535897931,

  // Variable: wpTheta
  //  Referenced by: '<S16>/Pitch Wave'

  1.5707963267948966,

  // Variable: wpX
  //  Referenced by: '<S16>/X Wave'

  0.0,

  // Variable: wpY
  //  Referenced by: '<S16>/Y Wave'

  1.5707963267948966,

  // Variable: wpZ
  //  Referenced by: '<S16>/Z Wave'

  3.1415926535897931,

  // Variable: zeta_l
  //  Referenced by: '<S194>/Gain'

  0.99,

  // Variable: PWM
  //  Referenced by:
  //    '<S9>/N to PWM'
  //    '<S15>/ PWM to N'

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
  //  Referenced by: '<S28>/Output'

  2.5E-10,

  // Mask Parameter: BandLimitedWhiteNoise1_Cov
  //  Referenced by: '<S29>/Output'

  4.0E-10,

  // Mask Parameter: SecondOrderFilter_FilterType
  //  Referenced by: '<S194>/Constant4'

  1.0,

  // Mask Parameter: DiscreteDerivative_ICPrevScaled
  //  Referenced by: '<S111>/UD'

  0.0,

  // Mask Parameter: BandLimitedWhiteNoise_seed
  //  Referenced by: '<S28>/White Noise'

  23341.0,

  // Mask Parameter: BandLimitedWhiteNoise1_seed
  //  Referenced by: '<S29>/White Noise'

  23341.0,

  // Mask Parameter: MinMaxRunningResettable_vinit
  //  Referenced by:
  //    '<S229>/Initial Condition'
  //    '<S229>/Memory'

  0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S71>/Constant'

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

  // Computed Parameter: Out1_Y0
  //  Referenced by: '<S234>/Out1'

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
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Buttons_SL_Info
  },

  // Computed Parameter: Constant_Value_n
  //  Referenced by: '<S228>/Constant'

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
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
      0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F }
    ,                                  // Axes

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    },                                 // Axes_SL_Info

    {
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0 }
    ,                                  // Buttons

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Buttons_SL_Info
  },

  // Computed Parameter: Out1_Y0_l
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

  // Computed Parameter: Constant_Value_l
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
  //  Referenced by: '<S68>/Constant'

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

  // Computed Parameter: Out1_Y0_j
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

  // Computed Parameter: Constant_Value_a
  //  Referenced by: '<S60>/Constant'

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
  //  Referenced by: '<S65>/Constant'

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

  // Computed Parameter: Output_Y0
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
  //  Referenced by: '<S210>/Out1'

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
    0.0                                // Fine
  },

  // Computed Parameter: Constant_Value_lq
  //  Referenced by: '<S206>/Constant'

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
    0.0                                // Fine
  },

  // Computed Parameter: Out1_Y0_jt
  //  Referenced by: '<S230>/Out1'

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

  // Computed Parameter: Constant_Value_a3
  //  Referenced by: '<S224>/Constant'

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

  // Computed Parameter: Constant_Value_m
  //  Referenced by: '<S105>/Constant'

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

  // Computed Parameter: Out1_Y0_p
  //  Referenced by: '<S200>/Out1'

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
  //  Referenced by: '<S195>/Constant'

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

  // Computed Parameter: Constant_Value_o
  //  Referenced by: '<S84>/Constant'

  {
    0.0,                               // X
    0.0,                               // Y
    0.0                                // Z
  },

  // Computed Parameter: Constant_Value_c
  //  Referenced by: '<S73>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_e
  //  Referenced by: '<S78>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_m1
  //  Referenced by: '<S80>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_h
  //  Referenced by: '<S231>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_ee
  //  Referenced by: '<S225>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Out1_Y0_n
  //  Referenced by: '<S233>/Out1'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_a2
  //  Referenced by: '<S227>/Constant'

  {
    false                              // Data
  },

  // Computed Parameter: Constant_Value_ly
  //  Referenced by: '<S72>/Constant'

  {
    0                                  // Data
  },

  // Computed Parameter: Out1_Y0_a
  //  Referenced by: '<S232>/Out1'

  {
    0U                                 // Data
  },

  // Computed Parameter: Constant_Value_d
  //  Referenced by: '<S226>/Constant'

  {
    0U                                 // Data
  },

  // Expression: 0.0001924722
  //  Referenced by: '<S19>/AHRS'

  0.0001924722,

  // Expression: 9.1385e-5
  //  Referenced by: '<S19>/AHRS'

  9.1385E-5,

  // Expression: 0.1
  //  Referenced by: '<S19>/AHRS'

  0.1,

  // Expression: 3.0462e-13
  //  Referenced by: '<S19>/AHRS'

  3.0462E-13,

  // Expression: 0.0096236100000000012
  //  Referenced by: '<S19>/AHRS'

  0.0096236100000000012,

  // Expression: 0.5
  //  Referenced by: '<S19>/AHRS'

  0.5,

  // Expression: 0.5
  //  Referenced by: '<S19>/AHRS'

  0.5,

  // Expression: 0.5
  //  Referenced by: '<S19>/AHRS'

  0.5,

  // Expression: 50
  //  Referenced by: '<S19>/AHRS'

  50.0,

  // Expression: 25
  //  Referenced by: '<S19>/IMU'

  25.0,

  // Expression: [ 27.5550, -2.4169, -16.0849 ]
  //  Referenced by: '<S19>/IMU'

  { 27.555, -2.4169, -16.0849 },

  // Expression: Inf
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: Inf
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: Inf
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: 0
  //  Referenced by: '<S19>/IMU'

  0.0,

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Expression: [ 0, 0, 0 ]
  //  Referenced by: '<S19>/IMU'

  { 0.0, 0.0, 0.0 },

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<S20>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<S20>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_j
  //  Referenced by: '<S21>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_m
  //  Referenced by: '<S21>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_h
  //  Referenced by: '<S22>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_l
  //  Referenced by: '<S22>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_i
  //  Referenced by: '<S23>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_f
  //  Referenced by: '<S23>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_jp
  //  Referenced by: '<S24>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_n
  //  Referenced by: '<S24>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_l
  //  Referenced by: '<S25>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_nr
  //  Referenced by: '<S25>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_p
  //  Referenced by: '<S26>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_h
  //  Referenced by: '<S26>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_n
  //  Referenced by: '<S27>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_fa
  //  Referenced by: '<S27>/Transfer Fcn'

  6.666666666666667,

  // Expression: 0
  //  Referenced by: '<S16>/Z Drift'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/X Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Y Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Z Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Roll Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Pitch Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S16>/Yaw Wave'

  0.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Body velocity '

  { 0.0, 0.0, 0.0 },

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Angular Rates'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S28>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev
  //  Referenced by: '<S28>/White Noise'

  1.0,

  // Expression: -1
  //  Referenced by: '<S19>/Gain'

  -1.0,

  // Expression: 0
  //  Referenced by: '<S29>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev_d
  //  Referenced by: '<S29>/White Noise'

  1.0,

  // Expression: [0,pi,pi/2]
  //  Referenced by: '<S18>/ y devant Z haut'

  { 0.0, 3.1415926535897931, 1.5707963267948966 },

  // Expression: 0.5
  //  Referenced by: '<S33>/1//2'

  0.5,

  // Expression: 2
  //  Referenced by: '<S37>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S37>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S37>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S37>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S38>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S38>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S38>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S38>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S39>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S39>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S39>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S39>/Gain2'

  2.0,

  // Expression: 1
  //  Referenced by: '<S52>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S53>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S100>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S101>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S150>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S151>/Constant'

  1.0,

  // Computed Parameter: Output_Y0_n
  //  Referenced by: '<S110>/Output'

  0.0,

  // Computed Parameter: isActive_Y0
  //  Referenced by: '<S110>/isActive'

  0.0,

  // Expression: lastPcov
  //  Referenced by: '<S116>/LastPcov'

  { 0.012028171656144025, 2.7603597991345548E-6, 7.8947982961580385E-6,
    -1.80952966248066E-8, 6.0867132597380638E-5, 0.00030811885414433818,
    0.00071978683168096805, 1.1787759709949878E-7, 7.7010621568248625E-7,
    -1.5883382473784707E-7, -0.0001494598469243314, 2.2198974262649045E-5,
    1.8643277052787744E-8, -0.00021465370266606762, -0.000868561002150558,
    -1.5471817666709154E-7, -1.0415834874836116E-6, -5.4949239648577192E-9,
    0.00014586565021983296, -4.0768704546876183E-5, 2.7603597991345548E-6,
    0.0092341634735414978, 1.4027213048273471E-5, -7.1952482059371131E-5,
    1.2600791040865106E-8, -0.0001124653695205158, 1.2287070535155139E-7,
    0.000424551967804619, 1.1803666846950958E-6, 8.76579902949609E-5,
    -1.0580026361381628E-8, -9.2477473767511966E-6, 0.00015426912206319092,
    -5.6026298227081881E-8, -1.6188728986598281E-7, -0.00051605655416526617,
    -1.5986691919307806E-6, -7.73947876467967E-5, 4.0719907220004027E-8,
    1.3682500402658065E-5, 7.8947982961580385E-6, 1.4027213048273471E-5,
    0.010123187273944694, -1.0972419424259764E-6, 7.1465399595602745E-7,
    -4.075296404054663E-8, 9.66414925451693E-7, 1.5178603454225326E-6,
    0.0005099354467921702, 4.5235374375733017E-6, -2.2297411837559151E-6,
    1.5331375297055342E-8, 3.9247936001045219E-6, -1.9808580755108126E-6,
    -1.051978485002078E-6, -1.6816805593323054E-6, -0.00062682576119724729,
    -2.5725594578403854E-6, 1.1493118174737315E-6, 9.696043505827304E-9,
    -1.80952966248066E-8, -7.1952482059371131E-5, -1.0972419424259764E-6,
    0.00057816039937472706, 3.2248980273487863E-7, 1.7956225195076063E-5,
    2.0283726202101113E-7, -9.361027221763154E-5, -4.6847768862964647E-6,
    1.3397350268875667E-5, -2.2458142559212427E-6, 3.094110300337448E-5,
    -0.00025177732743261267, -1.005882351674602E-6, -1.0091985326140326E-7,
    3.7733596425732545E-5, 1.9790261474087232E-6, -0.000324723171256703,
    5.6497076641586134E-7, -1.118939076634752E-5, 6.0867132597380638E-5,
    1.2600791040865106E-8, 7.1465399595602745E-7, 3.2248980273487863E-7,
    0.0010384043349333761, 3.2767161591040712E-5, 0.00015507403488538657,
    -1.3689528355683424E-8, 2.30074906697294E-6, 2.0989039911107357E-6,
    4.5216814463154284E-6, 0.00012652784844111891, 2.028172350847766E-8,
    -0.00048122247960394386, -4.7844032032995747E-5, 2.93871011838446E-8,
    -1.3517156049345344E-6, -2.3626150255143605E-7, -0.00055573885099075948,
    -3.81561702174669E-5, 0.00030811885414433818, -0.0001124653695205158,
    -4.075296404054663E-8, 1.7956225195076063E-5, 3.2767161591040712E-5,
    0.017052880172432328, 6.6707520851721369E-5, -2.0077393944082458E-5,
    -1.7205544248445228E-8, -2.8336129749333173E-5, -0.00012252620991316153,
    0.001448523801967833, -3.7532419440842165E-5, -0.00011458988273008907,
    -6.986686715019121E-5, 2.1603076229413884E-5, -1.0390332296637621E-8,
    1.8009200415759112E-5, 7.5415834650097337E-5, -0.0021492324014209391,
    0.00071978683168096805, 1.2287070535155139E-7, 9.66414925451693E-7,
    2.0283726202101113E-7, 0.00015507403488538657, 6.6707520851721369E-5,
    0.00032762844077820728, -1.3081836936197282E-8, 3.4745794638782312E-7,
    2.7761653466335125E-7, -0.00012090738694904059, 3.8426825330799947E-5,
    -9.5869676355220988E-8, -0.00017104510667395682, -0.00023947347725377646,
    -2.7727280388605419E-9, -4.3084366446777989E-7, -9.0107825774742182E-8,
    9.7818010606075836E-6, -2.8130656522749508E-5, 1.1787759709949878E-7,
    0.000424551967804619, 1.5178603454225326E-6, -9.361027221763154E-5,
    -1.3689528355683424E-8, -2.0077393944082458E-5, -1.3081836936197282E-8,
    0.00017798713983470697, 5.3410659114917688E-7, 6.971608953785335E-5,
    -1.5190774586221788E-7, -1.136709809566008E-5, 9.1622553140668616E-5,
    6.7460356901879672E-8, 1.2838581555673029E-9, -0.000131404326403845,
    -6.3016886132568717E-7, 5.7372954237481894E-6, -6.2644449055268624E-8,
    7.5563002199383169E-6, 7.7010621568248625E-7, 1.1803666846950958E-6,
    0.0005099354467921702, -4.6847768862964647E-6, 2.30074906697294E-6,
    -1.7205544248445228E-8, 3.4745794638782312E-7, 5.3410659114917688E-7,
    0.00024096883714211617, -6.4551582921893419E-6, 2.3581886340446905E-6,
    -4.1836388080340863E-9, 3.0053640354605506E-6, -1.3683171968326328E-6,
    -2.4917933316895637E-7, -3.879101117494545E-7, -0.00016967583688507875,
    1.3255955623704635E-6, -8.09983747430322E-7, 2.4545924466913954E-8,
    -1.5883382473784707E-7, 8.76579902949609E-5, 4.5235374375733017E-6,
    1.3397350268875667E-5, 2.0989039911107357E-6, -2.8336129749333173E-5,
    2.7761653466335125E-7, 6.971608953785335E-5, -6.4551582921893419E-6,
    0.0035512854089680608, -1.8206021487207892E-5, -3.96004496742922E-5,
    0.00032309896652019945, -5.9893901991344867E-7, 1.0359040759813272E-7,
    -5.1783575258991418E-5, -2.966499276341172E-6, -0.00014485940512402163,
    -2.4873511358886523E-6, 1.7360423728851441E-5, -0.0001494598469243314,
    -1.0580026361381628E-8, -2.2297411837559151E-6, -2.2458142559212427E-6,
    4.5216814463154284E-6, -0.00012252620991316153, -0.00012090738694904059,
    -1.5190774586221788E-7, 2.3581886340446905E-6, -1.8206021487207892E-5,
    0.0022193664462689467, -8.3536799590275577E-5, 2.3493579425471948E-7,
    0.00055240596269450859, 0.00010049881118682599, 1.1828977315253272E-8,
    1.0519229394818185E-6, 9.9399792159037319E-7, -0.00044288879608316912,
    8.30761657713607E-5, 2.2198974262649045E-5, -9.2477473767511966E-6,
    1.5331375297055342E-8, 3.094110300337448E-5, 0.00012652784844111891,
    0.001448523801967833, 3.8426825330799947E-5, -1.136709809566008E-5,
    -4.1836388080340863E-9, -3.96004496742922E-5, -8.3536799590275577E-5,
    0.0030574961985175135, -2.4433189538663544E-5, -9.488284921476355E-5,
    -1.6326987591363654E-5, 5.3481893794941561E-6, -3.03882152152475E-8,
    -8.6422761859231877E-6, -3.5823264782080687E-5, -0.00091825723436701431,
    1.8643277052787744E-8, 0.00015426912206319092, 3.9247936001045219E-6,
    -0.00025177732743261267, 2.028172350847766E-8, -3.7532419440842165E-5,
    -9.5869676355220988E-8, 9.1622553140668616E-5, 3.0053640354605506E-6,
    0.00032309896652019945, 2.3493579425471948E-7, -2.4433189538663544E-5,
    0.10539234687189118, 4.63087038497718E-7, 9.0315778768435769E-8,
    -6.5663563500115708E-5, -2.5852596718598824E-6, 1.7505128543876309E-6,
    -4.7620287052601548E-7, 1.802458396746996E-5, -0.00021465370266606762,
    -5.6026298227081881E-8, -1.9808580755108126E-6, -1.005882351674602E-6,
    -0.00048122247960394386, -0.00011458988273008907, -0.00017104510667395682,
    6.7460356901879672E-8, -1.3683171968326328E-6, -5.9893901991344867E-7,
    0.00055240596269450859, -9.488284921476355E-5, 4.63087038497718E-7,
    0.10563212663595455, 0.0001106210641605636, -3.4924558503213646E-8,
    1.3973385027846871E-6, 5.0222944186439967E-7, 2.1602117773018672E-6,
    6.8072585727288687E-5, -0.000868561002150558, -1.6188728986598281E-7,
    -1.051978485002078E-6, -1.0091985326140326E-7, -4.7844032032995747E-5,
    -6.986686715019121E-5, -0.00023947347725377646, 1.2838581555673029E-9,
    -2.4917933316895637E-7, 1.0359040759813272E-7, 0.00010049881118682599,
    -1.6326987591363654E-5, 9.0315778768435769E-8, 0.0001106210641605636,
    0.10536476125010624, 6.9726835540072556E-9, 3.31971230185721E-7,
    1.4135361997395471E-8, -5.7530731408284957E-5, 2.2052645141978784E-5,
    -1.5471817666709154E-7, -0.00051605655416526617, -1.6816805593323054E-6,
    3.7733596425732545E-5, 2.93871011838446E-8, 2.1603076229413884E-5,
    -2.7727280388605419E-9, -0.000131404326403845, -3.879101117494545E-7,
    -5.1783575258991418E-5, 1.1828977315253272E-8, 5.3481893794941561E-6,
    -6.5663563500115708E-5, -3.4924558503213646E-8, 6.9726835540072556E-9,
    0.1052572343850883, 5.0005805088546936E-7, 2.5068483912506337E-5,
    7.2568799673993925E-9, -6.41641610005726E-6, -1.0415834874836116E-6,
    -1.5986691919307806E-6, -0.00062682576119724729, 1.9790261474087232E-6,
    -1.3517156049345344E-6, -1.0390332296637621E-8, -4.3084366446777989E-7,
    -6.3016886132568717E-7, -0.00016967583688507875, -2.966499276341172E-6,
    1.0519229394818185E-6, -3.03882152152475E-8, -2.5852596718598824E-6,
    1.3973385027846871E-6, 3.31971230185721E-7, 5.0005805088546936E-7,
    0.10529608666746762, 4.4510737648921188E-7, 8.0232071034784251E-9,
    2.2763028032188416E-9, -5.4949239648577192E-9, -7.73947876467967E-5,
    -2.5725594578403854E-6, -0.000324723171256703, -2.3626150255143605E-7,
    1.8009200415759112E-5, -9.0107825774742182E-8, 5.7372954237481894E-6,
    1.3255955623704635E-6, -0.00014485940512402163, 9.9399792159037319E-7,
    -8.6422761859231877E-6, 1.7505128543876309E-6, 5.0222944186439967E-7,
    1.4135361997395471E-8, 2.5068483912506337E-5, 4.4510737648921188E-7,
    0.10543918050304923, -2.097843701981194E-7, -5.8852845972011036E-6,
    0.00014586565021983296, 4.0719907220004027E-8, 1.1493118174737315E-6,
    5.6497076641586134E-7, -0.00055573885099075948, 7.5415834650097337E-5,
    9.7818010606075836E-6, -6.2644449055268624E-8, -8.09983747430322E-7,
    -2.4873511358886523E-6, -0.00044288879608316912, -3.5823264782080687E-5,
    -4.7620287052601548E-7, 2.1602117773018672E-6, -5.7530731408284957E-5,
    7.2568799673993925E-9, 8.0232071034784251E-9, -2.097843701981194E-7,
    0.10565477704591891, -2.56276333802349E-5, -4.0768704546876183E-5,
    1.3682500402658065E-5, 9.696043505827304E-9, -1.118939076634752E-5,
    -3.81561702174669E-5, -0.0021492324014209391, -2.8130656522749508E-5,
    7.5563002199383169E-6, 2.4545924466913954E-8, 1.7360423728851441E-5,
    8.30761657713607E-5, -0.00091825723436701431, 1.802458396746996E-5,
    6.8072585727288687E-5, 2.2052645141978784E-5, -6.41641610005726E-6,
    2.2763028032188416E-9, -5.8852845972011036E-6, -2.56276333802349E-5,
    0.10612635647968524 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S112>/G_zero'

  0.0,

  // Expression: zeros(12,1)
  //  Referenced by: '<S112>/y.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/u.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/du.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/ext.mv_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S116>/ext.mv_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: lastu+uoff
  //  Referenced by: '<S116>/last_mv'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: lastx+xoff
  //  Referenced by: '<S116>/last_x'

  { 0.0, 0.0, 0.31, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S110>/Constant4'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S112>/md_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/umin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/umax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12,1)
  //  Referenced by: '<S112>/ymin_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(12,1)
  //  Referenced by: '<S112>/ymax_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,8)
  //  Referenced by: '<S112>/E_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S116>/umin_scale4'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,12)
  //  Referenced by: '<S112>/F_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: Yscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S116>/ymin_scale1'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S112>/S_zero'

  0.0,

  // Expression: MDscale(:,ones(1,max(nCC,1)))'
  //  Referenced by: '<S116>/ymin_scale2'

  1.0,

  // Expression: zeros(1,1)
  //  Referenced by: '<S112>/switch_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S112>/mv.target_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: RMVscale
  //  Referenced by: '<S116>/uref_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S112>/ecr.wt_zero'

  0.0,

  // Expression: [0,0,0,0,0,0,0,0].'
  //  Referenced by: '<S110>/Delay1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: MVscale
  //  Referenced by: '<S116>/u_scale'

  { 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S110>/Pulse Generator'

  1.0,

  // Expression: 2
  //  Referenced by: '<S110>/Pulse Generator'

  2.0,

  // Expression: 1
  //  Referenced by: '<S110>/Pulse Generator'

  1.0,

  // Expression: 0
  //  Referenced by: '<S110>/Pulse Generator'

  0.0,

  // Expression: 40
  //  Referenced by: '<S109>/MATLAB System'

  40.0,

  // Computed Parameter: TSamp_WtEt
  //  Referenced by: '<S111>/TSamp'

  10.0,

  // Expression: zeros(1,8)
  //  Referenced by: '<S108>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S183>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S184>/Constant'

  1.0,

  // Expression: [0 0 0 1 0 0 0]
  //  Referenced by: '<S191>/Constant7'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S190>/Constant'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: .2
  //  Referenced by: '<S192>/MATLAB System'

  0.2,

  // Expression: .1
  //  Referenced by: '<S192>/MATLAB System'

  0.1,

  // Expression: 3
  //  Referenced by: '<S192>/MATLAB System'

  3.0,

  // Computed Parameter: linWpts_Y0
  //  Referenced by: '<S205>/linWpts'

  0.0,

  // Computed Parameter: RotWpts_Y0
  //  Referenced by: '<S205>/RotWpts'

  0.0,

  // Computed Parameter: time_Y0
  //  Referenced by: '<S205>/time'

  0.0,

  // Expression: 0
  //  Referenced by: '<S205>/Constant1'

  0.0,

  // Computed Parameter: Out1_Y0_i
  //  Referenced by: '<S207>/Out1'

  0.0,

  // Expression: 1
  //  Referenced by: '<S217>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S218>/Constant'

  1.0,

  // Computed Parameter: y_Y0
  //  Referenced by: '<S211>/y'

  0.0,

  // Expression: zeros( 3, 2 )
  //  Referenced by: '<S209>/Polynomial Trajectory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S209>/Constant'

  1.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S209>/Discrete-Time Integrator'

  0.05,

  // Expression: 0
  //  Referenced by: '<S209>/Discrete-Time Integrator'

  0.0,

  // Expression: [1,1]
  //  Referenced by: '<S192>/Constant1'

  { 1.0, 1.0 },

  // Expression: 1
  //  Referenced by: '<S208>/Delay'

  1.0,

  // Expression: 0
  //  Referenced by: '<S192>/Constant'

  0.0,

  // Expression: 0
  //  Referenced by: '<S208>/Constant6'

  0.0,

  // Expression: [0,0,0,1,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S188>/Constant'

  { 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 10
  //  Referenced by: '<S10>/Constant1'

  10.0,

  // Expression: 0
  //  Referenced by: '<S10>/Delay'

  0.0,

  // Expression: 1
  //  Referenced by: '<S155>/Delay'

  1.0,

  // Expression: 2
  //  Referenced by: '<S175>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S175>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S175>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S175>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S174>/Gain'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S174>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S174>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S174>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S173>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S173>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S173>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S173>/Gain1'

  2.0,

  // Expression: 1
  //  Referenced by: '<S10>/Gain'

  1.0,

  // Expression: 0.5
  //  Referenced by: '<S167>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S167>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S167>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S167>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S168>/Gain'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S168>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S168>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S168>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S169>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S169>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S169>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S169>/Gain2'

  2.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainva_o
  //  Referenced by: '<S10>/Discrete-Time Integrator'

  0.025,

  // Computed Parameter: DiscreteTimeIntegrator1_gainval
  //  Referenced by: '<S10>/Discrete-Time Integrator1'

  0.025,

  // Expression: 0
  //  Referenced by: '<S10>/Discrete-Time Integrator1'

  0.0,

  // Expression: 180/pi
  //  Referenced by: '<S179>/Gain'

  57.295779513082323,

  // Expression: 0
  //  Referenced by: '<S194>/Constant'

  0.0,

  // Expression: x0
  //  Referenced by: '<S194>/Constant3'

  0.0,

  // Computed Parameter: Integrator_gainval
  //  Referenced by: '<S198>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S198>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S198>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S198>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S198>/Saturation'

  0.0,

  // Expression: (2*pi*fn).^2
  //  Referenced by: '<S194>/Gain3'

  95.5488288487489,

  // Expression: 0
  //  Referenced by: '<S194>/Constant1'

  0.0,

  // Expression: xdot0
  //  Referenced by: '<S194>/Constant2'

  0.0,

  // Computed Parameter: Integrator_gainval_e
  //  Referenced by: '<S199>/Integrator'

  0.05,

  // Expression: antiwindupUpperLimit
  //  Referenced by: '<S199>/Integrator'

  0.0,

  // Expression: antiwindupLowerLimit
  //  Referenced by: '<S199>/Integrator'

  0.0,

  // Expression: windupUpperLimit
  //  Referenced by: '<S199>/Saturation'

  0.0,

  // Expression: windupLowerLimit
  //  Referenced by: '<S199>/Saturation'

  0.0,

  // Expression: -1
  //  Referenced by: '<S189>/Gain'

  -1.0,

  // Expression: 1
  //  Referenced by: '<S85>/Delay'

  1.0,

  // Expression: 0.0
  //  Referenced by: '<S5>/Delay'

  0.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S82>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: [0,0,0]
  //  Referenced by: '<S83>/Constant'

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S85>/Constant6'

  0.0,

  // Expression: 0
  //  Referenced by: '<S155>/Constant6'

  0.0,

  // Expression: Ndis
  //  Referenced by: '<S144>/FixedHorizonOptimizer'

  0,

  // Expression: iA
  //  Referenced by: '<S116>/Memory'

  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },

  // Computed Parameter: Delay1_InitialCondition_k
  //  Referenced by: '<S192>/Delay1'

  0,

  // Computed Parameter: Merge1_InitialOutput
  //  Referenced by: '<S11>/Merge1'

  0,

  // Start of '<S155>/Subsystem2'
  {
    // Computed Parameter: Quat_Y0
    //  Referenced by: '<S162>/Quat'

    0.0,

    // Expression: [0,pi,pi/2]
    //  Referenced by: '<S162>/si y devant'

    { 0.0, 3.1415926535897931, 1.5707963267948966 },

    // Expression: 0.5
    //  Referenced by: '<S163>/1//2'

    0.5
  }
  ,

  // End of '<S155>/Subsystem2'

  // Start of '<S85>/Subsystem2'
  {
    // Computed Parameter: Quat_Y0
    //  Referenced by: '<S91>/Quat'

    0.0,

    // Expression: [0,pi,-pi/2]
    //  Referenced by: '<S91>/si y devant'

    { 0.0, 3.1415926535897931, -1.5707963267948966 },

    // Expression: 0.5
    //  Referenced by: '<S92>/1//2'

    0.5
  }
  // End of '<S85>/Subsystem2'
};

//
// File trailer for generated code.
//
// [EOF]
//
