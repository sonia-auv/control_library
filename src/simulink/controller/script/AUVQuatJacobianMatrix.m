function [Anqv,Bnqv,Cnq,Dnq] = AUVQuatJacobianMatrix(in1,in2)
%AUVQUATJACOBIANMATRIX
%    [ANQV,BNQV,CNQ,DNQ] = AUVQUATJACOBIANMATRIX(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.7.
%    05-Sep-2021 14:32:21

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
t8 = sign(p);
t9 = sign(q);
t10 = sign(r);
t11 = sign(u);
t12 = sign(v);
t13 = sign(w);
t14 = epsilon1.^2;
t15 = epsilon2.^2;
t16 = epsilon3.^2;
t17 = epsilon1.*epsilon2.*2.0;
t18 = epsilon1.*epsilon3.*2.0;
t19 = epsilon2.*epsilon3.*2.0;
t20 = epsilon1.*eta.*2.0;
t21 = epsilon2.*eta.*2.0;
t22 = epsilon3.*eta.*2.0;
t23 = epsilon1.*u.*2.0;
t24 = epsilon2.*u.*2.0;
t25 = epsilon3.*u.*2.0;
t26 = eta.*u.*2.0;
t27 = epsilon1.*v.*2.0;
t28 = epsilon2.*v.*2.0;
t29 = epsilon3.*v.*2.0;
t30 = eta.*v.*2.0;
t31 = epsilon1.*w.*2.0;
t32 = epsilon2.*w.*2.0;
t33 = epsilon3.*w.*2.0;
t34 = eta.*w.*2.0;
t38 = sqrt(2.0);
t39 = epsilon1./2.0;
t40 = epsilon2./2.0;
t41 = epsilon3./2.0;
t42 = eta./2.0;
t43 = p./2.0;
t44 = q./2.0;
t45 = r./2.0;
t55 = r.*1.057129907309279e-5;
t56 = q.*9.760289672284637e-5;
t57 = v.*1.129023503850542e-2;
t58 = u.*4.77039452928936e-3;
t59 = p.*9.170377126078081e-5;
t61 = w.*1.43523560675718e-1;
t62 = u.*5.68699616459184e-3;
t65 = w.*6.901450517184653e-2;
t68 = v.*7.167022390945983e-3;
t35 = t14.*2.0;
t36 = t15.*2.0;
t37 = t16.*2.0;
t49 = -t39;
t50 = -t40;
t51 = -t41;
t52 = -t43;
t53 = -t44;
t54 = -t45;
t60 = -t59;
t63 = t38.*1.517111971060688e-2;
t64 = t38.*5.925549487801743e-4;
t66 = t38.*4.886926387591695e-5;
t67 = t38.*1.090649593858282e-2;
t69 = t38.*1.345765452672799e-2;
t72 = t38.*4.359319882537525e-2;
t46 = -t35;
t47 = -t36;
t48 = -t37;
et1 = p.*(-2.151948492273065e-5)+r.*1.345418075860736-t6.*7.773850521878333e-7-u.*1.129023503850542e-2;
et2 = w.*(-4.111179891417293e-4)-t12.*v.*7.773850521878333e-7-1.422045827172866e-5;
et3 = p.*2.989993556213668e-6-q.*1.443116363827266+t7.*5.158289927259702e-6-u.*1.43523560675718e-1;
et4 = v.*(-4.111179891417293e-4)+t13.*w.*5.158289927259702e-6+1.194048594273079e-4;
et5 = p.*(-1.039636542482752e-4)-q.*3.056030135457876e-3-r.*3.027000926212141e-2-t2.*2.176882722555211e-5;
et6 = v.*(-2.151948492273065e-5)+w.*2.989993556213668e-6-p.*t8.*2.176882722555211e-5-3.258806470891034e-4;
et7 = p.*(-3.056030135457876e-3)+q.*1.929418735906703e-3+r.*6.288494148926307e-5+t3.*1.003331497170287e-3;
et8 = u.*9.760289672284637e-5-w.*1.443116363827266+q.*t9.*1.003331497170287e-3+1.755830120048002e-2;
et9 = p.*(-3.027000926212141e-2)+q.*6.288494148926307e-5+r.*2.000695949098431e-3-t4.*1.032754577185093e-4;
et10 = u.*1.057129907309279e-5+v.*1.345418075860736-r.*t10.*1.032754577185093e-4-3.79689182788637e-3;
et11 = q.*4.159278787387334e-4-r.*7.412140931914926e-1-t5.*1.109195745194835e-6;
et12 = v.*4.77039452928936e-3-w.*1.468966557066211e-3-t11.*u.*1.109195745194835e-6-1.066534370379649e-5;
et13 = p.*1.073195185231853-q.*1.356129262930646e-5+t7.*2.198168967727268e-5;
et14 = u.*(-1.468966557066211e-3)-v.*6.901450517184653e-2+t13.*w.*2.198168967727268e-5;
et15 = 5.088354091961268e-4;
et16 = p.*2.8513455484883e-3-q.*3.231634295066181e-4+r.*4.207928569104986e-5-t2.*3.654339821712283e-3;
et17 = v.*(-9.170377126078081e-5)+w.*1.073195185231853-p.*t8.*3.654339821712283e-3;
et18 = -5.470568595377669e-2;
et19 = p.*(-3.231634295066181e-4)+q.*4.529247630233296e-6-r.*1.652899800142284e-2+t3.*1.026911824132076e-5;
et20 = u.*4.159278787387334e-4-w.*1.356129262930646e-5+q.*t9.*1.026911824132076e-5+1.797095692231134e-4;
et21 = p.*4.207928569104986e-5-q.*1.652899800142284e-2+r.*2.83488707941543e-3+t4.*4.363635272693571e-5;
et22 = u.*(-7.412140931914926e-1)+v.*1.057129907309279e-5+r.*t10.*4.363635272693571e-5+1.604277673784401e-3;
et23 = q.*6.940978266385651e-1-r.*3.242241074779526e-4+t5.*7.983067744568586e-6;
et24 = v.*(-5.890830655932608e-5)+w.*5.68699616459184e-3+t11.*u.*7.983067744568586e-6+7.676026677469795e-5;
et25 = p.*(-9.325546942917622e-1)-r.*7.608341180011572e-5+t6.*2.384257345947565e-5;
et26 = u.*(-5.890830655932608e-5)+w.*7.167022390945983e-3+t12.*v.*2.384257345947565e-5+4.361446364538229e-4;
et27 = p.*2.386485122121747e-2+q.*4.042687950231773e-6-r.*1.626901077424079e-4;
et28 = t2.*3.794960966701478e-4-v.*9.325546942917622e-1-w.*9.170377126078081e-5;
et29 = p.*t8.*3.794960966701478e-4+5.681079291469279e-3;
et30 = p.*4.042687950231773e-6+q.*2.386047734684244e-2-r.*9.41018323416786e-4;
et31 = t3.*(-3.975613724574329e-5)+u.*6.940978266385651e-1+w.*9.760289672284637e-5;
et32 = q.*t9.*(-3.975613724574329e-5)-6.957324018005075e-4;
et33 = p.*(-1.626901077424079e-4)-q.*9.41018323416786e-4-r.*2.6641242336162e-6;
et34 = t4.*(-5.388534696211267e-7)-u.*3.242241074779526e-4-v.*7.608341180011572e-5-r.*t10.*5.388534696211267e-7;
et35 = -1.981078932430613e-5;
et36 = q.*3.250645397627224e-2+r.*2.440048651733493e-1-t5.*1.525121428377004e-4;
et37 = v.*4.444624673664884e-2-w.*1.148218101592509e-1-t11.*u.*1.525121428377004e-4;
et38 = -1.466462911900965e-3;
et39 = p.*(-7.167022390945983e-3)+r.*1.45353196782447e-3-t6.*1.794346499283876e-2;
et40 = u.*4.444624673664884e-2-w.*5.393762265858517-t12.*v.*1.794346499283876e-2;
et41 = -3.282341157226602e-1;
et42 = p.*6.901450517184653e-2-q.*1.864649956966199e-3+t7.*1.71795837774031e-3;
et43 = u.*(-1.148218101592509e-1)-v.*5.393762265858517+t13.*w.*1.71795837774031e-3;
et44 = 3.976755504028495e-2;
et45 = p.*1.769281472159728e-4-q.*3.01187450220627e-3+r.*3.285261432418372e-3;
et46 = t2.*(-2.856014136143734e-1)+t65-t68-p.*t8.*2.856014136143734e-1-4.275470263688225;
et47 = p.*(-3.01187450220627e-3)+q.*8.286494635418413e-4-r.*2.91807921220024e-1;
et48 = t3.*8.026859015515944e-4+u.*3.250645397627224e-2-w.*1.864649956966199e-3;
et49 = q.*t9.*8.026859015515944e-4+1.40470032771529e-2;
et50 = p.*3.285261432418372e-3-q.*2.91807921220024e-1-r.*6.346774754713187e-4;
et51 = t4.*4.065642973722228e-4+u.*2.440048651733493e-1+v.*1.45353196782447e-3;
et52 = r.*t10.*4.065642973722228e-4+1.494721681515525e-2;
et53 = q.*(-5.68699616459184e-3)-r.*1.145088836853196e-3+t5.*1.173897851689236e-2;
et54 = v.*1.791142083314106e-5+w.*8.350290802903371+t11.*u.*1.173897851689236e-2+1.128747934316573e-1;
et55 = p.*1.253868812593498e-3-r.*1.118794885864644e-1+t6.*8.420676957883027e-5+u.*1.791142083314106e-5;
et56 = w.*2.531591064903574e-2+t12.*v.*8.420676957883027e-5+1.540367736198115e-3;
et57 = p.*(-3.238777202130156e-4)+q.*1.43523560675718e-1-t7.*3.005563975778192e-4;
et58 = u.*8.350290802903371+v.*2.531591064903574e-2-t13.*w.*3.005563975778192e-4;
et59 = -6.957324018005075e-3;
et60 = p.*5.100926963153893e-3+q.*7.542822424439259e-5+r.*7.611210069274643e-1;
et61 = t2.*1.340485455591163e-3+v.*1.253868812593498e-3-w.*3.238777202130156e-4;
et62 = p.*t8.*1.340485455591163e-3+2.006714753878986e-2;
et63 = p.*7.542822424439259e-5-q.*1.944664552574166e-4-r.*3.324115892995542e-3;
et64 = t3.*(-5.837445596834167e-2)+t61-t62-q.*t9.*5.837445596834167e-2-1.021552979445979;
et65 = p.*7.611210069274643e-1-q.*3.324115892995542e-3-r.*5.288701994301117e-3;
et66 = t4.*1.638416010492869e-7-u.*1.145088836853196e-3-v.*1.118794885864644e-1+r.*t10.*1.638416010492869e-7;
et67 = 6.02358827387084e-6;
et68 = q.*(-7.556997281264051e-5)-r.*4.77039452928936e-3-t5.*1.184630250300547e-3;
et69 = v.*(-5.91169722427816)-w.*2.297749951499739e-5-t11.*u.*1.184630250300547e-3;
et70 = -1.139067548365911e-2;
et71 = p.*1.666166625331443e-5+r.*1.129023503850542e-2+t6.*3.508020513341891e-4;
et72 = u.*(-5.91169722427816)+w.*1.257120723021817e-2+t12.*v.*3.508020513341891e-4;
et73 = 6.417110695137605e-3;
et74 = p.*(-1.349261694759633e-3)-q.*1.448357294143097e-2-t7.*3.993855127780116e-6-u.*2.297749951499739e-5;
et75 = v.*1.257120723021817e-2-t13.*w.*3.993855127780116e-6-9.245035018009527e-5;
et76 = p.*(-8.529709629024725e-3)-q.*5.995373902013627e-1-r.*6.894882893880376e-5;
et77 = t2.*6.656493888349138e-4+v.*1.666166625331443e-5-w.*1.349261694759633e-3;
et78 = p.*t8.*6.656493888349138e-4+9.9648112101035e-3;
et79 = p.*(-5.995373902013627e-1)+q.*8.543243474682068e-3+r.*3.011135164017993e-3;
et80 = t3.*1.606290206365557e-7-u.*7.556997281264051e-5-w.*1.448357294143097e-2+q.*t9.*1.606290206365557e-7;
et81 = 2.811007861139725e-6;
et82 = p.*(-6.894882893880376e-5)+q.*3.011135164017993e-3+r.*1.771186243098417e-5;
et83 = t4.*(-5.407622026010442e-2)+t57-t58-r.*t10.*5.407622026010442e-2-1.988096333092074;
mt1 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-t29+t32,t25-t31,-t24+t27,0.0,t43,t44,t45,epsilon1.*(-3.369912934691789e-4)+epsilon2.*3.395397974403745e-1];
mt2 = [epsilon1.*(-3.578279099157842e-1)+epsilon2.*2.319495115225023e-4];
mt3 = [epsilon1.*1.672127054596356e-2-epsilon2.*2.933280176862403e-3];
mt4 = [epsilon1.*(-1.258411063951611e+1)+epsilon2.*5.444121790623427e-2];
mt5 = [epsilon1.*5.905171449819092e-2-epsilon2.*4.316538442631601];
mt6 = [epsilon1.*3.550080926737473e-1+epsilon2.*6.535994347392862e-1,t28+t33,t24-t34-epsilon1.*v.*4.0,t25+t30-epsilon1.*w.*4.0,t52,0.0,t54,t44];
mt7 = [epsilon1.*(-1.263905936484723e-2)-epsilon3.*3.395397974403745e-1-eta.*3.369912934691789e-4];
mt8 = [epsilon1.*(-5.386046241846134e-2)-epsilon3.*2.319495115225023e-4-eta.*3.578279099157842e-1];
mt9 = [epsilon1.*3.727149784270437e-1+epsilon3.*2.933280176862403e-3+eta.*1.672127054596356e-2];
mt10 = [epsilon1.*(-4.209414016813798)-epsilon3.*5.444121790623427e-2-eta.*1.258411063951611e+1];
mt11 = [epsilon1.*7.364359516504992e-1+epsilon3.*4.316538442631601+eta.*5.905171449819092e-2];
mt12 = [epsilon1.*9.785912146552939e-3-epsilon3.*6.535994347392862e-1+eta.*3.550080926737473e-1,t27+t34-epsilon2.*u.*4.0,t23+t33,-t26+t29-epsilon2.*w.*4.0,t53,t45,0.0,t52];
mt13 = [epsilon2.*(-1.263905936484723e-2)-epsilon3.*3.369912934691789e-4+eta.*3.395397974403745e-1];
mt14 = [epsilon2.*(-5.386046241846134e-2)-epsilon3.*3.578279099157842e-1+eta.*2.319495115225023e-4];
mt15 = [epsilon2.*3.727149784270437e-1+epsilon3.*1.672127054596356e-2-eta.*2.933280176862403e-3];
mt16 = [epsilon2.*(-4.209414016813798)-epsilon3.*1.258411063951611e+1+eta.*5.444121790623427e-2];
mt17 = [epsilon2.*7.364359516504992e-1+epsilon3.*5.905171449819092e-2-eta.*4.316538442631601];
mt18 = [epsilon2.*9.785912146552939e-3+epsilon3.*3.550080926737473e-1+eta.*6.535994347392862e-1,-t30+t31-epsilon3.*u.*4.0,t26+t32-epsilon3.*v.*4.0,t23+t28,t54,t53,t43,0.0];
mt19 = [epsilon1.*(-3.395397974403745e-1)-epsilon2.*3.369912934691789e-4];
mt20 = [epsilon1.*(-2.319495115225023e-4)-epsilon2.*3.578279099157842e-1];
mt21 = [epsilon1.*2.933280176862403e-3+epsilon2.*1.672127054596356e-2];
mt22 = [epsilon1.*(-5.444121790623427e-2)-epsilon2.*1.258411063951611e+1];
mt23 = [epsilon1.*4.316538442631601+epsilon2.*5.905171449819092e-2];
mt24 = [epsilon1.*(-6.535994347392862e-1)+epsilon2.*3.550080926737473e-1,t47+t48+1.0,t17+t22,t18-t21,0.0,0.0,0.0,0.0];
mt25 = [t5.*(-3.624306316650479e-2)+t55+t56-t57-t61-t11.*u.*3.624306316650479e-2-3.484909919856229e-1,et11+et12,et23+et24,et36+et37+et38,et53+et54,et68+et69+et70,t17-t22,t46+t48+1.0,t19+t20,0.0,0.0,0.0];
mt26 = [0.0,et1+et2,t6.*(-1.903042325061665e-2)+t55+t58+t60-t65-t12.*v.*1.903042325061665e-2-3.481174984868899e-1,et25+et26,et39+et40+et41,et55+et56,et71+et72+et73,t18+t21,t19-t20,t46+t47+1.0,0.0,0.0,0.0,0.0,et3+et4];
mt27 = [et13+et14+et15,t7.*(-1.616685726098728e-2)+t56+t60+t62+t68-t13.*w.*1.616685726098728e-2-3.742328069672983e-1,et42+et43+et44,et57+et58+et59,et74+et75,0.0,0.0,0.0,t49,t42,t41,t50,et5+et6,et16+et17+et18,et27+et28+et29,et45+et46];
mt28 = [et60+et61+et62,et76+et77+et78,0.0,0.0,0.0,t50,t51,t42,t39,et7+et8,et19+et20,et30+et31+et32,et47+et48+et49,et63+et64,et79+et80+et81,0.0,0.0,0.0,t51,t40,t49,t42,et9+et10,et21+et22,et33+et34+et35,et50+et51+et52,et65+et66+et67,et82+et83];
Anqv = reshape([mt1,mt2,mt3,mt4,mt5,mt6,mt7,mt8,mt9,mt10,mt11,mt12,mt13,mt14,mt15,mt16,mt17,mt18,mt19,mt20,mt21,mt22,mt23,mt24,mt25,mt26,mt27,mt28],13,13);
if nargout > 1
    t70 = -t66;
    t71 = -t67;
    mt29 = [0.0,0.0,0.0,0.0,0.0,0.0,0.0,t63-3.307683405402052e-4];
    mt30 = [t71+1.397575406352208e-4];
    mt31 = [t70-1.725827915740819e-6];
    mt32 = [t72+1.302135095166983e-3];
    mt33 = [t69+5.247482382331681e-7];
    mt34 = [t64-1.731941163298826e-1,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt35 = [t38.*1.492882415550761e-2+1.859578044455023e-21];
    mt36 = [t38.*1.100012304554462e-2+7.924461028811397e-21];
    mt37 = [t38.*6.626442938924465e-5-5.828197568247432e-18];
    mt38 = [t38.*(-4.305183106323503e-2)+6.193288329240141e-19];
    mt39 = [t38.*1.386905498063568e-2-1.083514276897426e-19];
    mt40 = [t38.*(-1.225770464045467e-1)-1.439796020209256e-21,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt41 = [t63+3.350640332744937e-4];
    mt42 = [t71-1.415725736304834e-4];
    mt43 = [t70+1.748241265284163e-6];
    mt44 = [t72-1.31904594055876e-3];
    mt45 = [t69-5.315631504182326e-7];
    mt46 = [t64+1.75443390567933e-1,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt47 = [t38.*1.516372519659284e-2+3.336321356963975e-4];
    mt48 = [t38.*1.090087173345982e-2-1.409675626320625e-4];
    mt49 = [t38.*6.749005688877506e-5+1.740770148765829e-6];
    mt50 = [t38.*(-4.397656554353263e-2)-1.313408992094834e-3];
    mt51 = [t38.*1.386868232130781e-2-5.292915130232833e-7];
    mt52 = [t38.*4.198467360829836e-4+1.746936324885829e-1,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt53 = [-1.819638864719295e-3,-3.424925181634632e-3,-2.095639900015615e-2];
    mt54 = [-2.676719354658257e-1,1.059366762359936e-1,6.202181346042057e-4,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt55 = [-1.812421155037148e-3];
    mt56 = [3.387750973601051e-3];
    mt57 = [2.110031621698574e-2];
    mt58 = [2.647662125022089e-1];
    mt59 = [1.053788543694033e-1];
    mt60 = [-6.207996116589e-4,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.853873173346878e-3];
    mt61 = [3.570812279719344e-3,-2.182294950286063e-2,2.790736050389333e-1];
    mt62 = [-1.079313955363373e-1,-6.467243742662552e-4,0.0,0.0,0.0,0.0,0.0,0.0,0.0];
    mt63 = [1.778186846409557e-3];
    mt64 = [-3.533638071685763e-3];
    mt65 = [2.167903228603104e-2];
    mt66 = [-2.761678820753165e-1];
    mt67 = [-1.033841350690595e-1];
    mt68 = [6.473058513209489e-4];
    Bnqv = reshape([mt29,mt30,mt31,mt32,mt33,mt34,mt35,mt36,mt37,mt38,mt39,mt40,mt41,mt42,mt43,mt44,mt45,mt46,mt47,mt48,mt49,mt50,mt51,mt52,mt53,mt54,mt55,mt56,mt57,mt58,mt59,mt60,mt61,mt62,mt63,mt64,mt65,mt66,mt67,mt68],13,8);
end
if nargout > 2
    Cnq = reshape([1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0],[13,13]);
end
if nargout > 3
    Dnq = reshape([0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0],[13,8]);
end
