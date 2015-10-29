#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int PIN_BRILLO = 9;
const int PIN_CONTRASTE = 10;
const int PIN_13 = 13;
const int CAMBIO = 6; 
const int MAX = 7; 
const int MIN = 8; 

int brillo = 50; //0
int contraste = 50; //1
int buttonCambio = 0;
int buttonMax = 0;
int buttonMin = 0;
int estadoCambio = 0;

int valMaxLcd = 255;
int valMinLcd = 0;

void setup() {

  lcd.begin(16, 2);

  pinMode(CAMBIO, INPUT);
  pinMode(MAX, INPUT);
  pinMode(MIN, INPUT);

  pinMode(PIN_13, OUTPUT);

  lcd.print("Brillo:");
  lcd.setCursor(0,1);
  lcd.print("Contraste:");

  analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
  analogWrite(PIN_CONTRASTE, (contraste*valMaxLcd)/100);

  lcd.setCursor(11,0);
  lcd.print(brillo);
  lcd.setCursor(11,1);
  lcd.print(contraste);

  lcd.setCursor(14,0);
  lcd.print("%");
  lcd.setCursor(14,1);
  lcd.print("%");

  lcd.setCursor(11,0);
  lcd.cursor();
}

void loop() {
  buttonCambio = digitalRead(CAMBIO);
  if (buttonCambio == HIGH) {
    digitalWrite(PIN_13, HIGH);
    if(estadoCambio == 0){
      estadoCambio = 1;
      lcd.noCursor();
      lcd.setCursor(11,1);
      lcd.cursor();
      delay(100);
    }else{
      estadoCambio = 0;
      lcd.noCursor();
      lcd.setCursor(11,0);
      lcd.cursor();
      delay(100);
    }
  }
  buttonMax = digitalRead(MAX);
  buttonMin = digitalRead(MIN);
  if (buttonMax == HIGH) {
    digitalWrite(PIN_13, HIGH);
    if(estadoCambio == 0){
      brillo = brillo + 1;
      analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
      lcd.setCursor(11,0);
      lcd.print(brillo);
    }else{
      contraste = contraste + 1;
      analogWrite(PIN_CONTRASTE,(contraste*valMaxLcd)/100);
      lcd.setCursor(11,1);
      lcd.print(contraste);
    }
  }
  if (buttonMin == HIGH) {
    digitalWrite(PIN_13, HIGH);
    if(estadoCambio == 0){
      brillo = brillo - 1;
      analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
      lcd.setCursor(11,0);
      lcd.print(brillo);
    }else{
      contraste = contraste - 1;
      analogWrite(PIN_CONTRASTE, (contraste*valMaxLcd)/100);
      lcd.setCursor(11,1);
      lcd.print(contraste);
    }
  }
  digitalWrite(PIN_13, LOW);
  delay(100);
}

void limpiarCaracteres(){
  

}

