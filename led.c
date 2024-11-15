/*
 * File:   led.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:28
 */

#include "led.h"
#include "tools.h"

void toggle_led(unsigned char led, bool state) {
    switch (led) {
        case 1: LED1 = state; break;
        case 2: LED2 = state; break;
        case 3: LED3 = state; break;
        case 4: LED4 = state; break;
    }
}

void startup_flash(void) {
    for (unsigned char i = 0; i < 3; i++) {
        toggle_led(1, true);
        toggle_led(2, true);
        toggle_led(3, true);
        toggle_led(4, true);
        delay10ms(50);
        toggle_led(1, false);
        toggle_led(2, false);
        toggle_led(3, false);
        toggle_led(4, false);
        delay10ms(50);
    }
}