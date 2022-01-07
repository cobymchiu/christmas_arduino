# Arduino Christmas Tree Display

## Introduction
With the holidays coming up, we were inspired to create a project that reflects the festive season. We took inspiration from Christmas light displays and decided to create a rotating, light-up Christmas tree that played music. Exploring the public Arduino projectbase, we found an [an existing project](https://create.arduino.cc/projecthub/joshi/piezo-christmas-songs-fd1ae9) by Joshi with code that allowed us to play Christmas music through the Piezo buzzer1. We built off of this code to implement our intended functionality and mesh it with the electronic components we wanted to incorporate such as the DIP switch, momentary pushbuttons, and servo motor. 

Our goals for this display were to have the tree rotate back and forth from 0-180 degrees and have LEDs embedded into it that flash with each note the buzzer played. We also wanted the whole circuit to be able to be shut off with a switch and for the user to be able to push a button to select a song to play. Additionally, we wanted a means of controlling the volume of the music.

## Materials Used
* Arduino Uno R3
* DIP Switch SPST x 4
* 1 kΩ Potentiometer
* Piezo
* Pushbutton
* Micro Servo
* Red LED
* Green LED
* Yellow LED

## Description
Our Christmas tree was crafted out of paper and other recycled materials. We stuck our LEDs into the paper shell of the tree and used M-F jumper wires to link each one to our breadboard. The tree was taped to the rotating part of the servo motor and positioned in a way such that the impact of the wires on the tree’s rotation would be minimized. We set the servo-tree combination in a recycled tissue box as a base and created the rest of our circuit on the breadboard.

The Arduino and tree rested on top of the breadboard, and we made all connections using this configuration. In summary, we hooked most components to different pins of the Arduino then to the GND pin so that we could control each separately in the code. The Arduino checked for a high/low voltage on pin 13 to determine whether or not the circuit should be on. The motor’s power supply was linked in series with the switch so that its rotation would be shut off by flipping the trigger, and its signal input was linked to pin 5. Our LEDs were all connected in parallel with each other stemming from pin 9 and GND. The Piezo buzzer was wired from pin 12 to GND with a 100 kOhm potentiometer linked in series. Our pushbuttons were connected to pins 2 and 3. Because they were momentary pushbuttons, we decided to set those pins as pullup inputs to work around the fact that they did not maintain their value after being pressed.

## Improvements
The major problem we encountered was the wiring of LEDs. We were unable to foresee that the wiring could be a problem, so we simply used the breadboard rather than using a smaller circuit board which made each LED lightbulb require two long wires, so there were eighteen wires in total. The limited space inside the tree trunk makes it difficult to assemble the whole LED circuits after the servo rotor was attached to the tree. Furthermore, wires also applied large torque to the rotating motion, making the rotation tilted. We had to carefully adjust the range of the angle to ensure the tree won’t collapse during the rotation. In the mechanical aspect, our design was apparently limited.
Given more time, we would have also integrated an LCD display that printed messages such as the title of the song playing and other holiday-themed sayings. We would also look into soldering our project onto a more compact display board and found a different way to wire the LEDs such that they would not impact the tree’s rotation. 


### References
https://create.arduino.cc/projecthub/joshi/piezo-christmas-songs-fd1ae9 <br>
https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody <br>
https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/brightness-control <br>
https://learn.adafruit.com/adafruit-arduino-lesson-10-making-sounds/playing-a-scale <br>
