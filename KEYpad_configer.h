/*
 * KEYpad_configer.h
 *
 * Created: 1/24/2024 7:03:14 PM
 *  Author: Sara Fayed
 */ 


#ifndef KEYPAD_CONFIGER_H_
#define KEYPAD_CONFIGER_H_

//ROW IS INPUT
#define KPD_ROWS_PORT  DIO_PORTC
#define KPD_ROW0_PIN   DIO_PIN0
#define KPD_ROW1_PIN   DIO_PIN1
#define KPD_ROW2_PIN   DIO_PIN2
#define KPD_ROW3_PIN   DIO_PIN3


 //COLUM IS OUTPUT
 #define KPD_COLS_PORT   DIO_PORTD
 #define KPD_COL0_PIN    DIO_PIN0
 #define KPD_COL1_PIN    DIO_PIN1
 #define KPD_COL2_PIN    DIO_PIN2
 #define KPD_COL3_PIN    DIO_PIN3
 #define key_keys {{'7','8','9','/'},\
                  {'4','5','6','*'},\
                  {'1','2','3','-'},\
                  {'c','0','=','+'}}\

#endif /* KEYPAD_CONFIGER_H_ */