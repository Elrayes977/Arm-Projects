/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:STM32F103C8
	
	*****************************
 */
 
#ifndef _STM32F103C8_H
#define _STM32F103C8_H

#include "STD_TYPES.h"
/*********************************************************/
/*******************RCC Registers************************/
/*********************************************************/
#define RCC_u32BASE_ADDRESS 0x40021000
typedef struct 
{
	u32 RCC_CR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_APB2RSTR;
	u32 RCC_APB1RSTR;
	u32 RCC_AHBENR;
	u32 RCC_APB2ENR;
	u32 RCC_APB1ENR;
	u32 RCC_BDCR;
	u32 RCC_CSR;
	
	
}RCC_REG_DEF_t;

#define RCC ((RCC_REG_DEF_t*)RCC_u32BASE_ADDRESS)

#endif /*_STM32F103C8_H */