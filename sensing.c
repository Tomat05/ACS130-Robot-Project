/* 
 * File:   sensing.h
 * Author: Thomas Wetherill, Matt Smith, Josiah de Grey-Warter
 *
 * Created on 12 November 2024, 18:02
 * 
 * The implementation for `sensing.h`
 */

#include <xc.h>
#include <limits.h>

#include "sensing.h"

int read_adc(short_t sensor) {
    // Set the channel to the correct sensor
    ADCON0bits.CHS = sensor;
    ADCON0bits.GO = 1;
    
    while (ADCON0bits.GO); // Do nothing for the duration of the conversion
    return ((ADRESH << 8) + ADRESL); // Concatenate returned values into one 16b number
}

// Return which, if either, of the IR sensors detected an obstacle within the threshold
void detect_obstacle(Ir_t* ir, int threshold) {
    if (read_adc(LEFT) > threshold) {
        ir->left = true;
    }
    if (read_adc(RIGHT) > threshold) {
        ir->right = true;
    }
}

void detect_beacon(Beacon_t* beacons) {
    beacons->left = !(PORTAbits.RA2);
    beacons->right = !(PORTAbits.RA3);
}

void detect_encoder_change(Encoder_t* encoders) {    
    if (PORTCbits.RC0 != encoders->l_state) {
        encoders->left = (encoders->left + 1) % (HALF_ROTATION + 1);
        encoders->l_state = PORTCbits.RC0;
    }
    if (PORTCbits.RC5 != encoders->r_state) {
        encoders->right = (encoders->right + 1) % (HALF_ROTATION + 1);
        encoders->r_state = PORTCbits.RC5;
    }
}