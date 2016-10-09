/*Sensor de humedad con arduino
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez 
* License: MIT
*/

void setup() {
  Serial.begin(57600);
}

void loop() {
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(A0));  
  delay(100);
}
