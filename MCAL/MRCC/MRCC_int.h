/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:11/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */


#ifndef _RCC_INT_H
#define _RCC_INT_H


#define RCC_u8AHB  1
#define RCC_u8APB1 2
#define RCC_u8APB2 3

ErrorState_t RCC_voidEnablePeriphralCLK(u8 Copy_u8BusID,u8 Copy_u8PeriphralId);
ErrorState_t RCC_voidDisablePeriphralCLK(u8 Copy_u8BusID,u8 Copy_u8PeriphralId);

#endif /* _RCC_INT_H */