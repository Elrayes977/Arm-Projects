/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:25/7/2023
	Version: 1.0.0
	SWC:STK

	*****************************
 */

#ifndef MSYSTICK_MSTK_INT_H_
#define MSYSTICK_MSTK_INT_H_


ErrorState_t MSTK_enInit(void);
ErrorState_t MSTK_enSetBusyWait(u32 copy_u8Ticks);
ErrorState_t MSTK_enSetInterValSingle(u8 copy_u8Time, void (*ptrfn)(void));
ErrorState_t MSTK_enSetInterValPeriodic(u8 copy_u8Time, void (*ptrfn)(void));
ErrorState_t MSTK_enStopTimer(void);
ErrorState_t MSTK_enGetElapsedTime(u32 * ptrReturn);
ErrorState_t MSTK_enGetRemainingTime(u32 * ptrReturn);


#endif /* MSYSTICK_MSTK_INT_H_ */
