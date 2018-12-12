tfPosition = tf([1], [1, 0])
tfVelocity = tf([10], [2, 1])

[p, v, a] = TrajectoryGenerator();

for i = 1:length(v)
    
    commandPosition(i) = evalfr(tfPosition, p(i));
    commandVelocity(i) = evalfr(tfVelocity, p(i));
    
end

plot(commandPosition)