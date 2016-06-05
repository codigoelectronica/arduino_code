//Se declaran los pines para el sensor
int const TRIG = 9;
int const ECHO = 8;

//Variables de calculo
float distancia;
float tiempo;

void setup(){
  Serial.begin(9600);
  //Activación del pin como salida: para el pulso ultrasónico
  pinMode(TRIG, OUTPUT); 
  //Activación del pin como entrada: tiempo del rebote del ultrasonido
  pinMode(ECHO, INPUT); 
}

void loop(){
  //Por cuestión de estabilización del sensor
  digitalWrite(TRIG,LOW); 
  delayMicroseconds(5);
  //envío del pulso ultrasónico
  digitalWrite(TRIG, HIGH); 
  delayMicroseconds(10);
  /* Función para medir la longitud del pulso entrante. 
  Mide el tiempo que transcurrido entre el envío
  del pulso ultrasónico y cuando el sensor recibe el rebote, e
  s decir: desde que el pin 12 empieza a recibir el rebote, HIGH, hasta que
  deja de hacerlo, LOW, la longitud del pulso entrante*/
  tiempo=pulseIn(ECHO, HIGH); 
  /*fórmula para calcular la distancia obteniendo un valor entero*/
  /*Monitorización en centímetros por el monitor serial*/
  distancia= int(0.017*tiempo); 
  Serial.print("Distancia ");
  Serial.print(distancia);
  Serial.print(" cm");
  Serial.println("");
  delay(1000);
}
  
