class LED{
  public:
    LED (int _pin = -1, int _pos = -1){
      pin = _pin;
      pos = _pos;

      digitalWrite(pin, LOW);
    }

    void setPinPos(int _pin, int _pos)
    {
      pin = _pin;
      pos = _pos;
      lowerBound = 1023 * pos;
      if (lowerBound){
        lowerBound += 1;
      }
      upperBound = 1023 * (pos + 1);
    }
 
    int getPin(){
      return pin;  
    }

    void enable(){
      digitalWrite(pin, HIGH);
    }

    void disable(){
      digitalWrite(pin, LOW);
    }

    void updateBrightness(int rawBrightness){
      int convertedBrightness = map(rawBrightness, lowerBound, upperBound, 0, 255);
      convertedBrightness = convertedBrightness > 255 ? 255 : convertedBrightness;

      if (rawBrightness >= lowerBound){
          _updateBrightness(convertedBrightness);
      } else { 
        disable();
      }
    }

  private:
    int pin;
    int pos;
    int lowerBound;
    int upperBound;
    void _updateBrightness(int brightnessIntensity){
      analogWrite(pin, brightnessIntensity);
    }
};
