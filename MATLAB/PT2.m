function [ Y ] = PT2(x,t)

Umag = 12;
K = x(1);
tau1 = x(2);
tau2 = x(3);

Y =Umag * (K - (K*tau1*exp(-t/tau1))/(tau1 - tau2) + (K*tau2*exp(-t/tau2))/(tau1 - tau2));

end