/*******************************************************************************
* File Name: sensor_right_in.h  
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

#if !defined(CY_PINS_sensor_right_in_H) /* Pins sensor_right_in_H */
#define CY_PINS_sensor_right_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "sensor_right_in_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 sensor_right_in__PORT == 15 && ((sensor_right_in__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    sensor_right_in_Write(uint8 value);
void    sensor_right_in_SetDriveMode(uint8 mode);
uint8   sensor_right_in_ReadDataReg(void);
uint8   sensor_right_in_Read(void);
void    sensor_right_in_SetInterruptMode(uint16 position, uint16 mode);
uint8   sensor_right_in_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the sensor_right_in_SetDriveMode() function.
     *  @{
     */
        #define sensor_right_in_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define sensor_right_in_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define sensor_right_in_DM_RES_UP          PIN_DM_RES_UP
        #define sensor_right_in_DM_RES_DWN         PIN_DM_RES_DWN
        #define sensor_right_in_DM_OD_LO           PIN_DM_OD_LO
        #define sensor_right_in_DM_OD_HI           PIN_DM_OD_HI
        #define sensor_right_in_DM_STRONG          PIN_DM_STRONG
        #define sensor_right_in_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define sensor_right_in_MASK               sensor_right_in__MASK
#define sensor_right_in_SHIFT              sensor_right_in__SHIFT
#define sensor_right_in_WIDTH              1u

/* Interrupt constants */
#if defined(sensor_right_in__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in sensor_right_in_SetInterruptMode() function.
     *  @{
     */
        #define sensor_right_in_INTR_NONE      (uint16)(0x0000u)
        #define sensor_right_in_INTR_RISING    (uint16)(0x0001u)
        #define sensor_right_in_INTR_FALLING   (uint16)(0x0002u)
        #define sensor_right_in_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define sensor_right_in_INTR_MASK      (0x01u) 
#endif /* (sensor_right_in__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define sensor_right_in_PS                     (* (reg8 *) sensor_right_in__PS)
/* Data Register */
#define sensor_right_in_DR                     (* (reg8 *) sensor_right_in__DR)
/* Port Number */
#define sensor_right_in_PRT_NUM                (* (reg8 *) sensor_right_in__PRT) 
/* Connect to Analog Globals */                                                  
#define sensor_right_in_AG                     (* (reg8 *) sensor_right_in__AG)                       
/* Analog MUX bux enable */
#define sensor_right_in_AMUX                   (* (reg8 *) sensor_right_in__AMUX) 
/* Bidirectional Enable */                                                        
#define sensor_right_in_BIE                    (* (reg8 *) sensor_right_in__BIE)
/* Bit-mask for Aliased Register Access */
#define sensor_right_in_BIT_MASK               (* (reg8 *) sensor_right_in__BIT_MASK)
/* Bypass Enable */
#define sensor_right_in_BYP                    (* (reg8 *) sensor_right_in__BYP)
/* Port wide control signals */                                                   
#define sensor_right_in_CTL                    (* (reg8 *) sensor_right_in__CTL)
/* Drive Modes */
#define sensor_right_in_DM0                    (* (reg8 *) sensor_right_in__DM0) 
#define sensor_right_in_DM1                    (* (reg8 *) sensor_right_in__DM1)
#define sensor_right_in_DM2                    (* (reg8 *) sensor_right_in__DM2) 
/* Input Buffer Disable Override */
#define sensor_right_in_INP_DIS                (* (reg8 *) sensor_right_in__INP_DIS)
/* LCD Common or Segment Drive */
#define sensor_right_in_LCD_COM_SEG            (* (reg8 *) sensor_right_in__LCD_COM_SEG)
/* Enable Segment LCD */
#define sensor_right_in_LCD_EN                 (* (reg8 *) sensor_right_in__LCD_EN)
/* Slew Rate Control */
#define sensor_right_in_SLW                    (* (reg8 *) sensor_right_in__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define sensor_right_in_PRTDSI__CAPS_SEL       (* (reg8 *) sensor_right_in__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define sensor_right_in_PRTDSI__DBL_SYNC_IN    (* (reg8 *) sensor_right_in__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define sensor_right_in_PRTDSI__OE_SEL0        (* (reg8 *) sensor_right_in__PRTDSI__OE_SEL0) 
#define sensor_right_in_PRTDSI__OE_SEL1        (* (reg8 *) sensor_right_in__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define sensor_right_in_PRTDSI__OUT_SEL0       (* (reg8 *) sensor_right_in__PRTDSI__OUT_SEL0) 
#define sensor_right_in_PRTDSI__OUT_SEL1       (* (reg8 *) sensor_right_in__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define sensor_right_in_PRTDSI__SYNC_OUT       (* (reg8 *) sensor_right_in__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(sensor_right_in__SIO_CFG)
    #define sensor_right_in_SIO_HYST_EN        (* (reg8 *) sensor_right_in__SIO_HYST_EN)
    #define sensor_right_in_SIO_REG_HIFREQ     (* (reg8 *) sensor_right_in__SIO_REG_HIFREQ)
    #define sensor_right_in_SIO_CFG            (* (reg8 *) sensor_right_in__SIO_CFG)
    #define sensor_right_in_SIO_DIFF           (* (reg8 *) sensor_right_in__SIO_DIFF)
#endif /* (sensor_right_in__SIO_CFG) */

/* Interrupt Registers */
#if defined(sensor_right_in__INTSTAT)
    #define sensor_right_in_INTSTAT            (* (reg8 *) sensor_right_in__INTSTAT)
    #define sensor_right_in_SNAP               (* (reg8 *) sensor_right_in__SNAP)
    
	#define sensor_right_in_0_INTTYPE_REG 		(* (reg8 *) sensor_right_in__0__INTTYPE)
#endif /* (sensor_right_in__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_sensor_right_in_H */


/* [] END OF FILE */
