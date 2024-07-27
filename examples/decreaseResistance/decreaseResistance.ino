//This example shows how to use the 'decreaseResistance()' method.

#include <X9C103S.h>
void setup() {
  Serial.begin(9600);
  X9C103S pot1(6, 7, 8); //X9C103S digital potentiometer connected to the Arduino with inc pin to pin 6 ud pin to pin 7 and cs pin to pin 8. Change pin numbers as nessary.
  pot1.initializePot();
}

void loop() {
  pot1.setResistance(50); //Sets the pot resistance to 50. The number can be any number from 1 to 100 (both included).
  pot1.decreaseResistance(10); //Decreases the pot resistance by 10. The resistance is now at the value 40.
  Serial.write(pot1.getResistance()); //Gets the resistance of the pot and sends it via serial.
}
