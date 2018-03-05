#include <avr/io.h>
#include <util/delay.h>
/*50MHz update , 20 ms update period */

/*waits using 16bit timer*/
void delay(){
	uint8_t i;
	for(i =0; i < 50; i++){
		/*delay loop for 16bit timer found in delay.h*/
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0); 
	}
}

/* set the prescaler of pins, PWM MODE , Inverted or not*/
void set_pins(uint8_t preScaler ,  ){

}

/* used to get the angle feed the duty cycle 1ms 1.5ms 2ms, looking at about 1
us(microsecond) per degree*/
float get_angle(uint8_t dCycle){
	return ((dCycle - DCYCLEMIN) * 360) / (DCYCLEMAX - DCYCLEMIN + 1);
}