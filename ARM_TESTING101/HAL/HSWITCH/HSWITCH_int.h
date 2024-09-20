/*
 * HSWITCH_int.h
 *
 *  Created on: Jul 19, 2023
 *      Author: Elrayes
 */

#ifndef HSWITCH_HSWITCH_INT_H_
#define HSWITCH_HSWITCH_INT_H_

#if HSWITCH_DIR==ACTIVE_LOW
#define SWITCH_OFF 1
#define SWITCH_ON  0
#else
#define SWITCH_OFF 0
#define SWITCH_ON  1
#endif
ErrorState_t Hswitch_enInit(void);
ErrorState_t Hswitch_enGetValue(u8 * ptr_getValue);


#endif /* HSWITCH_HSWITCH_INT_H_ */
