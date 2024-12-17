/* 
 * File:   led.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
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

// Allow us to set the LEDs using a single short_t rather than the extra memory of using 4
// If we don't cast it all to bools it doesn't work and I'm not sure why but if it works it works
#define set_leds(ll, lr, rl, rr) (_set_leds( \
    ((bool)ll << 3) | \
    ((bool)lr << 2) | \
    ((bool)rl << 1) | \
    (bool)rr))

#endif
