#include <Tone.h>

#define button1 6
#define button2 5
#define button3 4
#define piezo1 3
#define piezo2 2

Tone chanter, drone;
bool soundPlaying;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(piezo1, OUTPUT);
  pinMode(piezo2, OUTPUT);
  
  chanter.begin(piezo1);
  drone.begin(piezo2);
}

void loop() { 
  if(soundPlaying == false) {
    if(digitalRead(button1) == HIGH || digitalRead(button2) == HIGH || digitalRead(button3) == HIGH) {
      soundPlaying = true;  
    }
  } else if(soundPlaying == true) {
    drone.play(NOTE_G3);
    
    if(digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == LOW) {
      chanter.play(NOTE_G5);
    } else if(digitalRead(button1) == HIGH && digitalRead(button2) == LOW && digitalRead(button3) == LOW) {
      chanter.play(NOTE_A5);
    } else if(digitalRead(button1) == LOW && digitalRead(button2) == HIGH && digitalRead(button3) == LOW) {
      chanter.play(NOTE_B5);
    } else if(digitalRead(button1) == LOW && digitalRead(button2) == LOW && digitalRead(button3) == HIGH) {
      chanter.play(NOTE_C6);
    } else if(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && digitalRead(button3) == LOW) {
      chanter.play(NOTE_D6);
    } else if(digitalRead(button1) == HIGH && digitalRead(button2) == LOW && digitalRead(button3) == HIGH) {
      chanter.play(NOTE_E6);
    } else if(digitalRead(button1) == LOW && digitalRead(button2) == HIGH && digitalRead(button3) == HIGH) {
      chanter.play(NOTE_FS6);
    } else if(digitalRead(button1) == HIGH && digitalRead(button2) == HIGH && digitalRead(button3) == HIGH) {
      chanter.play(NOTE_G6);
    }
  }
}
