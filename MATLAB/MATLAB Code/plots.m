figure % Output
plot(MeasuredData.time,MeasuredData.signals(2).values)
title('Output - PID Enhanced vs. Original')
ylabel('Degrees in °')
xlabel('Time in s')
ylim([0 100])
hold on
plot(MeasuredDatabad.time,MeasuredDatabad.signals(2).values, 'r')
hold on
plot(MeasuredData.time,MeasuredData.signals(1).values)
grid on
legend('Output Enhanced', 'Output Original', 'Desired Value', 'Location', 'southeast')

figure % Steady State Error
plot(MeasuredData.time,MeasuredData.signals(3).values)
title('Steady State Error - PID Enhanced vs. Original')
ylabel('Degrees in °')
xlabel('Time in s')
ylim([-20 100])
hold on
plot(MeasuredDatabad.time,MeasuredDatabad.signals(3).values, 'r')
grid on
legend('Error Enhanced', 'Error Original', 'Location', 'northeast')
