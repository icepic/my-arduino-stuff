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

#define waittime 50

#ifdef __cplusplus
extern "C" {
#endif

#include <SPI.h>

void setup(void) {
  /* your code here */
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV64); // 16MHz/64 == 250kHz
  pinMode(8,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(13,OUTPUT);

  digitalWrite(8,HIGH);
  return;
}

void loop(void) {
  /* more of your code here */
  delay(waittime);
  SPI.transfer(0x30);
  SPI.transfer(0x31);
  SPI.transfer(0x32);
  SPI.transfer(0x33);
  delay(waittime);
  SPI.transfer(0x39);
  SPI.transfer(0x38);
  SPI.transfer(0x37);
  SPI.transfer(0x36);
  return ;
}

#ifdef __cplusplus
}
#endif
