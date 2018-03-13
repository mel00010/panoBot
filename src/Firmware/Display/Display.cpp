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

}

Display::~Display() {

}

void command(char i) {
//	C_S = 0; //chip select LOW - active
//	P1 = i; //data on port
//	D_C = 0; //data/command select LOW - write
//	R_W = 0; //read/write select LOW - write
//	E = 1; //enable HIGH
//	delayms(1); //delay
//	E = 0; //enable LOW - data latched
}

void data(char i) {
//	C_S = 0; //chip select LOW
//	P1 = i; //data on port
//	D_C = 1; //data/command s
//	R_W = 0; //read/write select LOW - write
//	E = 1; //enable HIGH
//	delayms(1); //delay
//	E = 0; //enable LOW - data latched
}
//erases the Display
void Display::erase() {
	int i;
	command(0x01); //clear display
	command(0x02); //return home

}

void Display::write(const char* input) {

}

void Display::moveCursor(const Coordinate coordinate) {

}

Coordinate Display::getCursorPosition() {

}

void Display::update(const char* input, const Coordinate coordinate) {

}

void Display::erasePosition(const Coordinate coordinate) {

}

} /* namespace Display */

