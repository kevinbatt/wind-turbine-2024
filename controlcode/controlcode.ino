#include<Servo.h> //library used to control actuators
#include<Wire.h>  //if needed included i2c library

Servo Break; // make object for break actuator
Servo Pitch; // make object for pitch actuator

int movementTimer = 500; //timer to allow for actuator movement
int interruptTimer = 1000; // timer used for interrupt function
int Timer = 100; // general timer
int cutinTimer = 1000; // allow time for cut in voltage to be reached
int cutinVoltage = 1; // cut in voltage needs to be adjusted as needed
float val1 = analogRead(A3); // 8 bit value from voltage sensor
float val2 = (val1/40.97); //converted to actual voltag being read
float ial1 = analogRead(A4); //this is going to be our check for load connection
float ial2 = (ial1/50); //  need to figure out what the correct factor is for this but this will be our actual current going to the load, if this drops to zero the load is open and we need to stop the system. 
int startTime = 0; // initiate start time
int endTime = 0; // initiate end time
int Rev = 0; // initiate Revolutions
int RPM = 0; // initiate RPM
int rev = 0; // rev = Rev/3
const int signal = 2; // attach hall effect to pin 2
const int Ebreak = 3; // attach ebreak to pin 3
int IntBreakpos = 0; // initiate break pos
int IntPitchpos = 60; // initiate pitch pos
int FullyBreaked = 50; // the remaining vales are different variables used during the code
int FullyPitched = 85;
int SpeedupPitch = 60;
int SlowdownPitch = 85;
int slowRPM = 500;
int fastRPM = 1800;






void setup() {
  Serial.begin(9600);//begin serial
  Wire.begin(); // being i2c
  Break.attach(8); // attach break to pin 8
  Pitch.attach(9); // attach pitch to pin 9
  pinMode(signal, INPUT_PULLUP); //set signal as input
  pinMode(Ebreak, INPUT); // set ebreak as input


}

void loop() {
  Break.write(IntBreakpos);//move to initial break pos
  Pitch.write(IntPitchpos); // move to initial pitch pos
  delay(movementTimer); 

  if(val2 >= cutinVoltage){ //check that cut in voltage is reached
    delay(cutinTimer);
    digitalRead(Ebreak);
    if(Ebreak == HIGH){ // check that ebreak is not pressed
      if(ial2 >= 1){ // check to make sure that the load is connected
      Rev = 0;
      RPM = 0;
      startTime = millis();
      attachInterrupt(digitalPinToInterrupt(signal),interrupt1,FALLING); //attach signal to interrupt1 function on falling edge
      delay(interruptTimer);
      detachInterrupt(signal);
       if(Rev>0){ 
        rev = (Rev/3);
        RPM = (rev*60000)/(endTime);//calculate RPM based on number of revolutions
        Serial.println(RPM);
       }

      if(RPM<<slowRPM){//check RPM
        Break.write(IntBreakpos);
        Pitch.write(SpeedupPitch);
        Serial.println(RPM);
        delay(movementTimer);


      }
      if(RPM>>fastRPM){//Check RPM
        Break.write(IntBreakpos);
        Pitch.write(SlowdownPitch);
        Serial.println(RPM);
        delay(movementTimer);

      }



    }
    else{
      Break.write(FullyBreaked);
      Pitch.write(FullyPitched);
      Serial.println("LOAD Disconnected");
      delay(movementTimer);

    }
    }
    else{//if e break pressed this will happen instead
      Break.write(FullyBreaked);
      Pitch.write(FullyPitched);
      Serial.println("E Break Engaged");
      delay(movementTimer);

    }

  }
  else{//if cut in votlage is not reached this will happen instead
    Break.write(FullyBreaked);
    Pitch.write(FullyPitched);
    Serial.println("Cut In Votlage not Reached");
    delay(movementTimer);
  }
  delay(Timer);

}

void interrupt1(){//interrupt function
  Rev++;
}
