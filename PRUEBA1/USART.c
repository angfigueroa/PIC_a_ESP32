#include <xc.h>
#include "USART.h"

void UART_TX_Init(void)
{
    BRGH = 0;
    SPBRG = 12;
    SYNC = 0;
    SPEN = 1;
    TX_D = 1;
    RX_D = 1;
    TXEN = 1;
}

void UART_Write(unsigned char data)
{
    while(!TRMT);
    TXREG = data;
}

void UART_write_string(char txt[]){
    for (uint8_t i = 0; txt[i] != '\0'; i++){               //Recorrer el string y mostrarlo en
        UART_Write(txt[i]);
    }
}
