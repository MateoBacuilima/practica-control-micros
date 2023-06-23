#include <stdio.h>  //Se incluyen librerias.
#include <Arduino.h>
#include "teclas.h" //Se indica que se usara el .h de teclas.


struct impre  //Se establece la estructura impre para contener el nombre del pulsante y el estado que se encuentra
{
    int name;
    estados estado;
};

struct impresem  //Se establece estructura para saber el nombre del pulsante y el estado del semaforo.
{
    int name;
    int estadosem;
};

void predataanti(struct impre impresion); //Lineas para hacer entender al codigo que en algun punto estas funciones se usaran.
void predatasem(struct impresem modo);