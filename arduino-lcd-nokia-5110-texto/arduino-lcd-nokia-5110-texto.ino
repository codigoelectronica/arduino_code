#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Conexión de los pines del lcd al display
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

void setup() {
  //Se inicializa el lcd
  display.begin();
  //Se setea el contraste del lcd
  display.setContrast(50);
}

void loop() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("text size 1");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  double variablePuntoFlotante = 3.32;
  display.println(variablePuntoFlotante);
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("text size 2");
  display.display();
  delay(2000);

  display.clearDisplay();
  display.setRotation(1);
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println("Rotacion");
  display.setTextSize(2);
  display.println("Ejemplo");
  display.display();
  delay(2000);

  display.setRotation(0);


  
}
