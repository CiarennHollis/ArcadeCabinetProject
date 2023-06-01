# Arcade Cabinet Input Software Devlog
#### Ciarenn Hollis  
  
## 1 June 2023 | 14:46
### Update
 * I wasn't able to fix the issue with the controller reading "extra" inputs. I tried using if statements and else if statements but it didn't exactly work. I did notice that the longer the button is held for dictates how much "extra" inputs get read in. A light tap won't have as many keystrokes as a harder press.
 * Uploaded it to github to have sharing and version control.

### Next Steps
 * Find a solution for the "extra" input that the controller reads in.
  
   
 ## 1 June 2023 | 12:21
 ### Update
 * I've accomplished the goals set in the previous entry.
 * There is an issue with the arduino reading several inputs for a single button press (or really what it is is that the loop checking for the voltage on the buttons checks several times before the voltage can revert back to normal). I need to have some logic to prevent that from causing there to be "extra" inputs read
 ### Next Steps
  * Fix "multiple" input issue
  
  
## 1 June 2023 | 9:30
### Check In
This project is programming the software that would allow the arcade cabinet to read input from the it's gamepads (which each have one joy stick and an A and B btn). This project is going to be written in C++ for an Arduino Leonardo. Currently, there is one gamepad set up with the arduino for testing, the second will be added later on. I've found some examples of people creating their own custom game controllers using the arduino where the input the arduino reads from the controller is translated into a keyboard input for the computer it's hooked up to to use. I want to do something similar with this, this would make it easier for students to program their own games for it.

### Goals
 * Have the arduino read input from the buttons and have the keyboard key equivalent be returned.
 * Have the arduino read input from the joystick and have the keyboard key equivalents be returned.

### Notes
#### Pin to Btn Notes
 * 0 = PL2 A
 * 1 = PL2 B
 * 2 = PL2 Left
 * 3 = PL2 Down
 * 4 = PL2 Right
 * 5 = PL2 Up
   
#### Digital Pins
 * 

#### Serial functions
  * begin() - sets the data rate in bits per second (baud) for serial data transmission. Do these gamepads have a specific baud rate they need? Have to ask Will. Answer: the gamepad doesn't operate on serial but the arduino does, I just might have to try different rates. There is one used in an example I found that I will start with.
  * println() - prints data to the serial port as human-readable ASCII test followed by a carriage return character

#### Keyboard functions
 * begin() - starts emulating a keyboard connected to a computer. End control with Keyboard.end().
 * write() - sends a keystroke to a connected computer via its ASCII value
 
#### ASCII Values used
 * A - 65
 * S - 83
 * W - 87
 * D - 68
 * C - 67
 * V - 86
 * Left Arrow - 
 * Down Arrow - 
 * Right Arrow - 
 * Up Arrow - 
 * N - 78
 * M - 77
 