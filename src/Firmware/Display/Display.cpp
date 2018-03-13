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

#include "../Util/Pair.hpp"

namespace Display {

Display::Display() {
	//turns the display on, but not cursor or blink
	command(0b00001100);

}

Display::~Display() {
	//turns the display off, and cursor or blink off if they were on
	command(0b00001000);

}

void Display::command(char i) {
//	C_S = 0; //chip select LOW - active
//	P1 = i; //data on port
//	D_C = 0; //data/command select LOW - write
//	R_W = 0; //read/write select LOW - write
//	E = 1; //enable HIGH
//	delayms(1); //delay
//	E = 0; //enable LOW - data latched
}

void Display::data(char i) {
//	C_S = 0; //chip select LOW
//	P1 = i; //data on port
//	D_C = 1; //data/command s
//	R_W = 0; //read/write select LOW - write
//	E = 1; //enable HIGH
//	delayms(1); //delay
//	E = 0; //enable LOW - data latched
}
//clears the Display
void Display::erase() {
	//clears the display. Datasheet defines as:
	//Write "20H" to DDRAM and set DDRAM address to "00H" from AC.
	command(0b0000000001);

	

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

