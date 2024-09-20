/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:24/7/2023
	Version: 1.0.0
	SWC:EXTI

	*****************************
 */

#ifndef MEXTI_MEXTI_INT_H_
#define MEXTI_MEXTI_INT_H_

typedef enum {
    EXTI0 = 0,
    EXTI_1,
    EXTI_2,
    EXTI_3,
    EXTI_4,
    EXTI_5,
    EXTI_6,
    EXTI_7,
    EXTI_8,
    EXTI_9,
    EXTI_10,
    EXTI_11,
    EXTI_12,
    EXTI_13,
    EXTI_14,
    EXTI_15
}EXTI_LINE_t;

typedef enum{
	RISING_EDGE=0,
	FALING_EDGE,
	ANY_CHANGE

}TRIG_SET_t;


ErrorState_t MEXTI_enInit(EXTI_LINE_t copy_u8LineSelect);
ErrorState_t MEXTI_enEnable(u8 Copy_EdgeSelect);
ErrorState_t MEXTI_enDisable(u8 Copy_EdgeSelect);
ErrorState_t MEXTI_enSWI_Enable();
ErrorState_t MEXTI_enSWI_Disable();
ErrorState_t MEXTI_enSetSignalLatch();

#endif /* MEXTI_MEXTI_INT_H_ */
