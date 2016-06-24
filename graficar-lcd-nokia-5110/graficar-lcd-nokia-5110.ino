#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16

void setup() {
  Serial.begin(9600);

  display.begin();
  display.setContrast(50);
  display.display();
  display.clearDisplay();
}

void loop() {
  display.clearDisplay();
  setMessage("Pixel");
  display.drawPixel(42, 24, BLACK);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  setMessage("Linea");
  display.drawLine(0, 24, 84, 24, BLACK);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  setMessage("Linea");
  display.drawRect(0, 10, 84, 32, BLACK);
  display.display();
  delay(2000);
  
  display.clearDisplay();
  setMessage("Circulo");
  display.drawCircle(42, 24, 18, BLACK);
  display.display();
  delay(2000);
}

void setMessage(String msj){
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(msj);
  display.display();
}

