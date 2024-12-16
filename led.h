/* 
 * File:   led.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:29
 * 
 * Functions and definitions relating to the LEDs on the board
 */

#ifndef LED_H
#define	LED_H

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdarg.h>

#include "timing.h"
#include "utils.h"

//// LEDs as viewed from the LHS of the robot
#define LED_LL 0b1000
#define LED_L 0b0100
#define LED_R 0b0010
#define LED_RR 0b0001

void _set_leds(short_t leds);
void flash(short_t times, short_t interval); // Interval is in 10s of ms

#define set_leds(ll, lr, rl, rr) (_set_leds((ll << 3) | (lr << 2) | (rl << 1) | rr))

#endif
