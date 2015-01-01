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
void __cxa_pure_virtual(void);
void __cxa_pure_virtual(void) {};
#endif

void setup(void) {
	/* your code here */
  Serial.begin(115200);
  return;
}

void loop(void) {
	/* more of your code here */
  unsigned int time1, time2;

  time1=micros();
  time2=micros();
  Serial.print("\n\rMicros: ");
  Serial.println(time2-time1);
  time1=micros();
  time2=micros();
  Serial.print("\n\rMicros: ");
  Serial.println(time2-time1);
  time1=micros();
  time2=micros();
  Serial.print("\n\rMicros: ");
  Serial.println(time2-time1);
  time1=micros();
  time2=micros();
  Serial.print("\n\rMicros: ");
  Serial.println(time2-time1);


	return ;
}

#ifdef __cplusplus
}
#endif
