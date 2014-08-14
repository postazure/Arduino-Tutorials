//Declare Pin Const
const int pinRed_btn = 2;
const int pinYel_btn = 3;
const int pinGre_btn = 8;
const int pinBlu_btn = 12;

const int pinRed_led = 4;
const int pinYel_led = 5;
const int pinGre_led = 6;
const int pinBlu_led = 7;

int roundCounter = 0;
int scoreCounter = 0;

int trans_i = 0;

int simon_pick[] = {
  0};
//int simon_pick_color;

//int round_pick;
int led_string[] = {
  pinRed_led, pinYel_led, pinGre_led, pinBlu_led};
int btn_string[] = {
  pinRed_btn, pinYel_btn, pinGre_btn, pinBlu_btn};

int gameRunning = 1;

//debounce
int pinState_btn;
int debounceTime = 300;
int timeMark = millis();
int timeDelta;
int user_guess = 4;


void display_simon(){ //shows the colors at start of round 
  int simon_pick_color;
  for(int i; i <= roundCounter; i++){
    if(simon_pick[i] == 0){
      simon_pick_color = pinRed_led;
    }
    else if(simon_pick[i] == 1){
      simon_pick_color = pinYel_led;
    }
    else if(simon_pick[i] == 2){
      simon_pick_color = pinGre_led;
    }
    else if(simon_pick[i] == 3){
      simon_pick_color = pinBlu_led;
    }
    else{
      Serial.println("##### simon_pick[] error.");
    }

    digitalWrite(simon_pick_color, HIGH);
    delay(450);
    digitalWrite(simon_pick_color, LOW);
    delay(100); 
  }
}

void get_guess(){ //wait for player to guess (debounce)
  timeDelta = millis() - timeMark;  
  while(digitalRead(pinRed_btn) == LOW && digitalRead(pinYel_btn) == LOW && digitalRead(pinGre_btn) == LOW && digitalRead(pinBlu_btn) == LOW){
  }


  if(timeDelta > debounceTime){
    timeMark = millis();
    if(digitalRead(pinRed_btn) == HIGH){
      user_guess = 0;
      digitalWrite(pinRed_led, HIGH);
      delay(350);
      digitalWrite(pinRed_led, LOW); 
    }
    else if(digitalRead(pinYel_btn) == HIGH){
      user_guess = 1;
      digitalWrite(pinYel_led, HIGH);
      delay(350);
      digitalWrite(pinYel_led, LOW);      
    }
    else if(digitalRead(pinGre_btn) == HIGH){
      user_guess = 2;
      digitalWrite(pinGre_led, HIGH);
      delay(350);
      digitalWrite(pinGre_led, LOW);
    }
    else if(digitalRead(pinBlu_btn) == HIGH){
      user_guess = 3;
      digitalWrite(pinBlu_led, HIGH);
      delay(350);
      digitalWrite(pinBlu_led, LOW);
    }    

  }

}

void pick_simon(){
  int round_pick = random(0,3);
  Serial.print("pick_simon(), roundCounter: ");
  Serial.println(roundCounter);
  simon_pick[roundCounter] = round_pick;
  Serial.print("simon_pick[roundCounter]: ");
  Serial.println(simon_pick[roundCounter]);
}


void check_guess(){ //match guess with simon's pick, determine if correct
  Serial.print("Checking Guess \tPlayer's Guess: ");
  Serial.print(user_guess);
  Serial.print(" , Simon's Color: ");
  trans_i = 0;
  while(trans_i <= roundCounter){
    Serial.println(simon_pick[trans_i]);
    if(user_guess != simon_pick[trans_i]){
      trans_i = roundCounter + 1; //exits loop

      Serial.println("Game Over");
      Serial.print("Your Score: ");
      Serial.println(roundCounter);
      game_over();

      gameRunning = 0;
    }
    else if(user_guess == simon_pick[trans_i]){
      Serial.print("check_guess Correct");

    }
    else{
      Serial.print("###check_guess error"); 
    }
    trans_i++;
    if(trans_i<= roundCounter){
       get_guess();
    }

  }

  for(int i = 0; i < 4; i++){ 
    digitalWrite(led_string[i], HIGH);
  }
  delay(500);
  for(int i = 0; i<4; i++){
    digitalWrite(led_string[i], LOW);
  }
  delay(200);
}

void game_start(){ // opening sequence, reset round
  for(int i = 0; i < 4; i++){
    digitalWrite(led_string[i], HIGH);
  }
  delay(250);
  for(int i = 0; i < 4; i++){

    digitalWrite(led_string[i], LOW);
  }
  roundCounter = 0;
  scoreCounter = 0;
  gameRunning = 1;


}

void game_over(){ //end game, show score
  for(int i = 0; i <= roundCounter; i++){
    led_string[0];
  }
}




void setup(){
  for(int i = 0; i < 4; i++){
    pinMode(btn_string[i], INPUT);
    pinMode(led_string[i], OUTPUT);
  }

  Serial.begin(9600);
}
void loop(){
  game_start();
  Serial.println();
  Serial.println("==========Start New Game===========");
  while(gameRunning == 1){
    pick_simon();
//    Serial.print("Simon picked a color. ");
//    Serial.println(round_pick);
//    Serial.print("pre display_simon(): simon_pick[roundCounter]: ");
//    Serial.println(simon_pick[roundCounter]);
    display_simon();
//    Serial.print("Simon's colors: ");
//    for(int i = 0; i<=roundCounter; i++){
//      Serial.print(simon_pick[i]);
//      Serial.print(", ");
//    }
//    Serial.println();
//    Serial.print("Pre get_guess(): simon_pick[roundCounter]: ");
//    Serial.println(simon_pick[roundCounter]);
    get_guess();
//    Serial.print("Player guessed: ");
//    Serial.println(user_guess);
//    Serial.print("Pre check_guess(): simon_pick[roundCounter]: ");
//    Serial.println(simon_pick[roundCounter]);
    check_guess();

    roundCounter++;
    Serial.println("----------New Round----------");
  }

  delay(3000);
}









