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

#include <libopencm3/stm32/f1/rcc.h>
#include <libopencm3/stm32/f1/gpio.h>
#include <libopencm3/stm32/timer.h>

#include "pwm.h"
#include "servo.h"

void servo_init(void)
{
     /* init timer2 with a period of 20ms */
     pwm_init_timer(&RCC_APB1ENR, RCC_APB1ENR_TIM2EN, TIM2, PWM_PRESCALE, PWM_PERIOD);

     /* init output of channel2 of timer2 */
     pwm_init_output_channel(TIM2, SERVO_CH1, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH2);

     /* init output of channel3 of timer2 */
     pwm_init_output_channel(TIM2, SERVO_CH2, &RCC_APB2ENR, RCC_APB2ENR_IOPAEN, GPIOA, GPIO_TIM2_CH3);

     pwm_set_pulse_width(TIM2, SERVO_CH1, SERVO_NULL);
     pwm_set_pulse_width(TIM2, SERVO_CH2, SERVO_NULL);

     /* start timer1 */
     pwm_start_timer(TIM2);
}

void servo_set_position(enum tim_oc_id ch, uint32_t pos_us)
{
     pwm_set_pulse_width(TIM2, ch, pos_us);
}

