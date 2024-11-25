/*
 * File:   led.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:28
 * 
 * Description: The implementation for `led.h`
 */

#include "led.h"

void toggle_led(short_t led, bool state) {
    switch (led) {
        case 1: LATBbits.LB2 = state; break;
        case 2: LATBbits.LB3 = state; break;
        case 3: LATBbits.LB4 = state; break;
        case 4: LATBbits.LB5 = state; break;
    }
}

void flash(short_t amount, short_t interval) {
    for (unsigned char i = 0; i < amount; i++) {
        toggle_led(1, true);
        toggle_led(2, true);
        toggle_led(3, true);
        toggle_led(4, true);
        delay10ms(interval);
        toggle_led(1, false);
        toggle_led(2, false);
        toggle_led(3, false);
        toggle_led(4, false);
        delay10ms(interval);
    }
}