#include "LEDOrderedDimmer.h"

LEDOrderedDimmer orderedDimmer(A0, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  orderedDimmer.addLED(3,0);
  orderedDimmer.addLED(5,1);
  orderedDimmer.addLED(6,2);
  orderedDimmer.addLED(10,3);
  orderedDimmer.addLED(11,4);
}

void loop() {
  // put your main code here, to run repeatedly
  orderedDimmer.updateLED();
}
