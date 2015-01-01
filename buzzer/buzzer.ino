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

void setup(void) {
	/* your code here */
  pinMode(10,OUTPUT);
  return;
}

void loop(void) {
	/* more of your code here */
  for (int i=0;i<255;i++) {
    analogWrite(10,i);
    delay(10);
  }
  return ;
}

#ifdef __cplusplus
}
#endif
