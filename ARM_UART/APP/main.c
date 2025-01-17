

/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:3/8/2023
	Version: 1.0.0
	SWC:UART

	*****************************
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MRCC_int.h"
#include "MGPIO_int.h"
#include "MUART_int.h"

int main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_USART1EN);

	MGPIO_enSetPinDirection(PA10, GPIO_u8INPUT_FLOATING); //rx
	MGPIO_enSetPinDirection(PA9, GPIO_u8OUT_AF_PP_DRAIN_2MHZ);//tx

	MGPIO_enSetPinDirection(PA0, GPIO_u8OUT_PUSH_PULL_2MHZ);

	//MUSART_voidInit();
	u8 result;

	while(1)
	{
	//	MUSART_voidTransmit("H");
	//	result=MUSART_u8ReceiveBusyWait();
		if(result=='5')
		{
			MGPIO_enSetPinValue(PA0,GPIO_u8HIGH);
		}
		else if(result=='3')
		{
			MGPIO_enSetPinValue(PA0,GPIO_u8LOW);

		}


	}





return 0;
}
