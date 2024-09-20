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
}

ErrorState_t  MNVIC_enSetPrOptions(NVIC_Prority_t Copy_IRQ_ID,u8 Copy_G_perioritiyID,u8 Copy_S_perioritiyID)
{

#if   NVIC_PR_OPTIONS== SCB_G_16_SUP_NONE



#elif	NVIC_PR_OPTIONS==SCB_G_8_SUP_4



#elif	NVIC_PR_OPTIONS==SCB_G_4_SUP_4



#elif	NVIC_PR_OPTIONS==SCB_G_2_SUP_8



#elif	NVIC_PR_OPTIONS==SCB_G_NONE_SUP_16



#else
#error("Wron periorty Type")
#endif

return SUCCES;
}


ErrorState_t MNVIC_u8EnableInterrupt(u8 Copy_u8IRQNumber)
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
ErrorState_t MNVIC_u8DisableInterrupt(u8 Copy_u8IRQNumber)
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
ErrorState_t MNVIC_u8SetPendingFlag(u8 Copy_u8IRQNumber)
{


}
ErrorState_t MNVIC_u8ClearPendingFlag(u8 Copy_u8IRQNumber)
{


}
ErrorState_t MNVIC_u8GetActiveFlag(u8 Copy_u8IRQNumber,u8 *ptrResult)
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
