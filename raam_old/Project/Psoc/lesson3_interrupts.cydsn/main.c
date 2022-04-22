/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"


CY_ISR( sw1_handler )
{
    led_Write( ~led_Read());
    CyDelay(200);
    led_Write( ~led_Read());
    CyDelay(200);
    led_Write( ~led_Read());
    CyDelay(200);
     led_Write( ~led_Read());
    CyDelay(200);
    led_Write( ~led_Read());
    CyDelay(200);
    led_Write( ~led_Read());
    CyDelay(200);
    
    sw1_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    sw1_Int_StartEx(sw1_handler);
    
   
      
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
      /* Place your application code here. */
    }
}

/* [] END OF FILE */
