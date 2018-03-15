/*******************************************************************************
 * Servo.cpp
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

#include "Servo.hpp"

#include <avr/io.h>
#include <math.h>
#include <util/delay.h>

namespace Servo {

void setServoPosition(int servo, double position) {
	const double scale = 5.55555555556;
	double buffer = fmod(position, 360.0);
	switch (servo) {
		case SERVO0:
			break;
		case SERVO1:
			break;
		case SERVO2:
			buffer *= scale;
			buffer += 500;
			OCR3A = (int) buffer;
			break;
		default:
			break;
	}
}

void setServoSpeed(int servo, double rpm) {
	const double scale = -1.42857142857;
	double buffer = rpm;

	if (rpm < -140) {
		buffer = -140;
	}
	if (rpm > 140) {
		buffer = 140;
	}

	buffer *= scale;

	if (rpm < 0) {
		buffer += 1480;
	} else if (rpm > 0) {
		buffer += 1520;
	} else if (rpm == 0) {
		buffer += 1500;
	}
	switch (servo) {
		case SERVO0:
			OCR1A = (int) buffer;
			break;
		case SERVO1:
			OCR1B = (int) buffer;
			break;
		default:
			break;
	}
}

////controls the angle of sero
//void angle_feedback(int servo) {
//
//	int unitsFC = 360;
//	int dutyScale = 1000;                       // Scale duty cycle to 1/1000ths
////  int dcMin = //change this
////  int dcMax = //change this                      // Maximum duty cycle
//	int q2min = unitsFC / 4;                      // For checking if in 1st quadrant
//	int q3max = q2min * 3;                      // For checking if in 4th quadrant
//	int turns = 0;                              // For tracking turns
//
//	int dc, theta, thetaP, tHigh, tLow;         // Measure feedback signal high/low times.
//	tLow = pulse_in(pinFeedback, 0);            // Measure low time
//	tHigh = pulse_in(pinFeedback, 1);           // Measure high time
//
//	// Calcualte initial duty cycle and angle.
//	dc = (dutyScale * tHigh) / (tHigh + tLow);
//	theta = (unitsFC - 1) - ((dc - dcMin) * unitsFC) / (dcMax - dcMin + 1);
//	thetaP = theta;
//
//	while (1)                                    // Main loop for this cog
//	{
//		// Measure high and low times, making sure to only take valid cycle
//		// times (a high and a low on opposite sides of the 0/359 boundary
//		// will not be valid.
//		int tCycle = 0;                           // Clear cycle time
//		while (1)                                  // Keep checking
//		{
//			tHigh = //change this
//					tLow = //change thisw
//							tCycle = tHigh + tLow;
//			if ((tCycle > 1000) && (tCycle < 1200))  // If cycle time valid
//				break;                                // break from loop
//		}
//		dc = (dutyScale * tHigh) / tCycle;        // Calculate duty cycle
//
//		// This gives a theta increasing int the
//		// counterclockwise direction.
//		theta = (unitsFC - 1) -                   // Calculate angle
//		((dc - dcMin) * unitsFC)
//				/ (dcMax - dcMin + 1);
//
//		if (theta < 0)                             // Keep theta valid
//			theta = 0;
//		else if (theta > (unitsFC - 1))
//			theta = unitsFC - 1;
//
//		// If transition from quadrant 4 to
//		// quadrant 1, increase turns count.
//		if ((theta < q2min) && (thetaP > q3max))
//			turns++;
//		// If transition from quadrant 1 to
//		// quadrant 4, decrease turns count.
//		else if ((thetaP < q2min) && (theta > q3max))
//			turns--;
//
//		// Construct the angle measurement from the turns count and
//		// current theta value.
//		if (turns >= 0)
//			angle = (turns * unitsFC) + theta;
//		else if (turns < 0)
//			angle = ((turns + 1) * unitsFC) - (unitsFC - theta);
//
//		thetaP = theta;                           // Theta previous for next rep
//	}
//}
//
//void control360()                             // Cog for control system
//{
//	//servo_speed(pinControl, 0);                 // Start servo control cog
//
//	int errorAngle, output, offset;             // Control system variables
//
//	while (1)                                    // Main loop for this cog
//	{
//		errorAngle = targetAngle - angle;         // Calculate error
//		output = errorAngle * Kp;                 // Calculate proportional
//		if (output > 200)
//			output = 200;            // Clamp output
//		if (output < -200)
//			output = -200;
//		if (errorAngle > 0)                        // Add offset
//			offset = 30;
//		else if (errorAngle < 0)
//			offset = -30;
//		else
//			offset = 0;
//		//servo_speed(pinControl, output + offset); // Set output
//		pause(20);                                // Repeat after 20 ms
//	}
//}
//
//void feedback360() {
//	int cirlce = 360;
//	int scale = 1000;
//	int dutyMin = 5; //maybe more
//	int dutyMax = 650; //maybe less
//}

} /* namespace Servo */
