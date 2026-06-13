%% PT2 (überdämpft) Systemidentifikation - Messdaten measurement_data.mat

clear; clc; close all;

%% 1. Daten laden
load('measurement_data.mat');   % enthält 'raw_data_new'

t     = raw_data_new(:,1);
U_in  = raw_data_new(:,2);
U_out = raw_data_new(:,3);

%% 2. Sprunghöhe und Modellfunktion (PT2, überdämpft, T1 ≠ T2)
U_step = U_in(end) - U_in(1);   % ≈ 5.24

pt2_model = @(p, t) p(1) * U_step * ...
    (1 - (p(2)*exp(-t/p(2)) - p(3)*exp(-t/p(3))) ./ (p(2) - p(3) + eps));

%% 3. Fit mit lsqcurvefit
p0 = [5, 0.3, 0.1];   % Startwerte: K, T1, T2
p_opt = lsqcurvefit(pt2_model, p0, t, U_out, [0 0 0], [10 5 5]);

%% 4. Identifizierte Übertragungsfunktion
T = sort(p_opt(2:3), 'descend');
K = p_opt(1);

G_ident = tf(K, conv([T(1) 1], [T(2) 1]))

fprintf('K  = %.4f\n', K);
fprintf('T1 = %.4f s\n', T(1));
fprintf('T2 = %.4f s\n', T(2));

%% 5. Vergleich Messung vs. Modell
U_out_model = pt2_model(p_opt, t);

figure;
plot(t, U_in, 'k-', 'LineWidth', 1.2); hold on;
plot(t, U_out, 'b-', 'MarkerSize', 4);
plot(t, U_out_model, 'r-', 'LineWidth', 1.5);
xlim([0, 8]);
ylim([0, 29]);
legend('U_{in}', 'U_{out} (Messung)', 'U_{out} (Modell)', 'Location', 'best');
xlabel('Zeit [s]'); ylabel('Spannung');
title('Sprungantwort: Messung vs. PT2-Modell');