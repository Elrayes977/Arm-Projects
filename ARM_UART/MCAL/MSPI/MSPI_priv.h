/*
 * MSPI_priv.h
 *
 *  Created on: Aug 8, 2023
 *      Author: Elrayes
 */

#ifndef MSPI_MSPI_PRIV_H_
#define MSPI_MSPI_PRIV_H_

#define SPI_u8MASTER   21
#define SPI_u8SLAVE    55

#define SPI_u8CK_PR_HIGH 21
#define SPI_u8CK_PR_LOW  55 //patern 1010101010 same as 0xAA.

#define SPI_u8CK_PH_LOW  55
#define SPI_u8CK_PH_HIGH 21

#define SPI_u8_8_BITMODE  55
#define SPI_u8_16_BITMODE 21

#define SPI_u8_lSB_MODE  55
#define SPI_u8_MSB_MODE  21
//SPI_CR1 reg bits
#define MSTR 		2
#define BR0  		3
#define BR1	 		4
#define BR2	  		5
#define CPOL 		1
#define CPHA 		0
#define DFF	    	11
#define LSBFIRST 	7
#define SPE      	6
//------------------------
#define BSY         7

#endif /* MSPI_MSPI_PRIV_H_ */
