/* 
 * File:   sensing.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 18:02
 * 
 * Functions and definitions relating to the sensors on the robot
 */

#ifndef SENSING_H
#define	SENSING_H

#include <stdbool.h>

#include "utils.h"
#include "led.h"

// Just to give the bitmasks meaningful names
#define IR_MASK 0b1001
#define BEACON_MASK 0b0110

#define LEFT 0
#define RIGHT 1

int read_adc(short_t sensor);

void detect_obstacle(State_t* state, int threshold);

#endif	/* SENSING_H */

