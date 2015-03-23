/*Luces ritmicas potenciometro
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez
* License: MIT
*/
void setup() {
  //Iniciamos puerto serial
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  //Leemos puesrto analogo
  int sensorValue = analogRead(A0);
  //Calculamos voltaje
  float voltaje = (sensorValue*5.0)/1024;
  //Verificamos el voltaje para encender los leds
  if(voltaje < 0.8){
    digitalWrite(2, HIGH);             
    digitalWrite(3, LOW);              
    digitalWrite(4, LOW);   
    digitalWrite(5, LOW);   
    digitalWrite(6, LOW);   
    digitalWrite(7, LOW);       
  }else if(voltaje >= 0.9 & voltaje <= 1.6){
    digitalWrite(2, HIGH);             
    digitalWrite(3, HIGH);              
    digitalWrite(4, LOW);   
    digitalWrite(5, LOW);   
    digitalWrite(6, LOW);   
    digitalWrite(7, LOW);
  }else if(voltaje >= 1.7 & voltaje <= 2.5){
    digitalWrite(2, HIGH);             
    digitalWrite(3, HIGH);              
    digitalWrite(4, HIGH);   
    digitalWrite(5, LOW);   
    digitalWrite(6, LOW);   
    digitalWrite(7, LOW);
  }else if(voltaje >= 2.6 & voltaje <= 3.3){
    digitalWrite(2, HIGH);             
    digitalWrite(3, HIGH);              
    digitalWrite(4, HIGH);   
    digitalWrite(5, HIGH);   
    digitalWrite(6, LOW);   
    digitalWrite(7, LOW);
  }else if(voltaje >= 3.4 & voltaje <= 4.1){
    digitalWrite(2, HIGH);             
    digitalWrite(3, HIGH);              
    digitalWrite(4, HIGH);   
    digitalWrite(5, HIGH);   
    digitalWrite(6, HIGH);   
    digitalWrite(7, LOW);
  }else if(voltaje >= 4.2 & voltaje <= 5.0){
    digitalWrite(2, HIGH);             
    digitalWrite(3, HIGH);              
    digitalWrite(4, HIGH);   
    digitalWrite(5, HIGH);   
    digitalWrite(6, HIGH);   
    digitalWrite(7, HIGH);
  }
  Serial.println(voltaje);
  delay(10);        
}
