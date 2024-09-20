/*
 * MSPI_int.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Elrayes
 */

#ifndef MSPI_MSPI_INT_H_
#define MSPI_MSPI_INT_H_




typedef enum {
	SPI_F_2  = 0 ,
	SPI_F_4 ,
	SPI_F_8 ,
	SPI_F_16 ,
	SPI_F_32 ,
	SPI_F_64 ,
	SPI_F_128 ,
	SPI_F_256 ,

}SPI_Prescaler_t;


void SPI2_vInit(void) ;

ErrorState_t SPI2_u8SendRecive (u16 copy_u8SendData ,u8* Ptr_u8ReciveData );




#endif /* MSPI_MSPI_INT_H_ */
