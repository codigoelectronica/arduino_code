/* Fotoresistencia o LDR
 * Copyright: codigoelectronica.com
 * Author: Oscar Fernandez Alzate
 * License: MIT
 */

const int ledPin = 13;
const int sensorPin = 0;


void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valueAnalog = analogRead(sensorPin);
  Serial.println(valueAnalog);
}
