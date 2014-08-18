#include <LiquidCrystal.h>
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

const int pinUp_btn = 3;
const int pinDown_btn = 4;
const int pinSelect_btn = 5;

int btn_list[] = {
  pinUp_btn, pinDown_btn, pinSelect_btn};

int pressed_btn;
int btnState[3];

void setup(){
  //buttons
  for(int i= 0; i<3; i++){
    pinMode(btn_list[i], INPUT);
  }
  pinMode(5,INPUT);
  //lcd
  lcd.begin(16,2);
  lcd.print("Jump and Duck");
  lcd.setCursor(0,1);
  lcd.print("by Postazure");
  Serial.begin(9600);
  for(int i = 0; i<3; i++){
    Serial.print(btn_list[i]);
  }
}

void loop(){


//  for(int i = 0; i<3; i++){
//    
//    btnState[i] = digitalRead(btn_list[i]);
//  }
    btnState[2] = digitalRead(5);
  btnState[0] = digitalRead(btn_list[0]);
  btnState[1] = digitalRead(btn_list[1]);

  Serial.print("dr(btn_l[2]): ");
  Serial.println(digitalRead(5));
  
  get_input();

  Serial.println(pressed_btn);






}

