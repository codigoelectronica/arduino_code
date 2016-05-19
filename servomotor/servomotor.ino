//Se llama la libreria del servo
#include <Servo.h>

//Pin a conectar el servo
int pinServo = 2;

//Se crea un nuevo objeto del servo
Servo servo;

void setup() {
  //Inicializamos el servo con el pin declarado
  servo.attach(pinServo);
  Serial.begin(9600);
}

void loop() {
  //Movemos el servomotor a 10°
  servo.write(30);
  delay(2000);
  //Leemos la posición de servomotor y la mostramos
  Serial.println(servo.read());
  servo.write(90);
  delay(2000);
  Serial.println(servo.read());
  servo.write(160);
  delay(2000);
  Serial.println(servo.read());
}
