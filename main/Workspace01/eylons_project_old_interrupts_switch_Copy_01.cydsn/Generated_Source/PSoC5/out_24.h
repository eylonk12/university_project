/*******************************************************************************
* File Name: out_24.h  
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

#if !defined(CY_PINS_out_24_H) /* Pins out_24_H */
#define CY_PINS_out_24_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "out_24_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 out_24__PORT == 15 && ((out_24__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    out_24_Write(uint8 value);
void    out_24_SetDriveMode(uint8 mode);
uint8   out_24_ReadDataReg(void);
uint8   out_24_Read(void);
void    out_24_SetInterruptMode(uint16 position, uint16 mode);
uint8   out_24_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the out_24_SetDriveMode() function.
     *  @{
     */
        #define out_24_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define out_24_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define out_24_DM_RES_UP          PIN_DM_RES_UP
        #define out_24_DM_RES_DWN         PIN_DM_RES_DWN
        #define out_24_DM_OD_LO           PIN_DM_OD_LO
        #define out_24_DM_OD_HI           PIN_DM_OD_HI
        #define out_24_DM_STRONG          PIN_DM_STRONG
        #define out_24_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define out_24_MASK               out_24__MASK
#define out_24_SHIFT              out_24__SHIFT
#define out_24_WIDTH              1u

/* Interrupt constants */
#if defined(out_24__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in out_24_SetInterruptMode() function.
     *  @{
     */
        #define out_24_INTR_NONE      (uint16)(0x0000u)
        #define out_24_INTR_RISING    (uint16)(0x0001u)
        #define out_24_INTR_FALLING   (uint16)(0x0002u)
        #define out_24_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define out_24_INTR_MASK      (0x01u) 
#endif /* (out_24__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define out_24_PS                     (* (reg8 *) out_24__PS)
/* Data Register */
#define out_24_DR                     (* (reg8 *) out_24__DR)
/* Port Number */
#define out_24_PRT_NUM                (* (reg8 *) out_24__PRT) 
/* Connect to Analog Globals */                                                  
#define out_24_AG                     (* (reg8 *) out_24__AG)                       
/* Analog MUX bux enable */
#define out_24_AMUX                   (* (reg8 *) out_24__AMUX) 
/* Bidirectional Enable */                                                        
#define out_24_BIE                    (* (reg8 *) out_24__BIE)
/* Bit-mask for Aliased Register Access */
#define out_24_BIT_MASK               (* (reg8 *) out_24__BIT_MASK)
/* Bypass Enable */
#define out_24_BYP                    (* (reg8 *) out_24__BYP)
/* Port wide control signals */                                                   
#define out_24_CTL                    (* (reg8 *) out_24__CTL)
/* Drive Modes */
#define out_24_DM0                    (* (reg8 *) out_24__DM0) 
#define out_24_DM1                    (* (reg8 *) out_24__DM1)
#define out_24_DM2                    (* (reg8 *) out_24__DM2) 
/* Input Buffer Disable Override */
#define out_24_INP_DIS                (* (reg8 *) out_24__INP_DIS)
/* LCD Common or Segment Drive */
#define out_24_LCD_COM_SEG            (* (reg8 *) out_24__LCD_COM_SEG)
/* Enable Segment LCD */
#define out_24_LCD_EN                 (* (reg8 *) out_24__LCD_EN)
/* Slew Rate Control */
#define out_24_SLW                    (* (reg8 *) out_24__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define out_24_PRTDSI__CAPS_SEL       (* (reg8 *) out_24__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define out_24_PRTDSI__DBL_SYNC_IN    (* (reg8 *) out_24__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define out_24_PRTDSI__OE_SEL0        (* (reg8 *) out_24__PRTDSI__OE_SEL0) 
#define out_24_PRTDSI__OE_SEL1        (* (reg8 *) out_24__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define out_24_PRTDSI__OUT_SEL0       (* (reg8 *) out_24__PRTDSI__OUT_SEL0) 
#define out_24_PRTDSI__OUT_SEL1       (* (reg8 *) out_24__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define out_24_PRTDSI__SYNC_OUT       (* (reg8 *) out_24__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(out_24__SIO_CFG)
    #define out_24_SIO_HYST_EN        (* (reg8 *) out_24__SIO_HYST_EN)
    #define out_24_SIO_REG_HIFREQ     (* (reg8 *) out_24__SIO_REG_HIFREQ)
    #define out_24_SIO_CFG            (* (reg8 *) out_24__SIO_CFG)
    #define out_24_SIO_DIFF           (* (reg8 *) out_24__SIO_DIFF)
#endif /* (out_24__SIO_CFG) */

/* Interrupt Registers */
#if defined(out_24__INTSTAT)
    #define out_24_INTSTAT            (* (reg8 *) out_24__INTSTAT)
    #define out_24_SNAP               (* (reg8 *) out_24__SNAP)
    
	#define out_24_0_INTTYPE_REG 		(* (reg8 *) out_24__0__INTTYPE)
#endif /* (out_24__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_out_24_H */


/* [] END OF FILE */
