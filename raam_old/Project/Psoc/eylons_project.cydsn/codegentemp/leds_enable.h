/*******************************************************************************
* File Name: leds_enable.h  
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

#if !defined(CY_PINS_leds_enable_H) /* Pins leds_enable_H */
#define CY_PINS_leds_enable_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "leds_enable_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 leds_enable__PORT == 15 && ((leds_enable__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    leds_enable_Write(uint8 value);
void    leds_enable_SetDriveMode(uint8 mode);
uint8   leds_enable_ReadDataReg(void);
uint8   leds_enable_Read(void);
void    leds_enable_SetInterruptMode(uint16 position, uint16 mode);
uint8   leds_enable_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the leds_enable_SetDriveMode() function.
     *  @{
     */
        #define leds_enable_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define leds_enable_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define leds_enable_DM_RES_UP          PIN_DM_RES_UP
        #define leds_enable_DM_RES_DWN         PIN_DM_RES_DWN
        #define leds_enable_DM_OD_LO           PIN_DM_OD_LO
        #define leds_enable_DM_OD_HI           PIN_DM_OD_HI
        #define leds_enable_DM_STRONG          PIN_DM_STRONG
        #define leds_enable_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define leds_enable_MASK               leds_enable__MASK
#define leds_enable_SHIFT              leds_enable__SHIFT
#define leds_enable_WIDTH              1u

/* Interrupt constants */
#if defined(leds_enable__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in leds_enable_SetInterruptMode() function.
     *  @{
     */
        #define leds_enable_INTR_NONE      (uint16)(0x0000u)
        #define leds_enable_INTR_RISING    (uint16)(0x0001u)
        #define leds_enable_INTR_FALLING   (uint16)(0x0002u)
        #define leds_enable_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define leds_enable_INTR_MASK      (0x01u) 
#endif /* (leds_enable__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define leds_enable_PS                     (* (reg8 *) leds_enable__PS)
/* Data Register */
#define leds_enable_DR                     (* (reg8 *) leds_enable__DR)
/* Port Number */
#define leds_enable_PRT_NUM                (* (reg8 *) leds_enable__PRT) 
/* Connect to Analog Globals */                                                  
#define leds_enable_AG                     (* (reg8 *) leds_enable__AG)                       
/* Analog MUX bux enable */
#define leds_enable_AMUX                   (* (reg8 *) leds_enable__AMUX) 
/* Bidirectional Enable */                                                        
#define leds_enable_BIE                    (* (reg8 *) leds_enable__BIE)
/* Bit-mask for Aliased Register Access */
#define leds_enable_BIT_MASK               (* (reg8 *) leds_enable__BIT_MASK)
/* Bypass Enable */
#define leds_enable_BYP                    (* (reg8 *) leds_enable__BYP)
/* Port wide control signals */                                                   
#define leds_enable_CTL                    (* (reg8 *) leds_enable__CTL)
/* Drive Modes */
#define leds_enable_DM0                    (* (reg8 *) leds_enable__DM0) 
#define leds_enable_DM1                    (* (reg8 *) leds_enable__DM1)
#define leds_enable_DM2                    (* (reg8 *) leds_enable__DM2) 
/* Input Buffer Disable Override */
#define leds_enable_INP_DIS                (* (reg8 *) leds_enable__INP_DIS)
/* LCD Common or Segment Drive */
#define leds_enable_LCD_COM_SEG            (* (reg8 *) leds_enable__LCD_COM_SEG)
/* Enable Segment LCD */
#define leds_enable_LCD_EN                 (* (reg8 *) leds_enable__LCD_EN)
/* Slew Rate Control */
#define leds_enable_SLW                    (* (reg8 *) leds_enable__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define leds_enable_PRTDSI__CAPS_SEL       (* (reg8 *) leds_enable__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define leds_enable_PRTDSI__DBL_SYNC_IN    (* (reg8 *) leds_enable__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define leds_enable_PRTDSI__OE_SEL0        (* (reg8 *) leds_enable__PRTDSI__OE_SEL0) 
#define leds_enable_PRTDSI__OE_SEL1        (* (reg8 *) leds_enable__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define leds_enable_PRTDSI__OUT_SEL0       (* (reg8 *) leds_enable__PRTDSI__OUT_SEL0) 
#define leds_enable_PRTDSI__OUT_SEL1       (* (reg8 *) leds_enable__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define leds_enable_PRTDSI__SYNC_OUT       (* (reg8 *) leds_enable__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(leds_enable__SIO_CFG)
    #define leds_enable_SIO_HYST_EN        (* (reg8 *) leds_enable__SIO_HYST_EN)
    #define leds_enable_SIO_REG_HIFREQ     (* (reg8 *) leds_enable__SIO_REG_HIFREQ)
    #define leds_enable_SIO_CFG            (* (reg8 *) leds_enable__SIO_CFG)
    #define leds_enable_SIO_DIFF           (* (reg8 *) leds_enable__SIO_DIFF)
#endif /* (leds_enable__SIO_CFG) */

/* Interrupt Registers */
#if defined(leds_enable__INTSTAT)
    #define leds_enable_INTSTAT            (* (reg8 *) leds_enable__INTSTAT)
    #define leds_enable_SNAP               (* (reg8 *) leds_enable__SNAP)
    
	#define leds_enable_0_INTTYPE_REG 		(* (reg8 *) leds_enable__0__INTTYPE)
#endif /* (leds_enable__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_leds_enable_H */


/* [] END OF FILE */
