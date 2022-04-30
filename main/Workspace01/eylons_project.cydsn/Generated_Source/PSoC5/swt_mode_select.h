/*******************************************************************************
* File Name: swt_mode_select.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_swt_mode_select_H) /* Pins swt_mode_select_H */
#define CY_PINS_swt_mode_select_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "swt_mode_select_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 swt_mode_select__PORT == 15 && ((swt_mode_select__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    swt_mode_select_Write(uint8 value);
void    swt_mode_select_SetDriveMode(uint8 mode);
uint8   swt_mode_select_ReadDataReg(void);
uint8   swt_mode_select_Read(void);
void    swt_mode_select_SetInterruptMode(uint16 position, uint16 mode);
uint8   swt_mode_select_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the swt_mode_select_SetDriveMode() function.
     *  @{
     */
        #define swt_mode_select_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define swt_mode_select_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define swt_mode_select_DM_RES_UP          PIN_DM_RES_UP
        #define swt_mode_select_DM_RES_DWN         PIN_DM_RES_DWN
        #define swt_mode_select_DM_OD_LO           PIN_DM_OD_LO
        #define swt_mode_select_DM_OD_HI           PIN_DM_OD_HI
        #define swt_mode_select_DM_STRONG          PIN_DM_STRONG
        #define swt_mode_select_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define swt_mode_select_MASK               swt_mode_select__MASK
#define swt_mode_select_SHIFT              swt_mode_select__SHIFT
#define swt_mode_select_WIDTH              1u

/* Interrupt constants */
#if defined(swt_mode_select__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in swt_mode_select_SetInterruptMode() function.
     *  @{
     */
        #define swt_mode_select_INTR_NONE      (uint16)(0x0000u)
        #define swt_mode_select_INTR_RISING    (uint16)(0x0001u)
        #define swt_mode_select_INTR_FALLING   (uint16)(0x0002u)
        #define swt_mode_select_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define swt_mode_select_INTR_MASK      (0x01u) 
#endif /* (swt_mode_select__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define swt_mode_select_PS                     (* (reg8 *) swt_mode_select__PS)
/* Data Register */
#define swt_mode_select_DR                     (* (reg8 *) swt_mode_select__DR)
/* Port Number */
#define swt_mode_select_PRT_NUM                (* (reg8 *) swt_mode_select__PRT) 
/* Connect to Analog Globals */                                                  
#define swt_mode_select_AG                     (* (reg8 *) swt_mode_select__AG)                       
/* Analog MUX bux enable */
#define swt_mode_select_AMUX                   (* (reg8 *) swt_mode_select__AMUX) 
/* Bidirectional Enable */                                                        
#define swt_mode_select_BIE                    (* (reg8 *) swt_mode_select__BIE)
/* Bit-mask for Aliased Register Access */
#define swt_mode_select_BIT_MASK               (* (reg8 *) swt_mode_select__BIT_MASK)
/* Bypass Enable */
#define swt_mode_select_BYP                    (* (reg8 *) swt_mode_select__BYP)
/* Port wide control signals */                                                   
#define swt_mode_select_CTL                    (* (reg8 *) swt_mode_select__CTL)
/* Drive Modes */
#define swt_mode_select_DM0                    (* (reg8 *) swt_mode_select__DM0) 
#define swt_mode_select_DM1                    (* (reg8 *) swt_mode_select__DM1)
#define swt_mode_select_DM2                    (* (reg8 *) swt_mode_select__DM2) 
/* Input Buffer Disable Override */
#define swt_mode_select_INP_DIS                (* (reg8 *) swt_mode_select__INP_DIS)
/* LCD Common or Segment Drive */
#define swt_mode_select_LCD_COM_SEG            (* (reg8 *) swt_mode_select__LCD_COM_SEG)
/* Enable Segment LCD */
#define swt_mode_select_LCD_EN                 (* (reg8 *) swt_mode_select__LCD_EN)
/* Slew Rate Control */
#define swt_mode_select_SLW                    (* (reg8 *) swt_mode_select__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define swt_mode_select_PRTDSI__CAPS_SEL       (* (reg8 *) swt_mode_select__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define swt_mode_select_PRTDSI__DBL_SYNC_IN    (* (reg8 *) swt_mode_select__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define swt_mode_select_PRTDSI__OE_SEL0        (* (reg8 *) swt_mode_select__PRTDSI__OE_SEL0) 
#define swt_mode_select_PRTDSI__OE_SEL1        (* (reg8 *) swt_mode_select__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define swt_mode_select_PRTDSI__OUT_SEL0       (* (reg8 *) swt_mode_select__PRTDSI__OUT_SEL0) 
#define swt_mode_select_PRTDSI__OUT_SEL1       (* (reg8 *) swt_mode_select__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define swt_mode_select_PRTDSI__SYNC_OUT       (* (reg8 *) swt_mode_select__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(swt_mode_select__SIO_CFG)
    #define swt_mode_select_SIO_HYST_EN        (* (reg8 *) swt_mode_select__SIO_HYST_EN)
    #define swt_mode_select_SIO_REG_HIFREQ     (* (reg8 *) swt_mode_select__SIO_REG_HIFREQ)
    #define swt_mode_select_SIO_CFG            (* (reg8 *) swt_mode_select__SIO_CFG)
    #define swt_mode_select_SIO_DIFF           (* (reg8 *) swt_mode_select__SIO_DIFF)
#endif /* (swt_mode_select__SIO_CFG) */

/* Interrupt Registers */
#if defined(swt_mode_select__INTSTAT)
    #define swt_mode_select_INTSTAT            (* (reg8 *) swt_mode_select__INTSTAT)
    #define swt_mode_select_SNAP               (* (reg8 *) swt_mode_select__SNAP)
    
	#define swt_mode_select_0_INTTYPE_REG 		(* (reg8 *) swt_mode_select__0__INTTYPE)
#endif /* (swt_mode_select__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_swt_mode_select_H */


/* [] END OF FILE */
