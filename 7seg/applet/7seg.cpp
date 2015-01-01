#include "Arduino.h"
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

#include <inttypes.h>

void setlevel(uint8_t level) {
  Serial.write(0x7a);
  Serial.write(level);
  return;
}

void setnumber(uint8_t led, uint8_t gfx) {
  if (led > 3) return;
  Serial.write((0x7B + led));
  Serial.write(gfx);
  return;
}

void setup(void) {
  /* your code here */
  Serial.begin(9600);
  Serial.write(0x76);

  Serial.write(0);
  Serial.write(1);
  Serial.write(2);
  Serial.write(3);
  return;
}

void loop(void) {
  /* more of your code here */
  delay(500);
  Serial.write("0123");
  delay(500);
  Serial.write("2345");
  return ;
}

#ifdef __cplusplus
}
#endif
#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}

