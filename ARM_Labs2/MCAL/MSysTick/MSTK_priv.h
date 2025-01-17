/*
 *
	*****************************
	Author:Abdelrahman Elrayes
	Origin Date:25/7/2023
	Version: 1.0.0
	SWC:STK

	*****************************
 */

#ifndef MSYSTICK_MSTK_PRIV_H_
#define MSYSTICK_MSTK_PRIV_H_
//modes
#define AHB_MODE	1
#define AHB_OVER_8_MODE	0
//STK_CTRL_reg
#define ENABLE_BIT 		0
#define TICKINT_BIT		1
#define CLKSOURCE_BIT	2
#define COUNTFLAG		3
////////
#define MAX_LOAD_VALUE  16777215 //2^24 -1


#define STK_MODE_PERIODIC	 1
#define STK_MODE_SINGLE   	 2
#endif /* MSYSTICK_MSTK_PRIV_H_ */
