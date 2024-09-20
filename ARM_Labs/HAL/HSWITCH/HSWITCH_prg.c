/*
 * HSWITCH_prg.c
 *
 *  Created on: Jul 19, 2023
 *      Author: Elrayes
 */

#include "STD_TYPES.h"
#include "ERROR_STATES.h"
#include "BIT_MATH.h"
#include "MGPIO_int.h"
#include "MRCC_int.h"

#include "HSWITCH_priv.h"
#include "HSWITCH_config.h"
#include "HSWITCH_int.h"

ErrorState_t Hswitch_enInit(void)
{
RCC_voidInitSystemClock();
RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
MGPIO_enSetPinDirection(HSWITCH_PIN,GPIO_u8INPUT_PULL_UP_DOWN);
#if (HSWITCH_DIR==ACTIVE_LOW)
MGPIO_enSetPinValue(HSWITCH_PIN,GPIO_u8HIGH);
#else
MGPIO_enSetPinValue(HSWITCH_PIN,GPIO_u8LOW);
#endif
return SUCCES;
}
ErrorState_t Hswitch_enGetValue(u8 * ptr_getValue)
{
	u8 Local_getValue=SWITCH_OFF;
	MGPIO_enGetPinValue(HSWITCH_PIN,&Local_getValue);
	if(Local_getValue==SWITCH_ON){
	*ptr_getValue=SWITCH_ON;
	}
	else{
		*ptr_getValue=SWITCH_OFF;
	}
	return SUCCES;
}
