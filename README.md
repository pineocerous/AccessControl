# AccessControl
Simple access control code for RFID card reader and Arduino.

Requires https://github.com/monkeyboard/Wiegand-Protocol-Library-for-Arduino 

D0 (Green wire RFID reader) to PIN 2
D1 (White wire RFID reader) to PIN 3

Be sure to ground the reader to the Arduino common or Wiegand won't read correctly. Get your card's decimal values by scanning them and checking serial output from arduino.
