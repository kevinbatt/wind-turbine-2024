const int signal = 2;
int rev = 0;
int rpm = 0;
long startTime = 0;
long endTime = 0;





void setup() {
  Serial.begin(9600);
  pinMode(signal, INPUT_PULLUP);

}

void loop() {
  rev = 0;
  rpm = 0;
  startTime = millis();
  attachInterrupt(digitalPinToInterrupt(signal),interrupt1,FALLING);
  delay(1000);
  detachInterrupt(signal);
  endTime = millis()- startTime;
  if(rev>0){
    rpm = (rev*60000)/(3*endTime);
    Serial.println(rpm);


  }
  

}

void interrupt1(){
  rev++;

}
