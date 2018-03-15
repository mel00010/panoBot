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
#include <Servo/Servo.hpp>
#include <Setup/Setup.hpp>
#include <Util/delay.hpp>

#include <avr/io.h>
#include <util/delay.h>
#include <stddef.h>

int main(void) {
	Display::Display* display = nullptr;

	Setup::setup(display);

	/* The Big Loop */
	for (;;) {
		display->erase();
		display->write("Starting panorama...");

		delay_ms(1000);

		display->erase();
		display->write("Focusing camera...");
		Camera::focus();

		delay_ms(1000);

		display->erase();
		display->write("Taking photo 1 / 5...");
		Camera::takePhoto();

		display->erase();
		display->write("Moving...");

		Servo::setServoSpeed(SERVO0, 100);
		Servo::setServoSpeed(SERVO1, -100);
		Servo::setServoPosition(SERVO2, 230);
		delay_ms(1000);
		Servo::setServoSpeed(SERVO0, 0);
		Servo::setServoSpeed(SERVO1, 0);
		Servo::setServoPosition(SERVO2, 90);
		delay_ms(500);

		display->erase();
		display->write("Taking photo 2 / 5...");
		Camera::takePhoto();

		display->erase();
		display->write("Moving...");

		Servo::setServoSpeed(SERVO0, 100);
		Servo::setServoSpeed(SERVO1, -100);
		Servo::setServoPosition(SERVO2, 270);
		delay_ms(1000);
		Servo::setServoSpeed(SERVO0, 0);
		Servo::setServoSpeed(SERVO1, 0);
		Servo::setServoPosition(SERVO2, 90);
		delay_ms(500);

		display->erase();
		display->write("Taking photo 3 / 5...");
		Camera::takePhoto();

		display->erase();
		display->write("Moving...");

		Servo::setServoSpeed(SERVO0, 100);
		Servo::setServoSpeed(SERVO1, -100);
		Servo::setServoPosition(SERVO2, 270);
		delay_ms(1000);
		Servo::setServoSpeed(SERVO0, 0);
		Servo::setServoSpeed(SERVO1, 0);
		Servo::setServoPosition(SERVO2, 90);
		delay_ms(500);

		display->erase();
		display->write("Taking photo 4 / 5...");
		Camera::takePhoto();

		display->erase();
		display->write("Moving...");

		Servo::setServoSpeed(SERVO0, 100);
		Servo::setServoSpeed(SERVO1, -100);
		Servo::setServoPosition(SERVO2, 270);
		delay_ms(1000);
		Servo::setServoSpeed(SERVO0, 0);
		Servo::setServoSpeed(SERVO1, 0);
		Servo::setServoPosition(SERVO2, 90);
		delay_ms(500);

		display->erase();
		display->write("Taking photo 5 / 5...");
		Camera::takePhoto();

		display->erase();
		display->write("Moving...");

		Servo::setServoSpeed(SERVO0, 100);
		Servo::setServoSpeed(SERVO1, -100);
		Servo::setServoPosition(SERVO2, 0);
		delay_ms(1000);
		Servo::setServoSpeed(SERVO0, 0);
		Servo::setServoSpeed(SERVO1, 0);
		Servo::setServoPosition(SERVO2, 90);
		delay_ms(500);
	}
}

