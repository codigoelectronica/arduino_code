//Se importan las liberias
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


#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

void setup() {
  Serial.begin(9600);
  //Se inicializa el lcd
  display.begin();
  //Se setea el contraste del lcd
  display.setContrast(50);
}

void loop() {
  //Limpiamos el display
  display.clearDisplay();
  //Establecemos el tamaño del text
  display.setTextSize(1);
  //Establecemos el color del display
  display.setTextColor(BLACK);
  //Se pocisiona el cursor
  display.setCursor(0,0);
  //Se escribe
  display.println("Adafruit_GFX");
  //Se muestra la información
  display.setCursor(0,8);
  //Se escribe
  display.println("Adafruit_PCD8544");
  display.display();
  display.setCursor(0,24);
  //Se escribe
  display.println("@codelectronica");
  display.display();
  delay(2000);
}
