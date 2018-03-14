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

	command(0b00001111);

}

Display::~Display() {
	//turns the display off, and cursor or blink off if they were on
	command(0b00001000);

}

void Display::command(char command_bits) {
	DC_LOW();
	RW_LOW();

	CS_LOW();
	E_HIGH();

	DATA_PINS = command_bits;

	delay_us(100);
	E_LOW();
	CS_HIGH();

	DATA_PINS = 0x00;
}

void Display::data(char data_bits) {
	DC_HIGH();
	RW_LOW();

	CS_LOW();
	E_HIGH();

	DATA_PINS = data_bits;

	delay_us(100);
	E_LOW();
	CS_HIGH();

	DATA_PINS = 0x00;
}
//clears the Display
void Display::erase() {
	//clears the display. Datasheet defines as:
	//Write "20H" to DDRAM and set DDRAM address to "00H" from AC.
	command(0b00000001);

}

void Display::write(const char* input) {

}

void Display::moveCursor(const Coordinate coordinate) {
	//moves cursor right
	command(0b00000101);

}

Coordinate Display::getCursorPosition() {

}

void Display::update(const char* input, const Coordinate coordinate) {

}

void Display::erasePosition(const Coordinate coordinate) {

}

} /* namespace Display */

