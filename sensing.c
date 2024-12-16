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
//    _set_leds((((ADRESH << 8) + ADRESL) / 64) - 1);
    return ((ADRESH << 8) + ADRESL); // Concatenate returned values into one 16b number
}

// Return which, if either, of the IR sensors detected an obstacle within the threshold
void detect_obstacle(Sensors_t* sensors, int threshold) {
    if (read_adc(LEFT) > threshold) {
        sensors->IR_L = true;
    }
    if (read_adc(RIGHT) > threshold) {
        sensors->IR_R = true;
    }
}

void detect_beacon(Sensors_t* sensors) {
//    sensors->BE = ~((PORTAbits.RA2 << 1) | PORTAbits.RA3);
    sensors->BE_L = !(PORTAbits.RA2);
    sensors->BE_R = !(PORTAbits.RA3);
}