/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */




#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MRCC_priv.h"
#include "MRCC_config.h"
#include "MRCC_int.h"

void RCC_voidInitSystemClock(void)
{
#if RCC_u8CLK_TYPE==RCC_u8HSE_CRYSTAL
	RCC->RCC_CR=0x00010080;
#elif RCC_u8CLK_TYPE==RCC_u8HSE_RC
	RCC->RCC_CR=0x00050080;
#elif RCC_u8CLK_TYPE==RCC_u8HSI
	RCC->RCC_CR=0x00000081;
	RCC->RCC_CFGR = 0x00000000;
#elif RCC_u8CLK_TYPE==RCC_u8PLL
   // enable pll from Cr register 
    RCC->RCC_CR=0x01000080;
		#if RCC_u8PLL_INPUT == RCC_u8PLL_HSI_DIV_2
		    RCC->RCC_CR|=0x00000081;
			RCC->RCC_CFGR = (PLL_u8CLOCK<<RCC_u8PLL_SHIFT)|0x00000000;
			#elif RCC_u8PLL_INPUT == RCC_u8PLL_HSE_DIV_2
			 RCC->RCC_CR|=0x00050080;
			RCC->RCC_CFGR = (PLL_u8CLOCK<<RCC_u8PLL_SHIFT)|0x00020000;
			#elif RCC_u8PLL_INPUT == RCC_u8PLL_HSE
			 RCC->RCC_CR|=0x00010080;
			RCC->RCC_CFGR = (PLL_u8CLOCK<<RCC_u8PLL_SHIFT)|0x00000000;
		#endif
	//RCC->RCC_CR = 0x00010080;
#else
	#error("You choosed wrong Clock Type")
#endif

}

ErrorState_t RCC_voidEnablePeriphralCLK(PeriphralBusId_t Copy_enPeriphralId)
{	
	u8 Local_u8BusID =Copy_enPeriphralId/100;
	u8 Local_u8PeriphralID =Copy_enPeriphralId % 100;

	ErrorState_t Local_enErrorState=SUCCES;

	if(Local_u8PeriphralID  <= 31) //unsigned
	{
		switch(Local_u8BusID)
		{
			case RCC_u8AHB: SET_BIT(RCC->RCC_AHBENR,Local_u8PeriphralID) ;    	
			break;

			case RCC_u8APB2:SET_BIT(RCC->RCC_APB2ENR,Local_u8PeriphralID) ;	
			break;

			case RCC_u8APB1: SET_BIT(RCC->RCC_APB1ENR,Local_u8PeriphralID) ;	
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

ErrorState_t RCC_voidDisablePeriphralCLK(PeriphralBusId_t Copy_enPeriphralId)
{

	u8 Local_u8BusID =Copy_enPeriphralId/100;
	u8 Local_u8PeriphralID =Copy_enPeriphralId % 100;
ErrorState_t Local_enErrorState=SUCCES;
if(Local_u8PeriphralID <= 31) //unsigned
	{
		switch(Local_u8BusID)
		{
			case RCC_u8AHB: CLR_BIT(RCC->RCC_AHBENR,Local_u8PeriphralID) ;    	
			break;

			case RCC_u8APB1:CLR_BIT(RCC->RCC_APB1ENR,Local_u8PeriphralID) ;	
			break;
			
			case RCC_u8APB2:CLR_BIT(RCC->RCC_APB2ENR,Local_u8PeriphralID) ;	
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




