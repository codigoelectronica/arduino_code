/*Luces ritmicas
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez Alzate @oscar_fedezal
* License: MIT
*/

//Creamos un array donde colocamos los números de los pines
//que van a crear el efecto rítmico
int inputsPints[] = {2,3,4,5,6,7,8};


void setup() {
  
  //En un for recorremos el array completo
  for(int index = 0; index < 7; index ++){
    //Colocamos como salida los pines declarados en el array
    pinMode(inputsPints[index], OUTPUT);
  }
}

void loop() {
  
  for(int index = 0; index < 7; index ++){
    //En el mismo for, colocamos como estado alto al pin
    digitalWrite(inputsPints[index], HIGH);     
    delay(500);
  }
  
  for(int index = 0; index < 7; index ++){
    //En el mismo for, colocamos como estado bajo al pin
    digitalWrite(inputsPints[index], LOW);     
    delay(200);
  }
}
