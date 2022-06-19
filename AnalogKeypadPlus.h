#pragma once
//
//    FILE: AnalogKeypad.h
//  AUTHOR: Marco Affinito from "AnalogKeypad" by Rob Tillaart
// VERSION: 0.1.0
//    DATE: 2022-05-26
// PURPOSE: Class for (Robotdyn) 4x4 and 4x3 analogue keypad
//     URL: https://github.com/maraffy/AnalogKeypadPlus
//


#include "AnalogKeypad.h"


#define ANALOGKEYPADPLUS_LIB_VERSION      (F("0.1.0"))

// pin : analog input pin
// kmap : array of uint8_t for keypad character mapping
// bits : number of bits of the A/D converter (default = 10)
// db : debounce time (default = 10)
// setDebounce(const uint16_t db) : set the debounce time
// getKey() : returns the ASCII code when a key is pressed, otherwise it returns 0
class AnalogKeypadPlus : public AnalogKeypad
{
public:
  explicit AnalogKeypadPlus(const uint8_t pin, uint8_t *kmap, const uint8_t bits = 10, const uint16_t db = 10);
  setDebounce(const uint16_t db) { _debounce = db; };
  getKey();
private:
  uint16_t _debounce;
  uint8_t *_keyMap;
  uint8_t _lastPress;
  uint32_t _lastTime;
};

// -- END OF FILE --
