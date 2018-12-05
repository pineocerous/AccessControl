#include <Wiegand.h>
WIEGAND wg;


#define RED 4   //Red LED +5v Out on Pin 4
#define GREEN 5 //Green LED +5v Out on Pin 5
#define LOCK 6  //Lock relay +5v Out on Pin 6

unsigned long friendlyCode [] = {     //Enter your Friendly RFID card decimal values here
};


int i;
void setup() {

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(LOCK, OUTPUT);
  
  Serial.begin(9600);
  wg.begin();
}

void loop() {

  if (wg.available())
  {
    Serial.print("Wiegand HEX = ");
    Serial.print(wg.getCode(), HEX);
    Serial.print(", DECIMAL = ");
    Serial.print(wg.getCode());
    Serial.print(", Type W");
    Serial.println(wg.getWiegandType());

    
  for (i = 0; i < (sizeof(friendlyCode)); i++) {
  if (wg.getCode() == friendlyCode [i]) {
    Serial.print("Friendly!");              //Access Granted!
    digitalWrite(LOCK, HIGH);
    digitalWrite(GREEN, HIGH);
    delay(3000);
    digitalWrite(LOCK, LOW);
    digitalWrite(GREEN, LOW);
  }
  }
  }
}
    

  
