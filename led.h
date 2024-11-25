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

#include "timing.h"
#include "misc.h"

// LEDs as viewed from the LHS of the robot
#define LED_LL 1
#define LED_L 2
#define LED_R 3
#define LED_RR 4

void toggle_led(short_t led, bool state);
void flash(short_t amount, short_t interval); // Interval is in 10s of ms
#endif
