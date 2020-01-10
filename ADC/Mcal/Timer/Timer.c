/*
 * Timer.c
 *
 *  Created on: Nov 23, 2019
 *      Author: Hosam
 */


#include "Timer.h"

/*Holds prescalers of each timer*/
static uint8_t Timer0_PSC = 0;


/*Holds interrupt or polling mode */
static uint8_t Timer0_Mode = 0;




/**
 *
 * @param T_cfg,contain configuration struct
 *
 * Description : Initialize the timer
 */
uint8_t Timer_Init(Timer_cfg_s *T_cfg)
{
	if(NULL_PTR != T_cfg )
	{
		if((T_cfg->Ch) < NO_OF_CHANNELS)
		{
			if(TIMER0 == T_cfg->Ch)
			{

				if(TIMER_MODE == T_cfg->Timer_Mode)
				{
					Timer0_PSC = T_cfg->PSC;

				}
				else if(COUNTER_MODE == T_cfg->Timer_Mode)
				{
					Timer0_PSC = T_cfg->PSC;
					if(T0_EXT_CLK_ON_FALLING == T_cfg->PSC)
					{
						SET_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);
						CLEAR_BIT(TCCR0,CS00);
					}
					else if(T0_EXT_CLK_ON_RISSING == T_cfg->PSC)
					{
						SET_BIT(TCCR0,CS00);
						SET_BIT(TCCR0,CS01);
						SET_BIT(TCCR0,CS02);
					}
					else
					{
						return ERROR_NOK;
					}
				}
				else
				{
					return ERROR_NOK;
				}
				if(INTERRUPT_MODE == T_cfg->Interrupt_Mode)
				{
					SET_BIT(TIMSK,OCIE0);
					SET_BIT(TCCR0,WGM01);
					CLEAR_BIT(TCCR0,WGM00);
					Timer0_Mode = INTERRUPT_MODE;
					SET_BIT(SREG,I);
				}
				else if(POLLING_MODE == T_cfg->Interrupt_Mode)
				{
					CLEAR_BIT(TIMSK,TOIE0);
					Timer0_Mode = POLLING_MODE;
				}
				else
				{
					return ERROR_NOK;
				}
				return ERROR_OK;
			}
			else if(TIMER1 == T_cfg->Ch)
			{

			}
			else if(TIMER2 == T_cfg->Ch)
			{

			}
			else
			{
				return ERROR_NOK;
			}
		}else
		{
			return ERROR_NOK;
		}
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}

/**
 *
 * @param Channel,which Timer to stop
 *
 * Description : Stop the chosen timer
 */
uint8_t Timer_Stop(uint8_t Timer_Channel)
{
	if(Timer_Channel < NO_OF_CHANNELS)
	{
		if(TIMER0 == Timer_Channel )
		{
			CLEAR_BIT(TCCR0,CS00);
			CLEAR_BIT(TCCR0,CS01);
			CLEAR_BIT(TCCR0,CS02);
		}else if(TIMER1 == Timer_Channel )
		{

		}else
		{

		}
		return 	ERROR_OK;
	}else
	{
		return ERROR_NOK;
	}
}

/**
 *
 * @param Time,time required in ms
 * @param Channel, which timer is being used
 *
 * Description : Function to start counting
 */


extern uint8_t Timer_Start(uint8_t Timer_Channel,uint32_t Tick_Counts)
{
	if(Timer_Channel < NO_OF_CHANNELS)
	{
		if(Tick_Counts <= TIMER0_MAX)
		{
			OCR0 = Tick_Counts;
		}else
		{
			return ERROR_NOK;
		}
		
		
		if(TIMER0 == Timer_Channel)
		{
			if(T0_NO_CLK == Timer0_PSC)
			{
				CLEAR_BIT(TCCR0,CS00);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS02);
			}
			else if(T0_PSC_0 == Timer0_PSC)
			{
				SET_BIT(TCCR0,CS00);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS02);
			}
			else if(T0_PSC_8 == Timer0_PSC)
			{
				SET_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS00);
				CLEAR_BIT(TCCR0,CS02);
			}
			else if(T0_PSC_64 == Timer0_PSC)
			{
				SET_BIT(TCCR0,CS00);
				SET_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS02);
			}
			else if(T0_PSC_256 == Timer0_PSC)
			{
				SET_BIT(TCCR0,CS02);
				CLEAR_BIT(TCCR0,CS01);
				CLEAR_BIT(TCCR0,CS00);
			}
			else if(T0_PSC_1024 == Timer0_PSC)
			{
				TCCR0 |= (1<<CS00) | (1<<CS02);
				CLEAR_BIT(TCCR0,CS01);
			}else
			{
				return ERROR_NOK;
			}

		}else if(TIMER1 == Timer_Channel)
		{

		}else
		{

		}


		if(POLLING_MODE == Timer0_Mode)
		{

		}else if(INTERRUPT_MODE == Timer0_Mode)
		{		
			
		}else
		{
			return ERROR_NOK;
		}
	return ERROR_OK;
	}else
	{
		return ERROR_NOK;
	}
}


extern uint8_t Timer_Reset(uint8_t Timer_Channel)
{
	if(Timer_Channel < NO_OF_CHANNELS)
	{
		if(TIMER0 == Timer_Channel)
		{
			TCNT0 = 0;
			return ERROR_OK;
		}else if(TIMER1 == Timer_Channel)
		{
			return ERROR_OK;
		}else
		{
			return ERROR_OK;
		}
	}else
	{
		return ERROR_NOK;
	}
}

extern uint8_t Timer_Get_TickTime(uint8_t Timer_Channel, uint16_t *Timer_Time)
{
	if(Timer_Channel < NO_OF_CHANNELS)
	{
		if(TIMER0 == Timer_Channel)
		{
			*Timer_Time = TCNT0;
			return ERROR_OK;
		}else if(TIMER1 == Timer_Channel)
		{
			return ERROR_OK;
		}else
		{
			return ERROR_OK;
		}

	}else
	{
		return ERROR_NOK;
	}
}


