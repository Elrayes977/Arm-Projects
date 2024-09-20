/*
 * Config.h
 *
 *  Created on: May 29, 2023
 *      Author: Elrayes
 */

#ifndef HAL_LED_HLED_CONFIG_H_
#define HAL_LED_HLED_CONFIG_H_
/*
 * please conifgure LED pins
 *
 * please choose led direction
 * HLED_LED_FORWARD , HLED_LED_REVERSE
 *
 * */
#define HLED_RED_LED_PIN	PC13
#define HLED_RED_LED_DIR	HLED_LED_FORWARD




#define HLED_GRN_LED_PIN	PC14
#define HLED_GRN_LED_DIR	HLED_LED_REVERSE

#define HLED_BLUE_LED_PIN	PC15
#define HLED_BLUE_LED_DIR	HLED_LED_REVERSE

#endif /* HAL_LED_HLED_CONFIG_H_ */
