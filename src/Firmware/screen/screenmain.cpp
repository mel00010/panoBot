#include <string>
#include <iostream>
#include <cstdlib>
#include "screen.hpp"




Screen::Screen(){

}

Screen::~Screen(){

}


void command(char i){
	C_S = 0; //chip select LOW - active
	P1 = i; //data on port
	D_C = 0; //data/command select LOW - write
	R_W = 0; //read/write select LOW - write
	E = 1; //enable HIGH
	delayms(1); //delay
	E = 0; //enable LOW - data latched
}

void data(char i){
	C_S = 0; //chip select LOW
	P1 = i; //data on port
	D_C = 1; //data/command s
	R_W = 0; //read/write select LOW - write
	E = 1; //enable HIGH
	delayms(1); //delay
	E = 0; //enable LOW - data latched
}
//erases the screen
void Screen::eraseScreen(){
	int i;
	command(0x01); //clear display
	command(0x02); //return home

}

void Screen::write(const std::string  &input){

}

void Screen::moveCursor(const size_t &x, const size_t y){

}

std::pair<size_t, size_t> Screen::getCursorPosition(){

}


void Screen::update(const std::string &input, const size_t x, const size_t y){

}


void Screen::erasePosition(const size_t x, const size_t y){

}

void main(void){
	init();
	while(1){
		output();
		delayms(2000);
	}
}


