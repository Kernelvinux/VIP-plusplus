function gabor_filter = gabor2D(w, theta, sigma, Gaborsize, type)
%gabor2D generate a spatial gabor filter (2D)
%   gabor_filter = gabor2D(w, theta, sigma, size, type)
%   w : central frequency
%   theta : angle or orientation (degree)
%   sigma : sigma value of Gaussian envelope (usually choose = 1/w)
%   size : size of output filter in pixel (size*size)
%   type : 'even' or 'odd', default: 'odd'; 
%       'even' : real part of gabor filter
%       'odd' : imaginary part of gabor filter
%      ---------------------------------------------
% Example
%   Assume you want to filter the central frequency 32 of the image size
%   320*240 with filters size 31x31. It may be:
%   w = [2 4 8 16 32 64];
%   w = w/(320/31);     % scale central frequency
%   theta = [0 45 90 135];
%   sigma = 1./w;
%   size = 31;
%   type = 'even';
%   g = gabor2D(w(5), theta(1), sigma(5), size, type);
%   showGabor(g);
%      ---------------------------------------------
%   Nguyen Hoang Minh
%   March 02 2015

    p = floor(Gaborsize/2)/Gaborsize;
    [xr, yr] = meshgrid(-p:1/Gaborsize:p, -p:1/Gaborsize:p);
    yr = -yr;
    rotation = xr*cosd(theta)+yr*sind(theta);
    
    if ~exist('type', 'var') || ~strcmp(type, 'even')
        sinusoid = sind(double(2*180*w*rotation));
    else
        sinusoid = cosd(double(2*180*w*rotation));
    end

    filter_radius = floor(Gaborsize/2);
    [xg, yg] = meshgrid(-filter_radius:filter_radius, -filter_radius:filter_radius);
    yg = -yg;
    sigma_scale = sigma*(Gaborsize/2);
    A = 1/(2*pi*sigma_scale^2);
    k = -1*((xg.^2+yg.^2)/(2*sigma_scale^2));
    gauss = A*exp(k);
    
    gabor_filter = gauss.*sinusoid;
end