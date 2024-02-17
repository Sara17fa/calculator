/*
 * CFile1.c
 *
 * Created: 1/27/2024 3:14:14 PM
 *  Author: Sara Fayed
 */
#include <avr/io.h>
#include "util/delay.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "lcd_confier.h"
#include <stdlib.h>
#include "STD_TYPE.h" 
#include "LCD_pins.h"




void LCD_init(){
	DIO_setpinDirection(lcd_control_port,lcd_RS,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_control_port,lcd_R_W,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_control_port,lcd_enable,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_port_data,lcd_pin0_data,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_port_data,lcd_pin1_data,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_port_data,lcd_pin2_data,DIO_PIN_OUTPUT);
	DIO_setpinDirection(lcd_port_data,lcd_pin3_data,DIO_PIN_OUTPUT);
	_delay_ms(40);
	DIO_setpinValue(lcd_control_port,lcd_R_W,DIO_PIN_LOW);
	DIO_setpinValue(lcd_control_port,lcd_RS,DIO_PIN_LOW);
	
	write_data(0b0010);
	//enable
	
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_LOW);
	
	LCD_sendcommand(0b00101000);
	LCD_sendcommand(0X0E);
	LCD_sendcommand(0X06);
	LCD_sendcommand(0X01);
	
	
	
}
void LCD_sendcommand(u8 comm){
	
	
	DIO_setpinValue(lcd_control_port,lcd_R_W,DIO_PIN_LOW);

	DIO_setpinValue(lcd_control_port,lcd_RS,DIO_PIN_LOW);
     	write_data(comm>>4);
	
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_LOW);
	
	write_data(comm);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_LOW);
	
}
void LCD_senddata(u8 key){
	DIO_setpinValue(lcd_control_port,lcd_R_W,DIO_PIN_LOW);
DIO_setpinValue(lcd_control_port,lcd_RS,DIO_PIN_HIGH);	
	
	write_data(key>>4);
	
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_LOW);
	
	write_data(key);
	
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_HIGH);
	_delay_ms(1);
	DIO_setpinValue(lcd_control_port,lcd_enable,DIO_PIN_LOW);
	
}
void LCD_sendstring(u8*data){
	
		int i=0;
		while(((data[i]))!=NULL)
		{
			
				LCD_senddata((data[i]));
			i++;
		}
	
}
void LCD_clear(){
	
	
	LCD_sendcommand(0X01);
	
}

void write_data(u8 value){
	u8 arrydata[4]={lcd_pin0_data,lcd_pin1_data,lcd_pin2_data,lcd_pin3_data};
	for (int i=0;i<4;i++)
	{
		if (GIT_BIT(value,i)==1)
		{
			DIO_setpinValue(lcd_port_data,arrydata[i],DIO_PIN_HIGH);
		}
		else{
			DIO_setpinValue(lcd_port_data,arrydata[i],DIO_PIN_LOW);
		}
	}
	
	
}
void LCD_intgerToString(int dat){
	u8 buff[16];
	itoa(dat,buff,10);
	LCD_sendstring(buff);
}
