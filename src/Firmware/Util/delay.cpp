/*******************************************************************************
 * delay.cpp
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

#include "delay.hpp"

#include <util/delay.h>

#define SCALE 16

void delay_s(int seconds) {
	_delay_us(1000000 * seconds / SCALE);
}
void delay_ms(int milliseconds) {
	_delay_us(1000 * milliseconds / SCALE);
}
void delay_us(int microseconds) {
	_delay_us(microseconds / SCALE);
}

