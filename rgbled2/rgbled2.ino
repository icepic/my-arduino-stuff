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

#define RED 10
#define GREEN 11
#define BLUE 6

void up(void);
void down(void);

const char color[3] = { RED,GREEN,BLUE };
char current=0;

void setup(void) {
  /* your code here */
  pinMode(GREEN,OUTPUT);
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  return;
}

void loop(void) {
  /* more of your code here */
  up();
  current=1;
  up();
  current=2;
  up();
  current=0;
  down();
  current=2;
  down();
  current=0;
  up();
  current=1;
  down();
  current=0;
  down();
  return ;
}

void up() {
  uint8_t i;
  for (i=0;i<255;i++) {
    analogWrite(color[current],i);
    delay(5);
  }
}

void down() {
  uint8_t i;
  for (i=255;i!=0;i--) {
    analogWrite(color[current],i);
    delay(5);
  }
}

#ifdef __cplusplus
}
#endif
