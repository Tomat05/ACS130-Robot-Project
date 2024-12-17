/* 
 * File:   timing.c
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 12 November 2024, 11:38
 */

#include <xc.h>

#include "timing.h"

void delay10ms(short_t multiplier) {
    for (short_t i = 0; i < multiplier; i++) {
        __delay_ms(10);
    }
}
