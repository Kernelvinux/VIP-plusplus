#include "main.h"

/*
Funcion principal
***/
int main(){
/*********************************************************
**  Definicion de variables principales
**********************************************************/
    Mat frame,      // Captura de la camara
        frameF,
        frameOut;
    vector<Mat> frameC(3);

/*********************************************************
**  Configuracion de camara
**********************************************************/
    VideoCapture cap(0);    // open the default camera
    if(!cap.isOpened())     // check if we succeeded
    return -1;

    namedWindow("Camara",1);
    namedWindow("Saliency",1);

/*********************************************************
**  Bucle principal
**********************************************************/
    for(;;){
        cap >> frame; // get a new frame from camera
        frame.convertTo(frameF, CV_32FC3);
        split(frameF,frameC);

        frameOut = saliencyMap(frameC[0],frameC[1],frameC[2]);

        imshow("Camara", frame);
        imshow("Saliency", frameOut);
        if(waitKey(30) >= 0) break;
    }

    return 0;
}
