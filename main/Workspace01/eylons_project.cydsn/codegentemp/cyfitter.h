/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.4
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2020 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* PWM_1 */
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A0_REG CYREG_B1_UDB04_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__A1_REG CYREG_B1_UDB04_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D0_REG CYREG_B1_UDB04_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__D1_REG CYREG_B1_UDB04_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F0_REG CYREG_B1_UDB04_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u0__F1_REG CYREG_B1_UDB04_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A0_REG CYREG_B1_UDB05_06_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_A1_REG CYREG_B1_UDB05_06_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D0_REG CYREG_B1_UDB05_06_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_D1_REG CYREG_B1_UDB05_06_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB05_06_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F0_REG CYREG_B1_UDB05_06_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__16BIT_F1_REG CYREG_B1_UDB05_06_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_A1_REG CYREG_B1_UDB05_A0_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A0_REG CYREG_B1_UDB05_A0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__A1_REG CYREG_B1_UDB05_A1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_D1_REG CYREG_B1_UDB05_D0_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D0_REG CYREG_B1_UDB05_D0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__D1_REG CYREG_B1_UDB05_D1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__DP_AUX_CTL_REG CYREG_B1_UDB05_ACTL
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_F1_REG CYREG_B1_UDB05_F0_F1
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F0_REG CYREG_B1_UDB05_F0
#define PWM_1_PWMUDB_sP16_pwmdp_u1__F1_REG CYREG_B1_UDB05_F1

/* mp_led */
#define mp_led__0__INTTYPE CYREG_PICU2_INTTYPE1
#define mp_led__0__MASK 0x02u
#define mp_led__0__PC CYREG_PRT2_PC1
#define mp_led__0__PORT 2u
#define mp_led__0__SHIFT 1u
#define mp_led__AG CYREG_PRT2_AG
#define mp_led__AMUX CYREG_PRT2_AMUX
#define mp_led__BIE CYREG_PRT2_BIE
#define mp_led__BIT_MASK CYREG_PRT2_BIT_MASK
#define mp_led__BYP CYREG_PRT2_BYP
#define mp_led__CTL CYREG_PRT2_CTL
#define mp_led__DM0 CYREG_PRT2_DM0
#define mp_led__DM1 CYREG_PRT2_DM1
#define mp_led__DM2 CYREG_PRT2_DM2
#define mp_led__DR CYREG_PRT2_DR
#define mp_led__INP_DIS CYREG_PRT2_INP_DIS
#define mp_led__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define mp_led__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define mp_led__LCD_EN CYREG_PRT2_LCD_EN
#define mp_led__MASK 0x02u
#define mp_led__PORT 2u
#define mp_led__PRT CYREG_PRT2_PRT
#define mp_led__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define mp_led__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define mp_led__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define mp_led__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define mp_led__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define mp_led__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define mp_led__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define mp_led__PS CYREG_PRT2_PS
#define mp_led__SHIFT 1u
#define mp_led__SLW CYREG_PRT2_SLW

/* Clock_1 */
#define Clock_1__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Clock_1__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Clock_1__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Clock_1__CFG2_SRC_SEL_MASK 0x07u
#define Clock_1__INDEX 0x00u
#define Clock_1__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_1__PM_ACT_MSK 0x01u
#define Clock_1__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_1__PM_STBY_MSK 0x01u

/* Clock_2 */
#define Clock_2__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define Clock_2__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define Clock_2__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define Clock_2__CFG2_SRC_SEL_MASK 0x07u
#define Clock_2__INDEX 0x01u
#define Clock_2__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Clock_2__PM_ACT_MSK 0x02u
#define Clock_2__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Clock_2__PM_STBY_MSK 0x02u

