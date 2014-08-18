const int pinBtn[] = {2,3,4};
const int pinLed[] = {10,11,12};
int qtyPlayers = 3;



void setup(){
//Set INPUTs and OUTPUTs
  for(int i = 0; i<qtyPlayers; i++){
    pinMode(pinBtn[i], INPUT);
    pinMode(pinLed[i], OUTPUT);
  }
//Initiate Terminal Contact
  Serial.begin(9600);
  Serial.print("-=Start=-");
  qtyPlayers = player_setup();
}

void loop(){
  toggle();
  
}

int player_setup(){
  //each player that is playing presses their button in player order. Then press RE to select done.
  return numOfPlayers;
}

void toggle(){
  int pinState[qtyPlayers];
  int pinState_prev[] = {LOW,LOW,LOW};
  int ledState[] = {LOW,LOW,LOW};
  const int debounce = 100;
  int time = millis();

  for(int i =0; i<qtyPlayers;i++){
    pinState[i] = digitalRead(pinBtn[i]);
    if(pinState[i] == HIGH && pinState_prev[i] == LOW && millis() - time > debounce){
      if(ledState[i] == LOW){   
        ledState[i] = HIGH;       
      }else{
        ledState[i] = LOW;
      } 
      time = millis();
    }
    digitalWrite(pinLed[i], ledState[i]);
    pinState_prev[i] = pinState[i];
  }
}
