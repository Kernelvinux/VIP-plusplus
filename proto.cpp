#include "proto.h"

static float sumVector(float* vector, uint size){
    float sum=0;
    uint    i;

    for (i=0;i<size;i++) sum+=vector[i];
    return sum;
}

static int** generarRegionesP2P(Pair topPair, Pair lowPair, uint** topLabel, uint &sizeLabel){
    uint** lowLabel;
    uint  topRows, topCols,
          lowRows, lowCols;
    uint    i,j,
          i1,j1;
          iS,jS;

    topRows = topPair.rows;
    topCols = topPair.cols;

    lowRows = topPair.rows;
    lowCols = lowPair.cols;


//-- Inicializar punteros
    lowLabel = new int*[lowRows];
    for(i=0;i<lowRows;++i) lowLabel = new int [lowCols];

/********************************************
 *   __|___|___
 *     |1 2|
 *     |3 4|
 *   ----------
 *     |   |
 * *********************************************/

/*
    for (i=2,i1=3;i1<lowRows-2;i+=2,i1=i+1){
        iS = i*0.5;
        // Superior de la cuadricula {1,2}
        for (j=2,j1=3; j1<lowCols-2; j+=2,j1=j+1){
            jS = j*0.5;
            // Posicion 1 de la cuadricula
            if(lowPair.confidence[i][j] == 1){
                if(topLabel[iS][jS] != 0)
                    lowLabel[i][j] = topLabel[iS][jS];

                else if(topLabel[iS][jS-1] != 0){
                    if (topLabel[iS-1][jS] != 0){
                        if( (topPair.measurement.at<float>(iS-1,jS) - lowPair.measurement.at<float>(i,j))  >  );
                        else;
                    }
                    else
                        lowLabel[i][j] = topLabel[iS][jS-1];
                }else if(topLabel[iS-1][jS] != 0)
                    lowLabel[i][j] = topLabel[iS-1][jS];
            }
                
                
            // Posicion 2 de la cuadricula

        }
        // Superior de la cuadricula {3,4}
        for (j=2,j1=3; j1<lowCols-2; j+=2,j1=j+1){
            jS = j*0.5;
            // Posicion 3 de la cuadricula

            // Posicion 4 de la cuadricula

        }
    }*/

    for (i=0,i1=3;i1<lowRows;i+=2,i1=i+1){
        iS = i*0.5;
        // Superior de la cuadricula {1,2}
        for (j=0,j1=3; j1<lowCols; j+=2,j1=j+1){
            jS = j*0.5;

            // Misma etiqueta
            if (topLabel[iS][jS] != 0){
                // Posicion 1 de la cuadricula
                if(lowPair.confidence[ i][ j] == 1)  lowLabel[ i][ j] = topLabel[iS][jS];

                // Posicion 2 de la cuadricula
                if(lowPair.confidence[ i][j1] == 1)  lowLabel[ i][j1] = topLabel[iS][jS];

                // Posicion 3 de la cuadricula
                if(lowPair.confidence[i1][ j] == 1)  lowLabel[i1][ j] = topLabel[iS][jS];

                // Posicion 4 de la cuadricula
                if(lowPair.confidence[i1][j1] == 1)  lowLabel[i1][j1] = topLabel[iS][jS];
            }
            // Nueva etiqueta
            else{
                // Posicion 1 de la cuadricula
                if(lowPair.confidence[ i][ j] == 1){
                    ++sizeLabel;
                    lowLabel[ i][ j] = sizeLabel;
                }

                // Posicion 2 de la cuadricula
                if(lowPair.confidence[ i][j1] == 1){
                    ++sizeLabel;
                    lowLabel[ i][j1] = sizeLabel;
                }

                // Posicion 3 de la cuadricula
                if(lowPair.confidence[i1][ j] == 1){
                    ++sizeLabel;
                    lowLabel[i1][ j] = sizeLabel;
                }

                // Posicion 4 de la cuadricula
                if(lowPair.confidence[i1][j1] == 1){
                    ++sizeLabel;
                    lowLabel[i1][j1] = sizeLabel;
                }
            }
        }
    }

    delete topLabel;
    return lowLabel;
}

