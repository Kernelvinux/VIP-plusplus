#include "ntva.h"

/*********************************************************
**  SensoryEvidence
*
*   Retorna valor entero de evidencia sensorial.
*
**********************************************************/

int sensoryEvidence(Object Objeto, int numObj){

    // sensoryEvidence
    //       obj: Mapa de objetos. Etiquetados
    //    numObj: Numero de objetos

    int rows,cols;

    rows = Objeto.getrows();
    cols = Objeto.getCols();
    n           = zeros(numObj,3);
    numPixelObj = zeros(1,numObj);

    for i=1:rows
        for j=1:cols
            n( obj(i,j) ,1) = n( obj(i,j) ,1) + visualFn(i,j,1);
            n( obj(i,j) ,2) = n( obj(i,j) ,2) + visualFn(i,j,2);
            n( obj(i,j) ,3) = n( obj(i,j) ,3) + visualFn(i,j,3);

            numPixelObj( obj(i,j) ) = numPixelObj( obj(i,j) ) + 1;
        end
    end

    for x=1:numObj
        n(x,1) = n(x,1)/numPixelObj(1);
        n(x,2) = n(x,2)/numPixelObj(2);
        n(x,3) = n(x,3)/numPixelObj(3);
    end

    end
    */

    int** n;

    n = new int* [numObj];
    for(i=0;i<numObj;i++) n[i] = new int[3];

}


/*********************************************************
**  WeightObject
*
*   Retorna valor entero del peso relativo de la atención del objeto
*
**********************************************************/



/*********************************************************
**  NormalizeWeights
*
*   Retorna el valor entero del peso normalizado
*
**********************************************************/
