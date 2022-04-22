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

enum state_e     {start, move_to_sample, stay_on_sample, move_from_sample, stay_off_sample};
enum direction_e {to_sample = 1, from_sample = 0};

const int total_steps     = 1450;

const int start_delay     = 750;
const int min_speed_delay = 700;
const int max_speed_delay = 250;

 //255 for full power (maximum of 4V) and 0 for the least power (0V)
const int max_vdac_power = 245;
const int min_vdac_power = 0; 

const int always_enable_leds = 1; 

int main(void)
{
    // Starting the DAC used for leds display of magnets location
    // As the magnet is closer to the sample more leds will turn up. 
    VDAC8_1_Start();
    
    int  current_delay;
    int  current_step = 0;
    // Indicates if the current state is the first time the magnet moves, 
    // if so, we can't predict the starting location and therefore moving at 
    // minimal speed.
    int  first_moving_state; 
    enum direction_e direction = from_sample;
    enum state_e     state     = start;
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    Opamp_1_Start();
    Opamp_1_Init();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    
    for(;;)
    {
        direction = operation_input_Read();
        
        switch(state){
            case start:
                // On the start state we will always go away from the sample
                // regardless of direction input.
                if (direction == from_sample){
                    state = move_from_sample;
                } else{
                    state = move_to_sample;
                }
                first_moving_state = 1;
                break;

            case move_to_sample:
                direction_out_Write(to_sample);
                pulse_out_Write(~ pulse_out_Read());
                if (first_moving_state == 1){
                    current_delay = start_delay;
                    first_moving_state = 0;
                } else{
                    // The magnet is on the left sensor and needs to move to the right one.
                    VDAC8_1_SetValue(max_vdac_power);
                    if (current_step < total_steps){
                        VDAC8_1_SetValue(max_vdac_power - (int)(current_step*max_vdac_power/total_steps));
                        if (current_step > total_steps - 50){
                            leds_enable_Write(always_enable_leds);
                        } else{
                            leds_enable_Write(1);
                        }
                        
                        current_delay = abs(725-current_step);
                        if (current_delay > min_speed_delay){
                            current_delay = min_speed_delay;
                        }
                        if (current_delay < max_speed_delay){
                            current_delay = max_speed_delay;
                        }
                        

                        CyDelayUs(current_delay);
                    } else{ // Passed the total steps
                        
                    }
                    if (sensor_right_Read() == 0){
                        current_step = 0;
                        state = stay_on_sample;
                    }
                }
              break;
            
            case stay_on_sample:
              break;
            
            case move_from_sample:
                
              first_moving_state = 0;
              break;
            
            case stay_off_sample:
              // statements
              break;
        }
    }
    
    
    
    
    
    
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
                        VDAC8_1_SetValue((int)(i*max_vdac_power/total_steps));
                        if (i < 50)
                            leds_enable_Write(0 + always_enable_leds);
                        else
                            leds_enable_Write(1);
                            
                            
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
                else // sensor_right_Read() == 1
                {
                    // The magnet is in the middle and needs to move to the left sensor.
                    direction_out_Write(operation_input_Read());
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(start_delay);
                }
            }
            else // sensor_left_Read() == 0
            // The magnet is on the left.
            {
                VDAC8_1_SetValue(max_vdac_power);
            }
        }
        else // operation_input_Read() == 1.
        {
            if (sensor_right_Read() == 1)
            {
                if (sensor_left_Read() == 0)
                {
                    // The magnet is on the left sensor and needs to move to the right one.
                    direction_out_Write(1);
                    VDAC8_1_SetValue(max_vdac_power);
                    for (int i=0;i<total_steps;i++)
                    {
                        VDAC8_1_SetValue(max_vdac_power - (int)(i*max_vdac_power/total_steps));
                        if (i > total_steps - 50)
                            leds_enable_Write(0 + always_enable_leds);
                        else
                            leds_enable_Write(1);
                            
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
                    // direction_out_Write(operation_input_Read());
                    direction_out_Write(operation_input_Read());
                    pulse_out_Write(~ pulse_out_Read());
                    CyDelayUs(start_delay);
                }
            }
            else 
            // The magnet is on the smaple.
            {
                VDAC8_1_SetValue(0);
                leds_enable_Write(0 + always_enable_leds);
            }
        }
    }
}

/* [] END OF FILE */
