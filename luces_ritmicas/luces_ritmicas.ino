/*Luces ritmicas
*Copyright: codigoelectronica.com
* Author: Oscar Fernandez
* License: MIT
*/

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

void loop() {
  digitalWrite(2, HIGH);   
  delay(1000);             
  digitalWrite(3, HIGH);   
  delay(1000);             
  digitalWrite(4, HIGH);   
  delay(1000);
  digitalWrite(5, HIGH);   
  delay(1000);
  digitalWrite(6, HIGH);   
  delay(1000);
  digitalWrite(7, HIGH);   
  delay(1000);
  digitalWrite(2, LOW);    
  delay(1000);
  digitalWrite(3, LOW);    
  delay(1000);
  digitalWrite(4, LOW);    
  delay(1000);
  digitalWrite(5, LOW);    
  delay(1000);
  digitalWrite(6, LOW);    
  delay(1000);
  digitalWrite(7, LOW);    
  delay(1000);
}
