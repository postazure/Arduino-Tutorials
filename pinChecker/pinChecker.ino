int pinState;

void setup(){
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13, LOW);
}

void loop(){
  pinState = digitalRead(2);
  
  if(pinState == HIGH){
    digitalWrite(13, HIGH);
    delay(300);
    pinState = LOW;
  }else{
    digitalWrite(13, LOW);
}
}
