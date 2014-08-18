#include <Debounce.h>

class Debounce
{
  public:
  Debounce(int btn);
  int debounce();
    
    
  private:
  int _timeMarker;
  int _timeCounter;
  int _timeDelta;
  
  int _btn;
  int _validBtn;
  int _debounceTime
};
