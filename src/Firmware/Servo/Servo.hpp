/*******************************************************************************
 * Servo.hpp
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
#ifndef SRC_FIRMWARE_SERVO_SERVO_HPP_
#define SRC_FIRMWARE_SERVO_SERVO_HPP_

#include <stddef.h>
#include <stdint.h>
#include "PIDObj.hpp"

#define SERVO0 0
#define SERVO1 1
#define SERVO2 2


namespace Servo {

void move(int desiredPos, int desiredServo, PIDObj pobj);
void setServoPosition(int servo, double position);
void setServoSpeed(int servo, double rpm);
//void angle_feedback();
//void control360();
//void feedback360();
//float get_angle(uint8_t dCycle);

} /* namespace Servo */




#endif /* SRC_FIRMWARE_SERVO_SERVO_HPP_ */
