#include <ESP8266WiFi.h>

const char* ssid = "Wiffy";
const char* password = "gibwiffypls";

int ledPin = 2; // GPIO2
WiFiServer server(5555);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(D1,OUTPUT);
  pinMode(D2,OUTPUT);
  digitalWrite(D2,HIGH);
  Serial.begin(115200);
  delay(10);
  //digitalWrite(LED_BUILTIN, LOW);
  
 // pinMode(ledPin, OUTPUT);
  //digitalWrite(ledPin, LOW);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
  delay(500);
  Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  WiFi.mode(WIFI_STA);
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
  return;
  }
  Serial.println("client connected");
  client.println("hi client");
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
  delay(1);
  }
  
  
  int req = client.read();//.readStringUntil('\r');
  if (req==0)
  {
    digitalWrite(D2,LOW);
  }
  else if (req==1)
  {
    digitalWrite(D2,HIGH);
  }
  //activate motor
  digitalWrite(LED_BUILTIN, LOW);
  for (int i=0; i<=1400; i++)
  {
    digitalWrite(D1,HIGH);
    delayMicroseconds(350);                      // Wait for a second
    digitalWrite(D1,LOW);
    delayMicroseconds(350);  
  }
  digitalWrite(LED_BUILTIN, HIGH);
  
  //Serial.println(req);
  //client.flush();
  /*
  // Match the request
  
  int value = LOW;
  if (request.indexOf("/LED=ON") != -1) {
  digitalWrite(ledPin, HIGH);
  value = HIGH;
  }
  if (request.indexOf("/LED=OFF") != -1) {
  digitalWrite(ledPin, LOW);
  value = LOW;
  }
  
  // Set ledPin according to the request
  //digitalWrite(ledPin, value);
  
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); // do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  
  client.print("Led pin is now: ");
  
  if(value == HIGH) {
  client.print("On");
  } else {
  client.print("Off");
  }
  client.println("<br><br>");
  client.println("Click <a href=\"/LED=ON\">here</a> turn the LED on pin 2 ON<br>");
  client.println("Click <a href=\"/LED=OFF\">here</a> turn the LED on pin 2 OFF<br>");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
*/
}
