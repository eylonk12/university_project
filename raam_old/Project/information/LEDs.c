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
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Starting the DAC used for leds display of magnets location
    // As the magnet is closer to the sample more leds will turn up. 
    VDAC8_1_Start();
    //total steps are 1445;
    int total_steps = 1450;
    //int middle_steps = 725;
    
    int current_delay;
    int min_speed_delay = 700;
    int max_speed_delay = 250;
    
    int big_delay = 750;
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        if (operation_input_Read() == 0)
        {
            if (sensor_left_Read() == 1)
            {
                if (sensor_right_Read() == 0)
                {
                    // The magnet is on the right sensor (sample) and needs to move to the left one.
                    direction_out_Write(0);
                    VDAC8_1_SetValue(0);
                    for (int i=0;i<total_steps;i++)
                    {
                        VDAC8_1_SetValue((int)(i*255/total_steps));
                        if (sensor_left_Read() == 0)
                            break;
                        pulse_out_Write(~ pulse_out_Read());
                        current_delay = abs(725-i);
                        if (current_delay > min_speed_delay)
                            current_delay = min_speed_delay;
                        if (current_delay < max_speed_delay)
                            current_delay = max_speed_delay;
                        
                        CyDelayUs(current_delay);
                    }
                }
                else
                {
                    // The magnet is in the middle and needs to move to the left sensor.
                    direction_out_Write(operation_input_Read());
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(big_delay);
                }
            }
            else
            // The magnet is on the left.
            {
                VDAC8_1_SetValue(255);
            }
        }
        else 
        {
            if (sensor_right_Read() == 1)
            {
                if (sensor_left_Read() == 0)
                {
                    // The magnet is on the left sensor and needs to move to the right one.
                    direction_out_Write(1);
                    VDAC8_1_SetValue(255);
                    for (int i=0;i<total_steps;i++)
                    {
                        VDAC8_1_SetValue(255 - (int)(i*255/total_steps));
                        if (sensor_right_Read() == 0)
                            break;
                        pulse_out_Write(~ pulse_out_Read());
                        current_delay = abs(725-i);
                        if (current_delay > min_speed_delay)
                            current_delay = min_speed_delay;
                        if (current_delay < max_speed_delay)
                            current_delay = max_speed_delay;
                        
                        CyDelayUs(current_delay);
                    }
                }
                else
                {
                    // The magnet is in the middle and needs to move to the right sensor.
                    direction_out_Write(operation_input_Read());
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(big_delay);
                }
            }
            else 
            // The magnet is on the smaple.
            {
                VDAC8_1_SetValue(0);
            }
        }
    }
}

/* [] END OF FILE */
