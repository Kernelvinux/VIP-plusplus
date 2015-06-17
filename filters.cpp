#include "filters.h"
/*********************************************************
**  Convolucion kernel 7x7
*
*   Codigo Piero
*   Piero Aqui!!!!!!!!!!
*
**********************************************************/
/*
Mat convolutionK7(Mat image, const float kernel[7][7]){
    Mat  outImg;   // Salida de la funcion
    uint i,j;      // Variables de bucle
    size_t rows, cols;

    rows = image.rows;
    cols = image.cols;

    outImg = Mat(rows,cols,CV_32FC1);


    // Cuerpo
    for (i=0;i<rows;i++) for(j=0;j<cols;j++){
        outImg.at<float>(i,j) = image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    // Margen superior
    i=2;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= 2*(image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6]);
        outImg.at<float>(i,j)+= image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    i=1;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= 2*(image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6]);
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    i=0;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= 2*(image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6]);
    }

    // Margen Inferior
    i=rows-3;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= 2*(image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6]);
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
    }

    i=rows-2;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= 2*(image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6]);
        outImg.at<float>(i,j)+= image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
   }

    i=rows-1;
    for (j=3;j<cols-3;j++){
        outImg.at<float>(i,j) = 2*(image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6]);
        outImg.at<float>(i,j)+= 2*(image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6]);
        outImg.at<float>(i,j)+= image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
    }

    // Margen Izquierda
    j=2;
    for (i=3;i<rows-3;i++){
        outImg.at<float>(i,j) = image.at<float>(i-3,j-2)*kernel[0][1] + 2*image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,j-2)*kernel[1][1] + 2*image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= image.at<float>(i-1,j-2)*kernel[2][1] + 2*image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= image.at<float>(  i,j-2)*kernel[3][1] + 2*image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= image.at<float>(i+1,j-2)*kernel[4][1] + 2*image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-2)*kernel[5][1] + 2*image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,j-2)*kernel[6][1] + 2*image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    j=1;
    for (i=3;i<rows-3;i++){
        outImg.at<float>(i,j) = image.at<float>(i-3,j-1)*kernel[0][2] + 2*image.at<float>(i-3,  j)*kernel[0][3] + 2*image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,j-1)*kernel[1][2] + 2*image.at<float>(i-2,  j)*kernel[1][3] + 2*image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= image.at<float>(i-1,j-1)*kernel[2][2] + 2*image.at<float>(i-1,  j)*kernel[2][3] + 2*image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= image.at<float>(  i,j-1)*kernel[3][2] + 2*image.at<float>(  i,  j)*kernel[3][3] + 2*image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= image.at<float>(i+1,j-1)*kernel[4][2] + 2*image.at<float>(i+1,  j)*kernel[4][3] + 2*image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
        outImg.at<float>(i,j)+= image.at<float>(i+2,j-1)*kernel[5][2] + 2*image.at<float>(i+2,  j)*kernel[5][3] + 2*image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,j-1)*kernel[6][2] + 2*image.at<float>(i+3,  j)*kernel[6][3] + 2*image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
    }

    j=0;
    for (i=3;i<rows-3;i++){
        outImg.at<float>(i,j) = image.at<float>(i-3,  j)*kernel[0][3] + 2*image.at<float>(i-3,j+1)*kernel[0][4] + 2*image.at<float>(i-3,j+2)*kernel[0][5] + 2*image.at<float>(i-3,j+3)*kernel[0][6];
        outImg.at<float>(i,j)+= image.at<float>(i-2,  j)*kernel[1][3] + 2*image.at<float>(i-2,j+1)*kernel[1][4] + 2*image.at<float>(i-2,j+2)*kernel[1][5] + 2*image.at<float>(i-2,j+3)*kernel[1][6];
        outImg.at<float>(i,j)+= image.at<float>(i-1,  j)*kernel[2][3] + 2*image.at<float>(i-1,j+1)*kernel[2][4] + 2*image.at<float>(i-1,j+2)*kernel[2][5] + 2*image.at<float>(i-1,j+3)*kernel[2][6];
        outImg.at<float>(i,j)+= image.at<float>(  i,  j)*kernel[3][3] + 2*image.at<float>(  i,j+1)*kernel[3][4] + 2*image.at<float>(  i,j+2)*kernel[3][5] + 2*image.at<float>(  i,j+3)*kernel[3][6];
        outImg.at<float>(i,j)+= image.at<float>(i+1,  j)*kernel[4][3] + 2*image.at<float>(i+1,j+1)*kernel[4][4] + 2*image.at<float>(i+1,j+2)*kernel[4][5] + 2*image.at<float>(i+1,j+3)*kernel[4][6];
        outImg.at<float>(i,j)+= image.at<float>(i+2,  j)*kernel[5][3] + 2*image.at<float>(i+2,j+1)*kernel[5][4] + 2*image.at<float>(i+2,j+2)*kernel[5][5] + 2*image.at<float>(i+2,j+3)*kernel[5][6];
        outImg.at<float>(i,j)+= image.at<float>(i+3,  j)*kernel[6][3] + 2*image.at<float>(i+3,j+1)*kernel[6][4] + 2*image.at<float>(i+3,j+2)*kernel[6][5] + 2*image.at<float>(i+3,j+3)*kernel[6][6];
    }

    // Esquinas
    for (i=0;     i<3;   i++) for (j=0     ;j<3;   j++)  outImg.at<float>(i,j) = image.at<float>(     3,3     );
    for (i=0;     i<3;   i++) for (j=cols-3;j<cols;j++)  outImg.at<float>(i,j) = image.at<float>(     3,cols-4);
    for (i=rows-3;i<rows;i++) for (j=cols-3;j<cols;j++)  outImg.at<float>(i,j) = image.at<float>(rows-4,cols-4);
    for (i=rows-3;i<rows;i++) for (j=0     ;j<3;   j++)  outImg.at<float>(i,j) = image.at<float>(rows-4,3     );

    return outImg;
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
    for (i=3;i<rows-3;i++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + 2*image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + 2*image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + 2*image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + 2*image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + 2*image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + 2*image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + 2*image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5];
    }

    i=cols-2;
    for (i=3;i<rows-3;i++){
        outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + 2*image[i-3][j-1]*kernel[0][2] + 2*image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4];
        outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + 2*image[i-2][j-1]*kernel[1][2] + 2*image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4];
        outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + 2*image[i-1][j-1]*kernel[2][2] + 2*image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4];
        outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + 2*image[  i][j-1]*kernel[3][2] + 2*image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4];
        outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + 2*image[i+1][j-1]*kernel[4][2] + 2*image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4];
        outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + 2*image[i+2][j-1]*kernel[5][2] + 2*image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4];
        outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + 2*image[i+3][j-1]*kernel[6][2] + 2*image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4];
    }

    i=cols-1;
    for (i=3;i<rows-3;i++){
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
*/
