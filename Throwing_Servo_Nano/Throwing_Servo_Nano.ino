#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  pinMode(10,HIGH);
  pinMode(11,LOW);
  myservo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
    delay(10000);
    
    myservo.write(60);
  
  

}
