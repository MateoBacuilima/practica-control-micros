#include <stdio.h>
#include <Arduino.h>
#include "teclas.h"

estados estadoact;
bool salida;
unsigned long timein;
unsigned long actime;
int pulsa=2;

void inicializarMEF(void){
    estadoact=estado1;
}

void actualizarMEF(void){
    switch (estadoact)
    {
    case estado1:
        salida=false;
        if (digitalRead(pulsa)==false)
        {
            botonpress();
        }
        break;

    case estado2:
        actime=millis();
        if ((actime-timein>100) && (digitalRead(pulsa)==true))
        {
            estadoact=estado1;
        }
        else if ((actime-timein>100) && (digitalRead(pulsa)==false))
        {
            estadoact=estado3;
        }
        else estadoact=estado2;
        
        
        break;

    case estado3:
        salida=true;
        if (digitalRead(pulsa)==true)
        {
            botonnopress();
        }
        break;
    
    case estado4:
        actime=millis();
        if ((actime-timein>100) && (digitalRead(pulsa)==false))
        {
            estadoact=estado3;
        }
        else if ((actime-timein>100) && (digitalRead(pulsa)==true))
        {
            estadoact=estado1;
        }
        else estadoact=estado4;
        break;
    
    default:
        estadoact=estado1;
        break;
    }

}

void botonpress(void){
    estadoact=estado2;
    timein=millis();
}

void botonnopress(void){
    estadoact=estado4;
    timein=millis();
}