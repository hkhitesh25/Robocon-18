#include<Servo.h>
int threshold1_polarity= 100;
int threshold2_reference = 26;
int threshold_Claw = 50;
int threshold_tsop=50;
int flag=1;
int i=0;
int ref[100];
int refc=0;
int avg=0;
Servo myservo;
void setup() {
  
  myservo.attach(9);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A2,INPUT);
  myservo.write(0);
  delay(1000);
  pinMode(13, OUTPUT);
  pinMode(13, LOW);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A4, INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  
}

void loop() {
   digitalWrite(13,LOW);
// while(flag==1)
//  {
//   if(analogRead(A0)<threshold_Claw)
//   
//  {
//  delay(500);
//  if(analogRead(A0)>threshold_Claw)
//  continue;
//   myservo.write(87);
//   delay(500);
//  myservo.write(125);
//   digitalWrite(13,HIGH);
//  delay(6000);
//  flag=2;
// 
//  }
while(flag==1)
{
delay(1000);
digitalWrite(13,HIGH);
myservo.write(145);
delay(2000);
myservo.write(30);
//delay(1000);
flag=2;
}
digitalWrite(13,LOW);

    while(i<14)
    {
      if((analogRead(A1)-26)>150)
       { 
        while((analogRead(A1)-26)>150);
         ref[i]=millis();
          refc=+ref[i];
          if(i>0)
          {
            avg = avg+(ref[i]-ref[i-1]);  
          }
        
          i++;
      }
    }
    
    refc = (refc/i + 4*avg/14);
    while(millis() < refc);


      myservo.write(30);
      delayMicroseconds(16000);
        delayMicroseconds(16000);
      digitalWrite(13,HIGH);
      myservo.write(0); 
      delay(1000);   
}



    
  

  

