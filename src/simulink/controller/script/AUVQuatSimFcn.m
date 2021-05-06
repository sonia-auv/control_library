function out1 = AUVQuatSimFcn(in1,in2)
%AUVQUATSIMFCN
%    OUT1 = AUVQUATSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    05-May-2021 19:59:21

U1 = in2(1,:);
U2 = in2(2,:);
U3 = in2(3,:);
U4 = in2(4,:);
U5 = in2(5,:);
U6 = in2(6,:);
U7 = in2(7,:);
U8 = in2(8,:);
epsilon1 = in1(5,:);
epsilon2 = in1(6,:);
epsilon3 = in1(7,:);
eta = in1(4,:);
p = in1(11,:);
q = in1(12,:);
r = in1(13,:);
u = in1(8,:);
v = in1(9,:);
w = in1(10,:);
t2 = abs(p);
t3 = abs(q);
t4 = abs(r);
t5 = abs(u);
t6 = abs(v);
t7 = abs(w);
t8 = epsilon1.^2;
t9 = epsilon2.^2;
t10 = epsilon3.^2;
t11 = epsilon1.*epsilon2.*2.0;
t12 = epsilon1.*epsilon3.*2.0;
t13 = epsilon2.*epsilon3.*2.0;
t14 = epsilon1.*eta.*2.0;
t15 = epsilon2.*eta.*2.0;
t16 = epsilon3.*eta.*2.0;
t20 = sqrt(2.0);
t21 = p./1.25e+2;
t22 = p./2.5e+2;
t23 = q./1.25e+2;
t24 = q./5.0e+2;
t25 = r./2.5e+2;
t26 = p./1.0e+3;
t27 = q./1.0e+3;
t28 = r.*(9.0./5.0e+2);
t29 = r./1.0e+3;
t30 = p.*(7.4e+1./1.25e+2);
t33 = q.*1.7228;
t34 = r.*1.8864;
t35 = p.*6.79e-2;
t36 = p.*6.111e-1;
t37 = q.*6.111e-1;
t38 = q.*3.395e-2;
t39 = r.*6.79e-2;
t40 = r.*3.395e-2;
t41 = v.*4.65656e+1;
t43 = u.*3.54148e+1;
t45 = w.*4.97195e+1;
t17 = t8.*2.0;
t18 = t9.*2.0;
t19 = t10.*2.0;
t31 = -t27;
t32 = -t29;
t42 = t3.*1.45708e+1;
t44 = -t41;
t46 = t5.*7.00596e+1;
t47 = t6.*9.00196e+1;
t48 = -t43;
t49 = -t45;
t50 = t4.*1.119756e+1;
t52 = t24+t28;
t53 = t7.*1.10155248e+2;
t54 = t24+t26;
t55 = t26+t28;
t56 = t2.*2.4333236e+1;
t62 = t23+t25+t30;
t63 = t40+t41;
t65 = t37+t43;
t66 = t35+t45;
t51 = t42+7.0;
t57 = t46+4.5e+1;
t58 = t47+6.0e+1;
t59 = t50+1.5e+1;
t60 = t56+1.0e+1;
t61 = t53+7.0e+1;
t64 = t36+t44;
t67 = t39+t48;
t68 = t38+t49;
t69 = t22+t31+t34;
t70 = t21+t32+t33;
out1 = [-u.*(t18+t19-1.0)+w.*(t12+t15)+v.*(t11-t16);u.*(t11+t16)-v.*(t17+t19-1.0)+w.*(t13-t14);v.*(t13+t14)-w.*(t17+t18-1.0)+u.*(t12-t15);epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0;(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0;(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0;epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0;U1.*(-3.322565616540353e-4)+U2.*1.924407910076907e-21+U3.*3.365715819352566e-4+U4.*3.351332418415161e-4-U5.*1.827658480130064e-3-U6.*1.820757985983108e-3+U7.*1.862462071995808e-3+U8.*1.785954394117357e-3-t8.*7.30027481299789e-3-t9.*7.30027481299789e-3+U1.*t20.*1.388751583658544e-2+U2.*t20.*1.36441441865844e-2+U3.*t20.*1.388751583658544e-2+U4.*t20.*1.388010211445763e-2-epsilon1.*epsilon3.*2.511358325325105-epsilon2.*epsilon3.*1.045342560949904e-2-epsilon1.*eta.*1.045342560949904e-2+epsilon2.*eta.*2.511358325325105-p.*t52.*9.646091910334113e-1-p.*t60.*1.311449245682505e-4-p.*t64.*7.061007558560694e-6+p.*t66.*9.795530445547602e-7-p.*t69.*1.00784985251745e-2-p.*t70.*1.01706003393634e-3+q.*t51.*1.00784985251745e-2-q.*t55.*3.325582586263411e-5+q.*t62.*1.01706003393634e-3-q.*t65.*7.061007558560694e-6+q.*t68.*2.841264185665424e-2-q.*t69.*1.311449245682505e-4+r.*t54.*2.397212066131356e-4-r.*t59.*1.01706003393634e-3+r.*t62.*1.00784985251745e-2+r.*t63.*2.841264185665424e-2+r.*t67.*9.795530445547602e-7+r.*t70.*1.311449245682505e-4+t52.*u.*4.452370189092105e-3-t57.*u.*2.841264185665424e-2-t63.*u.*1.01706003393634e-3+t68.*u.*1.00784985251745e-2-t55.*v.*3.421650249296742e-1-t58.*v.*9.795530445547602e-7-t66.*v.*1.311449245682505e-4-t67.*v.*1.01706003393634e-3+t54.*w.*3.452918815213876e-2+t61.*w.*7.061007558560694e-6-t64.*w.*1.311449245682505e-4+t65.*w.*1.00784985251745e-2+3.650137406498945e-3;U1.*1.435764907550211e-4+U2.*8.386928478359308e-21-U3.*1.454411205050863e-4-U4.*1.448195772550645e-4-U5.*3.517711354130674e-3+U6.*3.479483922034707e-3+U7.*3.669391896618328e-3-U8.*3.631164464522361e-3-t8.*3.181595877276055e-2-t9.*3.181595877276055e-2-U1.*t20.*1.016871821092269e-2+U2.*t20.*1.026490273061244e-2-U3.*t20.*1.016871821092269e-2+U4.*t20.*1.01629393229337e-2-epsilon1.*epsilon3.*8.38846728463838e-3-epsilon2.*epsilon3.*3.169690916335036-epsilon1.*eta.*3.169690916335036+epsilon2.*eta.*8.38846728463838e-3-p.*t52.*3.325582586263411e-5-p.*t60.*2.248074156809131e-2-p.*t64.*3.077318746649526e-5+p.*t66.*2.177042499421424e-2-p.*t69.*1.056006411490808e-4+p.*t70.*4.394974468910954e-4+q.*t51.*1.056006411490808e-4-q.*t55.*7.391059285535734e-1-q.*t62.*4.394974468910954e-4-q.*t65.*3.077318746649526e-5+q.*t68.*9.795530445547602e-7-q.*t69.*2.248074156809131e-2+r.*t54.*1.044749714487514e-3+r.*t59.*4.394974468910954e-4+r.*t62.*1.056006411490808e-4+r.*t63.*9.795530445547602e-7+r.*t67.*2.177042499421424e-2+r.*t70.*2.248074156809131e-2+t52.*u.*7.632211762366998e-1-t57.*u.*9.795530445547602e-7+t63.*u.*4.394974468910954e-4+t68.*u.*1.056006411490808e-4-t55.*v.*3.585141767011295e-3-t58.*v.*2.177042499421424e-2-t66.*v.*2.248074156809131e-2+t67.*v.*4.394974468910954e-4-t54.*w.*1.492093832195269e-2+t61.*w.*3.077318746649526e-5-t64.*w.*2.248074156809131e-2+t65.*w.*1.056006411490808e-4+1.590797938638028e-2;U1.*(-1.79300452890001e-6)-U2.*5.482503016575469e-18+U3.*1.816290301991572e-6+U4.*1.808528377624063e-6-U5.*1.967444604318457e-2+U6.*1.982279841788232e-2-U7.*2.056838150065161e-2+U8.*2.042002912595386e-2+t8.*1.177970365072619+t9.*1.177970365072619-U1.*t20.*5.005711642807568e-5+U2.*t20.*6.795081884453763e-5-U3.*t20.*5.005711642807568e-5+U4.*t20.*6.922415301497247e-5+epsilon1.*epsilon3.*3.500902378353971e-2+epsilon2.*epsilon3.*1.997752778025354e-1+epsilon1.*eta.*1.997752778025354e-1-epsilon2.*eta.*3.500902378353971e-2+p.*t52.*2.397212066131356e-4+p.*t60.*2.344600889211616e-3+p.*t64.*2.011631475694989e-2-p.*t66.*3.077318746649526e-5+p.*t69.*4.098131897727732e-4-p.*t70.*5.488509355322561e-6-q.*t51.*4.098131897727732e-4+q.*t55.*1.044749714487514e-3+q.*t62.*5.488509355322561e-6+q.*t65.*2.011631475694989e-2-q.*t68.*7.061007558560694e-6+q.*t69.*2.344600889211616e-3-r.*t54.*6.829488859984489e-1-r.*t59.*5.488509355322561e-6-r.*t62.*4.098131897727732e-4-r.*t63.*7.061007558560694e-6-r.*t67.*3.077318746649526e-5-r.*t70.*2.344600889211616e-3-t52.*u.*7.959920018873436e-2+t57.*u.*7.061007558560694e-6-t63.*u.*5.488509355322561e-6-t68.*u.*4.098131897727732e-4+t55.*v.*1.391315779278565e-2+t58.*v.*3.077318746649526e-5+t66.*v.*2.344600889211616e-3-t67.*v.*5.488509355322561e-6+t54.*w.*1.863348926132009e-4-t61.*w.*2.011631475694989e-2+t64.*w.*2.344600889211616e-3-t65.*w.*4.098131897727732e-4-5.889851825363093e-1;U1.*1.318503530423044e-3+U2.*6.389978285325469e-19-U3.*1.33562695289607e-3-U4.*1.329919145405061e-3-U5.*2.680137823703811e-1+U6.*2.651001783834337e-1+U7.*2.795702821700801e-1-U8.*2.766566781831328e-1-t8.*2.424049355009183-t9.*2.424049355009183+U1.*t20.*4.337725161813152e-2-U2.*t20.*4.282486018388474e-2+U3.*t20.*4.337725161813152e-2-U4.*t20.*4.376121900064788e-2-epsilon1.*epsilon3.*6.818956302528262e-1-epsilon2.*epsilon3.*1.459417589942288e+2-epsilon1.*eta.*1.459417589942288e+2+epsilon2.*eta.*6.818956302528262e-1-p.*t52.*4.452370189092105e-3-p.*t60.*1.712800190419855-p.*t64.*2.344600889211616e-3+p.*t66.*2.248074156809131e-2-p.*t69.*8.048629798197023e-3+p.*t70.*4.036029382599731e-3+q.*t51.*8.048629798197023e-3-q.*t55.*7.632211762366998e-1-q.*t62.*4.036029382599731e-3-q.*t65.*2.344600889211616e-3+q.*t68.*1.311449245682505e-4-q.*t69.*1.712800190419855+r.*t54.*7.959920018873436e-2+r.*t59.*4.036029382599731e-3+r.*t62.*8.048629798197023e-3+r.*t63.*1.311449245682505e-4+r.*t67.*2.248074156809131e-2+r.*t70.*1.712800190419855+t52.*u.*5.814956646475407e+1-t57.*u.*1.311449245682505e-4+t63.*u.*4.036029382599731e-3+t68.*u.*8.048629798197023e-3-t55.*v.*2.732509816487889e-1-t58.*v.*2.248074156809131e-2-t66.*v.*1.712800190419855+t67.*v.*4.036029382599731e-3-t54.*w.*1.370231975392609e-1+t61.*w.*2.344600889211616e-3-t64.*w.*1.712800190419855+t65.*w.*8.048629798197023e-3+1.212024677504591;U1.*1.116645188080143e-5-U2.*1.116905395599563e-19-U3.*1.131147073639648e-5-U4.*1.126313111786487e-5+U5.*1.059865723986993e-1+U6.*1.054470706961683e-1-U7.*1.080065349719949e-1-U8.*1.034271081228726e-1+t8.*4.237000006755883e-1+t9.*4.237000006755883e-1+U1.*t20.*1.344626169736146e-2+U2.*t20.*1.386370341841576e-2+U3.*t20.*1.344626169736146e-2+U4.*t20.*1.385577336329698e-2+epsilon1.*epsilon3.*4.990664049223964e+1+epsilon2.*epsilon3.*6.857581441832506e-1+epsilon1.*eta.*6.857581441832506e-1-epsilon2.*eta.*4.990664049223964e+1+p.*t52.*3.421650249296742e-1+p.*t60.*8.048629798197023e-3+p.*t64.*4.098131897727732e-4-p.*t66.*1.056006411490808e-4+p.*t69.*5.840708372786397e-1+p.*t70.*3.418127206367122e-5-q.*t51.*5.840708372786397e-1+q.*t55.*3.585141767011295e-3-q.*t62.*3.418127206367122e-5+q.*t65.*4.098131897727732e-4-q.*t68.*1.00784985251745e-2+q.*t69.*8.048629798197023e-3-r.*t54.*1.391315779278565e-2+r.*t59.*3.418127206367122e-5-r.*t62.*5.840708372786397e-1-r.*t63.*1.00784985251745e-2-r.*t67.*1.056006411490808e-4-r.*t70.*8.048629798197023e-3-t52.*u.*2.732509816487889e-1+t57.*u.*1.00784985251745e-2+t63.*u.*3.418127206367122e-5-t68.*u.*5.840708372786397e-1+t55.*v.*1.982920492560982e+1+t58.*v.*1.056006411490808e-4+t66.*v.*8.048629798197023e-3+t67.*v.*3.418127206367122e-5-t54.*w.*1.160454186561638e-3-t61.*w.*4.098131897727732e-4+t64.*w.*8.048629798197023e-3-t65.*w.*5.840708372786397e-1-2.118500003377942e-1;U1.*(-1.731955207793958e-1)-U2.*1.495839047092992e-21+U3.*1.754448132570503e-1+U4.*1.746950490978321e-1+U5.*6.220154747413743e-4-U6.*6.343890952284132e-4-U7.*6.49068248438291e-4+U8.*6.614418689253294e-4+t8.*5.674491391669308e-3+t9.*5.674491391669308e-3+U1.*t20.*5.98031999464489e-4-U2.*t20.*1.225810501024604e-1+U3.*t20.*5.98031999464489e-4+U4.*t20.*4.168404330597764e-4-epsilon1.*epsilon3.*7.685539751972064e-1+epsilon2.*epsilon3.*7.195997737127799e-1+epsilon1.*eta.*7.195997737127799e-1+epsilon2.*eta.*7.685539751972064e-1-p.*t52.*3.452918815213876e-2+p.*t60.*4.036029382599731e-3+p.*t64.*5.488509355322561e-6-p.*t66.*4.394974468910954e-4-p.*t69.*3.418127206367122e-5-p.*t70.*5.301633212737938e-1+q.*t51.*3.418127206367122e-5+q.*t55.*1.492093832195269e-2+q.*t62.*5.301633212737938e-1+q.*t65.*5.488509355322561e-6+q.*t68.*1.01706003393634e-3+q.*t69.*4.036029382599731e-3-r.*t54.*1.863348926132009e-4-r.*t59.*5.301633212737938e-1+r.*t62.*3.418127206367122e-5+r.*t63.*1.01706003393634e-3-r.*t67.*4.394974468910954e-4-r.*t70.*4.036029382599731e-3-t52.*u.*1.370231975392609e-1-t57.*u.*1.01706003393634e-3-t63.*u.*5.301633212737938e-1+t68.*u.*3.418127206367122e-5-t55.*v.*1.160454186561638e-3+t58.*v.*4.394974468910954e-4+t66.*v.*4.036029382599731e-3-t67.*v.*5.301633212737938e-1+t54.*w.*1.79990447572453e+1-t61.*w.*5.488509355322561e-6+t64.*w.*4.036029382599731e-3+t65.*w.*3.418127206367122e-5-2.837245695834654e-3];
