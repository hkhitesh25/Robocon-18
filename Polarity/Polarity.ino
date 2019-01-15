void setup() {
  // put your setup code here, to run once:
 pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  if(Serial.available()){
    int n= Serial.parseInt();
    if(n==3){
      Serial.print("polarity reversed");
       digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  
    }
    delay(10000);
  }

}
