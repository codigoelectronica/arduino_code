/**
 * Arduino control brillo led
 * Creado por: Oscar Fernandez <oscarfdzalz@gmail.com>
 * Publicado por: codigoelectronica.com <codigoelectronica@gmail.com>
 * 
 * Este código permite controlar la intensidad de luz de un led 
 * con un potenciometro
 */

int ledPin = 9;
int analogPin = 3;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  val = analogRead(analogPin);
  analogWrite(ledPin, val / 4);
}
