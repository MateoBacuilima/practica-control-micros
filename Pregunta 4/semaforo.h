#include <stdio.h> //Se agregan librería de interes.
#include <Arduino.h>

enum states:int{  //Variable para determinar los diferentes estados del semaforo.
    state1,
    state2,
    state3,
    state4
};

extern bool semaforoleds[3];
void inicializarMEFsem();  // Funcion para inicializar y actualizar maquina de estados, solo se establece que en algún punto existira.
void actualizarMEFsem(int tiem,int mod);