/* 
 *  PHYS 3150 final project
 *  Christmas tree display and music
 *  Coby Chiu and Zekun Chu
 */
#include <Servo.h>
#include "pitches.h"
#include <LiquidCrystal.h>

int lcd1,
int b1 = 2; int b2 = 3;
int motorPin = 5;
int ledPin = 9;
//int latchPin = 9; int clockPin = 10; int dataPin = 11
int buzzerPin = 12;
int switchPin = 13;
bool isOn = false;

Servo servo;
LiquidCrystal lcd(4, 6, 7, 8, 10, 11,);

int angle = 0;

void setup() {
  /*pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);*/
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  //pinMode(motorPin, OUTPUT);
  servo.attach(motorPin);
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.print("Merry Christmas!");
}

void loop() {
  // check switch condition -- nothing happens if switch isn't on
  if (digitalRead(switchPin == HIGH)){
    mode = true;
  }

  if (isOn) {
    servoRotate();
    // selecting music
    if (digitalRead(b1) == LOW){
      //analogWrite(motorPin, 50);
      lcd.print("Playing: 'We Wish You a Merry Christmas'");
      play(1);
    } else if (digitalRead(b2)) == LOW){
      //analogWrite(motorPin, 50);
      lcd.print("Playing: 'Jingle Bells'");
      play(2);
    }
  } else {
    //analogWrite(motorPin, 0);
    buzz(buzzerPin, 0, 1000);
  }
}

// function to rotate servo motor back and forth 180 degrees
void servoRotate() {
  // scan from 0 to 180 degrees
  for(angle = 0; angle < 180; angle++){                                  
    servo.write(angle);               
    delay(30); //change this to change speed?               
  } 
  // now scan back from 180 to 0 degrees
  for(angle = 180; angle > 0; angle--){                                
    servo.write(angle);           
    delay(30);       
  } 
}


/******************* code to play music *********************/

int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

int jingle_melody[] = {
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};

int jingle_tempo[] = {
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

void play(int song){
  // we wish you a merry christmas
  if (song == 1){
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];

      buzz(buzzerPin, wish_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(buzzerPin, 0, noteDuration);
    }
  } else if (song == 2) {
    // jingle bells
    int size = sizeof(jingle_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      int noteDuration = 1000 / jingle_tempo[thisNote];

      buzz(buzzerPin, jingle_melody[thisNote], noteDuration);

      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(buzzerPin, 0, noteDuration);
    }
  } 
}

void buzz(int targetPin, long frequency, long length) {
  //digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    digitalWrite(ledPin, HIGH); // turns on LEDs
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    digitalWrite(ledPin, LOW); // turns off LEDs
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
  //digitalWrite(13, LOW);

}
