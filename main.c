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
#include <stdbool.h>

#pragma config OSC = HS    //High speed resonator
#pragma config WDT = OFF   //Watchdog timer off
#pragma config LVP = OFF   //Low voltage programming disabled
#pragma config PWRT = ON   //Power up timer on

#include "led.h"
#include "setup.h"
#include "motion.h"
#include "sensing.h"
#include "utils.h"

#define OBSTACLE_THRESHOLD 750

void main(void) {
    setup_io();
    setup_pwm();
    setup_adc();
    
    flash(3, 50);
    
    State_t state;
    
    for (;;) {
        state.all = 0;
        detect_obstacle(&state, OBSTACLE_THRESHOLD);
//        TODO: Detect beacon
        
        set_leds(state.IR_L, state.BE_L, state.BE_R, state.IR_R);
        
//        if (state.IR) {
//            avoid_obstacle(64);
//        }
//            
//        forwards(64);
    }
    return;
}