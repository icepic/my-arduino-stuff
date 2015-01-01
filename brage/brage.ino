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

void setup(void) {
	/* your code here */
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  return;
}

void loop(void) {
	/* more of your code here */
  delay(100);
  digitalWrite(13, HIGH);
  delay(100);
  digitalWrite(13,LOW);
  Serial.println("one loop");
  return ;
}

#ifdef __cplusplus
}
#endif
