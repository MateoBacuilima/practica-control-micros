#include <stdio.h>     //Se incluyen librerías respectivas.
#include <Arduino.h>
#include "uart.h"
#include "teclas.h"

unsigned long cont1=0;  // Se establecen algunas variables para determinar cuando imprimir resultados.
unsigned long cont2=0;
unsigned long cont3=0;
unsigned long cont4=0;

int modoant1=5;    // Variables para identificar cuando modos anteriores, se empieza en un modo aparte a los demas.
int modoant2=5;
estados modoimant1=estado5;
estados modoimant2=estado5;

void predataanti(struct impre impresion){  // Funcion para determinar el estado de la maquina de estados
    if (impresion.estado==modoimant1)      // de la función antirrebote.
    {
        cont1++;
    }
    else if (impresion.estado!=modoimant1)
    {
        cont1=0;
    }

    if (impresion.estado==modoimant2)
    {
        cont2++;
    }
    else if (impresion.estado!=modoimant2)
    {
        cont2=0;
    }
    
    
    
    if (impresion.name==2 && cont1==0)
    {
        Serial.println(" ");
        Serial.println("tecla de velocidad.");
    }
    else if (impresion.name==3 && cont2==0)
    {
        Serial.println(" ");
        Serial.println("tecla de modos");
    }
    

    switch (impresion.estado)
    {
    case estado1:
        if ((impresion.name==2 && cont1==0) || (impresion.name==3 && cont2==0))
        {
            Serial.println("La tecla no esta pulsada.");
            Serial.println(" ");
        }
        break;
    case estado2:
        if ((impresion.name==2 && cont1==0) || (impresion.name==3 && cont2==0))
        {
            Serial.println("Decidiendo si esta pulsada o no.");
            Serial.println(" ");
        }
        
        break;
    case estado3:
        if ((impresion.name==2 && cont1==0) || (impresion.name==3 && cont2==0))
        {
            Serial.println("La tecla se encuentra pulsada.");
            Serial.println(" ");
        }
        
        break;
    case estado4:
        if ((impresion.name==2 && cont1==0) || (impresion.name==3 && cont2==0))
        {
            Serial.println("Decidiendo si la tecla se dejo de pulsar.");
            Serial.println(" ");
        }
        
        break;
    
    default:
        break;
    }

    if (impresion.name==2)
    {
        modoimant1=impresion.estado;
    }
    else if (impresion.name==3)
    {
        modoimant2=impresion.estado;
    }
    

}

void predatasem(struct impresem modo){  //Funcion para determinar el estado de de la maquina de estados del semaforo.
    if (modoant1==modo.estadosem)
    {
        cont3++;
    }
    else if (modoant1!=modo.estadosem)
    {
        cont3=0;
    }

    if (modoant2==modo.estadosem)
    {
        cont4++;
    }
    else if (modoant2!=modo.estadosem)
    {
        cont4=0;
    }
    

    switch (modo.estadosem)  // Se va eligiendo el caso y se imprime el resultado.
    {
    case 0:
        if ((modo.name==2 && cont3==0) || (modo.name==3 && cont4==0))
        {
            if (modo.name==2)
            {
                Serial.println("El semáforo tiene una velocidad de x1.");
                Serial.println(" ");
            }
            else if (modo.name==3)
            {
                Serial.println("El semáforo esta en modo normal.");
                Serial.println(" ");
            }
         
        }
        
        break;
    case 1:
        if ((modo.name==2 && cont3==0) || (modo.name==3 && cont4==0))
        {
            if (modo.name==2)
            {
                Serial.println("El semáforo tiene una velocidad de x0.5.");
                Serial.println(" ");
            }
            else if (modo.name==3)
            {
                Serial.println("El semáforo esta desconectado.");
                Serial.println(" ");
            }
        }
        
        break;
    case 2:
        if ((modo.name==2 && cont3==0) || (modo.name==3 && cont4==0))
        {
            if (modo.name==2)
            {
                Serial.println("El semáforo tiene una velocidad de x2.");
                Serial.println(" ");
            }
            else if (modo.name==3)
            {
                Serial.println("El semáforo esta en modo alarma.");
                Serial.println(" ");
            }
        }
        
        break;
    
    default:
        break;
    }
    
    // Seccion para determinar cual de los dos pulsantes se uso y determinar el estado que tendra ese pulsante.
    if (modo.name==2)
    {
        modoant1=modo.estadosem;
    }
    else if (modo.name==3)
    {
        modoant2=modo.estadosem;
    }

}