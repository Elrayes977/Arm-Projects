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

static void (*EXTI_CallBack[EXTI_NUMBER_OF_LINES])(void)= {NULL};

ErrorState_t MEXTI_enInit(EXTI_LINE_t copy_u8LineSelect)
{
	ErrorState_t Local_enStatuse=SUCCES;
	if(copy_u8LineSelect<EXTI_NUMBER_OF_LINES)
	{
		SET_BIT(EXTI_REG->EXTI_IMR,copy_u8LineSelect);
	}
	else
	{
		Local_enStatuse=OUT_OF_RANGE;

	}
	return Local_enStatuse;
}
ErrorState_t MEXTI_enIntDisable(EXTI_LINE_t copy_u8LineSelect)
{
	ErrorState_t Local_enStatuse=SUCCES;
	if(copy_u8LineSelect<EXTI_NUMBER_OF_LINES)
	{
		CLR_BIT(EXTI_REG->EXTI_IMR,copy_u8LineSelect);
	}
	else
	{
		Local_enStatuse=OUT_OF_RANGE;

	}
	return Local_enStatuse;
}

ErrorState_t MEXTI_enSWI_Enable(EXTI_LINE_t copy_u8LineSelect)
{
	ErrorState_t Local_enStatuse=SUCCES;
		if(copy_u8LineSelect<EXTI_NUMBER_OF_LINES){
	SET_BIT(EXTI_REG->EXTI_SWIER ,   copy_u8LineSelect);
		}
			else
			{
				Local_enStatuse=OUT_OF_RANGE;

			}
			return Local_enStatuse;

}
ErrorState_t MEXTI_enSWI_Disable(EXTI_LINE_t copy_u8LineSelect)
{


	ErrorState_t Local_enStatuse=SUCCES;
			if(copy_u8LineSelect<EXTI_NUMBER_OF_LINES){
				CLR_BIT(EXTI_REG->EXTI_SWIER ,  copy_u8LineSelect);
			}
				else
				{
					Local_enStatuse=OUT_OF_RANGE;

				}
				return Local_enStatuse;

}
ErrorState_t MEXTI_enSetSignalLatch(EXTI_LINE_t copy_u8LineSelect,TRIG_SET_t Copy_EdgeSelect)
{
	ErrorState_t Local_enStatuse=SUCCES;
	if ( copy_u8LineSelect < EXTI_NUMBER_OF_LINES) {
			switch (Copy_EdgeSelect) {
			case FALING_EDGE:
				SET_BIT(EXTI_REG->EXTI_FTSR, copy_u8LineSelect);
				break;
			case RISING_EDGE:
				SET_BIT(EXTI_REG->EXTI_RTSR, copy_u8LineSelect);
				break;
			case ANY_CHANGE:
				SET_BIT(EXTI_REG->EXTI_RTSR, copy_u8LineSelect);
				SET_BIT(EXTI_REG->EXTI_FTSR, copy_u8LineSelect);
				break;
			default:
				Local_enStatuse=OUT_OF_RANGE;
				break;
			}
		} else {
			Local_enStatuse=OUT_OF_RANGE;
		}
	return Local_enStatuse;

}

ErrorState_t MEXTI_enSetCallBackFunc(EXTI_LINE_t copy_u8LineSelect,void (*ptrfun)(void))
{
	ErrorState_t Local_enStatuse=SUCCES;
		if (*ptrfun != NULL) {
			if (copy_u8LineSelect <= EXTI_NUMBER_OF_LINES) {
				EXTI_CallBack[copy_u8LineSelect] = ptrfun;
			} else {
				Local_enStatuse=OUT_OF_RANGE;
			}
		} else {
			Local_enStatuse=NULL_PTR_ERR;
		}
		return Local_enStatuse;



}

void EXTI_ClearPendingBit(EXTI_LINE_t copy_u8LineSelec)
{
	SET_BIT( EXTI_REG->EXTI_PR , copy_u8LineSelec);
}




/******************************************************************/
/******************************************************************/
/******************************************************************/
/******************************************************************/
// IRQS
void EXTI0_IRQHandler(void) /* EXTI Line0 interrupt */
{
	EXTI_CallBack[EXTI_0]();

	EXTI_ClearPendingBit(EXTI_0);
}
/* EXTI Line1 interrupt                             */
void EXTI1_IRQHandler(void) {
	EXTI_CallBack[EXTI_1]();
	EXTI_ClearPendingBit(EXTI_1);
}
/* EXTI Line2 interrupt                             */
void EXTI2_IRQHandler(void) {
	EXTI_CallBack[EXTI_2]();
	EXTI_ClearPendingBit(EXTI_2);

}
/* EXTI Line3 interrupt                             */
void EXTI3_IRQHandler(void) {
	EXTI_CallBack[EXTI_3]();
	EXTI_ClearPendingBit(EXTI_3);
}
/* EXTI Line4 interrupt                             */
void EXTI4_IRQHandler(void) {
	EXTI_CallBack[EXTI_4]();
	EXTI_ClearPendingBit(EXTI_4);
}
/* EXTI Line9_5 interrupt */
void EXTI9_5_IRQHandler(void) {

	if (EXTI_CallBack[EXTI_5] != NULL) {
		EXTI_CallBack[EXTI_5]();
		EXTI_ClearPendingBit(EXTI_5);
	}
	if (EXTI_CallBack[EXTI_6] != NULL) {
		EXTI_CallBack[EXTI_6]();
		EXTI_ClearPendingBit(EXTI_6);
	}
	if (EXTI_CallBack[EXTI_7] != NULL) {
		EXTI_CallBack[EXTI_7]();
		EXTI_ClearPendingBit(EXTI_7);
	}
	if (EXTI_CallBack[EXTI_8] != NULL) {
			EXTI_CallBack[EXTI_8]();
			EXTI_ClearPendingBit(EXTI_8);
		}
	if (EXTI_CallBack[EXTI_9] != NULL) {
			EXTI_CallBack[EXTI_9]();
			EXTI_ClearPendingBit(EXTI_9);
		}
}

/* EXTI Line15_10 interrupt */
void EXTI15_10_IRQHandler(void) {
	//EXTI10
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_10)==1) {
		if (EXTI_CallBack[EXTI_10] != NULL)
		{
		EXTI_CallBack[EXTI_10]();
		}
		EXTI_ClearPendingBit(EXTI_10);
	}
	//EXTI11
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_11)==1) {
			if (EXTI_CallBack[EXTI_11] != NULL)
			{
			EXTI_CallBack[EXTI_11]();
			}
			EXTI_ClearPendingBit(EXTI_11);
		}
	//EXTI12
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_12)==1) {
			if (EXTI_CallBack[EXTI_12] != NULL)
			{
			EXTI_CallBack[EXTI_12]();
			}
			EXTI_ClearPendingBit(EXTI_12);
		}
	//EXTI13
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_13)==1) {
			if (EXTI_CallBack[EXTI_13] != NULL)
			{
			EXTI_CallBack[EXTI_13]();
			}
			EXTI_ClearPendingBit(EXTI_13);
		}
	//EXTI14
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_14)==1) {
			if (EXTI_CallBack[EXTI_14] != NULL)
			{
			EXTI_CallBack[EXTI_14]();
			}
			EXTI_ClearPendingBit(EXTI_14);
		}
	//EXTI15
	if (GET_BIT(EXTI_REG->EXTI_PR,EXTI_15)==1) {
			if (EXTI_CallBack[EXTI_15] != NULL)
			{
			EXTI_CallBack[EXTI_15]();
			}
			EXTI_ClearPendingBit(EXTI_15);
		}
}
















