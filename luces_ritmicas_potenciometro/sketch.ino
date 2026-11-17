/*Luces ritmicas potenciómetro
* Copyright: codigoelectronica.com <codioelectronica@gmail.com>
* Author: Oscar Fernandez Alzate <oscarfdzalz@gmail.com>
* License: MIT
*/
//Pines para los leds
const int pins[8] = {2,3,4,5,6,7,8,9}; 

//Secuencia de los leds
const byte vumeter[9] = {0b00000000,  //0
                          0b00000001, //1
                          0b00000011, //2
                          0b00000111, //3
                          0b00001111, //4
                          0b00011111, //5
                          0b00111111, //6
                          0b01111111, //7
                          0b11111111  //8
                        };

void setup() {
  //Ponemos los pines como salida
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);  
  }
}

void loop() {
  //Lectura del puerto A0
  int valueAnalog = analogRead(0);
  //Conversión para obtener la secuencia
  int positionLed = (valueAnalog * 9) / 1024;
  delay(10);
  lightVumeter(positionLed);
}

/**
 * Función para encender los led segun el número de
 * secuencia 
 */
void lightVumeter(int number) {
  byte numberBit = vumeter[number];
  for (int i = 0; i < 8; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
}
