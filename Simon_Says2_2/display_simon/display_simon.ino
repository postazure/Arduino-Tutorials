
void display_simon(){ //shows the colors at start of round 
  simon_pick[roundCounter] = (int) random(4);

  for(int i; i <= roundCounter; i++){
    play_tone(simon_pick[i]);
    flash_led(simon_pick[i], 400);
    delay(200);
  }
}
