/* 
 * File:   utils.h
 * Author: Thomas Wetherill
 *
 * Created on 25 November 2024, 18:52
 * 
 * Miscellaneous helper functions, definitions, etc.
 */

#ifndef MISC_H
#define	MISC_H

#include <stdbool.h>

// Defining this because it's more succinct and descriptive than unsigned char
typedef unsigned char short_t;

// For storing if the beacon is detected and if an obstacle is detected in a convenient way
// which only takes up xx bits, and because I wanted to faff around with bitfields

typedef union {
    struct {
        bool left   :1;
        bool right  :1;
    };
    short_t value;
} Ir_t;
        
typedef union {
    struct {
        bool left   :1;
        bool right  :1;
    };
    short_t value;
} Beacon_t;

typedef union {
    struct {
        unsigned int left;
        unsigned int right;
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
