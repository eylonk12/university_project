/*******************************************************************************
* File Name: in23.h  
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

#if !defined(CY_PINS_in23_H) /* Pins in23_H */
#define CY_PINS_in23_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "in23_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 in23__PORT == 15 && ((in23__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    in23_Write(uint8 value);
void    in23_SetDriveMode(uint8 mode);
uint8   in23_ReadDataReg(void);
uint8   in23_Read(void);
void    in23_SetInterruptMode(uint16 position, uint16 mode);
uint8   in23_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the in23_SetDriveMode() function.
     *  @{
     */
        #define in23_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define in23_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define in23_DM_RES_UP          PIN_DM_RES_UP
        #define in23_DM_RES_DWN         PIN_DM_RES_DWN
        #define in23_DM_OD_LO           PIN_DM_OD_LO
        #define in23_DM_OD_HI           PIN_DM_OD_HI
        #define in23_DM_STRONG          PIN_DM_STRONG
        #define in23_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define in23_MASK               in23__MASK
#define in23_SHIFT              in23__SHIFT
#define in23_WIDTH              1u

/* Interrupt constants */
#if defined(in23__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in in23_SetInterruptMode() function.
     *  @{
     */
        #define in23_INTR_NONE      (uint16)(0x0000u)
        #define in23_INTR_RISING    (uint16)(0x0001u)
        #define in23_INTR_FALLING   (uint16)(0x0002u)
        #define in23_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define in23_INTR_MASK      (0x01u) 
#endif /* (in23__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define in23_PS                     (* (reg8 *) in23__PS)
/* Data Register */
#define in23_DR                     (* (reg8 *) in23__DR)
/* Port Number */
#define in23_PRT_NUM                (* (reg8 *) in23__PRT) 
/* Connect to Analog Globals */                                                  
#define in23_AG                     (* (reg8 *) in23__AG)                       
/* Analog MUX bux enable */
#define in23_AMUX                   (* (reg8 *) in23__AMUX) 
/* Bidirectional Enable */                                                        
#define in23_BIE                    (* (reg8 *) in23__BIE)
/* Bit-mask for Aliased Register Access */
#define in23_BIT_MASK               (* (reg8 *) in23__BIT_MASK)
/* Bypass Enable */
#define in23_BYP                    (* (reg8 *) in23__BYP)
/* Port wide control signals */                                                   
#define in23_CTL                    (* (reg8 *) in23__CTL)
/* Drive Modes */
#define in23_DM0                    (* (reg8 *) in23__DM0) 
#define in23_DM1                    (* (reg8 *) in23__DM1)
#define in23_DM2                    (* (reg8 *) in23__DM2) 
/* Input Buffer Disable Override */
#define in23_INP_DIS                (* (reg8 *) in23__INP_DIS)
/* LCD Common or Segment Drive */
#define in23_LCD_COM_SEG            (* (reg8 *) in23__LCD_COM_SEG)
/* Enable Segment LCD */
#define in23_LCD_EN                 (* (reg8 *) in23__LCD_EN)
/* Slew Rate Control */
#define in23_SLW                    (* (reg8 *) in23__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define in23_PRTDSI__CAPS_SEL       (* (reg8 *) in23__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define in23_PRTDSI__DBL_SYNC_IN    (* (reg8 *) in23__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define in23_PRTDSI__OE_SEL0        (* (reg8 *) in23__PRTDSI__OE_SEL0) 
#define in23_PRTDSI__OE_SEL1        (* (reg8 *) in23__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define in23_PRTDSI__OUT_SEL0       (* (reg8 *) in23__PRTDSI__OUT_SEL0) 
#define in23_PRTDSI__OUT_SEL1       (* (reg8 *) in23__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define in23_PRTDSI__SYNC_OUT       (* (reg8 *) in23__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(in23__SIO_CFG)
    #define in23_SIO_HYST_EN        (* (reg8 *) in23__SIO_HYST_EN)
    #define in23_SIO_REG_HIFREQ     (* (reg8 *) in23__SIO_REG_HIFREQ)
    #define in23_SIO_CFG            (* (reg8 *) in23__SIO_CFG)
    #define in23_SIO_DIFF           (* (reg8 *) in23__SIO_DIFF)
#endif /* (in23__SIO_CFG) */

/* Interrupt Registers */
#if defined(in23__INTSTAT)
    #define in23_INTSTAT            (* (reg8 *) in23__INTSTAT)
    #define in23_SNAP               (* (reg8 *) in23__SNAP)
    
	#define in23_0_INTTYPE_REG 		(* (reg8 *) in23__0__INTTYPE)
#endif /* (in23__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_in23_H */


/* [] END OF FILE */
