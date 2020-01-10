/*
 * Timer.h
 *
 *  Created on: Nov 23, 2019
 *      Author: Hosam
 */

#ifndef TIMER_H_
#define TIMER_H_


#include "..\..\Infrastructure\common_macros.h"
#include "..\..\Infrastructure\std_types.h"
#include "..\..\Infrastructure\registers.h"

#define MS_CALCULATIONS 1000 / 128
/* Number of Ticks per OVF */

#define TIMER0_MAX 255

#define TIMER2_MAX 255

/* Timer Channels */

#define TIMER0 0
#define TIMER1 1
#define TIMER2 2

/* Timer or Counter */

#define TIMER_MODE 		0
#define COUNTER_MODE 	1

/* Interrupt or Polling */

#define INTERRUPT_MODE 	1
#define POLLING_MODE 	0

#define NO_OF_CHANNELS 3

/* Prescalers for Timer 0*/

#define T0_NO_CLK             	 0
#define T0_PSC_0                 1
#define T0_PSC_8                 2
#define T0_PSC_64                3
#define T0_PSC_256               4
#define T0_PSC_1024              5
#define T0_EXT_CLK_ON_FALLING    6
#define T0_EXT_CLK_ON_RISSING    7

/* Prescalers for Timer 2*/

#define T2_NO_CLK             	0
#define T2_PSC_0                1
#define T2_PSC_8                2
#define T2_PSC_32               3
#define T2_PSC_64               4
#define T2_PSC_128              5
#define T2_PSC_256              6
#define T2_PSC_1024             7

/* Frequency for ms and 8 MHz */

#define CONST_FOR_8MHZ 		8000	/* (1 /1000)ms * 8000000 */
#define CONST_FOR_1MHZ 		1000	/* (1 /1000)ms * 1000000 */

/* Timer configuration Structure */

typedef struct{
	uint8_t Ch;
	uint8_t PSC;
	uint8_t Interrupt_Mode;
	uint8_t Timer_Mode;
}Timer_cfg_s;



extern uint8_t Timer_Init(Timer_cfg_s *T_cfg);

/*extern void Timer_Start(u32 Time ,uint8_t Timer_Channel);*/

extern uint8_t Timer_Start(uint8_t Timer_Channel,uint32_t Tick_Counts);

extern uint8_t Timer_Stop(uint8_t Timer_Channel);

extern uint8_t Timer_Reset(uint8_t Timer_Channel);

extern uint8_t Timer_Get_TickTime(uint8_t Timer_Channel, uint16_t *Timer_Time);


#endif /* TIMER_H_ */


