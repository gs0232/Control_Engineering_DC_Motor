function [ Y ] = PT1T(x,t)

Umag = 12;
K = x(1);
tau = x(2);
T = x(3);

Y = Umag * K * (1 - exp(-(t-T)/tau)).*heaviside(t-T);

end