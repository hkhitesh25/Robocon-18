#include <Servo.h>
Servo myservo;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  //pinMode(10,HIGH);
  //pinMode(11,LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    int n = Serial.parseInt();
    Serial.print("Angle is : ");
    Serial.println(n);
    myservo.write(n);
    //delay(500);
    //myservo.detach();
  }
  

}
