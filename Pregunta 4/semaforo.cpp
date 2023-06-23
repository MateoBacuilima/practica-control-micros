#include <stdio.h> // Se incluyen librerias
#include <Arduino.h>
#include <stdbool.h> // Se incluyen los respectivos encabezados para el semaforo.
#include "semaforo.h"

bool semaforoleds[3];  // Se establecen algunas variables de interés.
states actstate;
unsigned long newtime;
unsigned long lasttime;
int count=3;
float tiem;
bool inter=0;

void inicializarMEFsem(){ //Se genera la funcion para inicializar la maquina de estados del semaforo.
    actstate=state1;
    lasttime=millis();
}

void actualizarMEFsem(int pul1, int pul2){ // Se genera la funcion para actualizar el semaforo.
    switch (pul1)  //Aqui se elige entre las diferentes velocidades del semaforo.
    {
    case 1:
        tiem=2;
        break;
    case 2:
        tiem=0.5;
        break;
    case 0:
        tiem=1;
        break;
    
    default:
        tiem=1;
        break;
    }
    
    
    switch (actstate) //Aqui se establece la maquina de estados del semaforo.
    {
    case state1:
        
        switch (pul2)   //Se diferencia cada uno de los casos, donde cada uno dependiendo de la entrada
        {               //también se encuentra en algún modo de operación.
        case 0:
            newtime=millis();
            semaforoleds[0]={0};
            semaforoleds[1]={1};
            semaforoleds[2]={1};
            if (newtime-lasttime>(3000*tiem))
            {
                actstate=state2;
                lasttime=millis();
            }
            else actstate=state1;
            break;
        
        case 1:
            newtime=millis();
            if (newtime-lasttime>500*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={inter};
                semaforoleds[2]={1};
                inter=!inter;
                lasttime=millis();
            }
            
            break;

        case 2:
            newtime=millis();
            if (newtime-lasttime>1000*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={1};
                semaforoleds[2]={inter};
                inter=!inter;
                lasttime=millis();
            }
            break;
        
        default:
            break;
        }

        break;
    case state2:
        switch (pul2)
        {
        case 0:
            newtime=millis();
            semaforoleds[0]={1};
            semaforoleds[1]={0};
            semaforoleds[2]={1};
            if (newtime-lasttime>(500*tiem))
            {
                actstate=state3;
                lasttime=millis();
            }
            else actstate=state2;
            break;
        
        case 1:
            newtime=millis();
            if (newtime-lasttime>500*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={inter};
                semaforoleds[2]={1};
                inter=!inter;
                lasttime=millis();
            }
            
            
            break;

        case 2:
            newtime=millis();
            if (newtime-lasttime>1000*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={1};
                semaforoleds[2]={inter};
                inter=!inter;
                lasttime=millis();
            }
            break;
        
        default:
            break;
        }
        break;
    case state3:
        switch (pul2)
        {
        case 0:
            newtime=millis();
            semaforoleds[0]={1};
            semaforoleds[1]={1};
            semaforoleds[2]={0};
            if (newtime-lasttime>(2000*tiem))
            {
                actstate=state1;
                lasttime=millis();
            }
            else actstate=state3;
            break;
        
        case 1:
            newtime=millis();
            if (newtime-lasttime>500*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={inter};
                semaforoleds[2]={1};
                inter=!inter;
                lasttime=millis();
            }
            
            
            break;

        case 2:
            newtime=millis();
            if (newtime-lasttime>1000*tiem)
            {
                semaforoleds[0]={1};
                semaforoleds[1]={1};
                semaforoleds[2]={inter};
                inter=!inter;
                lasttime=millis();
            }
            break;
        
        default:
            break;
        }
        break;

    default:
        actstate=state1; //Este es el estado por defecto.
        break;
    }

}