const int sensorPin = A0; //const is a variable whos value cannot be changed
float baselineTemp = 0.0;
float voltage = 0.0;
float temperature = 0.0;
int sensorVal = 0;
//LED pin 2-4
//sensor pin A0

void setup(){
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber < 5; pinNumber++ ){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
  
  sensorVal = analogRead(sensorPin);
  voltage = (sensorVal/1024.0) * 5.0;
  baselineTemp = (voltage -.5) * 100;
}

void loop(){
  sensorVal = analogRead(sensorPin);
  
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  
  voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  
  Serial.print(", degrees C: ");
  temperature = (voltage -.5) * 100;
  Serial.println(temperature);
  
  if(temperature < baselineTemp){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+1 && temperature < baselineTemp + 2){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+2 && temperature < baselineTemp+3){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }else if(temperature >= baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(10);
}
