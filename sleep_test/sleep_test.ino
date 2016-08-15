void setup() {
  Serial.begin(115200);
  //WiFi.mode(WIFI_STA);
  //delay(1000);
  Serial.println("");
  Serial.println("");
  Serial.println("Begin");
  delay(1000);
}

void loop() {
  Serial.println("first");
  ESP.deepSleep(5000000, WAKE_RF_DEFAULT);//must connect GPIO16 (D0) to RST to issue wake interrupt
  delay(100);
  Serial.println("second");
}
