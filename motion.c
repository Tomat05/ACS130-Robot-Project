/* 
 * File:   motion.c
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
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

void turn(short_t speed, bool right) {
    l_speed(speed, !right);
    r_speed(speed, right);
}

void turn_90(Sensors_t* sensors, bool right) {
    turn(TURN_SPEED, right);
    while (sensors->encoder.right < HALF_ROTATION && sensors->encoder.left < HALF_ROTATION) {
        detect_encoder_change(&sensors->encoder);
#if defined(FINDING_BEACON)
        // If at any point during the rotation, one or both of the beacon sensors
        // are off, we know that we aren't right next to the beacon.
        if (sensors->ir.value != 0b11) {
            return; // TODO: THIS IS STUPID AND DOESN'T WORK
        }
#endif
    }
    sensors->encoder.left = sensors->encoder.right = 0;
}

void stop(void) {
    M_RIGHT_BACK = 1;
    M_RIGHT_FORWARD = 1;
    M_LEFT_BACK = 1;
    M_LEFT_FORWARD = 1;
}

void avoid_obstacle(Sensors_t* sensors) {
    backwards(FORWARD_SPEED / 2);
    delay10ms(128);
    
    at_beacon(sensors);
    
    forwards(FORWARD_SPEED / 2);
    delay10ms(128);
    
    turn_90(&sensors->encoder, false);
    
    forwards(FORWARD_SPEED);
    delay10ms(50);
}

void at_beacon(Sensors_t* sensors) {
    for (short_t i = 0; i < 3; i++) {
#define FINDING_BEACON
        turn_90(sensors, RIGHT);
#undef FINDING_BEACON
    }
    stop();
    flash(3, 50);
    for (;;); // Do nothing indefinitely
}