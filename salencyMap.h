#ifndef SALENCYMAP_H
#define SALENCYMAP_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <filters.h>
#include <vector>

/*
Espacios de trabajo
***/
using namespace  cv;
using namespace std;

/*
Tipo de datos
***/
typedef unsigned int       uint;
typedef vector<Mat>     Feature;
typedef vector<Mat>  Multiscale;


/*********************************************************
**  Pyramid
*
*   Retorna vector de Mat.
*   resul.at(0) = suma multiescala
*
**********************************************************/
Multiscale Pyramid(Mat img, float kernel[][]){
    Mat         aux;
    Multiscale pyrm;
    uint          i;

    for (i=0;i<8;i++){
        aux = convolutionK7(img, kernel);
        pyrm.push_back(aux);
        resize(aux, aux, Size(), 0.5, 0.5);
    }

    return pyrm;
}

/*********************************************************
**  Center Surround
*
*   Retorna vector de Mat.
*   cenSrr = pyrm(c) O pyrm(s)
*            c={2,3,4} s=c+d
*            d={3,4}
*
**********************************************************/
Multiscale centerSurround(Multiscale pyrm){
    Mat   aux1,aux2,aux3,
          aux4,aux5,aux6;
    Feature      cenSurr;

    resize(pyrm.at(4),pyrm.at(4), pyrm.at(1).size(), 0, 0,INTER_LINEAR);
    resize(pyrm.at(5),pyrm.at(5), pyrm.at(2).size(), 0, 0,INTER_LINEAR);
    resize(pyrm.at(6),pyrm.at(6), pyrm.at(3).size(), 0, 0,INTER_LINEAR);

    aux1 = pyrm.at(1)-pyrm.at(4);
    aux2 = pyrm.at(2)-pyrm.at(5);
    aux3 = pyrm.at(3)-pyrm.at(6);

    resize(pyrm.at(5),pyrm.at(5), pyrm.at(1).size(), 0, 0,INTER_LINEAR);
    resize(pyrm.at(6),pyrm.at(6), pyrm.at(2).size(), 0, 0,INTER_LINEAR);
    resize(pyrm.at(7),pyrm.at(7), pyrm.at(3).size(), 0, 0,INTER_LINEAR);

    aux4 = pyrm.at(1)-pyrm.at(5);
    aux5 = pyrm.at(2)-pyrm.at(6);
    aux6 = pyrm.at(3)-pyrm.at(7);

    cenSurr.push_back(aux1);
    cenSurr.push_back(aux2);
    cenSurr.push_back(aux3);
    cenSurr.push_back(aux4);
    cenSurr.push_back(aux5);
    cenSurr.push_back(aux6);

    return cenSurr;
}

/*********************************************************
**  Static Features
**********************************************************/
vector<Feature> staticFeatures(Mat red, Mat green, Mat blue){
//- Definicion de variables principales
    Multiscale redGauss, greenGauss, blueGauss,
                 colorGab0,
                colorGab45,
                colorGab90,
               colorGab135;
    Multiscale intensityGauss;
    Feature      intensity,
                     color,
              orientation0,
             orientation45,
             orientation90,
            orientation135;
    Mat averageColor;
    uint i;

//- Piramide Gauss y Gabbor
      redGauss = Pyramid(  red,GaussianFilter);
    greenGauss = Pyramid(green,GaussianFilter);
     blueGauss = Pyramid( blue,GaussianFilter);

    averageColor = red+green+blue;

    colorGab0   = Pyramid(averageColor,GabborFilter_0  );
    colorGab45  = Pyramid(averageColor,GabborFilter_45 );
    colorGab90  = Pyramid(averageColor,GabborFilter_90 );
    colorGab135 = Pyramid(averageColor,GabborFilter_135);

//- Intensidad
    // Diferencia cientro-alrededor
    for (i=0;i<8;i++)
        intensityGauss.push_back( redGauss(i)+greenGauss(i)+blueGauss(i) );

    intensity = centerSurround(intensityGauss);

//- Orientacion
    orientation0   = centerSurround(colorGab0  );
    orientation45  = centerSurround(colorGab45 );
    orientation90  = centerSurround(colorGab90 );
    orientation135 = centerSurround(colorGab135);

//- Color
}

/*********************************************************
**  Saliency Map
*
*   Basado en Itti
*
**********************************************************/
Mat saliencyMap(Mat red, Mat gren, Mat blue){

}



#endif // SALENCYMAP_H