/* Opamp_1 */
#define Opamp_1_ABuf__CR CYREG_OPAMP3_CR
#define Opamp_1_ABuf__MX CYREG_OPAMP3_MX
#define Opamp_1_ABuf__NPUMP_OPAMP_TR0 CYREG_NPUMP_OPAMP_TR0
#define Opamp_1_ABuf__PM_ACT_CFG CYREG_PM_ACT_CFG4
#define Opamp_1_ABuf__PM_ACT_MSK 0x08u
#define Opamp_1_ABuf__PM_STBY_CFG CYREG_PM_STBY_CFG4
#define Opamp_1_ABuf__PM_STBY_MSK 0x08u
#define Opamp_1_ABuf__RSVD CYREG_OPAMP3_RSVD
#define Opamp_1_ABuf__SW CYREG_OPAMP3_SW
#define Opamp_1_ABuf__TR0 CYREG_OPAMP3_TR0
#define Opamp_1_ABuf__TR1 CYREG_OPAMP3_TR1

/* VDAC8_1 */
#define VDAC8_1_viDAC8__CR0 CYREG_DAC3_CR0
#define VDAC8_1_viDAC8__CR1 CYREG_DAC3_CR1
#define VDAC8_1_viDAC8__D CYREG_DAC3_D
#define VDAC8_1_viDAC8__PM_ACT_CFG CYREG_PM_ACT_CFG8
#define VDAC8_1_viDAC8__PM_ACT_MSK 0x08u
#define VDAC8_1_viDAC8__PM_STBY_CFG CYREG_PM_STBY_CFG8
#define VDAC8_1_viDAC8__PM_STBY_MSK 0x08u
#define VDAC8_1_viDAC8__STROBE CYREG_DAC3_STROBE
#define VDAC8_1_viDAC8__SW0 CYREG_DAC3_SW0
#define VDAC8_1_viDAC8__SW2 CYREG_DAC3_SW2
#define VDAC8_1_viDAC8__SW3 CYREG_DAC3_SW3
#define VDAC8_1_viDAC8__SW4 CYREG_DAC3_SW4
#define VDAC8_1_viDAC8__TR CYREG_DAC3_TR
#define VDAC8_1_viDAC8__TRIM__M1 CYREG_FLSHID_CUST_TABLES_DAC3_M1
#define VDAC8_1_viDAC8__TRIM__M2 CYREG_FLSHID_CUST_TABLES_DAC3_M2
#define VDAC8_1_viDAC8__TRIM__M3 CYREG_FLSHID_CUST_TABLES_DAC3_M3
#define VDAC8_1_viDAC8__TRIM__M4 CYREG_FLSHID_CUST_TABLES_DAC3_M4
#define VDAC8_1_viDAC8__TRIM__M5 CYREG_FLSHID_CUST_TABLES_DAC3_M5
#define VDAC8_1_viDAC8__TRIM__M6 CYREG_FLSHID_CUST_TABLES_DAC3_M6
#define VDAC8_1_viDAC8__TRIM__M7 CYREG_FLSHID_CUST_TABLES_DAC3_M7
#define VDAC8_1_viDAC8__TRIM__M8 CYREG_FLSHID_CUST_TABLES_DAC3_M8
#define VDAC8_1_viDAC8__TST CYREG_DAC3_TST

/* pulse_out */
#define pulse_out__0__INTTYPE CYREG_PICU2_INTTYPE4
#define pulse_out__0__MASK 0x10u
#define pulse_out__0__PC CYREG_PRT2_PC4
#define pulse_out__0__PORT 2u
#define pulse_out__0__SHIFT 4u
#define pulse_out__AG CYREG_PRT2_AG
#define pulse_out__AMUX CYREG_PRT2_AMUX
#define pulse_out__BIE CYREG_PRT2_BIE
#define pulse_out__BIT_MASK CYREG_PRT2_BIT_MASK
#define pulse_out__BYP CYREG_PRT2_BYP
#define pulse_out__CTL CYREG_PRT2_CTL
#define pulse_out__DM0 CYREG_PRT2_DM0
#define pulse_out__DM1 CYREG_PRT2_DM1
#define pulse_out__DM2 CYREG_PRT2_DM2
#define pulse_out__DR CYREG_PRT2_DR
#define pulse_out__INP_DIS CYREG_PRT2_INP_DIS
#define pulse_out__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define pulse_out__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define pulse_out__LCD_EN CYREG_PRT2_LCD_EN
#define pulse_out__MASK 0x10u
#define pulse_out__PORT 2u
#define pulse_out__PRT CYREG_PRT2_PRT
#define pulse_out__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define pulse_out__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define pulse_out__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define pulse_out__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define pulse_out__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define pulse_out__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define pulse_out__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define pulse_out__PS CYREG_PRT2_PS
#define pulse_out__SHIFT 4u
#define pulse_out__SLW CYREG_PRT2_SLW

