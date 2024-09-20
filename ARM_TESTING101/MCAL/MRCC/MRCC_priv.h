/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */

#ifndef _RCC_PRIV_H
#define _RCC_PRIV_H

#define RCC_u8HSE_CRYSTAL	1
#define RCC_u8HSE_RC		2
#define RCC_u8HSI			3
#define RCC_u8PLL			4


#define RCC_u8PLL_HSI_DIV_2		10
#define RCC_u8PLL_HSE_DIV_2		20
#define RCC_u8PLL_HSE			30

#define PLLinputclockx_2     0b0000
#define PLLinputclockx_3     0b0001
#define PLLinputclockx_4     0b0010
#define PLLinputclockx_5     0b0011
#define PLLinputclockx_6     0b0100
#define PLLinputclockx_7     0b0101
#define PLLinputclockx_8     0b0110 
#define PLLinputclockx_9     0b0111
#define PLLinputclockx_10    0b1000
#define PLLinputclockx_11    0b1001
#define PLLinputclockx_12    0b1010
#define PLLinputclockx_13    0b1011
#define PLLinputclockx_14    0b1100
#define PLLinputclockx_15    0b1101
#define PLLinputclockx_16    0b1110

#define RCC_u8PLL_SHIFT 17

#endif /* _RCC_PRIV_H */