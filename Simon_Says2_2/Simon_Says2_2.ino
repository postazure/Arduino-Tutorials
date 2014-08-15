/*  Simon Says
 Compatable with Uno
 
 created by Postazure
 on 8/14/14 */




//------------------------------------Global Variables
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
int simon_pick[100] = {
};

int gameRunning = 1;

//debounce vars
int debounceTime = 300;
int timeMark = millis();
int user_guess;


//---------------------------------- Setup, initalize game
void setup(){
  for(int i = 0; i < 4; i++){
    pinMode(btn_string[i], INPUT);
    pinMode(led_string[i], OUTPUT);
  }
  pinMode(pinSpeaker, OUTPUT);
  
  randomSeed(analogRead(0));
  Serial.begin(9600);
}

//------------------------------------Main Loop
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
      flash_led_correct();
      }
      roundCounter++;
  }
  game_over();
  delay(3000);
}


























