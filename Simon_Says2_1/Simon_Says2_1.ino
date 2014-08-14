//Declare Pin Const
const int pinRed_btn = 2;
const int pinYel_btn = 3;
const int pinGre_btn = 8;
const int pinBlu_btn = 12;
const int pinRed_led = 4;
const int pinYel_led = 5;
const int pinGre_led = 6;
const int pinBlu_led = 7;
const int pinSpeaker = 11;

int led_string[] = {
  pinRed_led, pinYel_led, pinGre_led, pinBlu_led};
int btn_string[] = {
  pinRed_btn, pinYel_btn, pinGre_btn, pinBlu_btn};
  
int roundCounter;
int simon_pick[100] = {};

int gameRunning = 1;

//debounce
int debounceTime = 300;
int timeMark = millis();
int user_guess;


void display_simon(){ //shows the colors at start of round 
  simon_pick[roundCounter] = (int) random(4);

  for(int i; i <= roundCounter; i++){
    play_tone(simon_pick[i]);
    flash_led(simon_pick[i], 400);
    delay(200);
  }
}

void play_tone(int freq){
  int notes[] = { 
    230, 400, 500, 600};

  tone(pinSpeaker, notes[freq]);
  delay(50);
  noTone(pinSpeaker);
}

void flash_led(int ledName, int ledTime){
  //red, yellow, green, blue
  //time in ms  
  digitalWrite(led_string[ledName], HIGH);
  delay(ledTime);
  digitalWrite(led_string[ledName], LOW); 
}

void get_guess(){ //wait for player to guess (debounce)
  int timeDelta = millis() - timeMark;  
  while(digitalRead(pinRed_btn) == LOW && 
    digitalRead(pinYel_btn) == LOW && 
    digitalRead(pinGre_btn) == LOW && 
    digitalRead(pinBlu_btn) == LOW){}
  
  if(timeDelta > debounceTime){
    timeMark = millis();
    if(digitalRead(pinRed_btn) == HIGH){
      user_guess = 0;
    }
    else if(digitalRead(pinYel_btn) == HIGH){
      user_guess = 1;
    }
    else if(digitalRead(pinGre_btn) == HIGH){
      user_guess = 2;
    }
    else if(digitalRead(pinBlu_btn) == HIGH){
      user_guess = 3;
    }   
    play_tone(user_guess);
    flash_led(user_guess, 350);
  }
}

void check_guess(int _i){ //match guess with simon's pick, determine if correct
  if(user_guess != simon_pick[_i]){
    gameRunning = 0;
  }
}

void game_start(){ // opening sequence, reset round
  for(int i = 0; i < 4; i++){
    digitalWrite(led_string[i], HIGH);
    play_tone(i);
  }
  delay(250);
  for(int i = 0; i < 4; i++){
    digitalWrite(led_string[i], LOW);
  }
  roundCounter = 0;
  gameRunning = 1;
  delay(300);
}

void game_over(){ //end game, show score
  for(int j = 0; j <= 3; j++){
    play_tone(0);
    for(int i = 0; i <= 4; i++){
      digitalWrite(led_string[i], HIGH);
    }
    delay(100);
    for(int i = 0; i <= 4; i++){
      digitalWrite(led_string[i], LOW);
    }
    delay(50);
  }
  Serial.println("Game Over");
  Serial.print("Your Score: ");
  Serial.println(roundCounter);
}

void setup(){
  for(int i = 0; i < 4; i++){
    pinMode(btn_string[i], INPUT);
    pinMode(led_string[i], OUTPUT);
  }
  pinMode(pinSpeaker, OUTPUT);
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

void loop(){
  game_start();
  Serial.println();
  Serial.println("==========Start New Game===========");
  while(gameRunning == 1){
    display_simon();
    for(int trans_i = 0; trans_i <= roundCounter; trans_i++){
      get_guess();
      check_guess(trans_i);
      if(gameRunning == 0){
        break;
      }
    }
    if(gameRunning == 1){
      for(int i = 0; i < 4; i++){ 
        play_tone(i);
        digitalWrite(led_string[i], HIGH);
      }
      delay(400);
      for(int i = 0; i<4; i++){
        digitalWrite(led_string[i], LOW);
      }
    }
    roundCounter++;
  }
  game_over();
  delay(3000);
}

























