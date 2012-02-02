/*
 * This file is part of the PWM-Servo example.
 *
 * Copyright (C) 2011 Stefan Wendler <sw@kaltpost.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __SERVO_H_
#define __SERVO_H_

#include <libopencm3/stm32/timer.h>

/**
 * Prescale 72000000 Hz system clock by 72 = 1000000 Hz.
 */
#define PWM_PRESCALE	(72)

/**
 * We need a 50 Hz period (1000 / 20ms = 50), thus devide 100000 by 50 = 20000 (us).
 */
#define PWM_PERIOD		(20000)

/**
 * Max. pos. at 2050 us (2.00ms).
 */
#define SERVO_MAX		(2050)

/**
 * Min. pos. at 950  us (0.95ms).
 */
#define SERVO_MIN		(950)

/**
 * Middle pos. at 1580 us (1.58ms).
 */
#define SERVO_NULL		(1580)

/**
 * TIM2 channel for servo 1.
 *
 * Changing this also requires to change settings in {@link servo_init}!
 */
#define SERVO_CH1		TIM_OC2

/**
 * TIM2 channel for servo 2.
 *
 * Changing this also requires to change settings in {@link servo_init}!
 */
#define SERVO_CH2		TIM_OC3

/**
 * Initialize and start the PWM used for the servos, drive servos to middle position.
 */
void servo_init(void);

/**
 * Drive the servo connected to the given channel to the given position in us.
 *
 * @param[in]	ch		The channel of the servo. E.g. SERVO_CH1, SERVO_CH2.
 * @param[in]	pos_us	The position in us to which to drive the servo to.
 */
void servo_set_position(enum tim_oc_id ch, uint32_t pos_us);

#endif
