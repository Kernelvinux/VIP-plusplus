#ifndef FEATURESVIP_H
#define FEATURESVIP_H

#include "main.h"

/*
Espacios de trabajo
***/
using namespace  cv;
using namespace std;

/*
Tipo de datos
***/
typedef vector<Mat>     Feature;
typedef vector<Mat>  Multiscale;

/*
Funciones
***/
Multiscale Pyramid(Mat img, float kernel[7][7]);
Multiscale centerSurround(Multiscale pyrm);
Multiscale centerSurround(Multiscale pyrm1, Multiscale pyrm2);
vector<Feature> staticFeatures(Mat red, Mat green, Mat blue);
Mat saliencyMap(Mat red, Mat gren, Mat blue);

#endif // FEATURESVIP_H
