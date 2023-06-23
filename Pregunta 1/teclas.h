#ifndef TECLAS_H
#define TECLAS_H
#include <stdio.h>
#include <Arduino.h>

enum estados{
    estado1,
    estado2,
    estado3,
    estado4
};

extern estados estadoact;
extern bool salida;
extern unsigned long timein;
extern unsigned long actime;
extern int pulsa;

void botonpress(void);
void botonnopress(void);
void inicializarMEF(void);
void actualizarMEF(void);

#endif