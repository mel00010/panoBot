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
	display = new Display::Display();

	DDRH |= _BV(PH1); // Set 16 (PH1) to output
	DDRH |= _BV(PH0); // Set 17 (PH0) to output
}

} /* namespace Setup */

