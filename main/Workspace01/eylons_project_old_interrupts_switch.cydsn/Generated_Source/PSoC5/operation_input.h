/*******************************************************************************
* File Name: operation_input.h  
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

#if !defined(CY_PINS_operation_input_H) /* Pins operation_input_H */
#define CY_PINS_operation_input_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "operation_input_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 operation_input__PORT == 15 && ((operation_input__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    operation_input_Write(uint8 value);
void    operation_input_SetDriveMode(uint8 mode);
uint8   operation_input_ReadDataReg(void);
uint8   operation_input_Read(void);
void    operation_input_SetInterruptMode(uint16 position, uint16 mode);
uint8   operation_input_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the operation_input_SetDriveMode() function.
     *  @{
     */
        #define operation_input_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define operation_input_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define operation_input_DM_RES_UP          PIN_DM_RES_UP
        #define operation_input_DM_RES_DWN         PIN_DM_RES_DWN
        #define operation_input_DM_OD_LO           PIN_DM_OD_LO
        #define operation_input_DM_OD_HI           PIN_DM_OD_HI
        #define operation_input_DM_STRONG          PIN_DM_STRONG
        #define operation_input_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define operation_input_MASK               operation_input__MASK
#define operation_input_SHIFT              operation_input__SHIFT
#define operation_input_WIDTH              1u

/* Interrupt constants */
#if defined(operation_input__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in operation_input_SetInterruptMode() function.
     *  @{
     */
        #define operation_input_INTR_NONE      (uint16)(0x0000u)
        #define operation_input_INTR_RISING    (uint16)(0x0001u)
        #define operation_input_INTR_FALLING   (uint16)(0x0002u)
        #define operation_input_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define operation_input_INTR_MASK      (0x01u) 
#endif /* (operation_input__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define operation_input_PS                     (* (reg8 *) operation_input__PS)
/* Data Register */
#define operation_input_DR                     (* (reg8 *) operation_input__DR)
/* Port Number */
#define operation_input_PRT_NUM                (* (reg8 *) operation_input__PRT) 
/* Connect to Analog Globals */                                                  
#define operation_input_AG                     (* (reg8 *) operation_input__AG)                       
/* Analog MUX bux enable */
#define operation_input_AMUX                   (* (reg8 *) operation_input__AMUX) 
/* Bidirectional Enable */                                                        
#define operation_input_BIE                    (* (reg8 *) operation_input__BIE)
/* Bit-mask for Aliased Register Access */
#define operation_input_BIT_MASK               (* (reg8 *) operation_input__BIT_MASK)
/* Bypass Enable */
#define operation_input_BYP                    (* (reg8 *) operation_input__BYP)
/* Port wide control signals */                                                   
#define operation_input_CTL                    (* (reg8 *) operation_input__CTL)
/* Drive Modes */
#define operation_input_DM0                    (* (reg8 *) operation_input__DM0) 
#define operation_input_DM1                    (* (reg8 *) operation_input__DM1)
#define operation_input_DM2                    (* (reg8 *) operation_input__DM2) 
/* Input Buffer Disable Override */
#define operation_input_INP_DIS                (* (reg8 *) operation_input__INP_DIS)
/* LCD Common or Segment Drive */
#define operation_input_LCD_COM_SEG            (* (reg8 *) operation_input__LCD_COM_SEG)
/* Enable Segment LCD */
#define operation_input_LCD_EN                 (* (reg8 *) operation_input__LCD_EN)
/* Slew Rate Control */
#define operation_input_SLW                    (* (reg8 *) operation_input__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define operation_input_PRTDSI__CAPS_SEL       (* (reg8 *) operation_input__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define operation_input_PRTDSI__DBL_SYNC_IN    (* (reg8 *) operation_input__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define operation_input_PRTDSI__OE_SEL0        (* (reg8 *) operation_input__PRTDSI__OE_SEL0) 
#define operation_input_PRTDSI__OE_SEL1        (* (reg8 *) operation_input__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define operation_input_PRTDSI__OUT_SEL0       (* (reg8 *) operation_input__PRTDSI__OUT_SEL0) 
#define operation_input_PRTDSI__OUT_SEL1       (* (reg8 *) operation_input__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define operation_input_PRTDSI__SYNC_OUT       (* (reg8 *) operation_input__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(operation_input__SIO_CFG)
    #define operation_input_SIO_HYST_EN        (* (reg8 *) operation_input__SIO_HYST_EN)
    #define operation_input_SIO_REG_HIFREQ     (* (reg8 *) operation_input__SIO_REG_HIFREQ)
    #define operation_input_SIO_CFG            (* (reg8 *) operation_input__SIO_CFG)
    #define operation_input_SIO_DIFF           (* (reg8 *) operation_input__SIO_DIFF)
#endif /* (operation_input__SIO_CFG) */

/* Interrupt Registers */
#if defined(operation_input__INTSTAT)
    #define operation_input_INTSTAT            (* (reg8 *) operation_input__INTSTAT)
    #define operation_input_SNAP               (* (reg8 *) operation_input__SNAP)
    
	#define operation_input_0_INTTYPE_REG 		(* (reg8 *) operation_input__0__INTTYPE)
#endif /* (operation_input__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_operation_input_H */


/* [] END OF FILE */
