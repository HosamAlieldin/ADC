 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega32 ADC driver
 *
 * Author: Hosam
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "..\..\Infrastructure\registers.h"
#include "..\..\Infrastructure\micro_config.h"
#include "..\..\Infrastructure\std_types.h"
#include "..\..\Infrastructure\common_macros.h"
#include "..\Timer\Timer.h"

extern volatile uint16_t gu16_res;
#define ADC_NO_OF_CHANNELS 8

#define ADC_POLLING	   0
#define ADC_INTERRUPT  1

#define ADC_FREE_RUNNING	0
#define ADC_ANALOG_COMP		1
#define ADC_EXTERNAL_INT0	2
#define ADC_TIMER0_CMP		3
#define ADC_TIMER0_OVF		4
#define ADC_TIMER1_CMP		5
#define ADC_TIMER1_ovf		6
#define ADC_TIMER1_ICU		7

#define ADC_RIGHT_ADJ		0
#define ADC_LEFT_ADJ		1

#define ADC0		0
#define ADC1		1
#define ADC2		2
#define ADC3		3
#define ADC4		4
#define ADC5		5
#define ADC6		6
#define ADC7		7

#define ADC_AREF	  0
#define ADC_AVCC 	  1
#define ADC_INTERNAL  3

#define ADC_AUTO_TRIGGER	0
#define ADC_START_CONV		1


#define ADC_PRE_2		1
#define ADC_PRE_4		2
#define ADC_PRE_8		3
#define ADC_PRE_16		4
#define ADC_PRE_32		5
#define ADC_PRE_64		6
#define ADC_PRE_128		7

typedef struct
{
	uint8_t Pre_Scaller;
	uint8_t Trigger_mode;
	uint8_t Channel;
	uint8_t Adj;
	uint8_t Ref;
	uint8_t INT_mode;
	uint8_t Auto_trig;
}ADC_Config_str;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(ADC_Config_str *ADC_cfg);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
void ADC_readChannel(uint8_t channel_num);

#endif /* ADC_H_ */
