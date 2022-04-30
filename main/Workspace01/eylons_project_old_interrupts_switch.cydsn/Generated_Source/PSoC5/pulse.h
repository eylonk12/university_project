/*******************************************************************************
* File Name: pulse.h  
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

#if !defined(CY_PINS_pulse_H) /* Pins pulse_H */
#define CY_PINS_pulse_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "pulse_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 pulse__PORT == 15 && ((pulse__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    pulse_Write(uint8 value);
void    pulse_SetDriveMode(uint8 mode);
uint8   pulse_ReadDataReg(void);
uint8   pulse_Read(void);
void    pulse_SetInterruptMode(uint16 position, uint16 mode);
uint8   pulse_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the pulse_SetDriveMode() function.
     *  @{
     */
        #define pulse_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define pulse_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define pulse_DM_RES_UP          PIN_DM_RES_UP
        #define pulse_DM_RES_DWN         PIN_DM_RES_DWN
        #define pulse_DM_OD_LO           PIN_DM_OD_LO
        #define pulse_DM_OD_HI           PIN_DM_OD_HI
        #define pulse_DM_STRONG          PIN_DM_STRONG
        #define pulse_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define pulse_MASK               pulse__MASK
#define pulse_SHIFT              pulse__SHIFT
#define pulse_WIDTH              1u

/* Interrupt constants */
#if defined(pulse__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in pulse_SetInterruptMode() function.
     *  @{
     */
        #define pulse_INTR_NONE      (uint16)(0x0000u)
        #define pulse_INTR_RISING    (uint16)(0x0001u)
        #define pulse_INTR_FALLING   (uint16)(0x0002u)
        #define pulse_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define pulse_INTR_MASK      (0x01u) 
#endif /* (pulse__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define pulse_PS                     (* (reg8 *) pulse__PS)
/* Data Register */
#define pulse_DR                     (* (reg8 *) pulse__DR)
/* Port Number */
#define pulse_PRT_NUM                (* (reg8 *) pulse__PRT) 
/* Connect to Analog Globals */                                                  
#define pulse_AG                     (* (reg8 *) pulse__AG)                       
/* Analog MUX bux enable */
#define pulse_AMUX                   (* (reg8 *) pulse__AMUX) 
/* Bidirectional Enable */                                                        
#define pulse_BIE                    (* (reg8 *) pulse__BIE)
/* Bit-mask for Aliased Register Access */
#define pulse_BIT_MASK               (* (reg8 *) pulse__BIT_MASK)
/* Bypass Enable */
#define pulse_BYP                    (* (reg8 *) pulse__BYP)
/* Port wide control signals */                                                   
#define pulse_CTL                    (* (reg8 *) pulse__CTL)
/* Drive Modes */
#define pulse_DM0                    (* (reg8 *) pulse__DM0) 
#define pulse_DM1                    (* (reg8 *) pulse__DM1)
#define pulse_DM2                    (* (reg8 *) pulse__DM2) 
/* Input Buffer Disable Override */
#define pulse_INP_DIS                (* (reg8 *) pulse__INP_DIS)
/* LCD Common or Segment Drive */
#define pulse_LCD_COM_SEG            (* (reg8 *) pulse__LCD_COM_SEG)
/* Enable Segment LCD */
#define pulse_LCD_EN                 (* (reg8 *) pulse__LCD_EN)
/* Slew Rate Control */
#define pulse_SLW                    (* (reg8 *) pulse__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define pulse_PRTDSI__CAPS_SEL       (* (reg8 *) pulse__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define pulse_PRTDSI__DBL_SYNC_IN    (* (reg8 *) pulse__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define pulse_PRTDSI__OE_SEL0        (* (reg8 *) pulse__PRTDSI__OE_SEL0) 
#define pulse_PRTDSI__OE_SEL1        (* (reg8 *) pulse__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define pulse_PRTDSI__OUT_SEL0       (* (reg8 *) pulse__PRTDSI__OUT_SEL0) 
#define pulse_PRTDSI__OUT_SEL1       (* (reg8 *) pulse__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define pulse_PRTDSI__SYNC_OUT       (* (reg8 *) pulse__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(pulse__SIO_CFG)
    #define pulse_SIO_HYST_EN        (* (reg8 *) pulse__SIO_HYST_EN)
    #define pulse_SIO_REG_HIFREQ     (* (reg8 *) pulse__SIO_REG_HIFREQ)
    #define pulse_SIO_CFG            (* (reg8 *) pulse__SIO_CFG)
    #define pulse_SIO_DIFF           (* (reg8 *) pulse__SIO_DIFF)
#endif /* (pulse__SIO_CFG) */

/* Interrupt Registers */
#if defined(pulse__INTSTAT)
    #define pulse_INTSTAT            (* (reg8 *) pulse__INTSTAT)
    #define pulse_SNAP               (* (reg8 *) pulse__SNAP)
    
	#define pulse_0_INTTYPE_REG 		(* (reg8 *) pulse__0__INTTYPE)
#endif /* (pulse__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_pulse_H */


/* [] END OF FILE */
