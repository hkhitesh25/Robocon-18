//#include <Servo.h>
//Servo myservo;
int my_values[100][2];
int br_or_rpm_value=1;
int delay2=0;
float servo_read=0.0;
void setup() {
  // put your setup code here, to run once:
  
  
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  Serial.begin(9600);
//  myservo.attach(9);
  //myservo.write(20);
// servo_read= myservo.read();
 //Serial.print("Angle of servo is :");
 //Serial.println(servo_read);
 
  
  
}

void loop() {
  digitalWrite(5,LOW);
  digitalWrite(7,HIGH);
  // put your main code here, to run repeatedly:
   // myservo.write(110);
  if(br_or_rpm_value!=2){
  
 // Serial.print("Angle of servo is :");
// Serial.println(servo_read);
Serial.println("Enter the number of sets you want to enter : ");
  }
 
  // servo_read= myservo.read();
 
   
   
  br_or_rpm_value=2;
  
  if(Serial.available()){
    int n=Serial.parseInt();
    Serial.print("n is : ");
        Serial.println(n);
      for(int i=0;i<n || n==0;i++){
        Serial.println("Enter the value : ");
         while(Serial.available()== 0);
        my_values[i][0]=Serial.parseInt();
        Serial.print("value is : ");
        Serial.println(my_values[i][0]);
        Serial.println("Enter the delay :");
        while(Serial.available()== 0);
        my_values[i][1] = Serial.parseInt();
        Serial.print("delay is : ");
        Serial.println(my_values[i][1]);
        
      }
      Serial.print("Enter delay2 : ");
      while(Serial.available()== 0);
        delay2 = Serial.parseInt();
       Serial.println(delay2);
      Serial.println("Done!!");
   
  do{
    for(int i=0;i<n || n==0;i++)
    {
      
      Serial.println(my_values[i][0]);
        analogWrite(3,my_values[i][0]);
        if(i%2==0 || n==0){
          Serial.println("Oscillation Starts");
          digitalWrite(2,LOW);
          digitalWrite(4,HIGH);
          //analogWrite(3,my_values[i][0]);
           delay(my_values[i][1]);
         digitalWrite(2,HIGH);
          digitalWrite(4,HIGH);
         delay(delay2);
        }
         
        else{
         
          digitalWrite(2,LOW);
          digitalWrite(4,HIGH);
          //analogWrite(3,my_values[i][0]);
           delay(my_values[i][1]);
          //digitalWrite(3,HIGH);
          //digitalWrite(6,HIGH);
         //delay(500);
        }
        Serial.println("Complete Rotation Starts");
       digitalWrite(4,HIGH);
       digitalWrite(2,LOW);


      while(Serial.available()== 0);
      br_or_rpm_value=Serial.parseInt();
   
      }
      while( br_or_rpm_value>10){
        analogWrite(3,br_or_rpm_value);
        Serial.print("RPM_value : ");
        Serial.println(br_or_rpm_value);
        while(Serial.available()== 0);
        br_or_rpm_value=Serial.parseInt();
      }
       if(br_or_rpm_value==3){
          digitalWrite(5,LOW);
          digitalWrite(7,HIGH);
          Serial.println("Polarity Reversed");
         //digitalWrite(2,HIGH);
        //digitalWrite(4,HIGH); 
      //servo2(); 
      while(Serial.available()== 0);
        br_or_rpm_value=Serial.parseInt();
    }    
    if(br_or_rpm_value==4){
      digitalWrite(2,HIGH);
      digitalWrite(4,HIGH); 
      
        Serial.println("Hand Brake");
        while(Serial.available()== 0);
        br_or_rpm_value=Serial.parseInt();
    }
   }while(br_or_rpm_value==2); 
  }
  
}
void servo2(){
 //myservo.attach(9);
 // myservo.write(60);
 //servo_read= myservo.read();
 //Serial.print("Angle of servo is :");
 //Serial.println(servo_read);
  //Serial.println("Rotation of servo");
        digitalWrite(3,HIGH);
        digitalWrite(6,HIGH); 
        Serial.println("Hand Brake");
        while(Serial.available()== 0);
        br_or_rpm_value=Serial.parseInt();
}

