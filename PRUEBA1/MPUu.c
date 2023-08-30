#include <xc.h>
#include "USART.h"
#include "MPUu.h"
#include "I2C.h"
#include <stdio.h>

//MPU6059 routines
void MPU6050_Init()
{
    //Power up delay & I2C_Init
    __delay_ms(100);
    I2C_Master_Init();
    
    //Setting the sample data rate
    I2C_Start(0xD0);
    I2C_Master_Write(SMPLRT_DIV);
    I2C_Master_Write(0x07);
    I2C_Master_Stop();
    
    //Setting the clock source
    I2C_Start(0xD0);
    I2C_Master_Write(PWR_MGMT_1);
    I2C_Master_Write(0x01);
    I2C_Master_Stop();
    
    //Configura el DLPF
    I2C_Start(0xD0);
    I2C_Master_Write(CONFIG);
    I2C_Master_Write(0x00);
    I2C_Master_Stop();
    
    //COnfig the ACCEL
    I2C_Start(0xD0);
    I2C_Master_Write(ACCEL_CONFIG);
    I2C_Master_Write(0x00);
    I2C_Master_Stop();
    
    //COnfig the GYRO
    I2C_Start(0xD0);
    I2C_Master_Write(GYRO_CONFIG);
    I2C_Master_Write(0x18);
    I2C_Master_Stop();
    
    //Enable data ready interrupts
    I2C_Start(0xD0);
    I2C_Master_Write(INT_ENABLE);
    I2C_Master_Write(0x01);
    I2C_Master_Stop();
   
}

void MPU6050_Read()
{
    char buffer[40];
    int Ax, Ay, Az, T, Gx, Gy, Gz;
    //Prepare for reading
    I2C_Start(0xD0);
    I2C_Master_Write(ACCEL_XOUT_H);
    I2C_Master_Stop();
    I2C_Start(0xD1);
    Ax = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    Ay = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    Az = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    T = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    Gx = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    Gy = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    Gz = ((int)I2C_Read(0)<<8) | (int)I2C_Read(0);
    I2C_Master_Stop();
    
    PORTB = (Ay+16384)/128; //COnversion para los datos de la variable ay del acelerometro
    
    sprintf(buffer, "Ay = %d   ", Ay);
    UART_write_string(PORTB);
}

