#include <Servo.h> //include servo library
Servo myservo;//create object for servo1
Servo myservo2;//create object for servo2

int pos = 0;//initialize pos for servo 1
int pos2 = 0;//initialize pos for servo 2



void setup() {
  Serial.begin(9600);
  while(! Serial);
  Serial.println("for servo1,Enter +F to move +50 and -F to move -50. Enter +B to move 10 and -B to move -10//
  for servo2,enter +K/-K to move +50/-50 and +T/-t to move +10/-10// enter ");
  myservo.attach(8);
  myservo2.attach(9);

  

}

void loop() {
  if(Serial.available()){
    char ch = Serial.read();
    if(ch == '+F'|| ch == '+f'){
      pos = pos+50;
      myservo.write(pos);
      delay(1000);

    }
    if(ch == '-F'|| ch == '-f'){
      pos = pos-50;
      myservo.write(pos);
      delay(1000);

    }
    if(ch == '+B' || ch == '+b'){
      pos = pos+10;
      myservo.write(pos);
      delay(1000);
    }
    if(ch == '-B' || ch == '-b'){
    pos = pos-10;
    myservo.write(pos);
    delay(1000);

    }
    if(ch == '+k' || '+k'){
      pos2 = pos2+50;
      myservo2.write(pos2);
      delay(1000);

    }
    if(ch == '-K' || '-k'){
      pos2 = pos2-50;
      myservo2.write(pos2);
      delay(1000);
    }
   if(ch == '+T' || '+t'){
    pos2 = pos2+10;
    myservo2.write(pos2);
    delay(1000);
   }
   if(ch == '-T' || ch == '-t'){
    pos2 = pos2-10;
    myservo2.write(pos2);
    delay(1000);
   }
   if(ch == 'R' || ch == 'r'){
    pos = 0;
    pos2 = 0;
    myservo.write(pos);
    myservo2.write(pos2);
    delay(1000);
   }
   else{
    pos = 0;
    pos2 = 0 
    myservo.write(pos);
    myservo2.write(pos2);
    
   }
   
  }

 
}

