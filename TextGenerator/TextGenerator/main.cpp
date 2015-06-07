#include <iostream>

using namespace std;

int main(){

    /*Declaracion de variables*/
    int i=1,j=0;
    int x,y;

    /*Generador de Ecuaciones de Filtrado*/
    y=i;

    x=j;
    cout <<"outImg[i][j] = image[i" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";
    for (x=x+1;x<3;x++){
        cout << " + image[i" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";}
    cout <<" + image[i" << y-3 << "][j  ]*kernel[" << y << "][" << x << "]";
    for (x=1;x<4;x++){
        cout << " + image[i" << y-3 << "][j+" << x << "]*kernel[" << y << "][" << x+3 << "]";}
    cout << ";" << endl;

    for (y=y+1;y<3;y++){
        x=j;
        cout <<"outImg[i][j]+= image[i" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";
        for (x=1;x<3;x++){
            cout << " + image[i" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";}
        cout <<" + image[i" << y-3 << "][j  ]*kernel[" << y << "][" << x << "]";
        for (x=1;x<4;x++){
            cout << " + image[i" << y-3 << "][j+" << x << "]*kernel[" << y << "][" << x+3 << "]";}
    cout << ";" << endl;
    }

    x=j;
    cout <<"outImg[i][j]+= image[i  ][j" << x-3 << "]*kernel[" << y << "][" << x << "]";
    for (x=1;x<3;x++){
        cout << " + image[i  ][j" << x-3 << "]*kernel[" << y << "][" << x << "]";}
    cout <<" + image[i  ][j  ]*kernel[" << y << "][" << x << "]";
    for (x=1;x<4;x++){
        cout << " + image[i  ][j+" << x << "]*kernel[" << y << "][" << x+3 << "]";}
    cout << ";" << endl;

    for (y=y+1;y<7;y++){
        x=j;
        cout <<"outImg[i][j]+= image[i+" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";
        for (x=1;x<3;x++){
            cout << " + image[i+" << y-3 << "][j" << x-3 << "]*kernel[" << y << "][" << x << "]";}
        cout <<" + image[i+" << y-3 << "][j  ]*kernel[" << y << "][" << x << "]";
        for (x=1;x<4;x++){
            cout << " + image[i+" << y-3 << "][j+" << x << "]*kernel[" << y << "][" << x+3 << "]";}
    cout << ";" << endl;
    }

    return 0;
}

/*
outImg[i][j] = image[i-3][j-3]*kernel[0][0] + image[i-3][j-2]*kernel[0][1] + image[i-3][j-1]*kernel[0][2] + image[i-3][j  ]*kernel[0][3] + image[i-3][j+1]*kernel[0][4] + image[i-3][j+2]*kernel[0][5] + image[i-3][j+3]*kernel[0][6];
outImg[i][j]+= image[i-2][j-3]*kernel[1][0] + image[i-2][j-2]*kernel[1][1] + image[i-2][j-1]*kernel[1][2] + image[i-2][j  ]*kernel[1][3] + image[i-2][j+1]*kernel[1][4] + image[i-2][j+2]*kernel[1][5] + image[i-2][j+3]*kernel[1][6];
outImg[i][j]+= image[i-1][j-3]*kernel[2][0] + image[i-1][j-2]*kernel[2][1] + image[i-1][j-1]*kernel[2][2] + image[i-1][j  ]*kernel[2][3] + image[i-1][j+1]*kernel[2][4] + image[i-1][j+2]*kernel[2][5] + image[i-1][j+3]*kernel[2][6];
outImg[i][j]+= image[  i][j-3]*kernel[3][0] + image[  i][j-2]*kernel[3][1] + image[  i][j-1]*kernel[3][2] + image[  i][j  ]*kernel[3][3] + image[  i][j+1]*kernel[3][4] + image[  i][j+2]*kernel[3][5] + image[  i][j+3]*kernel[3][6];
outImg[i][j]+= image[i+1][j-3]*kernel[4][0] + image[i+1][j-2]*kernel[4][1] + image[i+1][j-1]*kernel[4][2] + image[i+1][j  ]*kernel[4][3] + image[i+1][j+1]*kernel[4][4] + image[i+1][j+2]*kernel[4][5] + image[i+1][j+3]*kernel[4][6];
outImg[i][j]+= image[i+2][j-3]*kernel[5][0] + image[i+2][j-2]*kernel[5][1] + image[i+2][j-1]*kernel[5][2] + image[i+2][j  ]*kernel[5][3] + image[i+2][j+1]*kernel[5][4] + image[i+2][j+2]*kernel[5][5] + image[i+2][j+3]*kernel[5][6];
outImg[i][j]+= image[i+3][j-3]*kernel[6][0] + image[i+3][j-2]*kernel[6][1] + image[i+3][j-1]*kernel[6][2] + image[i+3][j  ]*kernel[6][3] + image[i+3][j+1]*kernel[6][4] + image[i+3][j+2]*kernel[6][5] + image[i+3][j+3]*kernel[6][6];
*/
