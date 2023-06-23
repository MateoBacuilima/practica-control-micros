#include <stdio.h>
#include <Arduino.h>

enum states:int{
    state1,
    state2,
    state3,
    state4
};

extern bool semaforoleds[3];
void inicializarMEFsem();
void actualizarMEFsem(int tiem,int mod);