#ifndef TECLAS_H
#define TECLAS_H
#include <stdio.h>
#include <Arduino.h>

enum estados:int{
    estado1,
    estado2,
    estado3,
    estado4
};

struct pulsantes
{
    int name;
    unsigned long delay;
    estados estado;
};


extern estados estadoact;
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

estados botonpress(void);
estados botonnopress(void);
void inicializarMEF(void);
void actualizarMEF(struct pulsantes tecla);

#endif