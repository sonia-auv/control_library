function T__H_N = pinger2hydroAngles(in1,in2,in3,in4)
%pinger2hydroAngles
%    T__H_N = pinger2hydroAngles(IN1,IN2,IN3,IN4)

%    This function was generated by the Symbolic Math Toolbox version 9.0.
%    22-Feb-2022 23:39:14

d_x = in3(1,:);
d_y = in3(2,:);
d_z = in3(3,:);
epsilon1 = in2(:,2);
epsilon2 = in2(:,3);
epsilon3 = in2(:,4);
eta = in2(:,1);
pp_x = in4(1,:);
pp_y = in4(2,:);
pp_z = in4(3,:);
ps_x = in1(1,:);
ps_y = in1(2,:);
ps_z = in1(3,:);
t2 = epsilon1.^2;
t3 = epsilon2.^2;
t4 = epsilon3.^2;
t5 = epsilon1.*epsilon2.*2.0;
t6 = epsilon1.*epsilon3.*2.0;
t7 = epsilon2.*epsilon3.*2.0;
t8 = epsilon1.*eta.*2.0;
t9 = epsilon2.*eta.*2.0;
t10 = epsilon3.*eta.*2.0;
t11 = t2.*2.0;
t12 = t3.*2.0;
t13 = t4.*2.0;
t14 = -t8;
t15 = -t9;
t16 = -t10;
t17 = t5+t10;
t18 = t6+t9;
t19 = t7+t8;
t20 = t5+t16;
t21 = t6+t15;
t22 = t7+t14;
t23 = d_x.*t17;
t24 = d_y.*t19;
t25 = d_z.*t18;
t26 = pp_x.*t18;
t27 = pp_y.*t17;
t28 = pp_z.*t19;
t35 = t11+t12-1.0;
t36 = t11+t13-1.0;
t37 = t12+t13-1.0;
t29 = d_x.*t21;
t30 = d_y.*t20;
t31 = d_z.*t22;
t32 = pp_x.*t20;
t33 = pp_y.*t22;
t34 = pp_z.*t21;
t38 = d_x.*t37;
t39 = d_y.*t36;
t40 = d_z.*t35;
t41 = pp_x.*t37;
t42 = pp_y.*t36;
t43 = pp_z.*t35;
t44 = -t38;
t45 = -t39;
t46 = -t40;
t47 = -t41;
t48 = -t42;
t49 = -t43;
t50 = ps_x+t25+t30+t44;
t51 = ps_y+t23+t31+t45;
t52 = ps_z+t24+t29+t46;
t53 = t17.*t51;
t54 = t18.*t50;
t55 = t19.*t52;
t56 = t20.*t50;
t57 = t21.*t52;
t58 = t22.*t51;
t65 = t35.*t52;
t66 = t36.*t51;
t67 = t37.*t50;
t59 = -t53;
t60 = -t54;
t61 = -t55;
t62 = -t56;
t63 = -t57;
t64 = -t58;
t68 = t26+t33+t49+t60+t64+t65;
t69 = t28+t32+t48+t61+t62+t66;
t70 = t27+t34+t47+t59+t63+t67;
t71 = abs(t68);
t72 = abs(t69);
t73 = abs(t70);
t74 = t71.^2;
t75 = t72.^2;
t76 = t73.^2;
t77 = t74+t75+t76+1.0;
T__H_N = [atan2(t28+t32-t42-t55-t56+t66,t70);acos(t68.*1.0./sqrt(t77));sqrt(t77)];
