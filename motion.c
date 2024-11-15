/* 
 * File:   motion.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 17:20
 */

#include "motion.h"

void l_speed(unsigned char speed, bool backwards) {
    CCPR1L = speed;
    if (backwards) {
        M_LEFT_BACK = 1;
        M_LEFT_FORWARD = 0;
    } else {
        M_LEFT_BACK = 0;
        M_LEFT_FORWARD = 1;
    }
}

void r_speed(unsigned char speed, bool backwards) {
    CCPR2L = speed;
    if (backwards) {
        M_RIGHT_BACK = 1;
        M_RIGHT_FORWARD = 0;
    } else {
        M_RIGHT_BACK = 0;
        M_RIGHT_FORWARD = 1;
    }
}

void forwards(unsigned char speed) {
    l_speed(speed, false);
    r_speed(speed, false);
}

void backwards(unsigned char speed) {
    l_speed(speed, true);
    r_speed(speed, true);
}

void left(unsigned char speed) {
    l_speed(speed, true);
    r_speed(speed, false);
}

void right(unsigned char speed) {
    l_speed(speed, false);
    r_speed(speed, true);
}

void stop(void) {
    M_RIGHT_BACK = 1;
    M_RIGHT_FORWARD = 1;
    M_LEFT_BACK = 1;
    M_LEFT_FORWARD = 1;
}