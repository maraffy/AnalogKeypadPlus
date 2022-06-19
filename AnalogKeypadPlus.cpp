//
//    FILE: AnalogKeypadPlus.cpp
//  AUTHOR: Marco Affinito from "AnalogKeypad" by Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2022-05-26
// PURPOSE: Class for (Robotdyn) 4x4 and 4x3 analog keypad with keymap
//
//  HISTORY:
//  0.1.0  2022-05-26  initial version
//

#include "AnalogKeypadPlus.h"

// NOTE the MAGIC NUMBERS in rawRead() are for 8 BIT ADC
// as 8 bit compares are fast
//
// The _analogShift takes care if the ADC has more
// than e.g. 10 bits. 
//
// Arduino UNO3 build in ==>  10 bits
// Other may have 12 or even 16 bits.
AnalogKeypadPlus::AnalogKeypadPlus(const uint8_t pin, uint8_t *kmap, const uint8_t bits = 10, const uint16_t db = 10):
                                   AnalogKeypad(pin, bits)
{
  _keyMap = kmap;
  _debounce = db;
  _lastPress = 0;
  _lastTime = 0;
}

AnalogKeypadPlus::getKey()
{
  uint32_t now = millis();
  uint16_t button;
  uint8_t keyPressed = 0;
  
  if (now - _lastTime > _debounce) {
    button = pressed();
    if (button != 0 && _lastPress == 0) {
      button = read();
      keyPressed = _keyMap[button-1];
    }
    _lastPress = button;
    _lastTime = now;
  }
  return keyPressed;
}


// -- END OF FILE --

