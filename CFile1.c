/*
 * CFile1.c
 *
 * Created: 2/11/2024 9:31:46 PM
 *  Author: Sara Fayed
 */ 
#include "BIT_MATH.h"
#include "calcul_confi.h"
#include "DIO_interface.h"
#include "KEYpad_configer.h"
#include "Keypad_interface.h"
#include "lcd_confier.h"
#include "LCD_pins.h"
#include <avr/io.h>
#include <stdlib.h>
#include "STD_TYPE.h"
#include <util/delay.h>


u16 collect_numbers(u8 *inputarr,u8 inpcounter){
	int i=0,rs=0;
	while(1){
		if (inputarr[i]=='-')
		{
			rs=inputarr[i]-inputarr[i+1];
			return rs;
		}
				
		if (inputarr[i]=='+')
		{
			rs=inputarr[i]+inputarr[i+1];
			return rs;
		}
		if (inputarr[i]=='*')
		{
			rs=inputarr[i]*inputarr[i+1];
			return rs;
		}
	}
}