%% Einheitliche Einstellungen
fontAxis = 14;
fontLabel = 16;
fontTitle = 18;
fontLegend = 13;
lineWidth = 2;

%% Output
figure('Color','w','Position',[100 100 900 500])

plot(MeasuredData.time, MeasuredData.signals(2).values, ...
    'LineWidth', lineWidth)
hold on

plot(MeasuredDatabad.time, MeasuredDatabad.signals(2).values, ...
    'r', 'LineWidth', lineWidth)

plot(MeasuredData.time, MeasuredData.signals(1).values, ...
    '--k', 'LineWidth', lineWidth)

grid on
box on

title('Output – PID Enhanced vs. Original', ...
    'FontSize', fontTitle, ...
    'FontWeight', 'bold')

xlabel('Time (s)', 'FontSize', fontLabel)
ylabel('Angle (°)', 'FontSize', fontLabel)

ylim([0 100])

legend({'Output Enhanced', ...
         'Output Original', ...
         'Desired Value'}, ...
         'Location', 'southeast', ...
         'FontSize', fontLegend)

ax = gca;
ax.FontSize = fontAxis;
ax.LineWidth = 1.2;

exportgraphics(gcf, 'Output_PID_Comparison.png', 'Resolution', 300)


%% Steady State Error
figure('Color','w','Position',[100 100 900 500])

plot(MeasuredData.time, MeasuredData.signals(3).values, ...
    'LineWidth', lineWidth)
hold on

plot(MeasuredDatabad.time, MeasuredDatabad.signals(3).values, ...
    'r', 'LineWidth', lineWidth)

grid on
box on

title('Steady-State Error – PID Enhanced vs. Original', ...
    'FontSize', fontTitle, ...
    'FontWeight', 'bold')

xlabel('Time (s)', 'FontSize', fontLabel)
ylabel('Error', 'FontSize', fontLabel)

ylim([-20 100])

legend({'Error Enhanced', ...
         'Error Original'}, ...
         'Location', 'northeast', ...
         'FontSize', fontLegend)

ax = gca;
ax.FontSize = fontAxis;
ax.LineWidth = 1.2;

exportgraphics(gcf, 'SteadyStateError_PID_Comparison.png', ...
    'Resolution', 300)