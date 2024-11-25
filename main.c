/*
 * File:   main.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:25
 * 
 * The entry-point and main execution loop of the programme
 */


#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#pragma config OSC = HS    //High speed resonator
#pragma config WDT = OFF   //Watchdog timer off
#pragma config LVP = OFF   //Low voltage programming disabled
#pragma config PWRT = ON   //Power up timer on

#include "led.h"
#include "setup.h"
#include "motion.h"
#include "sensing.h"
#include "misc.h"

#define OBSTACLE_THRESHOLD 800

void main(void) {
    setup_io();
    setup_pwm();
    setup_adc();
    
    flash(3, 50);
    
    for (;;) {
        short_t obstacles = detect_obstacle(OBSTACLE_THRESHOLD);
        toggle_led(LED_LL, (obstacles & 0b10));
        toggle_led(LED_RR, (obstacles & 0b01));
    }
    return;
}