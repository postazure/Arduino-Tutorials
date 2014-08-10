const int redLED = 11;
const int greenLED = 9;
const int blueLED = 10;

const int redSens = A2;
const int greenSens = A0;
const int blueSens = A1;

int redVal_LED = 0;
int greenVal_LED = 0;
int blueVal_LED = 0;

int redVal_Sens = 0;
int greenVal_Sens = 0;
int blueVal_Sens = 0;

void setup(){
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop(){
  redVal_Sens = analogRead(redSens);
  delay(5);
  greenVal_Sens = analogRead(greenSens);
  delay(5);
  blueVal_Sens = analogRead(blueSens);
  
  Serial.print("Raw Sens Val \t Red: ");
  Serial.print(redVal_Sens);
  Serial.print("\t Green: ");
  Serial.print(greenVal_Sens);
  Serial.print("\t Blue: ");
  Serial.print(blueVal_Sens);
  
  redVal_LED = redVal_Sens/4;
  greenVal_LED = greenVal_Sens/4;
  blueVal_LED = blueVal_Sens/4;
  
  Serial.print("Mapped Sensor Values \t Red: ");
  Serial.print(redVal_LED);
  Serial.print("\t Green: ");
  Serial.print(greenVal_LED);
  Serial.print("\t Blue: ");
  Serial.println(blueVal_LED);
  
  analogWrite(redLED, redVal_LED);
  analogWrite(greenLED, greenVal_LED);
  analogWrite(blueLED, blueVal_LED);
  
}
  
  
  
