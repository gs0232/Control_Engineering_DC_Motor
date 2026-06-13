load('measurement_data.mat');
% Spalte 1: Zeit (t) in Sekunden
% Spalte 2: Eingangsspannung (U_in) in Volt
% Spalte 3: Ausgangsspannung (U_out) in Volt
t     = raw_data_new(:, 1);
U_in  = raw_data_new(:, 2);
U_out = raw_data_new(:, 3);

% 2. Plot erstellen
figure
hold on;

% Daten plotten mit den Farben aus dem Screenshot
plot(t, U_in, 'LineWidth', 1.2, 'Color', [0.2, 0.6, 0.8]);  % Blau für U_in
plot(t, U_out, 'LineWidth', 1.2, 'Color', [0.85, 0.33, 0.1]); % Orange/Rot für U_out

title('Plot raw measurement data')
box on;

% 3. Beschriftungen und Achsen anpassen (exakt wie im Screenshot)
xlabel('Time t /s');
ylabel('Voltage U /V');

% Achsenbegrenzung definieren (passend zum Bildausschnitt)
xlim([0, 2.45]);
ylim([0, 27]);

% 4. Legende hinzufügen und formatieren
lgd = legend('U_{in}', 'U_{out}', 'Location', 'southeast');
lgd.FontSize = 14;

hold off;