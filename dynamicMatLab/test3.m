


%% Video
closepreview
close all
clc

obj = VideoReader('3_ walk_MPEG4_High Quality.mp4');

% obj = imread('VisualSalience_Motion.gif');

% Taking frames' parameters
Icam = rgb2gray(read(obj, 1));
height = size(Icam,1);
width = size(Icam,2);

framesTaken = 4;

initialFrame = 1;
controlFrame = 1;

outputstR1 = zeros(height,width,4);
outputstR2 = zeros(height,width,4);
outputstR = zeros(height,width,4);

outputstL1 = zeros(height,width,4);
outputstL2 = zeros(height,width,4);
outputstL = zeros(height,width,4);

outputstU1 = zeros(height,width,4);
outputstU2 = zeros(height,width,4);
outputstU = zeros(height,width,4);

outputstD1 = zeros(height,width,4);
outputstD2 = zeros(height,width,4);
outputstD = zeros(height,width,4);


outputFinalR = zeros(height,width,1);
outputFinalL = zeros(height,width,1);
outputFinalU = zeros(height,width,1);
outputFinalD = zeros(height,width,1);
outputFinalEnergy = zeros(height,width,1);


%   gabor_filter = gabor2D(w, theta, sigma, size, type)
%   w : central frequency
%   theta : angle or orientation (degree)
%   sigma : sigma value of Gaussian envelope (usually choose = 1/w)
%   size : size of output filter in pixel (size*size)
%   type : 'even' or 'odd', default: 'odd';
%       'even' : real part of gabor filter
%       'odd' : imaginary part of gabor filter

wgf = 1.1; sigmagf = 1.5; sizegf = 31;
gf45odd = gabor2D(wgf,45,sigmagf,sizegf,'odd');
gf45even = gabor2D(wgf,45,sigmagf,sizegf,'even');
gf135odd = gabor2D(wgf,135,sigmagf,sizegf,'odd');
gf135even = gabor2D(wgf,135,sigmagf,sizegf,'even');

% Taking frames for input video
for k = 1 : obj.NumberOfFrames
    
    % Reading frame in grayscale
    Icam = rgb2gray(read(obj, k));
    
    % Creating Buffer
    % This buffer is for 4 frames
    if k >= 4
        controlFrame
        img_array(1:size(Icam,1),1:size(Icam,2),1) = img_array(1:size(Icam,1),1:size(Icam,2),2);
        img_array(1:size(Icam,1),1:size(Icam,2),2) = img_array(1:size(Icam,1),1:size(Icam,2),3);
        img_array(1:size(Icam,1),1:size(Icam,2),3) = img_array(1:size(Icam,1),1:size(Icam,2),4);
        img_array(1:size(Icam,1),1:size(Icam,2),4) = double(Icam);
        controlFrame = controlFrame + 1;
        
        %         outputFrame = slow_t_Fast(1)*conv2(img_array(:,:,4),gabor2Dvalue,'same') + ...
        %             slow_t_Fast(2)*conv2(img_array(:,:,3),gabor2Dvalue,'same') + ...
        %             slow_t_Fast(3)*conv2(img_array(:,:,2),gabor2Dvalue,'same') + ...
        %             slow_t_Fast(4)*conv2(img_array(:,:,1),gabor2Dvalue,'same');
        
%         if mod(k,framesTaken)==0
            for m = 1:size(img_array,1)
                img_array_reshape = reshape(img_array(m,:,:),[width,4]);
                outputstR1(m,1:width,1:4) = conv2(img_array_reshape,gf135even,'same');
                outputstR2(m,1:width,1:4) = conv2(img_array_reshape,gf135odd,'same');
                outputstL1(m,1:width,1:4) = conv2(img_array_reshape,gf45even,'same');
                outputstL2(m,1:width,1:4) = conv2(img_array_reshape,gf45odd,'same');
                %                 [outputstR(m,1:width,1:4), outputstL(m,1:width,1:4)] = AdelsonBergerFunction(img_array_reshape,1.1,1.5);
            end
            for m = 1:size(img_array,2)
                img_array_reshape = reshape(img_array(:,m,:),[height,4]);
                outputstU1(1:height,m,1:4) = conv2(img_array_reshape,gf45even,'same');
                outputstU2(1:height,m,1:4) = conv2(img_array_reshape,gf45odd,'same');
                outputstD1(1:height,m,1:4) = conv2(img_array_reshape,gf135even,'same');
                outputstD2(1:height,m,1:4) = conv2(img_array_reshape,gf135odd,'same');
                %                 [outputstU(1:height,m,1:4), outputstD(1:height,m,1:4)] = AdelsonBergerFunction(img_array_reshape,1.1,1.5);
            end
            
            outputstR = outputstR1.^2 + outputstR2.^2;
            outputstL = outputstL1.^2 + outputstL2.^2;
            outputstU = outputstU1.^2 + outputstU2.^2;
            outputstD = outputstD1.^2 + outputstD2.^2;
            
            outputHE = abs(outputstR - outputstL)./(outputstR + outputstL );
            outputVE = abs(outputstU - outputstD)./(outputstU + outputstD );
            outputEnergy = (outputHE.^2+outputVE.^2).^0.5;
            sum_outputEnergy = sum(outputEnergy,3);
            outputFinalEnergy = cat(3, outputFinalEnergy, sum_outputEnergy);
            %             outputFinalR = cat(3, outputFinalR, outputstR);
            %             outputFinalL = cat(3, outputFinalL, outputstL);
            %             outputFinalU = cat(3, outputFinalU, outputstU);
            %             outputFinalD = cat(3, outputFinalD, outputstD);
%         end
        
    else
        initialFrame
        if mod(k,framesTaken)== 1
            img_array(1:size(Icam,1),1:size(Icam,2),2) = double(Icam);
        elseif mod(k,framesTaken) == 2
            img_array(1:size(Icam,1),1:size(Icam,2),3) = double(Icam);
        elseif mod(k,framesTaken) == 3
            img_array(1:size(Icam,1),1:size(Icam,2),4) = double(Icam);
            %         elseif mod(k,framesTaken)== 0
            %             img_array(1:size(Icam,1),1:size(Icam,2),4) = double(Icam);
        end
        initialFrame = initialFrame + 1;
    end
    
end


% for m = 1:71
%    figure(3), imagesc(outputFinal(:,:,m));
% end


% for n = 1:256
%     arrayObj = zeros(256,1);
%     for m = 1:40
%         arrayObj = cat(2,arrayObj,obj(:,n,1,m));
%     end
%     figure(2),imagesc(arrayObj);
% end
%
% for n = 1:269
%     figure(2),imagesc(outputFinalR(:,:,n));
%     figure(3),imagesc(outputFinalL(:,:,n));
%     figure(4),imagesc(outputFinalU(:,:,n));
%     figure(5),imagesc(outputFinalD(:,:,n));
% end
% for n = 1:269
%     figure(2),imagesc(outputFinalEnergy(:,:,n));
% end