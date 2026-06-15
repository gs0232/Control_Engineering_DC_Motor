%% Plot raw measurement data

%load('measurement_data.mat');

% Daten extrahieren
t     = raw_data_new(:,1);
U_in  = raw_data_new(:,2);
U_out = raw_data_new(:,3);

% Formatierung
fontAxis  = 13;
fontLabel = 15;
fontTitle = 16;
fontLegend = 11;
lineWidth = 1.8;

% Plot
figure('Color','w','Position',[100 100 900 500])

hold on
grid on
box on

plot(t, U_in, ...
    'LineWidth', lineWidth, ...
    'Color', [0.2, 0.6, 0.8])

plot(t, U_out, ...
    'LineWidth', lineWidth, ...
    'Color', [0.85, 0.33, 0.1])

% Titel und Beschriftung
title('Raw Measurement Data', ...
    'FontSize', fontTitle, ...
    'FontWeight', 'bold')

xlabel('Time (s)', ...
    'FontSize', fontLabel)

ylabel('Voltage (V)', ...
    'FontSize', fontLabel)

% Achsenbegrenzungen
xlim([0 2.45])
ylim([0 27])

% Achsen formatieren
set(gca, ...
    'FontSize', fontAxis, ...
    'LineWidth', 1.1)

% Legende
legend({'U_{in}', 'U_{out}'}, ...
    'Location', 'southeast', ...
    'FontSize', fontLegend)

% Export
exportgraphics(gcf, ...
    'RawMeasurementData.png', ...
    'Resolution', 300)