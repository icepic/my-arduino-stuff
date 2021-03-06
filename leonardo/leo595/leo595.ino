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

#define MYDELAY 500

void clockout(uint8_t);
void update_values();

uint8_t leds[8];
unsigned long mil;

/* pin11 goes to 595 pin 11 */
#define SHIFTCLOCK 11
/* pin 8 goes to 595 pin 14 */
#define SERDATAIN  8
/* to control when data goes out */
#define STROBEPIN 12

void setup(void) {

  pinMode(SERDATAIN, OUTPUT);
  pinMode(SHIFTCLOCK, OUTPUT);
  pinMode(STROBEPIN, OUTPUT);
  pinMode(13, OUTPUT);
  
  for(uint8_t i=0;i<8;i++) {
     leds[i] = i;
  }
  clockout(0);
  return;
}


void loop(void) {
  uint8_t current_byte, old=0;
  // loop 256 times with wrap
  for (uint8_t outer=2;outer!=0;outer +=2) {
    current_byte=0;
    for (uint8_t inner=0;inner < 8;inner++) {
      if (leds[inner] >= outer) {
        current_byte |= _BV(inner);
      } /* if leds are to show */   
    }   /* inner 8 values to compare */
//    if (current_byte != old) {
      clockout(current_byte);
      old = current_byte;
//    }
  }     /* outer loop for 256 values */
  mil=millis();
  update_values();
}

void update_led1() {
  // leds[0]
}
void update_led2() {
  // leds[1]
}
void update_led3() {
  // leds[2]
}
void update_led4() {
  leds[3]++;
}
void update_led5() {
  // leds[4];
}
void update_led6() {
}
void update_led7() {
   if ((mil % 20) == 0) leds[6]--;    
}
void update_led8() {
   if ((mil % 20) == 0) leds[7]++;
}

void
update_values() {
  update_led1();
  update_led2();
  update_led3();
  update_led4();
  update_led5();
  update_led6();
  update_led7();
  update_led8();
}

void unused(void) {
  uint8_t value = 0, overall = 0;
  unsigned long now;

  for (value = 0; value < 255; value++) {
    uint8_t temp = value >> 4; /* need only 4 major bits */
    now = micros();
    do {
      for (overall = 0; overall < 16; overall++) {
        if (temp > overall) {
          clockout(255);
          digitalWrite(13, HIGH);
        } else {
          clockout(0);
          digitalWrite(13, LOW);
        }
      }
    } while (micros() < (now + MYDELAY));
    //    delay(20); /* make the 0-255 stepping visible */
    clockout(0);
    digitalWrite(13, HIGH);
  }

  for (value = 255; value > 0; value--) {
    uint8_t temp = value >> 4; /* need only 4 major bits */
    now = micros();
    do {
      for (overall = 0; overall < 16; overall++) {
        if (temp > overall) {
          clockout(255);
          digitalWrite(13, HIGH);
        } else {
          clockout(0);
          digitalWrite(13, LOW);
        }
      }
    } while (micros() < (now + MYDELAY));
    // delay(20); /* make the 0-255 stepping visible */
    clockout(0);
    digitalWrite(13, HIGH);
  }

  return;
}

void clockout(uint8_t data) {
  uint8_t loop, pin = 1;

  digitalWrite(STROBEPIN, HIGH); /* disable output */
  for (loop = 0; loop < 8; loop++) {
    if (data & pin) {
      PORTB |= _BV(PORTB4); /* set bit one */
      // digitalWrite(SERDATAIN, HIGH);
    } else {
      PORTB &= ~_BV(PORTB4);  /* clear bit one */
      // digitalWrite(SERDATAIN, LOW);
    }
    pin = pin << 1;
    PORTB &= ~_BV(PORTB7);
    PORTB |= _BV(PORTB7);
  //  digitalWrite(SHIFTCLOCK, LOW);
  //  digitalWrite(SHIFTCLOCK, HIGH);
  }
  digitalWrite(STROBEPIN, LOW); /* enable output */
  return;
}

#ifdef __cplusplus
}
#endif
