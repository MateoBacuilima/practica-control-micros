# Practica-Control-Micros
Este repositorio contiene los 4 puntos solicitados en la guía de prácticas facilitada.
## Introducción
Esta práctica consistió en la programación de un arduino, pero realizada de manera correcta, es decir, respetando todas los conceptos de programación C, revisados en clase.
## Primer programa
En el primer programa, se realiza una aplicación para resolver el problema de los rebotes eléctricos en un pulsador pero mediante programación, de esta forma, se evita el uso de capacitores, en esta primera instancia se resuelve este problema mediante máquina de estados, pero solo para un pulsante.
## Segundo programa
Aquí la aplicación del punto anterior toma un poco más de forma y se centra en realizar la misma aplicación pero para manejar este problema para dos pulsantes, esto empleando la misma máquina de estados pero que los pulsantes se controlen de manera independiente.
## Tercer programa
En el tercer programa, se busca realizar la aplicación de un semáforo y a la vez con el programa realizado de los pulsantes cambiar con el un pulsante la velocidad del semáforo entre x1, x2 y x0.5, con el otro pulsante el modo del semáforo, este tiene tres modos, el primero es el modo normal, el segundo es modo desconectado y el tercero es modo alarma. Esto se realiza usando modularización y se resuelve usando concepto de máquina de estados.
## Cuarto programa
El cuarto programa tiene la misma aplicación pero se agrega la modularización de un programa que imprima el estado de velocidad y modo del semáforo, además del estado de la máquina de estados de la solución de antirrebote de los dos pulsantes, esto se realiza mediante comunicación uart, que puede darse entre un par de arduinos, pero en general es la comunicación serial del arduino, por lo que el estado del semáforo y de la máquina de estados de los pulsantes se muestra en el monitor serial.
## Conclusión
Después de realizar todas las actividades solocitadas en la práctica, se puede decir, que se ha cumplido con todos los objetivos impuestos en la misma, pues e siguió paso a pasao cada punto establecido que a la final fueron etapas para llegar al programa 4 que es el resultado de toda la práctica, que resuelve tanto el problema de los pulsadores antirrebote, el semáforo y la impresión de los resultados empleando comunicación UART del Arduino.