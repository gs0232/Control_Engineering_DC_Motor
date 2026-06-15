%% PT2 Systemidentifikation - Messdaten measurement_data.mat

clear; clc; close all;

%% 1. Daten laden
load('measurement_data.mat');   % enthält raw_data_new

t     = raw_data_new(:,1);
U_in  = raw_data_new(:,2);
U_out = raw_data_new(:,3);

%% 2. Sprunghöhe und Modellfunktion
U_step = U_in(end) - U_in(1);

pt2_model = @(p, t) p(1) * U_step * ...
    (1 - (p(2)*exp(-t/p(2)) - p(3)*exp(-t/p(3))) ./ ...
    (p(2) - p(3) + eps));

%% 3. Fit mit lsqcurvefit
p0 = [5, 0.3, 0.1];        % Startwerte: K, T1, T2
lb = [0, 0, 0];            % untere Grenzen
ub = [10, 5, 5];           % obere Grenzen

p_opt = lsqcurvefit(pt2_model, p0, t, U_out, lb, ub);

%% 4. Identifizierte Parameter
T = sort(p_opt(2:3), 'descend');
K = p_opt(1);

G_ident = tf(K, conv([T(1) 1], [T(2) 1]));

disp('Identifizierte Übertragungsfunktion:')
G_ident

fprintf('K  = %.4f\n', K);
fprintf('T1 = %.4f s\n', T(1));
fprintf('T2 = %.4f s\n', T(2));

%% 5. Vergleich Messung vs. Modell
U_out_model = pt2_model(p_opt, t);

%% 6. Plot-Formatierung
fontAxis   = 13;
fontLabel  = 15;
fontTitle  = 16;
fontLegend = 11;
lineWidth  = 1.8;

%% 7. Plot erstellen
figure('Color','w','Position',[100 100 900 500])

hold on
grid on
box on

plot(t, U_in, ...
    'k--', ...
    'LineWidth', lineWidth)

plot(t, U_out, ...
    'Color', [0.2, 0.6, 0.8], ...
    'LineWidth', lineWidth)

plot(t, U_out_model, ...
    'Color', [0.85, 0.33, 0.1], ...
    'LineWidth', lineWidth)

xlim([0 4])
ylim([0 29])

title('Step Response: Measurement vs. PT2 Model', ...
    'FontSize', fontTitle, ...
    'FontWeight', 'bold')

xlabel('Time (s)', ...
    'FontSize', fontLabel)

ylabel('Voltage (V)', ...
    'FontSize', fontLabel)

set(gca, ...
    'FontSize', fontAxis, ...
    'LineWidth', 1.1)

legend({'U_{in}', ...
        'U_{out} (Measurement)', ...
        'U_{out} (PT2 Model)'}, ...
        'Location', 'southeast', ...
        'FontSize', fontLegend)

exportgraphics(gcf, ...
    'PT2_Model_Comparison.png', ...
    'Resolution', 300)

hold off