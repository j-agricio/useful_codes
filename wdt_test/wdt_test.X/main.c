/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/watchdog.h"

#define FCY 60000000UL
#include "libpic30.h"
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
    __delay_ms(1000);
    WATCHDOG_TimerSoftwareEnable();
    while (1)
    {
        LED2_SetHigh();
        LED3_SetHigh();
        __delay_ms(125);
        LED2_SetLow();
        LED3_SetLow();
        __delay_ms(125);
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
