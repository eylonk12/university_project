/* ========================================
 *
 * Copyright University Of Ben Gurion Of The Negev, 2022
 * All Rights Reserved to Eylon Kapel and Raam Kavod
 * ========================================
*/

/*
This code's purpose is to control the position of a model on a strip, while indicating it's position with LEDs.
The closer the model will get to the sample, more LEDs will turn up.

Inputs:
1)Sensors : 1 = not in sensor's position, 0 = in sensor's position. There are 2 sensore, left and middle.
2)Operation : 1 = middle , 0 = left

Outputs:
1)Directions : 1 = middle and 0 = left
2)Pulse      : Mode1 - constant: direction (To left or to middle)
               Mode2 - PWM: velocity
*/
            

#include "project.h"
#include <stdio.h>
#include <stdlib.h>


// Parameters and variables.
int total_steps = 1450; // Total stepper motor steps from left to middle.
int current_delay; // A variable which'll determine the current delay to state the velocity.  
int min_speed_delay = 700; // Delay for min speed in micro seconds
int max_speed_delay = 250; // Delay for max speed in micro seconds
int max_delay = 750; // Delay for the slowest speed defined, for situation of unknown position.
int max_vdac_power = 245; // The maximum voltage defined for the LEDs output (Max for 5V is 256 but it is too much)
int always_enable_leds = 1; // a constant for the posibility to always enable the LEDs


int main(void)
{ 
    //Init
    VDAC8_1_Start(); // Starting the DAC, to activate the LEDs display.
    CyGlobalIntEnable; // Enable global interrupts.
    Opamp_1_Start(); // Actication of operetional amplifier stage 1
    Opamp_1_Init(); // Actication of operetional amplifier stage 2

    for(;;)
    {
        if (operation_input_Read() == 0)  // If requested position is left. (Away from sample)
        {
            if (sensor_left_Read() == 1) // If current position isn't left.
            {
                if (sensor_right_Read() == 0) // If current position is middle.
                {
                    direction_out_Write(0); // Go left.
                    VDAC8_1_SetValue(0); // Set LEDs volatge to 0V.
                    for (int i=0;i<total_steps;i++)
                    {
                        VDAC8_1_SetValue((int)(i*max_vdac_power/total_steps));
                        if (i < 50)
                            leds_enable_Write(always_enable_leds);
                        else
                            leds_enable_Write(1);
                            
                            
                        if (sensor_left_Read() == 0) // If the model arrived to the requested posiiton (left).
                            break;
                        pulse_out_Write(~ pulse_out_Read());  // Toggle until arrival to requested potision.
                        current_delay = abs(total_steps/2 - i); // Set delay in micro seconds to set velocity (acceleration).
                        if (current_delay > min_speed_delay)
                            current_delay = min_speed_delay; // Limit of maximum delay
                        if (current_delay < max_speed_delay)
                            current_delay = max_speed_delay; // Limit of minimum delay
                        
                        CyDelayUs(current_delay); // Delay in micro sconds 
                    }
                }
                else // If somewhere between left and middle.
                {
                    direction_out_Write(0); // Go left.
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(max_delay); // For slowest defined velocity. 
                }
            }
            else // If the magnet is already on the left.
            {
                VDAC8_1_SetValue(max_vdac_power);
            }
        }
        else // If requested position is middle (Close to the sample).
        {
            if (sensor_right_Read() == 1) // If current position isn't middle.
            {
                if (sensor_left_Read() == 0) // If current position is left.
                {
                    direction_out_Write(1); // Go right.
                    VDAC8_1_SetValue(max_vdac_power);
                    for (int i=0;i<total_steps;i++)
                    {
                        VDAC8_1_SetValue(max_vdac_power - (int)(i*max_vdac_power/total_steps));
                        if (i > total_steps - 50)
                            leds_enable_Write(always_enable_leds);
                        else
                            leds_enable_Write(1);
                            
                        if (sensor_right_Read() == 0) // If the model arrived to the requested posiiton (middle).
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
                else // If somewhere between left and middle.
                {
                    direction_out_Write(1); //Go right.
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(max_delay);
                }
            }
            else  // If the model is already on the middle.
            {
                VDAC8_1_SetValue(0);
                leds_enable_Write(always_enable_leds);
            }
        }
    }
}

/* [] END OF FILE */

