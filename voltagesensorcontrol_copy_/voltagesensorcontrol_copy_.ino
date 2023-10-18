//This is a simple code that utilizes the voltage sensor to control the pos of the actuator. 
//The current sensor will be implimented into this code also, the goal is to expaned this into the final control setup. 



#include<Servo.h>
Servo myservo;
int pos = 10;

float val1 = analogRead(A3);
float val2 = (val1/40.97);


void setup() {
Serial.begin(9600);
myservo.attach(9);
pos = 10;
myservo.write(10);

  

}

void loop() {
  
  if(val2 >=10&& val2<=15){
    pos = 180;
    myservo.write(pos);
    delay(2000);

  }
  if(val2 >=0 && val2 <=9){
    pos = 10;
    myservo.write(pos);
    delay(2000);

  }
  serialprint;
  delay(5000);

 

  

  
 

}
void serialprint(){
  Serial.println(val2);
  Serial.println(pos);

}

