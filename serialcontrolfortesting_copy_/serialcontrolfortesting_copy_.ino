#include <Servo.h> //include servo library
Servo myservo;//create object for servo1


int pos = 10;//initialize pos for servo 1
char ch = Serial.read();
bool lastPos = pos; 



void setup() {
  Serial.begin(9600);
  while(! Serial);
  Serial.println("enter +F to move servo 1 postive +50, enter -F to move -50, enter +B to move servo 1 +10, - B to move -10.enter +K to move servo 2 +50 and -K to move -50, enter +t to move servo 2 +10 and -T to move -10. Enter R to reset.");
  myservo.attach(8);
  pos = 10;
  myservo.write(pos);
 


}

void loop() {
  if(Serial.available()){
    if(ch == 'f' || ch == 'F'){
      pos = lastPos + 50;
      myservo.write(pos);

    }
    if(ch == 'b' || ch == 'B'){
      pos = lastPos - 50;
      myservo.write(pos);


    }
    if(ch == 'w' || ch == 'W'){
      pos = lastPos + 10;
      myservo.write(pos);

    }
    if(ch == 'd'|| ch == 'D'){
      pos = lastPos - 10;
      myservo.write(pos);

    }
    if(ch == 'y' || ch == 'Y'){
      pos = lastPos + 1;
      myservo.write(pos);
    }
    if(ch == 'p' || ch == 'P'){
      pos = lastPos - 1;
      myservo.write(pos);
    }
  }
} 


