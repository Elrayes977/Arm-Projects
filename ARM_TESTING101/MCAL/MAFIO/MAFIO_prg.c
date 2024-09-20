/*
 * MAFIO_prg.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Elrayes
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MAFIO_priv.h"
#include "MAFIO_config.h"
#include "MAFIO_int.h"






ErrorState_t AFIO_u8SetEXTIConfiguration(AFIO_EXTI_LINE_t Copy_u8EXTILineId, u8 Copy_u8EXTIPortMap)
{




	u8 Local_u8RegIndex   = 0 ;
		ErrorState_t Local_u8ErrorState = SUCCES;
if(Copy_u8EXTILineId<AFIO_EXTI_NUMBER_OF_LINES){
		if(Copy_u8EXTILineId <= 3)
		{
			Local_u8RegIndex = 0;
		}
		else if(Copy_u8EXTILineId <= 7)
		{
			Local_u8RegIndex = 1;
			Copy_u8EXTILineId = Copy_u8EXTILineId - 4;
		}
		else if(Copy_u8EXTILineId <= 11)
		{
			Local_u8RegIndex = 2;
			Copy_u8EXTILineId = Copy_u8EXTILineId - 8;
		}
		else if(Copy_u8EXTILineId <= 15)
		{
			Local_u8RegIndex = 3;
			Copy_u8EXTILineId = Copy_u8EXTILineId - 12;

		}
		else
		{
			Local_u8ErrorState = OUT_OF_RANGE;
		}
}
else{
	Local_u8ErrorState = OUT_OF_RANGE;
}

		AFIO_REG->AFIO_EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8EXTILineId * 4));
		AFIO_REG->AFIO_EXTICR[Local_u8RegIndex] |=  ((Copy_u8EXTIPortMap) << (Copy_u8EXTILineId * 4));

		return Local_u8ErrorState;


}
