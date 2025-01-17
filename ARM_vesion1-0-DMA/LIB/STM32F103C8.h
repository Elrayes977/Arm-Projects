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

#define RCC ((RCC_REG_DEF_t*)RCC_u32BASE_ADDRESS)  //type casting to the base adress as structure pointer to pints to its offsets in the structer


/*********************************************************/
/*******************GPIO Registers************************/
/*********************************************************/
#define GPIO_C_u32BASE_ADDRESS 0x40011000
#define GPIO_B_u32BASE_ADDRESS 0x40010C00
#define GPIO_A_u32BASE_ADDRESS 0x40010800



typedef struct 
{
	u32 GPIO_CRL;
	u32 GPIO_CRH;
	u32 GPIO_IDR;
	u32 GPIO_ODR;
	u32 GPIO_BSRR;
	u32 GPIO_BRR;
	u32 GPIO_LCKR;
	
}GPIO_REG_DEF_t;


#define GPIO_C ((GPIO_REG_DEF_t*)GPIO_C_u32BASE_ADDRESS)
#define GPIO_B ((GPIO_REG_DEF_t*)GPIO_B_u32BASE_ADDRESS)
#define GPIO_A ((GPIO_REG_DEF_t*)GPIO_A_u32BASE_ADDRESS)

/*********************************************************/
/*******************NVIC Registers************************/
/*********************************************************/

#define NVIC_u32BASE_ADRESS 0xE000E100
#define NVIC_RESERVED_LOCATIONS 29
#define NVIC_RESERVED_LOCATIONS_2 61
#define NVIC_IPR_SIZE 				84
#define NVIC_OFFSET_REG_SIZE 		3
typedef struct
{//we use array to mak it easir to acces registers
	//we have 29 location reserved between each register
	u32  NVIC_ISER[NVIC_OFFSET_REG_SIZE];
	u32	 Reserved1[NVIC_RESERVED_LOCATIONS];

	u32  NVIC_ICER[NVIC_OFFSET_REG_SIZE];
	u32	 Reserved2[NVIC_RESERVED_LOCATIONS];


	u32  NVIC_ISPR[NVIC_OFFSET_REG_SIZE];
	u32	 Reserved3[NVIC_RESERVED_LOCATIONS];

	u32  NVIC_ICPR[NVIC_OFFSET_REG_SIZE];
	u32	 Reserved4[NVIC_RESERVED_LOCATIONS];

	u32  NVIC_IABR[NVIC_OFFSET_REG_SIZE];
	u32  Reserved5[NVIC_RESERVED_LOCATIONS_2];

	u32 NVIC_IPR[NVIC_IPR_SIZE ];



}NVIC_REG_DEF_t;

#define NVIC_REG  ((NVIC_REG_DEF_t*)NVIC_u32BASE_ADRESS)


/*********************************************************/
/*******************SCB Registers************************/
/*********************************************************/
#define SCB_u32BASE_ADRESS 0xE000ED00
#define SCB_AIRCR_OFFFSET  0x0C

#define SCB_AIRCR *((u32 *)SCB_u32BASE_ADRESS+SCB_AIRCR_OFFFSET)

/*********************************************************/
/*******************EXTI Registers************************/
/*********************************************************/
#define EXTI_u32BASE_ADRESS 0x40010400

typedef struct
{
	u32 EXTI_IMR;
	u32 EXTI_EMR;
	u32 EXTI_RTSR;
	u32 EXTI_FTSR;
	u32 EXTI_SWIER;
	u32 EXTI_PR;
}EXTI_REG_DEF_t;

#define EXTI_REG  ((EXTI_REG_DEF_t*)EXTI_u32BASE_ADRESS)

/*********************************************************/
/*******************AFIO Registers************************/
/*********************************************************/

#define AFIO_u32BASE_ADRESS 0x40010000

typedef struct
{
	u32 AFIO_EVCR;
	u32 AFIO_MAPR;
	u32 AFIO_EXTICR[4];
	u32 AFIO_MAPR2;

}AFIO_REG_DEF_t;

#define AFIO_REG  ((AFIO_REG_DEF_t*)AFIO_u32BASE_ADRESS)


/*********************************************************/
/*******************STK Registers************************/
/*********************************************************/



#define STK_u32BASE_ADRESS 0xE000E010

typedef struct
{
	u32 STK_CTRL;
	u32 STK_LOAD;
	u32 STK_VAL;
	u32 STK_CALIB;

}STK_REG_DEF_t;

#define STK_REG  ((STK_REG_DEF_t*)STK_u32BASE_ADRESS)
/*********************************************************/
/*******************DMA Registers************************/
/*********************************************************/



#define DMA_u32BASE_ADRESS 0x40020000
typedef struct
{

	u32 DMA_CCR;
	u32 DMA_CNDTR;
	u32	DMA_CPAR;
	u32	DMA_CMAR;
	u32 reserved;

}DMA_CHANEL_t;
typedef struct
{
	u32 DMA_ISR;
	u32 DMA_IFCR;

	DMA_CHANEL_t DMA_CH[7];
}DMA_REG_DEF_t;

#define DMA ((DMA_REG_DEF_t*)DMA_u32BASE_ADRESS)

#endif /*_STM32F103C8_H */
