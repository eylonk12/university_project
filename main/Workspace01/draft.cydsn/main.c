/* ========================================
 *
 * Copyright Ben Gurion University Israel, 2022
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/


#include "project.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int total_steps = 1445;
    int delay = 425;
    int enable = 1;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if (sensor_left_Read() == 0 && enable == 1)
        {
            for (int i=0;i<total_steps;i++)
            {
                direction_out_Write(1);
                pulse_out_Write(~ pulse_out_Read());
                CyDelayUs(delay);
            }
            enable = 0;
        }
        
        if (sensor_right_Read() == 1)
        {
            while(sensor_left_Read() == 1)
            {
                direction_out_Write(0);
                pulse_out_Write(~ pulse_out_Read());
                CyDelayUs(delay);
            }
        }
        
            
    }
}

/* [] END OF FILE */
