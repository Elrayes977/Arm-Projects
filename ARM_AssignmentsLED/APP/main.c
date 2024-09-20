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
#include "MSTK_int.h"
#include "HLED_int.h"
#include "HSWITCH_int.h"
#include "HLEDMRX_int.h"
void delay(u16 num);

void main(void)
{
	RCC_voidInitSystemClock();
	RCC_voidEnablePeriphralCLK(APB2_IOPAEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPBEN);
	RCC_voidEnablePeriphralCLK(APB2_IOPCEN);
	MSTK_enInit();

	HLEDMRX_voidInit();

	//u8 value=1;

  while(1){

	 u8 i=0;
	 u8 j=0;
	while(j<4){
		u8 value=1;
		while(i<7)
			{
			MGPIO_u8SetPortValue_L(GPIO_PORTA, value);
			MSTK_enSetBusyWait(200);
			value<<=1;
			//MSTK_enSetBusyWait(200);
			i++;
			}
	value=0b10000000;
		while(i>0)
		{
			MGPIO_u8SetPortValue_L(GPIO_PORTA, value);
			MSTK_enSetBusyWait(200);
			value>>=1;
			//MSTK_enSetBusyWait(200);
			i--;
		}
		MSTK_enSetBusyWait(200);
		j++;}

	i=0;
	j=0;
	while(j<4){
		u8 valu1=0b00010000;
		u8 valu2=0b00001000;
	while(i<7)
	{
	MGPIO_u8SetPortValue_L(GPIO_PORTA, valu1+valu2);
	valu1|=valu1<<1;
	valu2|=valu2>>1;
	MSTK_enSetBusyWait(200);
	i++;
	}
	while(i>0)
	{
	MGPIO_u8SetPortValue_L(GPIO_PORTA, valu1+valu2);
	valu1&=valu1>>1;
	valu2&=valu2<<1;
	MSTK_enSetBusyWait(200);
	i--;

	}
	MSTK_enSetBusyWait(200);
	j++;}
	i=0;
	while(i<8)
	{
		MGPIO_u8SetPortValue_L(GPIO_PORTA, 0xFF);
		MSTK_enSetBusyWait(500);
		MGPIO_u8SetPortValue_L(GPIO_PORTA, 0x00);
		MSTK_enSetBusyWait(500);
	i++;
	}
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
