#include<Servo.h>;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
 
  pinMode(2,OUTPUT);
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
    digitalWrite(5,HIGH);
  digitalWrite(7,LOW);
  pinMode(9,OUTPUT);
  
  
      delay(5000);
     // Serial.begin(9600);
}

void loop() {

          
         analogWrite(3,110);
          //Serial.println("Complete Rotation Starts");
          digitalWrite(2,LOW);
          digitalWrite(4,HIGH);
          delay(2000);
          digitalWrite(5,LOW);
          digitalWrite(7,HIGH);
          delay(2000);
          //myservo.write();
          delay(500);
        
          while(0==0)
          {
         analogWrite(3,35);
    delay(100);
    analogWrite(3,24);
    delay(400);
    analogWrite(3,14);
    delay(2000);
          }
    //digitalWrite(output_signal,LOW);

  
  
}

