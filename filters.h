#ifndef FILTERS_H
#define FILTERS_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/*
Espacios de trabajo
***/
using namespace  cv;
using namespace std;

/*
Filtros
***/
const float GaussianFilter[7][7] = {{0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387},
                              {0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140},
                              {0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440},
                              {0.008351391561455500, 0.02990238918704820, 0.06427974061178290, 0.08295900303167780, 0.06427974061178290, 0.02990238918704820, 0.008351391561455500},
                              {0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440},
                              {0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140},
                              {0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387}};

const float GabborFilter_0[7][7] = {{ 0.219942090078691,   0.311000213036744,	 0.382853031059958,	 0.410319878554183,	 0.382853031059958,	 0.311000213036744,	 0.219942090078691},
                              {-0.360778177422810,	-0.510143783744886,	-0.628006302555330,	-0.673061067539018,	-0.628006302555330,	-0.510143783744886,	-0.360778177422810},
                              {-0.485511373161494,	-0.686517712143974,	-0.845129282723722,	-0.905761001002688,	-0.845129282723722,	-0.686517712143974,	-0.485511373161494},
                              { 0.536025919225963,   0.757945762054219,	 0.933059915130099,	                 1,	 0.933059915130099,	 0.757945762054219,	 0.536025919225963},
                              { 0.485511373161494,   0.686517712143974,	 0.845129282723722,	 0.905761001002688,	 0.845129282723722,	 0.686517712143974,	 0.485511373161494},
                              {-0.360778177422810,	-0.510143783744886,	-0.628006302555329,	-0.673061067539017,	-0.628006302555329,	-0.510143783744886,	-0.360778177422810},
                              {-0.219942090078691,	-0.311000213036744,	-0.382853031059959,	-0.410319878554183,	-0.382853031059959,	-0.311000213036744,	-0.219942090078691}};

const float GabborFilter_45[7][7] = {{ 0.0936538505193276, 0.395788446212621,	 0.275146412309302,	-0.371656367890720,	-0.660485759126544,	-0.180932827883211,	 0.287323786082038},
                               { 0.395788446212621,	 0.316041991529005,	-0.490346917282630,	-1.000935896555920,	-0.314949637645769,	 0.574481778215950,	 0.536404028842199},
                               { 0.275146412309302,	-0.490346917282630,	-1.14970706499635,	-0.415530574103585,	 0.870600805222588,	 0.933718090255184,	 0.089545106627328},
                               {-0.371656367890720,	-1.00093589655592,	-0.415530574103585,	                 1,	 1.23190620886194,	 0.135701505060078,	-0.549322969084363},
                               {-0.660485759126543,	-0.314949637645768,	 0.870600805222588,	 1.231906208861940,	 0.155871099872671,	-0.724752345861218,	-0.485164321321409},
                               {-0.180932827883210,	 0.574481778215950,	 0.933718090255184,	 0.135701505060078,	-0.724752345861218,	-0.557275295877272,	 0.022114507829037},
                               { 0.287323786082039,	 0.536404028842199,	 0.089545106627328, -0.549322969084363,	-0.485164321321409,	 0.022114507829037,	 0.218908093942334}};

const float GabborFilter_90[7][7] = {{0.219942090078691,	-0.360778177422810,	-0.485511373161494,	0.536025919225963,	0.485511373161494,	-0.360778177422810,	-0.219942090078691},
                               {0.311000213036744,	-0.510143783744887,	-0.686517712143974,	0.757945762054219,	0.686517712143974,	-0.510143783744886,	-0.311000213036744},
                               {0.382853031059958,	-0.628006302555330,	-0.845129282723722,	0.933059915130099,	0.845129282723722,	-0.628006302555329,	-0.382853031059958},
                               {0.410319878554183,	-0.673061067539018,	-0.905761001002688,	                1,	0.905761001002688,	-0.673061067539017,	-0.410319878554183},
                               {0.382853031059958,	-0.628006302555330,	-0.845129282723722,	0.933059915130099,	0.845129282723722,	-0.628006302555329,	-0.382853031059959},
                               {0.311000213036744,	-0.510143783744887,	-0.686517712143974,	0.757945762054219,	0.686517712143974,	-0.510143783744886,	-0.311000213036745},
                               {0.219942090078691,	-0.360778177422810,	-0.485511373161494,	0.536025919225963,	0.485511373161494,	-0.360778177422810,	-0.219942090078691}};

