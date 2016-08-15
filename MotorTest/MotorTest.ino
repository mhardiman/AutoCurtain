/*
 ESP8266 Blink by Simon Peter
 Blink the blue LED on the ESP-01 module
 This example code is in the public domain
 
 The blue LED on the ESP-01 module is connected to GPIO1 
 (which is also the TXD pin; so we cannot use Serial.print() at the same time)
 
 Note that this sketch uses LED_BUILTIN to find the pin with the internal LED
*/

/*static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10  = 1;*/

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  //pinMode(2,OUTPUT);
  //pinMode(3,OUTPUT);
  //pinMode(4,OUTPUT);
  //pinMode(5,OUTPUT);
  //pinMode(6,OUTPUT);
  //pinMode(7,OUTPUT);
  //digitalWrite(1,HIGH);
  //digitalWrite(0,LOW);
  //digitalWrite(2,HIGH);
  //digitalWrite(3,HIGH);
  digitalWrite(D2,HIGH);
  //digitalWrite(5,HIGH);
  //digitalWrite(6,HIGH);
  //digitalWrite(7,HIGH);
  //Serial.begin(115200);
  //Serial.println(D0);
  //Serial.println(D1);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

// the loop function runs over and over again forever
void loop() {
  //digitalWrite(1,HIGH);
  //digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
                                    // but actually the LED is on; this is because 
                                    // it is acive low on the ESP-01)
  digitalWrite(D1,HIGH);
  delayMicroseconds(350);                      // Wait for a second
  //digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by making the voltage HIGH
  digitalWrite(D1,LOW);
  delayMicroseconds(350);                      // Wait for two seconds (to demonstrate the active low LED)
}
