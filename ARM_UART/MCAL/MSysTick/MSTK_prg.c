/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:25/7/2023
	Version: 1.0.0
	SWC:STK

	*****************************
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"
/***********STK*************/
#include "MSTK_priv.h"
#include "MSTK_config.h"
#include "MSTK_int.h"

static void (*CallBackFun)(void)=NULL;

static u8 SG_u8Interval_Mode;

ErrorState_t MSTK_enInit(void)
{
	ErrorState_t Local_Status=SUCCES;
#if CLOCK_MODE==AHB_OVER_8_MODE

	//SET_BIT(STK_REG->STK_CTRL,ENABLE_BIT);
	CLR_BIT(STK_REG->STK_CTRL,CLKSOURCE_BIT);

#elif	CLOCK_MODE==AHB_MODE
	//SET_BIT(STK_REG->STK_CTRL,ENABLE_BIT);
	SET_BIT(STK_REG->STK_CTRL,CLKSOURCE_BIT);

#else
 #error("Wrong AHB MODE")
#endif
return Local_Status;
}
ErrorState_t MSTK_enSetBusyWait(u32 copy_u8Ticks)
{
	ErrorState_t Local_Status=SUCCES;

	u32 Local_Ticksin_ms=copy_u8Ticks*1000;
	//enable Timer
	if(Local_Ticksin_ms<=MAX_LOAD_VALUE){
	SET_BIT(STK_REG->STK_CTRL,ENABLE_BIT);//Enable bit
	STK_REG->STK_LOAD=Local_Ticksin_ms;//set value to delay
	while(!GET_BIT(STK_REG->STK_CTRL,COUNTFLAG));
	//disable Timer
	CLR_BIT(STK_REG->STK_CTRL,ENABLE_BIT);
	STK_REG->STK_LOAD=0;
	STK_REG->STK_VAL=0;
	}
	else
	{
		 Local_Status=FAILIUR;
	}


return Local_Status;
	}
ErrorState_t MSTK_enSetInterValSingle(u8 copy_u8Time, void (*ptrfn)(void))
{
	ErrorState_t Local_Status=SUCCES;
	u8 SG_u8Interval_Mode=STK_MODE_SINGLE;

	/**/
	CallBackFun=ptrfn;
if(CallBackFun!=NULL)
	{
	u32 Local_Ticksin_ms=copy_u8Time*1000;
	if(Local_Ticksin_ms<=MAX_LOAD_VALUE){
	STK_REG->STK_LOAD=Local_Ticksin_ms;//set value to delay
	SET_BIT(STK_REG->STK_CTRL,TICKINT_BIT);
	SET_BIT(STK_REG->STK_CTRL,ENABLE_BIT);//Enable bit
	}//if max load
	else{
		Local_Status=OUT_OF_RANGE;

	}//else max load

	}
else{

	Local_Status=NULL_PTR_ERR;

}//null check

return Local_Status;
}
ErrorState_t MSTK_enSetInterValPeriodic(u8 copy_u8Time, void (*ptrfn)(void))
{
	ErrorState_t Local_Status=SUCCES;
	u8 SG_u8Interval_Mode=STK_MODE_PERIODIC;

		/**/
		CallBackFun=ptrfn;
	if(CallBackFun!=NULL)
		{
		u32 Local_Ticksin_ms=copy_u8Time*1000;
		if(Local_Ticksin_ms<=MAX_LOAD_VALUE){
		STK_REG->STK_LOAD=Local_Ticksin_ms;//set value to delay
		SET_BIT(STK_REG->STK_CTRL,TICKINT_BIT);
		SET_BIT(STK_REG->STK_CTRL,ENABLE_BIT);//Enable bit
		}//if max load
		else{
			Local_Status=OUT_OF_RANGE;

		}//else max load

		}
	else{

		Local_Status=NULL_PTR_ERR;

	}//null check

	return Local_Status;

}
ErrorState_t MSTK_enStopTimer(void)
{
	ErrorState_t Local_Status=SUCCES;

CLR_BIT(STK_REG->STK_CTRL,ENABLE_BIT);
CLR_BIT(STK_REG->STK_CTRL,TICKINT_BIT);
STK_REG->STK_LOAD=0;
STK_REG->STK_VAL=0;


return Local_Status;
}
ErrorState_t MSTK_enGetElapsedTime(u32 * ptrReturn)
{
	ErrorState_t Local_Status=SUCCES;
	if(ptrReturn!=NULL){
	u32 Local_u32ElapsedTime=(STK_REG->STK_LOAD)-(STK_REG->STK_VAL);
	*ptrReturn=Local_u32ElapsedTime/1000;//in milliseconds
	}
	else{
		Local_Status=NULL_PTR_ERR;
	}
	return Local_Status;

}
ErrorState_t MSTK_enGetRemainingTime(u32 * ptrReturn)
{
ErrorState_t Local_Status=SUCCES;

if(ptrReturn!=NULL){
	u32 Local_u32RemainigTime=(STK_REG->STK_LOAD);
	*ptrReturn=Local_u32RemainigTime/1000;//in milliseconds
	}
	else{
		Local_Status=NULL_PTR_ERR;
	}
return Local_Status;
}

void SysTick_Handler(void)
{

	CallBackFun();

	if(SG_u8Interval_Mode==STK_MODE_SINGLE)
	{
		CLR_BIT(STK_REG->STK_CTRL,ENABLE_BIT);
		CLR_BIT(STK_REG->STK_CTRL,TICKINT_BIT);
		STK_REG->STK_LOAD=0;
		STK_REG->STK_VAL=0;
	}
	else
	{


	}


}

