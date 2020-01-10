#include "dio.h"

/* global array of pointers to address ports available */
volatile uint8_t* const gapu8_PORT[]={&PORT_REGA,&PORT_REGB,&PORT_REGC,&PORT_REGD};
volatile uint8_t* const gapu8_DDR[]= {&DIR_REGA,&DIR_REGB,&DIR_REGC,&DIR_REGD};
volatile uint8_t* const gapu8_PIN[]= {&PIN_REGA,&PIN_REGB,&PIN_REGC,&PIN_REGD};


/***************************************************************************
 * Function: DIO_Init_Port
 * @param: Port_no, Port number sent by the user
 * @param: val, value to assign to port
 * Description: Function to initialize Port Direction and return status
 **************************************************************************/
uint8_t DIO_Init_Port(uint8_t Port_no , uint8_t val)
{
	if (Port_no< number_of_ports)
	{
		*gapu8_DDR[Port_no]=val;
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}

/***************************************************************************
 * Function: DIO_Init_Pin
 * @param: Port_no, Pin number sent by the user
 * @param: val, value to assign to pin
 * Description: Function to initialize Pin Direction and return status
 **************************************************************************/

uint8_t DIO_Init_Pin(uint8_t Pin_no, uint8_t val)
{
	uint8_t port ,pin ;
	if (Pin_no < number_of_all_pins)
	{
		port = Pin_no / number_of_pins;
		pin = Pin_no % number_of_pins;
		if (val == HIGH)
		{
			SET_BIT(*gapu8_DDR[port],pin);
			return ERROR_OK;
		}
		else if (val == LOW)
		{
			CLEAR_BIT(*gapu8_DDR[port],pin);

			return ERROR_OK;
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
}

/***************************************************************************
 * Function: DIO_Port_Read
 * @param: Port_no, Port number sent by the user
 * @param: *val, value to read from port
 * Description: Function to return Port value and return status
 **************************************************************************/

uint8_t DIO_Port_Read (uint8_t Port_no, uint8_t *val)
{
	if (Port_no < number_of_ports)
	{
		*val = *gapu8_PIN[Port_no];
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}

/***************************************************************************
 * Function: DIO_Pin_Read
 * @param: Pin_no, Pin number sent by the user
 * @param: *val, value to read from pin
 * Description: Function to return Pin value and return status
 **************************************************************************/

uint8_t DIO_Pin_Read (uint8_t Pin_no, uint8_t *val)
{
	uint8_t port , pin ;
	if (Pin_no < number_of_all_pins)
	{
		port = Pin_no / number_of_pins;
		pin = Pin_no % number_of_pins;
		*val = GET_BIT(*gapu8_PIN[port],pin);
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}

/***************************************************************************
 * Function: DIO_Port_Write
 * @param: Port_no, Port number sent by the user
 * @param: val, value to write to port
 * Description: Function to write Port value and return status
 **************************************************************************/

uint8_t DIO_Port_Write(uint8_t Port_no,uint8_t val)
{
	if (Port_no < number_of_ports)
	{
		*gapu8_PORT[Port_no]=val;
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}

/***************************************************************************
 * Function: DIO_Pin_Write
 * @param: Pin_no, Pin number sent by the user
 * @param: val, value to write to pin
 * Description: Function to write Pin value and return status
 **************************************************************************/

uint8_t DIO_Pin_Write(uint8_t Pin_no,uint8_t val)
{
	uint8_t port,pin;
	if(Pin_no < number_of_all_pins)
	{
		port = Pin_no / number_of_pins;
		pin = Pin_no % number_of_pins;
		if (val == HIGH)
		{
			SET_BIT(*gapu8_PORT[port],pin);
			return ERROR_OK;
		}
		else if (val == LOW)
		{
			CLEAR_BIT(*gapu8_PORT[port],pin);
			return ERROR_OK;
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
}

/***************************************************************************
 * Function: DIO_Activate_Pullup
 * @param: Pin_no, Pin number sent by the user
 * Description: Function to enable the internal Pull-up resistor of a Pin
 **************************************************************************/

uint8_t DIO_Activate_Pullup(uint8_t Pin_no)
{
	uint8_t port ,pin ;
	if (Pin_no < number_of_all_pins)
	{
		port = Pin_no / number_of_pins;
		pin = Pin_no % number_of_pins;
		SET_BIT(*gapu8_PORT[port],pin);
		return ERROR_OK;
	}
	else
	{
		return ERROR_NOK;
	}
}
