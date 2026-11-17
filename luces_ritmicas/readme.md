# Luces rítmicas con Arduino

Este proyecto controla ocho LED con un Arduino Uno y un registro de desplazamiento por código. El circuito se describe en `diagram.json` para su simulación en Wokwi y el programa está en `sketch.ino`.

## Contenido de la carpeta

- `sketch.ino`: configura las señales del arduino y envía patrones de encendido a sus salidas.
- `diagram.json`: circuito de Wokwi con Arduino Uno, ocho LED y ocho resistencias de 330 ohmios.

## Funcionamiento del programa

El Arduino usa tres pines para comunicarse con el registro:

- Pin 11: datos (`DS`).
- Pin 12: reloj (`SHCP`).
- Pin 8: latch o almacenamiento (`STCP`).


## Conexiones del circuito

El Arduino recibe alimentación de 5V y GND. Sus salidas Q2-Q9 se conectan a los ánodos de los LED; cada cátodo va a GND a través de una resistencia de 330 ohmios.
![Luces rítmicas con Arduino](https://codigoelectronica.com/b/oscardevops/images/2015/01/esquema-arduino-luces-ritmicas.png)

## Nota sobre el nombre

Aunque el proyecto se llama “Luces rítmicas”, el programa actual no lee música ni un sensor de sonido: genera una cuenta binaria con un intervalo fijo de un segundo.

## Más información

[Artículo: Arduino luces rítmicas](https://codigoelectronica.com/blog/arduino-luces-ritmicas)
