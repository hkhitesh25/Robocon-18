#include<Servo.h>;
Servo myservo;
int Control_Pin = 0;
int MSB = 0;
int LSB = 0;
int input_signal_control_pin = 8;
int input_signal_MSB_pin = 10;
int input_signal_LSB_pin = 11;
int output_signal_pin = 12;
int motor_input_1_pin = 2;
int motor_input_PWM_pin = 3;
int motor_input_2_pin = 4;
int polarity_change_pin1 = 5;
int polarity_change_pin2 = 7;
int servo_attach_pin = 9;
int servo_closing_angle = 0;
int servo_opening_angle = 0;
int servo_delay = 0;
int TZ1_rpm = 90;
int TZ1_delay = 548/6;
int TZ2_rpm = 0;
int TZ2_delay = 0;
int TZ3_rpm = 0;
int TZ3_delay = 0;

void setup() {

  myservo.attach(servo_attach_pin);
  pinMode(input_signal_control_pin,INPUT);
  pinMode(input_signal_MSB_pin,INPUT);
  pinMode(input_signal_LSB_pin,INPUT);
  pinMode(output_signal_pin,OUTPUT);
  pinMode(motor_input_1_pin,OUTPUT);
  pinMode(motor_input_PWM_pin,OUTPUT);
  pinMode(motor_input_2_pin,OUTPUT);
  pinMode(polarity_change_pin1,OUTPUT);
  pinMode(polarity_change_pin2,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(17,OUTPUT);
  pinMode(19,OUTPUT);

}
void initial_reference(){
    analogWrite(motor_input_PWM_pin,35);
    delay(100);
    analogWrite(motor_input_PWM_pin,24);
    delay(400);
    analogWrite(motor_input_PWM_pin,14);
    delay(2000);
    digitalWrite(output_signal_pin,LOW);
}

void Target_TZ(int rpm, int de_lay){
   digitalWrite(output_signal_pin,HIGH);
    myservo.write(servo_closing_angle);
    delay(servo_delay);
    analogWrite(motor_input_PWM_pin,rpm);
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    delay(2000);
    digitalWrite(polarity_change_pin1,LOW);
    digitalWrite(polarity_change_pin2,HIGH);
    delay(de_lay);
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    myservo.write(servo_opening_angle);
    delay(servo_delay);
}

void loop(){
  Control_Pin = digitalRead(input_signal_control_pin);
  MSB = digitalRead(input_signal_MSB_pin);
  LSB = digitalRead(input_signal_LSB_pin);
  if(Control_Pin == HIGH)
  {
    if(MSB == LOW && LSB == LOW)
    {
      //  Do Nothing, Stay at INITIAL_REFERENCE
      initial_reference();
    }
  }
  if(Control_Pin == HIGH)
  {
    if(MSB == LOW && LSB == HIGH)
    {
      //  Go to TZ1, & then stay at INITIAL_REFERENCE
      digitalWrite(14,HIGH); 
      Target_TZ(TZ1_rpm,TZ1_delay);
      initial_reference();
    }
  }
  if(Control_Pin == HIGH)
  {
    if(MSB == HIGH && LSB == LOW)
    {
      //  Go to TZ2, & then stay at INITIAL_REFERENCE
      digitalWrite(14,HIGH);
      digitalWrite(17,HIGH); 
      Target_TZ(TZ2_rpm,TZ2_delay);
      initial_reference();
    } 
  }
  if(Control_Pin == HIGH)
  {
    if(MSB == HIGH && LSB == HIGH)
    {   
      //   Go to TZ3, & then stay at INITIAL_REFERENCE
      digitalWrite(14,HIGH);
      digitalWrite(17,HIGH); 
      digitalWrite(19,HIGH); 
      Target_TZ(TZ3_rpm,TZ3_delay);
      initial_reference();
    }
  }
  digitalWrite(14,LOW);
      digitalWrite(17,LOW); 
      digitalWrite(19,LOW); 
}
