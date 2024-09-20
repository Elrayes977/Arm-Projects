/*
 * MNVIC_prg.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Elrayes
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MNVIC_priv.h"
#include "MNVIC_config.h"
#include "MNVIC_int.h"
ErrorState_t NVIC_enInit(void)
{
	/* Init priority field */
SCB_AIRCR=NVIC_PR_OPTIONS;

return SUCCES;
}

ErrorState_t  MNVIC_enSetPrOptions(NVIC_Prority_t Copy_IRQ_ID,u8 Copy_G_perioritiyID,u8 Copy_S_perioritiyID)
{
	ErrorState_t Local_enState=SUCCES;

#if NVIC_PR_OPTIONS == SCB_G_16_SUP_NONE
	u8 local_u8G_Mask  		 = 0x0f;
	u8 local_u8SUB_Mask 	 = 0x00;
	u8 local_8uSUB_Offsit    = 0   ;

#elif NVIC_PR_OPTIONS == SCB_G_8_SUP_4
	u8 local_u8G_Mask  		 = 0x08;
	u8 local_u8SUB_Mask 	 = 0x01;
    u8 local_8uSUB_Offsit    = 1   ;

#elif NVIC_PR_OPTIONS == SCB_G_4_SUP_4
	u8 local_u8G_Mask  		 = 0x03;
	u8 local_u8SUB_Mask 	 = 0x03;
    u8 local_8uSUB_Offsit    = 2   ;

#elif NVIC_PR_OPTIONS == SCB_G_2_SUP_8
    u8 local_u8G_Mask  		 = 0x01;
    u8 local_u8SUB_Mask 	 = 0x03;
    u8 local_8uSUB_Offsit    = 3   ;
#elif NVIC_PR_OPTIONS == SCB_G_NONE_SUP_16
	u8 local_u8G_Mask        = 0x00;
	u8 local_u8SUB_Mask      = 0x0f;
	u8 local_8uSUB_Offsit    = 4;
#else
#error("Wron periorty Type")
#endif

	u8 local_u8Periority;
		if (Copy_IRQ_ID < INTERRUPT_TOTAL) {
			local_u8Periority = (((Copy_G_perioritiyID & local_u8G_Mask)<< local_8uSUB_Offsit)| (Copy_S_perioritiyID & local_u8SUB_Mask)) & 0b00001111;
			local_u8Periority <<= 4 ;
			NVIC_REG->NVIC_IPR[Copy_IRQ_ID] = local_u8Periority;
		} else {
			Local_enState=OUT_OF_RANGE;
		}
		return Local_enState;


return SUCCES;
}


ErrorState_t MNVIC_u8EnableInterrupt(NVIC_Prority_t Copy_u8IRQNumber)
{
	ErrorState_t Local_enState=SUCCES;
	if(Copy_u8IRQNumber<31)
	{	//Atomic Acssess change only the bit
		NVIC_REG->NVIC_ISER[0]=(1<<Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber<63)
	{	//Atomic Acssess change only the bit
		Copy_u8IRQNumber=Copy_u8IRQNumber-32;
		NVIC_REG->NVIC_ISER[1]=(1<<Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber<81)
	{	//Atomic Acssess change only the bit
		Copy_u8IRQNumber=Copy_u8IRQNumber-64;
		NVIC_REG->NVIC_ISER[2]=(1<<Copy_u8IRQNumber);
	}
	else
	{
		Local_enState=OUT_OF_RANGE;

	}
	return Local_enState;
}
ErrorState_t MNVIC_u8DisableInterrupt(NVIC_Prority_t Copy_u8IRQNumber)
{

	ErrorState_t Local_enState=SUCCES;
	if(Copy_u8IRQNumber<31)
	{	//Atomic Acssess change only the bit
		NVIC_REG->NVIC_ICER[0]=(1<<Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber<63)
	{	//Atomic Acssess change only the bit
		Copy_u8IRQNumber=Copy_u8IRQNumber-32;
		NVIC_REG->NVIC_ICER[1]=(1<<Copy_u8IRQNumber);
	}
	else if(Copy_u8IRQNumber<81)
	{	//Atomic Acssess change only the bit
		Copy_u8IRQNumber=Copy_u8IRQNumber-64;
		NVIC_REG->NVIC_ICER[2]=(1<<Copy_u8IRQNumber);
	}
	else
	{
		Local_enState=OUT_OF_RANGE;

	}
	return Local_enState;

}
ErrorState_t MNVIC_u8SetPendingFlag(NVIC_Prority_t Copy_u8IRQNumber)
{
	ErrorState_t Local_enState=SUCCES;
		u8 Copy_ID_Index = Copy_u8IRQNumber / NVIC_REG_SIZE;
		if (Copy_u8IRQNumber < INTERRUPT_TOTAL) {
			Copy_u8IRQNumber = Copy_u8IRQNumber % NVIC_REG_SIZE;
			NVIC_REG->NVIC_ISPR[Copy_ID_Index] = (1 << Copy_u8IRQNumber);
		} else {
			Local_enState=OUT_OF_RANGE;
		}
		return Local_enState;

}
ErrorState_t MNVIC_u8ClearPendingFlag(NVIC_Prority_t Copy_u8IRQNumber)
{

	ErrorState_t Local_enState=SUCCES;
			u8 Copy_ID_Index = Copy_u8IRQNumber / NVIC_REG_SIZE;
			if (Copy_u8IRQNumber < INTERRUPT_TOTAL) {
				Copy_u8IRQNumber = Copy_u8IRQNumber % NVIC_REG_SIZE;
				NVIC_REG->NVIC_ICPR[Copy_ID_Index] = (1 << Copy_u8IRQNumber);
			} else {
				Local_enState=OUT_OF_RANGE;
			}
			return Local_enState;
}
ErrorState_t MNVIC_u8GetActiveFlag(NVIC_Prority_t Copy_u8IRQNumber,u8 *ptrResult)
{

	ErrorState_t Copy_status =SUCCES;
		u8 Copy_ID_Index = Copy_u8IRQNumber / NVIC_REG_SIZE;
		if (Copy_u8IRQNumber < INTERRUPT_TOTAL) {
			Copy_u8IRQNumber = Copy_u8IRQNumber % NVIC_REG_SIZE;
			*ptrResult = GET_BIT(NVIC_REG->NVIC_IABR[Copy_ID_Index],Copy_u8IRQNumber);
		} else {
			Copy_status = FAILIUR;
		}
		return Copy_status;



}
