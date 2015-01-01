B/*
 0;301;0c* $OpenBSD: template.ino,v 1.1 2012/04/24 06:37:32 jasper Exp $
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

#define IRPIN 8
#define LED 13
#define OUTPUTPIN 12

#define ONTIME 120000UL

unsigned long now=0UL;
unsigned long delaytime=0UL;

void setup(void) {
  /* your code here */
  pinMode(IRPIN, INPUT);
  pinMode(OUTPUTPIN, OUTPUT);
  pinMode(LED,OUTPUT);

  Serial.begin(115200);
  Serial.println(F("Starting"));

  now=millis();

  return;
}

void loop(void) {
  /* more of your code here */

  if (digitalRead(8)==HIGH) {
    //    Serial.println(F("ALARM"));
    digitalWrite(LED, HIGH);
    digitalWrite(OUTPUTPIN, HIGH);
    now=millis();
    delaytime=now+ONTIME;
  } else {
    digitalWrite(LED, LOW); // mark the status
    if (delaytime < millis()) {
      digitalWrite(OUTPUTPIN, LOW);
    }
  }
  return;
}
