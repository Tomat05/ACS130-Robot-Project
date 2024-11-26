/*
 * File:   led.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:28
 * 
 * Description: The implementation for `led.h`
 */

#include "led.h"


void _set_leds(short_t states) {
    LATBbits.LB2 = (bool)(states & LED_LL);
    LATBbits.LB3 = (bool)(states & LED_L);
    LATBbits.LB4 = (bool)(states & LED_R);
    LATBbits.LB5 = (bool)(states & LED_RR);
}

void flash(short_t times, short_t interval) {
    for (short_t i = 0; i < times; i++) {
        _set_leds(0b1111);
        delay10ms(interval);
        _set_leds(0b0000);
        delay10ms(interval);
    }
}