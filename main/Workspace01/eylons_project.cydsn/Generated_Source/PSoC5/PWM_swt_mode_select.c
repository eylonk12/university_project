/*******************************************************************************
* File Name: PWM_swt_mode_select.c
* Version 3.30
*
* Description:
*  The PWM User Module consist of an 8 or 16-bit counter with two 8 or 16-bit
*  comparitors. Each instance of this user module is capable of generating
*  two PWM outputs with the same period. The pulse width is selectable between
*  1 and 255/65535. The period is selectable between 2 and 255/65536 clocks.
*  The compare value output may be configured to be active when the present
*  counter is less than or less than/equal to the compare value.
*  A terminal count output is also provided. It generates a pulse one clock
*  width wide when the counter is equal to zero.
*
* Note:
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "PWM_swt_mode_select.h"

/* Error message for removed <resource> through optimization */
#ifdef PWM_swt_mode_select_PWMUDB_genblk1_ctrlreg__REMOVED
    #error PWM_v3_30 detected with a constant 0 for the enable or \
         constant 1 for reset. This will prevent the component from operating.
#endif /* PWM_swt_mode_select_PWMUDB_genblk1_ctrlreg__REMOVED */

uint8 PWM_swt_mode_select_initVar = 0u;


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Start
********************************************************************************
*
* Summary:
*  The start function initializes the pwm with the default values, the
*  enables the counter to begin counting.  It does not enable interrupts,
*  the EnableInt command should be called if interrupt generation is required.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_swt_mode_select_initVar: Is modified when this function is called for the
*   first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void PWM_swt_mode_select_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(PWM_swt_mode_select_initVar == 0u)
    {
        PWM_swt_mode_select_Init();
        PWM_swt_mode_select_initVar = 1u;
    }
    PWM_swt_mode_select_Enable();

}


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  PWM_swt_mode_select_Start().
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWM_swt_mode_select_Init(void) 
{
    #if (PWM_swt_mode_select_UsingFixedFunction || PWM_swt_mode_select_UseControl)
        uint8 ctrl;
    #endif /* (PWM_swt_mode_select_UsingFixedFunction || PWM_swt_mode_select_UseControl) */

    #if(!PWM_swt_mode_select_UsingFixedFunction)
        #if(PWM_swt_mode_select_UseStatus)
            /* Interrupt State Backup for Critical Region*/
            uint8 PWM_swt_mode_select_interruptState;
        #endif /* (PWM_swt_mode_select_UseStatus) */
    #endif /* (!PWM_swt_mode_select_UsingFixedFunction) */

    #if (PWM_swt_mode_select_UsingFixedFunction)
        /* You are allowed to write the compare value (FF only) */
        PWM_swt_mode_select_CONTROL |= PWM_swt_mode_select_CFG0_MODE;
        #if (PWM_swt_mode_select_DeadBand2_4)
            PWM_swt_mode_select_CONTROL |= PWM_swt_mode_select_CFG0_DB;
        #endif /* (PWM_swt_mode_select_DeadBand2_4) */

        ctrl = PWM_swt_mode_select_CONTROL3 & ((uint8 )(~PWM_swt_mode_select_CTRL_CMPMODE1_MASK));
        PWM_swt_mode_select_CONTROL3 = ctrl | PWM_swt_mode_select_DEFAULT_COMPARE1_MODE;

         /* Clear and Set SYNCTC and SYNCCMP bits of RT1 register */
        PWM_swt_mode_select_RT1 &= ((uint8)(~PWM_swt_mode_select_RT1_MASK));
        PWM_swt_mode_select_RT1 |= PWM_swt_mode_select_SYNC;

        /*Enable DSI Sync all all inputs of the PWM*/
        PWM_swt_mode_select_RT1 &= ((uint8)(~PWM_swt_mode_select_SYNCDSI_MASK));
        PWM_swt_mode_select_RT1 |= PWM_swt_mode_select_SYNCDSI_EN;

    #elif (PWM_swt_mode_select_UseControl)
        /* Set the default compare mode defined in the parameter */
        ctrl = PWM_swt_mode_select_CONTROL & ((uint8)(~PWM_swt_mode_select_CTRL_CMPMODE2_MASK)) &
                ((uint8)(~PWM_swt_mode_select_CTRL_CMPMODE1_MASK));
        PWM_swt_mode_select_CONTROL = ctrl | PWM_swt_mode_select_DEFAULT_COMPARE2_MODE |
                                   PWM_swt_mode_select_DEFAULT_COMPARE1_MODE;
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */

    #if (!PWM_swt_mode_select_UsingFixedFunction)
        #if (PWM_swt_mode_select_Resolution == 8)
            /* Set FIFO 0 to 1 byte register for period*/
            PWM_swt_mode_select_AUX_CONTROLDP0 |= (PWM_swt_mode_select_AUX_CTRL_FIFO0_CLR);
        #else /* (PWM_swt_mode_select_Resolution == 16)*/
            /* Set FIFO 0 to 1 byte register for period */
            PWM_swt_mode_select_AUX_CONTROLDP0 |= (PWM_swt_mode_select_AUX_CTRL_FIFO0_CLR);
            PWM_swt_mode_select_AUX_CONTROLDP1 |= (PWM_swt_mode_select_AUX_CTRL_FIFO0_CLR);
        #endif /* (PWM_swt_mode_select_Resolution == 8) */

        PWM_swt_mode_select_WriteCounter(PWM_swt_mode_select_INIT_PERIOD_VALUE);
    #endif /* (!PWM_swt_mode_select_UsingFixedFunction) */

    PWM_swt_mode_select_WritePeriod(PWM_swt_mode_select_INIT_PERIOD_VALUE);

        #if (PWM_swt_mode_select_UseOneCompareMode)
            PWM_swt_mode_select_WriteCompare(PWM_swt_mode_select_INIT_COMPARE_VALUE1);
        #else
            PWM_swt_mode_select_WriteCompare1(PWM_swt_mode_select_INIT_COMPARE_VALUE1);
            PWM_swt_mode_select_WriteCompare2(PWM_swt_mode_select_INIT_COMPARE_VALUE2);
        #endif /* (PWM_swt_mode_select_UseOneCompareMode) */

        #if (PWM_swt_mode_select_KillModeMinTime)
            PWM_swt_mode_select_WriteKillTime(PWM_swt_mode_select_MinimumKillTime);
        #endif /* (PWM_swt_mode_select_KillModeMinTime) */

        #if (PWM_swt_mode_select_DeadBandUsed)
            PWM_swt_mode_select_WriteDeadTime(PWM_swt_mode_select_INIT_DEAD_TIME);
        #endif /* (PWM_swt_mode_select_DeadBandUsed) */

    #if (PWM_swt_mode_select_UseStatus || PWM_swt_mode_select_UsingFixedFunction)
        PWM_swt_mode_select_SetInterruptMode(PWM_swt_mode_select_INIT_INTERRUPTS_MODE);
    #endif /* (PWM_swt_mode_select_UseStatus || PWM_swt_mode_select_UsingFixedFunction) */

    #if (PWM_swt_mode_select_UsingFixedFunction)
        /* Globally Enable the Fixed Function Block chosen */
        PWM_swt_mode_select_GLOBAL_ENABLE |= PWM_swt_mode_select_BLOCK_EN_MASK;
        /* Set the Interrupt source to come from the status register */
        PWM_swt_mode_select_CONTROL2 |= PWM_swt_mode_select_CTRL2_IRQ_SEL;
    #else
        #if(PWM_swt_mode_select_UseStatus)

            /* CyEnterCriticalRegion and CyExitCriticalRegion are used to mark following region critical*/
            /* Enter Critical Region*/
            PWM_swt_mode_select_interruptState = CyEnterCriticalSection();
            /* Use the interrupt output of the status register for IRQ output */
            PWM_swt_mode_select_STATUS_AUX_CTRL |= PWM_swt_mode_select_STATUS_ACTL_INT_EN_MASK;

             /* Exit Critical Region*/
            CyExitCriticalSection(PWM_swt_mode_select_interruptState);

            /* Clear the FIFO to enable the PWM_swt_mode_select_STATUS_FIFOFULL
                   bit to be set on FIFO full. */
            PWM_swt_mode_select_ClearFIFO();
        #endif /* (PWM_swt_mode_select_UseStatus) */
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Enable
********************************************************************************
*
* Summary:
*  Enables the PWM block operation
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  This works only if software enable mode is chosen
*
*******************************************************************************/
void PWM_swt_mode_select_Enable(void) 
{
    /* Globally Enable the Fixed Function Block chosen */
    #if (PWM_swt_mode_select_UsingFixedFunction)
        PWM_swt_mode_select_GLOBAL_ENABLE |= PWM_swt_mode_select_BLOCK_EN_MASK;
        PWM_swt_mode_select_GLOBAL_STBY_ENABLE |= PWM_swt_mode_select_BLOCK_STBY_EN_MASK;
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */

    /* Enable the PWM from the control register  */
    #if (PWM_swt_mode_select_UseControl || PWM_swt_mode_select_UsingFixedFunction)
        PWM_swt_mode_select_CONTROL |= PWM_swt_mode_select_CTRL_ENABLE;
    #endif /* (PWM_swt_mode_select_UseControl || PWM_swt_mode_select_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_swt_mode_select_Stop
********************************************************************************
*
* Summary:
*  The stop function halts the PWM, but does not change any modes or disable
*  interrupts.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Side Effects:
*  If the Enable mode is set to Hardware only then this function
*  has no effect on the operation of the PWM
*
*******************************************************************************/
void PWM_swt_mode_select_Stop(void) 
{
    #if (PWM_swt_mode_select_UseControl || PWM_swt_mode_select_UsingFixedFunction)
        PWM_swt_mode_select_CONTROL &= ((uint8)(~PWM_swt_mode_select_CTRL_ENABLE));
    #endif /* (PWM_swt_mode_select_UseControl || PWM_swt_mode_select_UsingFixedFunction) */

    /* Globally disable the Fixed Function Block chosen */
    #if (PWM_swt_mode_select_UsingFixedFunction)
        PWM_swt_mode_select_GLOBAL_ENABLE &= ((uint8)(~PWM_swt_mode_select_BLOCK_EN_MASK));
        PWM_swt_mode_select_GLOBAL_STBY_ENABLE &= ((uint8)(~PWM_swt_mode_select_BLOCK_STBY_EN_MASK));
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
}

#if (PWM_swt_mode_select_UseOneCompareMode)
    #if (PWM_swt_mode_select_CompareMode1SW)


        /*******************************************************************************
        * Function Name: PWM_swt_mode_select_SetCompareMode
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm output when in Dither mode,
        *  Center Align Mode or One Output Mode.
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void PWM_swt_mode_select_SetCompareMode(uint8 comparemode) 
        {
            #if(PWM_swt_mode_select_UsingFixedFunction)

                #if(0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemodemasked = ((uint8)((uint8)comparemode << PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT));
                #else
                    uint8 comparemodemasked = comparemode;
                #endif /* (0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT) */

                PWM_swt_mode_select_CONTROL3 &= ((uint8)(~PWM_swt_mode_select_CTRL_CMPMODE1_MASK)); /*Clear Existing Data */
                PWM_swt_mode_select_CONTROL3 |= comparemodemasked;

            #elif (PWM_swt_mode_select_UseControl)

                #if(0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT)
                    uint8 comparemode1masked = ((uint8)((uint8)comparemode << PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT)) &
                                                PWM_swt_mode_select_CTRL_CMPMODE1_MASK;
                #else
                    uint8 comparemode1masked = comparemode & PWM_swt_mode_select_CTRL_CMPMODE1_MASK;
                #endif /* (0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT) */

                #if(0 != PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT)
                    uint8 comparemode2masked = ((uint8)((uint8)comparemode << PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT)) &
                                               PWM_swt_mode_select_CTRL_CMPMODE2_MASK;
                #else
                    uint8 comparemode2masked = comparemode & PWM_swt_mode_select_CTRL_CMPMODE2_MASK;
                #endif /* (0 != PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT) */

                /*Clear existing mode */
                PWM_swt_mode_select_CONTROL &= ((uint8)(~(PWM_swt_mode_select_CTRL_CMPMODE1_MASK |
                                            PWM_swt_mode_select_CTRL_CMPMODE2_MASK)));
                PWM_swt_mode_select_CONTROL |= (comparemode1masked | comparemode2masked);

            #else
                uint8 temp = comparemode;
            #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
        }
    #endif /* PWM_swt_mode_select_CompareMode1SW */

#else /* UseOneCompareMode */

    #if (PWM_swt_mode_select_CompareMode1SW)


        /*******************************************************************************
        * Function Name: PWM_swt_mode_select_SetCompareMode1
        ********************************************************************************
        *
        * Summary:
        *  This function writes the Compare Mode for the pwm or pwm1 output
        *
        * Parameters:
        *  comparemode:  The new compare mode for the PWM output. Use the compare types
        *                defined in the H file as input arguments.
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void PWM_swt_mode_select_SetCompareMode1(uint8 comparemode) 
        {
            #if(0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT)
                uint8 comparemodemasked = ((uint8)((uint8)comparemode << PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT)) &
                                           PWM_swt_mode_select_CTRL_CMPMODE1_MASK;
            #else
                uint8 comparemodemasked = comparemode & PWM_swt_mode_select_CTRL_CMPMODE1_MASK;
            #endif /* (0 != PWM_swt_mode_select_CTRL_CMPMODE1_SHIFT) */

            #if (PWM_swt_mode_select_UseControl)
                PWM_swt_mode_select_CONTROL &= ((uint8)(~PWM_swt_mode_select_CTRL_CMPMODE1_MASK)); /*Clear existing mode */
                PWM_swt_mode_select_CONTROL |= comparemodemasked;
            #endif /* (PWM_swt_mode_select_UseControl) */
        }
    #endif /* PWM_swt_mode_select_CompareMode1SW */

