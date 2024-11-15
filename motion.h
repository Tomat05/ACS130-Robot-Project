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

#define M_RIGHT_BACK LATBbits.LB0
#define M_RIGHT_FORWARD LATBbits.LB1

#define M_LEFT_BACK LATAbits.LA4
#define M_LEFT_FORWARD LATAbits.LA5

#define LEFT 0
#define RIGHT 1

void l_speed(unsigned char speed, bool backwards);
void r_speed(unsigned char speed, bool backwards);

void forwards(unsigned char speed);
void backwards(unsigned char speed);
void left(unsigned char speed);
void right(unsigned char speed);
void stop(void);

#endif	/* MOTION_H */

