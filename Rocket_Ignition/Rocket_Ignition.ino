
int switchState = 0;

int buttonPin = 2;
int greenLED = 3;
int redLED_a = 4;
int redLED_b = 5;


void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED_a, OUTPUT);
  pinMode(redLED_b, OUTPUT);

}

void loop(){
  switchState = digitalRead(buttonPin);
  //LOW == NOT PRESSED
  if (switchState == LOW){
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED_a, LOW);
    digitalWrite(redLED_b, LOW);
  }
  else{
    digitalWrite(greenLED, LOW);
    digitalWrite(redLED_a, HIGH);
    digitalWrite(redLED_b, LOW);

    delay(250);

    digitalWrite(redLED_a, LOW);
    digitalWrite(redLED_b, HIGH);

    delay(250);
  }


}

