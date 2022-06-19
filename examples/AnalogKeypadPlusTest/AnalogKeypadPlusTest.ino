#include "AnalogKeypadPlus.h"

const byte NKEYS = 16;      // number of keys                         
char keys[NKEYS] = {        // keymap definition
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};
AnalogKeypadPlus akp(A0, keys);   // Insert analog pin and keymap

void setup() {
  Serial.begin(115200);
  Serial.print("ANALOGKEYPADPLUS_LIB_VERSION:\t");
  Serial.println(ANALOGKEYPADPLUS_LIB_VERSION);
  Serial.println();
}

void loop() {
  char key;
  if ((key = akp.getKey())!=0)
    Serial.println(key);
}
