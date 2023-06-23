#include <stdio.h>   //Se indican algunas librerías.
#include <Arduino.h>
#include "semaforo.h" //Se indican los .h que serán empleados.
#include "teclas.h"
#include "uart.h"

void setup() {  //Se inicializan los respectivos puertos de salida.
  Serial.begin(9600);   
  inicializarMEFsem();
  for (int i = 0; i < sum; i++)
  {
    pinMode(4+i,OUTPUT);
  }
  inicializarMEF();
}

void loop() {
  //Se crean algunas estructuras.
  struct pulsantes puls1={2,100,estadoact1};
  struct pulsantes puls2={3,100,estadoact2};
  //Se llama a la maquina de estados de los pulsantes.
  actualizarMEF(puls1);
  actualizarMEF(puls2);
  //Se llama a la maquina de estados del semaforo.
  actualizarMEFsem(vel,modo);

  // Se escribre el estado de los leds del semaforo.
  for (int i = 0; i < sum; i++)
  {
    digitalWrite(4+i,semaforoleds[i]);
  }

  //Se generan estructuras para imprimer los resultados.

  struct impre pul1={2,estadoact1};
  struct impre pul2={3,estadoact2};
  struct impresem pulsa2={2,vel};
  struct impresem pulsa3={3,modo};

  //Se llama al módulo de impresión.
  predataanti(pul1);
  predataanti(pul2);
  predatasem(pulsa2);
  predatasem(pulsa3);
}
