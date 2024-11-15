/* 
 * File:   sensing.h
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 18:02
 */

#include <xc.h>

#include "sensing.h"

int read_adc(unsigned char sensor) {
    ADCON0bits.CHS0 = sensor;
    ADCON0bits.CHS &= 0b1000; // Set the bits that aren't the one we care about to 0
    ADCON0bits.GO = 1;
    
    while (ADCON0bits.GO); // Do nothing for the duration of the conversion
    return ((ADRESH << 8) + ADRESL); // Concatenate returned values into one 16b number
}