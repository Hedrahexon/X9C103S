//This example uses a potentiometer to control three X9C103S digital potentiometers

#define POT1_PIN A1;
#define POT2_PIN A2;

#include <X9C103S.h>
X9C103S pot1(1, 2, 3);
X9C103S pot2(4, 5, 6);
X9C103S pot3(7, 8, 9);
void setup() {
  Serial.begin(9600);
  pot1.initializePot();
  pot2.initializePot();
  pot3.initializePot();
}

void loop() {
  int resistance1 = map(analogRead(POT1_PIN), 0, 1023, 0, 100);
  int resistance2 = map(analogRead(POT2_PIN), 0, 1023, 0, 100);
  int resistance3 = round((resistance1 + resistance2) / 2);
  pot1.setResistance(resistance1);//Digital pot 1 is set to the value of physical pot 1.
  Serial.write("Potentiometer 1:");
  Serial.write(pot1.getResistance());
  pot2.setResistance(resistance2);//Digital pot 2 is set to the value of physical pot 2.
  Serial.write("Potentiometer 2:");
  Serial.write(pot2.getResistance());
  pot3.setResistance(resistance3);//Digital pot 3 is set to the average of physical pot 1 and physical pot 2.
  Serial.write("Potentiometer 3:");
  Serial.write(pot3.getResistance());
}
