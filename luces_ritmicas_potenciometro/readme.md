# Indicador de nivel con potenciómetro

Este proyecto usa un Arduino Uno, un potenciómetro y ocho LED para mostrar una escala de nivel. El circuito se puede simular en Wokwi con `diagram.json`; el código está en `sketch.ino`.

## Contenido de la carpeta

- `sketch.ino`: lee el potenciómetro y controla cuántos LED se encienden.
- `diagram.json`: describe el circuito de Wokwi, con Arduino Uno, potenciómetro, ocho LED y ocho resistencias de 330 ohmios.

## Funcionamiento

El Arduino lee la señal analógica del potenciómetro por A0. La lectura, entre 0 y 1023, se convierte a una de nueve posiciones (de 0 a 8). Según la posición, se enciende una cantidad progresiva de LED: desde ninguno hasta los ocho. El programa actualiza la lectura aproximadamente cada 10 ms.

Los LED están controlados individualmente por los pines digitales 2 a 9. La tabla `vumeter` contiene los patrones binarios que forman la barra, y `lightVumeter` escribe cada bit en su LED correspondiente.

## Conexiones

- Potenciómetro: VCC a 5 V, GND a GND y SIG a A0.
- LED 1 a LED 8: ánodos a los pines 2 a 9, respectivamente.
- Cada cátodo de LED se conecta a GND mediante una resistencia de 330 ohmios.

![Indicador de nivel con potenciómetro](https://codigoelectronica.com/b/oscardevops/images/2026/07/17832069192501783206919250arduinovmetroconpotencimetro.webp)

## Nota

Aunque el código y el artículo lo llaman “vúmetro” o luces rítmicas, el circuito no recibe ni analiza audio. El nivel mostrado corresponde únicamente a la posición del potenciómetro.

## Más información

[Artículo: Arduino vúmetro con potenciómetro](https://codigoelectronica.com/blog/arduino-vumetro-con-potenciometro)
