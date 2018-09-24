#include <string>
#include <iostream>
#include <cstdlib>

//NHD-0420CW-AW3 OLED Display
//Example code for display functionality provided in data sheet copied with comments



void command(char i){
	C_S = 0; //chip select LOW-active
	P1 = i; //data on port
	D_C = 1; //data/command select HIGH - data
	R_W = 0; //read/write select LOW - write
	E = 1; //enable HIGH
	delayms(1); //delay
	E = 0; //enable LOW - data latched

}

void data(char i){
	C_S = 0; //chip select LOW - active
	P1 = i; //data pm [prt
	D_C = 1; //data/command select HIGH - data
	R_W = 0; //read/write select LOW - write
	E = 1; //enable HIGH
	delayms(1); //delay
	E = 0; //enable LOW - data latched
}

void output(){
	int i;
	command(0x01); //clear display
	command(0x02); //return home
	for(i=0;i<20;i++){
		data(0x1F); //write solid blocks
	}
	command(0xA0); //line 2
	for(i = 0; i< 20; i++){
		data(0x1F); //write solid blocks
	}
	command(0xC0); //line 3
	for(i=0; i<20; i++){
		data(0x1F); //write solid blocks)
	}
	command(0xE0); //line 4
	for(i=0; i<20; i++){
		data(0x1F); //write solid blocks
	}
}

void init(){
	RES = 1; //reset HIGH - inactive
	delayms(1); //delay
	command(0x2A); //function set (extended command set)
	command(0x71); //function selection A
	data(0x00); //disable internal VDD regulator(2.8V I/0).data(0x5C) = enable regulator(5V I/O)
	command(0x28); //function set(fundamental command set)
	command(0x08); //display off, cursor off, blink off
	command(0x2A); //function set (extended command set)
	command(0x79); //OLED command set enabled
	command(0xD5); //set display clock divide ratio/oscillator frequency
	command(0x70); //set display clock divide ratio/oscillator frequency
	command(0x78); //OLED command set disabled
	command(0x09); //extended function set (4-lines)
	command(0x06); //COM SEG direction
	command(0x72); //function selection B
	data(0x00); //ROM CGRAM selection
	command(0x2A); //function set (extended command set)
	command(0x79); //OLED command set enabled
	command(0xDA); //set SEG pins hardware configuration
	command(0x10); //set SEG pins hardware configuration
	command(0xDC); //function selection C
	command(0x00); //function selection C
	command(0x81); //set contrast control
	command(0x7F); //set contrast control
	command(0xD9); //set phase length
	command(0xF1); //set phase length
	command(0xDB); //set VCOMH deselect level
	command(0x40); //set VCOMH deselect level
	command(0x78); //OLED command set disabled
	command(0x28); //function set(fundamental command set)
	command(0x01); //clear display
	command(0x80); //set DDRAM address to 0x00
	command(0x0C); //display ON
	delayms(100); //delay
}


void main(void){
	init();
	while(1){
		output();
		delayms(2000);
	}
	return 0; //I added this line idk if it's needed for actual functional conversion
	//of the above code
}