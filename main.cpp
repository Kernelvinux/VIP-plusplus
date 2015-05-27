/*
Librerias
***/
#include <QCoreApplication>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <filters.h>

/*
Espacios de trabajo
***/
using namespace  cv;
using namespace std;

/*
Tipo de datos
***/
typedef unsigned int uint;

/*
Funcion principal
***/

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

    for (i=0;i<rows;i++) for(j=0;j<cols;j++){
        out.at<float>(i,j);
        kernel[i][j];
    }

    return out;
}

int main(){
/*********************************************************
**  Definicion de variables principales
**********************************************************/
    uint i;
    double  minVal,
            maxVal;
    Mat frame,      // Captura de la camara
        fitr2,
        fitr3,
        fitr4,
        fitr5,
        fitr6,
        fitr7,
        fitr8,
        resul,
        frameF;

    // Definicion de filtro
    Mat krnGauss=(Mat_<float>(7,7)<<0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387,
                                    0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                    0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                    0.008351391561455500, 0.02990238918704820, 0.06427974061178290, 0.08295900303167780, 0.06427974061178290, 0.02990238918704820, 0.008351391561455500,
                                    0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                    0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                    0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387);

    Mat krnGabbor_0=(Mat_<float>(7,7)<< 0.219942090078691,   0.311000213036744,	 0.382853031059958,	 0.410319878554183,	 0.382853031059958,	 0.311000213036744,	 0.219942090078691,
                                       -0.360778177422810,	-0.510143783744886,	-0.628006302555330,	-0.673061067539018,	-0.628006302555330,	-0.510143783744886,	-0.360778177422810,
                                       -0.485511373161494,	-0.686517712143974,	-0.845129282723722,	-0.905761001002688,	-0.845129282723722,	-0.686517712143974,	-0.485511373161494,
                                        0.536025919225963,   0.757945762054219,	 0.933059915130099,	                 1,	 0.933059915130099,	 0.757945762054219,	 0.536025919225963,
                                        0.485511373161494,   0.686517712143974,	 0.845129282723722,	 0.905761001002688,	 0.845129282723722,	 0.686517712143974,	 0.485511373161494,
                                       -0.360778177422810,	-0.510143783744886,	-0.628006302555329,	-0.673061067539017,	-0.628006302555329,	-0.510143783744886,	-0.360778177422810,
                                       -0.219942090078691,	-0.311000213036744,	-0.382853031059959,	-0.410319878554183,	-0.382853031059959,	-0.311000213036744,	-0.219942090078691);

    Mat krnGabbor_45=(Mat_<float>(7,7)<< 0.0936538505193276, 0.395788446212621,	 0.275146412309302,	-0.371656367890720,	-0.660485759126544,	-0.180932827883211,	 0.287323786082038,
                                         0.395788446212621,	 0.316041991529005,	-0.490346917282630,	-1.000935896555920,	-0.314949637645769,	 0.574481778215950,	 0.536404028842199,
                                         0.275146412309302,	-0.490346917282630,	-1.14970706499635,	-0.415530574103585,	 0.870600805222588,	 0.933718090255184,	 0.089545106627328,
                                        -0.371656367890720,	-1.00093589655592,	-0.415530574103585,	                 1,	 1.23190620886194,	 0.135701505060078,	-0.549322969084363,
                                        -0.660485759126543,	-0.314949637645768,	 0.870600805222588,	 1.231906208861940,	 0.155871099872671,	-0.724752345861218,	-0.485164321321409,
                                        -0.180932827883210,	 0.574481778215950,	 0.933718090255184,	 0.135701505060078,	-0.724752345861218,	-0.557275295877272,	 0.022114507829037,
                                         0.287323786082039,	 0.536404028842199,	 0.089545106627328, -0.549322969084363,	-0.485164321321409,	 0.022114507829037,	 0.218908093942334);

/*********************************************************
**  Configuracion de camara
**********************************************************/
    VideoCapture cap(0);    // open the default camera
    if(!cap.isOpened())     // check if we succeeded
    return -1;

    namedWindow("Camara",1);
    namedWindow("Filtrado",1);

/*********************************************************
**  Bucle principal
**********************************************************/
    for(;;){
        cap >> frame; // get a new frame from camera
        frame.convertTo(frameF, CV_32FC3);

        Mat fitr1;

        
        
        filter2D(frameF, fitr1, CV_32FC3, krnGauss);
        resize(fitr1, fitr1, Size(), 0.5, 0.5);

        filter2D(fitr1,  fitr2, CV_32FC3, krnGauss);
        resize(fitr2, fitr2, Size(), 0.5, 0.5);

        filter2D(fitr2,  fitr3, CV_32FC3, krnGauss);
        resize(fitr3, fitr3, Size(), 0.5, 0.5);

        filter2D(fitr3,  fitr4, CV_32FC3, krnGauss);
        resize(fitr4, fitr4, Size(), 0.5, 0.5);

        filter2D(fitr4,  fitr5, CV_32FC3, krnGauss);
        resize(fitr5, fitr5, Size(), 0.5, 0.5);

        filter2D(fitr5,  fitr6, CV_32FC3, krnGauss);
        resize(fitr6, fitr6, Size(), 0.5, 0.5);

        filter2D(fitr6,  fitr7, CV_32FC3, krnGauss);
        resize(fitr7, fitr7, Size(), 0.5, 0.5);

        filter2D(fitr7,  fitr8, CV_32FC3, krnGauss);
        resize(fitr8, fitr8, Size(), 0.5, 0.5);

        //Canny(edges, edges, 0, 30, 3);
/*
        vector<Mat> fitr7C(3);
        split(fitr7,fitr7C);

        minMaxLoc(fitr7C[0],&minVal,&maxVal);
        cout << "min: " << minVal << ", " << "max: " << maxVal << endl;
*/

        resize(fitr5, fitr5, fitr2.size(), 0, 0,INTER_LINEAR);
        resize(fitr6, fitr6, fitr3.size(), 0, 0,INTER_LINEAR);
        resize(fitr7, fitr7, fitr4.size(), 0, 0,INTER_LINEAR);

        Mat resul2, resul3, resul4;

        resul2 = fitr2-fitr5;
        resul3 = fitr3-fitr6;
        resul4 = fitr4-fitr7;

        resize(fitr6, fitr6, fitr2.size(), 0, 0,INTER_LINEAR);
        resize(fitr7, fitr7, fitr3.size(), 0, 0,INTER_LINEAR);
        resize(fitr8, fitr8, fitr4.size(), 0, 0,INTER_LINEAR);

        resul2 += fitr2-fitr6;
        resul3 += fitr3-fitr7;
        resul4 += fitr4-fitr8;

        resize(resul3, resul3, resul2.size(), 0, 0,INTER_LINEAR);
        resize(resul4, resul4, resul2.size(), 0, 0,INTER_LINEAR);

        resul = resul2 + resul3 + resul4;

        resize(resul, resul, Size(), 4, 4,INTER_LINEAR);


        vector<Mat> resulC(3);
        split(resul,resulC);


        resulC[0] += resulC[1] + resulC[2];

        minMaxLoc(resulC[0],&minVal,&maxVal);
        resulC[0] = (resulC[0]-minVal)*255/(maxVal-minVal);

        //merge(resulC,resul);
        //resul.convertTo(resul, CV_8UC3);
        resulC[0].convertTo(resulC[0], CV_8UC3);

        /*
        normalize(resul, resul, 0, 255, NORM_MINMAX, CV_32FC3);
        resul.convertTo(resul, CV_8U);
        */

        imshow("Camara", frame);
        imshow("Filtrado", resulC[0]); //-- BIEN (Y)
        if(waitKey(30) >= 0) break;
    }

    return 0;
}
