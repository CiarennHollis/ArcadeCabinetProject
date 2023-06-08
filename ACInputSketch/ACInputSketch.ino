# include <Keyboard.h> 
int delayTime = 0;
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
      delay(delayTime);
  }
  if (digitalRead(1) == LOW)
  {
    //Send an ASCII 'C'
    Keyboard.write(67);
    delay(delayTime);
  }
  if (digitalRead(2) == LOW)
  {
  //Send an ASCII 'A'
    Keyboard.write(65);
    delay(delayTime);
  }
  if (digitalRead(3) == LOW)
  {
    //Send an ASCII 'S'
    Keyboard.write(83);
    delay(delayTime);
  }
  if (digitalRead(4) == LOW)
  {
    //Send an ASCII 'D'
    Keyboard.write(68);
    delay(delayTime);
  }
  if (digitalRead(5) == LOW)
  {
    //Send an ASCII 'W'
    Keyboard.write(87);
    delay(delayTime);
  }
  else 
  {
    Keyboard.releaseAll();
  }
    
  
}
