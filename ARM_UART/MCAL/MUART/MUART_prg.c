

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
/***********USART*************/
#include "MUART_priv.h"
#include "MUART_config.h"
#include "MUART_int.h"

static volatile u8 UART1_u8GlobalFrame[UART_FRAME_SIZE] = { 0 };
static volatile u8 UART1_u8index = 0;
static volatile u8 UART1_u8EndFrameRecieved = 0;

static char UART1_StringRX[UART_STR_SIZE] = { 0 };
static u16 UART1_MUNRX = 0;

static u8 UART1_DataReady = 0;

void MUSART1_voidInit(void)
{




	/******** baud rate **********/
	USART1->USART_BRR = BAUDRATE;

	/******** frame format *******/
//no parity
	CLR_BIT(USART1->USART_CR1, PCE);
// 1 start 8bit data n stop
	CLR_BIT(USART1->USART_CR1, M );
// 1 stop bit
	CLR_BIT(USART1->USART_CR2, StOP_0);
	CLR_BIT(USART1->USART_CR2, StOP_1);

	/******** enable RX **********/
	SET_BIT(USART1->USART_CR1, RE);
	/******** enable TX **********/
	SET_BIT(USART1->USART_CR1, TE);
	/*********UART enable ********/
	SET_BIT(USART1->USART_CR1, UE);
	// clr status reg
	USART1->USART_SR = 0;


}

/*
void MUSART_voidTransmit(u8 Copy_u8arr[])
{
u8 counter=0;

while(Copy_u8arr[counter]!='\0')
{
	USART1->USART_DR=Copy_u8arr[counter];

	while(GET_BIT(USART1->USART_SR,6)==0);

	counter++;

}



}
u8 MUSART_u8ReceiveBusyWait(void)
{
	while(GET_BIT(USART1->USART_SR,5)==0);



return (0xFF&USART1->USART_DR); //first 8 bits only

}
*/

ErrorState_t MUSART1_enSendByteBusywait(u8 Copy_u8Byte) {

	ErrorState_t local_u8Status = SUCCES;
		while (!GET_BIT(USART1->USART_SR, TXE)); // txe ---- time out is needed
		USART1->USART_DR = Copy_u8Byte;
		return local_u8Status;

}
ErrorState_t MUSART1_enRecieveByteBusyw8(u8 * Copy_ptrByte)
{

	ErrorState_t local_u8Status = SUCCES;
		while (!GET_BIT(USART1->USART_SR, RXNE)); // RXne ---- time out is needed
		*Copy_ptrByte = USART1->USART_DR;
		return local_u8Status;
}

ErrorState_t MUSART1_enSendByteAsynch(u8 Copy_u8Byte)
{


}
ErrorState_t MUSART1_enRecieveByteAsynch(void)
{



}



ErrorState_t MUSART1_enSendStringBusyW8(char*  Copy_ptrString)
{
	ErrorState_t local_u8Status = SUCCES;

		for (u8 local_index = 0; Copy_ptrString[local_index]; local_index++) {
			MUSART1_enSendByteBusywait(Copy_ptrString[local_index]);
		}
		return local_u8Status;
}





ErrorState_t MUSART1_enRecieveStringBusyW8(u8 * Copy_ptrString)
{
	ErrorState_t local_u8Status = SUCCES;
	//

		return local_u8Status;


}

ErrorState_t UART1_u8RecieveByte(volatile u8 *Copy_ptrByte) {
	ErrorState_t local_u8Status = SUCCES;
// return DR reg
	*Copy_ptrByte = USART1->USART_DR;
	return local_u8Status;

}


ErrorState_t MUSART1_enInterruptEnRX(void)
{
	ErrorState_t local_u8Status = SUCCES;
		SET_BIT(USART1->USART_CR1, RXNEIE);
		return local_u8Status;

}
ErrorState_t MUSART1_enInterruptDsRX(void)
{

		ErrorState_t local_u8Status = SUCCES;
		CLR_BIT(USART1->USART_CR1, RXNEIE);
		return local_u8Status;


}
ErrorState_t MUSART1_enInterruptCallBackRX(void)
{
	ErrorState_t local_u8Status = SUCCES;


			return local_u8Status;

}

