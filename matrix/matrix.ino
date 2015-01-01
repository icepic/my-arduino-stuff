/*
 * $OpenBSD: template.ino,v 1.1 2012/04/24 06:37:32 jasper Exp $
 *
 * Arduino projects run something like this:
 *	main() {
 *		init(); // arduino private setup
 *		setup(); // your setup goes here
 *		while(1) {
 *			loop(); // your main loop
 *		}
 *	}
 *
 * Arduino reference is at /usr/local/share/doc/arduino/reference/
 */

#ifdef __cplusplus
extern "C" {
#endif

#include "TimerOne.h"

byte rows[8] = {1, 2, 3, 4, 12, 11, 10, 9};
  byte cols[8] = {5, 6, 7, 8, 16, 15, 14, 13};
byte pins[16] = {5, 4, 3, 2, 14, 15, 16, 17, 13, 12, 11, 10, 9, 8, 7, 6};
byte screen[8] = {0, 0, 0, 0, 0, 0, 0, 0};
volatile byte screenRow = 0;
volatile byte screenCol = 0;

byte translatePin(byte original) {
  return pins[original - 1];
}


// interrupt routine
void doubleBuffer() {
  // reset the previous iteration
  digitalWrite(translatePin(rows[screenRow]), HIGH); // set previous off
  digitalWrite(translatePin(cols[screenCol]), LOW);  // set previous off
  // go to the next iteration...
  // go to the next screenCol, wrap if necessary
  screenCol++;
  if (screenCol >= 8) {
    screenCol = 0;
    // when screenCol wraps, go to the next screenRow, wrap if necessary
    screenRow++;
    if (screenRow >= 8) {
      screenRow = 0;
    }
  }
  // set this iteration
  if((screen[screenRow]>>screenCol)&B1 == B1) {
    digitalWrite(translatePin(rows[screenRow]), LOW);  // set this on
    digitalWrite(translatePin(cols[screenCol]), HIGH); // set this on
  } else {
    digitalWrite(translatePin(rows[screenRow]), HIGH); // set this off
    digitalWrite(translatePin(cols[screenCol]), LOW);  // set this off
  }
}

void allOFF() {
  for (int i = 0; i < 8; i++)
    screen[i]=0;
}

void on(byte row, byte column) {
    screen[column-1] |= (B1<<(row-1));
}

void off(byte row, byte column) {
    screen[column-1] &= ~(B1<<(row-1));
}

// looping some LEDs routine
void loop() {

  int x=1,y=1;
  int i=0,j=0;

  allOFF();
  for (i=1; i<9; i++) {
    on(i,y);
    delay(100);
    off(i,y);
  }
  allOFF();
  for (i=1; i<9; i++) {
    on(x,i);
    delay(100);
    off(x,i);
  }
  allOFF();
  for (i=1; i<9; i++) {
    for (j=1; j<9; j++) {
      on(i,j);
      //      delay(10);
    }
  }
  delay(1000);
}

void setup() {
  Timer1.initialize(100);
  for (int i = 2; i <= 17; i++)
    pinMode(i, OUTPUT);
  Timer1.attachInterrupt(doubleBuffer);
}

#ifdef __cplusplus
}
#endif
extern "C" void __cxa_pure_virtual(void) {
  while(1);
} 
