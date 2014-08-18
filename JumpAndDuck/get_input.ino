void get_input(){
  
  pressed_btn = -1;
  
  
  
  for(int i = 0; i<3; i++){
    if(btnState[i] == HIGH){
      Serial.print("Setting button ");
      Serial.println(i);
      pressed_btn = i;
    }
  }
}


