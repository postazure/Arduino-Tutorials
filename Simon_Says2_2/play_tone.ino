
void play_tone(int freq){
  int notes[] = { 
    230, 400, 500, 600};

  tone(pinSpeaker, notes[freq]);
  delay(50);
  noTone(pinSpeaker);
}
