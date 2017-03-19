/*
  AnalogKeypad.h
  Copyright 2017 Upperbound.com
  http://upperbound.com/projects/12-button-keypad/
  
  Library for a 12 button analog keypad that uses one analog pin and ground.
  
  This library debounces 12 pushbuttons and maps voltage divider values to 12 integer values set here.
  
*/


#ifndef AnalogKeypad_h
#define AnalogKeypad_h

#include "Arduino.h"

class AnalogKeypad {
	public:
		AnalogKeypad(int pin);
		int read();
		
		// Button mappings
        // You can reassign the button values if you like. 
        
		static const int BUTTON1 = 1;
		static const int BUTTON2 = 2;
		static const int BUTTON3 = 3;
		static const int BUTTON4 = 4;
		static const int BUTTON5 = 5;
		static const int BUTTON6 = 6;
		static const int BUTTON7 = 7;
		static const int BUTTON8 = 8;
		static const int BUTTON9 = 9;
		static const int BUTTON10 = 10;  
		static const int BUTTON11=11;
		static const int BUTTON12 = 12; 
		static const int BUTTONNONE=960;

	private:
		int _pin;  
		int _lastButtonState;
		int _buttonState;
		long _lastDebounceTime;
		int _tmpButtonState;
		
		static const long _debounceDelay=50;
		static const int _keypadHigh=960; // ADC value when no button is pressed
		
		
		// ADC button values. These assume use of 10K / 5% tolerance resistors in the voltage divider circuit.
        // You'll need to change these values if you use different value resistors.
        
		static const int _BUTTON1LOW = 355;
		static const int _BUTTON1HIGH = 408;

		static const int _BUTTON2LOW = 222;
		static const int _BUTTON2HIGH = 265;

		static const int _BUTTON3LOW = 13;
		static const int _BUTTON3HIGH = 30;

		static const int _BUTTON4LOW = 449;
		static const int _BUTTON4HIGH = 461;

		static const int _BUTTON5LOW = 518;
		static const int _BUTTON5HIGH = 529;

		static const int _BUTTON6LOW = 570;
		static const int _BUTTON6HIGH = 585;

		static const int _BUTTON7LOW = 679;
		static const int _BUTTON7HIGH = 691;

		static const int _BUTTON8LOW = 638;
		static const int _BUTTON8HIGH = 666;

		static const int _BUTTON9LOW = 614;
		static const int _BUTTON9HIGH = 632;

		static const int _BUTTON10LOW = 697;
		static const int _BUTTON10HIGH = 722;

		static const int _BUTTON11LOW = 723;
		static const int _BUTTON11HIGH = 736;

		static const int _BUTTON12LOW = 743;
		static const int _BUTTON12HIGH = 757;
		
};
#endif
