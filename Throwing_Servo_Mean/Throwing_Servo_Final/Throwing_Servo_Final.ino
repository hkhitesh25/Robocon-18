#include<EEPROM.h>
#include<Servo.h>
int threshold1_polarity= 100;
int threshold2_reference = 26;
int ref[100];
int threshold_Claw = 50;
int flag=1;
int addr=0;
int i=0;
int refc=0;
int avg=0;
Servo myservo;
//undo
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
   pinMode(A3,INPUT);
  pinMode(A4,INPUT);
  myservo.write(87);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, INPUT);
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  
 Serial.begin(9600);  
}

void loop() {

  
  digitalWrite(13,LOW);
  while(flag==1)
  {
    if(analogRead(A0)<threshold_Claw)
     {
        delay(500);
        if(analogRead(A0)>threshold_Claw)
        {continue;}
        myservo.write(87);
        delay(500);
        myservo.write(125);
        digitalWrite(13,HIGH);
        delay(6000);
        flag=2;
  
      }
  }
    Serial.println("Mai attak gya");
    digitalWrite(13,LOW);
    while(i<15)
    {
      if((analogRead(A1)-26)>150)
       { 
        while((analogRead(A1)-26)>150);
        Serial.println(i);
         ref[i]=millis();
          refc=+ref[i];
          if(i>0)
          {
            avg = avg+(ref[i]-ref[i-1]);  
          }
        
          i++;
      }
    }
    Serial.println("Mai bahar aagya");
    refc = (refc/i + 4*avg/15);
    Serial.println(refc);
    while(millis() < refc);
    Serial.println("Mai phir bahar aagya");
   delay(350/4);
      myservo.write(125);
      delayMicroseconds(16000);
        delayMicroseconds(16000);
      digitalWrite(13,HIGH);
      myservo.write(87); 
      delay(500);   

  }
