#include "featuresVIP.h"

/*********************************************************
**  Pyramid
*
*   Retorna vector de Mat.
*   resul.at(0) = suma multiescala
*
**********************************************************/
Multiscale Pyramid(Mat img, Mat kernel){
    Mat         aux;
    Multiscale pyrm;

    // Nivel 1
    filter2D(img, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);


    // Nivel 2
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 3
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 4
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 5
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 6
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 7
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    // Nivel 8
    filter2D(aux, aux, CV_32F, kernel);
    pyrm.push_back(aux);
    resize(aux, aux, Size(), 0.5, 0.5);

    return pyrm;
}

/*********************************************************
**  Center Surround
*
*   Retorna vector de Mat.
*   cenSrr(c,s) = pyrm(c) O pyrm(s)
*              c={2,3,4} s=c+d
*              d={3,4}
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
    cenSurr.push_back(aux4);

    cenSurr.push_back(aux2);
    cenSurr.push_back(aux5);

    cenSurr.push_back(aux3);
    cenSurr.push_back(aux6);

    return cenSurr;
}

Multiscale centerSurround(Multiscale pyrm1, Multiscale pyrm2){
    Mat   aux1,aux2,aux3,
          aux4,aux5,aux6;
    Feature      cenSurr;

    resize(pyrm2.at(4),pyrm2.at(4), pyrm1.at(1).size(), 0, 0,INTER_LINEAR);
    resize(pyrm2.at(5),pyrm2.at(5), pyrm1.at(2).size(), 0, 0,INTER_LINEAR);
    resize(pyrm2.at(6),pyrm2.at(6), pyrm1.at(3).size(), 0, 0,INTER_LINEAR);

    aux1 = pyrm1.at(1)-pyrm2.at(4);
    aux2 = pyrm1.at(2)-pyrm2.at(5);
    aux3 = pyrm1.at(3)-pyrm2.at(6);

    resize(pyrm2.at(5),pyrm2.at(5), pyrm1.at(1).size(), 0, 0,INTER_LINEAR);
    resize(pyrm2.at(6),pyrm2.at(6), pyrm1.at(2).size(), 0, 0,INTER_LINEAR);
    resize(pyrm2.at(7),pyrm2.at(7), pyrm1.at(3).size(), 0, 0,INTER_LINEAR);

    aux4 = pyrm1.at(1)-pyrm2.at(5);
    aux5 = pyrm1.at(2)-pyrm2.at(6);
    aux6 = pyrm1.at(3)-pyrm2.at(7);

    cenSurr.push_back(aux1);
    cenSurr.push_back(aux4);

    cenSurr.push_back(aux2);
    cenSurr.push_back(aux5);

    cenSurr.push_back(aux3);
    cenSurr.push_back(aux6);

    return cenSurr;
}

/*********************************************************
**  Static Features
*
*   Retorna un vector Feature en el siguiente orden:
*                                   -[0] Intensidad,
*                                   -[1] Orientacion 0,
*                                   -[2] Orientacion 45,
*                                   -[3] Orientacion 90,
*                                   -[4] Orientacion 135,
*                                   -[5] color RG
*                                   -[6] color RC,
*                                   -[7] color BY,
*                                   -[8] color BM.
*
*   Feature es un vector de Mat de diferentes dimensiones,
*   resultantes de la operancion centro-alrededor
*
**********************************************************/
vector<Feature> staticFeatures(Mat red, Mat green, Mat blue){
//- Definicion de variables principales
    Multiscale redGauss, greenGauss, blueGauss,
                 colorGab0,
                colorGab45,
                colorGab90,
               colorGab135,
             rgGssP,rgGssN,
             rcGssP,rcGssN,
             byGssP,byGssN,
             gmGssP,gmGssN;
    Multiscale intensityGauss,
                   rdGrnGauss;
    Feature      intensity,
                   colorRG,
                   colorRC,
                   colorBY,
                   colorGM,
              orientation0,
             orientation45,
             orientation90,
            orientation135;
    Mat       averageColor;
    vector<Feature> stcFeactures;
    uint i;

//- Piramide Gauss y Gabbor
      redGauss = Pyramid(     red,krnGauss);
    greenGauss = Pyramid(   green,krnGauss);
     blueGauss = Pyramid(    blue,krnGauss);
    rdGrnGauss = Pyramid(red-blue,krnGauss);

    averageColor = red+green+blue;

    colorGab0   = Pyramid(averageColor,krnGabbor_0  );
    colorGab45  = Pyramid(averageColor,krnGabbor_45 );
    colorGab90  = Pyramid(averageColor,krnGabbor_90 );
    colorGab135 = Pyramid(averageColor,krnGabbor_135);

//- Intensidad
    for (i=0;i<8;i++)
        intensityGauss.push_back( redGauss[i]+greenGauss[i]+blueGauss[i] );

    intensity = centerSurround(intensityGauss,intensityGauss);
    stcFeactures.push_back(intensity);

//- Orientacion
    orientation0   = centerSurround(colorGab0  ,colorGab0  );
    orientation45  = centerSurround(colorGab45 ,colorGab45 );
    orientation90  = centerSurround(colorGab90 ,colorGab90 );
    orientation135 = centerSurround(colorGab135,colorGab135);

    stcFeactures.push_back(orientation0  );
    stcFeactures.push_back(orientation45 );
    stcFeactures.push_back(orientation90 );
    stcFeactures.push_back(orientation135);

//- Color
    for (i=0;i<8;i++){
        rgGssP.push_back(0.75*(redGauss[i]-greenGauss[i]) );
        rcGssP.push_back( 0.5*(5*redGauss[i]-greenGauss[i]-rdGrnGauss[i]) -   2*blueGauss[i] );
        byGssP.push_back(   2*blueGauss[i] - redGauss[i] - greenGauss[i]  + 0.5*rdGrnGauss[i]);
        gmGssP.push_back( 0.5*(5*greenGauss[i]-rdGrnGauss[i]-redGauss[i]) -   2*blueGauss[i] );

        rgGssN.push_back(-rgGssP[i]);
        rcGssN.push_back(-rcGssP[i]);
        byGssN.push_back(-byGssP[i]);
        gmGssN.push_back(-gmGssP[i]);
    }

    colorRG = centerSurround(rgGssP,rgGssN);
    colorRC = centerSurround(rcGssP,rcGssN);
    colorBY = centerSurround(byGssP,byGssN);
    colorGM = centerSurround(gmGssP,gmGssN);

    stcFeactures.push_back(colorRG);
    stcFeactures.push_back(colorRC);
    stcFeactures.push_back(colorBY);
    stcFeactures.push_back(colorGM);

    return stcFeactures;
}