const float GabborFilter_135[7][7] = {{ 0.287323786082038,	 0.536404028842199,	 0.0895451066273280, -0.549322969084363,	-0.485164321321409,	 0.0221145078290367,	0.218908093942334},
                                {-0.180932827883211,	 0.574481778215950,	 0.933718090255184,   0.135701505060078,	-0.724752345861218,	-0.557275295877272,	    0.0221145078290367},
                                {-0.660485759126544,    -0.314949637645769,	 0.870600805222588,   1.23190620886194 ,	 0.155871099872671,	-0.724752345861218,	   -0.485164321321409},
                                {-0.371656367890720,	-1.00093589655592,	-0.415530574103585,                   1,	 1.23190620886194,	 0.135701505060078,	   -0.549322969084363},
                                { 0.275146412309302,	-0.490346917282630,	-1.14970706499635,	 -0.415530574103585,	 0.870600805222588,	 0.933718090255184,	    0.0895451066273277},
                                { 0.395788446212621,	 0.316041991529005,	-0.490346917282630,	 -1.00093589655592 ,	-0.314949637645768,	 0.574481778215950,	    0.536404028842199},
                                { 0.0936538505193276,	 0.395788446212621,	 0.275146412309302,	 -0.371656367890720,	-0.660485759126543,	-0.180932827883210,	    0.287323786082039}};


