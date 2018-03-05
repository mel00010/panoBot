// Create by Stewart, Justin 4 March 2018

#define buttonNumber 2

include <avr/io.h>
#include"ButtonPress.h"

int main(void)
{
DDRB = 0b00001100; // used as a example for port b we have 8 pins to use this example shows pins (0,1) set to 0 and pins(2,3) set to 1 still need to find out the exact pins we need to make this work 
PORTB = (1 << PINB0)|(1 << PINB1); // sets both pins 0,1 to 1 or high state

while (1) // inifinite loop
{
    if buttonPressed(int buttonNumber, unsigned char boardPin, unsigned char boardPort, int stateCheck){

    }
/*  
The following if statements are dummy statements made up so we can use the buttons within the board.
We will need to get more information to make these cases work like debouncing time which is statecheck
as well as the boardpin and boardport locations of the buttons
*/ 


    /*CASE BUTTON 1*/
    if (ButtonPressed(0,PINB, 0, 20){  //( int buttonNumber, unsigned char boardPin, boardPort , stateCheck )
        PORTB ^= (1 << PINB2 ) // will toggle PINB2 from state 1 to 0 
    }
    /*CASE BUTTON 2*/
    if (ButtonPressed(0,PINB, 0, 20){  //( int buttonNumber, unsigned char boardPin, boardPort , stateCheck )
        PORTB ^= (1 << PINB3 ) // will toggle PINB3  from state 1 to 0 
    }
    /*CASE BUTTON 3*/
    if (ButtonPressed(0,PINB, 0, 20){  //( int buttonNumber, unsigned char boardPin, boardPort , stateCheck )
        PORTB ^= (1 << PINB4 ) // will toggle PINB4 from state 0 to 1 
    }    

}
} 