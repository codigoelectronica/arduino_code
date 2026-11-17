# Control de brillo y contraste de un LCD 16x2

Este proyecto usa un Arduino Uno y tres pulsadores para ajustar los valores de brillo y contraste que se muestran en una pantalla LCD de 16 columnas por 2 filas.

## Contenido de la carpeta

- `sketch.ino`: programa del Arduino.
- `diagram.json`: diagrama del circuito para simularlo en Wokwi.
- `libraries.txt`: lista de bibliotecas usadas por la simulación.

## Funcionamiento

Al iniciar, la pantalla muestra `Brillo:` y `Contraste:`, ambos al 50 %. El botón **CAMBIO** alterna entre ajustar el brillo y ajustar el contraste. Los botones **MAX** y **MIN** incrementan o reducen en una unidad el valor seleccionado, limitado al intervalo de 0 % a 100 %. El cursor de la pantalla indica qué valor está seleccionado.

El programa utiliza el pin 13 como indicador mientras se procesa una pulsación. Los valores se convierten a una escala de 0 a 255 y se envían mediante `analogWrite`.

## Conexiones principales

- LCD: RS al pin 12, E al 11 y D4-D7 a los pines 5, 4, 3 y 2, respectivamente.
- Botones CAMBIO, MAX y MIN: pines 6, 7 y 8.
- Salidas PWM para los ajustes: pines 9 (brillo) y 10 (contraste).
- La simulación incluye un Arduino Uno, el LCD, los tres pulsadores, resistencias y un transistor.

![Texto alternativo](https://codigoelectronica.com/b/oscardevops/images/2015/01/Circito-lcd-brillo-contraste.png)
## Consideraciones

El circuito de `diagram.json` está preparado para Wokwi. En un montaje físico, verifica las conexiones y los requisitos de tu módulo LCD: el brillo de la retroiluminación y el contraste suelen necesitar circuitos o componentes de ajuste distintos. En particular, el pin de contraste del LCD normalmente se regula con un voltaje, por lo que aplicar PWM directamente puede no funcionar como se espera.

## Más información

[Artículo: Arduino LCD 2x16, brillo y contraste](https://codigoelectronica.com/blog/arduino-lcd2x16-brillo-contraste)
