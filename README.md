# AnalogKeypad

Project page: http://upperbound.com/projects/12-button-keypad/

This is an Arduino library for a 12 button keypad that uses just one analog pin and ground connection.

The library debounces the 12 buttons and maps the voltage levels to integer values defined in the AnalogKeypad.h file.

Put the .h and .cpp file in your Arduino libraries/ folder.

## Demo

```c++
/*
 * A simple test and demonstration of the AnalogKeypad library
 * This keypad uses only one analog pin and ground connection.
 * 
 * Copyright 2017 Upperbound.com
 * 
 */

#include <AnalogKeypad.h>

/* Processes button presses from a 12-button keypad with this configuration:

  +--------------+
  | 1  |  2  | 3 |
  +--------------+  
  | 4  |  5  | 6 |
  +--------------+
  | 7  |  8  | 9 |
  +--------------+
  | 10 | 11 | 12 |
  +--------------+
*/
  
// We'll use analog input 5
const int inputPin = A5;

AnalogKeypad keypad(inputPin);

void setup() {

  Serial.begin(9600);
  Serial.println("The buttons correspond to this layout:");
  Serial.println("+--------------+");
  Serial.println("| 1  |  2  | 3 |");
  Serial.println("+--------------+");
  Serial.println("| 4  |  5  | 6 |");
  Serial.println("+--------------+");
  Serial.println("| 7  |  8  | 9 |");
  Serial.println("+--------------+");
  Serial.println("| 10 | 11 | 12 |");
  Serial.println("+--------------+");
  Serial.println("Press a button!");

}

void loop() {

  int reading =keypad.read();
  
  if (reading <13) {
    
    Serial.print(reading);
    Serial.println(" pressed");  
  }
  delay(150);
}
```
