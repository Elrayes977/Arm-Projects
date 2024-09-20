/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:24/7/2023
	Version: 1.0.0
	SWC:EXTI

	*****************************
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MEXTI_priv.h"
#include "MEXTI_config.h"
#include "MEXTI_int.h"



ErrorState_t MEXTI_enInit(EXTI_LINE_t copy_u8LineSelect)
{
	ErrorState_t Local_enStatuse=SUCCES;
	if(copy_u8LineSelect<20)
	{
		SET_BIT(EXTI_REG->EXTI_IMR,copy_u8LineSelect);
	}
	else
	{
		Local_enStatuse=OUT_OF_RANGE;

	}
	return Local_enStatuse;
}
ErrorState_t MEXTI_enEnable(u8 Copy_EdgeSelect)
{


}
ErrorState_t MEXTI_enDisable(u8 Copy_EdgeSelect)
{



}
ErrorState_t MEXTI_enSWI_Enable()
{


}
ErrorState_t MEXTI_enSWI_Disable()
{




}
ErrorState_t MEXTI_enSetSignalLatch()
{




}
