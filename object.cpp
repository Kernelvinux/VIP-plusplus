#include "object.h"

/*********************************************************
**  Contructores
**********************************************************/
Object::Object(){
    // Inicializar punteros
    mn    = new float [2];
    In    = new float*[2];
    In[0] = new float [2];
    In[1] = new float [2];

    u00 = 0; u01 = 0; u02 = 0;
    u11 = 0; u10 = 0; u20 = 0;
}

Object::Object(uint label){
    // Inicializar punteros
    mn    = new float [2];
    In    = new float*[2];
    In[0] = new float [2];
    In[1] = new float [2];

    u00 = 0; u01 = 0; u02 = 0;
    u11 = 0; u10 = 0; u20 = 0;

    idx = label;
}

/*********************************************************
**  Funciones públicas
**********************************************************/
void Object::ellipse(){
    an = u00;

    mn[0] = u01/u00;
    mn[1] = u10/u00;

    float aux = mn[0]*mn[1] ;

    In[0][0] =  u02/u00 - mn[0]*mn[0];
    In[0][1] =  u11/u00 - aux;
    In[1][0] = In[0][1] - aux;
    In[1][1] =  u20/u00 - mn[1]*mn[1];
}
