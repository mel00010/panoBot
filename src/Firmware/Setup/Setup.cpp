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

#include "Setup.hpp"

#include <avr/io.h>
#include <avr/interrupt.h>
//#include <util/setbaud.h>
#include <stdio.h>


namespace Setup {

#define BAUD_PRESCALE (((( F_CPU / 16) + ( BAUD / 2) ) / ( BAUD ) ) - 1)

void USART_Init()
{
//	UBRR0L = (uint8_t)(BAUD_PRESCALE & 0xff);
//	UBRR0H = (uint8_t)(BAUD_PRESCALE >> 8);
//	UCSR0B =
		/* interrupt on receive */
//		_BV(RXCIE0) |
		/* interrupt on data read register empty (so we can transmit) */
//		_BV(UDRIE0) |
		/* enable read */
//		_BV(RXEN0)  |
		/* enable transmit */
//		_BV(TXEN0);
//	UCSR0C =
//		/* no parity bit */
//		~_BV(UPM01)   &
//		~_BV(UPM00)   &
//		/* asyncrounous USART */
//		~_BV(UMSEL01) &
//		~_BV(UMSEL00) &
//		/* one stop bit */
//		~_BV(USBS0)   &
//		/* 8 data bits */
//		_BV(UCSZ01)   |
//		_BV(UCSZ00);
}


void setup() {
	DDRH |= _BV(PH1); // Set 16 (PH1) to output
	DDRH |= _BV(PH0); // Set 17 (PH0) to output
}

} /* namespace Setup */