#if (PWM_swt_mode_select_CompareMode2SW)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_SetCompareMode2
    ********************************************************************************
    *
    * Summary:
    *  This function writes the Compare Mode for the pwm or pwm2 output
    *
    * Parameters:
    *  comparemode:  The new compare mode for the PWM output. Use the compare types
    *                defined in the H file as input arguments.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_SetCompareMode2(uint8 comparemode) 
    {

        #if(0 != PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT)
            uint8 comparemodemasked = ((uint8)((uint8)comparemode << PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT)) &
                                                 PWM_swt_mode_select_CTRL_CMPMODE2_MASK;
        #else
            uint8 comparemodemasked = comparemode & PWM_swt_mode_select_CTRL_CMPMODE2_MASK;
        #endif /* (0 != PWM_swt_mode_select_CTRL_CMPMODE2_SHIFT) */

        #if (PWM_swt_mode_select_UseControl)
            PWM_swt_mode_select_CONTROL &= ((uint8)(~PWM_swt_mode_select_CTRL_CMPMODE2_MASK)); /*Clear existing mode */
            PWM_swt_mode_select_CONTROL |= comparemodemasked;
        #endif /* (PWM_swt_mode_select_UseControl) */
    }
    #endif /*PWM_swt_mode_select_CompareMode2SW */

