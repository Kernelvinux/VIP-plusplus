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
        resul;

    // Definicion de filtro
    /*
    Mat krnGauss=(Mat_<float>(8,8)<<0.000244140625,	0.000732421875,	0.002197265625,	0.004638671875,	0.004638671875,	0.002197265625,	0.000732421875,	0.000244140625,
                                    0.000732421875,	0.002197265625,	0.006591796875,	0.013916015625,	0.013916015625,	0.006591796875,	0.002197265625,	0.000732421875,
                                    0.002197265625,	0.006591796875,	0.019775390625,	0.041748046875,	0.041748046875,	0.019775390625,	0.006591796875,	0.002197265625,
                                    0.004638671875,	0.013916015625,	0.041748046875,	0.088134765625,	0.088134765625,	0.041748046875,	0.013916015625,	0.004638671875,
                                    0.004638671875,	0.013916015625,	0.041748046875,	0.088134765625,	0.088134765625,	0.041748046875,	0.013916015625,	0.004638671875,
                                    0.002197265625,	0.006591796875,	0.019775390625,	0.041748046875,	0.041748046875,	0.019775390625,	0.006591796875,	0.002197265625,
                                    0.000732421875,	0.002197265625,	0.006591796875,	0.013916015625,	0.013916015625,	0.006591796875,	0.002197265625,	0.000732421875,
                                    0.000244140625,	0.000732421875,	0.002197265625,	0.004638671875,	0.004638671875,	0.002197265625,	0.000732421875,	0.000244140625);
*/
/*    Mat krnGauss=(Mat_<float>(7,7)<<0.0101342273814857,	0.0362858823037167,	0.0780020314685376,	0.100668899772898,	0.0780020314685376,	0.0362858823037167,	0.0101342273814857,
                                    0.0362858823037167,	0.129922608305059,	0.279288437763789,	0.360447788597821,	0.279288437763789,	0.129922608305059,	0.0362858823037167,
                                    0.0780020314685376,	0.279288437763789,	0.600373041198404,	0.774837428883249,	0.600373041198404,	0.279288437763789,	0.0780020314685376,
                                    0.100668899772898,	0.360447788597821,	0.774837428883249,	                1,	0.774837428883249,	0.360447788597821,	0.100668899772898,
                                    0.0780020314685376,	0.279288437763789,	0.600373041198404,	0.774837428883249,	0.600373041198404,	0.279288437763789,	0.0780020314685376,
                                    0.0362858823037167,	0.129922608305059,	0.279288437763789,	0.360447788597821,	0.279288437763789,	0.129922608305059,	0.0362858823037167,
                                    0.0101342273814857,	0.0362858823037167,	0.0780020314685376,	0.100668899772898,	0.0780020314685376,	0.0362858823037167,	0.0101342273814857);
*/
/*    Mat krnGauss=(Mat_<float>(7,7)<<0.00408496585350535,	0.0146263335718905,	0.0314415320535577,	0.0405782308411114,	0.0314415320535577,	0.0146263335718905,	0.00408496585350535,
                                    0.0146263335718905,	0.0523699931475892,	0.112577277832567,	0.145291481330247,	0.112577277832567,	0.0523699931475892,	0.0146263335718905,
                                    0.0314415320535577,	0.112577277832567,	0.242002007685473,	0.312326171483822,	0.242002007685473,	0.112577277832567,	0.0314415320535577,
                                    0.0405782308411114,	0.145291481330247,	0.312326171483822,	0.403086066626864,	0.312326171483822,	0.145291481330247,	0.0405782308411114,
                                    0.0314415320535577,	0.112577277832567,	0.242002007685473,	0.312326171483822,	0.242002007685473,	0.112577277832567,	0.0314415320535577,
                                    0.0146263335718905,	0.0523699931475892,	0.112577277832567,	0.145291481330247,	0.112577277832567,	0.0523699931475892,	0.0146263335718905,
                                    0.00408496585350535,	0.0146263335718905,	0.0314415320535577,	0.0405782308411114,	0.0314415320535577,	0.0146263335718905,	0.00408496585350535);
*/
    Mat krnGauss=(Mat_<float>(7,7)<<0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387,
                                    0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                    0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                    0.008351391561455500, 0.02990238918704820, 0.06427974061178290, 0.08295900303167780, 0.06427974061178290, 0.02990238918704820, 0.008351391561455500,
                                    0.006470970765075440, 0.02316949035515870, 0.04980634894491610, 0.06427974061178290, 0.04980634894491610, 0.02316949035515870, 0.006470970765075440,
                                    0.003010240620041140, 0.01077825005626290, 0.02316949035515870, 0.02990238918704820, 0.02316949035515870, 0.01077825005626290, 0.003010240620041140,
                                    0.000840725400064387, 0.00301024062004114, 0.00647097076507544, 0.00835139156145550, 0.00647097076507544, 0.00301024062004114, 0.000840725400064387);

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

        //cvtColor(frame, edges, CV_BGR2GRAY);
        //cout << "" << endl;
        /*
        GaussianBlur(frame, fitr2, Size(7,7), 0, 0);
        GaussianBlur(fitr2, fitr2, Size(7,7), 0, 0);
        GaussianBlur(fitr2, fitr3, Size(7,7), 0, 0);
        GaussianBlur(fitr3, fitr4, Size(7,7), 0, 0);
        GaussianBlur(fitr4, fitr5, Size(7,7), 0, 0);
        GaussianBlur(fitr5, fitr6, Size(7,7), 0, 0);
        GaussianBlur(fitr6, fitr7, Size(7,7), 0, 0);
        */
        Mat frameF;
        frame.convertTo(frameF, CV_32FC3);
        /*
        vector<Mat> frameC(3);
        split(frame,frameC);

        minMaxLoc(frameC[0],&minVal,&maxVal);
        cout << "min: " << minVal << ", ";
        cout << "max: " << maxVal << endl;
*/
        Mat fltr2,fltr3,fltr4,fltr5,resuDDD;

        filter2D(frameF, fltr2, CV_32FC3, krnGauss);
        filter2D(fltr2,  fltr2, CV_32FC3, krnGauss);
        filter2D(fltr2,  fltr3, CV_32FC3, krnGauss);
        filter2D(fltr3,  fltr4, CV_32FC3, krnGauss);
        filter2D(fltr4,  fltr5, CV_32FC3, krnGauss);/*
        filter2D(fitr5,  fitr6, CV_32FC3, krnGauss);
        filter2D(fitr6,  fitr7, CV_32FC3, krnGauss);
        filter2D(fitr7,  fitr8, CV_32FC3, krnGauss);*/

        resuDDD = fltr2-fltr5;

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
/*
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

        resize(fitr5, fitr5, Size(), 8, 8,INTER_LINEAR);
/*        resize(fitr6, fitr6, Size(), 8, 8,INTER_LINEAR);
        resize(fitr7, fitr7, Size(), 8, 8,INTER_LINEAR);
*/

        Mat resul2, resul3, resul4;

        resul2 = fitr2-fitr5;

        /*cout << frame.rows << "," << frame.cols << endl;
        /*        resul3 = fitr3-fitr6;
        resul4 = fitr4-fitr7;

        resize(fitr6, fitr6, Size(), 2, 2,INTER_LINEAR);
        resize(fitr7, fitr7, Size(), 2, 2,INTER_LINEAR);
        resize(fitr8, fitr8, Size(),16,16,INTER_LINEAR);

        resul2 += fitr2-fitr6;
        resul3 += fitr3-fitr7;
        resul4 += fitr4-fitr8;

        resize(resul3, resul3, Size(), 2, 2,INTER_LINEAR);
        resize(resul4, resul4, Size(), 4, 4,INTER_LINEAR);
*/
        /*resul = fitr2-fitr5 /* +  fitr2-fitr6  +
                fitr3-fitr6  +  fitr3-fitr7  +
                fitr4-fitr7  +  fitr4-fitr8  ;*/




        resul = resul2 /*+ resul3 + resul4*/;

        resize(resul, resul, Size(), 4, 4,INTER_LINEAR);


        vector<Mat> resulC(3);
        split(resul,resulC);

        /*minMaxLoc(resulC[0],&minVal,&maxVal);
        resulC[0] = (resulC[0]-minVal)*255/(maxVal-minVal);

        minMaxLoc(resulC[1],&minVal,&maxVal);
        resulC[1] = (resulC[1]-minVal)*255/(maxVal-minVal);

        minMaxLoc(resulC[2],&minVal,&maxVal);
        resulC[2] = (resulC[2]-minVal)*255/(maxVal-minVal);*/

        resulC[0] += resulC[1] + resulC[2];

        minMaxLoc(resulC[0],&minVal,&maxVal);
        resulC[0] = (resulC[0]-minVal)*255/(maxVal-minVal);

        //merge(resulC,resul);
        //resul.convertTo(resul, CV_8UC3);
        resulC[0].convertTo(resulC[0], CV_8UC3);

        vector<Mat> resuDDDC(3);
        split(resuDDD,resuDDDC);

        /*minMaxLoc(resuDDDC[0],&minVal,&maxVal);
        resuDDDC[0] = (resuDDDC[0]-minVal)*255/(maxVal-minVal);

        minMaxLoc(resuDDDC[1],&minVal,&maxVal);
        resuDDDC[1] = (resuDDDC[1]-minVal)*255/(maxVal-minVal);

        minMaxLoc(resuDDDC[2],&minVal,&maxVal);
        resuDDDC[2] = (resuDDDC[2]-minVal)*255/(maxVal-minVal);*/

        resuDDDC[0] += resuDDDC[1] + resuDDDC[2];

        minMaxLoc(resuDDDC[0],&minVal,&maxVal);
        resuDDDC[0] = (resuDDDC[0]-minVal)*255/(maxVal-minVal);

        //merge(resuDDDC,resuDDD);
        //resuDDD.convertTo(resuDDD, CV_8UC3);
        resuDDDC[0].convertTo(resuDDDC[0], CV_8UC3);

        /*
        normalize(resul, resul, 0, 255, NORM_MINMAX, CV_32FC3);
        resul.convertTo(resul, CV_8U);
        */

        imshow("Camara", resuDDDC[0]);
        imshow("Filtrado", resulC[0]); //-- BIEN (Y)
        if(waitKey(30) >= 0) break;
    }

    return 0;
}
