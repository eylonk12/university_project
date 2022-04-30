/*******************************************************************************
* File Name: swt_mode_select.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_swt_mode_select_ALIASES_H) /* Pins swt_mode_select_ALIASES_H */
#define CY_PINS_swt_mode_select_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define swt_mode_select_0			(swt_mode_select__0__PC)
#define swt_mode_select_0_INTR	((uint16)((uint16)0x0001u << swt_mode_select__0__SHIFT))

#define swt_mode_select_INTR_ALL	 ((uint16)(swt_mode_select_0_INTR))

#endif /* End Pins swt_mode_select_ALIASES_H */


/* [] END OF FILE */
