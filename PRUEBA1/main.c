/*
 * File:   main.c
 * Author: ANGELA
 *
 * Created on 29 de agosto de 2023, 11:43
 */

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)
// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>
#include <stdio.h>
#include "USART.h"
#include "MPUu.h"
#include "I2C.h"

//VARIABLES
#define _XTAL_FREQ 8000000

//Ciclo principal
void main(void) {
    
    UART_TX_Init();
    TRISD2 = 0; //Led indicador
    TRISB = 0;//Leds conectadas para demostrar la variable ay
    ANSELH = 0;
    
    MPU6050_Init();
    //Loop Principal
    while(1)
    {
        RD2 = ~RD2; //Blink Led verde
        MPU6050_Read();
        __delay_ms(50);   
    }
    return;
}
//Se hizo con oscilador externo al inicio pero no era tan estable y mejor se hizo con uno interno

