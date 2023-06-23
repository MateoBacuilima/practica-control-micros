#include <stdio.h>
#include <Arduino.h>
#include "teclas.h"


void setup() {
  inicializarMEF();
  pinMode(pulsa,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  actualizarMEF();
  Serial.println(salida);
}
 