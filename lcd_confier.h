/*
 * lcd_confier.h
 *
 * Created: 1/27/2024 3:15:15 PM
 *  Author: Sara Fayed
 */ 


#ifndef LCD_CONFIER_H_
#define LCD_CONFIER_H_
#include "STD_TYPE.h"
void LCD_init();
void write_data(u8 value);
void LCD_sendcommand(u8 comm);
void LCD_senddata(u8 key);
void LCD_sendstring(u8*data);
void LCD_clear();
void LCD_intgerToString(int dat);




#endif /* LCD_CONFIER_H_ */