# X9C103S

X9C103S is a light Arduino library to control X9C103S digital potentiometers. This library allows you to easily set, increase, and decrease the resistance of the X9C103S potentiometer.

## Installation

### Using the Arduino Library Manager

1. Open the Arduino IDE.
2. Go to `Sketch` > `Include Library` > `Manage Libraries...`.
3. In the Library Manager, search for `X9C103S`.
4. Click on the `X9C103S` library entry and press `Install`.

### Manual Installation

#### Method I

1. Download the latest release from the [GitHub releases page](https://github.com/yourusername/X9C103S/releases).
2. Extract the downloaded ZIP file.
3. Go to Arduino IDE
4. Click on 'Sketch'
5. Click on 'Include Library'
6. Click on 'Add .ZIP Library...'
7. Browse to the location of the zip file
8. Click on the zip file

#### Method II

1. Download the latest release from the [GitHub releases page](https://github.com/yourusername/X9C103S/releases).
2. Extract the downloaded ZIP file.
3. Move the extracted folder to your Arduino libraries directory (`~/Documents/Arduino/libraries` on Windows and macOS, `~/Arduino/libraries` on Linux).

## Usage

### Example Sketches

The library comes with several example sketches to help you get started. You can find these in the `examples` folder. Here are a few examples with brief descriptions and code snippets.:

#### 1. getResistance.ino

This example demonstrates how to initialize the potentiometer and read its resistance.

```cpp
#include <X9C103S.h>
void setup() {
  Serial.begin(9600);
  X9C103S pot1(6, 7, 8) //X9C103S digital potentiometer connected with inc pin to pin 6 ud pin to pin 7 and cs pin to pin 8. Change pin numbers as nessary.
  pot1.initializePot()
}

void loop() {
  pot1.setResistance(45) //Sets the pot resistance to 50. The number can be any number from 1 to 100 (both included).
  pot1.increaseResistance(25) //Increases the pot resistance by 10. The resistance is now at the value 70.
  Serial.write(pot1.getResistance()) //Gets the resistanceof the pot and sends it via serial.
}
```
#### 2. setToHighest.ion

This example demonstrates how to set the potentiometer to its highest value easily.

```cpp
#include <X9C103S.h>
void setup() {
  Serial.begin(9600);
  X9C103S pot1(6, 7, 8) //X9C103S digital potentiometer connected with inc pin to pin 6 ud pin to pin 7 and cs pin to pin 8. Change pin numbers as nessary.
  pot1.initializePot()
}

void loop() {
  pot1.setResistance(45) //Sets the pot resistance to 50. The number can be any number from 1 to 100 (both included).
  pot1.setToHighest() //Sets the pot resistance to highest value(100).
  Serial.write(pot1.getResistance()) //Gets the resistanceof the pot and sends it via serial(Should be 100).
}
```
