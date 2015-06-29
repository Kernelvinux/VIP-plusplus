#ifndef NTVA_H
#define NTVA_H

#include "main.h"
#include "object.h"

/*
 * Espacios de Trabajo
 ***/
using namespace  cv;
using namespace std;

/*
 * Funciones
 ***/
int sensoryEvidence(Object Objeto, int numObj);
int weightObject(int n, int PI);
int normalizeWeights(int w);


#endif // NTVA_H
