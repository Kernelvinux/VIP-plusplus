function G = fltGauss(orden,sigma)

G = zeros(orden,orden);
k = (orden-1)/2;

aux = 0.1;
%aux = 0.06;

for i=-k:k
    for j=-k:k
        x = i*aux;
        y = j*aux;
        
        matiza = 1/(2*pi*sigma^2);
        expon  = exp(-(x^2+y^2)/(2*sigma^2) );
        G(i+k+1,j+k+1) = matiza*expon;
    end
end

end