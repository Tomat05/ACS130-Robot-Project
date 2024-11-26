/* 
 * File:   sensing.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 18:02
 * 
 * The implementation for `sensing.h`
 */

#include <xc.h>

#include "sensing.h"

int read_adc(short_t sensor) {
    // Set the channel to the correct sensor
    ADCON0bits.CHS = sensor;
    ADCON0bits.GO = 1;
    
    while (ADCON0bits.GO); // Do nothing for the duration of the conversion
    return ((ADRESH << 8) + ADRESL); // Concatenate returned values into one 16b number
}

// Return which, if either, of the IR sensors detected an obstacle within the threshold
void detect_obstacle(State_t* state, int threshold) {
    if (read_adc(LEFT) > threshold) {
        state->IR_L = true;
    }
    if (read_adc(RIGHT) > threshold) {
        state->IR_R = true;
    }
}