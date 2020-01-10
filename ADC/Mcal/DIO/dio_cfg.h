#include "..\..\Infrastructure\registers.h"
#include "..\..\Infrastructure\std_types.h"
#include "..\..\Infrastructure\common_macros.h"
#include "..\..\Infrastructure\micro_config.h"

#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


#define number_of_ports 4
#define number_of_pins 8
#define number_of_all_pins	32

#define DIR_REGA	DDRA
#define DIR_REGB	DDRB
#define DIR_REGC	DDRC
#define DIR_REGD	DDRD


#define PORT_REGA	PORTA
#define PORT_REGB	PORTB
#define PORT_REGC	PORTC
#define PORT_REGD	PORTD


#define PIN_REGA	PINA
#define PIN_REGB	PINB
#define PIN_REGC	PINC
#define PIN_REGD	PIND

#define PA0			0
#define PA1			1
#define PA2			2
#define PA3			3
#define PA4			4
#define PA5			5
#define PA6			6
#define PA7			7

#define PB0			8
#define PB1			9
#define PB2			10
#define PB3			11
#define PB4			12
#define PB5			13
#define PB6			14
#define PB7			15

#define PC0			16
#define PC1			17
#define PC2			18
#define PC3			19
#define PC4			20
#define PC5			21
#define PC6			22
#define PC7			23

#define PD0			24
#define PD1			25
#define PD2			26
#define PD3			27
#define PD4			28
#define PD5			29
#define PD6			30
#define PD7			31

#endif /*DIO_CONFIG_H_*/
