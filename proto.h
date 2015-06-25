#ifndef PROTO_H
#define PROTO_H

#include "main.h"

/*
Constantes
***/
const float wk[16] = {0.0625,0.1875,0.1875,0.0625,
                      0.1875,0.5625,0.5625,0.1875,
                      0.1875,0.5625,0.5625,0.1875,
                      0.0625,0.1875,0.1875,0.0625};

const float dmax  = 0.2;
const float dmax2 = dmax*dmax;
const float cmin  = 0.5;
const float mthr  = 0.5;
const float miter = 5;
const float rmin  = 0.5;

/*
Tipo de dato
***/
struct Pair{
    Mat     measurement;
    bool**   confidence;

    uint      rows,cols;
};

/*
Funciones
***/
Pair convolutionSOR(Pair intPair);

#endif // PROTO_H
