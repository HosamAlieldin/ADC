/*
 * temp_sensor.c
 *
 *  Created on: jan 9, 2020
 *  Author: Hosam
 */

#include "..\Mcal\ADC\adc.h"
#include "..\ECUal\LCD\lcd.h"
#include "..\Mcal\Timer\Timer.h"
#define NO_OF_OVERFLOWS	31
uint8_t gu8_no=0;
void __vector_16(void)__attribute__((signal,used,externally_visible));
void __vector_10(void)__attribute__((signal,used,externally_visible));

void __vector_16()
{
	/* Read ADC Data after conversion complete */
	gu16_res = (uint16_t)ADCL;
	gu16_res |= (uint16_t)(ADCH<<8);
}

void __vector_10()
{
	gu8_no++;
	if (gu8_no == NO_OF_OVERFLOWS)
	{
		/* Read ADC Data after conversion complete */
		gu16_res = (uint16_t)ADCL;
		gu16_res |= (uint16_t)(ADCH<<8);
		gu8_no=0;
	}

}
int main(void)
{
	uint32_t temp;
	LCD_init(); /* initialize LCD driver */

	ADC_Config_str ADC_cfg;
	Timer_cfg_s	Timer_cfg;
	/*ADC config*/
	ADC_cfg.Pre_Scaller = ADC_PRE_64;
	ADC_cfg.Trigger_mode = ADC_TIMER0_CMP;
	ADC_cfg.Channel = ADC0;
	ADC_cfg.Ref = ADC_AVCC;
	ADC_cfg.INT_mode = ADC_INTERRUPT;
	ADC_cfg.Auto_trig = ADC_AUTO_TRIGGER;
	ADC_cfg.Adj = ADC_RIGHT_ADJ;
	ADC_init(&ADC_cfg); /* initialize ADC driver */

	/*Timer config*/
	Timer_cfg.Ch= TIMER0;
	Timer_cfg.Interrupt_Mode= INTERRUPT_MODE;
	Timer_cfg.Timer_Mode= TIMER_MODE ;
	Timer_cfg.PSC= T0_PSC_1024;

	Timer_Init(&Timer_cfg);
	LCD_clearScreen(); /* clear LCD at the beginning */

	/* display this string "Temp =    " only once at LCD */

	LCD_displayString("Temp = ");
	LCD_goToRowColumn(0,10);

	/* display character 'C' on the screen "Temp =   C" */
	LCD_displayCharacter('C');
	Timer_Start(TIMER0,250);
	while(1)
	{
		LCD_goToRowColumn(0,7); /* display the number every time at this position */
		ADC_readChannel(0); /* read channel two where the temp sensor is connect */
		temp = ((uint32_t)gu16_res*150U*5U*2U)/(1023U*3U); /* calculate the temp from the ADC value*/
		LCD_intgerToString(temp); /* display the temp on LCD screen */
	}
}
