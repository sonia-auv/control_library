function out1 = AUVQuatSimFcn(in1,in2)
%AUVQUATSIMFCN
%    OUT1 = AUVQUATSIMFCN(IN1,IN2)

%    This function was generated by the Symbolic Math Toolbox version 8.5.
%    09-Mar-2021 20:15:34

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
t11 = p.^2;
t12 = q.^2;
t13 = r.^2;
t14 = epsilon1.*epsilon2.*2.0;
t15 = epsilon1.*epsilon3.*2.0;
t16 = epsilon2.*epsilon3.*2.0;
t17 = epsilon1.*eta.*2.0;
t18 = epsilon2.*eta.*2.0;
t19 = epsilon3.*eta.*2.0;
t23 = sqrt(2.0);
t24 = 6.83593446428504e+1;
t25 = 3.37017803684019e+2;
t26 = 3.387462176910615e+2;
t27 = 3.400838131990407e+2;
t20 = t8.*2.0;
t21 = t9.*2.0;
t22 = t10.*2.0;
out1 = [-u.*(t21+t22-1.0)+w.*(t15+t18)+v.*(t14-t19);u.*(t14+t19)-v.*(t20+t22-1.0)+w.*(t16-t17);v.*(t16+t17)-w.*(t20+t21-1.0)+u.*(t15-t18);epsilon1.*p.*(-1.0./2.0)-(epsilon2.*q)./2.0-(epsilon3.*r)./2.0;(eta.*p)./2.0-(epsilon3.*q)./2.0+(epsilon2.*r)./2.0;(epsilon3.*p)./2.0+(eta.*q)./2.0-(epsilon1.*r)./2.0;epsilon2.*p.*(-1.0./2.0)+(epsilon1.*q)./2.0+(eta.*r)./2.0;U5.*2.73535501881162e-3+U6.*2.784726684729089e-3-U7.*2.795765795200637e-3-U8.*2.724315908340073e-3-p.*3.471418387278981e-4+q.*1.064478565421073e-1+r.*3.069162903790487e-2-t8.*1.094172245345473e-2-t9.*1.094172245345473e-2+t11.*1.338284063083145e-4+t12.*1.002523537952999e-3+t13.*8.616019471361592e-4-u.*1.344231176255995-v.*1.79003494025539e-4+w.*1.057188586807788e-3+U1.*t23.*1.451717689482891e-2+U2.*t23.*1.4518251006283e-2+U2.*t24.*1.023054301263496e-5+U3.*t23.*1.451717689482891e-2+U4.*t23.*1.4518251006283e-2+U1.*t27.*2.046108602526991e-6-U3.*t26.*2.046108602526991e-6-U4.*t25.*2.046108602526991e-6-epsilon1.*epsilon3.*3.123484310179862-epsilon2.*epsilon3.*4.676433128799746e-3-epsilon1.*eta.*4.676433128799746e-3+epsilon2.*eta.*3.123484310179862+p.*q.*2.504890687107359e-3-p.*r.*2.815211812769402e-2-q.*r.*1.11686502528595e-5-p.*t2.*8.447084287239883e-4+q.*t3.*2.215757754433911e-1+r.*t4.*2.291142384331214e-2-q.*w+r.*v-t5.*u.*2.092806633689434-t6.*v.*2.685637155130234e-4+t7.*w.*1.663641013751162e-3+5.470861226727363e-3;U5.*3.022939073570411e-3-U6.*3.019956810914758e-3-U7.*2.803229072445781e-3+U8.*2.800246809790128e-3-p.*1.83119052935866e-1+q.*5.750919721645535e-5+r.*1.241552255248743e-2+t8.*3.979432141499523e-2+t9.*3.979432141499523e-2-t11.*3.001665079238482e-3+t12.*1.42828353331662e-4-t13.*3.141990975596679e-3-u.*1.21721656489243e-4-v.*1.797019808754185-w.*3.844925019681022e-3-U1.*t23.*1.44704611435171e-2+U2.*t23.*1.447271421123873e-2+U2.*t24.*4.13850751749581e-6-U3.*t23.*1.44704611435171e-2+U4.*t23.*1.447271421123873e-2+U1.*t27.*8.27701503499162e-7-U3.*t26.*8.27701503499162e-7-U4.*t25.*8.27701503499162e-7-epsilon1.*epsilon3.*2.554896966017485e-3-epsilon2.*epsilon3.*3.405334164761517-epsilon1.*eta.*3.405334164761517+epsilon2.*eta.*2.554896966017485e-3-p.*q.*1.08168853188676e-3-p.*r.*4.551735686201773e-5-q.*r.*3.384927381565835e-2-p.*t2.*4.45587913118492e-1+q.*t3.*1.197078586859325e-4+r.*t4.*9.268237247522076e-3+p.*w-r.*u-t5.*u.*1.895060125549727e-4-t6.*v.*2.696116739602138-t7.*w.*6.050552415490969e-3-1.989716070749762e-2;U5.*2.968965367561718e-2-U6.*2.98937697836014e-2+U7.*2.924715798583806e-2-U8.*2.904304187785385e-2-p.*2.033370433218037e-2-q.*3.936123294461407e-3+r.*2.427755044280526e-4+t8.*1.724683099452803+t9.*1.724683099452803+t11.*2.699485838355468e-2+t12.*2.701577635266822e-2-t13.*1.065092125652584e-5+u.*6.810135637130917e-4-v.*3.295031203830933e-3-w.*2.062322039127013+U1.*t23.*3.635561768760388e-5-U2.*t23.*2.056256940887264e-5+U2.*t24.*8.09251681426842e-8+U3.*t23.*3.635561768760388e-5-U4.*t23.*2.056256940887264e-5+U1.*t27.*1.618503362853684e-8-U3.*t26.*1.618503362853684e-8-U4.*t25.*1.618503362853684e-8+epsilon1.*epsilon3.*5.170234666952211e-2-epsilon2.*epsilon3.*1.871021216126523e-1-epsilon1.*eta.*1.871021216126523e-1-epsilon2.*eta.*5.170234666952211e-2+p.*q.*9.260878416013351e-6-p.*r.*9.623864423293344e-4+q.*r.*2.23938322975103e-3-p.*t2.*4.947848262691675e-2-q.*t3.*8.193209328419752e-3-p.*v+q.*u+r.*t4.*1.81232885157559e-4+t5.*u.*1.060256397073638e-3-t6.*v.*4.943623182606318e-3-t7.*w.*3.245365652512883-8.623415497264016e-1;U5.*1.119353063894791e-1-U6.*1.118131314036241e-1-U7.*1.038002968858081e-1+U8.*1.036781218999531e-1-p.*6.780296487089063+q.*2.3559914627694e-3+r.*7.658056901715328e-2+t8.*1.473429435374185+t9.*1.473429435374185-t11.*7.673539591625989e-6+t12.*5.260321229343025e-3-t13.*5.257753061019209e-3-u.*1.098157925049354e-3-v.*1.098714353184497-w.*1.423626663142426e-1+U1.*t23.*9.492808470266959e-3-U2.*t23.*9.486916322314606e-3+U2.*t24.*2.552685633905109e-5+U3.*t23.*9.492808470266959e-3-U4.*t23.*9.486916322314606e-3+U1.*t27.*5.105371267810219e-6-U3.*t26.*5.105371267810219e-6-U4.*t25.*5.105371267810219e-6-epsilon1.*epsilon3.*4.206416447385742e-2-epsilon2.*epsilon3.*6.238920081899846e+1-epsilon1.*eta.*6.238920081899846e+1+epsilon2.*eta.*4.206416447385742e-2+p.*q.*4.6311642503843e-3-p.*r.*1.48983003430088e-3-q.*r.*2.53838130756937e-1-p.*t2.*1.649865545703091e+1+q.*t3.*4.904097200817196e-3+r.*t4.*5.716770109358099e-2-t5.*u.*1.709700110350838e-3-t6.*v.*1.648430443132119-t7.*w.*2.240284973398092e-1-7.367147176870926e-1;U5.*(-1.012332450240073e-1)-U6.*1.032493879177708e-1+U7.*1.034778750227315e-1+U8.*1.010047579190466e-1+p.*7.185129086813314e-3-q.*3.943191268849715+r.*1.303379737659277e-2+t8.*4.065519419678304e-1+t9.*4.065519419678304e-1-t11.*5.118595826549551e-3-t12.*4.611019807341635e-6+t13.*5.122337926531786e-3+u.*6.843080374882397e-1+v.*1.111855722557386e-3-w.*3.928102497767407e-2+U1.*t23.*7.877192276802997e-3+U2.*t23.*7.898179558071181e-3+U2.*t24.*4.344599125530923e-6+U3.*t23.*7.877192276802997e-3+U4.*t23.*7.898179558071181e-3+U1.*t27.*8.689198251061846e-7-U3.*t26.*8.689198251061846e-7-U4.*t25.*8.689198251061846e-7+epsilon1.*epsilon3.*5.182853916294368e+1+epsilon2.*epsilon3.*6.548084434307431e-2+epsilon1.*eta.*6.548084434307431e-2-epsilon2.*eta.*5.182853916294368e+1-p.*q.*4.632614335139548e-3+p.*r.*4.208304777356821e-2+q.*r.*8.976220218405162e-4+p.*t2.*1.748374417598929e-2-q.*t3.*8.207921620022204+r.*t4.*9.729781876816008e-3+t5.*u.*1.065385497404691+t6.*v.*1.668146790038781e-3-t7.*w.*6.181444354442688e-2-2.032759709839152e-1;U5.*(-6.85801054474782e-4)+U6.*1.002263016907581e-3+U7.*6.210565289621675e-4-U8.*9.37518491394967e-4+p.*5.104778446131286e-2+q.*6.102572278318447e-3-r.*1.034784718902429e+1-t8.*1.172665989223154e-2-t9.*1.172665989223154e-2+t11.*1.457893669507799e-3-t12.*7.996801394003562e-4+t13.*3.164294916084318e-5+u.*9.207139251291049e-2+v.*4.966112983882985e-2+w.*1.133029196470755e-3-U1.*t23.*7.73528522070761e-4-U2.*t23.*1.320451204847371e-3-U2.*t24.*3.44928239634143e-3-U3.*t23.*7.73528522070761e-4-U4.*t23.*1.320451204847371e-3-U1.*t27.*6.898564792682861e-4+U3.*t26.*6.898564792682861e-4+U4.*t25.*6.898564792682861e-4+epsilon1.*epsilon3.*1.419164525223335+epsilon2.*epsilon3.*9.6948344384558e-1+epsilon1.*eta.*9.6948344384558e-1-epsilon2.*eta.*1.419164525223335+p.*q.*2.067299666471362e-1+p.*r.*5.291945935893979e-3-q.*r.*4.355714778944812e-3+p.*t2.*1.242157786574259e-1+q.*t3.*1.270276573613178e-2-r.*t4.*7.724709317995389+t5.*u.*1.433441095755001e-1+t6.*v.*7.450791739399212e-2+t7.*w.*1.782987316121096e-3+5.863329946115769e-3];
