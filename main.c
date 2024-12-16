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

#define OBSTACLE_THRESHOLD 400

void main(void) {
    setup_io();
    setup_pwm();
    setup_adc();
    
    flash(3, 50);
    
    Sensors_t sensors;
    
    for (;;) {
        sensors.all = 0;
        detect_obstacle(&sensors, OBSTACLE_THRESHOLD);
        detect_beacon(&sensors);
        
//        set_leds(sensors.IR_L, sensors.BE_L, sensors.BE_R, sensors.IR_R);
        _set_leds(sensors.all);
        
        if (sensors.IR) {
//            avoid_obstacle(96);
//            stop();
        }
//            
//        forwards(96);
    }
    return;
}