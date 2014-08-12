
const int button1 = 8;
const int button2 = 3;
const int button3 = 2;

int pinState_cur = 0;

//Debounce Vars
const int debounceTime = 300;  //300ms pause
int timeSinceBtn_pressed = 0;
int timeSinceBtn_counter = 0;
int timePassed;


void setup(){
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);

  Serial.begin(9600);  
}

void loop(){

  
  if(digitalRead(button1) == HIGH){
    pinState_cur = 1;

  }
  else if(digitalRead(button2) == HIGH){
    pinState_cur = 2;

  }
  else if(digitalRead(button3) == HIGH){
    pinState_cur = 3;

  }
  timeSinceBtn_counter = millis();
  timePassed = timeSinceBtn_counter - timeSinceBtn_pressed;
  
  if (pinState_cur != 0 && timePassed > debounceTime){
    Serial.print(timePassed);
    Serial.print("BTN: ");
    Serial.println(pinState_cur);
    timeSinceBtn_pressed = timeSinceBtn_counter;
    pinState_cur = 0;
  }else{
    pinState_cur = 0;
  }
   
}



