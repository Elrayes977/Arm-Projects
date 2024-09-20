/*
 * 
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:13/7/2023
	Version: 1.0.0
	SWC:RCC
	
	*****************************
 */
#include "STD_TYPES.h"                 
#include "BIT_MATH.h"
#include "ERROR_STATES.h"
#include "STM32F103C8.h"

#include "MGPIO_priv.h"
#include "MGPIO_config.h"
#include "MGPIO_int.h"


  
 ErrorState_t MGPIO_u8SetPortDirection_H(u8 Copy_u8PortId ,u8 Copy_u8Mode) {
	 ErrorState_t State = SUCCES ; 
	 u32 Copy_Tmode= Copy_u8Mode|Copy_u8Mode<<4|Copy_u8Mode<<8|
					Copy_u8Mode<<12|Copy_u8Mode<<16|Copy_u8Mode<<20
					|Copy_u8Mode<<24 |Copy_u8Mode<<28; 
	switch (Copy_u8PortId)
	{
		case GPIO_PORTA :
		GPIO_A->GPIO_CRH = Copy_Tmode ;
		/*
		 for (u8 i = 0 ; i < 8 ; i++){
		 GPIO_A->GPIO_CRH|=(Copy_u8Mode<<(i*GPIO_u8PIN_REG_SIZE));
		}
		*/
		  State = SUCCES ; 
			break  ; 
		case GPIO_PORTB :
		GPIO_B->GPIO_CRH = Copy_Tmode ;
		  State = SUCCES ; 
			break  ; 
		case GPIO_PORTC :
		GPIO_C->GPIO_CRH = Copy_Tmode ;
		  State = SUCCES ; 
		
			break  ; 
		default : 
		  State = FAILIUR ;
			break ; 
	}
	return State ;
 }
ErrorState_t MGPIO_u8SetPortDirection_L(u8 Copy_u8PortId ,u8 Copy_u8Mode) {
		 ErrorState_t State = SUCCES ; 
		 u32 Copy_Tmode= Copy_u8Mode|Copy_u8Mode<<4|Copy_u8Mode<<8|
							Copy_u8Mode<<12|Copy_u8Mode<<16|Copy_u8Mode<<20
							|Copy_u8Mode<<24 |Copy_u8Mode<<28; 
	switch (Copy_u8PortId)
	{
		case GPIO_PORTA :
			GPIO_A->GPIO_CRL = Copy_Tmode ;
			/*
			for (u8 i = 0 ; i < 8 ; i++){
			GPIO_A->GPIO_CRH|=(Copy_u8Mode<<(i*GPIO_u8PIN_REG_SIZE));
			}
			*/
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTB :
			GPIO_B->GPIO_CRL = Copy_Tmode ;
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTC :
			GPIO_C->GPIO_CRL = Copy_Tmode ;
			State = SUCCES ; 
		
			break  ; 
		default : 
			State = FAILIUR ;
			break ; 
	}
	return State ;
}
ErrorState_t MGPIO_u8SetPortValue_L(u8 Copy_u8PortId ,u8 Copy_u8Value) {
	ErrorState_t State = SUCCES ;
	switch (Copy_u8PortId)
	{
		case GPIO_PORTA :
			GPIO_A->GPIO_ODR = Copy_u8Value ;
		
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTB :
			GPIO_B->GPIO_ODR = Copy_u8Value ;
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTC :
			GPIO_C->GPIO_ODR = Copy_u8Value ;
			State = SUCCES ; 
		
			break  ; 
		default : 
			State = FAILIUR ;
			break ; 
	}
	return State ;
}
ErrorState_t MGPIO_u8SetPortValue_H(u8 Copy_u8PortId ,u8 Copy_u8Value){
	ErrorState_t State = SUCCES ;
	switch (Copy_u8PortId)
	{
		case GPIO_PORTA :
		
		    GPIO_A->GPIO_ODR&=~(0xff)<<GPIO_u8OFSET ;
			GPIO_A->GPIO_ODR |= Copy_u8Value<<GPIO_u8OFSET;
		
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTB :
		
		    GPIO_B->GPIO_ODR&=~(0xff)<<GPIO_u8OFSET ;
			GPIO_B->GPIO_ODR |= Copy_u8Value<<GPIO_u8OFSET ;
			
			State = SUCCES ; 
			break  ; 
		case GPIO_PORTC :
		
		    GPIO_C->GPIO_ODR&=~(0xff)<<GPIO_u8OFSET ;  
			GPIO_C->GPIO_ODR |= Copy_u8Value<<GPIO_u8OFSET ;
			
			State = SUCCES ; 
		
			break  ; 
		default : 
			State = FAILIUR ;
			break ; 
	}
	return State ;
}

  
  
  