Pair convolutionSOR(Pair intPair){
    uint   rows,        // Numero de filas
           cols;        // Numero de columnas
    uint rows_2,        // rows - 2
         cols_2,        // cols - 2
         intRows_2,
         intCols_2;
    uint       i, j,    // Bucle principal
              _i,_j;    // Bucles internos
          i1_2,j1_2,    // Posicion en la siguiente escala (k-1)/2
            i4,j_4i;    // Posicion de la matriz en vector j-4*i
    bool** Ok;
    bool** confidence;
    bool   Ok_var;
    float* vNr;
    float   Nr;
    float  aux,aux2;
    float   dk;
    Pair   outPair;

    Mat image = intPair.measurement;
    bool** rk = intPair.confidence;

    rows = image.rows;
    cols = image.cols;

    intRows_2 = (int)rows/2;
    intCols_2 = (int)cols/2;
    Mat measurement(intRows_2,intRows_2,CV_32F);

//-- Inicializar punteros
    vNr = new float[16];
    Ok  = new bool*[4];
    for(i=0;i<4;i++) Ok[i] = new bool[4];

/*********************************************************
**  Bucle principal
**********************************************************/
    rows_2 = rows-2; cols_2 = cols-2;
    for(i=1;i<rows_2;i+=2) for(j=1;j<cols_2;j+=2){
        // Ok inicia como matriz de unos
        for(_i=0;_i<4;_i++) for(_j=0;_j<4;_j++) Ok[_i][_j] = 1;

        do{
        //--Calculo Nr
            for(_i=0;_i<4;++_i){
                i4 = 4*i;
                for(_j=0;_j<4;++_j){
                    j_4i = _j+i4;
                    vNr[j_4i] = rk[i+_i-1][j+_j-1]*wk[j_4i]*Ok[_i][_j];
                }
            }

            Nr  = sumVector(vNr,16);
            aux = 0;

        //--Calculo pest
            for(_i=0;_i<4;++_i){
                i4 = 4*i;
                for(_j=0;_j<4;++_j){
                    j_4i = _j+i4;
                    aux += image.at<float>(i+_i-1,j+_j-1) * vNr[j_4i];
                }
            }

            aux=aux/Nr;
        //--Calculo Ok,dk
            Ok_var = 0;
            for(_i=0;_i<4;++_i)for(_j=0;_j<4;++_j){
                aux2 = image.at<float>(i+_i-1,j+_j-1);
                dk = abs(aux2*aux2 - aux*aux);

                // Ok[_i][_j] inicia como 1
                if(dk>dmax2){
                    Ok[_i][_j] = 0;
                    Ok_var = 1;
                }
            }
        }while(Ok_var == 1);

        i1_2=i/2;j1_2=j/2;  // Posicion en la nueva escala
        measurement.at<float>(i1_2,j1_2) = aux;

    //--Calculo r* (confidence)
        confidence[i1_2][j1_2] = (Nr>=rmin)? 1:0;
    }

//--Problemas de frontera
    uint intRows_2_1 = intRows_2   - 1;
    uint intCols_2_1 = intCols_2   - 1;
    uint intRows_2_3 = intRows_2_1 - 2;
    uint intCols_2_3 = intCols_2_1 - 2;

    for(i=0;i<intRows_2_1;++i)
        measurement.at<float>(i,intCols_2_1) = measurement.at<float>(i,intCols_2_3);

    for(j=0;j<intCols_2_1;++j)
        measurement.at<float>(intRows_2_1,j) = measurement.at<float>(intRows_2_3,j);

    measurement.at<float>(intRows_2_1,intCols_2_1) = measurement.at<float>(intRows_2_3,intCols_2_3);

    outPair.measurement = measurement;
    outPair.confidence  = confidence ;

    outPair.rows = rows;
    outPair.cols = cols;

    return outPair;
}

float** homogeneusRegions(vector<Pair> pairs){
    uint     **label;
    uint       i,j,k;
    uint   rows,cols;
    uint   sizeLabel;

/*********************************************************
**  Top-down Pyramid
**********************************************************/
    // Inicializar label
    k = pairs.size() - 1;
    rows = pairs[k].rows;
    cols = pairs[k].cols;

    label = new uint [rows];
    for(i=0;i<rows;i++) label[i] = new uint[cols];

    for (i=0;i<rows;++i) for(j=0;j<cols;j++){
        if (pairs[k].confidence[i][j] == 1){
            ++sizeLabel;
            label[i][j] = sizeLabel;
        }
    }
    --k;

    // Bucle Generar regiones Top Pair to Low Pair
    while(k>0){
        label = generarRegionesP2P(pairs[k],pairs[k-1],label,sizeLabel);
        --k;
    }

/*********************************************************
**  Ellipse approximation
**********************************************************/



/*********************************************************
**  Blob merging
**********************************************************/

}

vector<Object> protoObject(Mat image){

}
