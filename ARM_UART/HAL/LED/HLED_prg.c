/*
 * HLED_prg.c
 *
 *  Created on: May 29, 2023
 *      Author: Elrayes
 */

#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "MRCC_int.h"

#include "HLED_priv.h"
#include "HLED_config.h"
#include "HLED_int.h"


/****************/
ErrorState_t HLED_enInit(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	switch(copy_u8LedId)
	{
		case HLED_RED_ID:
		MGPIO_enSetPinDirection(HLED_RED_LED_PIN,  GPIO_u8OUT_PUSH_PULL_2MHZ);
		break;
		case HLED_BLUE_ID:
		MGPIO_enSetPinDirection(HLED_BLUE_LED_PIN,  GPIO_u8OUT_PUSH_PULL_2MHZ);
		break;
		case HLED_GRN_ID:
		MGPIO_enSetPinDirection(HLED_GRN_LED_PIN,  GPIO_u8OUT_PUSH_PULL_2MHZ);
		break;
default:
	Local_State=OUT_OF_RANGE;
	}
return Local_State;
}
/****************/
ErrorState_t HLED_enSetON(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	switch(copy_u8LedId)
	{
	case HLED_RED_ID:
#if(HLED_RED_LED_DIR==HLED_LED_FORWARD)
		 MGPIO_enSetPinValue(HLED_RED_LED_PIN,GPIO_u8HIGH);
#elif(HLED_RED_LED_DIR==HLED_LED_REVERSE)
		 MGPIO_enSetPinValue(HLED_RED_LED_PIN,GPIO_u8LOW);
#else
	#error  ("wrong led Red Direction")
#endif
		break;
	case HLED_BLUE_ID:
#if(HLED_BLUE_LED_DIR==HLED_LED_FORWARD)
		MGPIO_enSetPinValue(HLED_BLUE_LED_PIN,GPIO_u8HIGH);
#elif(HLED_BLUE_LED_DIR==HLED_LED_REVERSE)
		MGPIO_enSetPinValue(HLED_BLUE_LED_PIN,GPIO_u8LOW);//dimmed cause it's false
#else
	#error  ("wrong led Red Direction")
#endif
		break;


	case HLED_GRN_ID:
#if(HLED_GRN_LED_DIR==HLED_LED_FORWARD)
		MGPIO_enSetPinValue(HLED_GRN_LED_PIN,GPIO_u8HIGH);
#elif(HLED_GRN_LED_DIR==HLED_LED_REVERSE)
		MGPIO_enSetPinValue(HLED_GRN_LED_PIN,GPIO_u8LOW);//dimmed cause it's false
#else
	#error  ("wrong led Red Direction")
#endif

break;
default:
	Local_State=OUT_OF_RANGE;
	}
return Local_State;

}
/****************/
ErrorState_t HLED_enSetOFF(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
		switch(copy_u8LedId)
		{
		case HLED_RED_ID:
	#if(HLED_RED_LED_DIR==HLED_LED_FORWARD)
			MGPIO_enSetPinValue(HLED_RED_LED_PIN,GPIO_u8LOW);
	#elif(HLED_RED_LED_DIR==HLED_LED_REVERSE)
			MGPIO_enSetPinValue(HLED_RED_LED_PIN,GPIO_u8HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif
			break;
		case HLED_BLUE_ID:
	#if(HLED_BLUE_LED_DIR==HLED_LED_FORWARD)
			MGPIO_enSetPinValue(HLED_BLUE_LED_PIN,GPIO_u8LOW);
	#elif(HLED_BLUE_LED_DIR==HLED_LED_REVERSE)
			MGPIO_enSetPinValue(HLED_BLUE_LED_PIN,GPIO_u8HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif
			break;


		case HLED_GRN_ID:
	#if(HLED_GRN_LED_DIR==HLED_LED_FORWARD)
			MGPIO_enSetPinValue(HLED_GRN_LED_PIN,GPIO_u8LOW);
	#elif(HLED_GRN_LED_DIR==HLED_LED_REVERSE)
			MGPIO_enSetPinValue(HLED_GRN_LED_PIN,GPIO_u8HIGH);//dimmed cause it's false
	#else
		#error  ("wrong led Red Direction")
	#endif

	break;
	default:
		Local_State=OUT_OF_RANGE;
		}
	return Local_State;


}
ErrorState_t HLED_enToggle(u8 copy_u8LedId)
{
	ErrorState_t Local_State=SUCCES;
	switch(copy_u8LedId)
	{
	case HLED_RED_ID:
		MGPIO_enTogglePin(HLED_RED_LED_PIN);
		break;
	case HLED_BLUE_ID:
		MGPIO_enTogglePin(HLED_BLUE_LED_PIN);
		break;

	case HLED_GRN_ID:
		MGPIO_enTogglePin(HLED_GRN_LED_PIN);
		break;
default:
	Local_State=OUT_OF_RANGE;

	}
return Local_State;

}
