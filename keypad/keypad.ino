#include <Keypad.h>

const byte numRows= 4;
const byte numCols= 4;

char keymap[numRows][numCols]=
{
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte rowPins[numRows] = {'5','4','3','2'};
byte colPins[numCols]=  {'9','8','7','6'};

//initializes an instance of the Keypad class
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);

void setup(){
  Serial.begin(9600);
}

void loop(){
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY){
    Serial.println(keypressed);
  }
}
