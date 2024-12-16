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

// The left and right IR sensors ADN0 and ADN1
#define LEFT 0
#define RIGHT 1

int read_adc(short_t sensor);

void detect_obstacle(Sensors_t* sensor, int threshold);
void detect_beacon(Sensors_t* sensor);

#endif	/* SENSING_H */

