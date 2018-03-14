/*******************************************************************************
 * Display.cpp
 * Copyright (C) 2018  Mel McCalla <melmccalla@gmail.com>
 *
 * This file is part of panoBot.
 *
 * panoBot is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * panoBot is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with panoBot.  If not, see <http://www.gnu.org/licenses/>.
 *******************************************************************************/

#include "Display.hpp"

#include <avr/io.h>
#include <string.h>

#include "../Util/Pair.hpp"
#include "../Util/delay.hpp"

#define DC_LOW()	PORTB &= ~_BV(PB1)
#define DC_HIGH()	PORTB |=  _BV(PB1)
#define RW_LOW()	PORTB &= ~_BV(PB2)
#define RW_HIGH()	PORTB |=  _BV(PB2)
#define E_LOW()		PORTB &= ~_BV(PB3)
#define E_HIGH()	PORTB |=  _BV(PB3)
#define CS_LOW()	PORTG &= ~_BV(PG0)
#define CS_HIGH()	PORTG |=  _BV(PG0)
#define RES_LOW()	PORTG &= ~_BV(PG1)
#define RES_HIGH()	PORTG |=  _BV(PG1)

#define DATA_PINS	PORTL

namespace Display {

Display::Display() {
	CS_HIGH();
	RES_HIGH();
	DATA_PINS = 0x00;
	//turns the display on, but not cursor or blink	PORTL = 0xFF;

//	command(0b00001111);
//	command(0b00000011);
//	command(0b00000100);

	command(0x2A);	//function set (extended command set)
	command(0x71);	//function selection A
	data(0x00);		// disable internal VDD regulator (2.8V I/O). data(0x5C) = enable regulator (5V I/O)
	command(0x28);	//function set (fundamental command set)
	command(0x08);	//display off, cursor off, blink off
	command(0x2A);	//function set (extended command set)
	command(0x79);	//OLED command set enabled
	command(0xD5);	//set display clock divide ratio/oscillator frequency
	command(0x70);	//set display clock divide ratio/oscillator frequency
	command(0x78);	//OLED command set disabled
	command(0x09);	//extended function set (4-lines)
	command(0x06);	//COM SEG direction
	command(0x72);	//function selection B
	data(0x00);   	//ROM CGRAM selection
	command(0x2A);	//function set (extended command set)
	command(0x79);	//OLED command set enabled
	command(0xDA);	//set SEG pins hardware configuration
	command(0x10);	//set SEG pins hardware configuration
	command(0xDC);	//function selection C
	command(0x00);	//function selection C
	command(0x81);	//set contrast control
	command(0x7F);	//set contrast control
	command(0xD9);	//set phase length
	command(0xF1);	//set phase length
	command(0xDB);	//set VCOMH deselect level
	command(0x40);	//set VCOMH deselect level
	command(0x78);	//OLED command set disabled
	command(0x28);	//function set (fundamental command set)
	command(0x01);	//clear display
	command(0x80);	//set DDRAM address to 0x00
	command(0x0C);	//display ON

}

Display::~Display() {
	//turns the display off, and cursor or blink off if they were on
	command(0b00001000);

}

//for all commands sent to display
void Display::command(char command_bits) {
	DC_LOW();
	RW_LOW();
	DATA_PINS = command_bits;
	CS_LOW();
	_delay_us(100);
	E_HIGH();
	E_LOW();
	CS_HIGH();
}

void Display::data(char data_bits) {
	DC_HIGH();
	RW_LOW();
	DATA_PINS = data_bits;
	CS_LOW();
	_delay_us(100);
	E_HIGH();
	E_LOW();
	CS_HIGH();
}
//clears the Display
void Display::erase() {
	//clears the display. Datasheet defines as:
	//Write "20H" to DDRAM and set DDRAM address to "00H" from AC.
	command(0b00000001);

}

void Display::write(const char* input) {
	size_t len = strlen(input); // Get the size of the string ahead of the loop so that strlen is not repeatedly called.
	for (size_t i = 0; i < len; i++) { 	//iterates through each character in the string
		data(input[i]);		//calls data, which writes the character to the screen.
	}
}

void Display::moveCursor(const Coordinate coordinate) {

	//cursor position
	int x = coordinate.x;
	//which line
	int y = coordinate.y;
	if (coordinate.y == 2){
		command(0b0000010010); //2nd line display shift enable
		command(0b00000111); //display shift "right"(down)

		for(int i = 0; i < x; i++){
			command(0b00000101); // cursor shift right
		}
		command(0b0000010000); //2nd line display shift disable
	}

	if (coordinate.y == 3){
		command(0b0000010100); //3rd line display shift enable
		command(0b00000111); //display shift "right"(down)

		for(int i = 0; i < x; i++){
			command(0b00000101); // moves cursor right
		}

		command(0b0000010100); //3rd line display shift disable

	}
	if (coordinate.y == 4){
		command(0b0000011000); //3rd line display shift enable
		command(0b00000111); //display shift "right"(down)

		for(int i = 0; i < x; i++){
			command(0b00000101); // moves cursor right
		}

		command(0b0000011000); //3rd line display shift disable

	}




	// //moves cursor left
	// command(0b00000100);

	// //moves cursor right
	// command(0b00000101);



}

Coordinate Display::getCursorPosition() {

}

void Display::update(const char* input, const Coordinate coordinate) {
	//moves to position to start update
	moveCursor(coordinate);
	//write, starting at position cursor has moved to.
	write(input);





}

//Implementation should be considered a rough idea at this point as not all functions called therein are properly defined
void Display::erasePosition(const Coordinate coordinate) {
	//moves cursor to position to erase
	moveCursor(coordinate);
	//writes empty character to this space. Function may be later updated to erase multiple spaces in succession, but not the full screen.
	write(" ");
	//This is a pseudo erase, as a blank character is inserted rather than the space deleted completely. Will hopefully change this.

}

} /* namespace Display */

