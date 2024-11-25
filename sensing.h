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

#include "misc.h"

#define RIGHT_IR 0b0001
#define LEFT_IR 0b0000

int read_adc(short_t sensor);

short_t detect_obstacle(int threshold);

#endif	/* SENSING_H */

