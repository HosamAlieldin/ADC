/*
 * common_macros.h
 *
 *  Created on: Jun 18, 2019
 *      Author: Lenovo
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=~(1<<BIT))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define GET_BIT(REG,BIT) ((REG & (1<<BIT))>>BIT)
#define ROR(REG,num) (REG=(REG >> num ) | (REG << (8-num)))
#define ROL(REG,num) (REG=(REG << num ) | (REG >> (8-num)))
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))
#endif /* COMMON_MACROS_H_ */