/* leds_enable */
#define leds_enable__0__INTTYPE CYREG_PICU1_INTTYPE5
#define leds_enable__0__MASK 0x20u
#define leds_enable__0__PC CYREG_PRT1_PC5
#define leds_enable__0__PORT 1u
#define leds_enable__0__SHIFT 5u
#define leds_enable__AG CYREG_PRT1_AG
#define leds_enable__AMUX CYREG_PRT1_AMUX
#define leds_enable__BIE CYREG_PRT1_BIE
#define leds_enable__BIT_MASK CYREG_PRT1_BIT_MASK
#define leds_enable__BYP CYREG_PRT1_BYP
#define leds_enable__CTL CYREG_PRT1_CTL
#define leds_enable__DM0 CYREG_PRT1_DM0
#define leds_enable__DM1 CYREG_PRT1_DM1
#define leds_enable__DM2 CYREG_PRT1_DM2
#define leds_enable__DR CYREG_PRT1_DR
#define leds_enable__INP_DIS CYREG_PRT1_INP_DIS
#define leds_enable__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define leds_enable__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define leds_enable__LCD_EN CYREG_PRT1_LCD_EN
#define leds_enable__MASK 0x20u
#define leds_enable__PORT 1u
#define leds_enable__PRT CYREG_PRT1_PRT
#define leds_enable__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define leds_enable__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define leds_enable__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define leds_enable__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define leds_enable__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define leds_enable__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define leds_enable__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define leds_enable__PS CYREG_PRT1_PS
#define leds_enable__SHIFT 5u
#define leds_enable__SLW CYREG_PRT1_SLW

/* sensor_left */
#define sensor_left__0__INTTYPE CYREG_PICU2_INTTYPE0
#define sensor_left__0__MASK 0x01u
#define sensor_left__0__PC CYREG_PRT2_PC0
#define sensor_left__0__PORT 2u
#define sensor_left__0__SHIFT 0u
#define sensor_left__AG CYREG_PRT2_AG
#define sensor_left__AMUX CYREG_PRT2_AMUX
#define sensor_left__BIE CYREG_PRT2_BIE
#define sensor_left__BIT_MASK CYREG_PRT2_BIT_MASK
#define sensor_left__BYP CYREG_PRT2_BYP
#define sensor_left__CTL CYREG_PRT2_CTL
#define sensor_left__DM0 CYREG_PRT2_DM0
#define sensor_left__DM1 CYREG_PRT2_DM1
#define sensor_left__DM2 CYREG_PRT2_DM2
#define sensor_left__DR CYREG_PRT2_DR
#define sensor_left__INP_DIS CYREG_PRT2_INP_DIS
#define sensor_left__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define sensor_left__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define sensor_left__LCD_EN CYREG_PRT2_LCD_EN
#define sensor_left__MASK 0x01u
#define sensor_left__PORT 2u
#define sensor_left__PRT CYREG_PRT2_PRT
#define sensor_left__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define sensor_left__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define sensor_left__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define sensor_left__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define sensor_left__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define sensor_left__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define sensor_left__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define sensor_left__PS CYREG_PRT2_PS
#define sensor_left__SHIFT 0u
#define sensor_left__SLW CYREG_PRT2_SLW

