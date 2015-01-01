#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB |= _BV( PB1 );
  while( 1 ) { 
    PORTB |=  _BV( PB1 );
    _delay_ms(200);
    PORTB &=~ _BV( PB1 );
    _delay_ms(200);
  }
}
