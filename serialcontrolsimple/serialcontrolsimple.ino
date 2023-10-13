#include<Servo.h>
Servo myservo;

int pos;

void setup(){
  Serial.begin(9600);
  myservo.attach(8);
  




}
void loop(){
  Serial.println("Enter pos:");
  while(Serial.available() == 0){}
  pos = Serial.readString().toInt();
  if(pos>=0 && pos <= 180){
    myservo.write(pos);
    Serial.println("Servo at pos:");
    Serial.println(pos);
  }
else{
  Serial.println("invalid");
}
}
