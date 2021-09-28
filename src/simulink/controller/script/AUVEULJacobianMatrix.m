function [Ane,Bne,Cne,Dne] = AUVEULJacobianMatrix(in1,in2)
%AUVEULJACOBIANMATRIX
%    [ANE,BNE,CNE,DNE] = AUVEULJACOBIANMATRIX(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.7.
%    27-Sep-2021 22:57:58

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
t11 = sign(p);
t12 = sin(phi);
t13 = sin(psi);
t14 = sign(q);
t15 = sign(r);
t16 = sin(theta);
t17 = sign(u);
t18 = sign(v);
t19 = sign(w);
t46 = r.*1.057129907309279e-5;
t47 = q.*9.760289672284637e-5;
t48 = v.*1.129023503850542e-2;
t49 = u.*4.77039452928936e-3;
t50 = p.*9.170377126078081e-5;
t52 = w.*1.43523560675718e-1;
t53 = u.*5.68699616459184e-3;
t54 = w.*6.901450517184653e-2;
t55 = v.*7.167022390945983e-3;
t20 = t16.^2;
t21 = r.*t5;
t22 = q.*t12;
t23 = t5.*t6;
t24 = t5.*t13;
t25 = t6.*t12;
t26 = t12.*t13;
t27 = 1.0./t9;
t33 = t5.*(3.1e+1./5.0e+2);
t34 = t12.*(3.1e+1./5.0e+2);
t39 = t5.*3.66384e-1;
t40 = t12.*3.66384e-1;
t51 = -t50;
t28 = t27.^2;
t29 = t16.*t26;
t30 = t16.*t23;
t31 = t16.*t24;
t32 = t16.*t25;
t41 = -t40;
t44 = t34+t39;
t35 = -t31;
t36 = -t32;
t37 = t23+t29;
t38 = t26+t30;
t45 = t33+t41;
t42 = t24+t36;
t43 = t25+t35;
et1 = t9.*3.211133971822094e-1-t5.*t16.*3.113882531703934e-3-t12.*t16.*2.99207771465984e-4;
et2 = t16.*t45.*(-1.278755659177642e-3);
et3 = p.*(-2.151948492273065e-5)+r.*1.345418075860736-t8.*7.773850521878333e-7-u.*1.129023503850542e-2;
et4 = w.*(-4.111179891417293e-4)-t18.*v.*7.773850521878333e-7-2.844091654345731e-5;
et5 = p.*2.989993556213668e-6-q.*1.443116363827266+t10.*5.158289927259702e-6-u.*1.43523560675718e-1;
et6 = v.*(-4.111179891417293e-4)+t19.*w.*5.158289927259702e-6+2.388097188546158e-4;
et7 = p.*(-1.039636542482752e-4)-q.*3.056030135457876e-3-r.*3.027000926212141e-2-t2.*2.176882722555211e-5;
et8 = v.*(-2.151948492273065e-5)+w.*2.989993556213668e-6-p.*t11.*2.176882722555211e-5-6.517612941782069e-4;
et9 = p.*(-3.056030135457876e-3)+q.*1.929418735906703e-3+r.*6.288494148926307e-5+t3.*1.003331497170287e-3;
et10 = u.*9.760289672284637e-5-w.*1.443116363827266+q.*t14.*1.003331497170287e-3+3.511660240096004e-2;
et11 = p.*(-3.027000926212141e-2)+q.*6.288494148926307e-5+r.*2.000695949098431e-3-t4.*1.032754577185093e-4;
et12 = u.*1.057129907309279e-5+v.*1.345418075860736-r.*t15.*1.032754577185093e-4-7.593783655772739e-3;
et13 = t9.*1.175993883409729e-4-t5.*t16.*2.982127378210696e-4+t12.*t16.*2.132281384959919e-1;
et14 = t16.*t45.*(-2.146651116826197e-1);
et15 = q.*4.159278787387334e-4-r.*7.412140931914926e-1-t7.*1.109195745194835e-6;
et16 = v.*4.77039452928936e-3-w.*1.468966557066211e-3-t17.*u.*1.109195745194835e-6-2.133068740759299e-5;
et17 = p.*1.073195185231853-q.*1.356129262930646e-5+t10.*2.198168967727268e-5;
et18 = u.*(-1.468966557066211e-3)-v.*6.901450517184653e-2+t19.*w.*2.198168967727268e-5;
et19 = 1.017670818392254e-3;
et20 = p.*2.8513455484883e-3-q.*3.231634295066181e-4+r.*4.207928569104986e-5-t2.*3.654339821712283e-3;
et21 = v.*(-9.170377126078081e-5)+w.*1.073195185231853-p.*t11.*3.654339821712283e-3;
et22 = -1.094113719075534e-1;
et23 = p.*(-3.231634295066181e-4)+q.*4.529247630233296e-6-r.*1.652899800142284e-2+t3.*1.026911824132076e-5;
et24 = u.*4.159278787387334e-4-w.*1.356129262930646e-5+q.*t14.*1.026911824132076e-5+3.594191384462268e-4;
et25 = p.*4.207928569104986e-5-q.*1.652899800142284e-2+r.*2.83488707941543e-3+t4.*4.363635272693571e-5;
et26 = u.*(-7.412140931914926e-1)+v.*1.057129907309279e-5+r.*t15.*4.363635272693571e-5+3.208555347568802e-3;
et27 = t9.*(-1.488363799063303e-3)+t5.*t16.*1.96478931578855e-1-t12.*t16.*2.685898981084329e-4;
et28 = t16.*t45.*2.229255513972545e-2;
et29 = q.*6.940978266385651e-1-r.*3.242241074779526e-4+t7.*7.983067744568586e-6;
et30 = v.*(-5.890830655932608e-5)+w.*5.68699616459184e-3+t17.*u.*7.983067744568586e-6+1.535205335493959e-4;
et31 = p.*(-9.325546942917622e-1)-r.*7.608341180011572e-5+t8.*2.384257345947565e-5;
et32 = u.*(-5.890830655932608e-5)+w.*7.167022390945983e-3+t18.*v.*2.384257345947565e-5+8.722892729076459e-4;
et33 = p.*2.386485122121747e-2+q.*4.042687950231773e-6-r.*1.626901077424079e-4;
et34 = t2.*3.794960966701478e-4-v.*9.325546942917622e-1-w.*9.170377126078081e-5;
et35 = p.*t11.*3.794960966701478e-4+1.136215858293856e-2;
et36 = p.*4.042687950231773e-6+q.*2.386047734684244e-2-r.*9.41018323416786e-4;
et37 = t3.*(-3.975613724574329e-5)+u.*6.940978266385651e-1+w.*9.760289672284637e-5;
et38 = q.*t14.*(-3.975613724574329e-5)-1.391464803601015e-3;
et39 = p.*(-1.626901077424079e-4)-q.*9.41018323416786e-4-r.*2.6641242336162e-6;
et40 = t4.*(-5.388534696211267e-7)-u.*3.242241074779526e-4-v.*7.608341180011572e-5-r.*t15.*5.388534696211267e-7;
et41 = -3.962157864861226e-5;
et42 = t9.*2.76229500271418e-2-t5.*t16.*2.330687970599158e-2+t12.*t16.*2.021387040297739e-1;
et43 = t16.*t45.*(-1.67769453147126e+1);
et44 = q.*3.250645397627224e-2+r.*2.440048651733493e-1-t7.*1.525121428377004e-4;
et45 = v.*4.444624673664884e-2-w.*1.148218101592509e-1-t17.*u.*1.525121428377004e-4;
et46 = -2.932925823801931e-3;
et47 = p.*(-7.167022390945983e-3)+r.*1.45353196782447e-3-t8.*1.794346499283876e-2;
et48 = u.*4.444624673664884e-2-w.*5.393762265858517-t18.*v.*1.794346499283876e-2;
et49 = -6.564682314453203e-1;
et50 = p.*6.901450517184653e-2-q.*1.864649956966199e-3+t10.*1.71795837774031e-3;
et51 = u.*(-1.148218101592509e-1)-v.*5.393762265858517+t19.*w.*1.71795837774031e-3;
et52 = 7.95351100805699e-2;
et53 = p.*1.769281472159728e-4-q.*3.01187450220627e-3+r.*3.285261432418372e-3;
et54 = t2.*(-2.856014136143734e-1)+t54-t55-p.*t11.*2.856014136143734e-1-8.55094052737645;
et55 = p.*(-3.01187450220627e-3)+q.*8.286494635418413e-4-r.*2.91807921220024e-1;
et56 = t3.*8.026859015515944e-4+u.*3.250645397627224e-2-w.*1.864649956966199e-3;
et57 = q.*t14.*8.026859015515944e-4+2.80940065543058e-2;
et58 = p.*3.285261432418372e-3-q.*2.91807921220024e-1-r.*6.346774754713187e-4;
et59 = t4.*4.065642973722228e-4+u.*2.440048651733493e-1+v.*1.45353196782447e-3;
et60 = r.*t15.*4.065642973722228e-4+2.98944336303105e-2;
et61 = t9.*(-2.190238961245431)+t5.*t16.*1.811730301770476e-1-t12.*t16.*9.424383785926009e-4;
et62 = t16.*t45.*7.874348694221141e-2;
et63 = q.*(-5.68699616459184e-3)-r.*1.145088836853196e-3+t7.*1.173897851689236e-2;
et64 = v.*1.791142083314106e-5+w.*8.350290802903371+t17.*u.*1.173897851689236e-2;
et65 = 2.257495868633146e-1;
et66 = p.*1.253868812593498e-3-r.*1.118794885864644e-1+t8.*8.420676957883027e-5+u.*1.791142083314106e-5;
et67 = w.*2.531591064903574e-2+t18.*v.*8.420676957883027e-5+3.080735472396229e-3;
et68 = p.*(-3.238777202130156e-4)+q.*1.43523560675718e-1-t10.*3.005563975778192e-4;
et69 = u.*8.350290802903371+v.*2.531591064903574e-2-t19.*w.*3.005563975778192e-4;
et70 = -1.391464803601015e-2;
et71 = p.*5.100926963153893e-3+q.*7.542822424439259e-5+r.*7.611210069274643e-1;
et72 = t2.*1.340485455591163e-3+v.*1.253868812593498e-3-w.*3.238777202130156e-4;
et73 = p.*t11.*1.340485455591163e-3+4.013429507757972e-2;
et74 = p.*7.542822424439259e-5-q.*1.944664552574166e-4-r.*3.324115892995542e-3;
et75 = t3.*(-5.837445596834167e-2)+t52-t53-q.*t14.*5.837445596834167e-2-2.043105958891958;
et76 = p.*7.611210069274643e-1-q.*3.324115892995542e-3-r.*5.288701994301117e-3;
et77 = t4.*1.638416010492869e-7-u.*1.145088836853196e-3-v.*1.118794885864644e-1+r.*t15.*1.638416010492869e-7;
et78 = 1.204717654774168e-5;
et79 = t9.*3.317560720329222e-1+t5.*t16.*4.801973436589438e-5-t12.*t16.*1.651548560377992e-1;
et80 = t16.*t45.*3.910191918844614e-2;
et81 = q.*(-7.556997281264051e-5)-r.*4.77039452928936e-3-t7.*1.184630250300547e-3;
et82 = v.*(-5.91169722427816)-w.*2.297749951499739e-5-t17.*u.*1.184630250300547e-3;
et83 = -2.278135096731822e-2;
et84 = p.*1.666166625331443e-5+r.*1.129023503850542e-2+t8.*3.508020513341891e-4;
et85 = u.*(-5.91169722427816)+w.*1.257120723021817e-2+t18.*v.*3.508020513341891e-4;
et86 = 1.283422139027521e-2;
et87 = p.*(-1.349261694759633e-3)-q.*1.448357294143097e-2-t10.*3.993855127780116e-6-u.*2.297749951499739e-5;
et88 = v.*1.257120723021817e-2-t19.*w.*3.993855127780116e-6-1.849007003601905e-4;
et89 = p.*(-8.529709629024725e-3)-q.*5.995373902013627e-1-r.*6.894882893880376e-5;
et90 = t2.*6.656493888349138e-4+v.*1.666166625331443e-5-w.*1.349261694759633e-3;
et91 = p.*t11.*6.656493888349138e-4+1.9929622420207e-2;
et92 = p.*(-5.995373902013627e-1)+q.*8.543243474682068e-3+r.*3.011135164017993e-3;
et93 = t3.*1.606290206365557e-7-u.*7.556997281264051e-5-w.*1.448357294143097e-2+q.*t14.*1.606290206365557e-7;
et94 = 5.622015722279451e-6;
et95 = p.*(-6.894882893880376e-5)+q.*3.011135164017993e-3+r.*1.771186243098417e-5;
et96 = t4.*(-5.407622026010442e-2)+t48-t49-r.*t15.*5.407622026010442e-2-3.976192666184148;
mt1 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t38.*v+t42.*w,-t43.*v-t37.*w,t5.*t9.*v-t9.*t12.*w,q.*t5.*t16.*t27-r.*t12.*t16.*t27,-t21-t22,q.*t5.*t27-r.*t12.*t27];
mt2 = [t5.*t9.*2.99207771465984e-4-t9.*t12.*3.113882531703934e-3-t9.*t44.*1.278755659177642e-3];
mt3 = [t5.*t9.*(-2.132281384959919e-1)-t9.*t12.*2.982127378210696e-4-t9.*t44.*2.146651116826197e-1];
mt4 = [t5.*t9.*2.685898981084329e-4+t9.*t12.*1.96478931578855e-1+t9.*t44.*2.229255513972545e-2];
mt5 = [t5.*t9.*(-2.021387040297739e-1)-t9.*t12.*2.330687970599158e-2-t9.*t44.*1.67769453147126e+1];
mt6 = [t5.*t9.*9.424383785926009e-4+t9.*t12.*1.811730301770476e-1+t9.*t44.*7.874348694221141e-2];
mt7 = [t5.*t9.*1.651548560377992e-1+t9.*t12.*4.801973436589438e-5+t9.*t44.*3.910191918844614e-2,-t6.*t16.*u+t9.*t25.*v+t9.*t23.*w,-t13.*t16.*u+t9.*t26.*v+t9.*t24.*w];
mt8 = [-t9.*u-t12.*t16.*v-t5.*t16.*w,t21+t22+t20.*t21.*t28+t20.*t22.*t28,0.0,t16.*t21.*t28+t16.*t22.*t28,et1+et2,et13+et14,et27+et28,et42+et43,et61+et62,et79+et80,-t37.*v+t43.*w-t9.*t13.*u,-t42.*v+t38.*w+t6.*t9.*u,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t6.*t9,t9.*t13,-t16,0.0,0.0,0.0];
mt9 = [t7.*(-3.624306316650479e-2)+t46+t47-t48-t52-t17.*u.*3.624306316650479e-2-6.969819839712459e-1,et15+et16,et29+et30,et44+et45+et46,et63+et64+et65,et81+et82+et83,-t24+t32,t37,t9.*t12,0.0,0.0,0.0,et3+et4];
mt10 = [t8.*(-1.903042325061665e-2)+t46+t49+t51-t54-t18.*v.*1.903042325061665e-2-6.962349969737797e-1,et31+et32,et47+et48+et49,et66+et67,et84+et85+et86,t38,-t25+t31,t5.*t9,0.0,0.0,0.0,et5+et6,et17+et18+et19];
mt11 = [t10.*(-1.616685726098728e-2)+t47+t51+t53+t55-t19.*w.*1.616685726098728e-2-7.484656139345965e-1,et50+et51+et52,et68+et69+et70,et87+et88,0.0,0.0,0.0,1.0,0.0,0.0,et7+et8,et20+et21+et22,et33+et34+et35,et53+et54,et71+et72+et73];
mt12 = [et89+et90+et91,0.0,0.0,0.0,t12.*t16.*t27,t5,t12.*t27,et9+et10,et23+et24,et36+et37+et38,et55+et56+et57,et74+et75,et92+et93+et94,0.0,0.0,0.0,t5.*t16.*t27,-t12,t5.*t27,et11+et12,et25+et26,et39+et40+et41,et58+et59+et60,et76+et77+et78,et95+et96];
Ane = reshape([mt1,mt2,mt3,mt4,mt5,mt6,mt7,mt8,mt9,mt10,mt11,mt12],12,12);
if nargout > 1
    mt13 = [0.0,0.0,0.0,0.0,0.0,0.0,2.112443491058583e-2,-1.528435693367568e-2,-7.083740367225213e-5,6.295222810123954e-2,1.903252229766864e-2];
    mt14 = [-1.723561170848664e-1,0.0,0.0,0.0,0.0,0.0,0.0,2.111254559100193e-2,1.555652319878203e-2,9.371205474517827e-5,-6.088448337462228e-2];
    mt15 = [1.961380565091311e-2,-1.733501214609461e-1,0.0,0.0,0.0,0.0,0.0,0.0,2.179026728440053e-2,-1.556568704794139e-2,-6.736333449122715e-5];
    mt16 = [6.033104706551379e-2,1.903146598627999e-2,1.762813898129492e-1,0.0,0.0,0.0,0.0,0.0,0.0,2.177837796481662e-2,1.527519308451633e-2];
    mt17 = [9.718612392620324e-5,-6.350566441034802e-2,1.961274933952446e-2,1.752873854368695e-1,0.0,0.0,0.0,0.0,0.0,0.0,-1.819638864719295e-3];
    mt18 = [-3.424925181634632e-3,-2.095639900015615e-2,-2.676719354658257e-1,1.059366762359936e-1,6.202181346042057e-4,0.0,0.0,0.0,0.0,0.0,0.0];
    mt19 = [-1.812421155037148e-3,3.387750973601051e-3,2.110031621698574e-2,2.647662125022089e-1,1.053788543694033e-1];
    mt20 = [-6.207996116589e-4,0.0,0.0,0.0,0.0,0.0,0.0,1.853873173346878e-3,3.570812279719345e-3,-2.182294950286063e-2,2.790736050389333e-1];
    mt21 = [-1.079313955363373e-1,-6.467243742662552e-4,0.0,0.0,0.0,0.0,0.0,0.0,1.778186846409557e-3,-3.533638071685763e-3,2.167903228603104e-2];
    mt22 = [-2.761678820753165e-1,-1.033841350690595e-1,6.47305851320949e-4];
    Bne = reshape([mt13,mt14,mt15,mt16,mt17,mt18,mt19,mt20,mt21,mt22],12,8);
end
if nargout > 2
    Cne = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0],[12,12]);
end
if nargout > 3
    Dne = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[12,8]);
end
