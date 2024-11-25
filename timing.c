/* 
 * File:   timing.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 11:38
 */

#include <xc.h>

#include "timing.h"

void delay10ms(short_t multiplier) {
    for (short_t i = 0; i < multiplier; i++) {
        /*
         * I hate that __delay_ms() is a macro because it means we have to pass in
         * a constant value rather than a variable.
         * This is extra annoying because the 10 we pass in gets cast to an unsigned
         * long and uses up a whole 32b of memory!!
         */
        __delay_ms(10);
    }
}
