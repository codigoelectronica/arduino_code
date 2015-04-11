/*Reloj de tiempo real con DS1307 en arduino
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez
* License: MIT
*/

//Cargamos librerias
#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <TimeAlarms.h>
#include <SPI.h>
#include <SD.h>

String date = "", dateTime = "", time = "", timeDate = "";
const int chipSelect = 4;


//Iniciamos el programa
void setup () {
  //Configuramos el serial
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  //actualizamos la hora
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  setSyncProvider(RTC.get);

  UpdateTime();
   Alarm.timerRepeat(3600, RepeatsHour);
   Alarm.timerRepeat(15, SaveSD);
}

void loop () {
 digitalClockDisplay();
 
  Alarm.delay(1000);
}

void SaveSD(){
  String dataString = "";
  clockDisplayRTC();
  clockDisplayTime();
  int sensor = analogRead(0);
  float sens = ((sensor * 5.0) / 1024)*10;
  dataString += dateTime+","+String(sens)+","+timeDate;
  
  File dataFile = SD.open("datalog.txt",FILE_WRITE);

  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    Serial.println(dataString);
    digitalWrite(1, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);              // wait for a second
    digitalWrite(1, LOW);    // turn the LED off by making the voltage LOW
    delay(100);  
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

void RepeatsHour(){
  digitalWrite(0, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait for a second
  digitalWrite(0, LOW);    // turn the LED off by making the voltage LOW
  delay(100);  
  Serial.println("15 second timer");
}
void UpdateTime() {
  tmElements_t tm;
  RTC.read(tm);
  setTime(tm.Hour, tm.Minute, tm.Second, tm.Day, tm.Month, tmYearToCalendar(tm.Year));
}

void clockDisplayRTC() {
  dateTime = "";
  tmElements_t tm;
  RTC.read(tm);
  date = String(tmYearToCalendar(tm.Year)) + "/" + String(tm.Month) + "/" + String(tm.Day);
  time = String(tm.Hour) + ":" + String(tm.Minute) + ":" + String(tm.Second);
  dateTime = date + " " + time;
  Serial.print(dateTime);
  Serial.println();
}

void clockDisplayTime() {
  timeDate = "";
  // digital clock display of the time
  timeDate += String(year())+"/"+String(month())+"/"+String(day())+" "+String(hour())+":"+String(minute())+":"+String(second());
  Serial.println(timeDate);
}

void printDigits(int digits) {
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if (digits < 10)
    Serial.print('0');
  Serial.print(digits);
}
void digitalClockDisplay()
{
  // digital clock display of the time
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.println(); 
}

