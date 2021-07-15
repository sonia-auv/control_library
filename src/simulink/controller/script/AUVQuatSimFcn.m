function out1 = AUVQuatSimFcn(in1,in2)
%AUVQUATSIMFCN
%    OUT1 = AUVQUATSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    10-Jul-2021 18:28:17

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
t26 = p.*(3.1e+1./5.0e+2);
t27 = p./1.0e+3;
t28 = q./1.0e+3;
t29 = r.*(9.0./5.0e+2);
t30 = r.*(3.1e+1./5.0e+2);
t31 = r./1.0e+3;
t32 = p.*(7.4e+1./1.25e+2);
t33 = p.*(2.79e+2./5.0e+2);
t34 = q.*(2.79e+2./5.0e+2);
t36 = q.*(3.1e+1./1.0e+3);
t38 = r.*(3.1e+1./1.0e+3);
t39 = q.*1.7228;
t40 = r.*1.8864;
t41 = u.*3.24648e+1;
t44 = v.*4.36156e+1;
t45 = w.*4.67695e+1;
t17 = t8.*2.0;
t18 = t9.*2.0;
t19 = t10.*2.0;
t35 = -t28;
t37 = -t31;
t42 = t3.*1.45708e+1;
t43 = -t41;
t46 = t5.*7.00596e+1;
t47 = t6.*9.00196e+1;
t48 = -t44;
t49 = -t45;
t50 = t4.*1.119756e+1;
t52 = t24+t29;
t53 = t7.*1.10155248e+2;
t54 = t24+t27;
t55 = t27+t29;
t56 = t2.*2.4333236e+1;
t62 = t34+t41;
t64 = t26+t45;
t65 = t38+t44;
t68 = t23+t25+t32;
t51 = t42+7.0;
t57 = t46+4.5e+1;
t58 = t47+6.0e+1;
t59 = t50+1.5e+1;
t60 = t56+1.0e+1;
t61 = t53+7.0e+1;
t63 = t30+t43;
t66 = t33+t48;
t67 = t36+t49;
t69 = t22+t35+t40;
t70 = t21+t37+t39;
out1 = [-u.*(t18+t19-1.0)+w.*(t12+t15)+v.*(t11-t16);u.*(t11+t16)-v.*(t17+t19-1.0)+w.*(t13-t14);v.*(t13+t14)-w.*(t17+t18-1.0)+u.*(t12-t15);epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0;(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0;(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0;epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0;U1.*(-3.307683405402052e-4)+U2.*1.859578044455023e-21+U3.*3.350640332744937e-4+U4.*3.336321356963975e-4-U5.*1.819638864719295e-3-U6.*1.812421155037148e-3+U7.*1.853873173346878e-3+U8.*1.778186846409557e-3-t8.*6.319529682423614e-3-t9.*6.319529682423614e-3+U1.*t20.*1.517111971060688e-2+U2.*t20.*1.492882415550761e-2+U3.*t20.*1.517111971060688e-2+U4.*t20.*1.516372519659284e-2-epsilon1.*epsilon3.*4.138016519122657e-1-epsilon2.*epsilon3.*1.3017970932508e-3-epsilon1.*eta.*1.3017970932508e-3+epsilon2.*eta.*4.138016519122657e-1-p.*t52.*9.602862890270499e-1-p.*t60.*1.303522588356414e-4+p.*t64.*9.480305514485772e-7-p.*t66.*6.823134824417595e-6-p.*t69.*1.003331497170287e-2-p.*t70.*1.012504487436365e-3+q.*t51.*1.003331497170287e-2-q.*t55.*2.938894709490589e-5-q.*t62.*6.823134824417595e-6+q.*t67.*3.097697706538871e-2+q.*t68.*1.012504487436365e-3-q.*t69.*1.303522588356414e-4+r.*t54.*2.115171795569455e-4-r.*t59.*1.012504487436365e-3+r.*t63.*9.480305514485772e-7+r.*t65.*3.097697706538871e-2+r.*t68.*1.003331497170287e-2+r.*t70.*1.303522588356414e-4+t52.*u.*4.040920023904883e-3-t57.*u.*3.097697706538871e-2-t65.*u.*1.012504487436365e-3+t67.*u.*1.003331497170287e-2-t55.*v.*3.11032764122789e-1-t58.*v.*9.480305514485772e-7-t63.*v.*1.012504487436365e-3-t64.*v.*1.303522588356414e-4+t54.*w.*3.138763911052732e-2+t61.*w.*6.823134824417595e-6+t62.*w.*1.003331497170287e-2-t66.*w.*1.303522588356414e-4+3.159764841211807e-3;U1.*1.397575406352208e-4+U2.*7.924461028811397e-21-U3.*1.415725736304834e-4-U4.*1.409675626320625e-4-U5.*3.424925181634632e-3+U6.*3.387750973601051e-3+U7.*3.570812279719344e-3-U8.*3.533638071685763e-3-t8.*2.693023120923067e-2-t9.*2.693023120923067e-2-U1.*t20.*1.090649593858282e-2+U2.*t20.*1.100012304554462e-2-U3.*t20.*1.090649593858282e-2+U4.*t20.*1.090087173345982e-2-epsilon1.*epsilon3.*9.920210995693149e-4-epsilon2.*epsilon3.*5.197901606989806e-1-epsilon1.*eta.*5.197901606989806e-1+epsilon2.*eta.*9.920210995693149e-4-p.*t52.*2.938894709490589e-5-p.*t60.*2.188227438151068e-2+p.*t64.*2.320783323245932e-2-p.*t66.*2.907630909692153e-5-p.*t69.*1.026911824132076e-4+p.*t70.*4.278073796758403e-4+q.*t51.*1.026911824132076e-4-q.*t55.*7.194428302062391e-1-q.*t62.*2.907630909692153e-5+q.*t67.*9.480305514485772e-7-q.*t68.*4.278073796758403e-4-q.*t69.*2.188227438151068e-2+r.*t54.*9.013655820045674e-4+r.*t59.*4.278073796758403e-4+r.*t63.*2.320783323245932e-2+r.*t65.*9.480305514485772e-7+r.*t68.*1.026911824132076e-4+r.*t70.*2.188227438151068e-2+t52.*u.*6.78350505826831e-1-t57.*u.*9.480305514485772e-7+t65.*u.*4.278073796758403e-4+t67.*u.*1.026911824132076e-4-t55.*v.*3.183426654809437e-3-t58.*v.*2.320783323245932e-2+t63.*v.*4.278073796758403e-4-t64.*v.*2.188227438151068e-2-t54.*w.*1.326202876995105e-2+t61.*w.*2.907630909692153e-5+t62.*w.*1.026911824132076e-4-t66.*w.*2.188227438151068e-2+1.346511560461533e-2;U1.*(-1.725827915740819e-6)-U2.*5.828197568247432e-18+U3.*1.748241265284163e-6+U4.*1.740770148765829e-6-U5.*2.095639900015615e-2+U6.*2.110031621698574e-2-U7.*2.182294950286063e-2+U8.*2.167903228603104e-2+t8.*1.863574892135219e-1+t9.*1.863574892135219e-1-U1.*t20.*4.886926387591695e-5+U2.*t20.*6.626442938924465e-5-U3.*t20.*4.886926387591695e-5+U4.*t20.*6.749005688877506e-5+epsilon1.*epsilon3.*5.875841520580333e-3+epsilon2.*epsilon3.*3.354073588822474e-2+epsilon1.*eta.*3.354073588822474e-2-epsilon2.*eta.*5.875841520580333e-3+p.*t52.*2.115171795569455e-4+p.*t60.*2.272431716587712e-3-p.*t64.*2.907630909692153e-5+p.*t66.*2.138473182670276e-2+p.*t69.*3.975613724574329e-4-p.*t70.*5.282877153148301e-6-q.*t51.*3.975613724574329e-4+q.*t55.*9.013655820045674e-4+q.*t62.*2.138473182670276e-2-q.*t67.*6.823134824417595e-6+q.*t68.*5.282877153148301e-6+q.*t69.*2.272431716587712e-3-r.*t54.*6.629266866277855e-1-r.*t59.*5.282877153148301e-6-r.*t63.*2.907630909692153e-5-r.*t65.*6.823134824417595e-6-r.*t68.*3.975613724574329e-4-r.*t70.*2.272431716587712e-3-t52.*u.*7.044538321421906e-2+t57.*u.*6.823134824417595e-6-t65.*u.*5.282877153148301e-6-t67.*u.*3.975613724574329e-4+t55.*v.*1.232440254618042e-2+t58.*v.*2.907630909692153e-5-t63.*v.*5.282877153148301e-6+t64.*v.*2.272431716587712e-3+t54.*w.*1.637691917475973e-4-t61.*w.*2.138473182670276e-2-t62.*w.*3.975613724574329e-4+t66.*w.*2.272431716587712e-3-9.317874460676093e-2;U1.*1.302135095166983e-3+U2.*6.193288329240141e-19-U3.*1.31904594055876e-3-U4.*1.313408992094834e-3-U5.*2.676719354658257e-1+U6.*2.647662125022089e-1+U7.*2.790736050389333e-1-U8.*2.761678820753165e-1-t8.*2.104707008406899-t9.*2.104707008406899+U1.*t20.*4.359319882537525e-2-U2.*t20.*4.305183106323503e-2+U3.*t20.*4.359319882537525e-2-U4.*t20.*4.397656554353263e-2-epsilon1.*epsilon3.*1.138522338822895e-1-epsilon2.*epsilon3.*2.524211455612299e+1-epsilon1.*eta.*2.524211455612299e+1+epsilon2.*eta.*1.138522338822895e-1-p.*t52.*4.040920023904883e-3-p.*t60.*1.71018810547529+p.*t64.*2.188227438151068e-2-p.*t66.*2.272431716587712e-3-p.*t69.*8.026859015515944e-3+p.*t70.*3.9859244840414e-3+q.*t51.*8.026859015515944e-3-q.*t55.*6.78350505826831e-1-q.*t62.*2.272431716587712e-3+q.*t67.*1.303522588356414e-4-q.*t68.*3.9859244840414e-3-q.*t69.*1.71018810547529+r.*t54.*7.044538321421906e-2+r.*t59.*3.9859244840414e-3+r.*t63.*2.188227438151068e-2+r.*t65.*1.303522588356414e-4+r.*t68.*8.026859015515944e-3+r.*t70.*1.71018810547529+t52.*u.*5.301583126973399e+1-t57.*u.*1.303522588356414e-4+t65.*u.*3.9859244840414e-3+t67.*u.*8.026859015515944e-3-t55.*v.*2.488326294809943e-1-t58.*v.*2.188227438151068e-2+t63.*v.*3.9859244840414e-3-t64.*v.*1.71018810547529-t54.*w.*1.235636590052834e-1+t61.*w.*2.272431716587712e-3+t62.*w.*8.026859015515944e-3-t66.*w.*1.71018810547529+1.052353504203449;U1.*5.247482382331681e-7-U2.*1.083514276897426e-19-U3.*5.315631504182326e-7-U4.*5.292915130232833e-7+U5.*1.059366762359936e-1+U6.*1.053788543694033e-1-U7.*1.079313955363373e-1-U8.*1.033841350690595e-1+t8.*3.682179758252496e-1+t9.*3.682179758252496e-1+U1.*t20.*1.345765452672799e-2+U2.*t20.*1.386905498063568e-2+U3.*t20.*1.345765452672799e-2+U4.*t20.*1.386868232130781e-2+epsilon1.*epsilon3.*8.637139725679998+epsilon2.*epsilon3.*1.184627304742461e-1+epsilon1.*eta.*1.184627304742461e-1-epsilon2.*eta.*8.637139725679998+p.*t52.*3.11032764122789e-1+p.*t60.*8.026859015515944e-3-p.*t64.*1.026911824132076e-4+p.*t66.*3.975613724574329e-4+p.*t69.*5.837445596834167e-1+p.*t70.*1.606290206365557e-6-q.*t51.*5.837445596834167e-1+q.*t55.*3.183426654809437e-3+q.*t62.*3.975613724574329e-4-q.*t67.*1.003331497170287e-2-q.*t68.*1.606290206365557e-6+q.*t69.*8.026859015515944e-3-r.*t54.*1.232440254618042e-2+r.*t59.*1.606290206365557e-6-r.*t63.*1.026911824132076e-4-r.*t65.*1.003331497170287e-2-r.*t68.*5.837445596834167e-1-r.*t70.*8.026859015515944e-3-t52.*u.*2.488326294809943e-1+t57.*u.*1.003331497170287e-2+t65.*u.*1.606290206365557e-6-t67.*u.*5.837445596834167e-1+t55.*v.*1.809608135018592e+1+t58.*v.*1.026911824132076e-4+t63.*v.*1.606290206365557e-6+t64.*v.*8.026859015515944e-3-t54.*w.*4.979499639733228e-5-t61.*w.*3.975613724574329e-4-t62.*w.*5.837445596834167e-1+t66.*w.*8.026859015515944e-3-1.841089879126248e-1;U1.*(-1.731941163298826e-1)-U2.*1.439796020209256e-21+U3.*1.75443390567933e-1+U4.*1.746936324885829e-1+U5.*6.202181346042057e-4-U6.*6.207996116589e-4-U7.*6.467243742662552e-4+U8.*6.473058513209489e-4+t8.*4.892956073276469e-3+t9.*4.892956073276469e-3+U1.*t20.*5.925549487801743e-4-U2.*t20.*1.225770464045467e-1+U3.*t20.*5.925549487801743e-4+U4.*t20.*4.198467360829836e-4-epsilon1.*epsilon3.*6.536113237400682e-1+epsilon2.*epsilon3.*3.845100214783996e-1+epsilon1.*eta.*3.845100214783996e-1+epsilon2.*eta.*6.536113237400682e-1-p.*t52.*3.138763911052732e-2+p.*t60.*3.9859244840414e-3-p.*t64.*4.278073796758403e-4+p.*t66.*5.282877153148301e-6-p.*t69.*1.606290206365557e-6-p.*t70.*5.301590221578864e-1+q.*t51.*1.606290206365557e-6+q.*t55.*1.326202876995105e-2+q.*t62.*5.282877153148301e-6+q.*t67.*1.012504487436365e-3+q.*t68.*5.301590221578864e-1+q.*t69.*3.9859244840414e-3-r.*t54.*1.637691917475973e-4-r.*t59.*5.301590221578864e-1-r.*t63.*4.278073796758403e-4+r.*t65.*1.012504487436365e-3+r.*t68.*1.606290206365557e-6-r.*t70.*3.9859244840414e-3-t52.*u.*1.235636590052834e-1-t57.*u.*1.012504487436365e-3-t65.*u.*5.301590221578864e-1+t67.*u.*1.606290206365557e-6-t55.*v.*4.979499639733228e-5+t58.*v.*4.278073796758403e-4-t63.*v.*5.301590221578864e-1+t64.*v.*3.9859244840414e-3+t54.*w.*1.643492968689448e+1-t61.*w.*5.282877153148301e-6+t62.*w.*1.606290206365557e-6+t66.*w.*3.9859244840414e-3-2.446478036638235e-3];
