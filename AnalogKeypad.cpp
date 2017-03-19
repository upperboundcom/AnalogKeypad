/*
	AnalogKeypad.cpp
	Copyright 2017 Upperbound.com
    http://upperbound.com/projects/12-button-keypad/
    
    Implementation for AnalogKeypad.h
    
    
*/

#include "AnalogKeypad.h"
#include "Arduino.h"

AnalogKeypad::AnalogKeypad(int pin) {
	_pin = pin;
	pinMode(_pin, INPUT_PULLUP); // activate the pullup resistor
	
	//_lastButtonState = _keypadHigh;
	_lastButtonState = BUTTONNONE;
	_lastDebounceTime=0;
}

int AnalogKeypad::read() {
	
	int reading = analogRead(_pin);
	
	if (reading >= _BUTTON1LOW && reading <=_BUTTON1HIGH) {
		_tmpButtonState = BUTTON1;
	}
	else if (reading >= _BUTTON2LOW && reading <=_BUTTON2HIGH) {
		_tmpButtonState = BUTTON2;
	}
	else if (reading >= _BUTTON3LOW && reading<= _BUTTON3HIGH) {
		_tmpButtonState = BUTTON3;
	}
	else if (reading >= _BUTTON4LOW && reading<= _BUTTON4HIGH) {
		_tmpButtonState = BUTTON4;
	}
	else if (reading >= _BUTTON5LOW && reading<=_BUTTON5HIGH) {
		_tmpButtonState = BUTTON5;
	}
  
	else if (reading >= _BUTTON6LOW && reading<= _BUTTON6HIGH) {
		_tmpButtonState = BUTTON6;
	}
  
	else if (reading >= _BUTTON7LOW && reading<=_BUTTON7HIGH) {
		_tmpButtonState = BUTTON7;
	}
  
	else if (reading >= _BUTTON8LOW && reading<= _BUTTON8HIGH) {
		_tmpButtonState = BUTTON8;
	}
  
	else if (reading >= _BUTTON9LOW && reading<=_BUTTON9HIGH) {
		_tmpButtonState = BUTTON9;
	}
  
	else if (reading >= _BUTTON10LOW && reading<=_BUTTON10HIGH) {
		_tmpButtonState = BUTTON10;
	}
	else if (reading >= _BUTTON11LOW && reading<=_BUTTON11HIGH) {
		_tmpButtonState = BUTTON11;
	 }
  
	else if (reading >= _BUTTON12LOW && reading<= _BUTTON12HIGH) {
		_tmpButtonState = BUTTON12;
	}
   
	else {
		//_tmpButtonState = _keypadHigh; // nothing being pushed
		_tmpButtonState = BUTTONNONE;
	}

	if (_tmpButtonState != _lastButtonState) {
		// reset debounce timer
		_lastDebounceTime = millis();
	}
	
	if ((millis() - _lastDebounceTime) > _debounceDelay) {
		// take the current state as the button state since we've been there longer than the debounce delay
		_buttonState = _tmpButtonState; 
		return _buttonState;
	}
	
	_lastButtonState = _tmpButtonState;
	
	return _lastButtonState;

}
