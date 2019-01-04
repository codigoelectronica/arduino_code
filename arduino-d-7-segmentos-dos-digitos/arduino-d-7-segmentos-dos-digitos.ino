const int pins[7] = { 2, 3, 4, 5, 6, 7, 8 }; 

//Declaramos los numeros para el ánodo común
const byte numbersDisplayAnode[10] = {0b1000000,     //0
                          0b1111001,          //1
                          0b0100100,          //2
                          0b0110000,          //3
                          0b0011001,          //4
                          0b0010010,          //5
                          0b0000010,          //6
                          0b1111000,          //7
                          0b0000000,          //8
                          0b0010000};         //9

const int nbrDigits = 2;
//                         digits 1   2
const int digitPins[nbrDigits] = {10,11};

void setup() {
  for(int i = 0; i < 8; i++) {
    pinMode(pins[i], OUTPUT);
  }

  for(int i = 0; i < nbrDigits; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void loop() {

  int randomInt = random(0, 99);

  for(int i = 0; i <  100; i++ ){
    showNumber(randomInt);  
    delay(1);
  }
  
}

void showNumber(int number) {
  if(number == 0) {
    showDigit(0, nbrDigits-1);
  } else {
    for(int digit = nbrDigits-1; digit >= 0; digit--) {
      if(number > 0) {
        showDigit(number % 10, digit);
        number = number / 10;
      }
    }
  }
}

void showDigit(int number, int digit) {
  digitalWrite(digitPins[digit], HIGH);
 byte numberBit = numbersDisplayAnode[number];
  for (int i = 0; i < 7; i++)  {
    int bit = bitRead(numberBit, i);
    digitalWrite(pins[i], bit);
  }
  delay(5);
  digitalWrite(digitPins[digit], LOW);
}

