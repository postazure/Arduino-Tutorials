
int simonPicks[] = {
};
int pick;
// 0 = red, 1 = yellow, 2 = green, 3 = blue
int pinRed_led = 2;
int pinRed_btn = 4;
int pinYel_led = 3;
int pinYel_btn = 5;
int pinGre_led = 11;
int pinGre_btn = 9;
int pinBlu_led = 12;
int pinBlu_btn = 10;
boolean waiting = true;

int roundCount = 0;

int user_guess;

void gameOver(){
  Serial.print("Game Over Score:");
  Serial.println(roundCount);

  for(int i; i<=roundCount; i++){
    digitalWrite(pinRed_led, HIGH);
    delay(250);
    digitalWrite(pinRed_led, LOW);
    delay(100); 
  }
  delay(3000);
}

void setup(){
  Serial.begin(9600);
  Serial.print("Game Start");

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
  
  digitalWrite(pinRed_led, HIGH);
  digitalWrite(pinYel_led, HIGH);
  digitalWrite(pinGre_led, HIGH);
  digitalWrite(pinBlu_led, HIGH);
  delay(1000);
  digitalWrite(pinRed_led, LOW);
  digitalWrite(pinYel_led, LOW);
  digitalWrite(pinGre_led, LOW);
  digitalWrite(pinBlu_led, LOW);
  
}

void loop(){
  //Serial.println(a);
  pick = random(4);
  simonPicks[roundCount] = pick;

  for(int i; i <= roundCount; i++){
    digitalWrite(simonPicks[i], HIGH);
    delay(500);
    digitalWrite(simonPicks[i], LOW);
    delay(20);
    Serial.println(simonPicks[i]);
  }

  for(int j; j <= roundCount; j++){

    waiting = true;
    while(waiting == true){
      Serial.println("Waiting..");
      if(digitalRead(pinRed_btn) == HIGH){
        user_guess = 0;
        Serial.print("User Guess ");
        Serial.println("Red");
        waiting = false;
      }
      if(digitalRead(pinYel_btn) == HIGH){
        user_guess = 1;
        Serial.print("User Guess ");
        Serial.println("Yellow");
        waiting = false;
      }
      if(digitalRead(pinGre_btn) == HIGH){
        user_guess = 2;
        Serial.print("User Guess ");
        Serial.println("Green");
        waiting = false;
      }
      if(digitalRead(pinBlu_btn) == HIGH){
        Serial.print("User Guess ");
        Serial.println("Blue");
        user_guess = 3;
        waiting = false;
      }
    }

    if(simonPicks[j] != user_guess){
      gameOver();
    }

  }  

  roundCount++; //increase the round and score
}



