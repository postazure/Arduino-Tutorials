Debounce::Debounce(int btn){
  _btn = btn; 
  _validBtn = 0; 
  _timeDelta = 0;
  _debounceTime = 300; //300ms read pause
}


int Debounce::debounce()
  _timeCounter = millis();
  _timeDelta = _timeCounter - _timeMarker;
  
  if (_btn != 0 && _timeDelta > _debounceTime){
    //Serial.println(pinState_cur);
    _timeMarker = _timeCounter;
    _validBtn = _btn;
    _btn = 0;
  }else{
    _btn = 0;
  }
  return _validBtn;
}
  
  
  
  
  
