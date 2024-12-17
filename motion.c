/* 
 * File:   motion.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 17:20
 */

#include "motion.h"

void l_speed(short_t speed, bool backwards) {
    CCPR1L = speed;
    if (backwards) {
        M_LEFT_BACK = 1;
        M_LEFT_FORWARD = 0;
    } else {
        M_LEFT_BACK = 0;
        M_LEFT_FORWARD = 1;
    }
}

void r_speed(short_t speed, bool backwards) {
    CCPR2L = speed;
    if (backwards) {
        M_RIGHT_BACK = 1;
        M_RIGHT_FORWARD = 0;
    } else {
        M_RIGHT_BACK = 0;
        M_RIGHT_FORWARD = 1;
    }
}

void forwards(short_t speed) {
    l_speed(speed, false);
    r_speed(speed, false);
}

void backwards(short_t speed) {
    l_speed(speed, true);
    r_speed(speed, true);
}

void left(short_t speed) {
    l_speed(speed, true);
    r_speed(speed, false);
}

void right(short_t speed) {
    l_speed(speed, false);
    r_speed(speed, true);
}

void stop(void) {
    M_RIGHT_BACK = 1;
    M_RIGHT_FORWARD = 1;
    M_LEFT_BACK = 1;
    M_LEFT_FORWARD = 1;
}

void avoid_obstacle(short_t speed) {
    backwards(speed);
    delay10ms(200);
    
    left(speed);
    delay10ms(64);
    
    forwards(speed);
    delay10ms(200);
    
    right(speed);
    delay10ms(64);
    
    forwards(speed);
    delay10ms(200);
}

void test(Encoder_t* encoder) {
    left(64);
    while (encoder->left < 8192) {
        detect_encoder_change(encoder);
    }
    stop();
}