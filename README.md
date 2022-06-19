# AnalogKeypadPlus
Analog Keypad Plus library for Arduino, depend from AnalogKeypad by Rob Tillaart
Library for (Robotdyn) 4x4 and 4x3 analog keypad.
The AnalogKeypad library must also be installed.

## Description

AnalogKeypadPlus is an extension of AnalogKeypad, simple library to read the keys from a (Robotdyn) 4x4 or 4x3 keypad.
No other keypads are tested, but they should work with this library after adjusting
the **MAGIC NUMBERS** in the function **rawRead()**.


## Interface


### Constructor

- **AnalogKeypadPlus(const uint8_t pin, uint8_t *kmap, const uint8_t bits = 10, const uint16_t db = 10)** constructor. Where: **pin** is the analog input pin used. **kmap** is the key map, array containing the ASCII codes assigned to the keys of the keypad. **bits** is the number of bits of the A/D converter, the default value is 10, but must be set to match the platform. If bits < 8 then the internal shift would be large causing all reads to return 0 or so. **db** is debounce time, the default value is 10 ms.

### key input
- **setDebounce(const uint16_t db)** set debounce time in ms.
- **getKey()** returns the ASCII code, obtained from the key map, when a key is pressed, otherwise it returns 0 even if you continue to press the key.
### polling interface

- **uint8_t pressed()** returns 0 if no key pressed, otherwise returns key pressed (may fluctuate).
- **uint8_t read()** read the key pressed returns 0 .. 16 where 0 means NOKEY.

### event interface

- **uint8_t event()** checks if a change has occurred since last time.
- **uint8_t key()** returns the key involved with last event.

Switch(int e = event()) 
  
| Event    | value |
|:--------:|:-----:|
| PRESSED  | 0x80  |
| RELEASED | 0x40  |
| REPEATED | 0x20  |
| CHANGED  | 0x10  |
| NOKEY    | 0x00  |


## Operation

The simplest usage is to use the **read()** function. 
This will return a 0 (NOKEY) when no key is pressed and
a number 1 to 16 for the keys pressed. Note the return value may
fluctuate randomly when multiple keys are pressed.

The **pressed()** function is a bit more robust.
It returns the key pressed first, so multiple key presses simultaniously 
are less likely to disturb your program.

An advanced usage is to use the **getKey()** function.
It returns the ASCII code corresponding to the key pressed, defined via key map, otherwise it returns 0.

See Examples
