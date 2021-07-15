function out1 = AUVQuatPerturbedSimFcn(in1,in2,in3)
%AUVQUATPERTURBEDSIMFCN
%    OUT1 = AUVQUATPERTURBEDSIMFCN(IN1,IN2,IN3)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    10-Jul-2021 18:28:15

F_ext1 = in2(1,:);
F_ext2 = in2(2,:);
F_ext3 = in2(3,:);
F_ext4 = in2(4,:);
F_ext5 = in2(5,:);
F_ext6 = in2(6,:);
U1 = in3(1,:);
U2 = in3(2,:);
U3 = in3(3,:);
U4 = in3(4,:);
U5 = in3(5,:);
U6 = in3(6,:);
U7 = in3(7,:);
U8 = in3(8,:);
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
z = in1(3,:);
t2 = abs(p);
t3 = abs(q);
t4 = abs(r);
t5 = abs(u);
t6 = abs(v);
t7 = abs(w);
t8 = epsilon1.*epsilon3;
t9 = epsilon2.*epsilon3;
t10 = epsilon1.*eta;
t11 = epsilon2.*eta;
t12 = epsilon1.^2;
t13 = epsilon2.^2;
t14 = epsilon3.^2;
t15 = epsilon1.*epsilon2.*2.0;
t20 = epsilon3.*eta.*2.0;
t26 = sqrt(2.0);
t27 = z.*(4.0e+1./3.0);
t29 = p./1.25e+2;
t30 = p./2.5e+2;
t31 = q./1.25e+2;
t32 = q./5.0e+2;
t33 = r./2.5e+2;
t34 = p.*(3.1e+1./5.0e+2);
t35 = p./1.0e+3;
t36 = q./1.0e+3;
t37 = r.*(9.0./5.0e+2);
t38 = r.*(3.1e+1./5.0e+2);
t39 = r./1.0e+3;
t43 = p.*(7.4e+1./1.25e+2);
t44 = p.*(2.79e+2./5.0e+2);
t45 = q.*(2.79e+2./5.0e+2);
t47 = q.*(3.1e+1./1.0e+3);
t49 = r.*(3.1e+1./1.0e+3);
t52 = q.*1.7228;
t53 = r.*1.8864;
t54 = u.*3.24648e+1;
t58 = v.*4.36156e+1;
t59 = w.*4.67695e+1;
t16 = t8.*2.0;
t17 = t9.*2.0;
t18 = t10.*2.0;
t19 = t11.*2.0;
t21 = t12.*2.0;
t22 = t13.*2.0;
t23 = t14.*2.0;
t24 = -t11;
t28 = t9+t10;
t40 = t27-2.0;
t46 = -t36;
t48 = -t39;
t55 = t3.*1.45708e+1;
t57 = -t54;
t60 = t5.*7.00596e+1;
t61 = t6.*9.00196e+1;
t62 = -t58;
t63 = -t59;
t64 = t4.*1.119756e+1;
t66 = t32+t37;
t67 = t7.*1.10155248e+2;
t68 = t32+t35;
t69 = t35+t37;
t70 = t2.*2.4333236e+1;
t78 = t45+t54;
t80 = t34+t59;
t81 = t49+t58;
t84 = t31+t33+t43;
t25 = -t19;
t41 = t8+t24;
t42 = t17+t18;
t50 = erf(t40);
t56 = t21+t22-1.0;
t65 = t55+7.0;
t71 = t60+4.5e+1;
t72 = t61+6.0e+1;
t73 = t64+1.5e+1;
t75 = t70+1.0e+1;
t76 = t67+7.0e+1;
t79 = t38+t57;
t82 = t44+t62;
t83 = t47+t63;
t86 = t30+t46+t53;
t87 = t29+t48+t52;
t51 = t16+t25;
t74 = t50.*1.575e-2;
t77 = t50.*1.57185e+1;
t85 = t74+1.575e-2;
t88 = t77-1.52815e+1;
out1 = [-u.*(t22+t23-1.0)+w.*(t16+t19)+v.*(t15-t20);u.*(t15+t20)-v.*(t21+t23-1.0)+w.*(t17-t18);t51.*u+t42.*v-t56.*w;epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0;(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0;(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0;epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0;F_ext1.*3.097697706538871e-2+F_ext2.*9.480305514485772e-7-F_ext3.*6.823134824417595e-6+F_ext4.*1.303522588356414e-4-F_ext5.*1.003331497170287e-2+F_ext6.*1.012504487436365e-3-U1.*3.307683405402052e-4+U2.*1.859578044455023e-21+U3.*3.350640332744937e-4+U4.*3.336321356963975e-4-U5.*1.819638864719295e-3-U6.*1.812421155037148e-3+U7.*1.853873173346878e-3+U8.*1.778186846409557e-3-t8.*1.110759819363012e-1-t9.*8.112658362937022e-4-t10.*8.112658362937022e-4+t11.*1.110759819363012e-1-t12.*6.261028533827147e-3-t13.*6.261028533827147e-3+U1.*t26.*1.517111971060688e-2+U2.*t26.*1.492882415550761e-2+U3.*t26.*1.517111971060688e-2+U4.*t26.*1.516372519659284e-2-p.*t66.*9.602862890270499e-1-p.*t75.*1.303522588356414e-4+p.*t80.*9.480305514485772e-7-p.*t82.*6.823134824417595e-6-p.*t86.*1.003331497170287e-2-p.*t87.*1.012504487436365e-3+q.*t65.*1.003331497170287e-2-q.*t69.*2.938894709490589e-5-q.*t78.*6.823134824417595e-6+q.*t83.*3.097697706538871e-2+q.*t84.*1.012504487436365e-3-q.*t86.*1.303522588356414e-4+r.*t68.*2.115171795569455e-4-r.*t73.*1.012504487436365e-3+r.*t79.*9.480305514485772e-7+r.*t81.*3.097697706538871e-2+r.*t84.*1.003331497170287e-2+r.*t87.*1.303522588356414e-4-t28.*t88.*1.860035941942108e-5-t42.*t85.*7.657188887155719e-3-t41.*t88.*6.077682900229264e-1-t51.*t85.*5.89379797395962e-1-t56.*t88.*6.693495262753661e-5+t66.*u.*4.040920023904883e-3-t71.*u.*3.097697706538871e-2-t81.*u.*1.012504487436365e-3+t83.*u.*1.003331497170287e-2-t69.*v.*3.11032764122789e-1-t72.*v.*9.480305514485772e-7-t79.*v.*1.012504487436365e-3-t80.*v.*1.303522588356414e-4+t68.*w.*3.138763911052732e-2+t76.*w.*6.823134824417595e-6+t78.*w.*1.003331497170287e-2-t82.*w.*1.303522588356414e-4+3.130514266913573e-3;F_ext1.*9.480305514485772e-7+F_ext2.*2.320783323245932e-2-F_ext3.*2.907630909692153e-5+F_ext4.*2.188227438151068e-2-F_ext5.*1.026911824132076e-4-F_ext6.*4.278073796758403e-4+U1.*1.397575406352208e-4+U2.*7.924461028811397e-21-U3.*1.415725736304834e-4-U4.*1.409675626320625e-4-U5.*3.424925181634632e-3+U6.*3.387750973601051e-3+U7.*3.570812279719344e-3-U8.*3.533638071685763e-3-t8.*6.038569484796216e-4-t9.*2.398264656422701e-1-t10.*2.398264656422701e-1+t11.*6.038569484796216e-4-t12.*2.668093267961221e-2-t13.*2.668093267961221e-2-U1.*t26.*1.090649593858282e-2+U2.*t26.*1.100012304554462e-2-U3.*t26.*1.090649593858282e-2+U4.*t26.*1.090087173345982e-2-p.*t66.*2.938894709490589e-5-p.*t75.*2.188227438151068e-2+p.*t80.*2.320783323245932e-2-p.*t82.*2.907630909692153e-5-p.*t86.*1.026911824132076e-4+p.*t87.*4.278073796758403e-4+q.*t65.*1.026911824132076e-4-q.*t69.*7.194428302062391e-1-q.*t78.*2.907630909692153e-5+q.*t83.*9.480305514485772e-7-q.*t84.*4.278073796758403e-4-q.*t86.*2.188227438151068e-2+r.*t68.*9.013655820045674e-4+r.*t73.*4.278073796758403e-4+r.*t79.*2.320783323245932e-2+r.*t81.*9.480305514485772e-7+r.*t84.*1.026911824132076e-4+r.*t87.*2.188227438151068e-2-t28.*t88.*4.553376880208519e-1-t42.*t85.*1.285414688755527-t41.*t88.*1.860035941942108e-5-t51.*t85.*6.032314190847719e-3-t56.*t88.*2.852385922408002e-4+t66.*u.*6.78350505826831e-1-t71.*u.*9.480305514485772e-7+t81.*u.*4.278073796758403e-4+t83.*u.*1.026911824132076e-4-t69.*v.*3.183426654809437e-3-t72.*v.*2.320783323245932e-2+t79.*v.*4.278073796758403e-4-t80.*v.*2.188227438151068e-2-t68.*w.*1.326202876995105e-2+t76.*w.*2.907630909692153e-5+t78.*w.*1.026911824132076e-4-t82.*w.*2.188227438151068e-2+1.33404663398061e-2;F_ext1.*(-6.823134824417595e-6)-F_ext2.*2.907630909692153e-5+F_ext3.*2.138473182670276e-2-F_ext4.*2.272431716587712e-3+F_ext5.*3.975613724574329e-4+F_ext6.*5.282877153148301e-6-U1.*1.725827915740819e-6-U2.*5.828197568247432e-18+U3.*1.748241265284163e-6+U4.*1.740770148765829e-6-U5.*2.095639900015615e-2+U6.*2.110031621698574e-2-U7.*2.182294950286063e-2+U8.*2.167903228603104e-2+t8.*4.346059700124901e-3+t9.*2.488170468747569e-2+t10.*2.488170468747569e-2-t11.*4.346059700124901e-3+t12.*3.006081615282016e-3+t13.*3.006081615282016e-3-U1.*t26.*4.886926387591695e-5+U2.*t26.*6.626442938924465e-5-U3.*t26.*4.886926387591695e-5+U4.*t26.*6.749005688877506e-5+p.*t66.*2.115171795569455e-4+p.*t75.*2.272431716587712e-3-p.*t80.*2.907630909692153e-5+p.*t82.*2.138473182670276e-2+p.*t86.*3.975613724574329e-4-p.*t87.*5.282877153148301e-6-q.*t65.*3.975613724574329e-4+q.*t69.*9.013655820045674e-4+q.*t78.*2.138473182670276e-2-q.*t83.*6.823134824417595e-6+q.*t84.*5.282877153148301e-6+q.*t86.*2.272431716587712e-3-r.*t68.*6.629266866277855e-1-r.*t73.*5.282877153148301e-6-r.*t79.*2.907630909692153e-5-r.*t81.*6.823134824417595e-6-r.*t84.*3.975613724574329e-4-r.*t87.*2.272431716587712e-3+t28.*t88.*5.704771844816004e-4+t42.*t85.*1.33487820176676e-1+t41.*t88.*1.338699052550732e-4+t51.*t85.*2.335366145807881e-2+t56.*t88.*2.097842192199541e-1-t66.*u.*7.044538321421906e-2+t71.*u.*6.823134824417595e-6-t81.*u.*5.282877153148301e-6-t83.*u.*3.975613724574329e-4+t69.*v.*1.232440254618042e-2+t72.*v.*2.907630909692153e-5-t79.*v.*5.282877153148301e-6+t80.*v.*2.272431716587712e-3+t68.*w.*1.637691917475973e-4-t76.*w.*2.138473182670276e-2-t78.*w.*3.975613724574329e-4+t82.*w.*2.272431716587712e-3-1.503040807641008e-3;F_ext1.*1.303522588356414e-4+F_ext2.*2.188227438151068e-2-F_ext3.*2.272431716587712e-3+F_ext4.*1.71018810547529-F_ext5.*8.026859015515944e-3-F_ext6.*3.9859244840414e-3+U1.*1.302135095166983e-3+U2.*6.193288329240141e-19-U3.*1.31904594055876e-3-U4.*1.313408992094834e-3-U5.*2.676719354658257e-1+U6.*2.647662125022089e-1+U7.*2.790736050389333e-1-U8.*2.761678820753165e-1-t8.*8.302909344814061e-2-t9.*1.872549529020894e+1-t10.*1.872549529020894e+1+t11.*8.302909344814061e-2-t12.*2.085223315214779-t13.*2.085223315214779+U1.*t26.*4.359319882537525e-2-U2.*t26.*4.305183106323503e-2+U3.*t26.*4.359319882537525e-2-U4.*t26.*4.397656554353263e-2-p.*t66.*4.040920023904883e-3-p.*t75.*1.71018810547529+p.*t80.*2.188227438151068e-2-p.*t82.*2.272431716587712e-3-p.*t86.*8.026859015515944e-3+p.*t87.*3.9859244840414e-3+q.*t65.*8.026859015515944e-3-q.*t69.*6.78350505826831e-1-q.*t78.*2.272431716587712e-3+q.*t83.*1.303522588356414e-4-q.*t84.*3.9859244840414e-3-q.*t86.*1.71018810547529+r.*t68.*7.044538321421906e-2+r.*t73.*3.9859244840414e-3+r.*t79.*2.188227438151068e-2+r.*t81.*1.303522588356414e-4+r.*t84.*8.026859015515944e-3+r.*t87.*1.71018810547529-t28.*t88.*4.293302233652395e-1-t42.*t85.*1.00460348544499e+2-t41.*t88.*2.557511318355284e-3-t51.*t85.*4.715159998099619e-1-t56.*t88.*2.229255513972545e-2+t66.*u.*5.301583126973399e+1-t71.*u.*1.303522588356414e-4+t81.*u.*3.9859244840414e-3+t83.*u.*8.026859015515944e-3-t69.*v.*2.488326294809943e-1-t72.*v.*2.188227438151068e-2+t79.*v.*3.9859244840414e-3-t80.*v.*1.71018810547529-t68.*w.*1.235636590052834e-1+t76.*w.*2.272431716587712e-3+t78.*w.*8.026859015515944e-3-t82.*w.*1.71018810547529+1.042611657607389;F_ext1.*(-1.003331497170287e-2)-F_ext2.*1.026911824132076e-4+F_ext3.*3.975613724574329e-4-F_ext4.*8.026859015515944e-3+F_ext5.*5.837445596834167e-1-F_ext6.*1.606290206365557e-6+U1.*5.247482382331681e-7-U2.*1.083514276897426e-19-U3.*5.315631504182326e-7-U4.*5.292915130232833e-7+U5.*1.059366762359936e-1+U6.*1.053788543694033e-1-U7.*1.079313955363373e-1-U8.*1.033841350690595e-1+t8.*6.390814043587317+t9.*8.787675444967862e-2+t10.*8.787675444967862e-2-t11.*6.390814043587317+t12.*3.648093084714819e-1+t13.*3.648093084714819e-1+U1.*t26.*1.345765452672799e-2+U2.*t26.*1.386905498063568e-2+U3.*t26.*1.345765452672799e-2+U4.*t26.*1.386868232130781e-2+p.*t66.*3.11032764122789e-1+p.*t75.*8.026859015515944e-3-p.*t80.*1.026911824132076e-4+p.*t82.*3.975613724574329e-4+p.*t86.*5.837445596834167e-1+p.*t87.*1.606290206365557e-6-q.*t65.*5.837445596834167e-1+q.*t69.*3.183426654809437e-3+q.*t78.*3.975613724574329e-4-q.*t83.*1.003331497170287e-2-q.*t84.*1.606290206365557e-6+q.*t86.*8.026859015515944e-3-r.*t68.*1.232440254618042e-2+r.*t73.*1.606290206365557e-6-r.*t79.*1.026911824132076e-4-r.*t81.*1.003331497170287e-2-r.*t84.*5.837445596834167e-1-r.*t87.*8.026859015515944e-3+t28.*t88.*2.014800998947134e-3+t42.*t85.*4.715159998099619e-1+t41.*t88.*1.968536397448103e-1+t51.*t85.*3.429048637339998e+1+t56.*t88.*3.900077063807416e-3-t66.*u.*2.488326294809943e-1+t71.*u.*1.003331497170287e-2+t81.*u.*1.606290206365557e-6-t83.*u.*5.837445596834167e-1+t69.*v.*1.809608135018592e+1+t72.*v.*1.026911824132076e-4+t79.*v.*1.606290206365557e-6+t80.*v.*8.026859015515944e-3-t68.*w.*4.979499639733228e-5-t76.*w.*3.975613724574329e-4-t78.*w.*5.837445596834167e-1+t82.*w.*8.026859015515944e-3-1.82404654235741e-1;F_ext1.*1.012504487436365e-3-F_ext2.*4.278073796758403e-4+F_ext3.*5.282877153148301e-6-F_ext4.*3.9859244840414e-3-F_ext5.*1.606290206365557e-6+F_ext6.*5.301590221578864e-1-U1.*1.731941163298826e-1-U2.*1.439796020209256e-21+U3.*1.75443390567933e-1+U4.*1.746936324885829e-1+U5.*6.202181346042057e-4-U6.*6.207996116589e-4-U7.*6.467243742662552e-4+U8.*6.473058513209489e-4-t8.*6.449242265146671e-1+t9.*3.660910622711756e-1+t10.*3.660910622711756e-1+t11.*6.449242265146671e-1+t12.*4.847661001538005e-3+t13.*4.847661001538005e-3+U1.*t26.*5.925549487801743e-4-U2.*t26.*1.225770464045467e-1+U3.*t26.*5.925549487801743e-4+U4.*t26.*4.198467360829836e-4-p.*t66.*3.138763911052732e-2+p.*t75.*3.9859244840414e-3-p.*t80.*4.278073796758403e-4+p.*t82.*5.282877153148301e-6-p.*t86.*1.606290206365557e-6-p.*t87.*5.301590221578864e-1+q.*t65.*1.606290206365557e-6+q.*t69.*1.326202876995105e-2+q.*t78.*5.282877153148301e-6+q.*t83.*1.012504487436365e-3+q.*t84.*5.301590221578864e-1+q.*t86.*3.9859244840414e-3-r.*t68.*1.637691917475973e-4-r.*t73.*5.301590221578864e-1-r.*t79.*4.278073796758403e-4+r.*t81.*1.012504487436365e-3+r.*t84.*1.606290206365557e-6-r.*t87.*3.9859244840414e-3+t28.*t88.*8.393580789239987e-3+t42.*t85.*2.341422921004155e-1-t41.*t88.*1.986533804350149e-2-t51.*t85.*9.435714906358336e-5+t56.*t88.*5.182502487238484e-5-t66.*u.*1.235636590052834e-1-t71.*u.*1.012504487436365e-3-t81.*u.*5.301590221578864e-1+t83.*u.*1.606290206365557e-6-t69.*v.*4.979499639733228e-5+t72.*v.*4.278073796758403e-4-t79.*v.*5.301590221578864e-1+t80.*v.*3.9859244840414e-3+t68.*w.*1.643492968689448e+1-t76.*w.*5.282877153148301e-6+t78.*w.*1.606290206365557e-6+t82.*w.*3.9859244840414e-3-2.423830500769003e-3];
