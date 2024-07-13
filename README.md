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

1. Download the latest zip file
2. Go to Arduino IDE
3. Click on 'Sketch'
4. Click on 'Include Library'
5. Click on 'Add .ZIP Library...'
6. Browse to the location of the zip file
7. Click on the zip file

#### Method II

1. Download the latest release from the [GitHub releases page](https://github.com/yourusername/X9C103S/releases).
2. Extract the downloaded ZIP file.
3. Move the extracted folder to your Arduino libraries directory (`~/Documents/Arduino/libraries` on Windows and macOS, `~/Arduino/libraries` on Linux).

## Usage

### Example Sketches

The library comes with several example sketches to help you get started. You can find these in the `examples` folder. Here are brief descriptions and code snippets for each example:

#### 1. getResistance.ino

This example demonstrates how to initialize the potentiometer and read its resistance.

```cpp
#include <X9C103S.h>

// Define the pins connected to the X9C103S digital potentiometer
#define INC_PIN 2
#define UD_PIN 3
#define CS_PIN 4

// Create an instance of the X9C103S class
X9C103S potentiometer(INC_PIN, UD_PIN, CS_PIN);

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging
  potentiometer.initializePot(); // Initialize the potentiometer
}

void loop() {
  // Set the resistance to a specific value
  potentiometer.setResistance(50);
  Serial.print("Resistance set to: ");
  Serial.println(potentiometer.getResistance());
  delay(2000);
}
