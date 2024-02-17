/*
 * DIO_PROTOTYEP.h
 *
 * Created: 9/27/2023 7:48:42 PM
 *  Author: Sara Fayed
 */ 


#ifndef DIO_PROTOTYEP_H_
#define DIO_PROTOTYEP_H_
#include "STD_TYPE.h"

#include "BIT_MATH.h"

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3

#define DIO_PIN_OUTPUT    1
#define DIO_PIN_INTPUT    0

#define DIO_PIN_HIGH   1
#define DIO_PIN_LOW    0


#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7

void DIO_setpinValue      (u8 Port_ID, u8 pin_ID,u8 pin_Value);
void DIO_setpinDirection    (u8 Port_ID, u8 pin_ID,u8 pindirection);
void DIO_togglepinValue        (u8 potr_ID,u8 pin_ID);


void  DIO_GETPINVALUE(u8 port_id,u8 pin_ID,u8 *pin_Value);
void DIO_activeportINpullURresistance(u8 port_ID,u8 pin_ID);

#endif /* DIO_PROTOTYEP_H_ */