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

#define DEBUG_SENSORS

#include "led.h"
#include "setup.h"
#include "motion.h"
#include "sensing.h"
#include "utils.h"

#define OBSTACLE_THRESHOLD 400
#define TURN_SPEED 128
#define FORWARD_SPEED 192

#define DISABLE_MOVEMENT

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
        
        set_leds(sensors.IR_L, sensors.BE_L, sensors.BE_R, sensors.IR_R);
        
// For debugging
#ifndef DISABLE_MOVEMENT
        
        if (sensors.IR) {
//            avoid_obstacle(TURN_SPEED);
        }
        
        switch (sensors.BEACON) {
            // Arbitrarily picked right as direction to turn if neither sensor
            // detects the beacon
            case 0b00:
            case 0b10:
                right(TURN_SPEED);
                break;
            case 0b01:
                left(TURN_SPEED);
                break;
            default:
                forwards(FORWARD_SPEED);
                break;
        }
        
#endif /* DISABLE_MOVEMENT */
    }
    return;
}