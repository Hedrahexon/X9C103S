#include "X9C103S.h"

X9C103S::X9C103S(int inc_pin, int ud_pin, int cs_pin) {
    _inc_pin = inc_pin;
    _ud_pin = ud_pin;
    _cs_pin = cs_pin;
}

void X9C103S::initializePot() {
    pinMode(_inc_pin, OUTPUT);
    pinMode(_ud_pin, OUTPUT);
    pinMode(_cs_pin, OUTPUT);
    digitalWrite(_cs_pin, HIGH);  // Ensure initial state is HIGH
    _resistance = 0;
}

void X9C103S::setResistance(int value) {
    int _value = value;
    if (_value != _resistance) {
        if (_value < 1) {
            _value = 1;
        }
        if (_value > 100) {
            _value = 100;
        }
        int diff = _value - _resistance

		if (diff > 0) {
        	digitalWrite(_ud_pin, HIGH);  // Set direction to increment
		} else {
			diff *= -1
	        digitalWrite(_ud_pin, LOW);  // Set direction to decrement
		}
        digitalWrite(_cs_pin, LOW);  // Enable the potentiometer
        for (int i = 0; i < diff; i++) {
            digitalWrite(_inc_pin, LOW);
            delay(1);
            digitalWrite(_inc_pin, HIGH);
            delay(1);
        }
        digitalWrite(_cs_pin, HIGH);  // Disable the potentiometer
        _resistance = _value;  // Update the private variable
    }
}

void X9C103S::increaseResistance(int value) {
    digitalWrite(_cs_pin, LOW);  // Enable the potentiometer
    digitalWrite(_ud_pin, HIGH);  // Set direction to increment
    for (int i = 0; i < value; i++) {
        digitalWrite(_inc_pin, LOW);
        delay(1);
        digitalWrite(_inc_pin, HIGH);
        delay(1);
    }
    digitalWrite(_cs_pin, HIGH);  // Disable the potentiometer
    _resistance += value;  // Update the private variable
    for (; _resistance > 100;) {
        if (_resistance > 100) {
            _resistance -= 100;
        }
    }
}

void X9C103S::decreaseResistance(int value) {
    digitalWrite(_cs_pin, LOW);  // Enable the potentiometer
    digitalWrite(_ud_pin, LOW);  // Set direction to decrement
    for (int i = 0; i < value; i++) {
        digitalWrite(_inc_pin, LOW);
        delay(1);
        digitalWrite(_inc_pin, HIGH);
        delay(1);
    }
    digitalWrite(_cs_pin, HIGH);  // Disable the potentiometer
    _resistance -= value;  // Update the private variable
    for (; _resistance < 1;) {
        if (_resistance < 1) {
            _resistance += 100;
        }
    }
}

int X9C103S::getResistance() {
    return _resistance;  // Return the value of the private variable
}
