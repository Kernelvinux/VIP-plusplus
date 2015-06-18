function R = tempGamma(orden,n,tau)
R = zeros(1,orden);

for t=1:orden
    matiza = (n*t)^n/( factorial(n-1)*tau^(n+1) );
    expo = exp(-n*t/tau);
    R(t) = matiza*expo;
end

end