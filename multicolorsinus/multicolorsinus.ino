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

#define DELAY 60

int i = 0;
int j = 0;
int brightness = 0;
unsigned int sincounter = 0;

int leds[]={13,12,11,10,9,8,7};

const char sinustabell[]={255,254,254,254,254,254,253,253,252,251,251,250,249,248,247,246,245,243,242,241,239,238,236,234,233,231,229,227,225,223,221,219,217,214,212,210,207,205,202,200,197,195,192,189,186,184,181,178,175,172,169,166,163,160,157,154,151,148,145,141,138,135,132,129,126,123,119,116,113,110,107,104,101,98,95,91,88,85,82,80,77,74,71,68,65,63,60,57,54,52,49,47,44,42,40,37,35,33,31,29,27,25,23,21,19,18,16,14,13,12,10,9,8,7,6,5,4,3,2,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,2,3,4,5,6,7,8,9,10,12,13,14,16,18,19,21,23,25,27,29,31,33,35,37,40,42,44,47,49,52,54,57,60,62,65,68,71,74,77,80,82,85,88,91,95,98,101,104,107,110,113,116,119,123,126,129,132,135,138,141,145,148,151,154,157,160,163,166,169,172,175,178,181,184,186,189,192,195,197,200,202,205,207,210,212,214,217,219,221,223,225,227,229,231,233,234,236,238,239,241,242,243,245,246,247,248,249,250,251,251,252,253,253,254,254,254,254,254,255};

void setup(void) {
  /* your code here */
  for (i=0; i<7; i++) {
    pinMode(leds[i], OUTPUT);
  }
  return;
}

void loop(void) {
  /* more of your code here */

  for (j=0; j<8; j++) {
    digitalWrite(leds[j],HIGH);
  }

  for (j=0; j<8; j++) {
    digitalWrite(leds[j],LOW);
    delay(DELAY);
  }

  for(j=0; j<8; j++) {
    digitalWrite(leds[7-j],HIGH);
    delay(DELAY);
  }

  for(j=0; j<8; j++) {
    digitalWrite(leds[7-j],LOW);
    delay(DELAY);
  }
  for (j=0; j<8; j++) {
    digitalWrite(leds[j],HIGH);
    delay(DELAY);
  }


  return;
}

#ifdef __cplusplus
}
#endif