/*********************************************************
**  Dynamic Features
*
*
**********************************************************/
Mat dynamicFeatures(Mat image, vector<Mat> &imageGM, vector<Mat> &imageGb){
    Mat     dynamic;
    uint          i;
    Mat filGM,filGb;
    Mat       GM,Gb;

    filter2D(image, filGM, CV_32FC3, krn7GM);
    filter2D(image, filGb, CV_32FC3, krn7Gb);

    if(imageGM.size()>=7){
        imageGM.erase( imageGM.begin() );
        imageGb.erase( imageGb.begin() );
    }

    imageGM.push_back(filGM);
    imageGb.push_back(filGb);

    GM = RM[imageGM.size()-1]*imageGM[0];
    for(i=1;i<imageGM.size();++i)
        GM += RM[imageGM.size()-1-i]*imageGM[i];

    Gb = Rb[imageGb.size()-1]*imageGb[0];
    for(i=1;i<imageGb.size();++i)
        Gb += Rb[imageGb.size()-1-i]*imageGb[i];

    /*GM = RM[0]*imageGM[0] + RM[1]*imageGM[1] + RM[2]*imageGM[2];
    GM+= RM[3]*imageGM[3] + RM[4]*imageGM[4] + RM[5]*imageGM[5];

    Gb = Rb[0]*imageGb[0] + Rb[1]*imageGb[1] + Rb[2]*imageGb[2];
    Gb+= Rb[3]*imageGb[3] + Rb[4]*imageGb[4] + Rb[5]*imageGb[5];*/

    dynamic = GM;
    // dynamic = GM + Gb;

    double  minVal, maxVal;
    Mat mapD;
    minMaxLoc(dynamic,&minVal,&maxVal);
    mapD = (dynamic-minVal)*255/(maxVal-minVal);

    mapD.convertTo(mapD, CV_8UC3);

    return mapD;
}

/*********************************************************
**  Saliency Map
*
*   Basado en Itti
*
**********************************************************/
Mat saliencyMap(Mat red, Mat green, Mat blue){
    vector<Feature> stcFeactures;
    Mat mapS;

    stcFeactures = staticFeatures(red,green,blue);

    int i = 7;
    double  minVal, maxVal;
    minMaxLoc(stcFeactures[i][0],&minVal,&maxVal);
    mapS = (stcFeactures[i][0]-minVal)*255/(maxVal-minVal);

    mapS.convertTo(mapS, CV_8UC3);

    return mapS;
}
