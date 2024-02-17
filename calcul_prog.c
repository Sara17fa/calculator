/*
 * calcul_prog.c
 *
 * Created: 2/9/2024 5:55:13 PM
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

void collect_numbers(u8 *inputarr){
	u8 i=0,count=0;
	//u8 mul_div_count=0;
	int error=0;
	
	int opercount=0;
	u16 operand[17]={0};
			u8 operator[17]={0};

	
	 while(inputarr[i]!='='){
		 
		 
				switch(inputarr[i]){
					
					
					case '*' :
					inputarr[i-1]=((inputarr[i-1]-'0')*(inputarr[i+1]-'0'))+'0';
					inputarr[i+1]='0';
					inputarr[i]='0';
					count++;
					i=0;
					
					//i++;
					//opercount++;
					break;
					
// 					case '-':
// 					i++;
// 					while((inputarr[i]-'0')<=9&&(inputarr[i]-'0')>=0){
// 						operand[opercount]=(inputarr[i]-'0');
// 						i++;
// 						
// 					}
// 					operand[opercount]*=-1;
// 					
// 					opercount++;
// 					
					//break;
					case '/':
			if ((inputarr[i+1]-'0')==0)
					{
						LCD_clear();
						LCD_sendstring("ERROR");
						error=1;
						break;
						
					}
					
					else{
						inputarr[i-1]=((inputarr[i-1]-'0')/(inputarr[i+1]-'0'))+'0';
						inputarr[i+1]='0';
						inputarr[i]='0';
						count++;
						i=0;
						//opercount++;
						
					break;
					}
				
				}
				i++;
				
			}
			
			i=0;
			while(inputarr[i]!='='){
				
				
				switch(inputarr[i]){
					case '-':
					
					
					inputarr[i]	=((inputarr[i+1]-'0')*(-1))+'0';
					i=0;
					inputarr[i+1]='0';
						
						count++;
										break;
					case '+':
					
					
					inputarr[i-1]	=((inputarr[i+1]-'0')+(inputarr[i-1]-'0'))+'0';
					inputarr[i+1]='0';
					inputarr[i]='0';
					i=0;
				count++;
					break;
					
			 }
			 i++;
			 
			}
	if (count==1)
	{
		LCD_intgerToString(inputarr[0]-'0');
	}
	 
	else {		
			int result=0;
for (int k=0;k<4;k++)
{
	result+=(inputarr[k]-'0');

}
LCD_intgerToString(result);	

	result=0;
	
	}
		
	
}
