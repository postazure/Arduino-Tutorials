
const int button1 = 3;
const int button2 = 4;
const int button3 = 5;

void setup(){
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  Serial.begin(9600);  
}

void loop(){

  if(digitalRead(button1) == HIGH){
    Serial.println("BTN 1");
  }else if(digitalRead(button2) == HIGH){
    Serial.println("BTN 2");
  }else if(digitalRead(button3) == HIGH){
    Serial.println("BTN 3");
  }
}
  
  
