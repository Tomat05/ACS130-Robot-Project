/* 
 * File:   setup.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 12 November 2024, 17:23
 * 
 * Functions and definitions relating to setting up the various registers on the chip
 */

#ifndef SETUP_H
#define	SETUP_H

#include <xc.h>

void setup_io(void);
void setup_pwm(void);
void setup_adc(void);

#endif	/* SETUP_H */

