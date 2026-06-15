t = resp_12V.time(:,1);
y = resp_12V.signals(1).values(:,1);
y = y/9.55;

x0 = [25 0.004 0.005];
X = lsqcurvefit(@PT2, x0, t, y)
sys_speed = tf(X(1), conv([X(2) 1],[X(3) 1]))

step(sys_speed * 12)
hold on
plot(t, y, 'r')

sys_s = tf([1], [1 0])

sys_pos = series(sys_speed, sys_s)

figure;
rlocus(sys_pos); % Gain 62, P.O. 100%