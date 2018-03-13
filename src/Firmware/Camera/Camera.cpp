/*******************************************************************************
 * Camera.cpp
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

#include "Camera.hpp"

#include <stddef.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../Util/delay.hpp"

namespace Camera {

void takePhoto() {
	PORTH |= _BV(PH0);
	delay_s(1);
	PORTH &= ~_BV(PH0);
}

void focus() {
	PORTH |= _BV(PH1);
	delay_s(1);
	PORTH &= ~_BV(PH1);
}

} /* namespace Camera */
