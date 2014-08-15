
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

