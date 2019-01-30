#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID       "N~Alzheimer~N"
#define WIFI_PASSWORD   "21052539."
#define FIREBASE_HOST "ledcontrol-d0d51.firebaseio.com"
#define FIREBASE_AUTH "VBhQR3lSjIW5yLXSmaqfSxlRem16u5jg2qRBsWTj"


void setup() {
  Serial.begin(115200);
  Serial.println(WiFi.localIP());
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  pinMode(D0, OUTPUT);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("LED", 0);   ///เซตให้มันเพิ่ม LED เป็นค่า 0
}

void loop() {
  digitalWrite(D0, Firebase.getInt("LED"));   ///รับค่าจากfirebase node 
  delay(500);
}
