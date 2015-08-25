/**Arduino pulsadores
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez @oscarfdzalz
* License: MIT*/

int led2 = 2;
int led3 = 3;

int inputPin5 = 5;
int inputPin6 = 6;

int val2 = 0;
int val3 = 0;


void setup() {
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(inputPin5, INPUT);
  pinMode(inputPin6, INPUT);
}

void loop() {
  val2 = digitalRead(inputPin5);
  if (val2 == HIGH) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }
  
  val3 = digitalRead(inputPin6);
  if (val3 == HIGH) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}

