
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

