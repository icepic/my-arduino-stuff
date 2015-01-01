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

int del=75;

void setup(void) {
	/* your code here */
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	pinMode(5,OUTPUT);
	pinMode(6,OUTPUT);

	return;
}

void loop(void) {
	/* more of your code here */
	digitalWrite(2, HIGH);   // turn on LED on pin 2
	delay(del);              // wait (length determined by value of 'del')
	digitalWrite(2, LOW);    // turn it off

	digitalWrite(3, HIGH);   // turn on LED on pin 3
	delay(del);              // wait
	digitalWrite(3, LOW);    // turn it off

	digitalWrite(4, HIGH);   // turn on LED on pin 4
	delay(del);              // wait
	digitalWrite(4, LOW);    // turn it off

	digitalWrite(5, HIGH);   // turn on LED on pin 5
	delay(del);              // wait
	digitalWrite(5, LOW);    // turn it off

	digitalWrite(6, HIGH);   // turn on LED on pin 6
	delay(del);              // wait
	digitalWrite(6, LOW);    // turn it off

	digitalWrite(5, HIGH);   // turn on LED on pin 5
	delay(del);              // wait
	digitalWrite(5, LOW);    // turn it off

	digitalWrite(4, HIGH);   // turn on LED on pin 4
	delay(del);              // wait
	digitalWrite(4, LOW);    // turn it off

	digitalWrite(3, HIGH);   // turn on LED on pin 3
	delay(del);              // wait
	digitalWrite(3, LOW);    // turn it off

	return ;
}

#ifdef __cplusplus
}
#endif
