
int simonPicks[] = {
};
int pick;
// 0 = red, 1 = yellow, 2 = green, 3 = blue
int pinRed_led = 4;
int pinRed_btn = 2;
int pinYel_led = 5;
int pinYel_btn = 3;
int pinGre_led = 6;
int pinGre_btn = 8;
int pinBlu_led = 7;
int pinBlu_btn = 12;
boolean waiting = true;

int roundCount = 0;

int user_guess;
int btn;

void gameReady(){
  digitalWrite(pinRed_led, HIGH);
  digitalWrite(pinYel_led, HIGH);
  digitalWrite(pinGre_led, HIGH);
  digitalWrite(pinBlu_led, HIGH);
  delay(1000);
  digitalWrite(pinRed_led, LOW);
  digitalWrite(pinYel_led, LOW);
  digitalWrite(pinGre_led, LOW);
  digitalWrite(pinBlu_led, LOW); 
    roundCount = 0;

  user_guess = 4;
}

void gameOver(){
  Serial.print("Game Over Score:");
  Serial.println(roundCount);

  for(int i; i<=roundCount; i++){
    digitalWrite(pinRed_led, HIGH);
    delay(250);
    digitalWrite(pinRed_led, LOW);
    delay(100); 
  }
  Serial.println("Waiting for new game");
  delay(3000);
  gameReady();
}

void debounce(){
  int timeMark;
  int timeDelta;
  const int debounceTime = 700;

  timeDelta = millis() - timeMark;

  if(btn != 4 && timeDelta > debounceTime){
    timeMark = millis();
    user_guess = btn;
    btn = 4;
  }
  else{
    btn = 4;
    delay(100);
  }
}

void get_guess(){
  Serial.print("get_guess");
  Serial.println(user_guess);
  if(user_guess == 0){ //red
    digitalWrite(pinRed_led, HIGH);
    delay(100);
    digitalWrite(pinRed_led, LOW);
    Serial.print("User Guess ");
    Serial.println("Red");
  }
  else if(user_guess == 1){ //yellow
    digitalWrite(pinYel_led, HIGH);
    delay(100);
    digitalWrite(pinYel_led, LOW);
    Serial.print("User Guess ");
    Serial.println("Yellow");  
  }
  else if(user_guess == 2){  //green
    digitalWrite(pinGre_led, HIGH);
    delay(100);
    digitalWrite(pinGre_led, LOW);      
    Serial.print("User Guess ");
    Serial.println("Green");
  }
  else if(user_guess == 3){ //blue
    digitalWrite(pinBlu_led, HIGH);
    delay(100);
    digitalWrite(pinBlu_led, LOW);  
    Serial.print("User Guess ");
    Serial.println("Blue");
  }

}


void setup(){
  Serial.begin(9600);
  Serial.println("Game Start");

  //OUTPUTS
  pinMode(pinRed_led, OUTPUT);
  pinMode(pinYel_led, OUTPUT);
  pinMode(pinGre_led, OUTPUT);
  pinMode(pinBlu_led, OUTPUT);

  //INPUTS
  pinMode(pinRed_btn, INPUT);
  pinMode(pinYel_btn, INPUT);
  pinMode(pinGre_btn, INPUT);
  pinMode(pinBlu_btn, INPUT);


  gameReady(); 


}

void loop(){

  pick = random(4);
  simonPicks[roundCount] = pick;

  for(int i = 0; i <= roundCount; i++){

    if(simonPicks[i] == 0){
      digitalWrite(pinRed_led, HIGH);
      delay(750);
      digitalWrite(pinRed_led, LOW);
      delay(100);
    }
    else if(simonPicks[i] == 1){
      digitalWrite(pinYel_led, HIGH);
      delay(750);
      digitalWrite(pinYel_led, LOW);
      delay(100);
    }
    else if(simonPicks[i] == 2){
      digitalWrite(pinGre_led, HIGH);
      delay(750);
      digitalWrite(pinGre_led, LOW);
      delay(100);
    }
    else if(simonPicks[i] == 3){
      digitalWrite(pinBlu_led, HIGH);
      delay(750);
      digitalWrite(pinBlu_led, LOW);
      delay(100);
    }
    Serial.println(simonPicks[i]);
    Serial.println(roundCount);
  }

  for(int j = 0; j <= roundCount; j++){


    while(digitalRead(pinRed_btn) == LOW && digitalRead(pinYel_btn) == LOW && digitalRead(pinGre_btn) == LOW && digitalRead(pinBlu_btn) == LOW){
    }
    //Serial.println("Waiting..");

    if(digitalRead(pinRed_btn) == HIGH){
      btn = 0;
    }
    if(digitalRead(pinYel_btn) == HIGH){
      btn = 1;
    }
    if(digitalRead(pinGre_btn) == HIGH){
      btn = 2;
    }
    if(digitalRead(pinBlu_btn) == HIGH){
      btn = 3;
    }

    debounce();
    get_guess();

    if(simonPicks[j] != user_guess){
      gameOver();
    }

  }  

  roundCount++; //increase the round and score
}









