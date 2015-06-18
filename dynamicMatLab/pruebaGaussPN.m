clc
clear all
close all

img   = imread('/home/victor/Documentos/Projects/VIPalgorithm/img/oso.jpg');
orden = 7;

% M(x,y)
theta=0;   GM_0   = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=45;  GM_45  = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=90;  GM_90  = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=135; GM_135 = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=180; GM_180 = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=225; GM_225 = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=270; GM_270 = fltGaussN(orden,theta) - fltGaussP(orden,theta);
theta=315; GM_315 = fltGaussN(orden,theta) - fltGaussP(orden,theta);

GM = GM_0 + GM_45 + GM_90 + GM_135 + GM_180 + GM_225 + GM_270 + GM_315;

figure
subplot(2,4,1); surf(GM_0);  title('Orientacion 0');
subplot(2,4,2); surf(GM_45); title('Orientacion 45');
subplot(2,4,3); surf(GM_90); title('Orientacion 90');
subplot(2,4,4); surf(GM_135);title('Orientacion 135');
subplot(2,4,5); surf(GM_180);title('Orientacion 180');
subplot(2,4,6); surf(GM_225);title('Orientacion 225');
subplot(2,4,7); surf(GM_270);title('Orientacion 270');
subplot(2,4,8); surf(GM_315);title('Orientacion 315');

figure
surf(GM)

imgFlt = imfilter(double(img),GM);

out(:,:,1) = uint8(stand( imgFlt(:,:,1) ));
out(:,:,2) = uint8(stand( imgFlt(:,:,2) ));
out(:,:,3) = uint8(stand( imgFlt(:,:,3) ));

figure
subplot(2,2,1); imshow( out(:,:,1) );
subplot(2,2,2); imshow( out(:,:,2) );
subplot(2,2,3); imshow( out(:,:,3) );
subplot(2,2,4); imshow( out        );

% B(x,y)
b = 0.75;
GB = fltGauss(orden,0.15) - b*fltGauss(orden,0.2);

figure
surf(GB)

imgFlt2 = imfilter(double(img),GB);

out2(:,:,1) = uint8(stand( imgFlt(:,:,1) ));
out2(:,:,2) = uint8(stand( imgFlt(:,:,2) ));
out2(:,:,3) = uint8(stand( imgFlt(:,:,3) ));

figure
imshow( out2 );

%% Diferencia
imgJaq = imgFlt - imgFlt2;

out3(:,:,1) = uint8(stand( imgJaq(:,:,1) ));
out3(:,:,2) = uint8(stand( imgJaq(:,:,2) ));
out3(:,:,3) = uint8(stand( imgJaq(:,:,3) ));

figure
imshow( out3 );
