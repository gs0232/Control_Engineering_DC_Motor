%% 4er Plot: Desired Value, Output, Error, Control Value

t = MeasuredData.time;

fontAxis = 13;
fontLabel = 15;
fontTitle = 16;
fontLegend = 11;
lineWidth = 1.8;

titles = {'Desired Value', 'Output', 'Error', 'Control Value'};
ylabels = {'Angle (°)', 'Angle (°)', 'Error (°)', 'Voltage (V)'};

figure('Color','w','Position',[100 100 1100 750])

for i = 1:4
    subplot(2,2,i)
    hold on
    grid on
    box on

    if i == 1
        plot(t, MeasuredData.signals(i).values, 'k--', 'LineWidth', lineWidth)
        legend({'Desired Value'}, 'Location', 'best', 'FontSize', fontLegend)
    else
        plot(t, MeasuredData.signals(i).values, 'LineWidth', lineWidth)
        plot(t, MeasuredDatabad.signals(i).values, 'r', 'LineWidth', lineWidth)
        legend({'Enhanced','Original'}, 'Location', 'best', 'FontSize', fontLegend)
    end

    title(titles{i}, 'FontSize', fontTitle, 'FontWeight', 'bold')
    xlabel('Time (s)', 'FontSize', fontLabel)
    ylabel(ylabels{i}, 'FontSize', fontLabel)

    set(gca, 'FontSize', fontAxis, 'LineWidth', 1.1)
end

% y-Achse für Control Value automatisch größer setzen
subplot(2,2,4)
controlValues = [MeasuredData.signals(4).values; MeasuredDatabad.signals(4).values];
maxControl = max(abs(controlValues));
ylim([-1.2*maxControl 1.2*maxControl])

sgtitle('PID Enhanced vs. Original', ...
    'FontSize', 20, ...
    'FontWeight', 'bold')

exportgraphics(gcf, 'PID_Comparison_4Plots.png', 'Resolution', 300)