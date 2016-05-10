/**Arduino input output
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez @oscar_fedezal
* License: MIT*/

//Se declaran los pines en un array
int pinInput[] = {2, 3, 4, 5};
int pinOutput[] = {6, 7, 8, 9};

void setup() {
  //Se declaran los pines como entrada o salida
  for(int i = 0; i < 4; i++){
    pinMode(pinInput[i], INPUT);
    pinMode(pinOutput[i], OUTPUT);
  }
}

void loop() {
  for(int i = 0; i < 4; i++){
    //Leemos el valor del pin que esta en el array
    int val = digitalRead(pinInput[i]);
    //Si el valor es 1 lo activamos, de lo contrario desactivamos
    if(val == 1){
      digitalWrite(pinOutput[i], HIGH);
    }else{
      digitalWrite(pinOutput[i], LOW);
    }
  }
}
