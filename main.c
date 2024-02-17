/*
 * simple_calculator.c
 *
 * Created: 2/9/2024 5:54:34 PM
 * Author : Sara Fayed
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
#include <string.h>

int main(void)
{
	// u8 mul_div_count=0;
	
	// u8 opercount=0;
	//u8  operand[17]={0};
	u8 inputarry[17]={0};
	u8 key=255,inpcounter=0;	
    /* Replace with your application code */
	LCD_init();
	KEP_init();
	LCD_sendstring("simple calculator");
	_delay_ms(1000);
	LCD_clear();
	
	
    while (1) 
    {
	KEP_getvalue(&key);
	if (key!=255)
	{
		
			switch(key){
				
				case '0':
				case '1':
				case '2' :
				case '3':
				case '4' :
				case '5' :
				case '6' :
				case '7' :
				case '8' :
				case  '9':
				//LCD_intgerToString(key);
				LCD_senddata(key);
				inputarry[inpcounter]=key;
				inpcounter++;
				break;
				case '+':
				case '-':
				case '*':
				case '/':
				LCD_senddata(key);
				inputarry[inpcounter]=key;
				inpcounter++;
				break;
				case '=':
				LCD_senddata(key);
				inputarry[inpcounter]=key;
				collect_numbers(&inputarry);

				
				
				
				break;
				
				case 'c':
				
					LCD_clear();
					memset(inputarry,0,sizeof(inputarry));
					inpcounter=0;
				
				break;
			
			}
		}
		
  else{
	//do no thing
}
	}
		
	}

