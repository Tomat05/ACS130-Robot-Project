/* 
 * File:   led.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:29
 */

#ifndef LED_H
#define	LED_H

#include <xc.h>
#include <stdbool.h>

#include "tools.h"

#define LED1 LATBbits.LB2
#define LED2 LATBbits.LB3
#define LED3 LATBbits.LB4
#define LED4 LATBbits.LB5

void toggle_led(unsigned char led, bool state);
void flash(unsigned char amount, unsigned char interval); // Interval is in 10s of ms
#endif
