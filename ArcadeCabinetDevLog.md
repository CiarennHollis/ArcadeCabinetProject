# Arcade Cabinet Input Software Devlog
#### Ciarenn Hollis  
  
## 14 June 2023 | 11:24
### Update
 * The new version of the script was tested on the machine.
 * Errors in the orientation were fixed. So now the machine's controls can be successfully oriented to either play with a portrait screen or a landscade screen.
 * Currently, from a functionality standpoint, this arcade machine is at minimum viable product status.
## 13 June 2023 | 14:57
### Update
 * Will and I tested playing the game KosmoSquad on the arcade cabinet machine itself with both controllers hooked up. It played relatively fine but playing a game in the landscape orientation with the controllers being in a different vertical orientation made play difficult.
 * There are two buttons on one of the controllers that didn't yet have a purpose. So, I decided to make these buttons be switches for changing the orientation of the controllers. If someone makes a game to fit a vertical orientation, the controllers can be flipped to match that; if someone wants to make a game to fit a vertical orientation, the controllers can be flipped to match that.
 * I basically just used arrays to store the keys and had the keystrokes that get returned be stored in variables rather than being hard coded like before. I separated out the code for switching the controls into it's own methods that shouldn't interfere with the original control logic written. 
 * This isn't the cleanest way to go about this, I don't think, but it was relatively the easiest that made the most sense to me without having to make it too complicated.
### Next Steps
 * Upload this version of the script to the arduino and test to see if it works. (The arduino isn't currently hooked up to this cpu I'm working on and is instead still in the cabinet.)
  
## 13 June 2023 | 9:30
### Note About Last Two Buttons
 * There are two buttons left on one of the controllers. We haven't decided how were are going to use them yet or what keyboard keys they are going to be mapped to.
 * Even if their purpose hasn't been decided yet, I can note down what pins they are going to be plugged into

## 8 June 2023 | 
### Notes
#### Updated Pin 'map'
  
* 0 = PL2 A        [v]
 * 1 = PL2 B       [c]
 * 4 = PL2 Left    [a]
 * 3 = PL2 Down  [s]
 * 2 = PL2 Right  [d]
 * 5 = PL2 Up     [w]
  
 * 6 = PL1 A        [n]
 * 7 = PL1 B        [m]
 * 8 = PL1 Left     [KEY_LEFT_ARROW]
 * 9 = PL1 Down  [KEY_DOWN_ARROW]
 * 10 = PL1 Right [KEY_RIGHT_ARROW]
 * 11 = PL1 Up     [KEY_UP_ARROW]
 
### Update
 * The second controller is programmed and hooked up. The controller works.
 * The main bits of the arcade cabinet are done.
  
## 8 June 2023 | 11:44
### Update 
 * I found a tutorial on setting up an arcade controller by the youtube channel BrainyBits. From there I found the companion artical the creator made which showcased his code for that controller. 
 * In the SetUp() function, I have the line of code: "Keyboard.begin();" I had learned previously from other articles that this command starts the simulation of a keyboard. In looking at BrainyBits's code, I saw that he was using the function Keyboard.press('') rather than Keyboard.write like I was. Keyboard.write() simulates a keyboard press and subsequent release while release only simulates a keyboard press ands to have Keyboard.release() called at somepoint after it for that key to be released. 
 * So, I implemented the usage of Keyboard.press() and Keyboard.release(), replace the Keyboard.write commands with them. This achieved the behavior we were looking for. To further test, I tried this out with the KosmoSquad game. The controller worked well enough with the game; the controller moved the player avavtar around as we intended it to.
### Next Steps
 * Writing code for the second controller to be functional. I was waiting on do the second controller until I got this first controller working since the code for the second controller will essentially be a duplicate of the first controller's but just tailored for the different pins and keystrokes.
  
## 8 June 2023 | 10:57
### Update 
 * So, after removing the delay (setting it to zero), both games could read input from the controller. However, this input is a kin to making a keystroke several times per second rather than a keystroke being held so the in-game player avatar wasn't performing the way it normally would when reacting to regular keyboard input. 
 * I am going to have to have a system that reads and checks input off the controller in a similar way that the input off a keyboard is read and checked. 
### Next steps
 * Research how a cpu reads input off the of a keyboard.
 * Figure out how to implement a similar system for the game controller.
  
## 8 June 2023 | 10:43
### Update
 * So, the controller can "type" it's ascii input equivalents into a text editor. But I wanted to see how it performs with an actual game. One of the developers from FlatRedBall the David A. knows gave me some games to try out. 
 * I tried out one of the games that that developer gave me (KosmoSquad) but the controller didn't seem to work with it. So instead I tried it out with the game Hyperlight Drifter to see if it might have just been that game or if it was the controller. In Hyperlight Drifter, the controller still didn't work but the game was reading input from it. The player avater did move and react slightly to it. I'm thinking maybe the delay on the controller may be too high for playing an actuall game with it so I'm going try a lower delay time to see if it changes anything.
## 6 June 2023 | 14:50
### Update
 * I was lookind around at things that could be used to fix the problem with the "extra" input keystrokes.  I found a video Paul McWhorter where he was setting up a push button and referenced the code he used for the delay on his button. 
 * Using that delay code fixed the "issue". With one button press on the game controller, there is only one key stroke. More keystrokes are still made if the button is held though, which is what we wanted.
 * Will had a question about whether we can get the buttons of the controller to not be read continuously but be read more similarly to how a keyboard's keypresses are read. I wonder if messing around with the delay would do that or if I would have to implement a system for detecting if the key was released. We might have to implement state for that. Will wants to test how the cpu reads keystrokes from the keyboard vs strokes from the controller.
### Next Steps
 * Mess around with the controller and see how close we can get it to mirroring keyboard inputs.

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
 