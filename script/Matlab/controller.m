TFpid = tf([2.7, 40, 1.85], [1, 0]);

sys = c2d(TFpid, 0.02,'tunstin');