/* leds_control */
#define leds_control__0__INTTYPE CYREG_PICU1_INTTYPE6
#define leds_control__0__MASK 0x40u
#define leds_control__0__PC CYREG_PRT1_PC6
#define leds_control__0__PORT 1u
#define leds_control__0__SHIFT 6u
#define leds_control__AG CYREG_PRT1_AG
#define leds_control__AMUX CYREG_PRT1_AMUX
#define leds_control__BIE CYREG_PRT1_BIE
#define leds_control__BIT_MASK CYREG_PRT1_BIT_MASK
#define leds_control__BYP CYREG_PRT1_BYP
#define leds_control__CTL CYREG_PRT1_CTL
#define leds_control__DM0 CYREG_PRT1_DM0
#define leds_control__DM1 CYREG_PRT1_DM1
#define leds_control__DM2 CYREG_PRT1_DM2
#define leds_control__DR CYREG_PRT1_DR
#define leds_control__INP_DIS CYREG_PRT1_INP_DIS
#define leds_control__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define leds_control__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define leds_control__LCD_EN CYREG_PRT1_LCD_EN
#define leds_control__MASK 0x40u
#define leds_control__PORT 1u
#define leds_control__PRT CYREG_PRT1_PRT
#define leds_control__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define leds_control__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define leds_control__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define leds_control__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define leds_control__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define leds_control__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define leds_control__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define leds_control__PS CYREG_PRT1_PS
#define leds_control__SHIFT 6u
#define leds_control__SLW CYREG_PRT1_SLW

/* sensor_right */
#define sensor_right__0__INTTYPE CYREG_PICU2_INTTYPE2
#define sensor_right__0__MASK 0x04u
#define sensor_right__0__PC CYREG_PRT2_PC2
#define sensor_right__0__PORT 2u
#define sensor_right__0__SHIFT 2u
#define sensor_right__AG CYREG_PRT2_AG
#define sensor_right__AMUX CYREG_PRT2_AMUX
#define sensor_right__BIE CYREG_PRT2_BIE
#define sensor_right__BIT_MASK CYREG_PRT2_BIT_MASK
#define sensor_right__BYP CYREG_PRT2_BYP
#define sensor_right__CTL CYREG_PRT2_CTL
#define sensor_right__DM0 CYREG_PRT2_DM0
#define sensor_right__DM1 CYREG_PRT2_DM1
#define sensor_right__DM2 CYREG_PRT2_DM2
#define sensor_right__DR CYREG_PRT2_DR
#define sensor_right__INP_DIS CYREG_PRT2_INP_DIS
#define sensor_right__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define sensor_right__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define sensor_right__LCD_EN CYREG_PRT2_LCD_EN
#define sensor_right__MASK 0x04u
#define sensor_right__PORT 2u
#define sensor_right__PRT CYREG_PRT2_PRT
#define sensor_right__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define sensor_right__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define sensor_right__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define sensor_right__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define sensor_right__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define sensor_right__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define sensor_right__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define sensor_right__PS CYREG_PRT2_PS
#define sensor_right__SHIFT 2u
#define sensor_right__SLW CYREG_PRT2_SLW

/* direction_out */
#define direction_out__0__INTTYPE CYREG_PICU2_INTTYPE5
#define direction_out__0__MASK 0x20u
#define direction_out__0__PC CYREG_PRT2_PC5
#define direction_out__0__PORT 2u
#define direction_out__0__SHIFT 5u
#define direction_out__AG CYREG_PRT2_AG
#define direction_out__AMUX CYREG_PRT2_AMUX
#define direction_out__BIE CYREG_PRT2_BIE
#define direction_out__BIT_MASK CYREG_PRT2_BIT_MASK
#define direction_out__BYP CYREG_PRT2_BYP
#define direction_out__CTL CYREG_PRT2_CTL
#define direction_out__DM0 CYREG_PRT2_DM0
#define direction_out__DM1 CYREG_PRT2_DM1
#define direction_out__DM2 CYREG_PRT2_DM2
#define direction_out__DR CYREG_PRT2_DR
#define direction_out__INP_DIS CYREG_PRT2_INP_DIS
#define direction_out__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define direction_out__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define direction_out__LCD_EN CYREG_PRT2_LCD_EN
#define direction_out__MASK 0x20u
#define direction_out__PORT 2u
#define direction_out__PRT CYREG_PRT2_PRT
#define direction_out__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define direction_out__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define direction_out__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define direction_out__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define direction_out__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define direction_out__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define direction_out__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define direction_out__PS CYREG_PRT2_PS
#define direction_out__SHIFT 5u
#define direction_out__SLW CYREG_PRT2_SLW