/*********************************************************
**  Convolucion kernel 7x7
*
*   Codigo Piero
*   Piero Aqui!!!!!!!!!!
*
**********************************************************/
Mat convolutionK7(Mat image, float kernel[7][7]){
    Mat  out;   // Salida de la funcion
    uint i,j;   // Variables de bucle

    rows = image.rows;
    cols = image.cols;

    out = Mat(rows,cols,CV_32F);

    // Cuerpo
    for (i=0;i<rows;i++) for(j=0;j<cols;j++){
        outImg[i][j] = image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg[i][j]+= image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg[i][j]+= image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg[i][j]+= image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg[i][j]+= image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
        outImg[i][j]+= image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg[i][j]+= image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    return out;
}

float **convolutionK7(float **image,float kernel[7][7],size_t rows, size_t cols){
    float **outImg;
    uint       i,j;

    // Inicializar puntero
    outImg = new float*[rows];
    for (i=0;i<rows;i++) outImg[i] = new float[cols];

    // Cuerpo
    for (i=3;i<rows-3;i++) for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];
    }

    // Margen superior
    i=2;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= 2*(image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6]);
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];
    }

    i=1;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= 2*(image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6]);
        outImg[i][j]+= 2*(image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6]);
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];

    }

    i=0;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= 2*(image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6]);
        outImg[i][j]+= 2*(image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6]);
        outImg[i][j]+= 2*(image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6]);
    }

    // Margen Inferior
    i=rows-3;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= 2*(image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6]);
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
    }

    i=rows-2;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= 2*(image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6]);
        outImg[i][j]+= 2*(image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6]);
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
        }

    i=rows-1;
    for (j=3;j<cols-3;j++){
        outImg[i][j] = 2*(image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6]);
        outImg[i][j]+= 2*(image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6]);
        outImg[i][j]+= 2*(image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6]);
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
    }

    // Margen Izquierda
    j=2;
    for (i=3;i<rows-3;i++){
        outImg[i][j] = image[i-3][j-2]*kernel[0][1] + 2*image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j-2]*kernel[1][1] + 2*image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= image[i-1][j-2]*kernel[2][1] + 2*image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= image[  i][j-2]*kernel[3][1] + 2*image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= image[i+1][j-2]*kernel[4][1] + 2*image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
        outImg[i][j]+= image[i+2][j-2]*kernel[5][1] + 2*image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j-2]*kernel[6][1] + 2*image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];
    }

    j=1;
    for (i=3;i<rows-3;i++){
        outImg[i][j] = image[i-3][j-1]*kernel[0][2] + 2*image[i-3][j  ]*kernel[0][3] + 2*image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j-1]*kernel[1][2] + 2*image[i-2][j  ]*kernel[1][3] + 2*image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= image[i-1][j-1]*kernel[2][2] + 2*image[i-1][j  ]*kernel[2][3] + 2*image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= image[  i][j-1]*kernel[3][2] + 2*image[  i][j  ]*kernel[3][3] + 2*image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= image[i+1][j-1]*kernel[4][2] + 2*image[i+1][j  ]*kernel[4][3] + 2*image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
        outImg[i][j]+= image[i+2][j-1]*kernel[5][2] + 2*image[i+2][j  ]*kernel[5][3] + 2*image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j-1]*kernel[6][2] + 2*image[i+3][j  ]*kernel[6][3] + 2*image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];
    }

    j=0;
    for (i=3;i<rows-3;i++){
        outImg[i][j] = image[i-3][j  ]*kernel[0][3] + 2*image[i-3][j+1]*kernel[0][4] + 2*image[i-3][j+2]*kernel[0][5] + 2*image[i-3][j+3]*kernel[0][6];
        outImg[i][j]+= image[i-2][j  ]*kernel[1][3] + 2*image[i-2][j+1]*kernel[1][4] + 2*image[i-2][j+2]*kernel[1][5] + 2*image[i-2][j+3]*kernel[1][6];
        outImg[i][j]+= image[i-1][j  ]*kernel[2][3] + 2*image[i-1][j+1]*kernel[2][4] + 2*image[i-1][j+2]*kernel[2][5] + 2*image[i-1][j+3]*kernel[2][6];
        outImg[i][j]+= image[  i][j  ]*kernel[3][3] + 2*image[  i][j+1]*kernel[3][4] + 2*image[  i][j+2]*kernel[3][5] + 2*image[  i][j+3]*kernel[3][6];
        outImg[i][j]+= image[i+1][j  ]*kernel[4][3] + 2*image[i+1][j+1]*kernel[4][4] + 2*image[i+1][j+2]*kernel[4][5] + 2*image[i+1][j+3]*kernel[4][6];
        outImg[i][j]+= image[i+2][j  ]*kernel[5][3] + 2*image[i+2][j+1]*kernel[5][4] + 2*image[i+2][j+2]*kernel[5][5] + 2*image[i+2][j+3]*kernel[5][6];
        outImg[i][j]+= image[i+3][j  ]*kernel[6][3] + 2*image[i+3][j+1]*kernel[6][4] + 2*image[i+3][j+2]*kernel[6][5] + 2*image[i+3][j+3]*kernel[6][6];
    }

    // Margen Derecha
    i=cols-3;
    for (i=3;i<rows-3;i++) for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + 2*image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + 2*image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + 2*image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + 2*image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + 2*image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + 2*image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + 2*image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5];
    }

    i=cols-2;
    for (i=3;i<rows-3;i++) for (j=3;j<cols-3;j++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + 2*image[i-3][j-1]*kernel[0][2] + 2*image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + 2*image[i-2][j-1]*kernel[1][2] + 2*image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + 2*image[i-1][j-1]*kernel[2][2] + 2*image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + 2*image[  i][j-1]*kernel[3][2] + 2*image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + 2*image[i+1][j-1]*kernel[4][2] + 2*image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + 2*image[i+2][j-1]*kernel[5][2] + 2*image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + 2*image[i+3][j-1]*kernel[6][2] + 2*image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4];
    }

    i=cols-1;
    for (i=3;i<rows-3;i++) for (j=3;j<cols-3;j++){
        outImg[i][j] = 2*image[i-3][j-3]*kernel[0][0] + 2*image[i-3][j-2]*kernel[0][1] + 2*image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3];
        outImg[i][j]+= 2*image[i-2][j-3]*kernel[1][0] + 2*image[i-2][j-2]*kernel[1][1] + 2*image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3];
        outImg[i][j]+= 2*image[i-1][j-3]*kernel[2][0] + 2*image[i-1][j-2]*kernel[2][1] + 2*image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3];
        outImg[i][j]+= 2*image[  i][j-3]*kernel[3][0] + 2*image[  i][j-2]*kernel[3][1] + 2*image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3];
        outImg[i][j]+= 2*image[i+1][j-3]*kernel[4][0] + 2*image[i+1][j-2]*kernel[4][1] + 2*image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3];
        outImg[i][j]+= 2*image[i+2][j-3]*kernel[5][0] + 2*image[i+2][j-2]*kernel[5][1] + 2*image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3];
        outImg[i][j]+= 2*image[i+3][j-3]*kernel[6][0] + 2*image[i+3][j-2]*kernel[6][1] + 2*image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3];
    }

    return outImg;
}


#endif // FILTERS_H
