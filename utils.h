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
typedef union {
    struct {
        short_t IR_L    :1;
        short_t IR_R    :1;
        short_t BE_L    :1;
        short_t BE_R    :1;
        short_t EN_L    :1;
        short_t EN_R    :1;
    };
    struct {
        short_t IR      :2;
        short_t BE      :2;
        short_t EN      :2;
    };
    short_t all;
} State_t;

#endif	/* MISC_H */

