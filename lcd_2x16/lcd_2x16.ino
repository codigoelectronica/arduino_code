//Incluimos la libreria del LCD
#include <LiquidCrystal.h>

 /** Iniciamos las conexiones del LCD
 * LCD RS al pin digital 12
 * LCD Enable al pin digital 11
 * LCD D4 al pin digital pin 5
 * LCD D5 al pin digital pin 4
 * LCD D6 al pin digital pin 3
 * LCD D7 al pin digital pin 2
 * LCD R/W al pin GND
 * LCD VSS al pin GND
 * LCD VCC al pin 5V*/
 
//pines del lcd     rs, en, D4, D5, D6, D7
//                   |   |  |   |   |   |
//pines del arduino 12, 11, 5   4   3   2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
  
  //Seteamos en el lcd el número de filas y columnas
  lcd.begin(16, 2);
  
  //Imprimimos un mensaje
  lcd.print("Hola...");
  delay(2000);
}

void loop() {
  //Limpiamos el lcd
  lcd.clear();
  lcd.print("Vamos a hacer");
  lcd.setCursor(0,1);
  lcd.print("unas pruebas");
  delay(2000);
  lcd.clear();
  
  lcd.print("del uso del lcd en");
  lcd.setCursor(0,1);
  lcd.print("donde vemos las funciones");
  delay(2000);
  lcd.clear();
  
  lcd.print("y su uso");
  delay(3000);
  lcd.clear();

  //Pruebas de display
  lcd.print("1. Display");
  lcd.noDisplay();
  delay(1000);
  lcd.display();
  delay(1000);
  lcd.clear();
  delay(200);
  
  //Pruebas de blink
  lcd.print("2. Blink");
  lcd.setCursor(0,1);
  lcd.blink();
  delay(3000);
  lcd.noBlink();
  delay(3000);
  lcd.clear();
  delay(200);
  
  //Prueba del cursor
  lcd.print("3. Cursor");
  lcd.setCursor(0,1);
  lcd.cursor();
  delay(3000);
  lcd.noCursor();
  delay(3000);
  lcd.clear();
  delay(200);

  //Impresion de caracteres
  lcd.print("3. Caracter");
  lcd.setCursor(0,1);

  byte armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
  };
  
  byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
  };
  
  //Asignacion e impresion de caracteres
  lcd.createChar(1, armsDown);
  lcd.createChar(2, armsUp);
  lcd.setCursor(0, 1);
  lcd.write(1);
  delay(2000);
  lcd.setCursor(0, 1);
  lcd.write(2);
  delay(2000);
}
