#include "main.h"

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
        resul,
        frameF;

/*********************************************************
**  Configuracion de camara
**********************************************************/
    VideoCapture cap(0);    // open the default camera
    if(!cap.isOpened())     // check if we succeeded
    return -1;

    namedWindow("Camara",1);
    //namedWindow("Filtrado",1);

/*********************************************************
**  Bucle principal
**********************************************************/
    for(;;){
        cap >> frame; // get a new frame from camera
        frame.convertTo(frameF, CV_32FC3);

        vector<Mat> frameC(3);
        split(frameF,frameC);

        vector<Feature> caracteristica;

        caracteristica = staticFeatures(frameC[0],frameC[1],frameC[2]);

        /*
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
        resize(fitr8, fitr8, Size(), 0.5, 0.5);*/

        //Canny(edges, edges, 0, 30, 3);
/*
        vector<Mat> fitr7C(3);
        split(fitr7,fitr7C);

        minMaxLoc(fitr7C[0],&minVal,&maxVal);
        cout << "min: " << minVal << ", " << "max: " << maxVal << endl;
*/
/*
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
        resulC[0].convertTo(resulC[0], CV_8UC3);*/

        /*
        normalize(resul, resul, 0, 255, NORM_MINMAX, CV_32FC3);
        resul.convertTo(resul, CV_8U);
        */

        imshow("Camara", frame);
        //imshow("Filtrado", resulC[0]);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}
