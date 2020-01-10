#include "dio_cfg.h"

#ifndef DIO_H_
#define DIO_H_

uint8_t DIO_Pin_Write(uint8_t Pin_no,uint8_t val);
uint8_t DIO_Pin_Read(uint8_t Pin_no,uint8_t *val);
uint8_t DIO_Port_Write(uint8_t Port_no,uint8_t val);
uint8_t DIO_Port_Read(uint8_t Port_no,uint8_t *val);
uint8_t DIO_Init_Port(uint8_t Port_no,uint8_t val);
uint8_t DIO_Init_Pin(uint8_t Pin_no,uint8_t val);
uint8_t DIO_Activate_Pullup(uint8_t Pin_no);
#endif /* DIO_H_*/
