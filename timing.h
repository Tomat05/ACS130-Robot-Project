/* 
 * File:   timing.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 12 November 2024, 11:38
 * 
 * Functions for timing things
 */

#ifndef TOOLS_H
#define	TOOLS_H

#include "utils.h"

// This lives here because if I try to put it anywhere else the compiler throws a fit
#define _XTAL_FREQ 10000000

void delay10ms(short_t multiplier);

#endif