ErrorState_t MUSART1_enInterruptEnTX(void)
{
	ErrorState_t local_u8Status = SUCCES;


				return local_u8Status;

}
ErrorState_t MUSART1_enInterruptDsTX(void)
{

	ErrorState_t local_u8Status = SUCCES;


				return local_u8Status;



}
ErrorState_t MUSART1_enInterruptCallBackTX(void)
{


	ErrorState_t local_u8Status = SUCCES;


				return local_u8Status;
}

ErrorState_t MUSART1_enSendNumString(u32 copy_u32num)
{
	ErrorState_t local_u8Status = SUCCES;

	u8 local_String[10];
		s8 index;
		for (index = 0; copy_u32num; index++) {
			local_String[index] = copy_u32num % 10 + '0';
			copy_u32num /= 10;
		}
		index--;
		for (; index >= 0; index--) {
			MUSART1_enSendByteBusywait(local_String[index]);
		}


				return local_u8Status;


}
/*************************************************************/

ErrorState_t MUSART1_enSendNum(u32 copy_u32num)
{

		ErrorState_t local_u8Status = SUCCES;

		u8 *localptr = (u8*) (&copy_u32num);
		MUSART1_enSendByteBusywait(localptr[0]);
		MUSART1_enSendByteBusywait(localptr[1]);
		MUSART1_enSendByteBusywait(localptr[2]);
		MUSART1_enSendByteBusywait(localptr[3]);

		return local_u8Status;
}




ErrorState_t UART1_u8SendNumString(u32 copy_u32num) {
	ErrorState_t local_u8Status = SUCCES;
	u8 local_String[10];
	s8 index;
	for (index = 0; copy_u32num; index++) {
		local_String[index] = copy_u32num % 10 + '0';
		copy_u32num /= 10;
	}
	index--;
	for (; index >= 0; index--) {
		MUSART1_enSendByteBusywait(local_String[index]);
	}

	return local_u8Status;

}

void separate_string() {
	u8 i, j = 0;
	for (i = 0;
			UART1_u8GlobalFrame[i] != '#' && UART1_u8GlobalFrame[i] != ' '
					&& i < UART_FRAME_SIZE; i++) {
		if (UART1_u8GlobalFrame[i] >= 'a' && UART1_u8GlobalFrame[i] <= 'z') {
			UART1_StringRX[j] = UART1_u8GlobalFrame[i];
			j++;
		}
	}
	UART1_StringRX[j] = 0;
	UART1_MUNRX = 0;
	for (; UART1_u8GlobalFrame[i] != '#' && i < UART_FRAME_SIZE; i++) {
		if (UART1_u8GlobalFrame[i] >= '0' && UART1_u8GlobalFrame[i] <= '9') {
			UART1_MUNRX = (UART1_MUNRX * 10) + (UART1_u8GlobalFrame[i] - '0');
		}
	}

}
void MUSART1_Runnable(void)
{
	if (UART1_u8EndFrameRecieved) {

			separate_string();
			UART1_DataReady = 1;
			UART1_u8EndFrameRecieved = 0;
			UART1_u8index = 0;
		} else {
			//do nothing
		}

}

u8 MUSART1_IsDataReady(void)
{
	return UART1_DataReady;
}
void MUSART1_GETdata(u8 *UART1ptrStr, u16 *UART1ptrNum)
{
	u8 index = 0;
		*UART1ptrNum = UART1_MUNRX;
		for (; UART1_StringRX[index]; index++) {
			UART1ptrStr[index] = UART1_StringRX[index];
			UART1_StringRX[index] = 0;
		}
		UART1ptrStr[index] = 0;
		UART1_MUNRX = 0;
		UART1_DataReady = 0;



}


void USART1_IRQHandler(void) {

	if (GET_BIT(USART1->USART_SR, RXNE)) {
		UART1_u8RecieveByte(&UART1_u8GlobalFrame[UART1_u8index]); //-
		if (UART1_u8GlobalFrame[UART1_u8index] == UART1_ENDFRAM
				|| UART1_u8index == UART_FRAME_SIZE - 1) {
			UART1_u8EndFrameRecieved = 1;
		}
		if (UART1_u8index < UART_FRAME_SIZE - 1) {
			UART1_u8index++;
		} else {
			// do nothing
		}
	}
}

