/*16MHz clock timer */
#define F_CPU 16000000 
#define OUTPUTPIN1 PD4
#define OUTPUTPIN2 PD5
#include <avr/io.h>
#include <util/delay.h>
/*50MHz update , 20 ms update period */

//controls the angle of sero
void angle_feedback(){

  int unitsFC = 360;                          
  int dutyScale = 1000;                       // Scale duty cycle to 1/1000ths
  int dcMin = //change this
  int dcMax = //change this                      // Maximum duty cycle
  int q2min = unitsFC/4;                      // For checking if in 1st quadrant
  int q3max = q2min * 3;                      // For checking if in 4th quadrant
  int turns = 0;                              // For tracking turns


  int dc, theta, thetaP, tHigh, tLow;         // Measure feedback signal high/low times.
  tLow = pulse_in(pinFeedback, 0);            // Measure low time 
  tHigh = pulse_in(pinFeedback, 1);           // Measure high time

  // Calcualte initial duty cycle and angle.
  dc = (dutyScale * tHigh) / (tHigh + tLow);
  theta = (unitsFC - 1) - ((dc - dcMin) * unitsFC) / (dcMax - dcMin + 1);
  thetaP = theta;

  while(1)                                    // Main loop for this cog
  {
    // Measure high and low times, making sure to only take valid cycle
    // times (a high and a low on opposite sides of the 0/359 boundary
    // will not be valid.
    int tCycle = 0;                           // Clear cycle time
    while(1)                                  // Keep checking
    {
      tHigh = //change this
      tLow = //change thisw
      tCycle = tHigh + tLow;
      if((tCycle > 1000) && (tCycle < 1200))  // If cycle time valid 
        break;                                // break from loop
    }      
    dc = (dutyScale * tHigh) / tCycle;        // Calculate duty cycle

    
    
    // This gives a theta increasing int the
    // counterclockwise direction.
    theta = (unitsFC - 1) -                   // Calculate angle
            ((dc - dcMin) * unitsFC) 
            / (dcMax - dcMin + 1);

    if(theta < 0)                             // Keep theta valid
      theta = 0; 
    else if(theta > (unitsFC - 1)) 
      theta = unitsFC - 1;

    // If transition from quadrant 4 to  
    // quadrant 1, increase turns count. 
    if((theta < q2min) && (thetaP > q3max))
      turns++;
    // If transition from quadrant 1 to  
    // quadrant 4, decrease turns count. 
    else if((thetaP < q2min) && (theta > q3max))
      turns --;

    // Construct the angle measurement from the turns count and
    // current theta value.
    if(turns >= 0)
      angle = (turns * unitsFC) + theta;
    else if(turns <  0)
      angle = ((turns + 1) * unitsFC) - (unitsFC - theta);

    thetaP = theta;                           // Theta previous for next rep
  }
}

void control360()                             // Cog for control system
{
  //servo_speed(pinControl, 0);                 // Start servo control cog
  
  int errorAngle, output, offset;             // Control system variables
  
  while(1)                                    // Main loop for this cog
  {
    errorAngle = targetAngle - angle;         // Calculate error
    output = errorAngle * Kp;                 // Calculate proportional 
    if(output > 200) output = 200;            // Clamp output
    if(output < -200) output = -200;
    if(errorAngle > 0)                        // Add offset
      offset = 30;
    else if(errorAngle < 0)
      offset = -30;
    else
      offset = 0;     
    //servo_speed(pinControl, output + offset); // Set output
    pause(20);                                // Repeat after 20 ms
  }    
}  

/* set the prescaler of pins, PWM MODE , Inverted or not*/
void initialize_servo(){

	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
    TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //prescaler = 64, mode =  14(FAST PWM)
    /*Mode 14 TOV1 Flag set at top of wgm */

    /*setting output pins */
    DDRD |= (1 << OUTPUTPIN1) | (1 << OUTPUTPIN2);

	ICR1 = 4999; /*Fast PMW mode*/
	/*milisec is about 100 4999/50			*/


	/* compare when OCR1A is a value, we will be at an angle*/
	while(1){
		
		OCR1A = 0;
		/*
		TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x9C;
ICR1L=0x3F;
OCR1AH=0x0B;
OCR1AL=0xB8;
OCR1BH=0x00;
OCR1BL=0x00;
*/

	}

}

void feedback360(){
	int cirlce = 360;
	int scale = 1000;
	int dutyMin = 5; //maybe more
	int dutyMax = 650; //maybe less 
}

/* used to get the angle feed the duty cycle 1ms 1.5ms 2ms, looking at about 1
us(microsecond) per degree*/
float get_angle(uint8_t dCycle){
	return ((dCycle - DCYCLEMIN) * 360) / (DCYCLEMAX - DCYCLEMIN + 1);
}