/* operation_input */
#define operation_input__0__INTTYPE CYREG_PICU0_INTTYPE0
#define operation_input__0__MASK 0x01u
#define operation_input__0__PC CYREG_PRT0_PC0
#define operation_input__0__PORT 0u
#define operation_input__0__SHIFT 0u
#define operation_input__AG CYREG_PRT0_AG
#define operation_input__AMUX CYREG_PRT0_AMUX
#define operation_input__BIE CYREG_PRT0_BIE
#define operation_input__BIT_MASK CYREG_PRT0_BIT_MASK
#define operation_input__BYP CYREG_PRT0_BYP
#define operation_input__CTL CYREG_PRT0_CTL
#define operation_input__DM0 CYREG_PRT0_DM0
#define operation_input__DM1 CYREG_PRT0_DM1
#define operation_input__DM2 CYREG_PRT0_DM2
#define operation_input__DR CYREG_PRT0_DR
#define operation_input__INP_DIS CYREG_PRT0_INP_DIS
#define operation_input__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU0_BASE
#define operation_input__LCD_COM_SEG CYREG_PRT0_LCD_COM_SEG
#define operation_input__LCD_EN CYREG_PRT0_LCD_EN
#define operation_input__MASK 0x01u
#define operation_input__PORT 0u
#define operation_input__PRT CYREG_PRT0_PRT
#define operation_input__PRTDSI__CAPS_SEL CYREG_PRT0_CAPS_SEL
#define operation_input__PRTDSI__DBL_SYNC_IN CYREG_PRT0_DBL_SYNC_IN
#define operation_input__PRTDSI__OE_SEL0 CYREG_PRT0_OE_SEL0
#define operation_input__PRTDSI__OE_SEL1 CYREG_PRT0_OE_SEL1
#define operation_input__PRTDSI__OUT_SEL0 CYREG_PRT0_OUT_SEL0
#define operation_input__PRTDSI__OUT_SEL1 CYREG_PRT0_OUT_SEL1
#define operation_input__PRTDSI__SYNC_OUT CYREG_PRT0_SYNC_OUT
#define operation_input__PS CYREG_PRT0_PS
#define operation_input__SHIFT 0u
#define operation_input__SLW CYREG_PRT0_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "eylons_project"
#define CY_VERSION "PSoC Creator  4.4"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 26u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 26u
#define CYDEV_CHIP_MEMBER_4AA 25u
#define CYDEV_CHIP_MEMBER_4AB 30u
#define CYDEV_CHIP_MEMBER_4AC 14u
#define CYDEV_CHIP_MEMBER_4AD 15u
#define CYDEV_CHIP_MEMBER_4AE 16u
#define CYDEV_CHIP_MEMBER_4D 20u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 27u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 24u
#define CYDEV_CHIP_MEMBER_4I 32u
#define CYDEV_CHIP_MEMBER_4J 21u
#define CYDEV_CHIP_MEMBER_4K 22u
#define CYDEV_CHIP_MEMBER_4L 31u
#define CYDEV_CHIP_MEMBER_4M 29u
#define CYDEV_CHIP_MEMBER_4N 11u
#define CYDEV_CHIP_MEMBER_4O 8u
#define CYDEV_CHIP_MEMBER_4P 28u
#define CYDEV_CHIP_MEMBER_4Q 17u
#define CYDEV_CHIP_MEMBER_4R 9u
#define CYDEV_CHIP_MEMBER_4S 12u
#define CYDEV_CHIP_MEMBER_4T 10u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 23u
#define CYDEV_CHIP_MEMBER_4W 13u
#define CYDEV_CHIP_MEMBER_4X 7u
#define CYDEV_CHIP_MEMBER_4Y 18u
#define CYDEV_CHIP_MEMBER_4Z 19u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 33u
#define CYDEV_CHIP_MEMBER_FM3 37u
#define CYDEV_CHIP_MEMBER_FM4 38u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 34u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 35u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 36u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AD_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4AE_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4W_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4X_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000000u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define Dedicated_Output__INTTYPE CYREG_PICU3_INTTYPE7
#define Dedicated_Output__MASK 0x80u
#define Dedicated_Output__PC CYREG_PRT3_PC7
#define Dedicated_Output__PORT 3u
#define Dedicated_Output__SHIFT 7u
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
