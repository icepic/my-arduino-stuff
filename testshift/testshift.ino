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
volatile int i=10;
int a=0,b=0;

#ifdef __cplusplus
extern "C" {
void __cxa_pure_virtual(void); void __cxa_pure_virtual(void) {};
#endif

void setup(void) {
	/* your code here */
  Serial.begin(115200);
	return;
}

void loop(void) {
  /* more of your code here */
  Serial.println(i);
  a=i/2;
  Serial.println(a);
  b=i>>1;
  Serial.println(b);
  return ;
}

#ifdef __cplusplus
}
#endif
