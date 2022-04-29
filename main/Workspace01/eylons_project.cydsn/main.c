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

int  current_delay;
int  current_step = 0;
// Indicates if the current state is the first time the magnet moves, 
// if so, we can't predict the starting location and therefore moving at 
// minimal speed.
int  first_moving_state; 
enum direction_e direction = from_sample;
enum state_e     state     = start;

int main(void)
{
    // Starting the DAC used for leds display of magnets location
    // As the magnet is closer to the sample more leds will turn up. 
    VDAC8_1_Start();
    
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    PWM_1_Start();
    Opamp_1_Start();
    Opamp_1_Init();
    
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
                } else{ // The magnet is on the left sensor and needs to move to the right one.
                    if (current_step < total_steps){
                        VDAC8_1_SetValue(max_vdac_power - (int)(current_step*max_vdac_power/total_steps));
                        if (current_step > total_steps - 50){
                            leds_enable_Write(always_enable_leds);
                        } else{
                            leds_enable_Write(1);
                        }
                        
                        current_delay = abs((total_steps/2)-current_step);
                        if (current_delay > min_speed_delay){
                            current_delay = min_speed_delay;
                        }
                        if (current_delay < max_speed_delay){
                            current_delay = max_speed_delay;
                        }
                    } else{ // Passed the total steps, we assume that if we reach here we are close to the sample.
                        current_delay = min_speed_delay;
                    }
                    current_step++;
                }
                CyDelayUs(current_delay);
                if (sensor_right_Read() == 0){
                        current_step = 0;
                        state = stay_on_sample;
                    }
              break;
            
            case stay_on_sample:
                if (direction == from_sample){
                    first_moving_state = 0;
                    state = move_from_sample;
                }
              break;
            
            case move_from_sample:
                direction_out_Write(from_sample);
                pulse_out_Write(~ pulse_out_Read());
                if (first_moving_state == 1){
                    current_delay = start_delay;
                } else{ // The magnet is on the right sensor and needs to move to the left one.
                    if (current_step < total_steps){
                        VDAC8_1_SetValue((int)(current_step*max_vdac_power/total_steps));
                        if (current_step < 50){
                            leds_enable_Write(always_enable_leds);
                        } else{
                            leds_enable_Write(1);
                        }
                        
                        current_delay = abs((total_steps/2)-current_step);
                        if (current_delay > min_speed_delay){
                            current_delay = min_speed_delay;
                        }
                        if (current_delay < max_speed_delay){
                            current_delay = max_speed_delay;
                        }
                    } else{ // Passed the total steps, we assume that if we reach here we are close to the sample.
                        current_delay = min_speed_delay;
                    }
                    current_step++;
                }
                CyDelayUs(current_delay);
                if (sensor_left_Read() == 0){
                        current_step = 0;
                        state = stay_off_sample;
                    }
              break;
            
            case stay_off_sample:
              if (direction == to_sample){
                    first_moving_state = 0;
                    state = move_to_sample;
                }
              break;
        }
    }
}
 

/* [] END OF FILE */
