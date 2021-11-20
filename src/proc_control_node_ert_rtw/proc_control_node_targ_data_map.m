  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 49;
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
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.simulation
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
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
	
	  ;% proc_control_node_P.dampA
	  section.data(14).logicalSrcIdx = 16;
	  section.data(14).dtTransOffset = 563;
	
	  ;% proc_control_node_P.dampB
	  section.data(15).logicalSrcIdx = 17;
	  section.data(15).dtTransOffset = 564;
	
	  ;% proc_control_node_P.ratioMax
	  section.data(16).logicalSrcIdx = 18;
	  section.data(16).dtTransOffset = 565;
	
	  ;% proc_control_node_P.ratioMin
	  section.data(17).logicalSrcIdx = 19;
	  section.data(17).dtTransOffset = 566;
	
	  ;% proc_control_node_P.waPhi
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 567;
	
	  ;% proc_control_node_P.waPsi
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 568;
	
	  ;% proc_control_node_P.waTheta
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 569;
	
	  ;% proc_control_node_P.waX
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 570;
	
	  ;% proc_control_node_P.waY
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 571;
	
	  ;% proc_control_node_P.waZ
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 572;
	
	  ;% proc_control_node_P.wfPhi
	  section.data(24).logicalSrcIdx = 26;
	  section.data(24).dtTransOffset = 573;
	
	  ;% proc_control_node_P.wfPsi
	  section.data(25).logicalSrcIdx = 27;
	  section.data(25).dtTransOffset = 574;
	
	  ;% proc_control_node_P.wfTheta
	  section.data(26).logicalSrcIdx = 28;
	  section.data(26).dtTransOffset = 575;
	
	  ;% proc_control_node_P.wfX
	  section.data(27).logicalSrcIdx = 29;
	  section.data(27).dtTransOffset = 576;
	
	  ;% proc_control_node_P.wfY
	  section.data(28).logicalSrcIdx = 30;
	  section.data(28).dtTransOffset = 577;
	
	  ;% proc_control_node_P.wfZ
	  section.data(29).logicalSrcIdx = 31;
	  section.data(29).dtTransOffset = 578;
	
	  ;% proc_control_node_P.wn_l
	  section.data(30).logicalSrcIdx = 32;
	  section.data(30).dtTransOffset = 579;
	
	  ;% proc_control_node_P.wpPhi
	  section.data(31).logicalSrcIdx = 33;
	  section.data(31).dtTransOffset = 580;
	
	  ;% proc_control_node_P.wpPsi
	  section.data(32).logicalSrcIdx = 34;
	  section.data(32).dtTransOffset = 581;
	
	  ;% proc_control_node_P.wpTheta
	  section.data(33).logicalSrcIdx = 35;
	  section.data(33).dtTransOffset = 582;
	
	  ;% proc_control_node_P.wpX
	  section.data(34).logicalSrcIdx = 36;
	  section.data(34).dtTransOffset = 583;
	
	  ;% proc_control_node_P.wpY
	  section.data(35).logicalSrcIdx = 37;
	  section.data(35).dtTransOffset = 584;
	
	  ;% proc_control_node_P.wpZ
	  section.data(36).logicalSrcIdx = 38;
	  section.data(36).dtTransOffset = 585;
	
	  ;% proc_control_node_P.zeta_l
	  section.data(37).logicalSrcIdx = 39;
	  section.data(37).dtTransOffset = 586;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.PWM
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% proc_control_node_P.BandLimitedWhiteNoise_Cov
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_Cov
	  section.data(2).logicalSrcIdx = 42;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.SecondOrderFilter_FilterType
	  section.data(3).logicalSrcIdx = 43;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.DiscreteDerivative_ICPrevScaled
	  section.data(4).logicalSrcIdx = 44;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise_seed
	  section.data(5).logicalSrcIdx = 45;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.BandLimitedWhiteNoise1_seed
	  section.data(6).logicalSrcIdx = 46;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_P.MinMaxRunningResettable_vinit
	  section.data(1).logicalSrcIdx = 47;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.MinMaxRunningResettable1_vinit
	  section.data(2).logicalSrcIdx = 48;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value
	  section.data(1).logicalSrcIdx = 49;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_f
	  section.data(1).logicalSrcIdx = 50;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0
	  section.data(1).logicalSrcIdx = 51;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_i
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_l
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_l
	  section.data(1).logicalSrcIdx = 54;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_g
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_o
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_m
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_k
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_p
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_f2
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_h
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Output_Y0
	  section.data(1).logicalSrcIdx = 62;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.CleanOutput_Y0
	  section.data(1).logicalSrcIdx = 63;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Output_Y0_k
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.SensorsOutput_Y0
	  section.data(1).logicalSrcIdx = 65;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_d
	  section.data(1).logicalSrcIdx = 66;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_lq
	  section.data(1).logicalSrcIdx = 67;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_oj
	  section.data(1).logicalSrcIdx = 68;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_g
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_b
	  section.data(1).logicalSrcIdx = 70;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_pb
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_hg
	  section.data(1).logicalSrcIdx = 72;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_h
	  section.data(1).logicalSrcIdx = 73;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ok
	  section.data(1).logicalSrcIdx = 74;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_m
	  section.data(1).logicalSrcIdx = 75;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_c
	  section.data(1).logicalSrcIdx = 76;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_e
	  section.data(1).logicalSrcIdx = 77;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_e
	  section.data(1).logicalSrcIdx = 78;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_kd
	  section.data(1).logicalSrcIdx = 79;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(38) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_n
	  section.data(1).logicalSrcIdx = 80;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_d
	  section.data(1).logicalSrcIdx = 81;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(40) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_nb
	  section.data(1).logicalSrcIdx = 82;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_oz
	  section.data(1).logicalSrcIdx = 83;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_bv
	  section.data(1).logicalSrcIdx = 84;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(43) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_ly
	  section.data(1).logicalSrcIdx = 85;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(44) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Out1_Y0_k
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(45) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_P.Constant_Value_a
	  section.data(1).logicalSrcIdx = 87;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(46) = section;
      clear section
      
      section.nData     = 238;
      section.data(238)  = dumData; %prealloc
      
	  ;% proc_control_node_P.TransferFcn_A
	  section.data(1).logicalSrcIdx = 88;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.TransferFcn_C
	  section.data(2).logicalSrcIdx = 89;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.TransferFcn_A_j
	  section.data(3).logicalSrcIdx = 90;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.TransferFcn_C_m
	  section.data(4).logicalSrcIdx = 91;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_P.TransferFcn_A_h
	  section.data(5).logicalSrcIdx = 92;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_P.TransferFcn_C_l
	  section.data(6).logicalSrcIdx = 93;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_P.TransferFcn_A_i
	  section.data(7).logicalSrcIdx = 94;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_P.TransferFcn_C_f
	  section.data(8).logicalSrcIdx = 95;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_P.TransferFcn_A_jp
	  section.data(9).logicalSrcIdx = 96;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_P.TransferFcn_C_n
	  section.data(10).logicalSrcIdx = 97;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_P.TransferFcn_A_l
	  section.data(11).logicalSrcIdx = 98;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_P.TransferFcn_C_nr
	  section.data(12).logicalSrcIdx = 99;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_P.TransferFcn_A_p
	  section.data(13).logicalSrcIdx = 100;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_P.TransferFcn_C_h
	  section.data(14).logicalSrcIdx = 101;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_P.TransferFcn_A_n
	  section.data(15).logicalSrcIdx = 102;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_P.TransferFcn_C_fa
	  section.data(16).logicalSrcIdx = 103;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_P.ZDrift_Value
	  section.data(17).logicalSrcIdx = 104;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_P.XWave_Bias
	  section.data(18).logicalSrcIdx = 105;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_P.YWave_Bias
	  section.data(19).logicalSrcIdx = 106;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_P.ZWave_Bias
	  section.data(20).logicalSrcIdx = 107;
	  section.data(20).dtTransOffset = 19;
	
	  ;% proc_control_node_P.RollWave_Bias
	  section.data(21).logicalSrcIdx = 108;
	  section.data(21).dtTransOffset = 20;
	
	  ;% proc_control_node_P.PitchWave_Bias
	  section.data(22).logicalSrcIdx = 109;
	  section.data(22).dtTransOffset = 21;
	
	  ;% proc_control_node_P.YawWave_Bias
	  section.data(23).logicalSrcIdx = 110;
	  section.data(23).dtTransOffset = 22;
	
	  ;% proc_control_node_P.InitialBodyvelocity_Value
	  section.data(24).logicalSrcIdx = 111;
	  section.data(24).dtTransOffset = 23;
	
	  ;% proc_control_node_P.InitialAngularRates_Value
	  section.data(25).logicalSrcIdx = 112;
	  section.data(25).dtTransOffset = 26;
	
	  ;% proc_control_node_P.ydevantZhaut_Value
	  section.data(26).logicalSrcIdx = 113;
	  section.data(26).dtTransOffset = 29;
	
	  ;% proc_control_node_P.WhiteNoise_Mean
	  section.data(27).logicalSrcIdx = 114;
	  section.data(27).dtTransOffset = 32;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev
	  section.data(28).logicalSrcIdx = 115;
	  section.data(28).dtTransOffset = 33;
	
	  ;% proc_control_node_P.WhiteNoise_Mean_e
	  section.data(29).logicalSrcIdx = 116;
	  section.data(29).dtTransOffset = 34;
	
	  ;% proc_control_node_P.WhiteNoise_StdDev_d
	  section.data(30).logicalSrcIdx = 117;
	  section.data(30).dtTransOffset = 35;
	
	  ;% proc_control_node_P.Constant_Value_mj
	  section.data(31).logicalSrcIdx = 118;
	  section.data(31).dtTransOffset = 36;
	
	  ;% proc_control_node_P.Gain_Gain
	  section.data(32).logicalSrcIdx = 119;
	  section.data(32).dtTransOffset = 37;
	
	  ;% proc_control_node_P.Gain1_Gain
	  section.data(33).logicalSrcIdx = 120;
	  section.data(33).dtTransOffset = 38;
	
	  ;% proc_control_node_P.Gain2_Gain
	  section.data(34).logicalSrcIdx = 121;
	  section.data(34).dtTransOffset = 39;
	
	  ;% proc_control_node_P.u2_Gain
	  section.data(35).logicalSrcIdx = 122;
	  section.data(35).dtTransOffset = 40;
	
	  ;% proc_control_node_P.Constant_Value_k2
	  section.data(36).logicalSrcIdx = 123;
	  section.data(36).dtTransOffset = 41;
	
	  ;% proc_control_node_P.Gain_Gain_j
	  section.data(37).logicalSrcIdx = 124;
	  section.data(37).dtTransOffset = 42;
	
	  ;% proc_control_node_P.Gain1_Gain_e
	  section.data(38).logicalSrcIdx = 125;
	  section.data(38).dtTransOffset = 43;
	
	  ;% proc_control_node_P.Gain2_Gain_d
	  section.data(39).logicalSrcIdx = 126;
	  section.data(39).dtTransOffset = 44;
	
	  ;% proc_control_node_P.Constant_Value_gp
	  section.data(40).logicalSrcIdx = 127;
	  section.data(40).dtTransOffset = 45;
	
	  ;% proc_control_node_P.Gain_Gain_e
	  section.data(41).logicalSrcIdx = 128;
	  section.data(41).dtTransOffset = 46;
	
	  ;% proc_control_node_P.Gain1_Gain_eg
	  section.data(42).logicalSrcIdx = 129;
	  section.data(42).dtTransOffset = 47;
	
	  ;% proc_control_node_P.Gain2_Gain_l
	  section.data(43).logicalSrcIdx = 130;
	  section.data(43).dtTransOffset = 48;
	
	  ;% proc_control_node_P.Constant_Value_iw
	  section.data(44).logicalSrcIdx = 131;
	  section.data(44).dtTransOffset = 49;
	
	  ;% proc_control_node_P.Gain_Gain_m
	  section.data(45).logicalSrcIdx = 132;
	  section.data(45).dtTransOffset = 50;
	
	  ;% proc_control_node_P.Gain1_Gain_g
	  section.data(46).logicalSrcIdx = 133;
	  section.data(46).dtTransOffset = 51;
	
	  ;% proc_control_node_P.Gain2_Gain_b
	  section.data(47).logicalSrcIdx = 134;
	  section.data(47).dtTransOffset = 52;
	
	  ;% proc_control_node_P.y_Y0
	  section.data(48).logicalSrcIdx = 135;
	  section.data(48).dtTransOffset = 53;
	
	  ;% proc_control_node_P.Constant_Value_f2j
	  section.data(49).logicalSrcIdx = 136;
	  section.data(49).dtTransOffset = 54;
	
	  ;% proc_control_node_P.Constant1_Value
	  section.data(50).logicalSrcIdx = 137;
	  section.data(50).dtTransOffset = 55;
	
	  ;% proc_control_node_P.Delay_InitialCondition
	  section.data(51).logicalSrcIdx = 138;
	  section.data(51).dtTransOffset = 56;
	
	  ;% proc_control_node_P.ENU2NED_Value
	  section.data(52).logicalSrcIdx = 139;
	  section.data(52).dtTransOffset = 57;
	
	  ;% proc_control_node_P.u2_Gain_g
	  section.data(53).logicalSrcIdx = 140;
	  section.data(53).dtTransOffset = 60;
	
	  ;% proc_control_node_P.Constant_Value_p
	  section.data(54).logicalSrcIdx = 141;
	  section.data(54).dtTransOffset = 61;
	
	  ;% proc_control_node_P.Gain2_Gain_a
	  section.data(55).logicalSrcIdx = 142;
	  section.data(55).dtTransOffset = 62;
	
	  ;% proc_control_node_P.Gain_Gain_l
	  section.data(56).logicalSrcIdx = 143;
	  section.data(56).dtTransOffset = 63;
	
	  ;% proc_control_node_P.Gain1_Gain_c
	  section.data(57).logicalSrcIdx = 144;
	  section.data(57).dtTransOffset = 64;
	
	  ;% proc_control_node_P.Gain_Gain_d
	  section.data(58).logicalSrcIdx = 145;
	  section.data(58).dtTransOffset = 65;
	
	  ;% proc_control_node_P.Constant_Value_fk
	  section.data(59).logicalSrcIdx = 146;
	  section.data(59).dtTransOffset = 66;
	
	  ;% proc_control_node_P.Gain2_Gain_i
	  section.data(60).logicalSrcIdx = 147;
	  section.data(60).dtTransOffset = 67;
	
	  ;% proc_control_node_P.Gain1_Gain_h
	  section.data(61).logicalSrcIdx = 148;
	  section.data(61).dtTransOffset = 68;
	
	  ;% proc_control_node_P.Gain_Gain_f
	  section.data(62).logicalSrcIdx = 149;
	  section.data(62).dtTransOffset = 69;
	
	  ;% proc_control_node_P.Gain1_Gain_m
	  section.data(63).logicalSrcIdx = 150;
	  section.data(63).dtTransOffset = 70;
	
	  ;% proc_control_node_P.Constant_Value_ek
	  section.data(64).logicalSrcIdx = 151;
	  section.data(64).dtTransOffset = 71;
	
	  ;% proc_control_node_P.Gain2_Gain_db
	  section.data(65).logicalSrcIdx = 152;
	  section.data(65).dtTransOffset = 72;
	
	  ;% proc_control_node_P.Constant_Value_pz
	  section.data(66).logicalSrcIdx = 153;
	  section.data(66).dtTransOffset = 73;
	
	  ;% proc_control_node_P.Constant_Value_pm
	  section.data(67).logicalSrcIdx = 154;
	  section.data(67).dtTransOffset = 74;
	
	  ;% proc_control_node_P.Gain_Gain_ei
	  section.data(68).logicalSrcIdx = 155;
	  section.data(68).dtTransOffset = 75;
	
	  ;% proc_control_node_P.Gain_Gain_i
	  section.data(69).logicalSrcIdx = 156;
	  section.data(69).dtTransOffset = 76;
	
	  ;% proc_control_node_P.MPCmanager_eInit
	  section.data(70).logicalSrcIdx = 157;
	  section.data(70).dtTransOffset = 77;
	
	  ;% proc_control_node_P.Delay_InitialCondition_g
	  section.data(71).logicalSrcIdx = 158;
	  section.data(71).dtTransOffset = 78;
	
	  ;% proc_control_node_P.md_zero_Value
	  section.data(72).logicalSrcIdx = 159;
	  section.data(72).dtTransOffset = 86;
	
	  ;% proc_control_node_P.mvtarget_zero_Value
	  section.data(73).logicalSrcIdx = 160;
	  section.data(73).dtTransOffset = 87;
	
	  ;% proc_control_node_P.ymin_zero_Value
	  section.data(74).logicalSrcIdx = 161;
	  section.data(74).dtTransOffset = 95;
	
	  ;% proc_control_node_P.ymax_zero_Value
	  section.data(75).logicalSrcIdx = 162;
	  section.data(75).dtTransOffset = 108;
	
	  ;% proc_control_node_P.dmvmin_zero_Value
	  section.data(76).logicalSrcIdx = 163;
	  section.data(76).dtTransOffset = 121;
	
	  ;% proc_control_node_P.dmvmax_zero_Value
	  section.data(77).logicalSrcIdx = 164;
	  section.data(77).dtTransOffset = 129;
	
	  ;% proc_control_node_P.xmin_zero_Value
	  section.data(78).logicalSrcIdx = 165;
	  section.data(78).dtTransOffset = 137;
	
	  ;% proc_control_node_P.xmax_zero_Value
	  section.data(79).logicalSrcIdx = 166;
	  section.data(79).dtTransOffset = 150;
	
	  ;% proc_control_node_P.ecrwt_zero_Value
	  section.data(80).logicalSrcIdx = 167;
	  section.data(80).dtTransOffset = 163;
	
	  ;% proc_control_node_P.params_zero_Value
	  section.data(81).logicalSrcIdx = 168;
	  section.data(81).dtTransOffset = 164;
	
	  ;% proc_control_node_P.PulseGenerator_Amp
	  section.data(82).logicalSrcIdx = 169;
	  section.data(82).dtTransOffset = 165;
	
	  ;% proc_control_node_P.PulseGenerator_Period
	  section.data(83).logicalSrcIdx = 170;
	  section.data(83).dtTransOffset = 166;
	
	  ;% proc_control_node_P.PulseGenerator_Duty
	  section.data(84).logicalSrcIdx = 171;
	  section.data(84).dtTransOffset = 167;
	
	  ;% proc_control_node_P.PulseGenerator_PhaseDelay
	  section.data(85).logicalSrcIdx = 172;
	  section.data(85).dtTransOffset = 168;
	
	  ;% proc_control_node_P.MATLABSystem_k
	  section.data(86).logicalSrcIdx = 173;
	  section.data(86).dtTransOffset = 169;
	
	  ;% proc_control_node_P.Constant_Value_d1
	  section.data(87).logicalSrcIdx = 174;
	  section.data(87).dtTransOffset = 170;
	
	  ;% proc_control_node_P.Constant1_Value_p
	  section.data(88).logicalSrcIdx = 175;
	  section.data(88).dtTransOffset = 171;
	
	  ;% proc_control_node_P.TSamp_WtEt
	  section.data(89).logicalSrcIdx = 176;
	  section.data(89).dtTransOffset = 172;
	
	  ;% proc_control_node_P.Constant_Value_lp
	  section.data(90).logicalSrcIdx = 177;
	  section.data(90).dtTransOffset = 173;
	
	  ;% proc_control_node_P.Constant_Value_du
	  section.data(91).logicalSrcIdx = 178;
	  section.data(91).dtTransOffset = 174;
	
	  ;% proc_control_node_P.E_zero_Value
	  section.data(92).logicalSrcIdx = 179;
	  section.data(92).dtTransOffset = 175;
	
	  ;% proc_control_node_P.F_zero_Value
	  section.data(93).logicalSrcIdx = 180;
	  section.data(93).dtTransOffset = 183;
	
	  ;% proc_control_node_P.G_zero_Value
	  section.data(94).logicalSrcIdx = 181;
	  section.data(94).dtTransOffset = 195;
	
	  ;% proc_control_node_P.LastPcov_InitialCondition
	  section.data(95).logicalSrcIdx = 182;
	  section.data(95).dtTransOffset = 196;
	
	  ;% proc_control_node_P.ywt_zero_Value
	  section.data(96).logicalSrcIdx = 183;
	  section.data(96).dtTransOffset = 596;
	
	  ;% proc_control_node_P.uwt_zero_Value
	  section.data(97).logicalSrcIdx = 184;
	  section.data(97).dtTransOffset = 608;
	
	  ;% proc_control_node_P.duwt_zero_Value
	  section.data(98).logicalSrcIdx = 185;
	  section.data(98).dtTransOffset = 616;
	
	  ;% proc_control_node_P.extmv_zero_Value
	  section.data(99).logicalSrcIdx = 186;
	  section.data(99).dtTransOffset = 624;
	
	  ;% proc_control_node_P.extmv_scale_Gain
	  section.data(100).logicalSrcIdx = 187;
	  section.data(100).dtTransOffset = 632;
	
	  ;% proc_control_node_P.last_mv_InitialCondition
	  section.data(101).logicalSrcIdx = 188;
	  section.data(101).dtTransOffset = 640;
	
	  ;% proc_control_node_P.Constant_Value_oq
	  section.data(102).logicalSrcIdx = 189;
	  section.data(102).dtTransOffset = 648;
	
	  ;% proc_control_node_P.ym_zero_Value
	  section.data(103).logicalSrcIdx = 190;
	  section.data(103).dtTransOffset = 656;
	
	  ;% proc_control_node_P.md_zero_Value_m
	  section.data(104).logicalSrcIdx = 191;
	  section.data(104).dtTransOffset = 668;
	
	  ;% proc_control_node_P.umin_zero_Value
	  section.data(105).logicalSrcIdx = 192;
	  section.data(105).dtTransOffset = 669;
	
	  ;% proc_control_node_P.umax_zero_Value
	  section.data(106).logicalSrcIdx = 193;
	  section.data(106).dtTransOffset = 677;
	
	  ;% proc_control_node_P.ymin_zero_Value_j
	  section.data(107).logicalSrcIdx = 194;
	  section.data(107).dtTransOffset = 685;
	
	  ;% proc_control_node_P.ymax_zero_Value_g
	  section.data(108).logicalSrcIdx = 195;
	  section.data(108).dtTransOffset = 697;
	
	  ;% proc_control_node_P.umin_scale4_Gain
	  section.data(109).logicalSrcIdx = 196;
	  section.data(109).dtTransOffset = 709;
	
	  ;% proc_control_node_P.ymin_scale1_Gain
	  section.data(110).logicalSrcIdx = 197;
	  section.data(110).dtTransOffset = 717;
	
	  ;% proc_control_node_P.S_zero_Value
	  section.data(111).logicalSrcIdx = 198;
	  section.data(111).dtTransOffset = 729;
	
	  ;% proc_control_node_P.ymin_scale2_Gain
	  section.data(112).logicalSrcIdx = 199;
	  section.data(112).dtTransOffset = 730;
	
	  ;% proc_control_node_P.switch_zero_Value
	  section.data(113).logicalSrcIdx = 200;
	  section.data(113).dtTransOffset = 731;
	
	  ;% proc_control_node_P.mvtarget_zero_Value_o
	  section.data(114).logicalSrcIdx = 201;
	  section.data(114).dtTransOffset = 732;
	
	  ;% proc_control_node_P.uref_scale_Gain
	  section.data(115).logicalSrcIdx = 202;
	  section.data(115).dtTransOffset = 740;
	
	  ;% proc_control_node_P.ecrwt_zero_Value_j
	  section.data(116).logicalSrcIdx = 203;
	  section.data(116).dtTransOffset = 748;
	
	  ;% proc_control_node_P.Delay1_InitialCondition
	  section.data(117).logicalSrcIdx = 204;
	  section.data(117).dtTransOffset = 749;
	
	  ;% proc_control_node_P.u_scale_Gain
	  section.data(118).logicalSrcIdx = 205;
	  section.data(118).dtTransOffset = 757;
	
	  ;% proc_control_node_P.PulseGenerator_Amp_a
	  section.data(119).logicalSrcIdx = 206;
	  section.data(119).dtTransOffset = 765;
	
	  ;% proc_control_node_P.PulseGenerator_Period_g
	  section.data(120).logicalSrcIdx = 207;
	  section.data(120).dtTransOffset = 766;
	
	  ;% proc_control_node_P.PulseGenerator_Duty_c
	  section.data(121).logicalSrcIdx = 208;
	  section.data(121).dtTransOffset = 767;
	
	  ;% proc_control_node_P.PulseGenerator_PhaseDelay_h
	  section.data(122).logicalSrcIdx = 209;
	  section.data(122).dtTransOffset = 768;
	
	  ;% proc_control_node_P.E_zero_Value_m
	  section.data(123).logicalSrcIdx = 210;
	  section.data(123).dtTransOffset = 769;
	
	  ;% proc_control_node_P.F_zero_Value_d
	  section.data(124).logicalSrcIdx = 211;
	  section.data(124).dtTransOffset = 777;
	
	  ;% proc_control_node_P.G_zero_Value_l
	  section.data(125).logicalSrcIdx = 212;
	  section.data(125).dtTransOffset = 790;
	
	  ;% proc_control_node_P.LastPcov_InitialCondition_k
	  section.data(126).logicalSrcIdx = 213;
	  section.data(126).dtTransOffset = 791;
	
	  ;% proc_control_node_P.ywt_zero_Value_f
	  section.data(127).logicalSrcIdx = 214;
	  section.data(127).dtTransOffset = 1232;
	
	  ;% proc_control_node_P.uwt_zero_Value_f
	  section.data(128).logicalSrcIdx = 215;
	  section.data(128).dtTransOffset = 1245;
	
	  ;% proc_control_node_P.duwt_zero_Value_a
	  section.data(129).logicalSrcIdx = 216;
	  section.data(129).dtTransOffset = 1253;
	
	  ;% proc_control_node_P.extmv_zero_Value_g
	  section.data(130).logicalSrcIdx = 217;
	  section.data(130).dtTransOffset = 1261;
	
	  ;% proc_control_node_P.extmv_scale_Gain_p
	  section.data(131).logicalSrcIdx = 218;
	  section.data(131).dtTransOffset = 1269;
	
	  ;% proc_control_node_P.last_mv_InitialCondition_k
	  section.data(132).logicalSrcIdx = 219;
	  section.data(132).dtTransOffset = 1277;
	
	  ;% proc_control_node_P.Constant_Value_e3
	  section.data(133).logicalSrcIdx = 220;
	  section.data(133).dtTransOffset = 1285;
	
	  ;% proc_control_node_P.ym_zero_Value_e
	  section.data(134).logicalSrcIdx = 221;
	  section.data(134).dtTransOffset = 1293;
	
	  ;% proc_control_node_P.md_zero_Value_n
	  section.data(135).logicalSrcIdx = 222;
	  section.data(135).dtTransOffset = 1306;
	
	  ;% proc_control_node_P.umin_zero_Value_d
	  section.data(136).logicalSrcIdx = 223;
	  section.data(136).dtTransOffset = 1307;
	
	  ;% proc_control_node_P.umax_zero_Value_m
	  section.data(137).logicalSrcIdx = 224;
	  section.data(137).dtTransOffset = 1315;
	
	  ;% proc_control_node_P.ymin_zero_Value_e
	  section.data(138).logicalSrcIdx = 225;
	  section.data(138).dtTransOffset = 1323;
	
	  ;% proc_control_node_P.ymax_zero_Value_a
	  section.data(139).logicalSrcIdx = 226;
	  section.data(139).dtTransOffset = 1336;
	
	  ;% proc_control_node_P.umin_scale4_Gain_o
	  section.data(140).logicalSrcIdx = 227;
	  section.data(140).dtTransOffset = 1349;
	
	  ;% proc_control_node_P.ymin_scale1_Gain_k
	  section.data(141).logicalSrcIdx = 228;
	  section.data(141).dtTransOffset = 1357;
	
	  ;% proc_control_node_P.S_zero_Value_d
	  section.data(142).logicalSrcIdx = 229;
	  section.data(142).dtTransOffset = 1370;
	
	  ;% proc_control_node_P.ymin_scale2_Gain_n
	  section.data(143).logicalSrcIdx = 230;
	  section.data(143).dtTransOffset = 1371;
	
	  ;% proc_control_node_P.switch_zero_Value_f
	  section.data(144).logicalSrcIdx = 231;
	  section.data(144).dtTransOffset = 1372;
	
	  ;% proc_control_node_P.mvtarget_zero_Value_g
	  section.data(145).logicalSrcIdx = 232;
	  section.data(145).dtTransOffset = 1373;
	
	  ;% proc_control_node_P.uref_scale_Gain_c
	  section.data(146).logicalSrcIdx = 233;
	  section.data(146).dtTransOffset = 1381;
	
	  ;% proc_control_node_P.ecrwt_zero_Value_p
	  section.data(147).logicalSrcIdx = 234;
	  section.data(147).dtTransOffset = 1389;
	
	  ;% proc_control_node_P.Delay1_InitialCondition_l
	  section.data(148).logicalSrcIdx = 235;
	  section.data(148).dtTransOffset = 1390;
	
	  ;% proc_control_node_P.u_scale_Gain_c
	  section.data(149).logicalSrcIdx = 236;
	  section.data(149).dtTransOffset = 1398;
	
	  ;% proc_control_node_P.PulseGenerator_Amp_b
	  section.data(150).logicalSrcIdx = 237;
	  section.data(150).dtTransOffset = 1406;
	
	  ;% proc_control_node_P.PulseGenerator_Period_h
	  section.data(151).logicalSrcIdx = 238;
	  section.data(151).dtTransOffset = 1407;
	
	  ;% proc_control_node_P.PulseGenerator_Duty_n
	  section.data(152).logicalSrcIdx = 239;
	  section.data(152).dtTransOffset = 1408;
	
	  ;% proc_control_node_P.PulseGenerator_PhaseDelay_c
	  section.data(153).logicalSrcIdx = 240;
	  section.data(153).dtTransOffset = 1409;
	
	  ;% proc_control_node_P.Constant_Value_mg
	  section.data(154).logicalSrcIdx = 241;
	  section.data(154).dtTransOffset = 1410;
	
	  ;% proc_control_node_P.Constant1_Value_n
	  section.data(155).logicalSrcIdx = 242;
	  section.data(155).dtTransOffset = 1411;
	
	  ;% proc_control_node_P.Constant2_Value
	  section.data(156).logicalSrcIdx = 243;
	  section.data(156).dtTransOffset = 1419;
	
	  ;% proc_control_node_P.Quat_Y0
	  section.data(157).logicalSrcIdx = 244;
	  section.data(157).dtTransOffset = 1420;
	
	  ;% proc_control_node_P.siydevant_Value
	  section.data(158).logicalSrcIdx = 245;
	  section.data(158).dtTransOffset = 1421;
	
	  ;% proc_control_node_P.u2_Gain_b
	  section.data(159).logicalSrcIdx = 246;
	  section.data(159).dtTransOffset = 1424;
	
	  ;% proc_control_node_P.enable_Y0
	  section.data(160).logicalSrcIdx = 247;
	  section.data(160).dtTransOffset = 1425;
	
	  ;% proc_control_node_P.error_Y0
	  section.data(161).logicalSrcIdx = 248;
	  section.data(161).dtTransOffset = 1426;
	
	  ;% proc_control_node_P.BodyVelocity_Y0
	  section.data(162).logicalSrcIdx = 249;
	  section.data(162).dtTransOffset = 1427;
	
	  ;% proc_control_node_P.Constant1_Value_a
	  section.data(163).logicalSrcIdx = 250;
	  section.data(163).dtTransOffset = 1428;
	
	  ;% proc_control_node_P.Constant6_Value
	  section.data(164).logicalSrcIdx = 251;
	  section.data(164).dtTransOffset = 1429;
	
	  ;% proc_control_node_P.Delay_InitialCondition_l
	  section.data(165).logicalSrcIdx = 252;
	  section.data(165).dtTransOffset = 1430;
	
	  ;% proc_control_node_P.Constant_Value_fg
	  section.data(166).logicalSrcIdx = 253;
	  section.data(166).dtTransOffset = 1431;
	
	  ;% proc_control_node_P.Gain_Gain_o
	  section.data(167).logicalSrcIdx = 254;
	  section.data(167).dtTransOffset = 1432;
	
	  ;% proc_control_node_P.Gain1_Gain_k
	  section.data(168).logicalSrcIdx = 255;
	  section.data(168).dtTransOffset = 1433;
	
	  ;% proc_control_node_P.Gain2_Gain_o
	  section.data(169).logicalSrcIdx = 256;
	  section.data(169).dtTransOffset = 1434;
	
	  ;% proc_control_node_P.Constant_Value_j
	  section.data(170).logicalSrcIdx = 257;
	  section.data(170).dtTransOffset = 1435;
	
	  ;% proc_control_node_P.Gain_Gain_mq
	  section.data(171).logicalSrcIdx = 258;
	  section.data(171).dtTransOffset = 1436;
	
	  ;% proc_control_node_P.Gain1_Gain_b
	  section.data(172).logicalSrcIdx = 259;
	  section.data(172).dtTransOffset = 1437;
	
	  ;% proc_control_node_P.Gain2_Gain_k
	  section.data(173).logicalSrcIdx = 260;
	  section.data(173).dtTransOffset = 1438;
	
	  ;% proc_control_node_P.Constant_Value_ol
	  section.data(174).logicalSrcIdx = 261;
	  section.data(174).dtTransOffset = 1439;
	
	  ;% proc_control_node_P.Gain_Gain_n
	  section.data(175).logicalSrcIdx = 262;
	  section.data(175).dtTransOffset = 1440;
	
	  ;% proc_control_node_P.Gain1_Gain_ch
	  section.data(176).logicalSrcIdx = 263;
	  section.data(176).dtTransOffset = 1441;
	
	  ;% proc_control_node_P.Gain2_Gain_br
	  section.data(177).logicalSrcIdx = 264;
	  section.data(177).dtTransOffset = 1442;
	
	  ;% proc_control_node_P.xhat_Y0
	  section.data(178).logicalSrcIdx = 265;
	  section.data(178).dtTransOffset = 1443;
	
	  ;% proc_control_node_P.Constant_Value_pg
	  section.data(179).logicalSrcIdx = 266;
	  section.data(179).dtTransOffset = 1444;
	
	  ;% proc_control_node_P.Q_Value
	  section.data(180).logicalSrcIdx = 267;
	  section.data(180).dtTransOffset = 1445;
	
	  ;% proc_control_node_P.R2_Value
	  section.data(181).logicalSrcIdx = 268;
	  section.data(181).dtTransOffset = 1614;
	
	  ;% proc_control_node_P.MeasurementFcn2Inputs_Value
	  section.data(182).logicalSrcIdx = 269;
	  section.data(182).dtTransOffset = 1623;
	
	  ;% proc_control_node_P.R1_Value
	  section.data(183).logicalSrcIdx = 270;
	  section.data(183).dtTransOffset = 1624;
	
	  ;% proc_control_node_P.MeasurementFcn1Inputs_Value
	  section.data(184).logicalSrcIdx = 271;
	  section.data(184).dtTransOffset = 1688;
	
	  ;% proc_control_node_P.DataStoreMemoryP_InitialValue
	  section.data(185).logicalSrcIdx = 272;
	  section.data(185).dtTransOffset = 1689;
	
	  ;% proc_control_node_P.DataStoreMemoryx_InitialValue
	  section.data(186).logicalSrcIdx = 273;
	  section.data(186).dtTransOffset = 1858;
	
	  ;% proc_control_node_P._InitialCondition
	  section.data(187).logicalSrcIdx = 274;
	  section.data(187).dtTransOffset = 1871;
	
	  ;% proc_control_node_P.Gain_Gain_jj
	  section.data(188).logicalSrcIdx = 275;
	  section.data(188).dtTransOffset = 1879;
	
	  ;% proc_control_node_P.Gain1_Gain_j
	  section.data(189).logicalSrcIdx = 276;
	  section.data(189).dtTransOffset = 1880;
	
	  ;% proc_control_node_P.Constant_Value_a1
	  section.data(190).logicalSrcIdx = 277;
	  section.data(190).dtTransOffset = 1881;
	
	  ;% proc_control_node_P.Gain2_Gain_ob
	  section.data(191).logicalSrcIdx = 278;
	  section.data(191).dtTransOffset = 1882;
	
	  ;% proc_control_node_P.Constant7_Value
	  section.data(192).logicalSrcIdx = 279;
	  section.data(192).dtTransOffset = 1883;
	
	  ;% proc_control_node_P.Constant_Value_fi
	  section.data(193).logicalSrcIdx = 280;
	  section.data(193).dtTransOffset = 1890;
	
	  ;% proc_control_node_P.MATLABSystem_linearConvergence
	  section.data(194).logicalSrcIdx = 281;
	  section.data(194).dtTransOffset = 1903;
	
	  ;% proc_control_node_P.MATLABSystem_quaternionConverge
	  section.data(195).logicalSrcIdx = 282;
	  section.data(195).dtTransOffset = 1904;
	
	  ;% proc_control_node_P.MATLABSystem_TargetThreshold
	  section.data(196).logicalSrcIdx = 283;
	  section.data(196).dtTransOffset = 1905;
	
	  ;% proc_control_node_P.linWpts_Y0
	  section.data(197).logicalSrcIdx = 284;
	  section.data(197).dtTransOffset = 1906;
	
	  ;% proc_control_node_P.RotWpts_Y0
	  section.data(198).logicalSrcIdx = 285;
	  section.data(198).dtTransOffset = 1907;
	
	  ;% proc_control_node_P.time_Y0
	  section.data(199).logicalSrcIdx = 286;
	  section.data(199).dtTransOffset = 1908;
	
	  ;% proc_control_node_P.Input_Y0
	  section.data(200).logicalSrcIdx = 287;
	  section.data(200).dtTransOffset = 1909;
	
	  ;% proc_control_node_P.target_Y0
	  section.data(201).logicalSrcIdx = 288;
	  section.data(201).dtTransOffset = 1910;
	
	  ;% proc_control_node_P.Constant1_Value_o
	  section.data(202).logicalSrcIdx = 289;
	  section.data(202).dtTransOffset = 1911;
	
	  ;% proc_control_node_P.Out1_Y0_i
	  section.data(203).logicalSrcIdx = 290;
	  section.data(203).dtTransOffset = 1912;
	
	  ;% proc_control_node_P.Constant_Value_pb
	  section.data(204).logicalSrcIdx = 291;
	  section.data(204).dtTransOffset = 1913;
	
	  ;% proc_control_node_P.Constant_Value_hy
	  section.data(205).logicalSrcIdx = 292;
	  section.data(205).dtTransOffset = 1914;
	
	  ;% proc_control_node_P.y_Y0_m
	  section.data(206).logicalSrcIdx = 293;
	  section.data(206).dtTransOffset = 1915;
	
	  ;% proc_control_node_P.Constant_Value_it
	  section.data(207).logicalSrcIdx = 294;
	  section.data(207).dtTransOffset = 1916;
	
	  ;% proc_control_node_P.u2_Gain_bg
	  section.data(208).logicalSrcIdx = 295;
	  section.data(208).dtTransOffset = 1919;
	
	  ;% proc_control_node_P.PolynomialTrajectory1_VelocityB
	  section.data(209).logicalSrcIdx = 296;
	  section.data(209).dtTransOffset = 1920;
	
	  ;% proc_control_node_P.Gain_Gain_g
	  section.data(210).logicalSrcIdx = 297;
	  section.data(210).dtTransOffset = 1926;
	
	  ;% proc_control_node_P.Constant_Value_ep
	  section.data(211).logicalSrcIdx = 298;
	  section.data(211).dtTransOffset = 1927;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_gainval
	  section.data(212).logicalSrcIdx = 299;
	  section.data(212).dtTransOffset = 1928;
	
	  ;% proc_control_node_P.DiscreteTimeIntegrator_IC
	  section.data(213).logicalSrcIdx = 300;
	  section.data(213).dtTransOffset = 1929;
	
	  ;% proc_control_node_P.Merge_InitialOutput
	  section.data(214).logicalSrcIdx = 301;
	  section.data(214).dtTransOffset = 1930;
	
	  ;% proc_control_node_P.Merge1_InitialOutput
	  section.data(215).logicalSrcIdx = 302;
	  section.data(215).dtTransOffset = 1931;
	
	  ;% proc_control_node_P.Delay_InitialCondition_o
	  section.data(216).logicalSrcIdx = 303;
	  section.data(216).dtTransOffset = 1932;
	
	  ;% proc_control_node_P.Constant_Value_ha
	  section.data(217).logicalSrcIdx = 304;
	  section.data(217).dtTransOffset = 1933;
	
	  ;% proc_control_node_P.Constant6_Value_p
	  section.data(218).logicalSrcIdx = 305;
	  section.data(218).dtTransOffset = 1934;
	
	  ;% proc_control_node_P.Constant_Value_m5
	  section.data(219).logicalSrcIdx = 306;
	  section.data(219).dtTransOffset = 1935;
	
	  ;% proc_control_node_P.MATLABSystem_initial_mode
	  section.data(220).logicalSrcIdx = 307;
	  section.data(220).dtTransOffset = 1948;
	
	  ;% proc_control_node_P.Delay_InitialCondition_c
	  section.data(221).logicalSrcIdx = 308;
	  section.data(221).dtTransOffset = 1949;
	
	  ;% proc_control_node_P.Constant_Value_as
	  section.data(222).logicalSrcIdx = 309;
	  section.data(222).dtTransOffset = 1950;
	
	  ;% proc_control_node_P.Constant3_Value
	  section.data(223).logicalSrcIdx = 310;
	  section.data(223).dtTransOffset = 1951;
	
	  ;% proc_control_node_P.Integrator_gainval
	  section.data(224).logicalSrcIdx = 311;
	  section.data(224).dtTransOffset = 1952;
	
	  ;% proc_control_node_P.Integrator_UpperSat
	  section.data(225).logicalSrcIdx = 312;
	  section.data(225).dtTransOffset = 1953;
	
	  ;% proc_control_node_P.Integrator_LowerSat
	  section.data(226).logicalSrcIdx = 313;
	  section.data(226).dtTransOffset = 1954;
	
	  ;% proc_control_node_P.Saturation_UpperSat
	  section.data(227).logicalSrcIdx = 314;
	  section.data(227).dtTransOffset = 1955;
	
	  ;% proc_control_node_P.Saturation_LowerSat
	  section.data(228).logicalSrcIdx = 315;
	  section.data(228).dtTransOffset = 1956;
	
	  ;% proc_control_node_P.Gain3_Gain
	  section.data(229).logicalSrcIdx = 316;
	  section.data(229).dtTransOffset = 1957;
	
	  ;% proc_control_node_P.Gain_Gain_ga
	  section.data(230).logicalSrcIdx = 317;
	  section.data(230).dtTransOffset = 1958;
	
	  ;% proc_control_node_P.Constant1_Value_d
	  section.data(231).logicalSrcIdx = 318;
	  section.data(231).dtTransOffset = 1959;
	
	  ;% proc_control_node_P.Constant2_Value_m
	  section.data(232).logicalSrcIdx = 319;
	  section.data(232).dtTransOffset = 1960;
	
	  ;% proc_control_node_P.Integrator_gainval_e
	  section.data(233).logicalSrcIdx = 320;
	  section.data(233).dtTransOffset = 1961;
	
	  ;% proc_control_node_P.Integrator_UpperSat_f
	  section.data(234).logicalSrcIdx = 321;
	  section.data(234).dtTransOffset = 1962;
	
	  ;% proc_control_node_P.Integrator_LowerSat_p
	  section.data(235).logicalSrcIdx = 322;
	  section.data(235).dtTransOffset = 1963;
	
	  ;% proc_control_node_P.Saturation_UpperSat_m
	  section.data(236).logicalSrcIdx = 323;
	  section.data(236).dtTransOffset = 1964;
	
	  ;% proc_control_node_P.Saturation_LowerSat_c
	  section.data(237).logicalSrcIdx = 324;
	  section.data(237).dtTransOffset = 1965;
	
	  ;% proc_control_node_P.Delay_InitialCondition_f
	  section.data(238).logicalSrcIdx = 325;
	  section.data(238).dtTransOffset = 1966;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(47) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_P.FixedHorizonOptimizer_Ndis
	  section.data(1).logicalSrcIdx = 326;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.FixedHorizonOptimizer_Ndis_g
	  section.data(2).logicalSrcIdx = 327;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(48) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% proc_control_node_P.depthnew_Y0
	  section.data(1).logicalSrcIdx = 328;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_P.depthnew_Y0_l
	  section.data(2).logicalSrcIdx = 329;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_P.Memory_InitialCondition
	  section.data(3).logicalSrcIdx = 330;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_P.Memory_InitialCondition_b
	  section.data(4).logicalSrcIdx = 331;
	  section.data(4).dtTransOffset = 50;
	
	  ;% proc_control_node_P.yBlockOrdering_Y0
	  section.data(5).logicalSrcIdx = 332;
	  section.data(5).dtTransOffset = 98;
	
	  ;% proc_control_node_P.yBlockOrdering_Y0_o
	  section.data(6).logicalSrcIdx = 333;
	  section.data(6).dtTransOffset = 99;
	
	  ;% proc_control_node_P.BlockOrdering_Value
	  section.data(7).logicalSrcIdx = 334;
	  section.data(7).dtTransOffset = 100;
	
	  ;% proc_control_node_P.Enable1_Value
	  section.data(8).logicalSrcIdx = 335;
	  section.data(8).dtTransOffset = 101;
	
	  ;% proc_control_node_P.Delay1_InitialCondition_k
	  section.data(9).logicalSrcIdx = 336;
	  section.data(9).dtTransOffset = 102;
	
	  ;% proc_control_node_P.Merge1_InitialOutput_g
	  section.data(10).logicalSrcIdx = 337;
	  section.data(10).dtTransOffset = 103;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(49) = section;
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
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.In1_p
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_i
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.In1_c
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_n
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_o
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.MultiportSwitch
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Merge1
	  section.data(1).logicalSrcIdx = 18;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.Transpose
	  section.data(2).logicalSrcIdx = 19;
	  section.data(2).dtTransOffset = 3;
	
	  ;% proc_control_node_B.DataTypeConversion
	  section.data(3).logicalSrcIdx = 20;
	  section.data(3).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.DataTypeConversion1
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 76;
      section.data(76)  = dumData; %prealloc
      
	  ;% proc_control_node_B.ZeroOrderHold1
	  section.data(1).logicalSrcIdx = 10;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.ZeroOrderHold
	  section.data(2).logicalSrcIdx = 11;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_B.MATLABSystem_o1
	  section.data(3).logicalSrcIdx = 12;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_B.MATLABSystem_o2
	  section.data(4).logicalSrcIdx = 13;
	  section.data(4).dtTransOffset = 6;
	
	  ;% proc_control_node_B.MATLABSystem_o3
	  section.data(5).logicalSrcIdx = 14;
	  section.data(5).dtTransOffset = 9;
	
	  ;% proc_control_node_B.MATLABSystem_o4
	  section.data(6).logicalSrcIdx = 15;
	  section.data(6).dtTransOffset = 10;
	
	  ;% proc_control_node_B.DiscreteTimeIntegrator
	  section.data(7).logicalSrcIdx = 16;
	  section.data(7).dtTransOffset = 11;
	
	  ;% proc_control_node_B.Merge
	  section.data(8).logicalSrcIdx = 17;
	  section.data(8).dtTransOffset = 12;
	
	  ;% proc_control_node_B.DataTypeConversion2
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 15;
	
	  ;% proc_control_node_B.MatrixConcatenate
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 16;
	
	  ;% proc_control_node_B.Selector
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 18;
	
	  ;% proc_control_node_B.Selector1
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 24;
	
	  ;% proc_control_node_B.Selector3
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 32;
	
	  ;% proc_control_node_B.Selector4
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 33;
	
	  ;% proc_control_node_B.DataStoreRead
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 40;
	
	  ;% proc_control_node_B.Sum
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 53;
	
	  ;% proc_control_node_B.Sum_o
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 54;
	
	  ;% proc_control_node_B.Sum_c
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 55;
	
	  ;% proc_control_node_B.q0
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 56;
	
	  ;% proc_control_node_B.q1
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 57;
	
	  ;% proc_control_node_B.q2
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 58;
	
	  ;% proc_control_node_B.q3
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 59;
	
	  ;% proc_control_node_B.Merge_i
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 60;
	
	  ;% proc_control_node_B.Saturation
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 70;
	
	  ;% proc_control_node_B.WorldPosition
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 78;
	
	  ;% proc_control_node_B.qS2W
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 81;
	
	  ;% proc_control_node_B.BodyVelocity
	  section.data(27).logicalSrcIdx = 41;
	  section.data(27).dtTransOffset = 85;
	
	  ;% proc_control_node_B.AngularRate
	  section.data(28).logicalSrcIdx = 42;
	  section.data(28).dtTransOffset = 88;
	
	  ;% proc_control_node_B.q2_l
	  section.data(29).logicalSrcIdx = 43;
	  section.data(29).dtTransOffset = 91;
	
	  ;% proc_control_node_B.q0_j
	  section.data(30).logicalSrcIdx = 44;
	  section.data(30).dtTransOffset = 92;
	
	  ;% proc_control_node_B.q1_g
	  section.data(31).logicalSrcIdx = 45;
	  section.data(31).dtTransOffset = 93;
	
	  ;% proc_control_node_B.q3_h
	  section.data(32).logicalSrcIdx = 46;
	  section.data(32).dtTransOffset = 94;
	
	  ;% proc_control_node_B.Gain2
	  section.data(33).logicalSrcIdx = 47;
	  section.data(33).dtTransOffset = 95;
	
	  ;% proc_control_node_B.Gain
	  section.data(34).logicalSrcIdx = 48;
	  section.data(34).dtTransOffset = 96;
	
	  ;% proc_control_node_B.Gain1
	  section.data(35).logicalSrcIdx = 49;
	  section.data(35).dtTransOffset = 97;
	
	  ;% proc_control_node_B.Gain_j
	  section.data(36).logicalSrcIdx = 51;
	  section.data(36).dtTransOffset = 98;
	
	  ;% proc_control_node_B.Gain2_d
	  section.data(37).logicalSrcIdx = 52;
	  section.data(37).dtTransOffset = 99;
	
	  ;% proc_control_node_B.Gain1_d
	  section.data(38).logicalSrcIdx = 53;
	  section.data(38).dtTransOffset = 100;
	
	  ;% proc_control_node_B.Gain_f
	  section.data(39).logicalSrcIdx = 55;
	  section.data(39).dtTransOffset = 101;
	
	  ;% proc_control_node_B.Gain1_c
	  section.data(40).logicalSrcIdx = 56;
	  section.data(40).dtTransOffset = 102;
	
	  ;% proc_control_node_B.Gain2_k
	  section.data(41).logicalSrcIdx = 57;
	  section.data(41).dtTransOffset = 103;
	
	  ;% proc_control_node_B.WorldPosition_o
	  section.data(42).logicalSrcIdx = 64;
	  section.data(42).dtTransOffset = 104;
	
	  ;% proc_control_node_B.Quaternion
	  section.data(43).logicalSrcIdx = 65;
	  section.data(43).dtTransOffset = 107;
	
	  ;% proc_control_node_B.BodyVelocity_b
	  section.data(44).logicalSrcIdx = 66;
	  section.data(44).dtTransOffset = 111;
	
	  ;% proc_control_node_B.AngularRate_m
	  section.data(45).logicalSrcIdx = 67;
	  section.data(45).dtTransOffset = 114;
	
	  ;% proc_control_node_B.y
	  section.data(46).logicalSrcIdx = 69;
	  section.data(46).dtTransOffset = 117;
	
	  ;% proc_control_node_B.XDrift
	  section.data(47).logicalSrcIdx = 70;
	  section.data(47).dtTransOffset = 118;
	
	  ;% proc_control_node_B.YDrift
	  section.data(48).logicalSrcIdx = 71;
	  section.data(48).dtTransOffset = 119;
	
	  ;% proc_control_node_B.WorldPosition_d
	  section.data(49).logicalSrcIdx = 72;
	  section.data(49).dtTransOffset = 120;
	
	  ;% proc_control_node_B.InitialBodyvelocity
	  section.data(50).logicalSrcIdx = 73;
	  section.data(50).dtTransOffset = 123;
	
	  ;% proc_control_node_B.BodyVelocity_c
	  section.data(51).logicalSrcIdx = 74;
	  section.data(51).dtTransOffset = 126;
	
	  ;% proc_control_node_B.InitialAngularRates
	  section.data(52).logicalSrcIdx = 75;
	  section.data(52).dtTransOffset = 129;
	
	  ;% proc_control_node_B.AngularRate_e
	  section.data(53).logicalSrcIdx = 76;
	  section.data(53).dtTransOffset = 132;
	
	  ;% proc_control_node_B.PWMtoN
	  section.data(54).logicalSrcIdx = 77;
	  section.data(54).dtTransOffset = 135;
	
	  ;% proc_control_node_B.Output
	  section.data(55).logicalSrcIdx = 78;
	  section.data(55).dtTransOffset = 143;
	
	  ;% proc_control_node_B.Output_i
	  section.data(56).logicalSrcIdx = 79;
	  section.data(56).dtTransOffset = 144;
	
	  ;% proc_control_node_B.Gain_c
	  section.data(57).logicalSrcIdx = 80;
	  section.data(57).dtTransOffset = 145;
	
	  ;% proc_control_node_B.Gain1_cn
	  section.data(58).logicalSrcIdx = 81;
	  section.data(58).dtTransOffset = 146;
	
	  ;% proc_control_node_B.Gain2_k0
	  section.data(59).logicalSrcIdx = 82;
	  section.data(59).dtTransOffset = 147;
	
	  ;% proc_control_node_B.Sum_d
	  section.data(60).logicalSrcIdx = 83;
	  section.data(60).dtTransOffset = 148;
	
	  ;% proc_control_node_B.Gain_cr
	  section.data(61).logicalSrcIdx = 84;
	  section.data(61).dtTransOffset = 149;
	
	  ;% proc_control_node_B.Gain1_d2
	  section.data(62).logicalSrcIdx = 85;
	  section.data(62).dtTransOffset = 150;
	
	  ;% proc_control_node_B.Gain2_n
	  section.data(63).logicalSrcIdx = 86;
	  section.data(63).dtTransOffset = 151;
	
	  ;% proc_control_node_B.Sum_il
	  section.data(64).logicalSrcIdx = 87;
	  section.data(64).dtTransOffset = 152;
	
	  ;% proc_control_node_B.Gain_l
	  section.data(65).logicalSrcIdx = 88;
	  section.data(65).dtTransOffset = 153;
	
	  ;% proc_control_node_B.Gain1_o
	  section.data(66).logicalSrcIdx = 89;
	  section.data(66).dtTransOffset = 154;
	
	  ;% proc_control_node_B.Gain2_i
	  section.data(67).logicalSrcIdx = 90;
	  section.data(67).dtTransOffset = 155;
	
	  ;% proc_control_node_B.Sum_pr
	  section.data(68).logicalSrcIdx = 91;
	  section.data(68).dtTransOffset = 156;
	
	  ;% proc_control_node_B.PressureDepth
	  section.data(69).logicalSrcIdx = 92;
	  section.data(69).dtTransOffset = 157;
	
	  ;% proc_control_node_B.Quaternion_k
	  section.data(70).logicalSrcIdx = 93;
	  section.data(70).dtTransOffset = 158;
	
	  ;% proc_control_node_B.AngularRate_d
	  section.data(71).logicalSrcIdx = 94;
	  section.data(71).dtTransOffset = 162;
	
	  ;% proc_control_node_B.y_g
	  section.data(72).logicalSrcIdx = 95;
	  section.data(72).dtTransOffset = 165;
	
	  ;% proc_control_node_B.Position_dot
	  section.data(73).logicalSrcIdx = 96;
	  section.data(73).dtTransOffset = 169;
	
	  ;% proc_control_node_B.Quaternion_dot
	  section.data(74).logicalSrcIdx = 97;
	  section.data(74).dtTransOffset = 172;
	
	  ;% proc_control_node_B.BodyVelocity_dot
	  section.data(75).logicalSrcIdx = 98;
	  section.data(75).dtTransOffset = 176;
	
	  ;% proc_control_node_B.AngularRates_dot
	  section.data(76).logicalSrcIdx = 99;
	  section.data(76).dtTransOffset = 179;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_i2
	  section.data(1).logicalSrcIdx = 100;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_e
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.In1_om
	  section.data(2).logicalSrcIdx = 102;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.ZeroOrderHold_h
	  section.data(1).logicalSrcIdx = 105;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_B.In1_cx
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% proc_control_node_B.Merge1_f
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_B.ZeroOrderHold2
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
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
    nTotSects     = 18;
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
      
	  ;% proc_control_node_DW.obj_n
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_m
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_j
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_jo
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_i
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
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_mv
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_o
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_mt
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_h
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_b
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_hd
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_c
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_ow
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_d
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_l
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.obj_df
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.obj_bg
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.obj_i4
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.obj_ag
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.obj_e
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.obj_lf
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.obj_mj
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.obj_p
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.obj_lfs
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.obj_ap
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.obj_f
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.obj_ab
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.obj_k
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.obj_kw
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 20;
      section.data(20)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Integrator_DSTATE
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Integrator_DSTATE_l
	  section.data(2).logicalSrcIdx = 32;
	  section.data(2).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.Delay_DSTATE
	  section.data(3).logicalSrcIdx = 33;
	  section.data(3).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.Delay_DSTATE_e
	  section.data(4).logicalSrcIdx = 34;
	  section.data(4).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.Delay_DSTATE_n
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.DiscreteTimeIntegrator_DSTATE
	  section.data(6).logicalSrcIdx = 42;
	  section.data(6).dtTransOffset = 15;
	
	  ;% proc_control_node_DW._DSTATE
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Delay_DSTATE_i
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.last_mv_DSTATE
	  section.data(9).logicalSrcIdx = 52;
	  section.data(9).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.Delay1_DSTATE
	  section.data(10).logicalSrcIdx = 53;
	  section.data(10).dtTransOffset = 33;
	
	  ;% proc_control_node_DW.last_mv_DSTATE_j
	  section.data(11).logicalSrcIdx = 54;
	  section.data(11).dtTransOffset = 41;
	
	  ;% proc_control_node_DW.Delay1_DSTATE_c
	  section.data(12).logicalSrcIdx = 55;
	  section.data(12).dtTransOffset = 49;
	
	  ;% proc_control_node_DW.UD_DSTATE
	  section.data(13).logicalSrcIdx = 56;
	  section.data(13).dtTransOffset = 57;
	
	  ;% proc_control_node_DW.Delay_DSTATE_a
	  section.data(14).logicalSrcIdx = 57;
	  section.data(14).dtTransOffset = 63;
	
	  ;% proc_control_node_DW.P
	  section.data(15).logicalSrcIdx = 61;
	  section.data(15).dtTransOffset = 71;
	
	  ;% proc_control_node_DW.x
	  section.data(16).logicalSrcIdx = 62;
	  section.data(16).dtTransOffset = 240;
	
	  ;% proc_control_node_DW.XDrift_NextOutput
	  section.data(17).logicalSrcIdx = 65;
	  section.data(17).dtTransOffset = 253;
	
	  ;% proc_control_node_DW.YDrift_NextOutput
	  section.data(18).logicalSrcIdx = 66;
	  section.data(18).dtTransOffset = 254;
	
	  ;% proc_control_node_DW.NextOutput
	  section.data(19).logicalSrcIdx = 67;
	  section.data(19).dtTransOffset = 255;
	
	  ;% proc_control_node_DW.NextOutput_b
	  section.data(20).logicalSrcIdx = 68;
	  section.data(20).dtTransOffset = 256;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 24;
      section.data(24)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Scope_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 69;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Scope1_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 70;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Scope_PWORK_c.LoggedData
	  section.data(3).logicalSrcIdx = 71;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Scope1_PWORK_p.LoggedData
	  section.data(4).logicalSrcIdx = 72;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.Scope2_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 73;
	  section.data(5).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.Scope3_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 74;
	  section.data(6).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.Scope_PWORK_cp.LoggedData
	  section.data(7).logicalSrcIdx = 75;
	  section.data(7).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.Scope1_PWORK_n.LoggedData
	  section.data(8).logicalSrcIdx = 76;
	  section.data(8).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.Scope1_PWORK_g.LoggedData
	  section.data(9).logicalSrcIdx = 77;
	  section.data(9).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.Scope_PWORK_e.LoggedData
	  section.data(10).logicalSrcIdx = 78;
	  section.data(10).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.Scope_PWORK_p.LoggedData
	  section.data(11).logicalSrcIdx = 79;
	  section.data(11).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.Scope_PWORK_eo.LoggedData
	  section.data(12).logicalSrcIdx = 80;
	  section.data(12).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.Scope_PWORK_ed.LoggedData
	  section.data(13).logicalSrcIdx = 81;
	  section.data(13).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.Scope1_PWORK_o.LoggedData
	  section.data(14).logicalSrcIdx = 82;
	  section.data(14).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Scope2_PWORK_l.LoggedData
	  section.data(15).logicalSrcIdx = 83;
	  section.data(15).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.Scope3_PWORK_n.LoggedData
	  section.data(16).logicalSrcIdx = 84;
	  section.data(16).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.Scope1_PWORK_k.LoggedData
	  section.data(17).logicalSrcIdx = 85;
	  section.data(17).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.Scope_PWORK_f.LoggedData
	  section.data(18).logicalSrcIdx = 86;
	  section.data(18).dtTransOffset = 20;
	
	  ;% proc_control_node_DW.Scope2_PWORK_lr.LoggedData
	  section.data(19).logicalSrcIdx = 87;
	  section.data(19).dtTransOffset = 21;
	
	  ;% proc_control_node_DW.Scope3_PWORK_c.LoggedData
	  section.data(20).logicalSrcIdx = 88;
	  section.data(20).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.Scope4_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 89;
	  section.data(21).dtTransOffset = 23;
	
	  ;% proc_control_node_DW.Scope_PWORK_l.LoggedData
	  section.data(22).logicalSrcIdx = 90;
	  section.data(22).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.Scope1_PWORK_a.LoggedData
	  section.data(23).logicalSrcIdx = 91;
	  section.data(23).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.Scope_PWORK_cg.LoggedData
	  section.data(24).logicalSrcIdx = 92;
	  section.data(24).dtTransOffset = 26;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.clockTickCounter
	  section.data(1).logicalSrcIdx = 93;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.clockTickCounter_h
	  section.data(2).logicalSrcIdx = 94;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.clockTickCounter_p
	  section.data(3).logicalSrcIdx = 95;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.m_bpIndex
	  section.data(1).logicalSrcIdx = 96;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.RandSeed
	  section.data(2).logicalSrcIdx = 97;
	  section.data(2).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.RandSeed_a
	  section.data(3).logicalSrcIdx = 98;
	  section.data(3).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.m_bpIndex_m
	  section.data(4).logicalSrcIdx = 99;
	  section.data(4).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.m_bpIndex_c
	  section.data(5).logicalSrcIdx = 100;
	  section.data(5).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.RandSeed_j
	  section.data(6).logicalSrcIdx = 101;
	  section.data(6).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.RandSeed_d
	  section.data(7).logicalSrcIdx = 102;
	  section.data(7).dtTransOffset = 27;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Integrator_IWORK
	  section.data(1).logicalSrcIdx = 103;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Integrator1_IWORK
	  section.data(2).logicalSrcIdx = 104;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.Integrator2_IWORK
	  section.data(3).logicalSrcIdx = 105;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.Integrator3_IWORK
	  section.data(4).logicalSrcIdx = 106;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Delay1_DSTATE_cr
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 51;
      section.data(51)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Integrator_PrevResetState
	  section.data(1).logicalSrcIdx = 109;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Integrator_PrevResetState_h
	  section.data(2).logicalSrcIdx = 110;
	  section.data(2).dtTransOffset = 1;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem
	  section.data(3).logicalSrcIdx = 111;
	  section.data(3).dtTransOffset = 2;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC
	  section.data(4).logicalSrcIdx = 112;
	  section.data(4).dtTransOffset = 3;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_d
	  section.data(5).logicalSrcIdx = 113;
	  section.data(5).dtTransOffset = 4;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_dy
	  section.data(6).logicalSrcIdx = 114;
	  section.data(6).dtTransOffset = 5;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_g
	  section.data(7).logicalSrcIdx = 115;
	  section.data(7).dtTransOffset = 6;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC
	  section.data(8).logicalSrcIdx = 116;
	  section.data(8).dtTransOffset = 7;
	
	  ;% proc_control_node_DW.singleWptsTrajectory_SubsysRanB
	  section.data(9).logicalSrcIdx = 117;
	  section.data(9).dtTransOffset = 8;
	
	  ;% proc_control_node_DW.Subsystem1_SubsysRanBC
	  section.data(10).logicalSrcIdx = 118;
	  section.data(10).dtTransOffset = 9;
	
	  ;% proc_control_node_DW.Subsystem_SubsysRanBC
	  section.data(11).logicalSrcIdx = 119;
	  section.data(11).dtTransOffset = 10;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_p
	  section.data(12).logicalSrcIdx = 120;
	  section.data(12).dtTransOffset = 11;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanBC
	  section.data(13).logicalSrcIdx = 121;
	  section.data(13).dtTransOffset = 12;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanBC
	  section.data(14).logicalSrcIdx = 122;
	  section.data(14).dtTransOffset = 13;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_n
	  section.data(15).logicalSrcIdx = 123;
	  section.data(15).dtTransOffset = 14;
	
	  ;% proc_control_node_DW.Subsystem1_SubsysRanBC_p
	  section.data(16).logicalSrcIdx = 124;
	  section.data(16).dtTransOffset = 15;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_o
	  section.data(17).logicalSrcIdx = 125;
	  section.data(17).dtTransOffset = 16;
	
	  ;% proc_control_node_DW.Pretraitement_SubsysRanBC
	  section.data(18).logicalSrcIdx = 126;
	  section.data(18).dtTransOffset = 17;
	
	  ;% proc_control_node_DW.SubsystemAuto_SubsysRanBC
	  section.data(19).logicalSrcIdx = 127;
	  section.data(19).dtTransOffset = 18;
	
	  ;% proc_control_node_DW.SubsystemManual_SubsysRanBC
	  section.data(20).logicalSrcIdx = 128;
	  section.data(20).dtTransOffset = 19;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_n
	  section.data(21).logicalSrcIdx = 129;
	  section.data(21).dtTransOffset = 20;
	
	  ;% proc_control_node_DW.Subsystem_SubsysRanBC_f
	  section.data(22).logicalSrcIdx = 130;
	  section.data(22).dtTransOffset = 21;
	
	  ;% proc_control_node_DW.Correct2_SubsysRanBC
	  section.data(23).logicalSrcIdx = 131;
	  section.data(23).dtTransOffset = 22;
	
	  ;% proc_control_node_DW.Correct1_SubsysRanBC
	  section.data(24).logicalSrcIdx = 132;
	  section.data(24).dtTransOffset = 23;
	
	  ;% proc_control_node_DW.DVLMesurments_SubsysRanBC
	  section.data(25).logicalSrcIdx = 133;
	  section.data(25).dtTransOffset = 24;
	
	  ;% proc_control_node_DW.Subsystem2_SubsysRanBC
	  section.data(26).logicalSrcIdx = 134;
	  section.data(26).dtTransOffset = 25;
	
	  ;% proc_control_node_DW.SwitchCase_ActiveSubsystem_l
	  section.data(27).logicalSrcIdx = 135;
	  section.data(27).dtTransOffset = 26;
	
	  ;% proc_control_node_DW.IDLE_SubsysRanBC
	  section.data(28).logicalSrcIdx = 136;
	  section.data(28).dtTransOffset = 27;
	
	  ;% proc_control_node_DW.AdaptiveMPCquaternion_SubsysRan
	  section.data(29).logicalSrcIdx = 137;
	  section.data(29).dtTransOffset = 28;
	
	  ;% proc_control_node_DW.AdaptiveMPCEuler_SubsysRanBC
	  section.data(30).logicalSrcIdx = 138;
	  section.data(30).dtTransOffset = 29;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_j
	  section.data(31).logicalSrcIdx = 139;
	  section.data(31).dtTransOffset = 30;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_i
	  section.data(32).logicalSrcIdx = 140;
	  section.data(32).dtTransOffset = 31;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_l
	  section.data(33).logicalSrcIdx = 141;
	  section.data(33).dtTransOffset = 32;
	
	  ;% proc_control_node_DW.JoyStickOpenLoop_SubsysRanBC
	  section.data(34).logicalSrcIdx = 142;
	  section.data(34).dtTransOffset = 33;
	
	  ;% proc_control_node_DW.QuaternionNonlinearMPCNotforcod
	  section.data(35).logicalSrcIdx = 143;
	  section.data(35).dtTransOffset = 34;
	
	  ;% proc_control_node_DW.SensorManager_SubsysRanBC
	  section.data(36).logicalSrcIdx = 144;
	  section.data(36).dtTransOffset = 35;
	
	  ;% proc_control_node_DW.IfActionSubsystem2_SubsysRanB_i
	  section.data(37).logicalSrcIdx = 145;
	  section.data(37).dtTransOffset = 36;
	
	  ;% proc_control_node_DW.IfActionSubsystem1_SubsysRanB_a
	  section.data(38).logicalSrcIdx = 146;
	  section.data(38).dtTransOffset = 37;
	
	  ;% proc_control_node_DW.IfActionSubsystem_SubsysRanBC_k
	  section.data(39).logicalSrcIdx = 147;
	  section.data(39).dtTransOffset = 38;
	
	  ;% proc_control_node_DW.ROSOutput_SubsysRanBC
	  section.data(40).logicalSrcIdx = 148;
	  section.data(40).dtTransOffset = 39;
	
	  ;% proc_control_node_DW.RealSystem_SubsysRanBC
	  section.data(41).logicalSrcIdx = 149;
	  section.data(41).dtTransOffset = 40;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_e
	  section.data(42).logicalSrcIdx = 150;
	  section.data(42).dtTransOffset = 41;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_b
	  section.data(43).logicalSrcIdx = 151;
	  section.data(43).dtTransOffset = 42;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_pz
	  section.data(44).logicalSrcIdx = 152;
	  section.data(44).dtTransOffset = 43;
	
	  ;% proc_control_node_DW.Simulation_SubsysRanBC
	  section.data(45).logicalSrcIdx = 153;
	  section.data(45).dtTransOffset = 44;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_du
	  section.data(46).logicalSrcIdx = 154;
	  section.data(46).dtTransOffset = 45;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_i
	  section.data(47).logicalSrcIdx = 155;
	  section.data(47).dtTransOffset = 46;
	
	  ;% proc_control_node_DW.EnabledSubsystem_SubsysRanBC_j
	  section.data(48).logicalSrcIdx = 156;
	  section.data(48).dtTransOffset = 47;
	
	  ;% proc_control_node_DW.Subsystem_SubsysRanBC_g
	  section.data(49).logicalSrcIdx = 157;
	  section.data(49).dtTransOffset = 48;
	
	  ;% proc_control_node_DW.Plotvalues_SubsysRanBC
	  section.data(50).logicalSrcIdx = 158;
	  section.data(50).dtTransOffset = 49;
	
	  ;% proc_control_node_DW.ModlePhysique_SubsysRanBC
	  section.data(51).logicalSrcIdx = 159;
	  section.data(51).dtTransOffset = 50;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% proc_control_node_DW.Memory_PreviousInput
	  section.data(1).logicalSrcIdx = 172;
	  section.data(1).dtTransOffset = 0;
	
	  ;% proc_control_node_DW.Memory_PreviousInput_h
	  section.data(2).logicalSrcIdx = 173;
	  section.data(2).dtTransOffset = 48;
	
	  ;% proc_control_node_DW.Memory_PreviousInput_i
	  section.data(3).logicalSrcIdx = 193;
	  section.data(3).dtTransOffset = 96;
	
	  ;% proc_control_node_DW.Memory_PreviousInput_f
	  section.data(4).logicalSrcIdx = 194;
	  section.data(4).dtTransOffset = 97;
	
	  ;% proc_control_node_DW.SensorManager_MODE
	  section.data(5).logicalSrcIdx = 196;
	  section.data(5).dtTransOffset = 98;
	
	  ;% proc_control_node_DW.ROSOutput_MODE
	  section.data(6).logicalSrcIdx = 197;
	  section.data(6).dtTransOffset = 99;
	
	  ;% proc_control_node_DW.Plotvalues_MODE
	  section.data(7).logicalSrcIdx = 198;
	  section.data(7).dtTransOffset = 100;
	
	  ;% proc_control_node_DW.ModlePhysique_MODE
	  section.data(8).logicalSrcIdx = 199;
	  section.data(8).dtTransOffset = 101;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
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


  targMap.checksum0 = 2470786312;
  targMap.checksum1 = 896412645;
  targMap.checksum2 = 3352249419;
  targMap.checksum3 = 2524740981;

