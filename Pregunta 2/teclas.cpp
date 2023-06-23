#include <stdio.h>
#include <Arduino.h>
#include "teclas.h"

estados estadoact;
estados estadoact1;
estados estadoact2;
bool salida;
bool salidapul1;
bool salidapul2;
unsigned long timein;
unsigned long actime;

void inicializarMEF(void){
    estadoact1=estado1;
    estadoact2=estado1;
}

void actualizarMEF(struct pulsantes tecla){
    estadoact=tecla.estado;
    switch (estadoact)
    {
    case estado1:
        salida=false;
        if (digitalRead(tecla.name)==false)
        {
            estadoact=botonpress();
        }
        break;

    case estado2:
        actime=millis();
        if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==true))
        {
            estadoact=estado1;
        }
        else if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==false))
        {
            estadoact=estado3;
        }
        else estadoact=estado2;
        
        
        break;

    case estado3:
        salida=true;
        if (digitalRead(tecla.name)==true)
        {
            estadoact=botonnopress();
        }
        break;
    
    case estado4:
        actime=millis();
        if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==false))
        {
            estadoact=estado3;
        }
        else if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==true))
        {
            estadoact=estado1;
        }
        else estadoact=estado4;
        break;
    
    default:
        estadoact=estado1;
        break;
    }

    if (tecla.name==2)
    {
        estadoact1=estadoact;
        salidapul1=salida;
    }
    else if (tecla.name==3)
    {
        estadoact2=estadoact;
        salidapul2=salida;
    }
    

}

estados botonpress(void){
    estadoact=estado2;
    timein=millis();
    
    return estadoact;

}

estados botonnopress(void){
    estadoact=estado4;
    timein=millis();

    return estadoact;

}