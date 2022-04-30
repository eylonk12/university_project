/*******************************************************************************
* File Name: ground.h  
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

#if !defined(CY_PINS_ground_H) /* Pins ground_H */
#define CY_PINS_ground_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ground_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ground__PORT == 15 && ((ground__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ground_Write(uint8 value);
void    ground_SetDriveMode(uint8 mode);
uint8   ground_ReadDataReg(void);
uint8   ground_Read(void);
void    ground_SetInterruptMode(uint16 position, uint16 mode);
uint8   ground_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ground_SetDriveMode() function.
     *  @{
     */
        #define ground_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ground_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ground_DM_RES_UP          PIN_DM_RES_UP
        #define ground_DM_RES_DWN         PIN_DM_RES_DWN
        #define ground_DM_OD_LO           PIN_DM_OD_LO
        #define ground_DM_OD_HI           PIN_DM_OD_HI
        #define ground_DM_STRONG          PIN_DM_STRONG
        #define ground_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ground_MASK               ground__MASK
#define ground_SHIFT              ground__SHIFT
#define ground_WIDTH              1u

/* Interrupt constants */
#if defined(ground__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ground_SetInterruptMode() function.
     *  @{
     */
        #define ground_INTR_NONE      (uint16)(0x0000u)
        #define ground_INTR_RISING    (uint16)(0x0001u)
        #define ground_INTR_FALLING   (uint16)(0x0002u)
        #define ground_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ground_INTR_MASK      (0x01u) 
#endif /* (ground__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ground_PS                     (* (reg8 *) ground__PS)
/* Data Register */
#define ground_DR                     (* (reg8 *) ground__DR)
/* Port Number */
#define ground_PRT_NUM                (* (reg8 *) ground__PRT) 
/* Connect to Analog Globals */                                                  
#define ground_AG                     (* (reg8 *) ground__AG)                       
/* Analog MUX bux enable */
#define ground_AMUX                   (* (reg8 *) ground__AMUX) 
/* Bidirectional Enable */                                                        
#define ground_BIE                    (* (reg8 *) ground__BIE)
/* Bit-mask for Aliased Register Access */
#define ground_BIT_MASK               (* (reg8 *) ground__BIT_MASK)
/* Bypass Enable */
#define ground_BYP                    (* (reg8 *) ground__BYP)
/* Port wide control signals */                                                   
#define ground_CTL                    (* (reg8 *) ground__CTL)
/* Drive Modes */
#define ground_DM0                    (* (reg8 *) ground__DM0) 
#define ground_DM1                    (* (reg8 *) ground__DM1)
#define ground_DM2                    (* (reg8 *) ground__DM2) 
/* Input Buffer Disable Override */
#define ground_INP_DIS                (* (reg8 *) ground__INP_DIS)
/* LCD Common or Segment Drive */
#define ground_LCD_COM_SEG            (* (reg8 *) ground__LCD_COM_SEG)
/* Enable Segment LCD */
#define ground_LCD_EN                 (* (reg8 *) ground__LCD_EN)
/* Slew Rate Control */
#define ground_SLW                    (* (reg8 *) ground__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ground_PRTDSI__CAPS_SEL       (* (reg8 *) ground__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ground_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ground__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ground_PRTDSI__OE_SEL0        (* (reg8 *) ground__PRTDSI__OE_SEL0) 
#define ground_PRTDSI__OE_SEL1        (* (reg8 *) ground__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ground_PRTDSI__OUT_SEL0       (* (reg8 *) ground__PRTDSI__OUT_SEL0) 
#define ground_PRTDSI__OUT_SEL1       (* (reg8 *) ground__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ground_PRTDSI__SYNC_OUT       (* (reg8 *) ground__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ground__SIO_CFG)
    #define ground_SIO_HYST_EN        (* (reg8 *) ground__SIO_HYST_EN)
    #define ground_SIO_REG_HIFREQ     (* (reg8 *) ground__SIO_REG_HIFREQ)
    #define ground_SIO_CFG            (* (reg8 *) ground__SIO_CFG)
    #define ground_SIO_DIFF           (* (reg8 *) ground__SIO_DIFF)
#endif /* (ground__SIO_CFG) */

/* Interrupt Registers */
#if defined(ground__INTSTAT)
    #define ground_INTSTAT            (* (reg8 *) ground__INTSTAT)
    #define ground_SNAP               (* (reg8 *) ground__SNAP)
    
	#define ground_0_INTTYPE_REG 		(* (reg8 *) ground__0__INTTYPE)
#endif /* (ground__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ground_H */


/* [] END OF FILE */
