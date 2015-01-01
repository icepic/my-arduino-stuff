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

int led=13;

void setup(void) {
  /* your code here */
  pinMode(led,OUTPUT);
  return;
}

void loop(void) {
  /* more of your code here */
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1500);               // wait for half a second                  
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1500);               // wait for a second                       
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)    
  delay(300);               // wait for half a second                   
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(300);               // wait for a second                        
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(300);               // wait for half a second     
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(300);               // wait for a second                        
  
  return ;
}

#ifdef __cplusplus
}
#endif
