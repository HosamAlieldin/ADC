/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega32 ADC driver
 *
 * Author: Hosam
 *
 *******************************************************************************/

#include "adc.h"
volatile uint16_t gu16_res=0;

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
static uint8_t gu8_conversion =0;
static uint8_t gu8_INT =0;
void ADC_init(ADC_Config_str *ADC_cfg)
{
	if (NULL_PTR != ADC_cfg)
	{
		if ((ADC_cfg->Channel) < ADC_NO_OF_CHANNELS)
		{
			ADMUX=(ADMUX&0x3F) | ADC_cfg->Ref;
			ADMUX=(ADMUX&0xDF) | ADC_cfg->Adj;
			ADMUX=(ADMUX&0xE0) | ADC_cfg->Channel;
			SFIOR = (SFIOR&0x1F)| ADC_cfg->Trigger_mode;
			if(ADC_cfg->Auto_trig == ADC_AUTO_TRIGGER)
			{
				ADCSRA|=(1<<ADATE);
			}
			if((ADC_cfg->INT_mode) == ADC_POLLING)
			{
				ADCSRA&=~(1<<ADIE);
				gu8_INT = ADC_POLLING;
				ADCSRA = (ADCSRA & 0xF8) | ADC_cfg->Pre_Scaller;
				gu8_conversion= ADC_cfg->Auto_trig;
			}
			else if ((ADC_cfg->INT_mode)== ADC_INTERRUPT)
			{
				SREG|=(1<<I);
				ADCSRA|=(1<<ADIE);
				gu8_INT= ADC_INTERRUPT;
				ADCSRA = (ADCSRA & 0xF8) | ADC_cfg->Pre_Scaller;
				gu8_conversion= ADC_cfg->Auto_trig;
			}
			ADCSRA|=(1<<ADEN);
		}
		else
		{

		}
	}
	else
	{

	}
}

void ADC_readChannel(uint8_t channel_num)
{
	channel_num &= 0x07; /* channel number must be from 0 --> 7 */
	ADMUX &= 0xE0; /* clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel */
	ADMUX = ADMUX | channel_num; /* choose the correct channel by setting the channel number in MUX4:0 bits */

	if(gu8_INT == ADC_POLLING)
	{
		if(gu8_conversion == ADC_START_CONV)
		{
			SET_BIT(ADCSRA,ADSC); /* start conversion write '1' to ADSC */
			while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* wait for conversion to complete ADIF becomes '1' */
			SET_BIT(ADCSRA,ADIF); /* clear ADIF by write '1' to it :) */
			gu16_res = (uint16_t)ADCL;
			gu16_res |= (((uint16_t)ADCH<<8));
		}
		else if (gu8_conversion == ADC_AUTO_TRIGGER)
		{

		}
	}
	else if (gu8_INT == ADC_INTERRUPT)
	{
		if(gu8_conversion == ADC_START_CONV)
		{
			SET_BIT(ADCSRA,ADSC);    /* start conversion write '1' to ADSC */
		}
		else if(gu8_conversion == ADC_AUTO_TRIGGER)
		{
			Timer_Start(TIMER0,250);
		}
	}
}
