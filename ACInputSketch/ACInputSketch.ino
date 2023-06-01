# include <Keyboard.h> 
void setup() {
  // put your setup code here, to run once:

  //starts serial connection
  Serial.begin(9600);

  //configure pins as an input and enables the internal pull-up resistor
  pinMode(0, INPUT_PULLUP); //PL2 A
  pinMode(1, INPUT_PULLUP); //PL2 B
  pinMode(2, INPUT_PULLUP); //PL2 Left
  pinMode(3, INPUT_PULLUP); //PL2 Down
  pinMode(4, INPUT_PULLUP); //PL2 Right
  pinMode(5, INPUT_PULLUP); //PL2 Up

  //start emulating a keyboard
  Keyboard.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(0) == LOW)
  {
    //Send an ASCII 'V'
      Keyboard.write(86);
  }
  if (digitalRead(1) == LOW)
  {
    //Send an ASCII 'C'
    Keyboard.write(67);
  }
  if (digitalRead(2) == LOW)
  {
  //Send an ASCII 'A'
    Keyboard.write(65);
  }
  if (digitalRead(3) == LOW)
  {
    //Send an ASCII 'S'
    Keyboard.write(83);
  }
  if (digitalRead(4) == LOW)
  {
    //Send an ASCII 'D'
    Keyboard.write(68);
  }
  if (digitalRead(5) == LOW)
  {
    //Send an ASCII 'W'
    Keyboard.write(87);
  }
  else 
  {
    Keyboard.releaseAll();
  }
    
  
}
