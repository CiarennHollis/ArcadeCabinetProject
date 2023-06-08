# include <Keyboard.h> 
void setup() {
  // put your setup code here, to run once:

  //start emulating a keyboard
  Keyboard.begin();

  //configure pins as an input and enables the internal pull-up resistor
  //PL2
  pinMode(0, INPUT_PULLUP); //PL2 A
  pinMode(1, INPUT_PULLUP); //PL2 B
  pinMode(2, INPUT_PULLUP); //PL2 Left
  pinMode(3, INPUT_PULLUP); //PL2 Down
  pinMode(4, INPUT_PULLUP); //PL2 Right
  pinMode(5, INPUT_PULLUP); //PL2 Up
  //PL1
  pinMode(6, INPUT_PULLUP); //PL1 A
  pinMode(7, INPUT_PULLUP); //PL1 B
  pinMode(8, INPUT_PULLUP); //PL1 Left
  pinMode(9, INPUT_PULLUP); //PL1 Down
  pinMode(10, INPUT_PULLUP); //PL1 Right
  pinMode(11, INPUT_PULLUP); //PL1 Up


}

void loop() {
  // put your main code here, to run repeatedly:
  ListenForPL2();
  ListenForPL1();
   
}

void ListenForPL2()
{
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

void ListenForPL1()
{
  if (digitalRead(6) == LOW){
    //Send an ASCII 'N'
      Keyboard.press('n');
  }
  else {
    Keyboard.release('n');
  }
  
  if (digitalRead(7) == LOW){
    //Send an ASCII 'M'
    Keyboard.press('m');
  }
  else{
    Keyboard.release('m');
  }
  
  if (digitalRead(8) == LOW){
  //Send an ASCII left arrow
    Keyboard.press(KEY_LEFT_ARROW);
  }
  else{
    Keyboard.release(KEY_LEFT_ARROW);
  }
  
  if (digitalRead(9) == LOW){
    //Send an ASCII down arrow
    Keyboard.press(KEY_DOWN_ARROW);
  }
  else{
    Keyboard.release(KEY_DOWN_ARROW);
  }
  
  if (digitalRead(10) == LOW)
  {
    //Send an ASCII right arrow
    Keyboard.press(KEY_RIGHT_ARROW);
  }
  else{
    Keyboard.release(KEY_RIGHT_ARROW);
  }
  
  if (digitalRead(11) == LOW)
  {
    //Send an ASCII up arrow
    Keyboard.press(KEY_UP_ARROW);
  }
  else{
    Keyboard.release(KEY_UP_ARROW);
  }
}
