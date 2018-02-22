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

#ifndef __AVR_ATmega328P__
#define __AVR_ATmega328P__
#endif/*__AVR_ATmega328P__*/


#include <Setup/Setup.hpp>


#include <avr/io.h>
#include <util/delay.h>


int main (void)
{

	Setup::setup();
	/* The Big Loop */
	for(;;) {
		PORTB |= 0b00100000; // Turn PB5 on
		_delay_ms(1000);
		PORTB &= 0b11011111; // Turn PB5 off
		_delay_ms(1000);
	}
}
