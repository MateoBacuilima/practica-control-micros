#include <stdio.h>
#include <Arduino.h>
#include <stdbool.h>
#include "semaforo.h"

bool semaforoleds[3];
states actstate;
unsigned long newtime;
unsigned long lasttime;
int count=3;
float tiem;
bool inter=0;

void inicializarMEFsem(){
    actstate=state1;
    lasttime=millis();
}

void actualizarMEFsem(int pul1, int pul2){
    switch (pul1)
    {
    case 1:
        tiem=1.5;
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
    
    
    switch (actstate)
    {
    case state1:
        
        switch (pul2)
        {
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
            if (newtime-lasttime>500)
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
            if (newtime-lasttime>1000)
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
            if (newtime-lasttime>500)
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
            if (newtime-lasttime>1000)
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
            if (newtime-lasttime>500)
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
            if (newtime-lasttime>1000)
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
        actstate=state1;
        break;
    }

}