#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define enableB 12
#define pinB1  2 //IN3
#define pinB2    0 //IN14
#define pinA1  13 // IN1
#define pinA2  15//IN2
#define enableA  14 
#define LED 16

const char* ssid = "ssid";
const char* password = "password";





void setup() {
  Serial.begin(115200);
  pinMode(LED,OUTPUT);
  pinMode(enableB , OUTPUT);
  pinMode(pinB1, OUTPUT);
  pinMode(pinB2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(pinA1, OUTPUT);
  pinMode(pinA2, OUTPUT);
  
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

  int Valueturnleft = -1;
  int Valueturnright = -1;
  int Valueforback = -1;
  int Valueforward = -1;
  int Valuestop = -1;
  int ValueError = -1;
  
  ValueError = content.indexOf("error");
  Valueturnleft = content.indexOf("turnleft");
  Valueturnright = content.indexOf("turnright");
  Valueforback = content.indexOf("forback");
  Valueforward = content.indexOf("forward");
  Valuestop = content.indexOf("stop");

  

 




  if (ValueError > 0) {
  delay(9000);
  }
  else 
  {
    Serial.print("");
    
     if (Valueturnleft and Valueturnright and  Valueforback and  Valueforward and Valuestop == -1) 
    {
      Serial.print("\nAwaiting Command\n");     
    }
        if (Valueturnleft != -1) //EB
          {
            digitalWrite(LED,HIGH);
               analogWrite(enableA,100);
            digitalWrite(pinA2, LOW);
            digitalWrite(pinA1, LOW);
            analogWrite(enableB,600); // หยุด
            digitalWrite(pinB2, HIGH);
            digitalWrite(pinB1, LOW);
            
         
              Serial.println("\n turnleft\n");
              
           }

         if (Valueturnright != -1) 
          {
             digitalWrite(LED,HIGH);   //EA                       
               analogWrite(enableA,600);// หยุด
            digitalWrite(pinA2, HIGH);
            digitalWrite(pinA1, LOW);
            analogWrite(enableB,100); 
            digitalWrite(pinB2, LOW);
            digitalWrite(pinB1, LOW);   
            Serial.print("\n right\n");
            
          }

          if (Valueforback != -1) 
          {
             digitalWrite(LED,HIGH);
            analogWrite(enableA,600);
            digitalWrite(pinA2, LOW);
            digitalWrite(pinA1, HIGH);
            analogWrite(enableB,600);
             digitalWrite(pinB2, LOW);
            digitalWrite(pinB1, HIGH);                                  
             Serial.println("forback");
            
          }

          if (Valueforward != -1) 
          {
             digitalWrite(LED,HIGH);            
           analogWrite(enableA,600);
             digitalWrite(pinA1, LOW);
            digitalWrite(pinA2, HIGH);          
            analogWrite(enableB,600);
             digitalWrite(pinB1, LOW);
            digitalWrite(pinB2, HIGH);        
            Serial.println("forward");
            
          }

          if (Valuestop != -1) 
          {
             
            digitalWrite(LED,LOW);
            
            analogWrite(enableA,0);
            digitalWrite(pinB2, HIGH);
            digitalWrite(pinB1, HIGH);
            analogWrite(enableB,0);
            digitalWrite(pinA2, HIGH);
            digitalWrite(pinA1, HIGH);
            Serial.println("stop");
          }
          } 
  }
  else {
    Serial.println("Fail. error code " + String(httpCode));
  }
    delay(1000);
  }
