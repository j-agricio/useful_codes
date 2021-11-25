/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  dsPIC33EP64GP506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.61
        MPLAB 	          :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/watchdog.h"


void delay_ms(unsigned int n);
/*
                         Main application
 
 * Summary: Uses is enabled but not cleared
 * then it resets the MCU
 * 
 
 */
int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    LED2_SetHigh();
    LED3_SetHigh();
    delay_ms(1000);
    WATCHDOG_TimerSoftwareEnable();
    while (1)
    {
        LED2_SetHigh();
        LED3_SetHigh();
        delay_ms(125);
        LED2_SetLow();
        LED3_SetLow();
        delay_ms(125);
    }
    return 1; 
}
/**
 End of File
*/

void delay_ms(unsigned int n)
{
    /*
    uint16_t count_ms = 0;
        
    while(count_ms < n)
    {
        T3CONbits.TON = 1;
        while(IFS0bits.T3IF == 0);
        IFS0bits.T3IF = 0;
        count_ms++;        
    }   
    
    T3CONbits.TON = 0;
    */
    uint16_t i, j;
    
    for (i = 0; i < n; i++)
    {
        //for (j = 0; j < 7; j++)            // FCY=7mhz => 7x1000 =~ 1ms
        for (j = 0; j < 60; j++)            // FCY=60mhz => 60x1000 =~ 1ms
        {
            asm volatile ("REPEAT, #1000"); 
            Nop();
        }
    }
}
