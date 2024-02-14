#include<Servo.h>
#include<Wire.h>

Servo Break;
Servo Pitch;

int movementTimer = 500;
int interruptTimer = 1000;
int Timer = 100;
int cutinTimer = 1000;
int cutinVoltage = 1;
float val1 = analogRead(A3);
float val2 = (val1/40.97);
int startTime = 0;
int endTime = 0;
int Rev = 0;
int RPM = 0;
const int signal = 2;
const int Ebreak = 3;
int IntBreakpos = 0;
int IntPitchpos = 10;
int FullyBreaked = 50;
int FullyPitched = 180;
int SpeedupPitch = 25;
int SlowdownPitch = 75;
int slowRPM = 500;
int fastRPM = 1800;






void setup() {
  Serial.begin(9600);
  Wire.begin();
  Break.attach(8);
  Pitch.attach(9);
  pinMode(signal, INPUT_PULLUP);
  pinMode(Ebreak, INPUT);


}

void loop() {
  Break.write(IntBreakpos);
  Pitch.write(IntPitchpos);
  delay(movementTimer);

  if(val2 >= cutinVoltage){
    delay(cutinTimer);
    if(Ebreak == HIGH){
      Rev = 0;
      RPM = 0;
      startTime = millis();
      attachInterrupt(digitalPinToInterrupt(signal),interrupt1,FALLING);
      delay(interruptTimer);
      detachInterrupt(signal);




      if(RPM<<slowRPM){
        Break.write(IntBreakpos);
        Pitch.write(SpeedupPitch);
        Serial.println(RPM);
        delay(movementTimer);




      }
      if(RPM>>fastRPM){
        Break.write(IntBreakpos);
        Pitch.write(SlowdownPitch);
        Serial.println(RPM);
        delay(movementTimer);

      }



    }
    else{
      Break.write(FullyBreaked);
      Pitch.write(FullyPitched);
      Serial.println("E Break Engaged");
      delay(movementTimer);

    }

  }
  else{
    Break.write(FullyBreaked);
    Pitch.write(FullyPitched);
    Serial.println("Cut In Votlage not Reached");
    delay(movementTimer);
  }
  delay(Timer);

}

void interrupt1(){
  Rev++;
}
