// Create by Stewart, Justin 4 March 2018

#ifndef buttons
#define buttonPress

#include <avr/io.h>

char buttonPressed(int buttonNumber, unsigned char boardPin, unsigned char boardPort, int stateCheck);
char startProgram(unsigned char boardPin, unsigned char boardPort);

char Pressed[buttonNumber];
int pressedCheck[buttonNumber]; //Measure button press cofidence
int releasedCheck[buttonNumber]; //Measure button release confidence


char startProgram(unsigned char boardPin, unsigned char boardPort){
    if (startPin ==0{  //( int buttonNumber, unsigned char boardPin, boardPort , stateCheck )
                PORTB ^= (1 << PINB3 ) /*This is a toggle function*/    // PORTB is the startPort we need to look at PINB3 is the pin needing to be changed from 0 to 1  we need to know which in and port still 
            }
}


char buttonPressed(int buttonNumber, unsigned char boardPin, unsigned char boardPort, int stateCheck){
    if (bit_is_clear(boardPin, boardPort)){
        pressedCheck[buttonNumber] ++; //Increase Pressed 
        releasedCheck[buttonNumber] = 0; //Reset released button state since there is a button press
        if (pressedCheck[buttonNumber] > stateCheck) {//Indicator of good button press
            if (Pressed[buttonNumber] == 0){
                Pressed[buttonNumber] = 1;
                return 1;
            }
        }
    //Zero it so a new pressed condition can be evaluated
    pressedCheck[buttonNumber] = 0;
    }
    
else
{
releasedCheck[buttonNumber] ++; //This works just like the pressed
pressedCheck[buttonNumber] = 0; //Reset pressed button state since the button is released
if (releasedCheck[buttonNumber] > stateCheck)
{
Pressed[buttonNumber] = 0;
releasedCheck[buttonNumber] = 0;
}
}
return 0;
}

#endif

char interrupt ()
