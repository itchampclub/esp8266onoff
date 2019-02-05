#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define pinON 5 //D1-GPIO5

const char* ssid = "ssid";
const char* password = "password";


void setup() {
  Serial.begin(115200);
  pinMode(pinOn, OUTPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
  Serial.print(",");
  }
}
 void loop() {
  Serial.println();
  HTTPClient http;
  http.begin("https://yoursubname.herokuapp.com/data.txt", "59:C1:57:75:F6:2B:7E:93:F3:07:A2:E5:41:C9:73:93:C3:3C:7F:16");
  int httpCode = http.GET();
  if (httpCode == 200) 
  {
    String content = http.getString();
    Serial.println(content);

  int ValueOn = -1;
  int ValueOff = -1;
  int ValueError = -1;
  
  ValueError = content.indexOf("error");
  ValueOn = content.indexOf("On");
  ValueOff = content.indexOf("Off");

  if (ValueError > 0) {
  delay(9000);
  }
  else 
  {
    Serial.print("");
    
     if (ValueOn and ValueOff == -1) 
    {
      Serial.print("\nAwaiting Command\n");     
    }
         if (ValueOn != -1)
          {
            digitalWrite(pinOn, HIGH); 
            Serial.println("\n On\n");
              
           }

         if (ValueOff != -1) 
          {
            digitalWrite(pinOn, LOW);   
            Serial.print("\n Off\n");
            
          }


          } 
  }
  else {
    Serial.println("Fail. error code " + String(httpCode));
  }
    delay(1000);
  }
