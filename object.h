#ifndef OBJECT_H
#define OBJECT_H

#include "main.h"

struct Position{
    uint row,
         col;

    Position(uint x, uint y){row=x;col=y;}
};

class Object{
private:
/*********************************************************
**  Variables privadas
**********************************************************/
    uint         idx;   // Id del objeto
    float     weight;   // Peso atencional del objeto

//--Caracteristicas de forma
    Position topLeft;   // Posicion top-left en la imagen
    bool**     shape;   // Forma del objeto
    size_t      rows,   // Tamaño del objeto. Filas.
                cols;   // Tamaño del objeto. Columnas.

//--Ellipse
    float  an;  // Medida de area
    float *mn;  // Centroide
    float *In;  // Matriz de inercia
    float  pn;  // Promedio de la region

/*********************************************************
**  Funciones privadas
**********************************************************/


public:
/*********************************************************
**  Variables publicas
**********************************************************/
//--Raw moments
    uint u00,u01,u02,
         u11,u10,u20;

/*********************************************************
**  Contructores
**********************************************************/
    Object(); // Contructor nulo
    Object(uint label);

/*********************************************************
**  Selectores
**********************************************************/
    uint     getIdx       (){ return     idx;}
    float    getWeight    (){ return  weight;}
    Position getTopLeft   (){ return topLeft;}
    bool**   getShape     (){ return   shape;}
    size_t   getRows      (){ return    rows;}
    size_t   getCols      (){ return    cols;}

/*********************************************************
**  Funciones publicas
**********************************************************/
    void ellipse();
/*********************************************************
**  Destructor
**********************************************************/
    ~Object() {}
};

#endif // OBJECT_H
