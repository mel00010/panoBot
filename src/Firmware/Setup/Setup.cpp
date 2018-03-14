/*******************************************************************************
 * Setup.cpp
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

#include <avr/io.h>
#include "Setup.hpp"

#include "../Display/Display.hpp"
#include "../Util/new.hpp"

namespace Setup {

void setup(Display::Display* display) {
	//	DDRB |= _BV(PB0); // Set 53 (PB0) to output
	DDRB |= _BV(PB1); // Set 52 (PB1) to output
	DDRB |= _BV(PB2); // Set 51 (PB2) to output
	DDRB |= _BV(PB3); // Set 50 (PB3) to output
	DDRL |= _BV(PL0); // Set 49 (PL0) to output
	DDRL |= _BV(PL1); // Set 48 (PL1) to output
	DDRL |= _BV(PL2); // Set 47 (PL2) to output
	DDRL |= _BV(PL3); // Set 46 (PL3) to output
	DDRL |= _BV(PL4); // Set 45 (PL4) to output
	DDRL |= _BV(PL5); // Set 44 (PL5) to output
	DDRL |= _BV(PL6); // Set 43 (PL6) to output
	DDRL |= _BV(PL7); // Set 42 (PL7) to output
	DDRL |= _BV(PG0); // Set 41 (PG0) to output
	DDRB |= _BV(PG1); // Set 40 (PG1) to output

	display = new Display::Display();

	DDRH |= _BV(PH1); // Set 16 (PH1) to output
	DDRH |= _BV(PH0); // Set 17 (PH0) to output

}

} /* namespace Setup */

