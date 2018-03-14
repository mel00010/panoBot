/*******************************************************************************
 * delay.hpp
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
#ifndef SRC_FIRMWARE_UTIL_DELAY_HPP_
#define SRC_FIRMWARE_UTIL_DELAY_HPP_

#include <util/delay.h>
#define SCALE 16

#define delay_s(seconds) _delay_ms(((1000 * seconds) / SCALE))
#define delay_ms(milliseconds) _delay_ms((milliseconds / SCALE))
#define delay_us(microseconds) _delay_us((microseconds / SCALE))


#endif /* SRC_FIRMWARE_UTIL_DELAY_HPP_ */
