/* 
 * File:   utils.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 25 November 2024, 18:52
 * 
 * Miscellaneous helper functions, definitions, etc.
 */

#ifndef MISC_H
#define	MISC_H

#include <stdbool.h>

// DEBUG
#define NO_MOVEMENT false
#define NO_BEACON true
#define NO_IR false

#define OBSTACLE_THRESHOLD 400
#define TURN_SPEED 100
#define FORWARD_SPEED 128

// Defining this because it's more succinct and descriptive than unsigned char
typedef unsigned char short_t;
typedef unsigned int uint_t;

// For storing if the beacon is detected and if an obstacle is detected in a convenient way
// which only takes up xx bits, and because I wanted to faff around with bitfields

typedef union {
    struct {
        bool left       :1;
        bool right      :1;
    };
    short_t value;
} Ir_t;
        
typedef union {
    struct {
        bool left       :1;
        bool right      :1;
    };
    short_t value;
} Beacon_t;

typedef union {
    struct {
        short_t left    :8;
        short_t right   :8;
        short_t r_state :1;
        short_t l_state :1;
    };
    struct {
        unsigned        
        :8;
        unsigned        :8;
        short_t state   :2;
    };
} Encoder_t;

typedef union {
    struct {
        Ir_t ir;
        Beacon_t beacon;
        Encoder_t encoder;
    };
    short_t all;
} Sensors_t;

#endif	/* MISC_H */
