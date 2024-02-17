/*
 * BIT_MATH.h
 *
 *  Created on: Sep 20, 2023
 *      Author: Sara Fayed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_
#define SET_BIT(reg,pin_num)       reg|=(1<<pin_num)
#define CLEAR_BIT(reg,pin_num)     reg&=~(1<<pin_num)
#define TOGGLE_BIT(reg,pin_num)    reg^=(1<<pin_num)
#define GIT_BIT(reg,pin_num)      ((reg>>pin_num)&1)

#endif /* BIT_MATH_H_ */
