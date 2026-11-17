/*Luces ritmicas
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez Alzate @oscar_fedezal
* License: MIT
*/

//Creamos un array donde colocamos los números de los pines
//que van a crear el efecto rítmico
int inputsPins[] = {2,3,4,5,6,7,8,9};
int totalPins = sizeof(inputsPins) / sizeof(inputsPins[0]);

void setup() {
  
  for(int index = 0; index < totalPins; index ++){
    pinMode(inputsPins[index], OUTPUT);
  }
}

void loop() {
  
  for(int index = 0; index < totalPins; index ++){
    digitalWrite(inputsPins[index], HIGH);     
    delay(500);
  }
  
  for(int index = 0; index < totalPins; index ++){
    digitalWrite(inputsPins[index], LOW);     
    delay(200);
  }
  
}