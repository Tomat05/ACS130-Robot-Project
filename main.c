/*
 * File:   main.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:25
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

void main(void) {
    setup_io();
    setup_pwm();
    setup_adc();
    
    startup_flash();
    
    forwards(255);
    delay10ms(100);
    backwards(255);
    delay10ms(100);
    stop();
    delay10ms(100);
    left(255);
    delay10ms(100);
    right(255);
    delay10ms(100);
    stop();
    while(1);
    return;
}