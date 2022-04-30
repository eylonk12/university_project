/*******************************************************************************
* File Name: PWM_swt_mode_select_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_swt_mode_select.h"

static PWM_swt_mode_select_backupStruct PWM_swt_mode_select_backup;


/*******************************************************************************
* Function Name: PWM_swt_mode_select_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_swt_mode_select_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_swt_mode_select_SaveConfig(void) 
{

    #if(!PWM_swt_mode_select_UsingFixedFunction)
        #if(!PWM_swt_mode_select_PWMModeIsCenterAligned)
            PWM_swt_mode_select_backup.PWMPeriod = PWM_swt_mode_select_ReadPeriod();
        #endif /* (!PWM_swt_mode_select_PWMModeIsCenterAligned) */
        PWM_swt_mode_select_backup.PWMUdb = PWM_swt_mode_select_ReadCounter();
        #if (PWM_swt_mode_select_UseStatus)
            PWM_swt_mode_select_backup.InterruptMaskValue = PWM_swt_mode_select_STATUS_MASK;
        #endif /* (PWM_swt_mode_select_UseStatus) */

        #if(PWM_swt_mode_select_DeadBandMode == PWM_swt_mode_select__B_PWM__DBM_256_CLOCKS || \
            PWM_swt_mode_select_DeadBandMode == PWM_swt_mode_select__B_PWM__DBM_2_4_CLOCKS)
            PWM_swt_mode_select_backup.PWMdeadBandValue = PWM_swt_mode_select_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_swt_mode_select_KillModeMinTime)
             PWM_swt_mode_select_backup.PWMKillCounterPeriod = PWM_swt_mode_select_ReadKillTime();
        #endif /* (PWM_swt_mode_select_KillModeMinTime) */

        #if(PWM_swt_mode_select_UseControl)
            PWM_swt_mode_select_backup.PWMControlRegister = PWM_swt_mode_select_ReadControlRegister();
        #endif /* (PWM_swt_mode_select_UseControl) */
    #endif  /* (!PWM_swt_mode_select_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_swt_mode_select_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_swt_mode_select_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_swt_mode_select_RestoreConfig(void) 
{
        #if(!PWM_swt_mode_select_UsingFixedFunction)
            #if(!PWM_swt_mode_select_PWMModeIsCenterAligned)
                PWM_swt_mode_select_WritePeriod(PWM_swt_mode_select_backup.PWMPeriod);
            #endif /* (!PWM_swt_mode_select_PWMModeIsCenterAligned) */

            PWM_swt_mode_select_WriteCounter(PWM_swt_mode_select_backup.PWMUdb);

            #if (PWM_swt_mode_select_UseStatus)
                PWM_swt_mode_select_STATUS_MASK = PWM_swt_mode_select_backup.InterruptMaskValue;
            #endif /* (PWM_swt_mode_select_UseStatus) */

            #if(PWM_swt_mode_select_DeadBandMode == PWM_swt_mode_select__B_PWM__DBM_256_CLOCKS || \
                PWM_swt_mode_select_DeadBandMode == PWM_swt_mode_select__B_PWM__DBM_2_4_CLOCKS)
                PWM_swt_mode_select_WriteDeadTime(PWM_swt_mode_select_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_swt_mode_select_KillModeMinTime)
                PWM_swt_mode_select_WriteKillTime(PWM_swt_mode_select_backup.PWMKillCounterPeriod);
            #endif /* (PWM_swt_mode_select_KillModeMinTime) */

            #if(PWM_swt_mode_select_UseControl)
                PWM_swt_mode_select_WriteControlRegister(PWM_swt_mode_select_backup.PWMControlRegister);
            #endif /* (PWM_swt_mode_select_UseControl) */
        #endif  /* (!PWM_swt_mode_select_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_swt_mode_select_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_swt_mode_select_Sleep(void) 
{
    #if(PWM_swt_mode_select_UseControl)
        if(PWM_swt_mode_select_CTRL_ENABLE == (PWM_swt_mode_select_CONTROL & PWM_swt_mode_select_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_swt_mode_select_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_swt_mode_select_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_swt_mode_select_UseControl) */

    /* Stop component */
    PWM_swt_mode_select_Stop();

    /* Save registers configuration */
    PWM_swt_mode_select_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_swt_mode_select_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_swt_mode_select_Wakeup(void) 
{
     /* Restore registers values */
    PWM_swt_mode_select_RestoreConfig();

    if(PWM_swt_mode_select_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_swt_mode_select_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
