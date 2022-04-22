/*******************************************************************************
* File Name: out23.h  
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

#if !defined(CY_PINS_out23_H) /* Pins out23_H */
#define CY_PINS_out23_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "out23_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 out23__PORT == 15 && ((out23__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    out23_Write(uint8 value);
void    out23_SetDriveMode(uint8 mode);
uint8   out23_ReadDataReg(void);
uint8   out23_Read(void);
void    out23_SetInterruptMode(uint16 position, uint16 mode);
uint8   out23_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the out23_SetDriveMode() function.
     *  @{
     */
        #define out23_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define out23_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define out23_DM_RES_UP          PIN_DM_RES_UP
        #define out23_DM_RES_DWN         PIN_DM_RES_DWN
        #define out23_DM_OD_LO           PIN_DM_OD_LO
        #define out23_DM_OD_HI           PIN_DM_OD_HI
        #define out23_DM_STRONG          PIN_DM_STRONG
        #define out23_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define out23_MASK               out23__MASK
#define out23_SHIFT              out23__SHIFT
#define out23_WIDTH              1u

/* Interrupt constants */
#if defined(out23__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in out23_SetInterruptMode() function.
     *  @{
     */
        #define out23_INTR_NONE      (uint16)(0x0000u)
        #define out23_INTR_RISING    (uint16)(0x0001u)
        #define out23_INTR_FALLING   (uint16)(0x0002u)
        #define out23_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define out23_INTR_MASK      (0x01u) 
#endif /* (out23__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define out23_PS                     (* (reg8 *) out23__PS)
/* Data Register */
#define out23_DR                     (* (reg8 *) out23__DR)
/* Port Number */
#define out23_PRT_NUM                (* (reg8 *) out23__PRT) 
/* Connect to Analog Globals */                                                  
#define out23_AG                     (* (reg8 *) out23__AG)                       
/* Analog MUX bux enable */
#define out23_AMUX                   (* (reg8 *) out23__AMUX) 
/* Bidirectional Enable */                                                        
#define out23_BIE                    (* (reg8 *) out23__BIE)
/* Bit-mask for Aliased Register Access */
#define out23_BIT_MASK               (* (reg8 *) out23__BIT_MASK)
/* Bypass Enable */
#define out23_BYP                    (* (reg8 *) out23__BYP)
/* Port wide control signals */                                                   
#define out23_CTL                    (* (reg8 *) out23__CTL)
/* Drive Modes */
#define out23_DM0                    (* (reg8 *) out23__DM0) 
#define out23_DM1                    (* (reg8 *) out23__DM1)
#define out23_DM2                    (* (reg8 *) out23__DM2) 
/* Input Buffer Disable Override */
#define out23_INP_DIS                (* (reg8 *) out23__INP_DIS)
/* LCD Common or Segment Drive */
#define out23_LCD_COM_SEG            (* (reg8 *) out23__LCD_COM_SEG)
/* Enable Segment LCD */
#define out23_LCD_EN                 (* (reg8 *) out23__LCD_EN)
/* Slew Rate Control */
#define out23_SLW                    (* (reg8 *) out23__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define out23_PRTDSI__CAPS_SEL       (* (reg8 *) out23__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define out23_PRTDSI__DBL_SYNC_IN    (* (reg8 *) out23__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define out23_PRTDSI__OE_SEL0        (* (reg8 *) out23__PRTDSI__OE_SEL0) 
#define out23_PRTDSI__OE_SEL1        (* (reg8 *) out23__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define out23_PRTDSI__OUT_SEL0       (* (reg8 *) out23__PRTDSI__OUT_SEL0) 
#define out23_PRTDSI__OUT_SEL1       (* (reg8 *) out23__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define out23_PRTDSI__SYNC_OUT       (* (reg8 *) out23__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(out23__SIO_CFG)
    #define out23_SIO_HYST_EN        (* (reg8 *) out23__SIO_HYST_EN)
    #define out23_SIO_REG_HIFREQ     (* (reg8 *) out23__SIO_REG_HIFREQ)
    #define out23_SIO_CFG            (* (reg8 *) out23__SIO_CFG)
    #define out23_SIO_DIFF           (* (reg8 *) out23__SIO_DIFF)
#endif /* (out23__SIO_CFG) */

/* Interrupt Registers */
#if defined(out23__INTSTAT)
    #define out23_INTSTAT            (* (reg8 *) out23__INTSTAT)
    #define out23_SNAP               (* (reg8 *) out23__SNAP)
    
	#define out23_0_INTTYPE_REG 		(* (reg8 *) out23__0__INTTYPE)
#endif /* (out23__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_out23_H */


/* [] END OF FILE */
