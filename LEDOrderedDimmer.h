 #include "LED.h"

class LEDOrderedDimmer {
  public:
    LEDOrderedDimmer(int _potPin, int _objectCounterMax){
      objectCounter = 0;
      if (_objectCounterMax > 50){
        _objectCounterMax = 50;
      }
      objectCounterMax = _objectCounterMax;
      ledContainer = new LED[objectCounterMax];
      potPin = _potPin;
    }

    ~LEDOrderedDimmer()
    {
      // cleanup of objects:
      delete [] ledContainer;  
    }

    void addLED(int pin, int orderedPos){
      if (objectCounter < objectCounterMax){
        ledContainer[objectCounter++].setPinPos(pin, orderedPos);
      }
    }

    void updateLED(){
      int brightness = map(analogRead(potPin), 0, 1023, 0, 5115);
      for (int i = 0; i <= objectCounter; i++){
        ledContainer[i].updateBrightness(brightness);
        delay(10);
      }
    }

  private:
    LED *ledContainer;
    int potPin;
    int objectCounter;
    int objectCounterMax;
};
