# include <Keyboard.h> 
void setup() {
  // put your setup code here, to run once:

  //start emulating a keyboard
  Keyboard.begin();

  //configure pins as an input and enables the internal pull-up resistor
  pinMode(0, INPUT_PULLUP); //PL2 A
  pinMode(1, INPUT_PULLUP); //PL2 B
  pinMode(2, INPUT_PULLUP); //PL2 Left
  pinMode(3, INPUT_PULLUP); //PL2 Down
  pinMode(4, INPUT_PULLUP); //PL2 Right
  pinMode(5, INPUT_PULLUP); //PL2 Up


}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(0) == LOW){
    //Send an ASCII 'V'
      Keyboard.press('v');
  }
  else {
    Keyboard.release('v');
  }
  
  if (digitalRead(1) == LOW){
    //Send an ASCII 'C'
    Keyboard.press('c');
  }
  else{
    Keyboard.release('c');
  }
  
  if (digitalRead(4) == LOW){
  //Send an ASCII 'A'
    Keyboard.press('a');
  }
  else{
    Keyboard.release('a');
  }
  
  if (digitalRead(3) == LOW){
    //Send an ASCII 'S'
    Keyboard.press('s');
  }
  else{
    Keyboard.release('s');
  }
  
  if (digitalRead(2) == LOW)
  {
    //Send an ASCII 'D'
    Keyboard.press('d');
  }
  else{
    Keyboard.release('d');
  }
  
  if (digitalRead(5) == LOW)
  {
    //Send an ASCII 'W'
    Keyboard.press('w');
  }
  else{
    Keyboard.release('w');
  }
   
}
