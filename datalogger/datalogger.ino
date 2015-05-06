/**Datalogger de para temperatura y humedad del hambiente
*
* Copyright: codigoelectronica.com
* Author: Oscar Fernandez
* License: MIT*/

/* Circuito
* Buzzer      pin 0
* Led Green   pin 1
* CS          pin 4
* MOSI        pin 11
* MISO        pin 12
* CLK         pin 13
*/

/*Cargamos librerias*/
#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>
#include <TimeAlarms.h>
#include <SPI.h>
#include <SD.h>
#include <dht.h>

/*Inicializamos las variables*/
/**Pines*/
const int buzzer = 0;
const int led_green = 1;
const int DHT11_PIN = 3;
const int chipSelect = 4;
const int reference5v = 5;

/**Variables*/
String dateRTC = "", dateT = "";
String timeRTC = "", timeT = "";
String dateTimeRTC = "", dateTimeT = "";
int error[1];//Variable para error
int temperature = 0, humidity = 0;

tmElements_t tm;
dht DHT;

/**Iniciamos el programa*/
void setup () {
  Serial.begin(9600);
  pinMode(10, OUTPUT);//Selector de chip de SD
  /*Verificamos la SD*/
  if (!SD.begin(chipSelect)){
    error[0] = 1;
    return;
  }
  tmElements_t tm;
  if (RTC.read(tm)){
    error[1] = 0;
  }else{
    error[1] = 1;
  }
  /**Cargamos la hora y fecha a las variables de time*/
  setSyncProvider(RTC.get);
  UpdateArduinoTime();
  clockDisplay(3);
  Alarm.timerRepeat(3600, RepeatsHour);
  Alarm.timerRepeat(15, SaveSD);
}

void loop () {
  errorStart();
  clockDisplay(1);
  displayMeteorology();
  Alarm.delay(1000);
}

void errorStart(){
  if(error[0] == 1){
    ErrorBuzzer(3,100,"La SD no funciona o no esta presente.");
  }else if(error[1] == 1){
    if (RTC.chipPresent()){
      ErrorBuzzer(2,200,"El RTC esta detenido, por favor inicielo.");
    }else{
      ErrorBuzzer(2,200,"El RTC no funciona o no esta presente.");
    }
  }
}

void SaveSD(){
  String dataString = "";
  clockRTC();
  clockTime();
  float sens = getTemperature();
  dataString += dateTimeRTC+","+String(sens)+","+dateTimeT;
  saveDataSD(dataString);
}

/*La funcion RepeatsHour permite ejecutar un proceso cada hora*/
void RepeatsHour(){
  toggleLed(buzzer, 100);   
  Serial.println("Repeticion de hora");
}

/*La funcion saveSD permite guardar en la sd*//**
* String dataString Informacion a guardar*/
void saveDataSD(String stringData){
  File dataFile = SD.open("datalog.txt",FILE_WRITE);
  if (dataFile) {
    dataFile.println(stringData);
    dataFile.close();
    toggleLed(led_green,200); 
    error[0] = 0;
  }else{
    error[0] = 1;
    errorStart();
  }
}



void displayMeteorology(){
  meteorology();
  Serial.print(humidity);
  Serial.print(",\t");
  Serial.println(temperature);
}

void meteorology(){
  temperature = 0;
  humidity = 0;
  DHT.read11(DHT11_PIN);
  temperature = DHT.temperature;
  humidity = DHT.humidity;
}

/*La funcion clockRTC permite leer el reloj del RTC*/
void clockRTC() {
  dateTimeRTC = "";
  tmElements_t tm;
  RTC.read(tm);
  dateRTC = String(tmYearToCalendar(tm.Year)) + "/" + String(tm.Month) + "/" + String(tm.Day);
  timeRTC = String(tm.Hour) + ":" + String(tm.Minute) + ":" + String(tm.Second);
  dateTimeRTC = dateRTC + " " + timeRTC;
}

/*La funcion clockTime permite leer el reloj de arduino*/
void clockTime() {
  dateTimeT = "";
  timeT = String(hour())+":"+String(minute())+":"+String(second());
  dateT = String(year())+"/"+String(month())+"/"+String(day());
  dateTimeT += dateT+" "+timeT;
}

/*La funcion clockDisplay permite imprimir la fecha y hora por terminal de 
comandos*//**
* int value Valor a seleccionar (1-> fecha externa, 2-> fecha interna, 3-> Todas las fechas)*/
void clockDisplay(int value){
  clockRTC();
  clockTime();
  switch(value){
    case 1:
      Serial.println("Reloj externo");
      Serial.println(dateTimeRTC);
    break;
    case 2:
      Serial.println("Reloj interno");
      Serial.println(dateTimeT);
    break;
    case 3:
      Serial.println("Reloj externo");
      Serial.println(dateTimeRTC);
      Serial.println("Reloj interno");
      Serial.println(dateTimeT);
    break;
  } 
}

/*Funcion UpdateTime para actualizar la hora en relog interno de con el RTC*/
void UpdateArduinoTime() {
  tmElements_t tm;
  RTC.read(tm);
  setTime(tm.Hour, tm.Minute, tm.Second, tm.Day, tm.Month, tmYearToCalendar(tm.Year));
}

/*Funcion ErrorBuzzer para el error con buzzer*//** 
* int repeat Repeticiones a sonar el buzzer
* int time Tiempo de espera
* String error Mensaje para terminal de comandos*/
void ErrorBuzzer(int repeat, int time, String error){
  Serial.println(error);
  for(int i = 0 ; i < repeat ; i++ ){
    digitalWrite(buzzer, HIGH);
    delay(time);    
    digitalWrite(buzzer, LOW);
    delay(time); 
  }
}
/*La funcion toggleLed permite prender y apagar un led en un tiempo*//**
* int pin Pin del arduino
* int time Tiempo de espera*/
void toggleLed(int pin, int time){
  digitalWrite(pin, HIGH);
  delay(time);    
  digitalWrite(pin, LOW);
  delay(time);
}

float getTemperature(){
  float sensor = analogRead(1);
  float operatingVoltage = 5.0 * sensor / 1024;
  return(operatingVoltage);
}
