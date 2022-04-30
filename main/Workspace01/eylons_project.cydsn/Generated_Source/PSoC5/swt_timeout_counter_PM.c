/*******************************************************************************
* File Name: swt_timeout_counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "swt_timeout_counter.h"

static swt_timeout_counter_backupStruct swt_timeout_counter_backup;


/*******************************************************************************
* Function Name: swt_timeout_counter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  swt_timeout_counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void swt_timeout_counter_SaveConfig(void) 
{
    #if (!swt_timeout_counter_UsingFixedFunction)

        swt_timeout_counter_backup.CounterUdb = swt_timeout_counter_ReadCounter();

        #if(!swt_timeout_counter_ControlRegRemoved)
            swt_timeout_counter_backup.CounterControlRegister = swt_timeout_counter_ReadControlRegister();
        #endif /* (!swt_timeout_counter_ControlRegRemoved) */

    #endif /* (!swt_timeout_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: swt_timeout_counter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  swt_timeout_counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void swt_timeout_counter_RestoreConfig(void) 
{      
    #if (!swt_timeout_counter_UsingFixedFunction)

       swt_timeout_counter_WriteCounter(swt_timeout_counter_backup.CounterUdb);

        #if(!swt_timeout_counter_ControlRegRemoved)
            swt_timeout_counter_WriteControlRegister(swt_timeout_counter_backup.CounterControlRegister);
        #endif /* (!swt_timeout_counter_ControlRegRemoved) */

    #endif /* (!swt_timeout_counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: swt_timeout_counter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  swt_timeout_counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void swt_timeout_counter_Sleep(void) 
{
    #if(!swt_timeout_counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(swt_timeout_counter_CTRL_ENABLE == (swt_timeout_counter_CONTROL & swt_timeout_counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            swt_timeout_counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            swt_timeout_counter_backup.CounterEnableState = 0u;
        }
    #else
        swt_timeout_counter_backup.CounterEnableState = 1u;
        if(swt_timeout_counter_backup.CounterEnableState != 0u)
        {
            swt_timeout_counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!swt_timeout_counter_ControlRegRemoved) */
    
    swt_timeout_counter_Stop();
    swt_timeout_counter_SaveConfig();
}


/*******************************************************************************
* Function Name: swt_timeout_counter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  swt_timeout_counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void swt_timeout_counter_Wakeup(void) 
{
    swt_timeout_counter_RestoreConfig();
    #if(!swt_timeout_counter_ControlRegRemoved)
        if(swt_timeout_counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            swt_timeout_counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!swt_timeout_counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