#endif /* UseOneCompareMode */


#if (!PWM_swt_mode_select_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteCounter
    ********************************************************************************
    *
    * Summary:
    *  Writes a new counter value directly to the counter register. This will be
    *  implemented for that currently running period and only that period. This API
    *  is valid only for UDB implementation and not available for fixed function
    *  PWM implementation.
    *
    * Parameters:
    *  counter:  The period new period counter value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  The PWM Period will be reloaded when a counter value will be a zero
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteCounter(uint16 counter) \
                                       
    {
        CY_SET_REG16(PWM_swt_mode_select_COUNTER_LSB_PTR, counter);
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadCounter
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current value of the counter.  It doesn't matter
    *  if the counter is enabled or running.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  The current value of the counter.
    *
    *******************************************************************************/
    uint16 PWM_swt_mode_select_ReadCounter(void) 
    {
        /* Force capture by reading Accumulator */
        /* Must first do a software capture to be able to read the counter */
        /* It is up to the user code to make sure there isn't already captured data in the FIFO */
          (void)CY_GET_REG8(PWM_swt_mode_select_COUNTERCAP_LSB_PTR_8BIT);

        /* Read the data from the FIFO */
        return (CY_GET_REG16(PWM_swt_mode_select_CAPTURE_LSB_PTR));
    }

    #if (PWM_swt_mode_select_UseStatus)


        /*******************************************************************************
        * Function Name: PWM_swt_mode_select_ClearFIFO
        ********************************************************************************
        *
        * Summary:
        *  This function clears all capture data from the capture FIFO
        *
        * Parameters:
        *  None
        *
        * Return:
        *  None
        *
        *******************************************************************************/
        void PWM_swt_mode_select_ClearFIFO(void) 
        {
            while(0u != (PWM_swt_mode_select_ReadStatusRegister() & PWM_swt_mode_select_STATUS_FIFONEMPTY))
            {
                (void)PWM_swt_mode_select_ReadCapture();
            }
        }

    #endif /* PWM_swt_mode_select_UseStatus */

#endif /* !PWM_swt_mode_select_UsingFixedFunction */


/*******************************************************************************
* Function Name: PWM_swt_mode_select_WritePeriod
********************************************************************************
*
* Summary:
*  This function is used to change the period of the counter.  The new period
*  will be loaded the next time terminal count is detected.
*
* Parameters:
*  period:  Period value. May be between 1 and (2^Resolution)-1.  A value of 0
*           will result in the counter remaining at zero.
*
* Return:
*  None
*
*******************************************************************************/
void PWM_swt_mode_select_WritePeriod(uint16 period) 
{
    #if(PWM_swt_mode_select_UsingFixedFunction)
        CY_SET_REG16(PWM_swt_mode_select_PERIOD_LSB_PTR, (uint16)period);
    #else
        CY_SET_REG16(PWM_swt_mode_select_PERIOD_LSB_PTR, period);
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
}

#if (PWM_swt_mode_select_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteCompare
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value when the PWM is in Dither
    *  mode. The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  compared to the compare value based on the compare mode defined in
    *  Dither Mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    * Side Effects:
    *  This function is only available if the PWM mode parameter is set to
    *  Dither Mode, Center Aligned Mode or One Output Mode
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteCompare(uint16 compare) \
                                       
    {
        #if(PWM_swt_mode_select_UsingFixedFunction)
            CY_SET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR, compare);
        #endif /* (PWM_swt_mode_select_UsingFixedFunction) */

        #if (PWM_swt_mode_select_PWMMode == PWM_swt_mode_select__B_PWM__DITHER)
            #if(PWM_swt_mode_select_UsingFixedFunction)
                CY_SET_REG16(PWM_swt_mode_select_COMPARE2_LSB_PTR, (uint16)(compare + 1u));
            #else
                CY_SET_REG16(PWM_swt_mode_select_COMPARE2_LSB_PTR, (compare + 1u));
            #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
        #endif /* (PWM_swt_mode_select_PWMMode == PWM_swt_mode_select__B_PWM__DITHER) */
    }


