
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

