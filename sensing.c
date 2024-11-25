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

// Return which, if any, sensors detected an obstacle within the threshold
short_t detect_obstacle(int threshold) {
    short_t result = 0b00;
    
    if (read_adc(LEFT_IR) > threshold) {
        result |= 0b01; // Set the flag for the left sensor
    }
    if (read_adc(RIGHT_IR) > threshold) {
        result |= 0b10; // Set the flag for the right sensor
    }
    
    return result;
}