#ifndef TECLAS_H
#define TECLAS_H
#include <stdio.h>  //Se definen algunas librerias.
#include <Arduino.h>

enum estados:int{  //Estos son los estado del antirrebote.
    estado1,
    estado2,
    estado3,
    estado4,
    estado5
};

struct pulsantes  //Se genera estructura para pulsantes.
{
    int name;
    unsigned long delay;
    estados estado;
};


extern estados estadoact;  //Se declara que algunas variables que estan en el .cpp puedan ser usadas de forma exterior.
extern estados estadoact1;
extern estados estadoact2;
extern bool salida;
extern bool salidapul1;
extern bool salidapul2;
extern unsigned long timein;
extern unsigned long actime;
extern int vel;
extern int modo;
extern int sum;

estados botonpress(void);  //Se indica sobre la existencia de futuras funciones dentro del .cpp
estados botonnopress(void);
void inicializarMEF(void);
void actualizarMEF(struct pulsantes tecla);

#endif