/*******************************************************************************
* File Name: in24.h  
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

#if !defined(CY_PINS_in24_H) /* Pins in24_H */
#define CY_PINS_in24_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "in24_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 in24__PORT == 15 && ((in24__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    in24_Write(uint8 value);
void    in24_SetDriveMode(uint8 mode);
uint8   in24_ReadDataReg(void);
uint8   in24_Read(void);
void    in24_SetInterruptMode(uint16 position, uint16 mode);
uint8   in24_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the in24_SetDriveMode() function.
     *  @{
     */
        #define in24_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define in24_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define in24_DM_RES_UP          PIN_DM_RES_UP
        #define in24_DM_RES_DWN         PIN_DM_RES_DWN
        #define in24_DM_OD_LO           PIN_DM_OD_LO
        #define in24_DM_OD_HI           PIN_DM_OD_HI
        #define in24_DM_STRONG          PIN_DM_STRONG
        #define in24_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define in24_MASK               in24__MASK
#define in24_SHIFT              in24__SHIFT
#define in24_WIDTH              1u

/* Interrupt constants */
#if defined(in24__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in in24_SetInterruptMode() function.
     *  @{
     */
        #define in24_INTR_NONE      (uint16)(0x0000u)
        #define in24_INTR_RISING    (uint16)(0x0001u)
        #define in24_INTR_FALLING   (uint16)(0x0002u)
        #define in24_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define in24_INTR_MASK      (0x01u) 
#endif /* (in24__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define in24_PS                     (* (reg8 *) in24__PS)
/* Data Register */
#define in24_DR                     (* (reg8 *) in24__DR)
/* Port Number */
#define in24_PRT_NUM                (* (reg8 *) in24__PRT) 
/* Connect to Analog Globals */                                                  
#define in24_AG                     (* (reg8 *) in24__AG)                       
/* Analog MUX bux enable */
#define in24_AMUX                   (* (reg8 *) in24__AMUX) 
/* Bidirectional Enable */                                                        
#define in24_BIE                    (* (reg8 *) in24__BIE)
/* Bit-mask for Aliased Register Access */
#define in24_BIT_MASK               (* (reg8 *) in24__BIT_MASK)
/* Bypass Enable */
#define in24_BYP                    (* (reg8 *) in24__BYP)
/* Port wide control signals */                                                   
#define in24_CTL                    (* (reg8 *) in24__CTL)
/* Drive Modes */
#define in24_DM0                    (* (reg8 *) in24__DM0) 
#define in24_DM1                    (* (reg8 *) in24__DM1)
#define in24_DM2                    (* (reg8 *) in24__DM2) 
/* Input Buffer Disable Override */
#define in24_INP_DIS                (* (reg8 *) in24__INP_DIS)
/* LCD Common or Segment Drive */
#define in24_LCD_COM_SEG            (* (reg8 *) in24__LCD_COM_SEG)
/* Enable Segment LCD */
#define in24_LCD_EN                 (* (reg8 *) in24__LCD_EN)
/* Slew Rate Control */
#define in24_SLW                    (* (reg8 *) in24__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define in24_PRTDSI__CAPS_SEL       (* (reg8 *) in24__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define in24_PRTDSI__DBL_SYNC_IN    (* (reg8 *) in24__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define in24_PRTDSI__OE_SEL0        (* (reg8 *) in24__PRTDSI__OE_SEL0) 
#define in24_PRTDSI__OE_SEL1        (* (reg8 *) in24__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define in24_PRTDSI__OUT_SEL0       (* (reg8 *) in24__PRTDSI__OUT_SEL0) 
#define in24_PRTDSI__OUT_SEL1       (* (reg8 *) in24__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define in24_PRTDSI__SYNC_OUT       (* (reg8 *) in24__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(in24__SIO_CFG)
    #define in24_SIO_HYST_EN        (* (reg8 *) in24__SIO_HYST_EN)
    #define in24_SIO_REG_HIFREQ     (* (reg8 *) in24__SIO_REG_HIFREQ)
    #define in24_SIO_CFG            (* (reg8 *) in24__SIO_CFG)
    #define in24_SIO_DIFF           (* (reg8 *) in24__SIO_DIFF)
#endif /* (in24__SIO_CFG) */

/* Interrupt Registers */
#if defined(in24__INTSTAT)
    #define in24_INTSTAT            (* (reg8 *) in24__INTSTAT)
    #define in24_SNAP               (* (reg8 *) in24__SNAP)
    
	#define in24_0_INTTYPE_REG 		(* (reg8 *) in24__0__INTTYPE)
#endif /* (in24__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_in24_H */


/* [] END OF FILE */
