#include <Servo.h> //include servo library
Servo myservo;//create object for servo1
Servo myservo2;//create object for servo2

int pos = 10;//initialize pos for servo 1
int pos2 = 10;//initialize pos for servo 2



void setup() {
  Serial.begin(9600);
  while(! Serial);
  Serial.println("Enter F to move to 180 and B to move back");
  myservo.attach(8);
  myservo2.attach(9);

  

}

void loop() {
  if(Serial.available()){
    char ch = Serial.read();
    if(ch == 'F'|| ch == 'f'){
      pos = 180;
      pos2 = 180;
      myservo.write(pos);
      myservo2.write(pos2);

    }
    if(ch == 'B' || ch == 'b'){
      pos = 10;
      pos2 = 10;
      myservo.write(pos);
      myservo.write(pos2);
    }
  }
  else{
    Serial.println("Waiting on input");
  }
}
