/*
 * MDMA_prg.c
 *
 *  Created on: Jul 31, 2023
 *      Author: elray
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MDMA_priv.h"
#include "MDMA_config.h"
#include "MDMA_int.h"

ErrorState_t MDMA_enInit(void)
{
/*Enable CLK of DMA*/
	//RCC->RCC_AHBENR|=(1<<0);
/*Init DMA channel [0]*/
	DMA->DMA_CH[0].DMA_CCR=0x4AC2;
/* Enable DMA Interrupt from  NVIC */
	//NVIC_REG->NVIC_IABR|=(1<<0);

return SUCCES;
}

ErrorState_t MDMA_enChannelStart(u32 *Copy_pu32SourceAddress,u32 *Copy_pu32DistnationAddress,
									u16 Copy_u16BlockSize)
{
ErrorState_t Local_errState=SUCCES;
//check for NULL
if((Copy_pu32DistnationAddress!=NULL)&&(Copy_pu32SourceAddress!=NULL)){
/*Disablechannel*/
CLR_BIT(DMA->DMA_CH[0].DMA_CCR,0);
//set source
DMA->DMA_CH[0].DMA_CPAR=(u32) Copy_pu32SourceAddress;//cast to save the adress as a value.
//set destination
DMA->DMA_CH[0].DMA_CMAR=(u32)Copy_pu32DistnationAddress;
//setblock size
DMA->DMA_CH[0].DMA_CNDTR=Copy_u16BlockSize;
//enable channel
SET_BIT(DMA->DMA_CH[0].DMA_CCR,0);
}
else{
	Local_errState=NULL_PTR_ERR;

}
return Local_errState;
}
