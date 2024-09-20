/*
 * MSPI_prog.c
 *
 *  Created on: Aug 8, 2023
 *      Author: Elrayes
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"
/***********STK*************/
#include "MSPI_priv.h"
#include "MSPI_config.h"
#include "MSPI_int.h"

void SPI2_vInit(void)
{


#if SPI_MODE == SPI_u8MASTER
	// set master
SET_BIT(SPI2->SPI_CR1, MSTR);
	// set clock
//insted of masking the hole register we are clearing and setting the  BR bits to set the buad rate moode -> example 001
	WRITE_BIT(SPI2->SPI_CR1, BR0, GET_BIT(BAUDRATE,0));
	WRITE_BIT(SPI2->SPI_CR1, BR1, GET_BIT(BAUDRATE,1));
	WRITE_BIT(SPI2->SPI_CR1, BR2, GET_BIT(BAUDRATE,2));

#elif SPI_MODE == SPI_u8SLAVE
	// set slave
	CLR_BIT(SPI2->SPI_CR1, MSTR);
#endif

	// set CK pr
#if SPI_CK_PR == SPI_u8CK_PR_LOW
	CLR_BIT(SPI2->SPI_CR1, CPOL);
#elif SPI_CK_PR == SPI_u8CK_PR_HIGH
	SET_BIT(SPI2->SPI_CR1, CPOL);
#endif

	// set Ck phase
#if SPI_CK_PH == SPI_u8CK_PH_LOW
	CLR_BIT(SPI2->SPI_CR1, CPHA);
#elif SPI_CK_PH == SPI_u8CK_PH_HIGH
	SET_BIT(SPI2->SPI_CR1, CPHA);
#endif

	// set mode 8bits , 16 bits
#if SPI_BITMODE == SPI_u8_8_BITMODE
	CLR_BIT(SPI2->SPI_CR1, DFF);
#elif SPI_BITMODE == SPI_u8_16_BITMODE
	SET_BIT(SPI2->SPI_CR1, DFF);
#endif

	// set LSB , MSB
#if SPI_MODE_SEND == SPI_u8_MSB_MODE
	CLR_BIT(SPI2->SPI_CR1, LSBFIRST);
#elif SPI_MODE_SEND == SPI_u8_lSB_MODE
	SET_BIT(SPI2->SPI_CR1, LSBFIRST);
#endif
	// enable spi
	SET_BIT(SPI2->SPI_CR1, SPE);


}

ErrorState_t SPI2_u8SendRecive (u16 copy_u8SendData ,u8* Ptr_u8ReciveData )
{

	ErrorState_t local_u8Status = SUCCES ;

	SPI2->SPI_DR = copy_u8SendData ;
	while(READ_BIT(SPI2->SPI_SR,BSY))  ;
	*Ptr_u8ReciveData =SPI2->SPI_DR;

	return local_u8Status ;
}

