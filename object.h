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
    uint         idx;   // Id del objeto
    float     weight;   // Peso atencional del objeto

    Position topLeft;   // Posicion top-left en la imagen
    bool**     shape;   // Forma del objeto
    size_t      rows,   // Tamaño del objeto. Filas.
                cols;   // Tamaño del objeto. Columnas.

/*********************************************************
**  Funciones privadas
**********************************************************/


public:
/*********************************************************
**  Contructores
**********************************************************/
    Object() {} // Contructor nulo

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

/*********************************************************
**  Destructor
**********************************************************/
    ~Object() {}
};

#endif // OBJECT_H
