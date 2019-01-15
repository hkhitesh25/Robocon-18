void setup() {
  // put your setup code here, to run once:
pinMode(A0,INPUT);
  pinMode(A1,INPUT);
   pinMode(A2,INPUT);
   pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13,LOW);
   digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
  Serial.begin(9600); }

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(analogRead(A1));
      int n =analogRead(A0);
//upto
    Serial.print("A0 : ");
       Serial.print(analogRead(A0));
       Serial.print("       A1: ");
        Serial.print(analogRead(A1));
              Serial.print("   A2 : ");
        Serial.print(analogRead(A2));
              Serial.print("   A3 : ");
        Serial.print(analogRead(A3));
        
        Serial.print("   A4 : ");
        Serial.println(analogRead(A4));
        

}
