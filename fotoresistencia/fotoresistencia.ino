/* Fotoresistencia o LDR
 * Copyright: codigoelectronica.com
 * Author: Oscar Fernandez Alzate
 * License: MIT
 */

const int sensorPin = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  int valueAnalog = analogRead(sensorPin);
  Serial.println(valueAnalog);
}
