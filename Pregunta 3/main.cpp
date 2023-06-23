#include <stdio.h>
#include <Arduino.h>
#include "semaforo.h"
#include "teclas.h"

void setup() {
  Serial.begin(9600);
  inicializarMEFsem();
  for (int i = 0; i < sum; i++)
  {
    pinMode(4+i,OUTPUT);
  }
  inicializarMEF();
}

void loop() {
  struct pulsantes puls1={2,100,estadoact1};
  struct pulsantes puls2={3,100,estadoact2};
  actualizarMEF(puls1);
  actualizarMEF(puls2);
  
  Serial.print(vel);
  Serial.println(modo);
  Serial.print(semaforoleds[0]);
  Serial.print(semaforoleds[1]);
  Serial.println(semaforoleds[2]); 

  actualizarMEFsem(vel,modo);
  
  digitalWrite(4,semaforoleds[0]);
  digitalWrite(5,semaforoleds[1]);
  digitalWrite(6,semaforoleds[2]);

}
