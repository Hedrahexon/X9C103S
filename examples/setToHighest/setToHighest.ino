//This example shows how to use the 'setToHighest()' method.

#include <X9C103S.h>
X9C103S pot1(6, 7, 8); //X9C103S digital potentiometer connected to the Arduino with inc pin to pin 6 ud pin to your pin 7 and cs pin to pin 8. Change pin numbers as necessary.
void setup() {
  Serial.begin(9600);
  pot1.initializePot();
}

void loop() {
  pot1.setResistance(45); //Sets the pot resistance to 50. The number can be any number from 1 to 100 (both included).
  pot1.setToHighest(); //Sets the pot resistance to highest value(100).
  Serial.write(pot1.getResistance()); //Gets the resistance of the pot and sends it via serial (Should be 100).
}
