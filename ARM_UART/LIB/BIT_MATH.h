/*
 * BIT_MATH.h
 *
 *  Created on: May 28, 2023
 *      Author: Elrayes
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(reg,bit)  (reg|=(1<<(bit)))
#define CLR_BIT(reg,bit)  (reg&=~(1<<(bit)))
#define TOG_BIT(reg,bit)  (reg^=(1<<(bit)))
#define GET_BIT(reg,bit)  ((reg>>(bit))&1)
#define WRITE_BIT(reg,bit,val)    (reg=(((reg)&~(1<<bit))|(val<<bit)))
#endif /* BIT_MATH_H_ */
