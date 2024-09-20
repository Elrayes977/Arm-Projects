/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */

#ifndef _RCC_pRG_H
#define _RCC_PRG_H

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STM32F103C8.h"

#include "MRCC_priv.h"
#include "MRCC_config.h"
#include "MRCC_int.h"

ErrorState_t RCC_voidEnablePeriphralCLK(u8 Copy_u8BusID,u8 Copy_u8PeriphralId)
{
	ErrorState_t Local_enErrorState=SUCCES;
	if(Copy_u8PeriphralId <= 31) //unsigned
	{
		switch(Copy_u8BusID)
		{
			case RCC_u8AHB: SET_BIT(RCC->RCC_AHBENR,Copy_u8PeriphralId) ;    	
			break;

			case RCC_u8APB1: SET_BIT(RCC->RCC_APB1ENR,Copy_u8PeriphralId) ;	
			break;
			
			case RCC_u8APB2:	SET_BIT(RCC->RCC_APB2ENR,Copy_u8PeriphralId) ;	
			break;
			
			default:
			Local_enErrorState=OUT_OF_RANGE;
			break;

		}

	}
	else
	{
		Local_enErrorState=OUT_OF_RANGE;

	}

	return Local_enErrorState;


}
ErrorState_t RCC_voidDisablePeriphralCLK(u8 Copy_u8BusID,u8 Copy_u8PeriphralId)
{
ErrorState_t Local_enErrorState=SUCCES;
if(Copy_u8PeriphralId <= 31) //unsigned
	{
		switch(Copy_u8BusID)
		{
			case RCC_u8AHB: CLR_BIT(RCC->RCC_AHBENR,Copy_u8PeriphralId) ;    	
			break;

			case RCC_u8APB1:CLR_BIT(RCC->RCC_APB1ENR,Copy_u8PeriphralId) ;	
			break;
			
			case RCC_u8APB2:CLR_BIT(RCC->RCC_APB2ENR,Copy_u8PeriphralId) ;	
			break;
			
			default:
			Local_enErrorState=OUT_OF_RANGE;
			break;

		}

	}
	else
	{
		Local_enErrorState=OUT_OF_RANGE;

	}

	return Local_enErrorState;
}




#endif /* _RCC_PRG_H */