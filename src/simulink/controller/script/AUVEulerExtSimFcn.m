function out1 = AUVEulerExtSimFcn(in1,in2)
%AUVEULEREXTSIMFCN
%    OUT1 = AUVEULEREXTSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.7.
%    28-Oct-2021 20:19:39

U1 = in2(1,:);
U2 = in2(2,:);
U3 = in2(3,:);
U4 = in2(4,:);
U5 = in2(5,:);
U6 = in2(6,:);
U7 = in2(7,:);
U8 = in2(8,:);
m_d1 = in1(13,:);
m_d2 = in1(14,:);
m_d3 = in1(15,:);
m_d4 = in1(16,:);
m_d5 = in1(17,:);
m_d6 = in1(18,:);
m_d7 = in1(19,:);
m_d8 = in1(20,:);
p = in1(10,:);
phi = in1(4,:);
psi = in1(6,:);
q = in1(11,:);
r = in1(12,:);
theta = in1(5,:);
u = in1(7,:);
v = in1(8,:);
w = in1(9,:);
t2 = abs(p);
t3 = abs(q);
t4 = abs(r);
t5 = cos(phi);
t6 = cos(psi);
t7 = abs(u);
t8 = abs(v);
t9 = cos(theta);
t10 = abs(w);
t11 = sin(phi);
t12 = sin(psi);
t13 = sin(theta);
t15 = sqrt(2.0);
t17 = p./1.25e+2;
t18 = p./2.5e+2;
t19 = q./1.25e+2;
t20 = q./5.0e+2;
t21 = r./2.5e+2;
t23 = p.*(3.1e+1./5.0e+2);
t24 = p./1.0e+3;
t25 = q./1.0e+3;
t26 = r.*(9.0./5.0e+2);
t27 = r.*(3.1e+1./5.0e+2);
t28 = r./1.0e+3;
t31 = p.*(7.4e+1./1.25e+2);
t32 = p.*(2.79e+2./5.0e+2);
t33 = q.*(2.79e+2./5.0e+2);
t35 = q.*(3.1e+1./1.0e+3);
t37 = r.*(3.1e+1./1.0e+3);
t44 = q.*1.7228;
t45 = r.*1.8864;
t46 = u.*3.24648e+1;
t49 = v.*4.36156e+1;
t50 = w.*4.67695e+1;
t14 = 1.0./t9;
t16 = t3./1.0e+1;
t22 = t8.*(4.1e+1./5.0e+1);
t29 = t4.*(5.1e+1./5.0e+2);
t30 = t5.*(3.1e+1./5.0e+2);
t34 = -t25;
t36 = -t28;
t38 = t7.*(1.17e+2./1.0e+2);
t39 = t10.*(1.89e+2./2.5e+2);
t40 = t2.*(1.67e+2./1.0e+3);
t48 = -t46;
t51 = -t49;
t52 = -t50;
t53 = t20+t26;
t54 = t11.*7.46622e-1;
t57 = t20+t24;
t58 = t24+t26;
t60 = t33+t46;
t62 = t23+t50;
t63 = t37+t49;
t66 = t19+t21+t31;
t41 = t16+7.0./3.0;
t42 = t29+5.0;
t43 = t22+2.0e+1;
t47 = t38+1.5e+1;
t55 = t40+1.0e+1./3.0;
t56 = t39+7.0e+1./3.0;
t59 = -t54;
t61 = t27+t48;
t64 = t32+t51;
t65 = t35+t52;
t68 = t18+t34+t45;
t69 = t17+t36+t44;
t67 = t30+t59;
et1 = U1.*(-3.307683405402052e-4)+U2.*1.859578044455023e-21;
et2 = U3.*3.350640332744937e-4;
et3 = U4.*3.336321356963975e-4-U5.*1.819638864719295e-3;
et4 = U6.*(-1.812421155037148e-3)+U7.*1.853873173346878e-3;
et5 = U8.*1.778186846409557e-3+m_d3+t13.*2.069008259561328e-1;
et6 = U1.*t15.*1.517111971060688e-2+U2.*t15.*1.492882415550761e-2+U3.*t15.*1.517111971060688e-2+U4.*t15.*1.516372519659284e-2;
et7 = p.*t53.*(-9.602862890270499e-1)-p.*t55.*1.303522588356414e-4+p.*t62.*9.480305514485772e-7-p.*t64.*6.823134824417595e-6;
et8 = p.*t68.*(-1.003331497170287e-2)-p.*t69.*1.012504487436365e-3+q.*t41.*1.003331497170287e-2-q.*t58.*2.938894709490589e-5;
et9 = q.*t60.*(-6.823134824417595e-6)+q.*t65.*3.097697706538871e-2+q.*t66.*1.012504487436365e-3-q.*t68.*1.303522588356414e-4;
et10 = r.*t42.*(-1.012504487436365e-3)+r.*t57.*2.115171795569455e-4+r.*t61.*9.480305514485772e-7+r.*t63.*3.097697706538871e-2;
et11 = r.*t66.*1.003331497170287e-2+r.*t69.*1.303522588356414e-4+t5.*t9.*3.080481990342793e-3;
et12 = t9.*t11.*3.038485611411295e-4+t9.*t67.*1.278755659177642e-3-t47.*u.*3.097697706538871e-2;
et13 = t53.*u.*4.040920023904883e-3-t63.*u.*1.012504487436365e-3+t65.*u.*1.003331497170287e-2-t43.*v.*9.480305514485772e-7;
et14 = t58.*v.*(-3.11032764122789e-1)-t61.*v.*1.012504487436365e-3-t62.*v.*1.303522588356414e-4+t56.*w.*6.823134824417595e-6;
et15 = t57.*w.*3.138763911052732e-2+t60.*w.*1.003331497170287e-2-t64.*w.*1.303522588356414e-4;
et16 = U1.*1.397575406352208e-4+U2.*7.924461028811397e-21;
et17 = U3.*(-1.415725736304834e-4);
et18 = U4.*(-1.409675626320625e-4)-U5.*3.424925181634632e-3;
et19 = U6.*3.387750973601051e-3+U7.*3.570812279719344e-3;
et20 = U8.*(-3.533638071685763e-3)+m_d4+t13.*4.960105497846575e-4;
et21 = U1.*t15.*(-1.090649593858282e-2)+U2.*t15.*1.100012304554462e-2-U3.*t15.*1.090649593858282e-2;
et22 = U4.*t15.*1.090087173345982e-2-p.*t53.*2.938894709490589e-5-p.*t55.*2.188227438151068e-2;
et23 = p.*t62.*2.320783323245932e-2-p.*t64.*2.907630909692153e-5-p.*t68.*1.026911824132076e-4+p.*t69.*4.278073796758403e-4;
et24 = q.*t41.*1.026911824132076e-4-q.*t58.*7.194428302062391e-1-q.*t60.*2.907630909692153e-5+q.*t65.*9.480305514485772e-7;
et25 = q.*t66.*(-4.278073796758403e-4)-q.*t68.*2.188227438151068e-2+r.*t42.*4.278073796758403e-4+r.*t57.*9.013655820045674e-4;
et26 = r.*t61.*2.320783323245932e-2+r.*t63.*9.480305514485772e-7+r.*t66.*1.026911824132076e-4+r.*t69.*2.188227438151068e-2;
et27 = t5.*t9.*1.558786802929103e-4-t9.*t11.*9.962138533478937e-2+t9.*t67.*2.146651116826197e-1;
et28 = t47.*u.*(-9.480305514485772e-7)+t53.*u.*6.78350505826831e-1+t63.*u.*4.278073796758403e-4+t65.*u.*1.026911824132076e-4;
et29 = t43.*v.*(-2.320783323245932e-2)-t58.*v.*3.183426654809437e-3+t61.*v.*4.278073796758403e-4;
et30 = t62.*v.*(-2.188227438151068e-2)+t56.*w.*2.907630909692153e-5-t57.*w.*1.326202876995105e-2+t60.*w.*1.026911824132076e-4;
et31 = t64.*w.*(-2.188227438151068e-2);
et32 = U1.*(-1.725827915740819e-6);
et33 = U2.*(-5.828197568247432e-18);
et34 = U3.*1.748241265284163e-6;
et35 = U4.*1.740770148765829e-6-U5.*2.095639900015615e-2;
et36 = U6.*2.110031621698574e-2-U7.*2.182294950286063e-2;
et37 = U8.*2.167903228603104e-2+m_d5-t13.*2.937920760290167e-3;
et38 = U1.*t15.*(-4.886926387591695e-5)+U2.*t15.*6.626442938924465e-5-U3.*t15.*4.886926387591695e-5;
et39 = U4.*t15.*6.749005688877506e-5+p.*t53.*2.115171795569455e-4+p.*t55.*2.272431716587712e-3-p.*t62.*2.907630909692153e-5;
et40 = p.*t64.*2.138473182670276e-2+p.*t68.*3.975613724574329e-4-p.*t69.*5.282877153148301e-6-q.*t41.*3.975613724574329e-4;
et41 = q.*t58.*9.013655820045674e-4+q.*t60.*2.138473182670276e-2-q.*t65.*6.823134824417595e-6+q.*t66.*5.282877153148301e-6;
et42 = q.*t68.*2.272431716587712e-3-r.*t42.*5.282877153148301e-6-r.*t57.*6.629266866277855e-1-r.*t61.*2.907630909692153e-5;
et43 = r.*t63.*(-6.823134824417595e-6)-r.*t66.*3.975613724574329e-4-r.*t69.*2.272431716587712e-3;
et44 = t5.*t9.*(-9.179660618809795e-2)+t9.*t11.*1.262558405802736e-4-t9.*t67.*2.229255513972545e-2;
et45 = t47.*u.*6.823134824417595e-6-t53.*u.*7.044538321421906e-2-t63.*u.*5.282877153148301e-6-t65.*u.*3.975613724574329e-4;
et46 = t43.*v.*2.907630909692153e-5+t58.*v.*1.232440254618042e-2-t61.*v.*5.282877153148301e-6+t62.*v.*2.272431716587712e-3;
et47 = t56.*w.*(-2.138473182670276e-2)+t57.*w.*1.637691917475973e-4-t60.*w.*3.975613724574329e-4+t64.*w.*2.272431716587712e-3;
et48 = U1.*1.302135095166983e-3;
et49 = U2.*6.193288329240141e-19;
et50 = U3.*(-1.31904594055876e-3);
et51 = U4.*(-1.313408992094834e-3)-U5.*2.676719354658257e-1;
et52 = U6.*2.647662125022089e-1+U7.*2.790736050389333e-1;
et53 = U8.*(-2.761678820753165e-1)+m_d6+t13.*5.692611694114474e-2;
et54 = U1.*t15.*4.359319882537525e-2-U2.*t15.*4.305183106323503e-2+U3.*t15.*4.359319882537525e-2;
et55 = U4.*t15.*(-4.397656554353263e-2)-p.*t53.*4.040920023904883e-3-p.*t55.*1.71018810547529;
et56 = p.*t62.*2.188227438151068e-2-p.*t64.*2.272431716587712e-3-p.*t68.*8.026859015515944e-3;
et57 = p.*t69.*3.9859244840414e-3+q.*t41.*8.026859015515944e-3-q.*t58.*6.78350505826831e-1;
et58 = q.*t60.*(-2.272431716587712e-3)+q.*t65.*1.303522588356414e-4-q.*t66.*3.9859244840414e-3;
et59 = q.*t68.*(-1.71018810547529)+r.*t42.*3.9859244840414e-3+r.*t57.*7.044538321421906e-2;
et60 = r.*t61.*2.188227438151068e-2+r.*t63.*1.303522588356414e-4+r.*t66.*8.026859015515944e-3;
et61 = r.*t69.*1.71018810547529+t5.*t9.*1.218289469126858e-2-t9.*t11.*9.502081330014666e-2;
et62 = t9.*t67.*1.67769453147126e+1-t47.*u.*1.303522588356414e-4+t53.*u.*5.301583126973399e+1;
et63 = t63.*u.*3.9859244840414e-3+t65.*u.*8.026859015515944e-3-t43.*v.*2.188227438151068e-2;
et64 = t58.*v.*(-2.488326294809943e-1)+t61.*v.*3.9859244840414e-3-t62.*v.*1.71018810547529;
et65 = t56.*w.*2.272431716587712e-3-t57.*w.*1.235636590052834e-1+t60.*w.*8.026859015515944e-3;
et66 = t64.*w.*(-1.71018810547529);
et67 = U1.*5.247482382331681e-7-U2.*1.083514276897426e-19;
et68 = U3.*(-5.315631504182326e-7);
et69 = U4.*(-5.292915130232833e-7)+U5.*1.059366762359936e-1;
et70 = U6.*1.053788543694033e-1-U7.*1.079313955363373e-1;
et71 = U8.*(-1.033841350690595e-1)+m_d7-t13.*4.318569862839999;
et72 = U1.*t15.*1.345765452672799e-2+U2.*t15.*1.386905498063568e-2+U3.*t15.*1.345765452672799e-2;
et73 = U4.*t15.*1.386868232130781e-2+p.*t53.*3.11032764122789e-1+p.*t55.*8.026859015515944e-3;
et74 = p.*t62.*(-1.026911824132076e-4)+p.*t64.*3.975613724574329e-4+p.*t68.*5.837445596834167e-1+p.*t69.*1.606290206365557e-6;
et75 = q.*t41.*(-5.837445596834167e-1)+q.*t58.*3.183426654809437e-3+q.*t60.*3.975613724574329e-4;
et76 = q.*t65.*(-1.003331497170287e-2)-q.*t66.*1.606290206365557e-6+q.*t68.*8.026859015515944e-3+r.*t42.*1.606290206365557e-6;
et77 = r.*t57.*(-1.232440254618042e-2)-r.*t61.*1.026911824132076e-4-r.*t63.*1.003331497170287e-2;
et78 = r.*t66.*(-5.837445596834167e-1)-r.*t69.*8.026859015515944e-3-t5.*t9.*1.792268917222077e-1;
et79 = t9.*t11.*4.39745529355291e-4-t9.*t67.*7.874348694221141e-2+t47.*u.*1.003331497170287e-2;
et80 = t53.*u.*(-2.488326294809943e-1)+t63.*u.*1.606290206365557e-6-t65.*u.*5.837445596834167e-1;
et81 = t43.*v.*1.026911824132076e-4+t58.*v.*1.809608135018592e+1+t61.*v.*1.606290206365557e-6+t62.*v.*8.026859015515944e-3;
et82 = t56.*w.*(-3.975613724574329e-4)-t57.*w.*4.979499639733228e-5-t60.*w.*5.837445596834167e-1;
et83 = t64.*w.*8.026859015515944e-3;
et84 = U1.*(-1.731941163298826e-1);
et85 = U2.*(-1.439796020209256e-21);
et86 = U3.*1.75443390567933e-1;
et87 = U4.*1.746936324885829e-1+U5.*6.202181346042057e-4;
et88 = U6.*(-6.207996116589e-4)-U7.*6.467243742662552e-4;
et89 = U8.*6.473058513209489e-4+m_d8+t13.*3.268056618700341e-1;
et90 = U1.*t15.*5.925549487801743e-4-U2.*t15.*1.225770464045467e-1+U3.*t15.*5.925549487801743e-4;
et91 = U4.*t15.*4.198467360829836e-4-p.*t53.*3.138763911052732e-2+p.*t55.*3.9859244840414e-3;
et92 = p.*t62.*(-4.278073796758403e-4)+p.*t64.*5.282877153148301e-6-p.*t68.*1.606290206365557e-6-p.*t69.*5.301590221578864e-1;
et93 = q.*t41.*1.606290206365557e-6+q.*t58.*1.326202876995105e-2+q.*t60.*5.282877153148301e-6+q.*t65.*1.012504487436365e-3;
et94 = q.*t66.*5.301590221578864e-1+q.*t68.*3.9859244840414e-3-r.*t42.*5.301590221578864e-1;
et95 = r.*t57.*(-1.637691917475973e-4)-r.*t61.*4.278073796758403e-4+r.*t63.*1.012504487436365e-3+r.*t66.*1.606290206365557e-6;
et96 = r.*t69.*(-3.9859244840414e-3)-t5.*t9.*2.215904695457434e-5+t9.*t11.*1.630606576308838e-1;
et97 = t9.*t67.*(-3.910191918844614e-2)-t47.*u.*1.012504487436365e-3-t53.*u.*1.235636590052834e-1;
et98 = t63.*u.*(-5.301590221578864e-1)+t65.*u.*1.606290206365557e-6+t43.*v.*4.278073796758403e-4-t58.*v.*4.979499639733228e-5;
et99 = t61.*v.*(-5.301590221578864e-1)+t62.*v.*3.9859244840414e-3-t56.*w.*5.282877153148301e-6;
et100 = t57.*w.*1.643492968689448e+1+t60.*w.*1.606290206365557e-6+t64.*w.*3.9859244840414e-3;
mt1 = [-v.*(t5.*t12-t6.*t11.*t13)+w.*(t11.*t12+t5.*t6.*t13)+t6.*t9.*u,v.*(t5.*t6+t11.*t12.*t13)-w.*(t6.*t11-t5.*t12.*t13)+t9.*t12.*u,-t13.*u+t9.*t11.*v+t5.*t9.*w,m_d1+p+q.*t11.*t13.*t14+r.*t5.*t13.*t14,m_d2+q.*t5-r.*t11,q.*t11.*t14+r.*t5.*t14,et1+et2+et3+et4+et5+et6+et7+et8+et9+et10+et11+et12+et13+et14+et15,et16+et17+et18+et19+et20+et21+et22+et23+et24+et25+et26+et27+et28+et29+et30+et31,et32+et33+et34+et35+et36+et37+et38+et39+et40+et41+et42+et43+et44+et45+et46+et47,et48+et49+et50+et51+et52+et53+et54+et55+et56+et57+et58+et59+et60+et61+et62+et63+et64+et65+et66,et67+et68+et69+et70+et71+et72+et73+et74+et75+et76+et77+et78+et79+et80+et81+et82+et83];
mt2 = [et84+et85+et86+et87+et88+et89+et90+et91+et92+et93+et94+et95+et96+et97+et98+et99+et100,m_d1,m_d2,m_d3,m_d4,m_d5,m_d6,m_d7,m_d8];
out1 = reshape([mt1,mt2],20,1);
