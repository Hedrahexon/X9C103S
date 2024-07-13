#ifndef X9C103S_H
#define X9C103S_H

#include <Arduino.h>

class X9C103S {
public:
    X9C103S(int inc_pin, int ud_pin, int cs_pin);
    void initializePot();
    void setResistance(int value);
    void increaseResistance(int value);
    void decreaseResistance(int value);
    int getResistance(); // Getter for the private variable

private:
    int _inc_pin;
    int _ud_pin;
    int _cs_pin;
    int _resistance; // Private variable to store the resistance value
};

#endif
