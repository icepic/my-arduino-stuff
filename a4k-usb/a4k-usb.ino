/*
 * Copyright (c) 2013 Janne Johansson <jj@stacken.kth.se>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifdef __cplusplus
extern "C" {
void __cxa_pure_virtual(void);
void __cxa_pure_virtual(void) {};
#endif

#define DEBUG 1
  
#define KDAT 9
#define KCLK 10
 /* Connect +5V and GND and then CLOCK pin to arduino 9
     and the DATA pin to 10. Or change the defines above
     5V is yellowgreen, GND is black, DATA lightgrey, CLK white

 */

#define LED_PIN 13

int sendsync(void);
unsigned char grabkey(void);

char insync=0;
unsigned long lasttime=0;
unsigned long delaytime=0;
unsigned long timearray[8];

void setup(void) {
  /* your code here */

  unsigned int loops;
  unsigned long time1=0,time2=0, time3=0,time4=0;

  pinMode(KCLK,INPUT_PULLUP);
  pinMode(KDAT,INPUT_PULLUP);
  pinMode(LED_PIN,OUTPUT);

  digitalWrite(LED_PIN,LOW);

  Serial.begin(115200);
  Serial.println("Starting.");
  Serial.print("Initial reading CLK: ");
  Serial.println(digitalRead(KCLK),BIN);
  Serial.print("Initial reading DATA: ");
  Serial.println(digitalRead(KDAT),BIN);

  // wait for a complete clock pulse.
  do {} while (HIGH==digitalRead(KCLK));
  do {time1++;} while (LOW==digitalRead(KCLK));
  do {time2++;} while (HIGH==digitalRead(KCLK));
  do {time3++;} while (LOW==digitalRead(KCLK));
  do {time4++;} while (HIGH==digitalRead(KCLK));
  do {} while (LOW==digitalRead(KCLK));
  // dont count last time, move on...

  /* try one sync pulse for kicks */
  /* ACK with a 75 ms pulse */
  loops=sendsync();
  insync=1;
  digitalWrite(LED_PIN,HIGH);
  Serial.print("loops: ");
  Serial.println(loops,DEC);
  Serial.print("time LOW: ");
  Serial.println(time1,DEC);
  Serial.print("time HIGH: ");
  Serial.println(time2,DEC);
  Serial.print("time LOW: ");
  Serial.println(time3,DEC);
  Serial.print("time HIGH: ");
  Serial.println(time4,DEC);
  
  return;
}

int sendsync(void) {
  /* ACK the received data with a 75 ms pulse */
  int loopnum=0;
  unsigned long time1,time2;
  time1=micros();
  pinMode(KDAT, OUTPUT);
  digitalWrite(KDAT, LOW);
  do {loopnum++; } 
  while (micros() < time1+75);
  //  delayMicroseconds(95); /* 75? 95? */

  digitalWrite(KDAT, HIGH);
  pinMode(KDAT,INPUT_PULLUP);
  return loopnum;
}

unsigned char grabkey(void) {

  unsigned char readchar=0;
  int clk;
  unsigned long time1,time2,time3,time4;

  time1=micros();
  for (int i=0;i<8;i++) {
    do { } while (HIGH==digitalRead(KCLK));
    time3=micros();
    /* clock switched, reading on bit of data */
    if (digitalRead(KDAT)==LOW) readchar |= (1 << (7-i));
    /* wait for clock to go up again */
    do { } while (LOW==digitalRead(KCLK));
    time4=micros();
#ifdef DEBUG
    timearray[i]=time4-time3;
#endif
  } /* loop 8 times */  
  time2=micros();

  sendsync();

  lasttime=(time2-time1);
  return readchar;
}

void loop(void) {

  /* Lets get into sync */
  unsigned char rawchar;

#ifdef DEBUG
  Serial.print(timearray[0]);
  Serial.print(" ");
  Serial.print(timearray[1]);
  Serial.print(" ");
  Serial.print(timearray[2]);
  Serial.print(" ");
  Serial.print(timearray[3]);
  Serial.print(" ");
  Serial.print(timearray[4]);
  Serial.print(" ");
  Serial.print(timearray[5]);
  Serial.print(" ");
  Serial.print(timearray[6]);
  Serial.print(" ");
  Serial.println(timearray[7]);
#endif

  if (insync) {
    digitalWrite(LED_PIN,HIGH);
    rawchar=grabkey();
    if (255 == rawchar) {
      /* seems to have lost sync */
      insync=0;
      Serial.println("lost sync");
      digitalWrite(LED_PIN,LOW);
      return;
    }

    Serial.print("we have a byte: ");
    Serial.println(rawchar,BIN);
    Serial.print("Micros to get a key: ");
    Serial.println(lasttime);
    digitalWrite(LED_PIN,HIGH);
  } else {
    digitalWrite(LED_PIN,LOW);
    sendsync();
    insync=1; /* hopefully this took us back in synch again */
  }
  /* more of your code here */
  return ;
}

#ifdef __cplusplus
}
#endif
