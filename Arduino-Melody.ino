/*
  Based on Tom Igoe's code
  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"


const int buttonPin = 5;     // the number of the pushbutton pin
const int lede = 9;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int tempo = 300;
 const int buzzerPin = 2;


int melody[] = {
     NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,

  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4

 
  
};
int noteDurations[] = {
4, 8,
4, 4, 4,
2, 4, 8,
4, 4, 4, 
2, 4, 8,
4, 4, 4,
4, 4, 4, 8, 
4,4, 4,
4, 2
};
int beatsPerMinute = 100;



void setup() {
  // initialize the LED pin as an output:
 
  pinMode(buttonPin, INPUT);
  pinMode(lede, OUTPUT);
 

}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
 if (buttonState == HIGH) {
   digitalWrite(lede, HIGH);
   delay(1000);
   playSong();
  } else {
   digitalWrite(lede, LOW );
   delay(1000);
  }
}


void playSong() {
  // iterate over the notes of the melody: 
int len = sizeof(melody)/sizeof(melody[0]);
for (int thisNote = 0; thisNote < len; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = static_cast<int>(1000 / noteDurations[thisNote] * 60 / beatsPerMinute);
    tone(buzzerPin, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(buzzerPin);
  }
  // Pause before playing again
  delay(100);
}
