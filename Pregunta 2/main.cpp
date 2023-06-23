#include <stdio.h>
#include <Arduino.h>
#include "teclas.h"


void setup() {
  inicializarMEF();
  Serial.begin(9600);
}

void loop() {
  struct pulsantes puls1={2,100,estadoact1};
  struct pulsantes puls2={3,100,estadoact2};
  actualizarMEF(puls1);
  actualizarMEF(puls2);
  Serial.print(salidapul1);
  Serial.println(salidapul2);
}
 