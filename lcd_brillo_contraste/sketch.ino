#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//Declaramos las constantes para cada uno 
//de los pines y pulsadores
const int PIN_BRILLO = 9;     //Pin salida brillo
const int PIN_CONTRASTE = 10; //Pin salida contraste
const int PIN_13 = 13;        //Led de control
const int CAMBIO = 6;         //Pulsador cambio de brillo a contraste
const int MAX = 7;            //Pulsador aumentar
const int MIN = 8;            //Pulsador disminuir 

int brillo = 50;       //Iniciamos variable brillo 50%
int contraste = 50;    //Iniciamos variable contraste 50%

//Iniciamos variables de los pulsadores
int buttonCambio = 0;
int buttonMax = 0;
int buttonMin = 0;
int estadoCambio = 0;

//Declaramos variables de lectura análoga max y min
int valMaxLcd = 255;
int valMinLcd = 0;


void setup() {
 lcd.begin(16, 2); //Iniciamos el lcd

  //Declaramos como entrada y salida a los pines
  pinMode(CAMBIO, INPUT);
  pinMode(MAX, INPUT);
  pinMode(MIN, INPUT);
  pinMode(PIN_13, OUTPUT);

  //Mostramos los valores iniciales de brillo y contraste
  lcd.print("Brillo:");
  lcd.setCursor(0,1);
  lcd.print("Contraste:");

  //Escribimos en los pines los valores por defecto
  analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
  analogWrite(PIN_CONTRASTE, (contraste*valMaxLcd)/100);

  lcd.setCursor(10,0);
  lcd.print(brillo);
  lcd.print("%");
  lcd.setCursor(10,1);
  lcd.print(contraste);
  lcd.print("%");

  lcd.setCursor(11,0);
  lcd.cursor();
}

void loop() {
  //Iniciamos el programa preguntando si el pulsador de cambio
  //fue habilitado 
  buttonCambio = digitalRead(CAMBIO);
  //Si es accionado cambiamos de brillo a contraste o viceversa 
  if (buttonCambio == HIGH) {
    digitalWrite(PIN_13, HIGH);
    //Si estado e 0
    if(estadoCambio == 0){
      estadoCambio = 1;     //Activamos estado
      lcd.noCursor();       //Quitamos el cursos del lcd
      lcd.setCursor(10,1);  //Seteamos el cursis en x=11 y=1 
      lcd.cursor();         //Colocamos el cursor
      delay(100);
    }else{
      //Si el cursor es 1 hacemos los cambios de esta forma
      estadoCambio = 0;
      lcd.noCursor();
      lcd.setCursor(11,0);
      lcd.cursor();
      delay(100);
    }
  }
  //Si el boton de cambio no es accionado, escribimos los valores 
  //de máximo y mínimo
  buttonMax = digitalRead(MAX);
  buttonMin = digitalRead(MIN);
  
  //Preguntamos si el pulsador máximo fue oprimido
  if (buttonMax == HIGH) {
    digitalWrite(PIN_13, HIGH);
    //Si es asi, verificamos el estado del cambio
    if(estadoCambio == 0){     //Si es activo aumentamos es valor de brillo
      if (brillo < 100) {
        brillo = brillo + 1;
      }
      //Lo escribimos en el pin brillo
      analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
      lcd.setCursor(10,0);
      lcd.print(brillo);
      lcd.print("%");
    }else{                    //de lo contrario aumentamos el contraste
      if (contraste < 100) {
        contraste = contraste + 1;
      }
      //Lo escribimos en el pin contraste
      analogWrite(PIN_CONTRASTE,(contraste*valMaxLcd)/100);
      lcd.setCursor(10,1);
      lcd.print(contraste);
      lcd.print("%");
    }
  }
  //Aplica la misma funcionalidad para el pin de mínima como esta 
  //en el de maxima
  if (buttonMin == HIGH) {
    digitalWrite(PIN_13, HIGH);
    if(estadoCambio == 0){
      if (brillo > 0) {
        brillo = brillo - 1;
      }
      analogWrite(PIN_BRILLO, (brillo*valMaxLcd)/100);
      lcd.setCursor(10,0);
      lcd.print(brillo);
      lcd.print("%");
    }else{
      if (contraste > 0) {
        contraste = contraste - 1;
      }
      analogWrite(PIN_CONTRASTE, (contraste*valMaxLcd)/100);
      lcd.setCursor(10,1);
      lcd.print(contraste);
      lcd.print("%");
    }
  }
  digitalWrite(PIN_13, LOW);
  delay(100);
}