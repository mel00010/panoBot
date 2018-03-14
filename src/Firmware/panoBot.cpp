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

//int main(void) {
//	Display::Display* display = nullptr;
//
//	Setup::setup(display);
//	display->erase();
//	display->write("Starting panorama...");
//
//	/* The Big Loop */
//	for (;;) {
//		delay_s(1);
//
////		display->erase();
////		display->write("Focusing camera...");
//		Camera::focus();
//
//		delay_s(1);
//
////		display->erase();
////		display->write("Taking photo 1 / 5...");
//		Camera::takePhoto();
//
//		delay_s(1);
//	}
//}

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void) {
	DDRB = 0xFF;
//set fast pwm, mode 3 from data sheet
	TCCR1A |= (1 << WGM01) | (1 << WGM00);
	TCCR1A |= (1 << COM2A0) | (1 << CS22); // prescaler of 64

	ICR1L = 4999;

	OCR1A = 4999 - 2000;

	OCR1A = ICR1L - 100;
	delay_ms(100);
	OCR1A = ICR1L - 2200;
	delay_ms(100);

	while (1) {

	}

}
