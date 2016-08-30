/**Reloj Analogo Lcd Arduinos
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez @oscar_fedezal
* License: MIT
*/

//Incluimos las librerías necesarias
#include <LCD5110_Graph.h>
#include <SPI.h>
#include <math.h> 
#include <Wire.h>
#include <RTClib.h>

//Declaramos la variable global del lcd y con los pines que usaremos
LCD5110 myGLCD(8,9,10,11,12);

//Cargamos las fuentes externas
extern unsigned char SmallFont[];
extern unsigned char TinyFont[];

//Declaramos la variable global de nuestro reloj ds1307
RTC_DS1307 rtc;

/*Creamos las variables para el uso del lcd*/
int xmax = 84;    //Tamaño maximo del lcd en x
int ymax = 48;    //Tamaño maximo del lcd en y
int xo = 42;      //Punto medio del eje x
int yo = 24;      //Punto medio del eje y
int radiox = 37;  //Maximo radio en x
int radioy = 21;  //Maximo radio en y



void setup()
{
  //Iniciamos nuesto lcd
  myGLCD.InitLCD();
  
  //Iniciamos nuestro reloj
  Wire.begin();
  rtc.begin();
  
  //Imprimimos un mensaje de bienvenida
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myGLCD.print("Reloj Analogo", CENTER, 0);
  myGLCD.print("con arduino y", CENTER, 20);
  myGLCD.print("lcd nokia5110", CENTER, 40);
  myGLCD.update();
  
  delay(3000);
  myGLCD.clrScr();
  
  //Colocamos los números 
  myGLCD.setFont(TinyFont);
  for(int countHour = 1 ; countHour <= 12 ; countHour++ ){
    int ang = (90 - countHour) * 30;
    float radianes = ConvertGradeToRadianes(ang);
    int x = radiox  * sin(radianes);
    int y = radioy * cos(radianes);
    x = x + xo;
    y = y + yo;
    myGLCD.print(String(countHour), x, y-2);
    myGLCD.update();
  }
}


void loop()
{
  //Leemos la hora en nuestro reloj
  DateTime now = rtc.now();
  //Realizamos el calculo para convertir la hora en formato 12 horas
  int numberHour = 0;
  if(now.hour() > 12){
    numberHour = now.hour() - 12;
  }else{
    numberHour = now.hour();
  }
  
  //Con los valores de la hora, mostramos las manecillas
  HandHour(numberHour, 0);
  HandMinute(now.minute(), 0);
  delay(1000);  
  HandHour(numberHour, 1);
  HandMinute(now.minute(), 1);
  delay(1000);
}

/**
 * Con la funcion HandHour podemos pintar la manecilla de la
 * hora en la pantalla
 * 
 * numberHour int Número del reloj de 1 a 12
 * delete int Eliminar la manecilla 0 pata mostrar 1 para eliminar
 */
void HandHour(int numberHour, int deletee){
  //Distancia entre numeros en grados 
  // grados/horas = distancia donde 360/12 = 30
  int ang = (90 - numberHour) * 30;
  float radianes = ConvertGradeToRadianes(ang);
  int x = (radiox / 2.2) * sin(radianes);
  int y = (radioy / 2.2) * cos(radianes);
  x = x + xo;
  y = y + yo;
  if(deletee == 1){
    myGLCD.clrLine(xo, yo, x, y);
  }else{
    myGLCD.drawLine(xo, yo, x, y);    
  }
  myGLCD.update();
}

/**
 * Con la funcion HandMinute podemos pintar la manecilla del
 * minuto en la pantalla
 * 
 * numberMinute int Número del reloj de 1 a 12
 * delete int Eliminar la manecilla 0 pata mostrar 1 para eliminar
 */
void HandMinute(int numberMinute, int deletee){
  //Distancia entre numeros en grados 
  // grados/minuto = distancia donde 360/60 = 6
  int ang = (90 - numberMinute) * 6;
  float radianes = ConvertGradeToRadianes(ang);
  int x = (radiox / 1.2) * sin(radianes);
  int y = (radioy / 1.2) * cos(radianes);
  x = x + xo;
  y = y + yo;
  if(deletee == 1){
    myGLCD.clrLine(xo, yo, x, y);
  }else{
    myGLCD.drawLine(xo, yo, x, y);    
  }
  myGLCD.update();
}

/**
 * La funcion ConvertGradeToRadianes donde permite convertir 
 * los grados en radianes
 * 
 * grade int Grados
 */
float ConvertGradeToRadianes(int grade){
  float radianes = 0;
  radianes = (grade * 3.1416) / 180; 
  return radianes;
}
