/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:13/7/2023
	Version: 1.0.0
	SWC:GPIO
	
	*****************************
 */
#ifndef _MGPIP_INT_H_
#define _MGPIP_INT_H_

#define GPIO_PORTA 1
#define GPIO_PORTB 2
#define GPIO_PORTC 3

#define GPIO_u8PIN0 0
#define GPIO_u8PIN1 1
#define GPIO_u8PIN2 2
#define GPIO_u8PIN3 3
#define GPIO_u8PIN4 4
#define GPIO_u8PIN5 5
#define GPIO_u8PIN6 6
#define GPIO_u8PIN7 7
#define GPIO_u8PIN8 8
#define GPIO_u8PIN9 9
#define GPIO_u8PIN10 10
#define GPIO_u8PIN11 11
#define GPIO_u8PIN12 12
#define GPIO_u8PIN13 13
#define GPIO_u8PIN14 14
#define GPIO_u8PIN15 15

/* INPUT */
#define GPIO_u8INPUT_ANALOG  		 0b0000
#define GPIO_u8INPUT_FLOATING		 0b0001
#define GPIO_u8INPUT_PULL_UP_DOWN 	 0b1000
/* OUTPUT */
#define GPIO_u8OUT_PUSH_PULL_2MHZ    0b0010
#define GPIO_u8OUT_PUSH_PULL_10MHZ   0b0001
#define GPIO_u8OUT_PUSH_PULL_50MHZ   0b0011


#define GPIO_u8OUT_PUSH_PULL_OPEN_DRAIN_2MHZ    0b0110
#define GPIO_u8OUT_PUSH_PULL_OPEN_DRAIN_10MHZ   0b0101
#define GPIO_u8OUT_PUSH_PULL_OPEN_DRAIN_50MHZ   0b0111


#define GPIO_u8OUT_AF_PP_DRAIN_2MHZ     0b1010
#define GPIO_u8OUT_AF_PP_10MHZ   		0b1001
#define GPIO_u8OUT_AF_PP_50MHZ   		0b1011



#define GPIO_u8HIGH 1
#define GPIO_u8LOW 0

#define GPIO_SET 0
#define GPIO_RESET 1

#define LOW 0
#define HIGH 1

ErrorState_t MGPIO_enSetRestPIN(u8 Copy_u8PinId,u8 Copy_u8Mode);

ErrorState_t MGPIO_enSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Mode);
ErrorState_t MGPIO_enSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value);
ErrorState_t MGPIO_enGetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 * ptr_u8ReturnValue);

ErrorState_t MGPIO_u8SetPortDirection_H(u8 Copy_u8PortId ,u8 Copy_u8Mode) ;
ErrorState_t MGPIO_u8SetPortDirection_L(u8 Copy_u8PortId ,u8 Copy_u8Mode) ;
ErrorState_t MGPIO_u8SetPortValue_H(u8 Copy_u8PortId ,u8 Copy_u8Value) ;
ErrorState_t MGPIO_u8SetPortValue_L(u8 Copy_u8PortId ,u8 Copy_u8Value) ;
#endif  // _MGPIP_INT_H_
