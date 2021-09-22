  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 41;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (proc_control_node_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.MPC
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.physics
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 29;
      section.data(29)  = dumData; %prealloc
      
	  ;% proc_control_node_P.N
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.RPM
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 201;
	
	  ;% proc_control_node_P.binv
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 402;
	
	  ;% proc_control_node_P.dMaxX
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 450;
	
	  ;% proc_control_node_P.dMaxY
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 451;
	
	  ;% proc_control_node_P.dMinX
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 452;
	
	  ;% proc_control_node_P.dMinY
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 453;
	
	  ;% proc_control_node_P.dSeedX
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 454;
	
	  ;% proc_control_node_P.dSeedY
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 455;
	
	  ;% proc_control_node_P.waPhi
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 456;
	
	  ;% proc_control_node_P.waPsi
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 457;
	
	  ;% proc_control_node_P.waTheta
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 458;
	
	  ;% proc_control_node_P.waX
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 459;
	
	  ;% proc_control_node_P.waY
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 460;
	
	  ;% proc_control_node_P.waZ
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 461;
	
	  ;% proc_control_node_P.wfPhi
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 462;
	
	  ;% proc_control_node_P.wfPsi
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 463;
	
	  ;% proc_control_node_P.wfTheta
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 464;
	
	  ;% proc_control_node_P.wfX
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 465;
	
	  ;% proc_control_node_P.wfY
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 466;
	
	  ;% proc_control_node_P.wfZ
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 467;
	
	  ;% proc_control_node_P.wn_l
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 468;
	
	  ;% proc_control_node_P.wpPhi
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 469;
	
	  ;% proc_control_node_P.wpPsi
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 470;
	
	  ;% proc_control_node_P.wpTheta
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 471;
	
	  ;% proc_control_node_P.wpX
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 472;
	
	  ;% proc_control_node_P.wpY
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 473;
	
	  ;% proc_control_node_P.wpZ
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 474;
	
	  ;% proc_control_node_P.zeta_l
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 475;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.PWM
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% proc_control_node_P.BandLimitedWhiteNoise_Cov
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_Cov
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.SecondOrderFilter_FilterType
	  section.data(3).logicalSrcIdx = 34;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.DiscreteDerivative_ICPrevScaled
	  section.data(4).logicalSrcIdx = 35;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise_seed
	  section.data(5).logicalSrcIdx = 36;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_seed
	  section.data(6).logicalSrcIdx = 37;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.MinMaxRunningResettable_vinit
	  section.data(1).logicalSrcIdx = 38;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_n
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_l
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_l
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_j
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_a
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.CleanOutput_Y0
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Output_Y0
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.SensorsOutput_Y0
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_d
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_lq
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_jt
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_a3
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_p
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_hg
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_o
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_c
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_e
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_m1
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_h
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ee
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_n
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_a2
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ly
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_a
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_d
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(36) = section;
      clear section
      
      section.nData     = 203;
      section.data(203)  = dumData; %prealloc
      
	  ;% proc_control_node_P.AHRS_AccelerometerNoise
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.AHRS_GyroscopeNoise
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.AHRS_MagnetometerNoise
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.AHRS_GyroscopeDriftNoise
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.AHRS_LinearAccelerationNoise
	  section.data(5).logicalSrcIdx = 73;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.AHRS_MagneticDisturbanceNoise
	  section.data(6).logicalSrcIdx = 74;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_P.AHRS_LinearAccelerationDecayFac
	  section.data(7).logicalSrcIdx = 75;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_P.AHRS_MagneticDisturbanceDecayFa
	  section.data(8).logicalSrcIdx = 76;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_P.AHRS_ExpectedMagneticFieldStren
	  section.data(9).logicalSrcIdx = 77;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_P.IMU_Temperature
	  section.data(10).logicalSrcIdx = 78;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_P.IMU_MagneticFieldNED
	  section.data(11).logicalSrcIdx = 79;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_P.IMU_AccelParamsMeasurementRange
	  section.data(12).logicalSrcIdx = 80;
	  section.data(12).dtTransOffset = 13;
	
	  ;% proc_control_node_P.IMU_AccelParamsResolution
	  section.data(13).logicalSrcIdx = 81;
	  section.data(13).dtTransOffset = 14;
	
	  ;% proc_control_node_P.IMU_AccelParamsConstantBias
	  section.data(14).logicalSrcIdx = 82;
	  section.data(14).dtTransOffset = 15;
	
	  ;% proc_control_node_P.IMU_AccelParamsAxesMisalignment
	  section.data(15).logicalSrcIdx = 83;
	  section.data(15).dtTransOffset = 18;
	
	  ;% proc_control_node_P.IMU_AccelParamsNoiseDensity
	  section.data(16).logicalSrcIdx = 84;
	  section.data(16).dtTransOffset = 21;
	
	  ;% proc_control_node_P.IMU_AccelParamsBiasInstability
	  section.data(17).logicalSrcIdx = 85;
	  section.data(17).dtTransOffset = 24;
	
	  ;% proc_control_node_P.IMU_AccelParamsRandomWalk
	  section.data(18).logicalSrcIdx = 86;
	  section.data(18).dtTransOffset = 27;
	
	  ;% proc_control_node_P.IMU_AccelParamsTemperatureBias
	  section.data(19).logicalSrcIdx = 87;
	  section.data(19).dtTransOffset = 30;
	
	  ;% proc_control_node_P.IMU_AccelParamsTemperatureScale
	  section.data(20).logicalSrcIdx = 88;
	  section.data(20).dtTransOffset = 33;
	
	  ;% proc_control_node_P.IMU_GyroParamsMeasurementRange
	  section.data(21).logicalSrcIdx = 89;
	  section.data(21).dtTransOffset = 36;
	
	  ;% proc_control_node_P.IMU_GyroParamsResolution
	  section.data(22).logicalSrcIdx = 90;
	  section.data(22).dtTransOffset = 37;
	
	  ;% proc_control_node_P.IMU_GyroParamsConstantBias
	  section.data(23).logicalSrcIdx = 91;
	  section.data(23).dtTransOffset = 38;
	
	  ;% proc_control_node_P.IMU_GyroParamsAxesMisalignment
	  section.data(24).logicalSrcIdx = 92;
	  section.data(24).dtTransOffset = 41;
	
	  ;% proc_control_node_P.IMU_GyroParamsAccelerationBias
	  section.data(25).logicalSrcIdx = 93;
	  section.data(25).dtTransOffset = 44;
	
	  ;% proc_control_node_P.IMU_GyroParamsNoiseDensity
	  section.data(26).logicalSrcIdx = 94;
	  section.data(26).dtTransOffset = 47;
	
	  ;% proc_control_node_P.IMU_GyroParamsBiasInstability
	  section.data(27).logicalSrcIdx = 95;
	  section.data(27).dtTransOffset = 50;
	
	  ;% proc_control_node_P.IMU_GyroParamsRandomWalk
	  section.data(28).logicalSrcIdx = 96;
	  section.data(28).dtTransOffset = 53;
	
	  ;% proc_control_node_P.IMU_GyroParamsTemperatureBias
	  section.data(29).logicalSrcIdx = 97;
	  section.data(29).dtTransOffset = 56;
	
	  ;% proc_control_node_P.IMU_GyroParamsTemperatureScaleF
	  section.data(30).logicalSrcIdx = 98;
	  section.data(30).dtTransOffset = 59;
	
	  ;% proc_control_node_P.IMU_MagParamsMeasurementRange
	  section.data(31).logicalSrcIdx = 99;
	  section.data(31).dtTransOffset = 62;
	
	  ;% proc_control_node_P.IMU_MagParamsResolution
	  section.data(32).logicalSrcIdx = 100;
	  section.data(32).dtTransOffset = 63;
	
	  ;% proc_control_node_P.IMU_MagParamsConstantBias
	  section.data(33).logicalSrcIdx = 101;
	  section.data(33).dtTransOffset = 64;
	
	  ;% proc_control_node_P.IMU_MagParamsAxesMisalignment
	  section.data(34).logicalSrcIdx = 102;
	  section.data(34).dtTransOffset = 67;
	
	  ;% proc_control_node_P.IMU_MagParamsNoiseDensity
	  section.data(35).logicalSrcIdx = 103;
	  section.data(35).dtTransOffset = 70;
	
	  ;% proc_control_node_P.IMU_MagParamsBiasInstability
	  section.data(36).logicalSrcIdx = 104;
	  section.data(36).dtTransOffset = 73;
	
	  ;% proc_control_node_P.IMU_MagParamsRandomWalk
	  section.data(37).logicalSrcIdx = 105;
	  section.data(37).dtTransOffset = 76;
	
	  ;% proc_control_node_P.IMU_MagParamsTemperatureBias
	  section.data(38).logicalSrcIdx = 106;
	  section.data(38).dtTransOffset = 79;
	
	  ;% proc_control_node_P.IMU_MagParamsTemperatureScaleFa
	  section.data(39).logicalSrcIdx = 107;
	  section.data(39).dtTransOffset = 82;
	
	  ;% proc_control_node_P.TransferFcn_A
	  section.data(40).logicalSrcIdx = 108;
	  section.data(40).dtTransOffset = 85;
	
	  ;% proc_control_node_P.TransferFcn_C
	  section.data(41).logicalSrcIdx = 109;
	  section.data(41).dtTransOffset = 86;
	
	  ;% proc_control_node_P.TransferFcn_A_j
	  section.data(42).logicalSrcIdx = 110;
	  section.data(42).dtTransOffset = 87;
	
	  ;% proc_control_node_P.TransferFcn_C_m
	  section.data(43).logicalSrcIdx = 111;
	  section.data(43).dtTransOffset = 88;
	
	  ;% proc_control_node_P.TransferFcn_A_h
	  section.data(44).logicalSrcIdx = 112;
	  section.data(44).dtTransOffset = 89;
	
	  ;% proc_control_node_P.TransferFcn_C_l
	  section.data(45).logicalSrcIdx = 113;
	  section.data(45).dtTransOffset = 90;
	
	  ;% proc_control_node_P.TransferFcn_A_i
	  section.data(46).logicalSrcIdx = 114;
	  section.data(46).dtTransOffset = 91;
	
	  ;% proc_control_node_P.TransferFcn_C_f
	  section.data(47).logicalSrcIdx = 115;
	  section.data(47).dtTransOffset = 92;
	
	  ;% proc_control_node_P.TransferFcn_A_jp
	  section.data(48).logicalSrcIdx = 116;
	  section.data(48).dtTransOffset = 93;
	
	  ;% proc_control_node_P.TransferFcn_C_n
	  section.data(49).logicalSrcIdx = 117;
	  section.data(49).dtTransOffset = 94;
	
	  ;% proc_control_node_P.TransferFcn_A_l
	  section.data(50).logicalSrcIdx = 118;
	  section.data(50).dtTransOffset = 95;
	
	  ;% proc_control_node_P.TransferFcn_C_nr
	  section.data(51).logicalSrcIdx = 119;
	  section.data(51).dtTransOffset = 96;
	
	  ;% proc_control_node_P.TransferFcn_A_p
	  section.data(52).logicalSrcIdx = 120;
	  section.data(52).dtTransOffset = 97;
	
	  ;% proc_control_node_P.TransferFcn_C_h
	  section.data(53).logicalSrcIdx = 121;
	  section.data(53).dtTransOffset = 98;
	
	  ;% proc_control_node_P.TransferFcn_A_n
	  section.data(54).logicalSrcIdx = 122;
	  section.data(54).dtTransOffset = 99;
	
	  ;% proc_control_node_P.TransferFcn_C_fa
	  section.data(55).logicalSrcIdx = 123;
	  section.data(55).dtTransOffset = 100;
	
	  ;% proc_control_node_P.ZDrift_Value
	  section.data(56).logicalSrcIdx = 124;
	  section.data(56).dtTransOffset = 101;
	
	  ;% proc_control_node_P.XWave_Bias
	  section.data(57).logicalSrcIdx = 125;
	  section.data(57).dtTransOffset = 102;
	
	  ;% proc_control_node_P.YWave_Bias
	  section.data(58).logicalSrcIdx = 126;
	  section.data(58).dtTransOffset = 103;
	
	  ;% proc_control_node_P.ZWave_Bias
	  section.data(59).logicalSrcIdx = 127;
	  section.data(59).dtTransOffset = 104;
	
	  ;% proc_control_node_P.RollWave_Bias
	  section.data(60).logicalSrcIdx = 128;
	  section.data(60).dtTransOffset = 105;
	
	  ;% proc_control_node_P.PitchWave_Bias
	  section.data(61).logicalSrcIdx = 129;
	  section.data(61).dtTransOffset = 106;
	
	  ;% proc_control_node_P.YawWave_Bias
	  section.data(62).logicalSrcIdx = 130;
	  section.data(62).dtTransOffset = 107;
	
	  ;% proc_control_node_P.InitialBodyvelocity_Value
	  section.data(63).logicalSrcIdx = 131;
	  section.data(63).dtTransOffset = 108;
	
	  ;% proc_control_node_P.InitialAngularRates_Value
	  section.data(64).logicalSrcIdx = 132;
	  section.data(64).dtTransOffset = 111;
	
	  ;% proc_control_node_P.WhiteNoise_Mean
	  section.data(65).logicalSrcIdx = 133;
	  section.data(65).dtTransOffset = 114;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev
	  section.data(66).logicalSrcIdx = 134;
	  section.data(66).dtTransOffset = 115;
	
	  ;% proc_control_node_P.Gain_Gain
	  section.data(67).logicalSrcIdx = 135;
	  section.data(67).dtTransOffset = 116;
	
	  ;% proc_control_node_P.WhiteNoise_Mean_e
	  section.data(68).logicalSrcIdx = 136;
	  section.data(68).dtTransOffset = 117;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev_d
	  section.data(69).logicalSrcIdx = 137;
	  section.data(69).dtTransOffset = 118;
	
	  ;% proc_control_node_P.ydevantZhaut_Value
	  section.data(70).logicalSrcIdx = 138;
	  section.data(70).dtTransOffset = 119;
	
	  ;% proc_control_node_P.u2_Gain
	  section.data(71).logicalSrcIdx = 139;
	  section.data(71).dtTransOffset = 122;
	
	  ;% proc_control_node_P.Gain_Gain_j
	  section.data(72).logicalSrcIdx = 140;
	  section.data(72).dtTransOffset = 123;
	
	  ;% proc_control_node_P.Gain1_Gain
	  section.data(73).logicalSrcIdx = 141;
	  section.data(73).dtTransOffset = 124;
	
	  ;% proc_control_node_P.Constant_Value_k
	  section.data(74).logicalSrcIdx = 142;
	  section.data(74).dtTransOffset = 125;
	
	  ;% proc_control_node_P.Gain2_Gain
	  section.data(75).logicalSrcIdx = 143;
	  section.data(75).dtTransOffset = 126;
	
	  ;% proc_control_node_P.Gain_Gain_e
	  section.data(76).logicalSrcIdx = 144;
	  section.data(76).dtTransOffset = 127;
	
	  ;% proc_control_node_P.Gain1_Gain_e
	  section.data(77).logicalSrcIdx = 145;
	  section.data(77).dtTransOffset = 128;
	
	  ;% proc_control_node_P.Constant_Value_gp
	  section.data(78).logicalSrcIdx = 146;
	  section.data(78).dtTransOffset = 129;
	
	  ;% proc_control_node_P.Gain2_Gain_l
	  section.data(79).logicalSrcIdx = 147;
	  section.data(79).dtTransOffset = 130;
	
	  ;% proc_control_node_P.Gain_Gain_m
	  section.data(80).logicalSrcIdx = 148;
	  section.data(80).dtTransOffset = 131;
	
	  ;% proc_control_node_P.Gain1_Gain_g
	  section.data(81).logicalSrcIdx = 149;
	  section.data(81).dtTransOffset = 132;
	
	  ;% proc_control_node_P.Constant_Value_i
	  section.data(82).logicalSrcIdx = 150;
	  section.data(82).dtTransOffset = 133;
	
	  ;% proc_control_node_P.Gain2_Gain_b
	  section.data(83).logicalSrcIdx = 151;
	  section.data(83).dtTransOffset = 134;
	
	  ;% proc_control_node_P.Constant_Value_g4
	  section.data(84).logicalSrcIdx = 152;
	  section.data(84).dtTransOffset = 135;
	
	  ;% proc_control_node_P.Constant_Value_m5
	  section.data(85).logicalSrcIdx = 153;
	  section.data(85).dtTransOffset = 136;
	
	  ;% proc_control_node_P.Constant_Value_i1
	  section.data(86).logicalSrcIdx = 154;
	  section.data(86).dtTransOffset = 137;
	
	  ;% proc_control_node_P.Constant_Value_a3q
	  section.data(87).logicalSrcIdx = 155;
	  section.data(87).dtTransOffset = 138;
	
	  ;% proc_control_node_P.Constant_Value_kr
	  section.data(88).logicalSrcIdx = 156;
	  section.data(88).dtTransOffset = 139;
	
	  ;% proc_control_node_P.Constant_Value_b
	  section.data(89).logicalSrcIdx = 157;
	  section.data(89).dtTransOffset = 140;
	
	  ;% proc_control_node_P.Output_Y0_n
	  section.data(90).logicalSrcIdx = 158;
	  section.data(90).dtTransOffset = 141;
	
	  ;% proc_control_node_P.isActive_Y0
	  section.data(91).logicalSrcIdx = 159;
	  section.data(91).dtTransOffset = 142;
	
	  ;% proc_control_node_P.LastPcov_InitialCondition
	  section.data(92).logicalSrcIdx = 160;
	  section.data(92).dtTransOffset = 143;
	
	  ;% proc_control_node_P.G_zero_Value
	  section.data(93).logicalSrcIdx = 161;
	  section.data(93).dtTransOffset = 543;
	
	  ;% proc_control_node_P.ywt_zero_Value
	  section.data(94).logicalSrcIdx = 162;
	  section.data(94).dtTransOffset = 544;
	
	  ;% proc_control_node_P.uwt_zero_Value
	  section.data(95).logicalSrcIdx = 163;
	  section.data(95).dtTransOffset = 556;
	
	  ;% proc_control_node_P.duwt_zero_Value
	  section.data(96).logicalSrcIdx = 164;
	  section.data(96).dtTransOffset = 564;
	
	  ;% proc_control_node_P.extmv_zero_Value
	  section.data(97).logicalSrcIdx = 165;
	  section.data(97).dtTransOffset = 572;
	
	  ;% proc_control_node_P.extmv_scale_Gain
	  section.data(98).logicalSrcIdx = 166;
	  section.data(98).dtTransOffset = 580;
	
	  ;% proc_control_node_P.last_mv_InitialCondition
	  section.data(99).logicalSrcIdx = 167;
	  section.data(99).dtTransOffset = 588;
	
	  ;% proc_control_node_P.last_x_InitialCondition
	  section.data(100).logicalSrcIdx = 168;
	  section.data(100).dtTransOffset = 596;
	
	  ;% proc_control_node_P.Constant4_Value
	  section.data(101).logicalSrcIdx = 169;
	  section.data(101).dtTransOffset = 616;
	
	  ;% proc_control_node_P.md_zero_Value
	  section.data(102).logicalSrcIdx = 170;
	  section.data(102).dtTransOffset = 628;
	
	  ;% proc_control_node_P.umin_zero_Value
	  section.data(103).logicalSrcIdx = 171;
	  section.data(103).dtTransOffset = 629;
	
	  ;% proc_control_node_P.umax_zero_Value
	  section.data(104).logicalSrcIdx = 172;
	  section.data(104).dtTransOffset = 637;
	
	  ;% proc_control_node_P.ymin_zero_Value
	  section.data(105).logicalSrcIdx = 173;
	  section.data(105).dtTransOffset = 645;
	
	  ;% proc_control_node_P.ymax_zero_Value
	  section.data(106).logicalSrcIdx = 174;
	  section.data(106).dtTransOffset = 657;
	
	  ;% proc_control_node_P.E_zero_Value
	  section.data(107).logicalSrcIdx = 175;
	  section.data(107).dtTransOffset = 669;
	
	  ;% proc_control_node_P.umin_scale4_Gain
	  section.data(108).logicalSrcIdx = 176;
	  section.data(108).dtTransOffset = 677;
	
	  ;% proc_control_node_P.F_zero_Value
	  section.data(109).logicalSrcIdx = 177;
	  section.data(109).dtTransOffset = 685;
	
	  ;% proc_control_node_P.ymin_scale1_Gain
	  section.data(110).logicalSrcIdx = 178;
	  section.data(110).dtTransOffset = 697;
	
	  ;% proc_control_node_P.S_zero_Value
	  section.data(111).logicalSrcIdx = 179;
	  section.data(111).dtTransOffset = 709;
	
	  ;% proc_control_node_P.ymin_scale2_Gain
	  section.data(112).logicalSrcIdx = 180;
	  section.data(112).dtTransOffset = 710;
	
	  ;% proc_control_node_P.switch_zero_Value
	  section.data(113).logicalSrcIdx = 181;
	  section.data(113).dtTransOffset = 711;
	
	  ;% proc_control_node_P.mvtarget_zero_Value
	  section.data(114).logicalSrcIdx = 182;
	  section.data(114).dtTransOffset = 712;
	
	  ;% proc_control_node_P.uref_scale_Gain
	  section.data(115).logicalSrcIdx = 183;
	  section.data(115).dtTransOffset = 720;
	
	  ;% proc_control_node_P.ecrwt_zero_Value
	  section.data(116).logicalSrcIdx = 184;
	  section.data(116).dtTransOffset = 728;
	
	  ;% proc_control_node_P.Delay1_InitialCondition
	  section.data(117).logicalSrcIdx = 185;
	  section.data(117).dtTransOffset = 729;
	
	  ;% proc_control_node_P.u_scale_Gain
	  section.data(118).logicalSrcIdx = 186;
	  section.data(118).dtTransOffset = 737;
	
	  ;% proc_control_node_P.PulseGenerator_Amp
	  section.data(119).logicalSrcIdx = 187;
	  section.data(119).dtTransOffset = 745;
	
	  ;% proc_control_node_P.PulseGenerator_Period
	  section.data(120).logicalSrcIdx = 188;
	  section.data(120).dtTransOffset = 746;
	
	  ;% proc_control_node_P.PulseGenerator_Duty
	  section.data(121).logicalSrcIdx = 189;
	  section.data(121).dtTransOffset = 747;
	
	  ;% proc_control_node_P.PulseGenerator_PhaseDelay
	  section.data(122).logicalSrcIdx = 190;
	  section.data(122).dtTransOffset = 748;
	
	  ;% proc_control_node_P.MATLABSystem_k
	  section.data(123).logicalSrcIdx = 191;
	  section.data(123).dtTransOffset = 749;
	
	  ;% proc_control_node_P.TSamp_WtEt
	  section.data(124).logicalSrcIdx = 192;
	  section.data(124).dtTransOffset = 750;
	
	  ;% proc_control_node_P.Constant1_Value
	  section.data(125).logicalSrcIdx = 193;
	  section.data(125).dtTransOffset = 751;
	
	  ;% proc_control_node_P.Constant_Value_mz
	  section.data(126).logicalSrcIdx = 194;
	  section.data(126).dtTransOffset = 759;
	
	  ;% proc_control_node_P.Constant_Value_df
	  section.data(127).logicalSrcIdx = 195;
	  section.data(127).dtTransOffset = 760;
	
	  ;% proc_control_node_P.Constant7_Value
	  section.data(128).logicalSrcIdx = 196;
	  section.data(128).dtTransOffset = 761;
	
	  ;% proc_control_node_P.Constant_Value_f
	  section.data(129).logicalSrcIdx = 197;
	  section.data(129).dtTransOffset = 768;
	
	  ;% proc_control_node_P.MATLABSystem_linearConvergence
	  section.data(130).logicalSrcIdx = 198;
	  section.data(130).dtTransOffset = 781;
	
	  ;% proc_control_node_P.MATLABSystem_quaternionConverge
	  section.data(131).logicalSrcIdx = 199;
	  section.data(131).dtTransOffset = 782;
	
	  ;% proc_control_node_P.MATLABSystem_TargetThreshold
	  section.data(132).logicalSrcIdx = 200;
	  section.data(132).dtTransOffset = 783;
	
	  ;% proc_control_node_P.linWpts_Y0
	  section.data(133).logicalSrcIdx = 201;
	  section.data(133).dtTransOffset = 784;
	
	  ;% proc_control_node_P.RotWpts_Y0
	  section.data(134).logicalSrcIdx = 202;
	  section.data(134).dtTransOffset = 785;
	
	  ;% proc_control_node_P.time_Y0
	  section.data(135).logicalSrcIdx = 203;
	  section.data(135).dtTransOffset = 786;
	
	  ;% proc_control_node_P.Constant1_Value_o
	  section.data(136).logicalSrcIdx = 204;
	  section.data(136).dtTransOffset = 787;
	
	  ;% proc_control_node_P.Out1_Y0_i
	  section.data(137).logicalSrcIdx = 205;
	  section.data(137).dtTransOffset = 788;
	
	  ;% proc_control_node_P.Constant_Value_p
	  section.data(138).logicalSrcIdx = 206;
	  section.data(138).dtTransOffset = 789;
	
	  ;% proc_control_node_P.Constant_Value_hy
	  section.data(139).logicalSrcIdx = 207;
	  section.data(139).dtTransOffset = 790;
	
	  ;% proc_control_node_P.y_Y0
	  section.data(140).logicalSrcIdx = 208;
	  section.data(140).dtTransOffset = 791;
	
	  ;% proc_control_node_P.PolynomialTrajectory1_VelocityB
	  section.data(141).logicalSrcIdx = 209;
	  section.data(141).dtTransOffset = 792;
	
	  ;% proc_control_node_P.Constant_Value_ep
	  section.data(142).logicalSrcIdx = 210;
	  section.data(142).dtTransOffset = 798;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_gainval
	  section.data(143).logicalSrcIdx = 211;
	  section.data(143).dtTransOffset = 799;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_IC
	  section.data(144).logicalSrcIdx = 212;
	  section.data(144).dtTransOffset = 800;
	
	  ;% proc_control_node_P.Constant1_Value_i
	  section.data(145).logicalSrcIdx = 213;
	  section.data(145).dtTransOffset = 801;
	
	  ;% proc_control_node_P.Delay_InitialCondition
	  section.data(146).logicalSrcIdx = 214;
	  section.data(146).dtTransOffset = 803;
	
	  ;% proc_control_node_P.Constant_Value_ha
	  section.data(147).logicalSrcIdx = 215;
	  section.data(147).dtTransOffset = 804;
	
	  ;% proc_control_node_P.Constant6_Value
	  section.data(148).logicalSrcIdx = 216;
	  section.data(148).dtTransOffset = 805;
	
	  ;% proc_control_node_P.Constant_Value_m5h
	  section.data(149).logicalSrcIdx = 217;
	  section.data(149).dtTransOffset = 806;
	
	  ;% proc_control_node_P.Constant1_Value_n
	  section.data(150).logicalSrcIdx = 218;
	  section.data(150).dtTransOffset = 819;
	
	  ;% proc_control_node_P.Delay_InitialCondition_p
	  section.data(151).logicalSrcIdx = 219;
	  section.data(151).dtTransOffset = 820;
	
	  ;% proc_control_node_P.Delay_InitialCondition_a
	  section.data(152).logicalSrcIdx = 220;
	  section.data(152).dtTransOffset = 821;
	
	  ;% proc_control_node_P.Gain_Gain_h
	  section.data(153).logicalSrcIdx = 221;
	  section.data(153).dtTransOffset = 822;
	
	  ;% proc_control_node_P.Gain1_Gain_k
	  section.data(154).logicalSrcIdx = 222;
	  section.data(154).dtTransOffset = 823;
	
	  ;% proc_control_node_P.Constant_Value_ic
	  section.data(155).logicalSrcIdx = 223;
	  section.data(155).dtTransOffset = 824;
	
	  ;% proc_control_node_P.Gain2_Gain_by
	  section.data(156).logicalSrcIdx = 224;
	  section.data(156).dtTransOffset = 825;
	
	  ;% proc_control_node_P.Gain_Gain_n
	  section.data(157).logicalSrcIdx = 225;
	  section.data(157).dtTransOffset = 826;
	
	  ;% proc_control_node_P.Constant_Value_pg
	  section.data(158).logicalSrcIdx = 226;
	  section.data(158).dtTransOffset = 827;
	
	  ;% proc_control_node_P.Gain2_Gain_lp
	  section.data(159).logicalSrcIdx = 227;
	  section.data(159).dtTransOffset = 828;
	
	  ;% proc_control_node_P.Gain1_Gain_f
	  section.data(160).logicalSrcIdx = 228;
	  section.data(160).dtTransOffset = 829;
	
	  ;% proc_control_node_P.Constant_Value_l4
	  section.data(161).logicalSrcIdx = 229;
	  section.data(161).dtTransOffset = 830;
	
	  ;% proc_control_node_P.Gain2_Gain_a
	  section.data(162).logicalSrcIdx = 230;
	  section.data(162).dtTransOffset = 831;
	
	  ;% proc_control_node_P.Gain_Gain_l
	  section.data(163).logicalSrcIdx = 231;
	  section.data(163).dtTransOffset = 832;
	
	  ;% proc_control_node_P.Gain1_Gain_fe
	  section.data(164).logicalSrcIdx = 232;
	  section.data(164).dtTransOffset = 833;
	
	  ;% proc_control_node_P.Gain_Gain_m3
	  section.data(165).logicalSrcIdx = 233;
	  section.data(165).dtTransOffset = 834;
	
	  ;% proc_control_node_P.Constant_Value_g0
	  section.data(166).logicalSrcIdx = 234;
	  section.data(166).dtTransOffset = 835;
	
	  ;% proc_control_node_P.Gain2_Gain_f
	  section.data(167).logicalSrcIdx = 235;
	  section.data(167).dtTransOffset = 836;
	
	  ;% proc_control_node_P.Gain_Gain_p
	  section.data(168).logicalSrcIdx = 236;
	  section.data(168).dtTransOffset = 837;
	
	  ;% proc_control_node_P.Gain1_Gain_gc
	  section.data(169).logicalSrcIdx = 237;
	  section.data(169).dtTransOffset = 838;
	
	  ;% proc_control_node_P.Gain_Gain_i
	  section.data(170).logicalSrcIdx = 238;
	  section.data(170).dtTransOffset = 839;
	
	  ;% proc_control_node_P.Constant_Value_h3
	  section.data(171).logicalSrcIdx = 239;
	  section.data(171).dtTransOffset = 840;
	
	  ;% proc_control_node_P.Gain2_Gain_ah
	  section.data(172).logicalSrcIdx = 240;
	  section.data(172).dtTransOffset = 841;
	
	  ;% proc_control_node_P.Gain1_Gain_kt
	  section.data(173).logicalSrcIdx = 241;
	  section.data(173).dtTransOffset = 842;
	
	  ;% proc_control_node_P.Gain_Gain_o
	  section.data(174).logicalSrcIdx = 242;
	  section.data(174).dtTransOffset = 843;
	
	  ;% proc_control_node_P.Gain1_Gain_l
	  section.data(175).logicalSrcIdx = 243;
	  section.data(175).dtTransOffset = 844;
	
	  ;% proc_control_node_P.Constant_Value_bb
	  section.data(176).logicalSrcIdx = 244;
	  section.data(176).dtTransOffset = 845;
	
	  ;% proc_control_node_P.Gain2_Gain_n
	  section.data(177).logicalSrcIdx = 245;
	  section.data(177).dtTransOffset = 846;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_gainva_o
	  section.data(178).logicalSrcIdx = 246;
	  section.data(178).dtTransOffset = 847;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator1_gainval
	  section.data(179).logicalSrcIdx = 247;
	  section.data(179).dtTransOffset = 848;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator1_IC
	  section.data(180).logicalSrcIdx = 248;
	  section.data(180).dtTransOffset = 849;
	
	  ;% proc_control_node_P.Gain_Gain_g
	  section.data(181).logicalSrcIdx = 249;
	  section.data(181).dtTransOffset = 850;
	
	  ;% proc_control_node_P.Constant_Value_as
	  section.data(182).logicalSrcIdx = 250;
	  section.data(182).dtTransOffset = 851;
	
	  ;% proc_control_node_P.Constant3_Value
	  section.data(183).logicalSrcIdx = 251;
	  section.data(183).dtTransOffset = 852;
	
	  ;% proc_control_node_P.Integrator_gainval
	  section.data(184).logicalSrcIdx = 252;
	  section.data(184).dtTransOffset = 853;
	
	  ;% proc_control_node_P.Integrator_UpperSat
	  section.data(185).logicalSrcIdx = 253;
	  section.data(185).dtTransOffset = 854;
	
	  ;% proc_control_node_P.Integrator_LowerSat
	  section.data(186).logicalSrcIdx = 254;
	  section.data(186).dtTransOffset = 855;
	
	  ;% proc_control_node_P.Saturation_UpperSat
	  section.data(187).logicalSrcIdx = 255;
	  section.data(187).dtTransOffset = 856;
	
	  ;% proc_control_node_P.Saturation_LowerSat
	  section.data(188).logicalSrcIdx = 256;
	  section.data(188).dtTransOffset = 857;
	
	  ;% proc_control_node_P.Gain3_Gain
	  section.data(189).logicalSrcIdx = 257;
	  section.data(189).dtTransOffset = 858;
	
	  ;% proc_control_node_P.Constant1_Value_d
	  section.data(190).logicalSrcIdx = 258;
	  section.data(190).dtTransOffset = 859;
	
	  ;% proc_control_node_P.Constant2_Value
	  section.data(191).logicalSrcIdx = 259;
	  section.data(191).dtTransOffset = 860;
	
	  ;% proc_control_node_P.Integrator_gainval_e
	  section.data(192).logicalSrcIdx = 260;
	  section.data(192).dtTransOffset = 861;
	
	  ;% proc_control_node_P.Integrator_UpperSat_f
	  section.data(193).logicalSrcIdx = 261;
	  section.data(193).dtTransOffset = 862;
	
	  ;% proc_control_node_P.Integrator_LowerSat_p
	  section.data(194).logicalSrcIdx = 262;
	  section.data(194).dtTransOffset = 863;
	
	  ;% proc_control_node_P.Saturation_UpperSat_m
	  section.data(195).logicalSrcIdx = 263;
	  section.data(195).dtTransOffset = 864;
	
	  ;% proc_control_node_P.Saturation_LowerSat_c
	  section.data(196).logicalSrcIdx = 264;
	  section.data(196).dtTransOffset = 865;
	
	  ;% proc_control_node_P.Gain_Gain_ga
	  section.data(197).logicalSrcIdx = 265;
	  section.data(197).dtTransOffset = 866;
	
	  ;% proc_control_node_P.Delay_InitialCondition_j
	  section.data(198).logicalSrcIdx = 266;
	  section.data(198).dtTransOffset = 867;
	
	  ;% proc_control_node_P.Delay_InitialCondition_f
	  section.data(199).logicalSrcIdx = 267;
	  section.data(199).dtTransOffset = 868;
	
	  ;% proc_control_node_P.Constant_Value_j
	  section.data(200).logicalSrcIdx = 268;
	  section.data(200).dtTransOffset = 869;
	
	  ;% proc_control_node_P.Constant_Value_oo
	  section.data(201).logicalSrcIdx = 269;
	  section.data(201).dtTransOffset = 872;
	
	  ;% proc_control_node_P.Constant6_Value_i
	  section.data(202).logicalSrcIdx = 270;
	  section.data(202).dtTransOffset = 875;
	
	  ;% proc_control_node_P.Constant6_Value_o
	  section.data(203).logicalSrcIdx = 271;
	  section.data(203).dtTransOffset = 876;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.FixedHorizonOptimizer_Ndis
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(38) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Memory_InitialCondition
	  section.data(1).logicalSrcIdx = 273;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.Delay1_InitialCondition_k
	  section.data(2).logicalSrcIdx = 274;
	  section.data(2).dtTransOffset = 64;
	
	  ;% proc_control_node_P.Merge1_InitialOutput
	  section.data(3).logicalSrcIdx = 275;
	  section.data(3).dtTransOffset = 65;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(39) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Subsystem2_p.Quat_Y0
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.Subsystem2_p.siydevant_Value
	  section.data(2).logicalSrcIdx = 277;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.Subsystem2_p.u2_Gain
	  section.data(3).logicalSrcIdx = 278;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(40) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Subsystem2.Quat_Y0
	  section.data(1).logicalSrcIdx = 279;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.Subsystem2.siydevant_Value
	  section.data(2).logicalSrcIdx = 280;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.Subsystem2.u2_Gain
	  section.data(3).logicalSrcIdx = 281;
	  section.data(3).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(41) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 13;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (proc_control_node_B)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_f
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_n
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_o
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_B.MultiportSwitch
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Quaternion
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 6;
	
	  ;% proc_control_node_B.Merge
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 136;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.y
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.RotationTrajectory_o1
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_B.RotationTrajectory_o2
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Transpose
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 3;
	
	  ;% proc_control_node_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 29;
	  section.data(3).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.NtoRPM
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 70;
      section.data(70)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Z
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Y
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_B.X
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_B.Sum
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_B.Sum_c
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_B.Sum_f
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_B.qW2S
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_B.WorldPosition
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 10;
	
	  ;% proc_control_node_B.Divide3
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 13;
	
	  ;% proc_control_node_B.Divide2
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 14;
	
	  ;% proc_control_node_B.Divide1
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 15;
	
	  ;% proc_control_node_B.Divide
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 16;
	
	  ;% proc_control_node_B.BodyPosition
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 17;
	
	  ;% proc_control_node_B.DataTypeConversion2
	  section.data(14).logicalSrcIdx = 31;
	  section.data(14).dtTransOffset = 20;
	
	  ;% proc_control_node_B.Transpose_i
	  section.data(15).logicalSrcIdx = 32;
	  section.data(15).dtTransOffset = 21;
	
	  ;% proc_control_node_B.Selector1
	  section.data(16).logicalSrcIdx = 33;
	  section.data(16).dtTransOffset = 37;
	
	  ;% proc_control_node_B.Selector
	  section.data(17).logicalSrcIdx = 34;
	  section.data(17).dtTransOffset = 45;
	
	  ;% proc_control_node_B.MatrixConcatenate
	  section.data(18).logicalSrcIdx = 35;
	  section.data(18).dtTransOffset = 51;
	
	  ;% proc_control_node_B.q0
	  section.data(19).logicalSrcIdx = 36;
	  section.data(19).dtTransOffset = 53;
	
	  ;% proc_control_node_B.q1
	  section.data(20).logicalSrcIdx = 37;
	  section.data(20).dtTransOffset = 54;
	
	  ;% proc_control_node_B.q2
	  section.data(21).logicalSrcIdx = 38;
	  section.data(21).dtTransOffset = 55;
	
	  ;% proc_control_node_B.q3
	  section.data(22).logicalSrcIdx = 39;
	  section.data(22).dtTransOffset = 56;
	
	  ;% proc_control_node_B.MATLABSystem
	  section.data(23).logicalSrcIdx = 40;
	  section.data(23).dtTransOffset = 57;
	
	  ;% proc_control_node_B.PulseGenerator
	  section.data(24).logicalSrcIdx = 41;
	  section.data(24).dtTransOffset = 65;
	
	  ;% proc_control_node_B.status
	  section.data(25).logicalSrcIdx = 42;
	  section.data(25).dtTransOffset = 66;
	
	  ;% proc_control_node_B.q0_c
	  section.data(26).logicalSrcIdx = 43;
	  section.data(26).dtTransOffset = 67;
	
	  ;% proc_control_node_B.q1_p
	  section.data(27).logicalSrcIdx = 44;
	  section.data(27).dtTransOffset = 68;
	
	  ;% proc_control_node_B.q2_k
	  section.data(28).logicalSrcIdx = 45;
	  section.data(28).dtTransOffset = 69;
	
	  ;% proc_control_node_B.q3_d
	  section.data(29).logicalSrcIdx = 46;
	  section.data(29).dtTransOffset = 70;
	
	  ;% proc_control_node_B.Quaternion_l
	  section.data(30).logicalSrcIdx = 47;
	  section.data(30).dtTransOffset = 71;
	
	  ;% proc_control_node_B.WorldPosition_o
	  section.data(31).logicalSrcIdx = 48;
	  section.data(31).dtTransOffset = 75;
	
	  ;% proc_control_node_B.BodyVelocity
	  section.data(32).logicalSrcIdx = 49;
	  section.data(32).dtTransOffset = 78;
	
	  ;% proc_control_node_B.AngularRate
	  section.data(33).logicalSrcIdx = 50;
	  section.data(33).dtTransOffset = 81;
	
	  ;% proc_control_node_B.y_g
	  section.data(34).logicalSrcIdx = 51;
	  section.data(34).dtTransOffset = 84;
	
	  ;% proc_control_node_B.VectorConcatenate
	  section.data(35).logicalSrcIdx = 52;
	  section.data(35).dtTransOffset = 85;
	
	  ;% proc_control_node_B.PWMtoN
	  section.data(36).logicalSrcIdx = 53;
	  section.data(36).dtTransOffset = 88;
	
	  ;% proc_control_node_B.XDrift
	  section.data(37).logicalSrcIdx = 62;
	  section.data(37).dtTransOffset = 96;
	
	  ;% proc_control_node_B.YDrift
	  section.data(38).logicalSrcIdx = 63;
	  section.data(38).dtTransOffset = 97;
	
	  ;% proc_control_node_B.ZDrift
	  section.data(39).logicalSrcIdx = 64;
	  section.data(39).dtTransOffset = 98;
	
	  ;% proc_control_node_B.XWave
	  section.data(40).logicalSrcIdx = 65;
	  section.data(40).dtTransOffset = 99;
	
	  ;% proc_control_node_B.YWave
	  section.data(41).logicalSrcIdx = 66;
	  section.data(41).dtTransOffset = 100;
	
	  ;% proc_control_node_B.ZWave
	  section.data(42).logicalSrcIdx = 67;
	  section.data(42).dtTransOffset = 101;
	
	  ;% proc_control_node_B.WorldPosition_d
	  section.data(43).logicalSrcIdx = 73;
	  section.data(43).dtTransOffset = 102;
	
	  ;% proc_control_node_B.InitialBodyvelocity
	  section.data(44).logicalSrcIdx = 74;
	  section.data(44).dtTransOffset = 105;
	
	  ;% proc_control_node_B.BodyVelocity_c
	  section.data(45).logicalSrcIdx = 75;
	  section.data(45).dtTransOffset = 108;
	
	  ;% proc_control_node_B.InitialAngularRates
	  section.data(46).logicalSrcIdx = 76;
	  section.data(46).dtTransOffset = 111;
	
	  ;% proc_control_node_B.AngularRate_e
	  section.data(47).logicalSrcIdx = 77;
	  section.data(47).dtTransOffset = 114;
	
	  ;% proc_control_node_B.Output
	  section.data(48).logicalSrcIdx = 82;
	  section.data(48).dtTransOffset = 117;
	
	  ;% proc_control_node_B.Quaternion_k
	  section.data(49).logicalSrcIdx = 83;
	  section.data(49).dtTransOffset = 118;
	
	  ;% proc_control_node_B.Output_i
	  section.data(50).logicalSrcIdx = 85;
	  section.data(50).dtTransOffset = 122;
	
	  ;% proc_control_node_B.AngularRate_d
	  section.data(51).logicalSrcIdx = 86;
	  section.data(51).dtTransOffset = 123;
	
	  ;% proc_control_node_B.Gain_c
	  section.data(52).logicalSrcIdx = 87;
	  section.data(52).dtTransOffset = 126;
	
	  ;% proc_control_node_B.Gain1
	  section.data(53).logicalSrcIdx = 88;
	  section.data(53).dtTransOffset = 127;
	
	  ;% proc_control_node_B.Gain2
	  section.data(54).logicalSrcIdx = 89;
	  section.data(54).dtTransOffset = 128;
	
	  ;% proc_control_node_B.Sum_d
	  section.data(55).logicalSrcIdx = 90;
	  section.data(55).dtTransOffset = 129;
	
	  ;% proc_control_node_B.Gain_cr
	  section.data(56).logicalSrcIdx = 91;
	  section.data(56).dtTransOffset = 130;
	
	  ;% proc_control_node_B.Gain1_d
	  section.data(57).logicalSrcIdx = 92;
	  section.data(57).dtTransOffset = 131;
	
	  ;% proc_control_node_B.Gain2_n
	  section.data(58).logicalSrcIdx = 93;
	  section.data(58).dtTransOffset = 132;
	
	  ;% proc_control_node_B.Sum_i
	  section.data(59).logicalSrcIdx = 94;
	  section.data(59).dtTransOffset = 133;
	
	  ;% proc_control_node_B.Gain_l
	  section.data(60).logicalSrcIdx = 95;
	  section.data(60).dtTransOffset = 134;
	
	  ;% proc_control_node_B.Gain1_o
	  section.data(61).logicalSrcIdx = 96;
	  section.data(61).dtTransOffset = 135;
	
	  ;% proc_control_node_B.Gain2_i
	  section.data(62).logicalSrcIdx = 97;
	  section.data(62).dtTransOffset = 136;
	
	  ;% proc_control_node_B.Sum_p
	  section.data(63).logicalSrcIdx = 98;
	  section.data(63).dtTransOffset = 137;
	
	  ;% proc_control_node_B.AHRS_o1
	  section.data(64).logicalSrcIdx = 99;
	  section.data(64).dtTransOffset = 138;
	
	  ;% proc_control_node_B.y_gh
	  section.data(65).logicalSrcIdx = 100;
	  section.data(65).dtTransOffset = 142;
	
	  ;% proc_control_node_B.Position_dot
	  section.data(66).logicalSrcIdx = 101;
	  section.data(66).dtTransOffset = 146;
	
	  ;% proc_control_node_B.Quaternion_dot
	  section.data(67).logicalSrcIdx = 102;
	  section.data(67).dtTransOffset = 149;
	
	  ;% proc_control_node_B.BodyVelocity_dot
	  section.data(68).logicalSrcIdx = 103;
	  section.data(68).dtTransOffset = 153;
	
	  ;% proc_control_node_B.AngularRates_dot
	  section.data(69).logicalSrcIdx = 104;
	  section.data(69).dtTransOffset = 156;
	
	  ;% proc_control_node_B.Merge_f
	  section.data(70).logicalSrcIdx = 105;
	  section.data(70).dtTransOffset = 159;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_b
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Data
	  section.data(1).logicalSrcIdx = 108;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_B.OR
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Reset
	  section.data(2).logicalSrcIdx = 110;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_B.Merge1
	  section.data(3).logicalSrcIdx = 111;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 20;
    sectIdxOffset = 13;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (proc_control_node_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_c
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_l
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_m
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_j
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_jo
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_a
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_a4
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_f
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_e
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_o
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_g
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_h
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_cs
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_mm
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_lu
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_le
	  section.data(1).logicalSrcIdx = 16;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_lj
	  section.data(2).logicalSrcIdx = 17;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_lf
	  section.data(3).logicalSrcIdx = 18;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_eb
	  section.data(4).logicalSrcIdx = 19;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_lfp
	  section.data(5).logicalSrcIdx = 20;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_mj
	  section.data(6).logicalSrcIdx = 21;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_p
	  section.data(7).logicalSrcIdx = 22;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_ab
	  section.data(8).logicalSrcIdx = 23;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_k
	  section.data(9).logicalSrcIdx = 24;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 19;
      section.data(19)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Delay_DSTATE_c
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.Integrator_DSTATE
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.Integrator_DSTATE_l
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Delay_DSTATE_d
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.Delay_DSTATE_d1
	  section.data(8).logicalSrcIdx = 32;
	  section.data(8).dtTransOffset = 23;
	
	  ;% proc_control_node_DW.Delay_DSTATE_n
	  section.data(9).logicalSrcIdx = 33;
	  section.data(9).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_b
	  section.data(10).logicalSrcIdx = 34;
	  section.data(10).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.UD_DSTATE
	  section.data(11).logicalSrcIdx = 42;
	  section.data(11).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.last_mv_DSTATE
	  section.data(12).logicalSrcIdx = 43;
	  section.data(12).dtTransOffset = 32;
	
	  ;% proc_control_node_DW.Delay1_DSTATE
	  section.data(13).logicalSrcIdx = 44;
	  section.data(13).dtTransOffset = 40;
	
	  ;% proc_control_node_DW.LastPcov_PreviousInput
	  section.data(14).logicalSrcIdx = 45;
	  section.data(14).dtTransOffset = 48;
	
	  ;% proc_control_node_DW.last_x_PreviousInput
	  section.data(15).logicalSrcIdx = 46;
	  section.data(15).dtTransOffset = 448;
	
	  ;% proc_control_node_DW.XDrift_NextOutput
	  section.data(16).logicalSrcIdx = 47;
	  section.data(16).dtTransOffset = 468;
	
	  ;% proc_control_node_DW.YDrift_NextOutput
	  section.data(17).logicalSrcIdx = 48;
	  section.data(17).dtTransOffset = 469;
	
	  ;% proc_control_node_DW.NextOutput
	  section.data(18).logicalSrcIdx = 49;
	  section.data(18).dtTransOffset = 470;
	
	  ;% proc_control_node_DW.NextOutput_b
	  section.data(19).logicalSrcIdx = 50;
	  section.data(19).dtTransOffset = 471;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 52;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Scope3_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 53;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Scope1_PWORK_n.LoggedData
	  section.data(4).logicalSrcIdx = 54;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.Scope1_PWORK_k.LoggedData
	  section.data(5).logicalSrcIdx = 55;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.Scope_PWORK_i.LoggedData
	  section.data(6).logicalSrcIdx = 56;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.Scope_PWORK_c.LoggedData
	  section.data(7).logicalSrcIdx = 57;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.Scope_PWORK_cp.LoggedData
	  section.data(8).logicalSrcIdx = 58;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.Scope1_PWORK_nr.LoggedData
	  section.data(9).logicalSrcIdx = 59;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.Scope1_PWORK_g.LoggedData
	  section.data(10).logicalSrcIdx = 60;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.Scope_PWORK_e.LoggedData
	  section.data(11).logicalSrcIdx = 61;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.Scope_PWORK_n.LoggedData
	  section.data(12).logicalSrcIdx = 62;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.Scope1_PWORK_h.LoggedData
	  section.data(13).logicalSrcIdx = 63;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.Scope_PWORK_f.LoggedData
	  section.data(14).logicalSrcIdx = 64;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.Scope2_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 65;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.Scope3_PWORK_c.LoggedData
	  section.data(16).logicalSrcIdx = 66;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.Scope4_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 67;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Scope_PWORK_l.LoggedData
	  section.data(18).logicalSrcIdx = 68;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.Scope_PWORK_cg.LoggedData
	  section.data(19).logicalSrcIdx = 69;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.Scope_PWORK_m.LoggedData
	  section.data(20).logicalSrcIdx = 70;
	  section.data(20).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.Scope1_PWORK_a.LoggedData
	  section.data(21).logicalSrcIdx = 71;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.m_bpIndex
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.m_bpIndex_m
	  section.data(2).logicalSrcIdx = 74;
	  section.data(2).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.m_bpIndex_c
	  section.data(3).logicalSrcIdx = 75;
	  section.data(3).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.RandSeed
	  section.data(4).logicalSrcIdx = 76;
	  section.data(4).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.RandSeed_a
	  section.data(5).logicalSrcIdx = 77;
	  section.data(5).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.RandSeed_j
	  section.data(6).logicalSrcIdx = 78;
	  section.data(6).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.RandSeed_d
	  section.data(7).logicalSrcIdx = 79;
	  section.data(7).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Integrator_IWORK
	  section.data(2).logicalSrcIdx = 81;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Integrator2_IWORK
	  section.data(3).logicalSrcIdx = 82;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Integrator3_IWORK
	  section.data(4).logicalSrcIdx = 83;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Delay1_DSTATE_c
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator1_PrevRes
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.If_ActiveSubsystem
	  section.data(3).logicalSrcIdx = 88;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Integrator_PrevResetState
	  section.data(4).logicalSrcIdx = 89;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.Integrator_PrevResetState_h
	  section.data(5).logicalSrcIdx = 90;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem
	  section.data(6).logicalSrcIdx = 91;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem_l
	  section.data(7).logicalSrcIdx = 92;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.If_ActiveSubsystem_l
	  section.data(8).logicalSrcIdx = 93;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC
	  section.data(9).logicalSrcIdx = 94;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e
	  section.data(10).logicalSrcIdx = 95;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_k
	  section.data(11).logicalSrcIdx = 96;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_kg
	  section.data(12).logicalSrcIdx = 97;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_d
	  section.data(13).logicalSrcIdx = 98;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC
	  section.data(14).logicalSrcIdx = 99;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.singleWptsTrajectory_SubsysRanB
	  section.data(15).logicalSrcIdx = 100;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_p
	  section.data(16).logicalSrcIdx = 101;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(17).logicalSrcIdx = 102;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(18).logicalSrcIdx = 103;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_n
	  section.data(19).logicalSrcIdx = 104;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.Subsystem1_SubsysRanBC
	  section.data(20).logicalSrcIdx = 105;
	  section.data(20).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(21).logicalSrcIdx = 106;
	  section.data(21).dtTransOffset = 20;
	
	  ;% proc_control_node_DW.Pretraitement_SubsysRanBC
	  section.data(22).logicalSrcIdx = 107;
	  section.data(22).dtTransOffset = 21;
	
	  ;% proc_control_node_DW.SubsystemAuto_SubsysRanBC
	  section.data(23).logicalSrcIdx = 108;
	  section.data(23).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.SubsystemManual_SubsysRanBC
	  section.data(24).logicalSrcIdx = 109;
	  section.data(24).dtTransOffset = 23;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n
	  section.data(25).logicalSrcIdx = 110;
	  section.data(25).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_b
	  section.data(26).logicalSrcIdx = 111;
	  section.data(26).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_i
	  section.data(27).logicalSrcIdx = 112;
	  section.data(27).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_l
	  section.data(28).logicalSrcIdx = 113;
	  section.data(28).dtTransOffset = 27;
	
	  ;% proc_control_node_DW.IDLE_SubsysRanBC
	  section.data(29).logicalSrcIdx = 114;
	  section.data(29).dtTransOffset = 28;
	
	  ;% proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC
	  section.data(30).logicalSrcIdx = 115;
	  section.data(30).dtTransOffset = 29;
	
	  ;% proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa
	  section.data(31).logicalSrcIdx = 116;
	  section.data(31).dtTransOffset = 30;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_o
	  section.data(32).logicalSrcIdx = 117;
	  section.data(32).dtTransOffset = 31;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_h
	  section.data(33).logicalSrcIdx = 118;
	  section.data(33).dtTransOffset = 32;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_c
	  section.data(34).logicalSrcIdx = 119;
	  section.data(34).dtTransOffset = 33;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_g
	  section.data(35).logicalSrcIdx = 120;
	  section.data(35).dtTransOffset = 34;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_b
	  section.data(36).logicalSrcIdx = 121;
	  section.data(36).dtTransOffset = 35;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_m
	  section.data(37).logicalSrcIdx = 122;
	  section.data(37).dtTransOffset = 36;
	
	  ;% proc_control_node_DW.SendTargetReached_SubsysRanBC
	  section.data(38).logicalSrcIdx = 123;
	  section.data(38).dtTransOffset = 37;
	
	  ;% proc_control_node_DW.ROSOutput_SubsysRanBC
	  section.data(39).logicalSrcIdx = 124;
	  section.data(39).dtTransOffset = 38;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g
	  section.data(40).logicalSrcIdx = 125;
	  section.data(40).dtTransOffset = 39;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_pz
	  section.data(41).logicalSrcIdx = 126;
	  section.data(41).dtTransOffset = 40;
	
	  ;% proc_control_node_DW.Plotvalues_SubsysRanBC
	  section.data(42).logicalSrcIdx = 127;
	  section.data(42).dtTransOffset = 41;
	
	  ;% proc_control_node_DW.If_ActiveSubsystem_j
	  section.data(43).logicalSrcIdx = 128;
	  section.data(43).dtTransOffset = 42;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_d
	  section.data(44).logicalSrcIdx = 129;
	  section.data(44).dtTransOffset = 43;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_k
	  section.data(45).logicalSrcIdx = 130;
	  section.data(45).dtTransOffset = 44;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_f
	  section.data(46).logicalSrcIdx = 131;
	  section.data(46).dtTransOffset = 45;
	
	  ;% proc_control_node_DW.ModlePhysique_SubsysRanBC
	  section.data(47).logicalSrcIdx = 132;
	  section.data(47).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI
	  section.data(1).logicalSrcIdx = 133;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 134;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Memory_PreviousInput_o
	  section.data(2).logicalSrcIdx = 147;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.ROSOutput_MODE
	  section.data(3).logicalSrcIdx = 161;
	  section.data(3).dtTransOffset = 65;
	
	  ;% proc_control_node_DW.Plotvalues_MODE
	  section.data(4).logicalSrcIdx = 162;
	  section.data(4).dtTransOffset = 66;
	
	  ;% proc_control_node_DW.ModlePhysique_MODE
	  section.data(5).logicalSrcIdx = 163;
	  section.data(5).dtTransOffset = 67;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Subsystem2_p.Subsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 164;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Subsystem2.Subsystem2_SubsysRanBC
	  section.data(1).logicalSrcIdx = 165;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2204037515;
  targMap.checksum1 = 3238934813;
  targMap.checksum2 = 3948677549;
  targMap.checksum3 = 2960805777;

