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

#include "servo.h"

/**
 * Setup the system clock to 72MHz.
 */
void clock_init(void)
{
     rcc_clock_setup_in_hse_8mhz_out_72mhz();
}

/**
 * Initialize the GPIO port for the LED at pin 12 on port C.
 */
void gpio_init(void)
{
     /* enable GPIOC clock */
     rcc_peripheral_enable_clock(&RCC_APB2ENR, RCC_APB2ENR_IOPCEN);

     /*
      * set GPIO12 at PORTC (led) to 'output alternate function push-pull'.
      */
     gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO12);
}

/**
 * Delay by executing some "nop"s.
 *
 * @param[in]	d	number of "nop"s to performe.
 */
void delay(int d)
{

     int i;

     for(i = 0; i < d; i++) {
          __asm("nop");
     }
}

int main(void)
{
     clock_init();
     gpio_init();
     servo_init();

     gpio_set(GPIOC, GPIO12);

     delay(150000000);

     // let pan-til "look around a little"
     while(1) {
          servo_set_position(SERVO_CH1, SERVO_MIN);
          servo_set_position(SERVO_CH2, SERVO_MAX);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_MAX);
          servo_set_position(SERVO_CH2, SERVO_MIN);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_MIN);
          servo_set_position(SERVO_CH2, SERVO_MIN);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_MAX);
          servo_set_position(SERVO_CH2, SERVO_MAX);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_MIN);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_MAX);
          servo_set_position(SERVO_CH2, SERVO_NULL);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_MIN);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_MAX);
          delay(15000000);

          servo_set_position(SERVO_CH1, SERVO_NULL);
          servo_set_position(SERVO_CH2, SERVO_NULL);
          delay(15000000);
     }

     return 0;
}
