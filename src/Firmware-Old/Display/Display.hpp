/*******************************************************************************
 * Display.hpp
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

#ifndef SRC_FIRMWARE_OLD_DISPLAY_DISPLAY_HPP_
#define SRC_FIRMWARE_OLD_DISPLAY_DISPLAY_HPP_

#include <stddef.h>

#include "../../Firmware-Old/Display/Coordinate.hpp"

namespace Display {

class Display {
	public:
		Display();
		~Display();
		//erases entire display
		void erase();
		//writes a string to display
		void write(const char* input);
		//position to write to in "display"
		void moveCursor(const Coordinate coordinate);
		//gets current cursor position
		Coordinate getCursorPosition();
		//overwriting in a certain position
		void update(const char* input, const Coordinate coordinate);
		//erases at a certain position rather than the entire screen
		void erasePosition(const Coordinate coordinate);
		//for sending command?
		void command(char i);
		void data(char i);

	private:
		Coordinate cursor;
		

};

} /* namespace Display */

#endif /* SRC_FIRMWARE_OLD_DISPLAY_DISPLAY_HPP_ */
