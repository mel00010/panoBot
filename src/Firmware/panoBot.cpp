/*******************************************************************************
 * panoBot.cpp
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

#include <Camera/Camera.hpp>
#include <Display/Display.hpp>
#include <Setup/Setup.hpp>
#include <Util/delay.hpp>


int main(void) {
	Display::Display* display = nullptr;

	Setup::setup(display);

	/* The Big Loop */
	for (;;) {
		display->write("Starting panorama...");
		delay_s(1);

		display->erase();
		display->write("Focusing camera...");
		Camera::focus();

		delay_s(1);

		display->erase();
		display->write("Taking photo 1 / 5...");
		Camera::takePhoto();

		delay_s(1);
	}
}