#else


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteCompare1
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare1 value.  The compare output will
    *  reflect the new value on the next UDB clock.  The compare output will be
    *  driven high when the present counter value is less than or less than or
    *  equal to the compare register, depending on the mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteCompare1(uint16 compare) \
                                        
    {
        #if(PWM_swt_mode_select_UsingFixedFunction)
            CY_SET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR, (uint16)compare);
        #else
            CY_SET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR, compare);
        #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteCompare2
    ********************************************************************************
    *
    * Summary:
    *  This funtion is used to change the compare value, for compare1 output.
    *  The compare output will reflect the new value on the next UDB clock.
    *  The compare output will be driven high when the present counter value is
    *  less than or less than or equal to the compare register, depending on the
    *  mode.
    *
    * Parameters:
    *  compare:  New compare value.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteCompare2(uint16 compare) \
                                        
    {
        #if(PWM_swt_mode_select_UsingFixedFunction)
            CY_SET_REG16(PWM_swt_mode_select_COMPARE2_LSB_PTR, compare);
        #else
            CY_SET_REG16(PWM_swt_mode_select_COMPARE2_LSB_PTR, compare);
        #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
    }
#endif /* UseOneCompareMode */

#if (PWM_swt_mode_select_DeadBandUsed)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function writes the dead-band counts to the corresponding register
    *
    * Parameters:
    *  deadtime:  Number of counts for dead time
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteDeadTime(uint8 deadtime) 
    {
        /* If using the Dead Band 1-255 mode then just write the register */
        #if(!PWM_swt_mode_select_DeadBand2_4)
            CY_SET_REG8(PWM_swt_mode_select_DEADBAND_COUNT_PTR, deadtime);
        #else
            /* Otherwise the data has to be masked and offset */
            /* Clear existing data */
            PWM_swt_mode_select_DEADBAND_COUNT &= ((uint8)(~PWM_swt_mode_select_DEADBAND_COUNT_MASK));

            /* Set new dead time */
            #if(PWM_swt_mode_select_DEADBAND_COUNT_SHIFT)
                PWM_swt_mode_select_DEADBAND_COUNT |= ((uint8)((uint8)deadtime << PWM_swt_mode_select_DEADBAND_COUNT_SHIFT)) &
                                                    PWM_swt_mode_select_DEADBAND_COUNT_MASK;
            #else
                PWM_swt_mode_select_DEADBAND_COUNT |= deadtime & PWM_swt_mode_select_DEADBAND_COUNT_MASK;
            #endif /* (PWM_swt_mode_select_DEADBAND_COUNT_SHIFT) */

        #endif /* (!PWM_swt_mode_select_DeadBand2_4) */
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadDeadTime
    ********************************************************************************
    *
    * Summary:
    *  This function reads the dead-band counts from the corresponding register
    *
    * Parameters:
    *  None
    *
    * Return:
    *  Dead Band Counts
    *
    *******************************************************************************/
    uint8 PWM_swt_mode_select_ReadDeadTime(void) 
    {
        /* If using the Dead Band 1-255 mode then just read the register */
        #if(!PWM_swt_mode_select_DeadBand2_4)
            return (CY_GET_REG8(PWM_swt_mode_select_DEADBAND_COUNT_PTR));
        #else

            /* Otherwise the data has to be masked and offset */
            #if(PWM_swt_mode_select_DEADBAND_COUNT_SHIFT)
                return ((uint8)(((uint8)(PWM_swt_mode_select_DEADBAND_COUNT & PWM_swt_mode_select_DEADBAND_COUNT_MASK)) >>
                                                                           PWM_swt_mode_select_DEADBAND_COUNT_SHIFT));
            #else
                return (PWM_swt_mode_select_DEADBAND_COUNT & PWM_swt_mode_select_DEADBAND_COUNT_MASK);
            #endif /* (PWM_swt_mode_select_DEADBAND_COUNT_SHIFT) */
        #endif /* (!PWM_swt_mode_select_DeadBand2_4) */
    }
#endif /* DeadBandUsed */

#if (PWM_swt_mode_select_UseStatus || PWM_swt_mode_select_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_SetInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  This function configures the interrupts mask control of theinterrupt
    *  source status register.
    *
    * Parameters:
    *  uint8 interruptMode: Bit field containing the interrupt sources enabled
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_SetInterruptMode(uint8 interruptMode) 
    {
        CY_SET_REG8(PWM_swt_mode_select_STATUS_MASK_PTR, interruptMode);
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadStatusRegister
    ********************************************************************************
    *
    * Summary:
    *  This function returns the current state of the status register.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current status register value. The status register bits are:
    *  [7:6] : Unused(0)
    *  [5]   : Kill event output
    *  [4]   : FIFO not empty
    *  [3]   : FIFO full
    *  [2]   : Terminal count
    *  [1]   : Compare output 2
    *  [0]   : Compare output 1
    *
    *******************************************************************************/
    uint8 PWM_swt_mode_select_ReadStatusRegister(void) 
    {
        return (CY_GET_REG8(PWM_swt_mode_select_STATUS_PTR));
    }

#endif /* (PWM_swt_mode_select_UseStatus || PWM_swt_mode_select_UsingFixedFunction) */


#if (PWM_swt_mode_select_UseControl)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Returns the current state of the control register. This API is available
    *  only if the control register is not removed.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8 : Current control register value
    *
    *******************************************************************************/
    uint8 PWM_swt_mode_select_ReadControlRegister(void) 
    {
        uint8 result;

        result = CY_GET_REG8(PWM_swt_mode_select_CONTROL_PTR);
        return (result);
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteControlRegister
    ********************************************************************************
    *
    * Summary:
    *  Sets the bit field of the control register. This API is available only if
    *  the control register is not removed.
    *
    * Parameters:
    *  uint8 control: Control register bit field, The status register bits are:
    *  [7]   : PWM Enable
    *  [6]   : Reset
    *  [5:3] : Compare Mode2
    *  [2:0] : Compare Mode2
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteControlRegister(uint8 control) 
    {
        CY_SET_REG8(PWM_swt_mode_select_CONTROL_PTR, control);
    }

#endif /* (PWM_swt_mode_select_UseControl) */


#if (!PWM_swt_mode_select_UsingFixedFunction)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadCapture
    ********************************************************************************
    *
    * Summary:
    *  Reads the capture value from the capture FIFO.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: The current capture value
    *
    *******************************************************************************/
    uint16 PWM_swt_mode_select_ReadCapture(void) 
    {
        return (CY_GET_REG16(PWM_swt_mode_select_CAPTURE_LSB_PTR));
    }

#endif /* (!PWM_swt_mode_select_UsingFixedFunction) */


#if (PWM_swt_mode_select_UseOneCompareMode)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadCompare
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare output when the PWM Mode parameter is
    *  set to Dither mode, Center Aligned mode, or One Output mode.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value
    *
    *******************************************************************************/
    uint16 PWM_swt_mode_select_ReadCompare(void) 
    {
        #if(PWM_swt_mode_select_UsingFixedFunction)
            return ((uint16)CY_GET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR));
        #else
            return (CY_GET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR));
        #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
    }

#else


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadCompare1
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare1 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 PWM_swt_mode_select_ReadCompare1(void) 
    {
        return (CY_GET_REG16(PWM_swt_mode_select_COMPARE1_LSB_PTR));
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadCompare2
    ********************************************************************************
    *
    * Summary:
    *  Reads the compare value for the compare2 output.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8/uint16: Current compare value.
    *
    *******************************************************************************/
    uint16 PWM_swt_mode_select_ReadCompare2(void) 
    {
        return (CY_GET_REG16(PWM_swt_mode_select_COMPARE2_LSB_PTR));
    }

#endif /* (PWM_swt_mode_select_UseOneCompareMode) */


/*******************************************************************************
* Function Name: PWM_swt_mode_select_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the period value used by the PWM hardware.
*
* Parameters:
*  None
*
* Return:
*  uint8/16: Period value
*
*******************************************************************************/
uint16 PWM_swt_mode_select_ReadPeriod(void) 
{
    #if(PWM_swt_mode_select_UsingFixedFunction)
        return ((uint16)CY_GET_REG16(PWM_swt_mode_select_PERIOD_LSB_PTR));
    #else
        return (CY_GET_REG16(PWM_swt_mode_select_PERIOD_LSB_PTR));
    #endif /* (PWM_swt_mode_select_UsingFixedFunction) */
}

#if ( PWM_swt_mode_select_KillModeMinTime)


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_WriteKillTime
    ********************************************************************************
    *
    * Summary:
    *  Writes the kill time value used by the hardware when the Kill Mode
    *  is set to Minimum Time.
    *
    * Parameters:
    *  uint8: Minimum Time kill counts
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void PWM_swt_mode_select_WriteKillTime(uint8 killtime) 
    {
        CY_SET_REG8(PWM_swt_mode_select_KILLMODEMINTIME_PTR, killtime);
    }


    /*******************************************************************************
    * Function Name: PWM_swt_mode_select_ReadKillTime
    ********************************************************************************
    *
    * Summary:
    *  Reads the kill time value used by the hardware when the Kill Mode is set
    *  to Minimum Time.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  uint8: The current Minimum Time kill counts
    *
    *******************************************************************************/
    uint8 PWM_swt_mode_select_ReadKillTime(void) 
    {
        return (CY_GET_REG8(PWM_swt_mode_select_KILLMODEMINTIME_PTR));
    }

#endif /* ( PWM_swt_mode_select_KillModeMinTime) */

/* [] END OF FILE */
