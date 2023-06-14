# include <Keyboard.h> 

char PL2Keys[6] = {'v', 'c', 'a', 's', 'd', 'w'}; 
char PL1Keys[6] = {'n', 'm', KEY_LEFT_ARROW, 
  KEY_DOWN_ARROW, KEY_RIGHT_ARROW, KEY_UP_ARROW};

char PL2A;
char PL2B;
char PL2Left;
char PL2Down;
char PL2Right;
char PL2Up;

char PL1A;
char PL1B;
char PL1Left;
char PL1Down;
char PL1Right;
char PL1Up;

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

  pinMode(12, INPUT_PULLUP); // Switch btn Landscape
  pinMode(13, INPUT_PULLUP); // Switch btn Portrait

  SetupKeys();


}

void loop() {
  // put your main code here, to run repeatedly:
  ListenForButtonOrientationChange();
  ListenForPL2();
  ListenForPL1();
   
}

void SetupKeys(){
  PL2A = PL2Keys[0];
  PL2B = PL2Keys[1];
  
  PL1A = PL1Keys[0];
  PL1B = PL1Keys[1];

  SetPortrait();
}

void SetPortrait() {
  PL2Left = PL2Keys[4];
  PL2Down = PL2Keys[3];
  PL2Right = PL2Keys[2];
  PL2Up = PL2Keys[5];

  PL1Left = PL1Keys[2];
  PL1Down = PL1Keys[3];
  PL1Right = PL1Keys[4];
  PL1Up = PL1Keys[5];
}
void SetLandscape(){
  PL2Left = PL2Keys[3];
  PL2Down = PL2Keys[2];
  PL2Right = PL2Keys[5];
  PL2Up = PL2Keys[4];

  PL1Left = PL1Keys[3];
  PL1Down = PL1Keys[4];
  PL1Right = PL1Keys[5];
  PL1Up = PL1Keys[2];
}

void ListenForButtonOrientationChange()
{
  if (digitalRead(12) == LOW){
    SetLandscape();
    Keyboard.press('1');
  }
  else{
    Keyboard.release('1');
  }

  if (digitalRead(13) == LOW){
    SetPortrait();
    Keyboard.press('2');
  }
  else{
    Keyboard.release('2');
  }
}

void ListenForPL2()
{
  if (digitalRead(0) == LOW){
    //Send an ASCII 'V'
      Keyboard.press(PL2A);
  }
  else {
    Keyboard.release(PL2A);
  }
  
  if (digitalRead(1) == LOW){
    //Send an ASCII 'C'
    Keyboard.press(PL2B);
  }
  else{
    Keyboard.release(PL2B);
  }
  
  if (digitalRead(4) == LOW){
  //Send an ASCII 'A'
    Keyboard.press(PL2Left);
  }
  else{
    Keyboard.release(PL2Left);
  }
  
  if (digitalRead(3) == LOW){
    //Send an ASCII 'S'
    Keyboard.press(PL2Down);
  }
  else{
    Keyboard.release(PL2Down);
  }
  
  if (digitalRead(2) == LOW)
  {
    //Send an ASCII 'D'
    Keyboard.press(PL2Right);
  }
  else{
    Keyboard.release(PL2Right);
  }
  
  if (digitalRead(5) == LOW)
  {
    //Send an ASCII 'W'
    Keyboard.press(PL2Up);
  }
  else{
    Keyboard.release(PL2Up);
  }
}

void ListenForPL1()
{
  if (digitalRead(6) == LOW){
    //Send an ASCII 'N'
      Keyboard.press(PL1A);
  }
  else {
    Keyboard.release(PL1A);
  }
  
  if (digitalRead(7) == LOW){
    //Send an ASCII 'M'
    Keyboard.press(PL1B);
  }
  else{
    Keyboard.release(PL1B);
  }
  
  if (digitalRead(8) == LOW){
  //Send an ASCII left arrow
    Keyboard.press(PL1Left);
  }
  else{
    Keyboard.release(PL1Left);
  }
  
  if (digitalRead(9) == LOW){
    //Send an ASCII down arrow
    Keyboard.press(PL1Down);
  }
  else{
    Keyboard.release(PL1Down);
  }
  
  if (digitalRead(10) == LOW)
  {
    //Send an ASCII right arrow
    Keyboard.press(PL1Right);
  }
  else{
    Keyboard.release(PL1Right);
  }
  
  if (digitalRead(11) == LOW)
  {
    //Send an ASCII up arrow
    Keyboard.press(PL1Up);
  }
  else{
    Keyboard.release(PL1Up);
  }
}
