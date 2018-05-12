TFpid = tf([2.7, 40, 1.85], [1, 0]);

sys = c2d(TFpid, 0.001,'tunstin')

integrator = tf([1], [1,0])

sys2 = c2d(integrator, 0.02,'tunstin')

TF = tf([1], [49.5, 136.1473])

sys3 = c2d(TF, 0.02,'tunstin')


step(sys3)

% integrator = tf([200], [1,3,4])
% 
% sys2 = c2d(integrator, 0.02,'tunstin')