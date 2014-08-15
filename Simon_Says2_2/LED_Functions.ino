
void flash_led(int ledName, int ledTime){
  //red, yellow, green, blue
  //time in ms  
  digitalWrite(led_string[ledName], HIGH);
  delay(ledTime);
  digitalWrite(led_string[ledName], LOW); 
}

void flash_led_correct(){
        for(int i = 0; i < 4; i++){ 
        play_tone(i);
        digitalWrite(led_string[i], HIGH);
      }
      delay(400);
      for(int i = 0; i<4; i++){
        digitalWrite(led_string[i], LOW);
      }
}
