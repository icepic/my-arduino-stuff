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
  void __cxa_pure_virtual(void); void __cxa_pure_virtual(void) {};
#endif

#define STR  10
#define DATA 9
#define CP   8
#define LED  13

#define DELAY 100

#define DEBUG 0

char table[8] = {1,2,4,8,16,32,64,128};
unsigned long time1, time2, time3, time4, time5, starttime;

void setup(void) {
  /*
  pinMode(STR, OUTPUT);
  pinMode(DATA, OUTPUT);
  pinMode(CP, OUTPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(CP,LOW);
  digitalWrite(STR, LOW);
  */

  DDRB = B00111111;
  PORTB &= ~(2<<(CP-8) || 2<<(STR-8));

  Serial.begin(115200);
  Serial.println("Setup done.\n\r");
  starttime=micros();

  return;
}

void loop(void) {
  /* more of your code here */

  unsigned int loop=0;

  while ((micros()-starttime) < 10000000) {
    for (int i=0;i<256;i++) {
      loop++;
      time1 = micros();
      // digitalWrite(STR,LOW);
      PORTB |= (2<<(STR-8));
      //    digitalWrite(LED, LOW);
      //    digitalWrite(LED, HIGH);
      time2 = micros();
      for (int j=0;j<8;j++) {
	PORTB &= ~(2<<(CP-8));
	//	digitalWrite(CP, LOW);

	if (i & table[j]) {
		PORTB |= (2<<(DATA-8));
	} else {
		PORTB &= ~(2<<(DATA-8));
	}
	//	digitalWrite(DATA, (i & table[j]));

	PORTB |= (2<<(CP-8));
	//	digitalWrite(CP, HIGH);
      }
      time3 = micros();
      PORTB &= ~(2<<(STR-8));
	//	digitalWrite(STR, HIGH);
    }
    time4 = micros();
  }

  Serial.println("init time: "); Serial.print(time2-time1);
  Serial.write('\n');Serial.write('\r');
  Serial.println("inner loop time: "); Serial.print(time3-time2);
  Serial.write('\n');Serial.write('\r');
  Serial.println("outer loop time: "); Serial.print(time4-time1);
  Serial.write('\n');Serial.write('\r');
  Serial.println("Loops per sec: "); Serial.print(8*loop);
  Serial.write('\n');Serial.write('\r');
  while (1) {
    time1++;
  }
}


#ifdef __cplusplus
}
#endif
