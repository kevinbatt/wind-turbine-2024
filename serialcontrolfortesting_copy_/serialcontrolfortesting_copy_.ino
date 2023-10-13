#include <Servo.h> //include servo library
Servo myservo;//create object for servo1
Servo myservo2; 

int pos = 10;//initialize pos for servo 1
int pos2 = 10;
char ch = Serial.readString().toInt();
bool lastPos = pos; 
bool lastPos2 = pos2;




void setup() {
  Serial.begin(9600);
  myservo.attach(8);
  myservo2.attach(9);
  pos = 10;
  pos2 = 10;
  myservo.write(pos);
  myservo2.write(pos2);
 


}

void loop() {
  Serial.println("enter value from 1 to 12 to move servo 1 or 2:");
  while(Serial.available() == 0){}
    ch = Serial.readString().toInt();
    pos = 10;
    pos2 = 10;
    

    if(ch == '1' ){
      pos = lastPos + 50;
      myservo.write(pos);

    }
    if(ch == '2' ){
      pos = lastPos - 50;
      myservo.write(pos);


    }
    if(ch == '3' ){
      pos = lastPos + 10;
      myservo.write(pos);

    }
    if(ch == '4'){
      pos = lastPos - 10;
      myservo.write(pos);

    }
    if(ch == '5' ){
      pos = lastPos + 1;
      myservo.write(pos);
    }
    if(ch == '6' ){
      pos = lastPos - 1;
      myservo.write(pos);
    }
    if(ch == '7'){
      pos2 = lastPos2 + 50;
      myservo2.write(pos2);

    }
    if(ch == '8'){
      pos2 = lastPos2 - 50;
      myservo2.write(pos2);
    }
    if(ch == '9'){
      pos2 = lastPos2 + 10;
      myservo2.write(pos2);

    }
    if(ch == '10'){
      pos2 = lastPos2 - 10;
      myservo2.write(pos2);
    }
    if(ch == '11'){
      pos2 = lastPos2 + 1;
      myservo2.write(pos2);

    }
    if(ch == '12'){
      pos2 = lastPos2 - 1;
      myservo2.write(pos2);
    }
  lastPos = pos;
  lastPos2= pos2;
  
} 