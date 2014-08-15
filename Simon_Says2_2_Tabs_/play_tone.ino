
void play_tone(int freq){
  int notes[] = { 
    300, 400, 500, 600};

  tone(pinSpeaker, notes[freq]);
  delay(50);
  noTone(pinSpeaker);
}
