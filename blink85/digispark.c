#include <avr/io.h>
#include <util/delay.h>

#define sleep_delay 1000

int main(void)
{
  DDRB |= _BV( PB1 );
  while( 1 ) { 
    PORTB |=  _BV( PB1 );
    _delay_ms(sleep_delay);
    PORTB &=~ _BV( PB1 );
    _delay_ms(sleep_delay);
  }
}
