/*Reloj de tiempo real con DS1307 en arduino
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez
* License: MIT
*/

//Cargamos librerias
#include <Wire.h>
#include "RTClib.h"

//Instanciamos el rtc
RTC_DS1307 rtc;

//Iniciamos el programa
void setup () {
  Serial.begin(9600);
#ifdef AVR
  Wire.begin();
#else
  Wire1.begin(); 
#endif
  rtc.begin();

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running!");
    //La siguiente linea es para establecer la fecha y hora al ds1307 al momento de compilar
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

    //Para establecer la fecha y hora manualmente
    // rtc.adjust(DateTime(2015, 1, 1, 3, 0, 0));
  }
}

void loop () {
  //Cargamos los valores de fecha, hora en variable now
  DateTime now = rtc.now();
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
    
  Serial.print(" since midnight 1/1/1970 = ");
  Serial.print(now.unixtime());
  Serial.print("s = ");
  Serial.print(now.unixtime() / 86400L);
  Serial.println("d");
    
  Serial.println();
  delay(3000);
}
