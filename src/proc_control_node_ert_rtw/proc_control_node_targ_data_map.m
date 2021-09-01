  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 48;
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
      
	  ;% proc_control_node_P.mpc
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
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.simulation
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Config10
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.Config19
	  section.data(2).logicalSrcIdx = 4;
	  section.data(2).dtTransOffset = 29;
	
	  ;% proc_control_node_P.N
	  section.data(3).logicalSrcIdx = 5;
	  section.data(3).dtTransOffset = 58;
	
	  ;% proc_control_node_P.RPM
	  section.data(4).logicalSrcIdx = 6;
	  section.data(4).dtTransOffset = 259;
	
	  ;% proc_control_node_P.Ui
	  section.data(5).logicalSrcIdx = 7;
	  section.data(5).dtTransOffset = 460;
	
	  ;% proc_control_node_P.binv
	  section.data(6).logicalSrcIdx = 8;
	  section.data(6).dtTransOffset = 468;
	
	  ;% proc_control_node_P.constValues
	  section.data(7).logicalSrcIdx = 9;
	  section.data(7).dtTransOffset = 516;
	
	  ;% proc_control_node_P.dMaxX
	  section.data(8).logicalSrcIdx = 10;
	  section.data(8).dtTransOffset = 557;
	
	  ;% proc_control_node_P.dMaxY
	  section.data(9).logicalSrcIdx = 11;
	  section.data(9).dtTransOffset = 558;
	
	  ;% proc_control_node_P.dMinX
	  section.data(10).logicalSrcIdx = 12;
	  section.data(10).dtTransOffset = 559;
	
	  ;% proc_control_node_P.dMinY
	  section.data(11).logicalSrcIdx = 13;
	  section.data(11).dtTransOffset = 560;
	
	  ;% proc_control_node_P.dSeedX
	  section.data(12).logicalSrcIdx = 14;
	  section.data(12).dtTransOffset = 561;
	
	  ;% proc_control_node_P.dSeedY
	  section.data(13).logicalSrcIdx = 15;
	  section.data(13).dtTransOffset = 562;
	
	  ;% proc_control_node_P.waPhi
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 563;
	
	  ;% proc_control_node_P.waPsi
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 564;
	
	  ;% proc_control_node_P.waTheta
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 565;
	
	  ;% proc_control_node_P.waX
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 566;
	
	  ;% proc_control_node_P.waY
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 567;
	
	  ;% proc_control_node_P.waZ
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 568;
	
	  ;% proc_control_node_P.wfPhi
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 569;
	
	  ;% proc_control_node_P.wfPsi
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 570;
	
	  ;% proc_control_node_P.wfTheta
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 571;
	
	  ;% proc_control_node_P.wfX
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 572;
	
	  ;% proc_control_node_P.wfY
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 573;
	
	  ;% proc_control_node_P.wfZ
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 574;
	
	  ;% proc_control_node_P.wn_l
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 575;
	
	  ;% proc_control_node_P.wpPhi
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 576;
	
	  ;% proc_control_node_P.wpPsi
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 577;
	
	  ;% proc_control_node_P.wpTheta
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 578;
	
	  ;% proc_control_node_P.wpX
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 579;
	
	  ;% proc_control_node_P.wpY
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 580;
	
	  ;% proc_control_node_P.wpZ
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 581;
	
	  ;% proc_control_node_P.zeta_l
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 582;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.PWM
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% proc_control_node_P.BandLimitedWhiteNoise_Cov
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_Cov
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.SecondOrderFilter_FilterType
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.DiscreteDerivative_ICPrevScaled
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise_seed
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_seed
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.MinMaxRunningResettable_vinit
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_j
	  section.data(1).logicalSrcIdx = 45;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_p
	  section.data(1).logicalSrcIdx = 46;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_d
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 48;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_d5
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_py
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_a
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_c
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_n
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.CleanOutput_Y0
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Output_Y0
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.SensorsOutput_Y0
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_h
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_gj
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_e
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ck
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_g5
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_k
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_o
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_b
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_p3
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_e
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_mi
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_au
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_o
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_g5r
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_ki
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ch
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_m
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(40) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_pn
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_ae
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(43) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_kv
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(44) = section;
      clear section
      
      section.nData     = 198;
      section.data(198)  = dumData; %prealloc
      
	  ;% proc_control_node_P.AHRS_AccelerometerNoise
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.AHRS_GyroscopeNoise
	  section.data(2).logicalSrcIdx = 82;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.AHRS_MagnetometerNoise
	  section.data(3).logicalSrcIdx = 83;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.AHRS_GyroscopeDriftNoise
	  section.data(4).logicalSrcIdx = 84;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.AHRS_LinearAccelerationNoise
	  section.data(5).logicalSrcIdx = 85;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.AHRS_MagneticDisturbanceNoise
	  section.data(6).logicalSrcIdx = 86;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_P.AHRS_LinearAccelerationDecayFac
	  section.data(7).logicalSrcIdx = 87;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_P.AHRS_MagneticDisturbanceDecayFa
	  section.data(8).logicalSrcIdx = 88;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_P.AHRS_ExpectedMagneticFieldStren
	  section.data(9).logicalSrcIdx = 89;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_P.IMU_Temperature
	  section.data(10).logicalSrcIdx = 90;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_P.IMU_MagneticFieldNED
	  section.data(11).logicalSrcIdx = 91;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_P.IMU_AccelParamsMeasurementRange
	  section.data(12).logicalSrcIdx = 92;
	  section.data(12).dtTransOffset = 13;
	
	  ;% proc_control_node_P.IMU_AccelParamsResolution
	  section.data(13).logicalSrcIdx = 93;
	  section.data(13).dtTransOffset = 14;
	
	  ;% proc_control_node_P.IMU_AccelParamsConstantBias
	  section.data(14).logicalSrcIdx = 94;
	  section.data(14).dtTransOffset = 15;
	
	  ;% proc_control_node_P.IMU_AccelParamsAxesMisalignment
	  section.data(15).logicalSrcIdx = 95;
	  section.data(15).dtTransOffset = 18;
	
	  ;% proc_control_node_P.IMU_AccelParamsNoiseDensity
	  section.data(16).logicalSrcIdx = 96;
	  section.data(16).dtTransOffset = 21;
	
	  ;% proc_control_node_P.IMU_AccelParamsBiasInstability
	  section.data(17).logicalSrcIdx = 97;
	  section.data(17).dtTransOffset = 24;
	
	  ;% proc_control_node_P.IMU_AccelParamsRandomWalk
	  section.data(18).logicalSrcIdx = 98;
	  section.data(18).dtTransOffset = 27;
	
	  ;% proc_control_node_P.IMU_AccelParamsTemperatureBias
	  section.data(19).logicalSrcIdx = 99;
	  section.data(19).dtTransOffset = 30;
	
	  ;% proc_control_node_P.IMU_AccelParamsTemperatureScale
	  section.data(20).logicalSrcIdx = 100;
	  section.data(20).dtTransOffset = 33;
	
	  ;% proc_control_node_P.IMU_GyroParamsMeasurementRange
	  section.data(21).logicalSrcIdx = 101;
	  section.data(21).dtTransOffset = 36;
	
	  ;% proc_control_node_P.IMU_GyroParamsResolution
	  section.data(22).logicalSrcIdx = 102;
	  section.data(22).dtTransOffset = 37;
	
	  ;% proc_control_node_P.IMU_GyroParamsConstantBias
	  section.data(23).logicalSrcIdx = 103;
	  section.data(23).dtTransOffset = 38;
	
	  ;% proc_control_node_P.IMU_GyroParamsAxesMisalignment
	  section.data(24).logicalSrcIdx = 104;
	  section.data(24).dtTransOffset = 41;
	
	  ;% proc_control_node_P.IMU_GyroParamsAccelerationBias
	  section.data(25).logicalSrcIdx = 105;
	  section.data(25).dtTransOffset = 44;
	
	  ;% proc_control_node_P.IMU_GyroParamsNoiseDensity
	  section.data(26).logicalSrcIdx = 106;
	  section.data(26).dtTransOffset = 47;
	
	  ;% proc_control_node_P.IMU_GyroParamsBiasInstability
	  section.data(27).logicalSrcIdx = 107;
	  section.data(27).dtTransOffset = 50;
	
	  ;% proc_control_node_P.IMU_GyroParamsRandomWalk
	  section.data(28).logicalSrcIdx = 108;
	  section.data(28).dtTransOffset = 53;
	
	  ;% proc_control_node_P.IMU_GyroParamsTemperatureBias
	  section.data(29).logicalSrcIdx = 109;
	  section.data(29).dtTransOffset = 56;
	
	  ;% proc_control_node_P.IMU_GyroParamsTemperatureScaleF
	  section.data(30).logicalSrcIdx = 110;
	  section.data(30).dtTransOffset = 59;
	
	  ;% proc_control_node_P.IMU_MagParamsMeasurementRange
	  section.data(31).logicalSrcIdx = 111;
	  section.data(31).dtTransOffset = 62;
	
	  ;% proc_control_node_P.IMU_MagParamsResolution
	  section.data(32).logicalSrcIdx = 112;
	  section.data(32).dtTransOffset = 63;
	
	  ;% proc_control_node_P.IMU_MagParamsConstantBias
	  section.data(33).logicalSrcIdx = 113;
	  section.data(33).dtTransOffset = 64;
	
	  ;% proc_control_node_P.IMU_MagParamsAxesMisalignment
	  section.data(34).logicalSrcIdx = 114;
	  section.data(34).dtTransOffset = 67;
	
	  ;% proc_control_node_P.IMU_MagParamsNoiseDensity
	  section.data(35).logicalSrcIdx = 115;
	  section.data(35).dtTransOffset = 70;
	
	  ;% proc_control_node_P.IMU_MagParamsBiasInstability
	  section.data(36).logicalSrcIdx = 116;
	  section.data(36).dtTransOffset = 73;
	
	  ;% proc_control_node_P.IMU_MagParamsRandomWalk
	  section.data(37).logicalSrcIdx = 117;
	  section.data(37).dtTransOffset = 76;
	
	  ;% proc_control_node_P.IMU_MagParamsTemperatureBias
	  section.data(38).logicalSrcIdx = 118;
	  section.data(38).dtTransOffset = 79;
	
	  ;% proc_control_node_P.IMU_MagParamsTemperatureScaleFa
	  section.data(39).logicalSrcIdx = 119;
	  section.data(39).dtTransOffset = 82;
	
	  ;% proc_control_node_P.TransferFcn_A
	  section.data(40).logicalSrcIdx = 120;
	  section.data(40).dtTransOffset = 85;
	
	  ;% proc_control_node_P.TransferFcn_C
	  section.data(41).logicalSrcIdx = 121;
	  section.data(41).dtTransOffset = 86;
	
	  ;% proc_control_node_P.TransferFcn_A_h
	  section.data(42).logicalSrcIdx = 122;
	  section.data(42).dtTransOffset = 87;
	
	  ;% proc_control_node_P.TransferFcn_C_m
	  section.data(43).logicalSrcIdx = 123;
	  section.data(43).dtTransOffset = 88;
	
	  ;% proc_control_node_P.TransferFcn_A_k
	  section.data(44).logicalSrcIdx = 124;
	  section.data(44).dtTransOffset = 89;
	
	  ;% proc_control_node_P.TransferFcn_C_a
	  section.data(45).logicalSrcIdx = 125;
	  section.data(45).dtTransOffset = 90;
	
	  ;% proc_control_node_P.TransferFcn_A_j
	  section.data(46).logicalSrcIdx = 126;
	  section.data(46).dtTransOffset = 91;
	
	  ;% proc_control_node_P.TransferFcn_C_j
	  section.data(47).logicalSrcIdx = 127;
	  section.data(47).dtTransOffset = 92;
	
	  ;% proc_control_node_P.TransferFcn_A_n
	  section.data(48).logicalSrcIdx = 128;
	  section.data(48).dtTransOffset = 93;
	
	  ;% proc_control_node_P.TransferFcn_C_d
	  section.data(49).logicalSrcIdx = 129;
	  section.data(49).dtTransOffset = 94;
	
	  ;% proc_control_node_P.TransferFcn_A_l
	  section.data(50).logicalSrcIdx = 130;
	  section.data(50).dtTransOffset = 95;
	
	  ;% proc_control_node_P.TransferFcn_C_k
	  section.data(51).logicalSrcIdx = 131;
	  section.data(51).dtTransOffset = 96;
	
	  ;% proc_control_node_P.TransferFcn_A_j1
	  section.data(52).logicalSrcIdx = 132;
	  section.data(52).dtTransOffset = 97;
	
	  ;% proc_control_node_P.TransferFcn_C_g
	  section.data(53).logicalSrcIdx = 133;
	  section.data(53).dtTransOffset = 98;
	
	  ;% proc_control_node_P.TransferFcn_A_d
	  section.data(54).logicalSrcIdx = 134;
	  section.data(54).dtTransOffset = 99;
	
	  ;% proc_control_node_P.TransferFcn_C_c
	  section.data(55).logicalSrcIdx = 135;
	  section.data(55).dtTransOffset = 100;
	
	  ;% proc_control_node_P.ZDrift_Value
	  section.data(56).logicalSrcIdx = 136;
	  section.data(56).dtTransOffset = 101;
	
	  ;% proc_control_node_P.XWave_Bias
	  section.data(57).logicalSrcIdx = 137;
	  section.data(57).dtTransOffset = 102;
	
	  ;% proc_control_node_P.YWave_Bias
	  section.data(58).logicalSrcIdx = 138;
	  section.data(58).dtTransOffset = 103;
	
	  ;% proc_control_node_P.ZWave_Bias
	  section.data(59).logicalSrcIdx = 139;
	  section.data(59).dtTransOffset = 104;
	
	  ;% proc_control_node_P.RollWave_Bias
	  section.data(60).logicalSrcIdx = 140;
	  section.data(60).dtTransOffset = 105;
	
	  ;% proc_control_node_P.PitchWave_Bias
	  section.data(61).logicalSrcIdx = 141;
	  section.data(61).dtTransOffset = 106;
	
	  ;% proc_control_node_P.YawWave_Bias
	  section.data(62).logicalSrcIdx = 142;
	  section.data(62).dtTransOffset = 107;
	
	  ;% proc_control_node_P.InitialBodyvelocity_Value
	  section.data(63).logicalSrcIdx = 143;
	  section.data(63).dtTransOffset = 108;
	
	  ;% proc_control_node_P.InitialAngularRates_Value
	  section.data(64).logicalSrcIdx = 144;
	  section.data(64).dtTransOffset = 111;
	
	  ;% proc_control_node_P.WhiteNoise_Mean
	  section.data(65).logicalSrcIdx = 145;
	  section.data(65).dtTransOffset = 114;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev
	  section.data(66).logicalSrcIdx = 146;
	  section.data(66).dtTransOffset = 115;
	
	  ;% proc_control_node_P.Gain_Gain
	  section.data(67).logicalSrcIdx = 147;
	  section.data(67).dtTransOffset = 116;
	
	  ;% proc_control_node_P.Gain_Gain_i
	  section.data(68).logicalSrcIdx = 148;
	  section.data(68).dtTransOffset = 117;
	
	  ;% proc_control_node_P.WhiteNoise_Mean_n
	  section.data(69).logicalSrcIdx = 149;
	  section.data(69).dtTransOffset = 118;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev_f
	  section.data(70).logicalSrcIdx = 150;
	  section.data(70).dtTransOffset = 119;
	
	  ;% proc_control_node_P.ydevantZhaut_Value
	  section.data(71).logicalSrcIdx = 151;
	  section.data(71).dtTransOffset = 120;
	
	  ;% proc_control_node_P.u2_Gain
	  section.data(72).logicalSrcIdx = 152;
	  section.data(72).dtTransOffset = 123;
	
	  ;% proc_control_node_P.Gain_Gain_c
	  section.data(73).logicalSrcIdx = 153;
	  section.data(73).dtTransOffset = 124;
	
	  ;% proc_control_node_P.Gain1_Gain
	  section.data(74).logicalSrcIdx = 154;
	  section.data(74).dtTransOffset = 125;
	
	  ;% proc_control_node_P.Constant_Value_nr
	  section.data(75).logicalSrcIdx = 155;
	  section.data(75).dtTransOffset = 126;
	
	  ;% proc_control_node_P.Gain2_Gain
	  section.data(76).logicalSrcIdx = 156;
	  section.data(76).dtTransOffset = 127;
	
	  ;% proc_control_node_P.Gain_Gain_cc
	  section.data(77).logicalSrcIdx = 157;
	  section.data(77).dtTransOffset = 128;
	
	  ;% proc_control_node_P.Gain1_Gain_b
	  section.data(78).logicalSrcIdx = 158;
	  section.data(78).dtTransOffset = 129;
	
	  ;% proc_control_node_P.Constant_Value_f
	  section.data(79).logicalSrcIdx = 159;
	  section.data(79).dtTransOffset = 130;
	
	  ;% proc_control_node_P.Gain2_Gain_c
	  section.data(80).logicalSrcIdx = 160;
	  section.data(80).dtTransOffset = 131;
	
	  ;% proc_control_node_P.Gain_Gain_f
	  section.data(81).logicalSrcIdx = 161;
	  section.data(81).dtTransOffset = 132;
	
	  ;% proc_control_node_P.Gain1_Gain_n
	  section.data(82).logicalSrcIdx = 162;
	  section.data(82).dtTransOffset = 133;
	
	  ;% proc_control_node_P.Constant_Value_pd
	  section.data(83).logicalSrcIdx = 163;
	  section.data(83).dtTransOffset = 134;
	
	  ;% proc_control_node_P.Gain2_Gain_i
	  section.data(84).logicalSrcIdx = 164;
	  section.data(84).dtTransOffset = 135;
	
	  ;% proc_control_node_P.MPCmanager_eInit
	  section.data(85).logicalSrcIdx = 165;
	  section.data(85).dtTransOffset = 136;
	
	  ;% proc_control_node_P.Output_Y0_i
	  section.data(86).logicalSrcIdx = 166;
	  section.data(86).dtTransOffset = 137;
	
	  ;% proc_control_node_P.isActive_Y0
	  section.data(87).logicalSrcIdx = 167;
	  section.data(87).dtTransOffset = 138;
	
	  ;% proc_control_node_P.Delay_InitialCondition
	  section.data(88).logicalSrcIdx = 168;
	  section.data(88).dtTransOffset = 139;
	
	  ;% proc_control_node_P.md_zero_Value
	  section.data(89).logicalSrcIdx = 169;
	  section.data(89).dtTransOffset = 147;
	
	  ;% proc_control_node_P.mvtarget_zero_Value
	  section.data(90).logicalSrcIdx = 170;
	  section.data(90).dtTransOffset = 148;
	
	  ;% proc_control_node_P.ymin_zero_Value
	  section.data(91).logicalSrcIdx = 171;
	  section.data(91).dtTransOffset = 156;
	
	  ;% proc_control_node_P.ymax_zero_Value
	  section.data(92).logicalSrcIdx = 172;
	  section.data(92).dtTransOffset = 169;
	
	  ;% proc_control_node_P.dmvmin_zero_Value
	  section.data(93).logicalSrcIdx = 173;
	  section.data(93).dtTransOffset = 182;
	
	  ;% proc_control_node_P.dmvmax_zero_Value
	  section.data(94).logicalSrcIdx = 174;
	  section.data(94).dtTransOffset = 190;
	
	  ;% proc_control_node_P.xmin_zero_Value
	  section.data(95).logicalSrcIdx = 175;
	  section.data(95).dtTransOffset = 198;
	
	  ;% proc_control_node_P.xmax_zero_Value
	  section.data(96).logicalSrcIdx = 176;
	  section.data(96).dtTransOffset = 211;
	
	  ;% proc_control_node_P.ecrwt_zero_Value
	  section.data(97).logicalSrcIdx = 177;
	  section.data(97).dtTransOffset = 224;
	
	  ;% proc_control_node_P.params_zero_Value
	  section.data(98).logicalSrcIdx = 178;
	  section.data(98).dtTransOffset = 225;
	
	  ;% proc_control_node_P.PulseGenerator_Amp
	  section.data(99).logicalSrcIdx = 179;
	  section.data(99).dtTransOffset = 226;
	
	  ;% proc_control_node_P.PulseGenerator_Period
	  section.data(100).logicalSrcIdx = 180;
	  section.data(100).dtTransOffset = 227;
	
	  ;% proc_control_node_P.PulseGenerator_Duty
	  section.data(101).logicalSrcIdx = 181;
	  section.data(101).dtTransOffset = 228;
	
	  ;% proc_control_node_P.PulseGenerator_PhaseDelay
	  section.data(102).logicalSrcIdx = 182;
	  section.data(102).dtTransOffset = 229;
	
	  ;% proc_control_node_P.MATLABSystem_k
	  section.data(103).logicalSrcIdx = 183;
	  section.data(103).dtTransOffset = 230;
	
	  ;% proc_control_node_P.TSamp_WtEt
	  section.data(104).logicalSrcIdx = 184;
	  section.data(104).dtTransOffset = 231;
	
	  ;% proc_control_node_P.Constant1_Value
	  section.data(105).logicalSrcIdx = 185;
	  section.data(105).dtTransOffset = 232;
	
	  ;% proc_control_node_P.Constant_Value_ms
	  section.data(106).logicalSrcIdx = 186;
	  section.data(106).dtTransOffset = 240;
	
	  ;% proc_control_node_P.Constant_Value_jf
	  section.data(107).logicalSrcIdx = 187;
	  section.data(107).dtTransOffset = 241;
	
	  ;% proc_control_node_P.Constant7_Value
	  section.data(108).logicalSrcIdx = 188;
	  section.data(108).dtTransOffset = 242;
	
	  ;% proc_control_node_P.MATLABSystem2_avanceRapide
	  section.data(109).logicalSrcIdx = 189;
	  section.data(109).dtTransOffset = 249;
	
	  ;% proc_control_node_P.MATLABSystem2_avancePrecision
	  section.data(110).logicalSrcIdx = 190;
	  section.data(110).dtTransOffset = 256;
	
	  ;% proc_control_node_P.MATLABSystem2_accRapide
	  section.data(111).logicalSrcIdx = 191;
	  section.data(111).dtTransOffset = 263;
	
	  ;% proc_control_node_P.MATLABSystem2_accPrecision
	  section.data(112).logicalSrcIdx = 192;
	  section.data(112).dtTransOffset = 270;
	
	  ;% proc_control_node_P.MATLABSystem2_Ts
	  section.data(113).logicalSrcIdx = 193;
	  section.data(113).dtTransOffset = 271;
	
	  ;% proc_control_node_P.Out1_Y0_n
	  section.data(114).logicalSrcIdx = 194;
	  section.data(114).dtTransOffset = 272;
	
	  ;% proc_control_node_P.Out2_Y0
	  section.data(115).logicalSrcIdx = 195;
	  section.data(115).dtTransOffset = 273;
	
	  ;% proc_control_node_P.MATLABSystem_linearConvergence
	  section.data(116).logicalSrcIdx = 196;
	  section.data(116).dtTransOffset = 274;
	
	  ;% proc_control_node_P.MATLABSystem_quaternionConverge
	  section.data(117).logicalSrcIdx = 197;
	  section.data(117).dtTransOffset = 275;
	
	  ;% proc_control_node_P.MATLABSystem_TargetThreshold
	  section.data(118).logicalSrcIdx = 198;
	  section.data(118).dtTransOffset = 276;
	
	  ;% proc_control_node_P.linWpts_Y0
	  section.data(119).logicalSrcIdx = 199;
	  section.data(119).dtTransOffset = 277;
	
	  ;% proc_control_node_P.RotWpts_Y0
	  section.data(120).logicalSrcIdx = 200;
	  section.data(120).dtTransOffset = 278;
	
	  ;% proc_control_node_P.time_Y0
	  section.data(121).logicalSrcIdx = 201;
	  section.data(121).dtTransOffset = 279;
	
	  ;% proc_control_node_P.Constant1_Value_l
	  section.data(122).logicalSrcIdx = 202;
	  section.data(122).dtTransOffset = 280;
	
	  ;% proc_control_node_P.Constant_Value_a
	  section.data(123).logicalSrcIdx = 203;
	  section.data(123).dtTransOffset = 281;
	
	  ;% proc_control_node_P.Constant_Value_ax
	  section.data(124).logicalSrcIdx = 204;
	  section.data(124).dtTransOffset = 282;
	
	  ;% proc_control_node_P.y_Y0
	  section.data(125).logicalSrcIdx = 205;
	  section.data(125).dtTransOffset = 283;
	
	  ;% proc_control_node_P.PolynomialTrajectory1_VelocityB
	  section.data(126).logicalSrcIdx = 206;
	  section.data(126).dtTransOffset = 284;
	
	  ;% proc_control_node_P.Constant_Value_en
	  section.data(127).logicalSrcIdx = 207;
	  section.data(127).dtTransOffset = 290;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_gainval
	  section.data(128).logicalSrcIdx = 208;
	  section.data(128).dtTransOffset = 291;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_IC
	  section.data(129).logicalSrcIdx = 209;
	  section.data(129).dtTransOffset = 292;
	
	  ;% proc_control_node_P.Constant1_Value_m
	  section.data(130).logicalSrcIdx = 210;
	  section.data(130).dtTransOffset = 293;
	
	  ;% proc_control_node_P.Delay_InitialCondition_f
	  section.data(131).logicalSrcIdx = 211;
	  section.data(131).dtTransOffset = 295;
	
	  ;% proc_control_node_P.Constant_Value_ct
	  section.data(132).logicalSrcIdx = 212;
	  section.data(132).dtTransOffset = 296;
	
	  ;% proc_control_node_P.Constant6_Value
	  section.data(133).logicalSrcIdx = 213;
	  section.data(133).dtTransOffset = 297;
	
	  ;% proc_control_node_P.Constant_Value_cy
	  section.data(134).logicalSrcIdx = 214;
	  section.data(134).dtTransOffset = 298;
	
	  ;% proc_control_node_P.Constant1_Value_p
	  section.data(135).logicalSrcIdx = 215;
	  section.data(135).dtTransOffset = 311;
	
	  ;% proc_control_node_P.Delay_InitialCondition_a
	  section.data(136).logicalSrcIdx = 216;
	  section.data(136).dtTransOffset = 312;
	
	  ;% proc_control_node_P.siydevant_Value
	  section.data(137).logicalSrcIdx = 217;
	  section.data(137).dtTransOffset = 313;
	
	  ;% proc_control_node_P.u2_Gain_k
	  section.data(138).logicalSrcIdx = 218;
	  section.data(138).dtTransOffset = 316;
	
	  ;% proc_control_node_P.Gain_Gain_a
	  section.data(139).logicalSrcIdx = 219;
	  section.data(139).dtTransOffset = 317;
	
	  ;% proc_control_node_P.Gain1_Gain_c
	  section.data(140).logicalSrcIdx = 220;
	  section.data(140).dtTransOffset = 318;
	
	  ;% proc_control_node_P.Constant_Value_n5
	  section.data(141).logicalSrcIdx = 221;
	  section.data(141).dtTransOffset = 319;
	
	  ;% proc_control_node_P.Gain2_Gain_l
	  section.data(142).logicalSrcIdx = 222;
	  section.data(142).dtTransOffset = 320;
	
	  ;% proc_control_node_P.Gain_Gain_i5
	  section.data(143).logicalSrcIdx = 223;
	  section.data(143).dtTransOffset = 321;
	
	  ;% proc_control_node_P.Constant_Value_ja
	  section.data(144).logicalSrcIdx = 224;
	  section.data(144).dtTransOffset = 322;
	
	  ;% proc_control_node_P.Gain2_Gain_b
	  section.data(145).logicalSrcIdx = 225;
	  section.data(145).dtTransOffset = 323;
	
	  ;% proc_control_node_P.Gain1_Gain_m
	  section.data(146).logicalSrcIdx = 226;
	  section.data(146).dtTransOffset = 324;
	
	  ;% proc_control_node_P.Constant_Value_pns
	  section.data(147).logicalSrcIdx = 227;
	  section.data(147).dtTransOffset = 325;
	
	  ;% proc_control_node_P.Gain2_Gain_bx
	  section.data(148).logicalSrcIdx = 228;
	  section.data(148).dtTransOffset = 326;
	
	  ;% proc_control_node_P.Gain_Gain_b
	  section.data(149).logicalSrcIdx = 229;
	  section.data(149).dtTransOffset = 327;
	
	  ;% proc_control_node_P.Gain1_Gain_p
	  section.data(150).logicalSrcIdx = 230;
	  section.data(150).dtTransOffset = 328;
	
	  ;% proc_control_node_P.Gain_Gain_g
	  section.data(151).logicalSrcIdx = 231;
	  section.data(151).dtTransOffset = 329;
	
	  ;% proc_control_node_P.Constant_Value_er
	  section.data(152).logicalSrcIdx = 232;
	  section.data(152).dtTransOffset = 330;
	
	  ;% proc_control_node_P.Gain2_Gain_a
	  section.data(153).logicalSrcIdx = 233;
	  section.data(153).dtTransOffset = 331;
	
	  ;% proc_control_node_P.Gain_Gain_cg
	  section.data(154).logicalSrcIdx = 234;
	  section.data(154).dtTransOffset = 332;
	
	  ;% proc_control_node_P.Gain1_Gain_g
	  section.data(155).logicalSrcIdx = 235;
	  section.data(155).dtTransOffset = 333;
	
	  ;% proc_control_node_P.Gain_Gain_ca
	  section.data(156).logicalSrcIdx = 236;
	  section.data(156).dtTransOffset = 334;
	
	  ;% proc_control_node_P.Constant_Value_or
	  section.data(157).logicalSrcIdx = 237;
	  section.data(157).dtTransOffset = 335;
	
	  ;% proc_control_node_P.Gain2_Gain_f
	  section.data(158).logicalSrcIdx = 238;
	  section.data(158).dtTransOffset = 336;
	
	  ;% proc_control_node_P.Gain1_Gain_c1
	  section.data(159).logicalSrcIdx = 239;
	  section.data(159).dtTransOffset = 337;
	
	  ;% proc_control_node_P.Gain_Gain_n
	  section.data(160).logicalSrcIdx = 240;
	  section.data(160).dtTransOffset = 338;
	
	  ;% proc_control_node_P.Gain1_Gain_d
	  section.data(161).logicalSrcIdx = 241;
	  section.data(161).dtTransOffset = 339;
	
	  ;% proc_control_node_P.Constant_Value_ao
	  section.data(162).logicalSrcIdx = 242;
	  section.data(162).dtTransOffset = 340;
	
	  ;% proc_control_node_P.Gain2_Gain_g
	  section.data(163).logicalSrcIdx = 243;
	  section.data(163).dtTransOffset = 341;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_gainva_a
	  section.data(164).logicalSrcIdx = 244;
	  section.data(164).dtTransOffset = 342;
	
	  ;% proc_control_node_P.Gain_Gain_bc
	  section.data(165).logicalSrcIdx = 245;
	  section.data(165).dtTransOffset = 343;
	
	  ;% proc_control_node_P.Gain1_Gain_pq
	  section.data(166).logicalSrcIdx = 246;
	  section.data(166).dtTransOffset = 344;
	
	  ;% proc_control_node_P.Gain_Gain_n3
	  section.data(167).logicalSrcIdx = 247;
	  section.data(167).dtTransOffset = 345;
	
	  ;% proc_control_node_P.Gain_Gain_m
	  section.data(168).logicalSrcIdx = 248;
	  section.data(168).dtTransOffset = 346;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator1_gainval
	  section.data(169).logicalSrcIdx = 249;
	  section.data(169).dtTransOffset = 347;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator1_IC
	  section.data(170).logicalSrcIdx = 250;
	  section.data(170).dtTransOffset = 348;
	
	  ;% proc_control_node_P.Constant_Value_ji
	  section.data(171).logicalSrcIdx = 251;
	  section.data(171).dtTransOffset = 349;
	
	  ;% proc_control_node_P.Constant3_Value
	  section.data(172).logicalSrcIdx = 252;
	  section.data(172).dtTransOffset = 350;
	
	  ;% proc_control_node_P.Integrator_gainval
	  section.data(173).logicalSrcIdx = 253;
	  section.data(173).dtTransOffset = 351;
	
	  ;% proc_control_node_P.Integrator_UpperSat
	  section.data(174).logicalSrcIdx = 254;
	  section.data(174).dtTransOffset = 352;
	
	  ;% proc_control_node_P.Integrator_LowerSat
	  section.data(175).logicalSrcIdx = 255;
	  section.data(175).dtTransOffset = 353;
	
	  ;% proc_control_node_P.Saturation_UpperSat
	  section.data(176).logicalSrcIdx = 256;
	  section.data(176).dtTransOffset = 354;
	
	  ;% proc_control_node_P.Saturation_LowerSat
	  section.data(177).logicalSrcIdx = 257;
	  section.data(177).dtTransOffset = 355;
	
	  ;% proc_control_node_P.Gain3_Gain
	  section.data(178).logicalSrcIdx = 258;
	  section.data(178).dtTransOffset = 356;
	
	  ;% proc_control_node_P.Constant1_Value_pt
	  section.data(179).logicalSrcIdx = 259;
	  section.data(179).dtTransOffset = 357;
	
	  ;% proc_control_node_P.Constant2_Value
	  section.data(180).logicalSrcIdx = 260;
	  section.data(180).dtTransOffset = 358;
	
	  ;% proc_control_node_P.Integrator_gainval_a
	  section.data(181).logicalSrcIdx = 261;
	  section.data(181).dtTransOffset = 359;
	
	  ;% proc_control_node_P.Integrator_UpperSat_p
	  section.data(182).logicalSrcIdx = 262;
	  section.data(182).dtTransOffset = 360;
	
	  ;% proc_control_node_P.Integrator_LowerSat_j
	  section.data(183).logicalSrcIdx = 263;
	  section.data(183).dtTransOffset = 361;
	
	  ;% proc_control_node_P.Saturation_UpperSat_n
	  section.data(184).logicalSrcIdx = 264;
	  section.data(184).dtTransOffset = 362;
	
	  ;% proc_control_node_P.Saturation_LowerSat_p
	  section.data(185).logicalSrcIdx = 265;
	  section.data(185).dtTransOffset = 363;
	
	  ;% proc_control_node_P.Gain_Gain_ib
	  section.data(186).logicalSrcIdx = 266;
	  section.data(186).dtTransOffset = 364;
	
	  ;% proc_control_node_P.Gain2_Gain_n
	  section.data(187).logicalSrcIdx = 267;
	  section.data(187).dtTransOffset = 365;
	
	  ;% proc_control_node_P.Gain1_Gain_cu
	  section.data(188).logicalSrcIdx = 268;
	  section.data(188).dtTransOffset = 366;
	
	  ;% proc_control_node_P.Gain_Gain_ac
	  section.data(189).logicalSrcIdx = 269;
	  section.data(189).dtTransOffset = 367;
	
	  ;% proc_control_node_P.Gain4_Gain
	  section.data(190).logicalSrcIdx = 270;
	  section.data(190).dtTransOffset = 368;
	
	  ;% proc_control_node_P.Gain3_Gain_d
	  section.data(191).logicalSrcIdx = 271;
	  section.data(191).dtTransOffset = 369;
	
	  ;% proc_control_node_P.Delay_InitialCondition_h
	  section.data(192).logicalSrcIdx = 272;
	  section.data(192).dtTransOffset = 370;
	
	  ;% proc_control_node_P.FirstOrderHold_IniOut
	  section.data(193).logicalSrcIdx = 273;
	  section.data(193).dtTransOffset = 371;
	
	  ;% proc_control_node_P.FirstOrderHold_ErrTol
	  section.data(194).logicalSrcIdx = 274;
	  section.data(194).dtTransOffset = 372;
	
	  ;% proc_control_node_P.FirstOrderHold1_IniOut
	  section.data(195).logicalSrcIdx = 275;
	  section.data(195).dtTransOffset = 373;
	
	  ;% proc_control_node_P.FirstOrderHold1_ErrTol
	  section.data(196).logicalSrcIdx = 276;
	  section.data(196).dtTransOffset = 374;
	
	  ;% proc_control_node_P.FirstOrderHold_IniOut_c
	  section.data(197).logicalSrcIdx = 277;
	  section.data(197).dtTransOffset = 375;
	
	  ;% proc_control_node_P.FirstOrderHold_ErrTol_p
	  section.data(198).logicalSrcIdx = 278;
	  section.data(198).dtTransOffset = 376;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(45) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Delay_InitialCondition_n
	  section.data(1).logicalSrcIdx = 279;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.Delay1_InitialCondition
	  section.data(2).logicalSrcIdx = 280;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.Merge1_InitialOutput
	  section.data(3).logicalSrcIdx = 281;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(46) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Subsystem1_e.Out1_Y0
	  section.data(1).logicalSrcIdx = 282;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(47) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Subsystem1.Out1_Y0
	  section.data(1).logicalSrcIdx = 283;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(48) = section;
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
    nTotSects     = 14;
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
      
	  ;% proc_control_node_B.In1_h
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_p
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.In1_ph
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.FirstOrderHold1
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.FirstOrderHold_c
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_k
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_pv
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% proc_control_node_B.y
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.RotationTrajectory_o1
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 4;
	
	  ;% proc_control_node_B.Transpose
	  section.data(3).logicalSrcIdx = 37;
	  section.data(3).dtTransOffset = 8;
	
	  ;% proc_control_node_B.DataTypeConversion
	  section.data(4).logicalSrcIdx = 38;
	  section.data(4).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% proc_control_node_B.WorldPosition_g
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.InitialBodyvelocity
	  section.data(2).logicalSrcIdx = 80;
	  section.data(2).dtTransOffset = 3;
	
	  ;% proc_control_node_B.BodyVelocity_i
	  section.data(3).logicalSrcIdx = 81;
	  section.data(3).dtTransOffset = 6;
	
	  ;% proc_control_node_B.InitialAngularRates
	  section.data(4).logicalSrcIdx = 82;
	  section.data(4).dtTransOffset = 9;
	
	  ;% proc_control_node_B.AngularRate_b
	  section.data(5).logicalSrcIdx = 83;
	  section.data(5).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.DataTypeConversion1_l
	  section.data(1).logicalSrcIdx = 39;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 71;
      section.data(71)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Sum
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Sum_m
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_B.Sum_i
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_B.qW2S
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_B.WorldPosition
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 7;
	
	  ;% proc_control_node_B.AngularRate
	  section.data(6).logicalSrcIdx = 12;
	  section.data(6).dtTransOffset = 10;
	
	  ;% proc_control_node_B.TmpSignalConversionAtFirstOrder
	  section.data(7).logicalSrcIdx = 13;
	  section.data(7).dtTransOffset = 13;
	
	  ;% proc_control_node_B.Divide3
	  section.data(8).logicalSrcIdx = 14;
	  section.data(8).dtTransOffset = 25;
	
	  ;% proc_control_node_B.Divide2
	  section.data(9).logicalSrcIdx = 15;
	  section.data(9).dtTransOffset = 26;
	
	  ;% proc_control_node_B.Divide1
	  section.data(10).logicalSrcIdx = 16;
	  section.data(10).dtTransOffset = 27;
	
	  ;% proc_control_node_B.Divide
	  section.data(11).logicalSrcIdx = 17;
	  section.data(11).dtTransOffset = 28;
	
	  ;% proc_control_node_B.BodyPosition
	  section.data(12).logicalSrcIdx = 18;
	  section.data(12).dtTransOffset = 29;
	
	  ;% proc_control_node_B.MultiportSwitch
	  section.data(13).logicalSrcIdx = 21;
	  section.data(13).dtTransOffset = 30;
	
	  ;% proc_control_node_B.Quaternion
	  section.data(14).logicalSrcIdx = 22;
	  section.data(14).dtTransOffset = 36;
	
	  ;% proc_control_node_B.Merge
	  section.data(15).logicalSrcIdx = 23;
	  section.data(15).dtTransOffset = 88;
	
	  ;% proc_control_node_B.Saturation
	  section.data(16).logicalSrcIdx = 24;
	  section.data(16).dtTransOffset = 96;
	
	  ;% proc_control_node_B.DataTypeConversion1
	  section.data(17).logicalSrcIdx = 25;
	  section.data(17).dtTransOffset = 104;
	
	  ;% proc_control_node_B.Gain2
	  section.data(18).logicalSrcIdx = 26;
	  section.data(18).dtTransOffset = 112;
	
	  ;% proc_control_node_B.Gain1
	  section.data(19).logicalSrcIdx = 27;
	  section.data(19).dtTransOffset = 113;
	
	  ;% proc_control_node_B.Sum_d
	  section.data(20).logicalSrcIdx = 28;
	  section.data(20).dtTransOffset = 114;
	
	  ;% proc_control_node_B.Gain4
	  section.data(21).logicalSrcIdx = 29;
	  section.data(21).dtTransOffset = 115;
	
	  ;% proc_control_node_B.Gain3
	  section.data(22).logicalSrcIdx = 30;
	  section.data(22).dtTransOffset = 116;
	
	  ;% proc_control_node_B.FirstOrderHold
	  section.data(23).logicalSrcIdx = 31;
	  section.data(23).dtTransOffset = 117;
	
	  ;% proc_control_node_B.DataTypeConversion2
	  section.data(24).logicalSrcIdx = 40;
	  section.data(24).dtTransOffset = 129;
	
	  ;% proc_control_node_B.Transpose_i
	  section.data(25).logicalSrcIdx = 41;
	  section.data(25).dtTransOffset = 130;
	
	  ;% proc_control_node_B.Selector1
	  section.data(26).logicalSrcIdx = 42;
	  section.data(26).dtTransOffset = 146;
	
	  ;% proc_control_node_B.Selector
	  section.data(27).logicalSrcIdx = 43;
	  section.data(27).dtTransOffset = 154;
	
	  ;% proc_control_node_B.MatrixConcatenate
	  section.data(28).logicalSrcIdx = 44;
	  section.data(28).dtTransOffset = 160;
	
	  ;% proc_control_node_B.DataTypeConversion_p
	  section.data(29).logicalSrcIdx = 45;
	  section.data(29).dtTransOffset = 162;
	
	  ;% proc_control_node_B.DataTypeConversion1_o
	  section.data(30).logicalSrcIdx = 46;
	  section.data(30).dtTransOffset = 168;
	
	  ;% proc_control_node_B.DataTypeConversion2_m
	  section.data(31).logicalSrcIdx = 47;
	  section.data(31).dtTransOffset = 170;
	
	  ;% proc_control_node_B.y_g
	  section.data(32).logicalSrcIdx = 48;
	  section.data(32).dtTransOffset = 171;
	
	  ;% proc_control_node_B.MATLABSystem
	  section.data(33).logicalSrcIdx = 49;
	  section.data(33).dtTransOffset = 174;
	
	  ;% proc_control_node_B.PulseGenerator
	  section.data(34).logicalSrcIdx = 50;
	  section.data(34).dtTransOffset = 182;
	
	  ;% proc_control_node_B.nlpstatus
	  section.data(35).logicalSrcIdx = 51;
	  section.data(35).dtTransOffset = 183;
	
	  ;% proc_control_node_B.Quaternion_l
	  section.data(36).logicalSrcIdx = 52;
	  section.data(36).dtTransOffset = 184;
	
	  ;% proc_control_node_B.WorldPosition_o
	  section.data(37).logicalSrcIdx = 53;
	  section.data(37).dtTransOffset = 188;
	
	  ;% proc_control_node_B.BodyVelocity
	  section.data(38).logicalSrcIdx = 54;
	  section.data(38).dtTransOffset = 191;
	
	  ;% proc_control_node_B.AngularRate_m
	  section.data(39).logicalSrcIdx = 55;
	  section.data(39).dtTransOffset = 194;
	
	  ;% proc_control_node_B.y_a
	  section.data(40).logicalSrcIdx = 57;
	  section.data(40).dtTransOffset = 197;
	
	  ;% proc_control_node_B.y_b
	  section.data(41).logicalSrcIdx = 58;
	  section.data(41).dtTransOffset = 201;
	
	  ;% proc_control_node_B.PWMtoN
	  section.data(42).logicalSrcIdx = 59;
	  section.data(42).dtTransOffset = 202;
	
	  ;% proc_control_node_B.XDrift
	  section.data(43).logicalSrcIdx = 68;
	  section.data(43).dtTransOffset = 210;
	
	  ;% proc_control_node_B.YDrift
	  section.data(44).logicalSrcIdx = 69;
	  section.data(44).dtTransOffset = 211;
	
	  ;% proc_control_node_B.ZDrift
	  section.data(45).logicalSrcIdx = 70;
	  section.data(45).dtTransOffset = 212;
	
	  ;% proc_control_node_B.XWave
	  section.data(46).logicalSrcIdx = 71;
	  section.data(46).dtTransOffset = 213;
	
	  ;% proc_control_node_B.YWave
	  section.data(47).logicalSrcIdx = 72;
	  section.data(47).dtTransOffset = 214;
	
	  ;% proc_control_node_B.ZWave
	  section.data(48).logicalSrcIdx = 73;
	  section.data(48).dtTransOffset = 215;
	
	  ;% proc_control_node_B.Output
	  section.data(49).logicalSrcIdx = 88;
	  section.data(49).dtTransOffset = 216;
	
	  ;% proc_control_node_B.Quaternion_p
	  section.data(50).logicalSrcIdx = 89;
	  section.data(50).dtTransOffset = 217;
	
	  ;% proc_control_node_B.Transpose_d
	  section.data(51).logicalSrcIdx = 90;
	  section.data(51).dtTransOffset = 221;
	
	  ;% proc_control_node_B.Output_d
	  section.data(52).logicalSrcIdx = 92;
	  section.data(52).dtTransOffset = 224;
	
	  ;% proc_control_node_B.AngularRate_h
	  section.data(53).logicalSrcIdx = 93;
	  section.data(53).dtTransOffset = 225;
	
	  ;% proc_control_node_B.Gain_f
	  section.data(54).logicalSrcIdx = 94;
	  section.data(54).dtTransOffset = 228;
	
	  ;% proc_control_node_B.Gain1_b
	  section.data(55).logicalSrcIdx = 95;
	  section.data(55).dtTransOffset = 229;
	
	  ;% proc_control_node_B.Gain2_l
	  section.data(56).logicalSrcIdx = 96;
	  section.data(56).dtTransOffset = 230;
	
	  ;% proc_control_node_B.Sum_h
	  section.data(57).logicalSrcIdx = 97;
	  section.data(57).dtTransOffset = 231;
	
	  ;% proc_control_node_B.Gain_e
	  section.data(58).logicalSrcIdx = 98;
	  section.data(58).dtTransOffset = 232;
	
	  ;% proc_control_node_B.Gain1_bf
	  section.data(59).logicalSrcIdx = 99;
	  section.data(59).dtTransOffset = 233;
	
	  ;% proc_control_node_B.Gain2_d
	  section.data(60).logicalSrcIdx = 100;
	  section.data(60).dtTransOffset = 234;
	
	  ;% proc_control_node_B.Sum_m0
	  section.data(61).logicalSrcIdx = 101;
	  section.data(61).dtTransOffset = 235;
	
	  ;% proc_control_node_B.Gain_n
	  section.data(62).logicalSrcIdx = 102;
	  section.data(62).dtTransOffset = 236;
	
	  ;% proc_control_node_B.Gain1_l
	  section.data(63).logicalSrcIdx = 103;
	  section.data(63).dtTransOffset = 237;
	
	  ;% proc_control_node_B.Gain2_m
	  section.data(64).logicalSrcIdx = 104;
	  section.data(64).dtTransOffset = 238;
	
	  ;% proc_control_node_B.Sum_c
	  section.data(65).logicalSrcIdx = 105;
	  section.data(65).dtTransOffset = 239;
	
	  ;% proc_control_node_B.AHRS_o1
	  section.data(66).logicalSrcIdx = 106;
	  section.data(66).dtTransOffset = 240;
	
	  ;% proc_control_node_B.y_f
	  section.data(67).logicalSrcIdx = 107;
	  section.data(67).dtTransOffset = 244;
	
	  ;% proc_control_node_B.Position_dot
	  section.data(68).logicalSrcIdx = 108;
	  section.data(68).dtTransOffset = 248;
	
	  ;% proc_control_node_B.Quaternion_dot
	  section.data(69).logicalSrcIdx = 109;
	  section.data(69).dtTransOffset = 251;
	
	  ;% proc_control_node_B.BodyVelocity_dot
	  section.data(70).logicalSrcIdx = 110;
	  section.data(70).dtTransOffset = 255;
	
	  ;% proc_control_node_B.AngularRates_dot
	  section.data(71).logicalSrcIdx = 111;
	  section.data(71).dtTransOffset = 258;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_g
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.NtoRPM
	  section.data(1).logicalSrcIdx = 113;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Data
	  section.data(1).logicalSrcIdx = 114;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_B.OR
	  section.data(1).logicalSrcIdx = 115;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Reset
	  section.data(2).logicalSrcIdx = 116;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_B.Merge1
	  section.data(3).logicalSrcIdx = 117;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
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
    nTotSects     = 23;
    sectIdxOffset = 14;
    
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
      
	  ;% proc_control_node_DW.obj_i
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_c
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_o
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_g
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_m
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_gr
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_k
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_ce
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_or
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_b
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_if
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_f
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_iv
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_a
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_gw
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_mi
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_bo
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_l
	  section.data(9).logicalSrcIdx = 18;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.obj_os
	  section.data(10).logicalSrcIdx = 19;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.obj_ai
	  section.data(11).logicalSrcIdx = 20;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_d
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_lm
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_o5
	  section.data(3).logicalSrcIdx = 23;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_bj
	  section.data(4).logicalSrcIdx = 24;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_p
	  section.data(5).logicalSrcIdx = 25;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_j
	  section.data(6).logicalSrcIdx = 26;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_k0
	  section.data(7).logicalSrcIdx = 27;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_jb
	  section.data(8).logicalSrcIdx = 28;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_aj
	  section.data(9).logicalSrcIdx = 29;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.obj_dr
	  section.data(10).logicalSrcIdx = 30;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.obj_f5
	  section.data(11).logicalSrcIdx = 31;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.obj_os4
	  section.data(12).logicalSrcIdx = 32;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Delay_DSTATE
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.Integrator_DSTATE
	  section.data(4).logicalSrcIdx = 36;
	  section.data(4).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.Integrator_DSTATE_h
	  section.data(5).logicalSrcIdx = 37;
	  section.data(5).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.Delay_DSTATE_f
	  section.data(6).logicalSrcIdx = 38;
	  section.data(6).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.Delay_DSTATE_j
	  section.data(7).logicalSrcIdx = 39;
	  section.data(7).dtTransOffset = 20;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_DSTATE_a
	  section.data(8).logicalSrcIdx = 40;
	  section.data(8).dtTransOffset = 21;
	
	  ;% proc_control_node_DW.UD_DSTATE
	  section.data(9).logicalSrcIdx = 51;
	  section.data(9).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.Delay_DSTATE_b
	  section.data(10).logicalSrcIdx = 52;
	  section.data(10).dtTransOffset = 28;
	
	  ;% proc_control_node_DW.Tk
	  section.data(11).logicalSrcIdx = 55;
	  section.data(11).dtTransOffset = 36;
	
	  ;% proc_control_node_DW.Ck
	  section.data(12).logicalSrcIdx = 56;
	  section.data(12).dtTransOffset = 37;
	
	  ;% proc_control_node_DW.Mk
	  section.data(13).logicalSrcIdx = 57;
	  section.data(13).dtTransOffset = 49;
	
	  ;% proc_control_node_DW.Uk
	  section.data(14).logicalSrcIdx = 58;
	  section.data(14).dtTransOffset = 61;
	
	  ;% proc_control_node_DW.Tk_m
	  section.data(15).logicalSrcIdx = 59;
	  section.data(15).dtTransOffset = 73;
	
	  ;% proc_control_node_DW.Ck_n
	  section.data(16).logicalSrcIdx = 60;
	  section.data(16).dtTransOffset = 74;
	
	  ;% proc_control_node_DW.Mk_o
	  section.data(17).logicalSrcIdx = 61;
	  section.data(17).dtTransOffset = 82;
	
	  ;% proc_control_node_DW.Uk_g
	  section.data(18).logicalSrcIdx = 62;
	  section.data(18).dtTransOffset = 90;
	
	  ;% proc_control_node_DW.Tk_e
	  section.data(19).logicalSrcIdx = 63;
	  section.data(19).dtTransOffset = 98;
	
	  ;% proc_control_node_DW.Ck_b
	  section.data(20).logicalSrcIdx = 64;
	  section.data(20).dtTransOffset = 99;
	
	  ;% proc_control_node_DW.Mk_h
	  section.data(21).logicalSrcIdx = 65;
	  section.data(21).dtTransOffset = 107;
	
	  ;% proc_control_node_DW.Uk_h
	  section.data(22).logicalSrcIdx = 66;
	  section.data(22).dtTransOffset = 115;
	
	  ;% proc_control_node_DW.XDrift_NextOutput
	  section.data(23).logicalSrcIdx = 67;
	  section.data(23).dtTransOffset = 123;
	
	  ;% proc_control_node_DW.YDrift_NextOutput
	  section.data(24).logicalSrcIdx = 68;
	  section.data(24).dtTransOffset = 124;
	
	  ;% proc_control_node_DW.NextOutput
	  section.data(25).logicalSrcIdx = 69;
	  section.data(25).dtTransOffset = 125;
	
	  ;% proc_control_node_DW.NextOutput_k
	  section.data(26).logicalSrcIdx = 70;
	  section.data(26).dtTransOffset = 126;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Scope_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Scope_PWORK_o.LoggedData
	  section.data(3).logicalSrcIdx = 73;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Scope3_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 74;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.Scope1_PWORK_i.LoggedData
	  section.data(5).logicalSrcIdx = 75;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.Scope_PWORK_f.LoggedData
	  section.data(6).logicalSrcIdx = 76;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.Scope1_PWORK_e.LoggedData
	  section.data(7).logicalSrcIdx = 77;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.Scope_PWORK_i.LoggedData
	  section.data(8).logicalSrcIdx = 78;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.Scope_PWORK_n.LoggedData
	  section.data(9).logicalSrcIdx = 79;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.Scope1_PWORK_m.LoggedData
	  section.data(10).logicalSrcIdx = 80;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.Scope_PWORK_l.LoggedData
	  section.data(11).logicalSrcIdx = 81;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.Scope_PWORK_ow.LoggedData
	  section.data(12).logicalSrcIdx = 82;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.Scope_PWORK_p.LoggedData
	  section.data(13).logicalSrcIdx = 83;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.Scope2_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 84;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.Scope3_PWORK_k.LoggedData
	  section.data(15).logicalSrcIdx = 85;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.Scope4_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 86;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.Scope_PWORK_py.LoggedData
	  section.data(17).logicalSrcIdx = 87;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Scope_PWORK_j.LoggedData
	  section.data(18).logicalSrcIdx = 88;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.Scope_PWORK_g.LoggedData
	  section.data(19).logicalSrcIdx = 89;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.Scope1_PWORK_k.LoggedData
	  section.data(20).logicalSrcIdx = 90;
	  section.data(20).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 91;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.m_bpIndex
	  section.data(1).logicalSrcIdx = 92;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.m_bpIndex_f
	  section.data(2).logicalSrcIdx = 93;
	  section.data(2).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.m_bpIndex_m
	  section.data(3).logicalSrcIdx = 94;
	  section.data(3).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.RandSeed
	  section.data(4).logicalSrcIdx = 95;
	  section.data(4).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.RandSeed_n
	  section.data(5).logicalSrcIdx = 96;
	  section.data(5).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.RandSeed_g
	  section.data(6).logicalSrcIdx = 97;
	  section.data(6).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.RandSeed_g2
	  section.data(7).logicalSrcIdx = 98;
	  section.data(7).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 99;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Integrator_IWORK
	  section.data(2).logicalSrcIdx = 100;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Integrator2_IWORK
	  section.data(3).logicalSrcIdx = 101;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Integrator3_IWORK
	  section.data(4).logicalSrcIdx = 102;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Delay1_DSTATE
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Delay_DSTATE_e
	  section.data(2).logicalSrcIdx = 105;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 38;
      section.data(38)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_PrevRese
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.If_ActiveSubsystem
	  section.data(2).logicalSrcIdx = 107;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator1_PrevRes
	  section.data(3).logicalSrcIdx = 108;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Integrator_PrevResetState
	  section.data(4).logicalSrcIdx = 109;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.Integrator_PrevResetState_l
	  section.data(5).logicalSrcIdx = 110;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem
	  section.data(6).logicalSrcIdx = 111;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem_c
	  section.data(7).logicalSrcIdx = 112;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC
	  section.data(8).logicalSrcIdx = 113;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_b
	  section.data(9).logicalSrcIdx = 114;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_c
	  section.data(10).logicalSrcIdx = 115;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_l
	  section.data(11).logicalSrcIdx = 116;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC
	  section.data(12).logicalSrcIdx = 117;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.singleWptsTrajectory_SubsysRanB
	  section.data(13).logicalSrcIdx = 118;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_co
	  section.data(14).logicalSrcIdx = 119;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(15).logicalSrcIdx = 120;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(16).logicalSrcIdx = 121;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_h
	  section.data(17).logicalSrcIdx = 122;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n
	  section.data(18).logicalSrcIdx = 123;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.Pretraitement_SubsysRanBC
	  section.data(19).logicalSrcIdx = 124;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.SubsystemAuto_SubsysRanBC
	  section.data(20).logicalSrcIdx = 125;
	  section.data(20).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.Subsystem2_SubsysRanBC
	  section.data(21).logicalSrcIdx = 126;
	  section.data(21).dtTransOffset = 20;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_k
	  section.data(22).logicalSrcIdx = 127;
	  section.data(22).dtTransOffset = 21;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g
	  section.data(23).logicalSrcIdx = 128;
	  section.data(23).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e
	  section.data(24).logicalSrcIdx = 129;
	  section.data(24).dtTransOffset = 23;
	
	  ;% proc_control_node_DW.SubsystemManual_SubsysRanBC
	  section.data(25).logicalSrcIdx = 130;
	  section.data(25).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_m
	  section.data(26).logicalSrcIdx = 131;
	  section.data(26).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_g
	  section.data(27).logicalSrcIdx = 132;
	  section.data(27).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_a
	  section.data(28).logicalSrcIdx = 133;
	  section.data(28).dtTransOffset = 27;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_b
	  section.data(29).logicalSrcIdx = 134;
	  section.data(29).dtTransOffset = 28;
	
	  ;% proc_control_node_DW.IDLE_SubsysRanBC
	  section.data(30).logicalSrcIdx = 135;
	  section.data(30).dtTransOffset = 29;
	
	  ;% proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC
	  section.data(31).logicalSrcIdx = 136;
	  section.data(31).dtTransOffset = 30;
	
	  ;% proc_control_node_DW.QuaternionNonlinearMPC_SubsysRa
	  section.data(32).logicalSrcIdx = 137;
	  section.data(32).dtTransOffset = 31;
	
	  ;% proc_control_node_DW.SendTargetReached_SubsysRanBC
	  section.data(33).logicalSrcIdx = 138;
	  section.data(33).dtTransOffset = 32;
	
	  ;% proc_control_node_DW.ROSOutput_SubsysRanBC
	  section.data(34).logicalSrcIdx = 139;
	  section.data(34).dtTransOffset = 33;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(35).logicalSrcIdx = 140;
	  section.data(35).dtTransOffset = 34;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_j
	  section.data(36).logicalSrcIdx = 141;
	  section.data(36).dtTransOffset = 35;
	
	  ;% proc_control_node_DW.Plotvalues_SubsysRanBC
	  section.data(37).logicalSrcIdx = 142;
	  section.data(37).dtTransOffset = 36;
	
	  ;% proc_control_node_DW.ModlePhysique_SubsysRanBC
	  section.data(38).logicalSrcIdx = 143;
	  section.data(38).dtTransOffset = 37;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_IC_LOADI
	  section.data(1).logicalSrcIdx = 144;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 145;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.ROSOutput_MODE
	  section.data(2).logicalSrcIdx = 179;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Plotvalues_MODE
	  section.data(3).logicalSrcIdx = 180;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.ModlePhysique_MODE
	  section.data(4).logicalSrcIdx = 181;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Subsystem1_e.Subsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 182;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Subsystem1.Subsystem1_SubsysRanBC
	  section.data(1).logicalSrcIdx = 183;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
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


  targMap.checksum0 = 892731744;
  targMap.checksum1 = 2089290880;
  targMap.checksum2 = 2412643030;
  targMap.checksum3 = 765891732;

