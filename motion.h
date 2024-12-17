/* 
 * File:   motion.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 12 November 2024, 17:21
 */

#ifndef MOTION_H
#define	MOTION_H

#include <xc.h>
#include <stdbool.h>

#include "utils.h"
#include "timing.h"
#include "sensing.h"
#include "led.h"

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
void turn(short_t speed, bool left);
void turn_90(Encoder_t* encoder, bool left);
void stop(void);

void avoid_obstacle(Sensors_t* sensors);
void at_beacon(Sensors_t* sensors);

void test(Encoder_t* encoder);

#endif	/* MOTION_H */

