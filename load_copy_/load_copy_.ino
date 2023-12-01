
const int relay1 = 9;
const int relay2 = 10;
const int relay3 = 11;

void setup(){
  Serial.begin(9600);
  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(relay3,OUTPUT);

}
void loop(){
  float val1 = analogRead(A3);
  float val2 = (val1/40.97);

  if(val2 >=1&&val2<=4){
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,LOW);
    digitalWrite(relay3,LOW);
  }
  if(val2>=4&&val2<=8){
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    digitalWrite(relay3,LOW);
  }
  if(val2>=9){
    digitalWrite(relay1,HIGH);
    digitalWrite(relay2,HIGH);
    digitalWrite(relay3,HIGH);
  }
  if(val2<1){
    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    digitalWrite(relay3,LOW);
 }
  Serial.println(val2);
  delay(2000);

}


  
