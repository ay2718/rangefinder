#ifndef LOWPASS_H
#define LOWPASS_H

class lowPass {
 private:
  unsigned long bestValue;
  unsigned long lastViewed;
  int scale;
  const unsigned long timeout = 500;
 public:
  lowPass(int _scale) {
    scale = _scale;
    bestValue = 0;
    lastViewed = 0;
  };
  unsigned long update(unsigned long _value) {
    if (_value == 0 || bestValue == 0 || millis() - lastViewed > timeout) {
      bestValue = _value;
    }
    else {
      bestValue *= scale;
      bestValue += _value;
      bestValue /= (scale + 1);
    }
    lastViewed = millis();
    return bestValue;
  };
  unsigned long get() { return bestValue; };
};

#endif
