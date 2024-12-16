/* 
 * File:   motion.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 17:21
 */

#ifndef MOTION_H
#define	MOTION_H

#include <xc.h>
#include <stdbool.h>

#include "utils.h"
#include "timing.h"

#define M_RIGHT_BACK LATBbits.LB0
#define M_RIGHT_FORWARD LATBbits.LB1

#define M_LEFT_BACK LATAbits.LA4
#define M_LEFT_FORWARD LATAbits.LA5

#define LEFT 0
#define RIGHT 1

void l_speed(short_t speed, bool backwards);
void r_speed(short_t speed, bool backwards);

void forwards(short_t speed);
void backwards(short_t speed);
void left(short_t speed);
void right(short_t speed);
void stop(void);

void avoid_obstacle(short_t speed);
void find_beacon(void);


#endif	/* MOTION_H */