ErrorState_t MGPIO_enSetPinDirection(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Mode)
{
	ErrorState_t Local_enStatus=SUCCES;
	switch (Copy_u8PortId)
	{
	case  GPIO_PORTA:
		if(Copy_u8PinId<=GPIO_u8f_REG_LEN)
		{
			GPIO_A->GPIO_CRL&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_A->GPIO_CRL|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
		}
		else if(Copy_u8PinId<=GPIO_u8L_REG_LEN)
		{	
			Copy_u8PinId=Copy_u8PinId-GPIO_u8OFSET;

			GPIO_A->GPIO_CRH&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_A->GPIO_CRH|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));

		}
		else
		{
			Local_enStatus=OUT_OF_RANGE;
		}
		break;
		case  GPIO_PORTB:
			if(Copy_u8PinId<=GPIO_u8f_REG_LEN)
		{
			GPIO_B->GPIO_CRL&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_B->GPIO_CRL|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
		}
		else if(Copy_u8PinId<=GPIO_u8L_REG_LEN)
		{	
			Copy_u8PinId=Copy_u8PinId-GPIO_u8OFSET;
			
			GPIO_B->GPIO_CRH&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_B->GPIO_CRH|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));

		}
		else
		{
			Local_enStatus=OUT_OF_RANGE;
		}
		break;
		case  GPIO_PORTC:
			if(Copy_u8PinId<=GPIO_u8f_REG_LEN)
		{
			GPIO_C->GPIO_CRL&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_C->GPIO_CRL|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
		}
		else if(Copy_u8PinId<=GPIO_u8L_REG_LEN)
		{	
			Copy_u8PinId=Copy_u8PinId-GPIO_u8OFSET;
			
			GPIO_C->GPIO_CRH&=~((GPIO_u8CLR_MASK)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));
			GPIO_C->GPIO_CRH|=((Copy_u8Mode)<<(Copy_u8PinId*GPIO_u8PIN_REG_SIZE));

		}
		else
		{
			Local_enStatus=OUT_OF_RANGE;
		}
		
		break;
	
	default:
	Local_enStatus=OUT_OF_RANGE;
		break;
	}

 return Local_enStatus;
}
ErrorState_t MGPIO_enSetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8Value)
{
	ErrorState_t Local_enStatus=SUCCES;
	switch(Copy_u8PortId)
	{
		case GPIO_PORTA: 
			if (Copy_u8Value==GPIO_u8HIGH)
			{
				SET_BIT(GPIO_A->GPIO_ODR,Copy_u8PinId);
			}
			else if(Copy_u8Value==GPIO_u8LOW)
			{
				CLR_BIT(GPIO_A->GPIO_ODR,Copy_u8PinId);

			}
			else
			{
			Local_enStatus=OUT_OF_RANGE;
			}
			
		break;

		case GPIO_PORTB: 
				if (Copy_u8Value==GPIO_u8HIGH)
			{
				SET_BIT(GPIO_B->GPIO_ODR,Copy_u8PinId);
			}
			else if(Copy_u8Value==GPIO_u8LOW)
			{
				CLR_BIT(GPIO_B->GPIO_ODR,Copy_u8PinId);

			}
			else
			{
			Local_enStatus=OUT_OF_RANGE;
			}
			
		break;
		case GPIO_PORTC: 
		if (Copy_u8Value==GPIO_u8HIGH)
			{
				SET_BIT(GPIO_C->GPIO_ODR,Copy_u8PinId);
			}
			else if(Copy_u8Value==GPIO_u8LOW)
			{
				CLR_BIT(GPIO_C->GPIO_ODR,Copy_u8PinId);

			}
			else
			{
			Local_enStatus=OUT_OF_RANGE;
			}
			
		
		
		break;
		default:
			Local_enStatus=OUT_OF_RANGE;
		break;

	}
	return Local_enStatus;
}
ErrorState_t MGPIO_enGetPinValue(u8 Copy_u8PortId,u8 Copy_u8PinId,u8 * ptr_u8ReturnValue)
{
ErrorState_t Local_enStatus=SUCCES;
switch (Copy_u8PortId)
{
case GPIO_PORTA:
		* ptr_u8ReturnValue=GET_BIT(GPIO_A->GPIO_IDR,Copy_u8PinId);
	break;
	case  GPIO_PORTB:
		* ptr_u8ReturnValue=GET_BIT(GPIO_B->GPIO_IDR,Copy_u8PinId);
	break;
	case GPIO_PORTC:
		* ptr_u8ReturnValue=GET_BIT(GPIO_C->GPIO_IDR,Copy_u8PinId);
	break;

default:
		Local_enStatus=OUT_OF_RANGE;
	break;
}
    return Local_enStatus;
}
