# Arduino-Ringo-1x1-Movement
A controller written for the Arduino's Ringo bot to make it move into 1x1 squares.  

## Instructions

1) To set up your computer foruse with the Ringo robot, Visit : http://www.plumgeek.com/getting-started.html
2) Follow the instructions there before you plug the Ringo in - they will guide you through installing drivers,the Arduino IDE, and Ringo’s software libraries. I
3) After finishing the setup process, scroll up to the navigation bar on the Getting Started page, and navigateto “Robots” > “Ringo” > “Ringo Software.”
4) Visit : https://github.com/feilipu/Arduino_FreeRTOS_LibraryDownload the library and move to your Libraries folder where you installed the Ringo libraries.
5) Import the code from the repository and run it throught Adruino IDE. 
6) The Law control law used to implement the tasks:
    - I used the control law of PID. The reason to choose this control law was that it was easier to understand and implement and didn’t require a model. Also, it was already explained in the assignment.
    - I had to make some changes in the mathematical equation of the PID Control, majorly I didn’t need some calculations, so I didn’t use them
7) I chose it to name Turn Right because that was the primary objective of the task, to make the ringo turn right to essentially complete a square of the requirement 1 ft x 1 ft.
    - I used the Ringo Hardware (Motors) function. I passed different speed values to the left and right motor. The speed of the left motor was more than the right motor to accomplish the turn.
    - I set a delay time to have the ringo make a successful turn, the delay time had to be perfect in order to cut the motors before the ringo turned more than a right angle.
    - As soon as the turn is made 0’s is passed as speed values to the motors to stop them from turning more. 
    - A delay function was used to wait a bit until passing it again to the next task. This task is periodic 
