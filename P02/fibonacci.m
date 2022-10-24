clear
close all
clc

A = load('results.txt');

N = A(:,1);
V = A(:,2);
Fib = A(:,3);
T = A(:,4);

%Apresentar por algoritmo
for n=1:4
    figure(n)
    N_alg = N(V==n);
    T_alg = T(V==n);
    plot(N_alg,T_alg)
    title(sprintf('Algoritmo %d',n))
    %semilogy(N_alg,T_alg)
end
