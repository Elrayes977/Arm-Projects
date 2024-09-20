/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:16/7/2023
	Version: 1.0.0
	SWC:RCC

	*****************************
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "MRCC_int.h"
#include "MGPIO_int.h"

void delay(u16 num);

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	MGPIO_enSetPinDirection(GPIO_PORTC, GPIO_u8PIN13, GPIO_u8OUT_PUSH_PULL_2MHZ);


  while(1){
	  MGPIO_enSetPinValue(GPIO_PORTC, GPIO_u8PIN13,GPIO_u8HIGH);
	  delay(600);
	  MGPIO_enSetPinValue(GPIO_PORTC, GPIO_u8PIN13,GPIO_u8LOW);
	  delay(600);
  }
}

void delay(u16 num)
{
for(u16 i=0;i<num;i++)
{
	for(u16 j=0;j<num;j++)
	{
		asm("NOP");
	}



}



}
