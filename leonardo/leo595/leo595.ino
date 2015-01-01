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

#define MYDELAY 10

void clockout(uint8_t);

  /* pin11 goes to 595 pin 11 */
#define SHIFTCLOCK 11
  /* pin 8 goes to 595 pin 14 */
#define SERDATAIN  8 
  /* to control when data goes out */
#define STROBEPIN 12

void setup(void) {
  pinMode(SERDATAIN,OUTPUT);
  pinMode(SHIFTCLOCK,OUTPUT);
  pinMode(STROBEPIN,OUTPUT);
  pinMode(13,OUTPUT);
  return;
}


void loop(void) {
  uint8_t value=0, overall=0;
  unsigned long now;
  
  for (value=0;value<255;value++) {
    uint8_t temp=value >> 4; /* need only 4 major bits */
    now=millis();
    do {
      for (overall=0;overall < 16;overall++) {
	if (temp > overall) {
	  clockout(255);
	  digitalWrite(13,HIGH);
	} else {
	  clockout(0);
	  digitalWrite(13,LOW);
	}
      }
    } while (millis() < (now+MYDELAY));
    //    delay(20); /* make the 0-255 stepping visible */
    clockout(0);
    digitalWrite(13,HIGH);
  }
  
  for (value=255;value>0;value--) {
    uint8_t temp=value >> 4; /* need only 4 major bits */
    now=millis();
    do {
      for (overall=0;overall < 16;overall++) {
	if (temp > overall) {
	  clockout(255);
	  digitalWrite(13,HIGH);
	} else {
	  clockout(0);
	  digitalWrite(13,LOW);
	}
      }
    } while (millis() < (now+MYDELAY));
    //    delay(20); /* make the 0-255 stepping visible */
    clockout(0);
    digitalWrite(13,HIGH);
  }
  
  return;
}
  /* SAMPLE
  clockout(255);
  digitalWrite(13,HIGH);
  delay(1000);
  */

void clockout(uint8_t data) {
  uint8_t loop,pin=1;

  digitalWrite(STROBEPIN,HIGH); /* disable output */
  for (loop=0;loop<8;loop++) {
    if (data & pin) {
      // PORTB |= PORTB4; /* set bit one */
      digitalWrite(SERDATAIN,HIGH);
    } else {
      // PORTB &= ~PORTB4;  /* clear bit one */
      digitalWrite(SERDATAIN,LOW);
    }
    pin = pin << 1;
    digitalWrite(SHIFTCLOCK,LOW);
    digitalWrite(SHIFTCLOCK,HIGH);
  }
  digitalWrite(STROBEPIN,LOW); /* enable output */
  return;
}

#ifdef __cplusplus
}
#endif
