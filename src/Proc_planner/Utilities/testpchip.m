


clear
x = [0	0	0	4	5	4  -4	-5	-4	4		5	4	-4		-5	-4	4	5	4	-5		].';
y = [0	0	0	0	1	2	2	 3	 4	4		5	6	6		7	8	8	9	10	10		].';
t = [0	0.1	6.0	18	25.1 32.3	49.1361470660830	56.3272082620096	63.4182694579363	80.2837503121676		87.4748115080943	94.5658727040209	111.431353558252	118.622414754179	125.713475950106	142.578956804337	149.770018000264	156.861079196190	174.7		]

xt = 0:0.1:174.7
tx  = interp1(t.',x,xt,'pchip');
ty = interp1(t.',y,xt,'pchip');
  
txs  = interp1(t.',x,xt,'linear');
tys = interp1(t.',y,xt,'linear');

txc  = interp1(t.',x,xt,'v5cubic');
tyc = interp1(t.',y,xt,'v5cubic');
plot(tx,ty)

% hold on
% plot(txs,tys)
% plot(txc,tyc)
a = [0,diff(tx)];
b = [0, diff(a)];

plot(xt.',b)

rottraj(quaternion([1 0 0 0]),quaternion([0.707106781186548	0	0	0.707106781186548]),[0,16],0.1:0.1:16)