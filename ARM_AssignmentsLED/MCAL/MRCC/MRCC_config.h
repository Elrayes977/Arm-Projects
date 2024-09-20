/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */

#ifndef _RCC_CONFIG_H
#define _RCC_CONFIG_H

/* 
*****************************
choose clock type:
1-RCC_u8HSE_CRYSTAL
2-RCC_u8HSE_RC
3-RCC_u8HSI
4-RCC_u8PLL
*****************************
 */

#define RCC_u8CLK_TYPE 	RCC_u8HSE_CRYSTAL


#if RCC_u8CLK_TYPE==RCC_u8PLL
/* 
*****************************
choose clock type:
1-RCC_u8PLL_HSI_DIV_2
2-RCC_u8PLL_HSE_DIV_2
3-RCC_u8PLL_HSE

*****************************
 */
 /*
 *********************** PLL options **********************************
1- PLLinputclockx_2    
2- PLLinputclockx_3      
3- PLLinputclockx_4      
4- PLLinputclockx_5      
5- PLLinputclockx_6      
6- PLLinputclockx_7      
7- PLLinputclockx_8     
6- PLLinputclockx_9      
7- PLLinputclockx_10     
8- PLLinputclockx_11     
9- PLLinputclockx_12     
10- PLLinputclockx_13    
11- PLLinputclockx_14    
12- PLLinputclockx_15    
13- PLLinputclockx_16    
*********************************************************
*/
#define PLL_u8CLOCK PLLinputclockx_2 
 
#define RCC_u8PLL_INPUT  RCC_u8PLL_HSI_DIV_2
#endif

#endif /* _RCC_CONFIG_H */