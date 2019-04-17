//Inicializamos el lcd
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Se declaran los pines para el sensor
int const TRIG = 9;
int const ECHO = 8;

//Variables de calculo
float distancia;
float tiempo;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
  //Activación del pin como salida: para el pulso ultrasónico
  pinMode(TRIG, OUTPUT); 
  //Activación del pin como entrada: tiempo del rebote del ultrasonido
  pinMode(ECHO, INPUT); 
}

void loop(){
  digitalWrite(TRIG,LOW); 
  delayMicroseconds(5);
  //Envío del pulso ultrasónico
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);

  //Obtenemos el tiempo de rebote
  tiempo = pulseIn(ECHO, HIGH); 

  //Calculamos la distancia
  distancia= tiempo / 2 / 29.1;
  Serial.print("Distancia ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println("");
  lcd.clear();
  lcd.print("Distancia");
  lcd.setCursor(0,1);
  lcd.print(distancia);
  delay(1000);
}
  
