%% 5. Systemidentifikation (PT2 overdamped)
% Ziel-Übertragungsfunktion: G(s) = K / ((T1*s + 1)*(T2*s + 1))
% Die analytische Sprungantwort für ein überdämpftes PT2-System bei einem 
% Eingangssprung der Höhe U_step ist:
% y(t) = K * U_step * (1 - (T1*exp(-t/T1) - T2*exp(-t/T2)) / (T1 - T2))

% Bestimmung der Sprunghöhe des Eingangs (U_in springt von 0 auf 5V)
U_step = max(U_in) - min(U_in); 

% Definition der analytischen Sprungantwort-Funktion
% x(1) = K (Verstärkung), x(2) = T1 (Zeitkonstante 1), x(3) = T2 (Zeitkonstante 2)
pt2_model = @(x, t) x(1) * U_step * (1 - (x(2)*exp(-t/x(2)) - x(3)*exp(-t/x(3))) / (x(2) - x(3)));

% Startwerte für die Optimierung [K, T1, T2]
% K_schätz = max_ausgang / max_eingang. T1 und T2 grob geschätzt aus dem Plot
K_start = max(U_out) / U_step; 
x0 = [K_start, 0.2, 0.05]; 

% Grenzen für die Parameter [K, T1, T2] (alle müssen positiv sein, T1 > T2)
lb = [0.1, 0.001, 0.001];
ub = [10, 2.0, 2.0];

% Optimierung durchführen (Fehlerquadrate minimieren)
options = optimoptions('lsqcurvefit', 'Display', 'off');
[estimated_params, resnorm] = lsqcurvefit(pt2_model, x0, t, U_out, lb, ub, options);

% Parameter extrahieren
K_ident  = estimated_params(1);
T1_ident = estimated_params(2);
T2_ident = estimated_params(3);

% Identifiziertes System anzeigen
fprintf('\n--- Identifizierte PT2 Parameter ---\n');
fprintf('Verstärkung K:      %.4f\n', K_ident);
fprintf('Zeitkonstante T1:   %.4f s\n', T1_ident);
fprintf('Zeitkonstante T2:   %.4f s\n', T2_ident);

%% 6. Vergleich Plotten (Messdaten vs. Identifiziertes Modell)
% Berechne die Modellantwort mit den gefundenen Parametern
U_out_model = pt2_model(estimated_params, t);

figure
plot(t, U_out, 'LineWidth', 1.5, 'Color', [0.85, 0.33, 0.1]); hold on;
plot(t, U_out_model, '--', 'LineWidth', 2, 'Color', [0.1, 0.6, 0.1]); % Grün gestrichelt für Modell
grid on;
title('Vergleich: Messdaten vs. Identifiziertes PT2-Modell');
xlabel('Time t /s');
ylabel('Voltage U_ {out} /V');
legend('Messdaten (Raw)', 'Identifiziertes PT2 Modell', 'Location', 'southeast');

%% 7. Übertragungsfunktion in MATLAB erstellen (für Control System Toolbox)
s = tf('s');
G_ident = K_ident / ((T1_ident*s + 1) * (T2_ident*s + 1));
disp('Identifizierte Übertragungsfunktion G(s):')
disp(G_ident)