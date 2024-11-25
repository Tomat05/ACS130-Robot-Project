/* 
 * File:   setup.c
 * Author: Thomas Wetherill
 *
 * Created on 12 November 2024, 17:23
 * 
 * The implementation of `setup.h`
 */

#include "setup.h"

void setup_io(void) {
    // Set I/O
    TRISA = 0b00000000;
    TRISB = 0b00000000;
    TRISC = 0b00000000;
    
    // Set all outputs to 0 just in case
    LATA = 0;
    LATB = 0;
    LATC = 0;
}

void setup_pwm(void) {
    PR2 = 255; // Set period of PW
    T2CON = 0b00000111; // Timer 2 on, Prescaler = 1
    
    CCP1CON = 0x0c;
    CCP2CON = 0x0c;
}

void setup_adc(void) {
    ADCON2bits.ADCS = 0b010; // Set conversion clock
    ADCON1 = 0b00001101; // Set ref voltage & set AN0, AN1 to A/D
    ADCON0bits.ADON = 1; // Turn on ADC
}