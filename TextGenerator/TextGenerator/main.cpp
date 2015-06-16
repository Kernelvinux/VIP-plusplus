#include <iostream>

/*
Espacios de trabajo
***/
using namespace std;

/*
Tipo de datos
***/
typedef unsigned int       uint;

int main(){
    uint x,y;
    uint orden,ord;

    orden = 7;

    ord = (orden-1)/2;

//-- y<0
    for (y=ord;y>0;y--){
        cout << "outImg[i][j]+= ";
        // x<0
        for (x=ord;x>0;x--){
            cout << "image.at<float>(i-" << y << ",j-" << x << ")*";
            cout << "kernel[" << ord-y << "][" << ord-x << "] + ";
        }

        // x=0
        cout << "image.at<float>(i-" << y << ",  j)*";
        cout << "kernel["<< ord-y << "]["<< ord << "]+";

        // x>0
        for (x=1;x<ord;x++){
            cout << "image.at<float>(i-" << y << ",j+" << x << ")*";
            cout << "kernel[" << ord-y << "][" << ord+x << "] + ";
        }

        // x=ord
        cout << "image.at<float>(i-" << y << ",j+" << ord << ")*";
        cout << "kernel[" << ord-y << "][" << ord*2<< "];" << endl;
    }

//-- y=0
    cout << "outImg[i][j]+= ";
    // x<0
    for (x=ord;x>0;x--){
        cout << "image.at<float>(  i,j-" << x << ")*";
        cout << "kernel[" << ord << "][" << ord-x << "] + ";
    }

    // x=0
    cout << "image.at<float>(  i,  j)*";
    cout << "kernel["<< ord << "]["<< ord << "]+";

    // x>0
    for (x=1;x<ord;x++){
        cout << "image.at<float>(  i,j+" << x << ")*";
        cout << "kernel[" << ord << "][" << ord+x << "] + ";
    }

    // x=ord
    cout << "image.at<float>(  i,j+" << ord << ")*";
    cout << "kernel[" << ord << "][" << ord*2<< "];" << endl;


//-- y>0
    for (y=1;y<ord;y++){
        cout << "outImg[i][j]+= ";
        // x<0
        for (x=ord;x>0;x--){
            cout << "image.at<float>(i+" << y << ",j-" << x << ")*";
            cout << "kernel[" << ord+y << "][" << ord-x << "] + ";
        }

        // x=0
        cout << "image.at<float>(i+" << y << ",  j)*";
        cout << "kernel["<< ord+y << "]["<< ord << "]+";

        // x>0
        for (x=1;x<ord;x++){
            cout << "image.at<float>(i+" << y << ",j+" << x << ")*";
            cout << "kernel[" << ord+y << "][" << ord+x << "] + ";
        }

        // x=ord
        cout << "image.at<float>(i+" << y << ",j+" << ord << ")*";
        cout << "kernel[" << ord+y << "][" << ord*2<< "];" << endl;
    }

//-- y=ord
    cout << "outImg[i][j]+= ";
    // x<0
    for (x=ord;x>0;x--){
        cout << "image.at<float>(i+" << ord << ",j-" << x << ")*";
        cout << "kernel[" << ord*2 << "][" << ord-x << "] + ";
    }

    // x=0
    cout << "image.at<float>(i+" << ord << ",  j)*";
    cout << "kernel["<< ord*2 << "]["<< ord << "]+";

    // x>0
    for (x=1;x<ord;x++){
        cout << "image.at<float>(i+" << ord << ",j+" << x << ")*";
        cout << "kernel[" << ord*2 << "][" << ord+x << "] + ";
    }

    // x=ord
    cout << "image.at<float>(i+" << ord << ",j+" << ord << ")*";
    cout << "kernel[" << ord*2 << "][" << ord*2<< "];" << endl;

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

/*
image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j-1)*kernel[0][4] + image.at<float>(i-3,j-2)*kernel[0][5] + image.at<float>(i-3,j-3)*kernel[0][6];
image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j-1)*kernel[1][4] + image.at<float>(i-2,j-2)*kernel[1][5] + image.at<float>(i-2,j-3)*kernel[1][6];
image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j-1)*kernel[2][4] + image.at<float>(i-1,j-2)*kernel[2][5] + image.at<float>(i-1,j-3)*kernel[2][6];
 */

/*
image.at<float>(i-3,j-3)*kernel[0][0] + image.at<float>(i-3,j-2)*kernel[0][1] + image.at<float>(i-3,j-1)*kernel[0][2] + image.at<float>(i-3,  j)*kernel[0][3]+image.at<float>(i-3,j+1)*kernel[0][4] + image.at<float>(i-3,j+2)*kernel[0][5] + image.at<float>(i-3,j+3)*kernel[0][6];
image.at<float>(i-2,j-3)*kernel[1][0] + image.at<float>(i-2,j-2)*kernel[1][1] + image.at<float>(i-2,j-1)*kernel[1][2] + image.at<float>(i-2,  j)*kernel[1][3]+image.at<float>(i-2,j+1)*kernel[1][4] + image.at<float>(i-2,j+2)*kernel[1][5] + image.at<float>(i-2,j+3)*kernel[1][6];
image.at<float>(i-1,j-3)*kernel[2][0] + image.at<float>(i-1,j-2)*kernel[2][1] + image.at<float>(i-1,j-1)*kernel[2][2] + image.at<float>(i-1,  j)*kernel[2][3]+image.at<float>(i-1,j+1)*kernel[2][4] + image.at<float>(i-1,j+2)*kernel[2][5] + image.at<float>(i-1,j+3)*kernel[2][6];
image.at<float>(  i,j-3)*kernel[3][0] + image.at<float>(  i,j-2)*kernel[3][1] + image.at<float>(  i,j-1)*kernel[3][2] + image.at<float>(  i,  j)*kernel[3][3]+image.at<float>(  i,j+1)*kernel[3][4] + image.at<float>(  i,j+2)*kernel[3][5] + image.at<float>(  i,j+3)*kernel[3][6];
image.at<float>(i+1,j-3)*kernel[4][0] + image.at<float>(i+1,j-2)*kernel[4][1] + image.at<float>(i+1,j-1)*kernel[4][2] + image.at<float>(i+1,  j)*kernel[4][3]+image.at<float>(i+1,j+1)*kernel[4][4] + image.at<float>(i+1,j+2)*kernel[4][5] + image.at<float>(i+1,j+3)*kernel[4][6];
image.at<float>(i+2,j-3)*kernel[5][0] + image.at<float>(i+2,j-2)*kernel[5][1] + image.at<float>(i+2,j-1)*kernel[5][2] + image.at<float>(i+2,  j)*kernel[5][3]+image.at<float>(i+2,j+1)*kernel[5][4] + image.at<float>(i+2,j+2)*kernel[5][5] + image.at<float>(i+2,j+3)*kernel[5][6];
image.at<float>(i+3,j-3)*kernel[6][0] + image.at<float>(i+3,j-2)*kernel[6][1] + image.at<float>(i+3,j-1)*kernel[6][2] + image.at<float>(i+3,  j)*kernel[6][3]+image.at<float>(i+3,j+1)*kernel[6][4] + image.at<float>(i+3,j+2)*kernel[6][5] + image.at<float>(i+3,j+3)*kernel[6][6];
 */
