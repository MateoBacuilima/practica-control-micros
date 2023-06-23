#include <stdio.h>  // Se extraen algunas librerias.
#include <Arduino.h>
#include "teclas.h" //Se establece a teclas h como el .h del documento.

estados estadoact; //Se declaran variables enum, que se declararon en el .h
estados estadoact1;
estados estadoact2;
bool salida;         //Algunas variables de interes.
bool salidapul1;
bool salidapul2;
unsigned long timein;
unsigned long actime;
int vel=0;
int modo=0;
int sum=3;

void inicializarMEF(void){  //Función para inicializar la máquina de estados.
    estadoact1=estado1; 
    estadoact2=estado1;
}

void actualizarMEF(struct pulsantes tecla){ //Función para actualizar la máquina de estados del antirrebote.
//Hay diferentes estados, en resumen, el estado uno es que no esta pulsado, el 2 que se esta pulsando,
//el tres que se encuentra pulsado y el cuatro que se esta dejando de pulsar.
    estadoact=tecla.estado;
    switch (estadoact)
    {
    case estado1:
        salida=0;
        if (digitalRead(tecla.name)==0)
        {
            estadoact=botonpress();
        }
        break;

    case estado2:
        actime=millis();
        if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==1))
        {
            estadoact=estado1;
        }
        else if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==0))
        {
            estadoact=estado3;
            if (tecla.name==2)
            {
                vel++;
                if (vel==3)
                {
                    vel=0;
                }
            
            }
        
            else if (tecla.name==3)
            {
                modo++;
                if (modo==3)
                {
                    modo=0;
                }
            
            }
        }
        else estadoact=estado2;
        
        
        break;

    case estado3:
        salida=HIGH;

        if (digitalRead(tecla.name)==1)
        {
            estadoact=botonnopress();
        }
        break;
    
    case estado4:
        actime=millis();
        if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==0))
        {
            estadoact=estado3;
        }
        else if ((actime-timein>tecla.delay) && (digitalRead(tecla.name)==1))
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
    
    return estadoact; //Se retorna el estado cuando el boton es presionado

}

estados botonnopress(void){
    estadoact=estado4;
    timein=millis();

    return estadoact; //Se retorna el estado cuando se deja de pulsar.

}