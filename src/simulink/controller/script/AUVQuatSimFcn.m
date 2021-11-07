function out1 = AUVQuatSimFcn(in1,in2)
%AUVQUATSIMFCN
%    OUT1 = AUVQUATSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.7.
%    07-Nov-2021 12:08:18

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
t22 = p./1.25e+2;
t23 = p./2.5e+2;
t24 = q./1.25e+2;
t25 = q./5.0e+2;
t26 = r./2.5e+2;
t28 = p.*(3.1e+1./5.0e+2);
t29 = p./1.0e+3;
t30 = q./1.0e+3;
t31 = r.*(9.0./5.0e+2);
t32 = r.*(3.1e+1./5.0e+2);
t33 = r./1.0e+3;
t35 = p.*(7.4e+1./1.25e+2);
t36 = p.*(2.79e+2./5.0e+2);
t37 = q.*(2.79e+2./5.0e+2);
t39 = q.*(3.1e+1./1.0e+3);
t41 = r.*(3.1e+1./1.0e+3);
t48 = q.*1.7228;
t49 = r.*1.8864;
t50 = u.*3.24648e+1;
t53 = v.*4.36156e+1;
t54 = w.*4.67695e+1;
t17 = t8.*2.0;
t18 = t9.*2.0;
t19 = t10.*2.0;
t21 = t3./1.0e+1;
t27 = t6.*(4.1e+1./5.0e+1);
t34 = t4.*(5.1e+1./5.0e+2);
t38 = -t30;
t40 = -t33;
t42 = t5.*(1.17e+2./1.0e+2);
t43 = t7.*(1.89e+2./2.5e+2);
t44 = t2.*(1.67e+2./1.0e+3);
t52 = -t50;
t55 = -t53;
t56 = -t54;
t57 = t25+t31;
t60 = t25+t29;
t61 = t29+t31;
t62 = t37+t50;
t64 = t28+t54;
t65 = t41+t53;
t68 = t24+t26+t35;
t45 = t21+7.0./3.0;
t46 = t34+5.0;
t47 = t27+2.0e+1;
t51 = t42+1.5e+1;
t58 = t44+1.0e+1./3.0;
t59 = t43+7.0e+1./3.0;
t63 = t32+t52;
t66 = t36+t55;
t67 = t39+t56;
t69 = t23+t38+t49;
t70 = t22+t40+t48;
et1 = U1.*(-3.307683405402052e-4)+U2.*1.859578044455023e-21;
et2 = U3.*3.350640332744937e-4;
et3 = U4.*3.336321356963975e-4-U5.*1.819638864719295e-3;
et4 = U6.*(-1.812421155037148e-3)+U7.*1.853873173346878e-3;
et5 = U8.*1.778186846409557e-3-t8.*6.319529682423614e-3;
et6 = t9.*(-6.319529682423614e-3)+U1.*t20.*1.517111971060688e-2+U2.*t20.*1.492882415550761e-2;
et7 = U3.*t20.*1.517111971060688e-2+U4.*t20.*1.516372519659284e-2-epsilon1.*epsilon3.*4.138016519122657e-1;
et8 = epsilon2.*epsilon3.*(-1.3017970932508e-3)-epsilon1.*eta.*1.3017970932508e-3+epsilon2.*eta.*4.138016519122657e-1;
et9 = p.*t57.*(-9.602862890270499e-1)-p.*t58.*1.303522588356414e-4+p.*t64.*9.480305514485772e-7-p.*t66.*6.823134824417595e-6;
et10 = p.*t69.*(-1.003331497170287e-2)-p.*t70.*1.012504487436365e-3+q.*t45.*1.003331497170287e-2-q.*t61.*2.938894709490589e-5;
et11 = q.*t62.*(-6.823134824417595e-6)+q.*t67.*3.097697706538871e-2+q.*t68.*1.012504487436365e-3-q.*t69.*1.303522588356414e-4;
et12 = r.*t46.*(-1.012504487436365e-3)+r.*t60.*2.115171795569455e-4+r.*t63.*9.480305514485772e-7+r.*t65.*3.097697706538871e-2;
et13 = r.*t68.*1.003331497170287e-2+r.*t70.*1.303522588356414e-4-t51.*u.*3.097697706538871e-2+t57.*u.*4.040920023904883e-3;
et14 = t65.*u.*(-1.012504487436365e-3)+t67.*u.*1.003331497170287e-2-t47.*v.*9.480305514485772e-7-t61.*v.*3.11032764122789e-1;
et15 = t63.*v.*(-1.012504487436365e-3)-t64.*v.*1.303522588356414e-4+t59.*w.*6.823134824417595e-6+t60.*w.*3.138763911052732e-2;
et16 = t62.*w.*1.003331497170287e-2-t66.*w.*1.303522588356414e-4+3.159764841211807e-3;
et17 = U1.*1.397575406352208e-4+U2.*7.924461028811397e-21;
et18 = U3.*(-1.415725736304834e-4);
et19 = U4.*(-1.409675626320625e-4)-U5.*3.424925181634632e-3;
et20 = U6.*3.387750973601051e-3+U7.*3.570812279719344e-3;
et21 = U8.*(-3.533638071685763e-3)-t8.*2.693023120923067e-2;
et22 = t9.*(-2.693023120923067e-2)-U1.*t20.*1.090649593858282e-2+U2.*t20.*1.100012304554462e-2;
et23 = U3.*t20.*(-1.090649593858282e-2)+U4.*t20.*1.090087173345982e-2-epsilon1.*epsilon3.*9.920210995693149e-4;
et24 = epsilon2.*epsilon3.*(-5.197901606989806e-1)-epsilon1.*eta.*5.197901606989806e-1+epsilon2.*eta.*9.920210995693149e-4;
et25 = p.*t57.*(-2.938894709490589e-5)-p.*t58.*2.188227438151068e-2+p.*t64.*2.320783323245932e-2-p.*t66.*2.907630909692153e-5;
et26 = p.*t69.*(-1.026911824132076e-4)+p.*t70.*4.278073796758403e-4+q.*t45.*1.026911824132076e-4-q.*t61.*7.194428302062391e-1;
et27 = q.*t62.*(-2.907630909692153e-5)+q.*t67.*9.480305514485772e-7-q.*t68.*4.278073796758403e-4-q.*t69.*2.188227438151068e-2;
et28 = r.*t46.*4.278073796758403e-4+r.*t60.*9.013655820045674e-4+r.*t63.*2.320783323245932e-2+r.*t65.*9.480305514485772e-7;
et29 = r.*t68.*1.026911824132076e-4+r.*t70.*2.188227438151068e-2-t51.*u.*9.480305514485772e-7+t57.*u.*6.78350505826831e-1;
et30 = t65.*u.*4.278073796758403e-4+t67.*u.*1.026911824132076e-4-t47.*v.*2.320783323245932e-2-t61.*v.*3.183426654809437e-3;
et31 = t63.*v.*4.278073796758403e-4-t64.*v.*2.188227438151068e-2+t59.*w.*2.907630909692153e-5-t60.*w.*1.326202876995105e-2;
et32 = t62.*w.*1.026911824132076e-4-t66.*w.*2.188227438151068e-2+1.346511560461533e-2;
et33 = U1.*(-1.725827915740819e-6);
et34 = U2.*(-5.828197568247432e-18);
et35 = U3.*1.748241265284163e-6;
et36 = U4.*1.740770148765829e-6-U5.*2.095639900015615e-2;
et37 = U6.*2.110031621698574e-2-U7.*2.182294950286063e-2;
et38 = U8.*2.167903228603104e-2+t8.*1.863574892135219e-1;
et39 = t9.*1.863574892135219e-1-U1.*t20.*4.886926387591695e-5+U2.*t20.*6.626442938924465e-5;
et40 = U3.*t20.*(-4.886926387591695e-5)+U4.*t20.*6.749005688877506e-5+epsilon1.*epsilon3.*5.875841520580333e-3;
et41 = epsilon2.*epsilon3.*3.354073588822474e-2+epsilon1.*eta.*3.354073588822474e-2-epsilon2.*eta.*5.875841520580333e-3;
et42 = p.*t57.*2.115171795569455e-4+p.*t58.*2.272431716587712e-3-p.*t64.*2.907630909692153e-5+p.*t66.*2.138473182670276e-2;
et43 = p.*t69.*3.975613724574329e-4-p.*t70.*5.282877153148301e-6-q.*t45.*3.975613724574329e-4+q.*t61.*9.013655820045674e-4;
et44 = q.*t62.*2.138473182670276e-2-q.*t67.*6.823134824417595e-6+q.*t68.*5.282877153148301e-6+q.*t69.*2.272431716587712e-3;
et45 = r.*t46.*(-5.282877153148301e-6)-r.*t60.*6.629266866277855e-1-r.*t63.*2.907630909692153e-5-r.*t65.*6.823134824417595e-6;
et46 = r.*t68.*(-3.975613724574329e-4)-r.*t70.*2.272431716587712e-3+t51.*u.*6.823134824417595e-6-t57.*u.*7.044538321421906e-2;
et47 = t65.*u.*(-5.282877153148301e-6)-t67.*u.*3.975613724574329e-4+t47.*v.*2.907630909692153e-5+t61.*v.*1.232440254618042e-2;
et48 = t63.*v.*(-5.282877153148301e-6)+t64.*v.*2.272431716587712e-3-t59.*w.*2.138473182670276e-2+t60.*w.*1.637691917475973e-4;
et49 = t62.*w.*(-3.975613724574329e-4)+t66.*w.*2.272431716587712e-3-9.317874460676093e-2;
et50 = U1.*1.302135095166983e-3;
et51 = U2.*6.193288329240141e-19;
et52 = U3.*(-1.31904594055876e-3);
et53 = U4.*(-1.313408992094834e-3)-U5.*2.676719354658257e-1;
et54 = U6.*2.647662125022089e-1+U7.*2.790736050389333e-1;
et55 = U8.*(-2.761678820753165e-1)-t8.*2.104707008406899;
et56 = t9.*(-2.104707008406899)+U1.*t20.*4.359319882537525e-2-U2.*t20.*4.305183106323503e-2;
et57 = U3.*t20.*4.359319882537525e-2-U4.*t20.*4.397656554353263e-2-epsilon1.*epsilon3.*1.138522338822895e-1;
et58 = epsilon2.*epsilon3.*(-2.524211455612299e+1)-epsilon1.*eta.*2.524211455612299e+1+epsilon2.*eta.*1.138522338822895e-1;
et59 = p.*t57.*(-4.040920023904883e-3)-p.*t58.*1.71018810547529+p.*t64.*2.188227438151068e-2;
et60 = p.*t66.*(-2.272431716587712e-3)-p.*t69.*8.026859015515944e-3+p.*t70.*3.9859244840414e-3;
et61 = q.*t45.*8.026859015515944e-3-q.*t61.*6.78350505826831e-1-q.*t62.*2.272431716587712e-3;
et62 = q.*t67.*1.303522588356414e-4-q.*t68.*3.9859244840414e-3-q.*t69.*1.71018810547529;
et63 = r.*t46.*3.9859244840414e-3+r.*t60.*7.044538321421906e-2+r.*t63.*2.188227438151068e-2+r.*t65.*1.303522588356414e-4;
et64 = r.*t68.*8.026859015515944e-3+r.*t70.*1.71018810547529-t51.*u.*1.303522588356414e-4;
et65 = t57.*u.*5.301583126973399e+1+t65.*u.*3.9859244840414e-3+t67.*u.*8.026859015515944e-3;
et66 = t47.*v.*(-2.188227438151068e-2)-t61.*v.*2.488326294809943e-1+t63.*v.*3.9859244840414e-3;
et67 = t64.*v.*(-1.71018810547529)+t59.*w.*2.272431716587712e-3-t60.*w.*1.235636590052834e-1;
et68 = t62.*w.*8.026859015515944e-3-t66.*w.*1.71018810547529+1.052353504203449;
et69 = U1.*5.247482382331681e-7-U2.*1.083514276897426e-19;
et70 = U3.*(-5.315631504182326e-7);
et71 = U4.*(-5.292915130232833e-7)+U5.*1.059366762359936e-1;
et72 = U6.*1.053788543694033e-1-U7.*1.079313955363373e-1;
et73 = U8.*(-1.033841350690595e-1)+t8.*3.682179758252496e-1;
et74 = t9.*3.682179758252496e-1+U1.*t20.*1.345765452672799e-2+U2.*t20.*1.386905498063568e-2;
et75 = U3.*t20.*1.345765452672799e-2+U4.*t20.*1.386868232130781e-2+epsilon1.*epsilon3.*8.637139725679998;
et76 = epsilon2.*epsilon3.*1.184627304742461e-1+epsilon1.*eta.*1.184627304742461e-1-epsilon2.*eta.*8.637139725679998;
et77 = p.*t57.*3.11032764122789e-1+p.*t58.*8.026859015515944e-3-p.*t64.*1.026911824132076e-4+p.*t66.*3.975613724574329e-4;
et78 = p.*t69.*5.837445596834167e-1+p.*t70.*1.606290206365557e-6-q.*t45.*5.837445596834167e-1;
et79 = q.*t61.*3.183426654809437e-3+q.*t62.*3.975613724574329e-4-q.*t67.*1.003331497170287e-2-q.*t68.*1.606290206365557e-6;
et80 = q.*t69.*8.026859015515944e-3+r.*t46.*1.606290206365557e-6-r.*t60.*1.232440254618042e-2-r.*t63.*1.026911824132076e-4;
et81 = r.*t65.*(-1.003331497170287e-2)-r.*t68.*5.837445596834167e-1-r.*t70.*8.026859015515944e-3;
et82 = t51.*u.*1.003331497170287e-2-t57.*u.*2.488326294809943e-1+t65.*u.*1.606290206365557e-6;
et83 = t67.*u.*(-5.837445596834167e-1)+t47.*v.*1.026911824132076e-4+t61.*v.*1.809608135018592e+1;
et84 = t63.*v.*1.606290206365557e-6+t64.*v.*8.026859015515944e-3-t59.*w.*3.975613724574329e-4-t60.*w.*4.979499639733228e-5;
et85 = t62.*w.*(-5.837445596834167e-1)+t66.*w.*8.026859015515944e-3-1.841089879126248e-1;
et86 = U1.*(-1.731941163298826e-1);
et87 = U2.*(-1.439796020209256e-21);
et88 = U3.*1.75443390567933e-1;
et89 = U4.*1.746936324885829e-1+U5.*6.202181346042057e-4;
et90 = U6.*(-6.207996116589e-4)-U7.*6.467243742662552e-4;
et91 = U8.*6.473058513209489e-4+t8.*4.892956073276469e-3;
et92 = t9.*4.892956073276469e-3+U1.*t20.*5.925549487801743e-4-U2.*t20.*1.225770464045467e-1;
et93 = U3.*t20.*5.925549487801743e-4+U4.*t20.*4.198467360829836e-4-epsilon1.*epsilon3.*6.536113237400682e-1;
et94 = epsilon2.*epsilon3.*3.845100214783996e-1+epsilon1.*eta.*3.845100214783996e-1+epsilon2.*eta.*6.536113237400682e-1;
et95 = p.*t57.*(-3.138763911052732e-2)+p.*t58.*3.9859244840414e-3-p.*t64.*4.278073796758403e-4+p.*t66.*5.282877153148301e-6;
et96 = p.*t69.*(-1.606290206365557e-6)-p.*t70.*5.301590221578864e-1+q.*t45.*1.606290206365557e-6+q.*t61.*1.326202876995105e-2;
et97 = q.*t62.*5.282877153148301e-6+q.*t67.*1.012504487436365e-3+q.*t68.*5.301590221578864e-1+q.*t69.*3.9859244840414e-3;
et98 = r.*t46.*(-5.301590221578864e-1)-r.*t60.*1.637691917475973e-4-r.*t63.*4.278073796758403e-4;
et99 = r.*t65.*1.012504487436365e-3+r.*t68.*1.606290206365557e-6-r.*t70.*3.9859244840414e-3-t51.*u.*1.012504487436365e-3;
et100 = t57.*u.*(-1.235636590052834e-1)-t65.*u.*5.301590221578864e-1+t67.*u.*1.606290206365557e-6;
et101 = t47.*v.*4.278073796758403e-4-t61.*v.*4.979499639733228e-5-t63.*v.*5.301590221578864e-1;
et102 = t64.*v.*3.9859244840414e-3-t59.*w.*5.282877153148301e-6+t60.*w.*1.643492968689448e+1+t62.*w.*1.606290206365557e-6;
et103 = t66.*w.*3.9859244840414e-3-2.446478036638235e-3;
mt1 = [-u.*(t18+t19-1.0)+w.*(t12+t15)+v.*(t11-t16),u.*(t11+t16)-v.*(t17+t19-1.0)+w.*(t13-t14),v.*(t13+t14)-w.*(t17+t18-1.0)+u.*(t12-t15),epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0,(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0,(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0,epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0,et1+et2+et3+et4+et5+et6+et7+et8+et9+et10+et11+et12+et13+et14+et15+et16,et17+et18+et19+et20+et21+et22+et23+et24+et25+et26+et27+et28+et29+et30+et31+et32];
mt2 = [et33+et34+et35+et36+et37+et38+et39+et40+et41+et42+et43+et44+et45+et46+et47+et48+et49,et50+et51+et52+et53+et54+et55+et56+et57+et58+et59+et60+et61+et62+et63+et64+et65+et66+et67+et68,et69+et70+et71+et72+et73+et74+et75+et76+et77+et78+et79+et80+et81+et82+et83+et84+et85,et86+et87+et88+et89+et90+et91+et92+et93+et94+et95+et96+et97+et98+et99+et100+et101+et102+et103];
out1 = reshape([mt1,mt2],13,1);
