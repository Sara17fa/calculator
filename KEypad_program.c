/*
 * KEypad_program.c
 *
 * Created: 1/24/2024 7:01:40 PM
 *  Author: Sara Fayed
 */
#include "Keypad_interface.h"
#include "KEYpad_configer.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STD_TYPE.h"
#include <stdlib.h>
#define F_CPU 100000000
 
void KEP_init(){
	DIO_setpinDirection(KPD_ROWS_PORT,KPD_ROW0_PIN,DIO_PIN_INTPUT);
	DIO_setpinDirection(KPD_ROWS_PORT,KPD_ROW1_PIN,DIO_PIN_INTPUT);
	DIO_setpinDirection(KPD_ROWS_PORT,KPD_ROW2_PIN,DIO_PIN_INTPUT);
	DIO_setpinDirection(KPD_ROWS_PORT,KPD_ROW3_PIN,DIO_PIN_INTPUT);
	
	DIO_setpinDirection(KPD_COLS_PORT,KPD_COL0_PIN,DIO_PIN_OUTPUT);
	DIO_setpinDirection(KPD_COLS_PORT,KPD_COL1_PIN,DIO_PIN_OUTPUT);
	DIO_setpinDirection(KPD_COLS_PORT,KPD_COL2_PIN,DIO_PIN_OUTPUT);
	DIO_setpinDirection(KPD_COLS_PORT,KPD_COL3_PIN,DIO_PIN_OUTPUT);
	//INIAL ROWAS IS 1
	DIO_activeportINpullURresistance(KPD_ROWS_PORT,KPD_ROW0_PIN);
	DIO_activeportINpullURresistance(KPD_ROWS_PORT,KPD_ROW1_PIN);
	DIO_activeportINpullURresistance(KPD_ROWS_PORT,KPD_ROW2_PIN);
	DIO_activeportINpullURresistance(KPD_ROWS_PORT,KPD_ROW3_PIN);
	
	
}
void KEP_getvalue(u8* returnvalue){
	
	if (returnvalue!=NULL)
	
	{
		*returnvalue=255;
		
		u8 pin_Value;
		u8 pinflag=0;
		u8 columscounter,rowscounter;
		u8 arrcol[4]={KPD_COL0_PIN,KPD_COL1_PIN,KPD_COL2_PIN,KPD_COL3_PIN};
		u8 arrrow[4]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};
				
		     u8 KPD_keys[4][4]=key_keys;
		for (columscounter=0;columscounter<4;columscounter++)
		{
	      DIO_setpinValue(KPD_COLS_PORT,arrcol[columscounter],DIO_PIN_LOW);
		  for(rowscounter=0;rowscounter<4;rowscounter++){
			 DIO_GETPINVALUE(KPD_ROWS_PORT,arrrow[rowscounter],&pin_Value);
			 
			if (pin_Value==0)
			{
				while (pin_Value==0)
				{
					DIO_GETPINVALUE(KPD_ROWS_PORT,arrrow[rowscounter],& pin_Value);
				}
				//pressed
				*returnvalue=KPD_keys[rowscounter][columscounter];
				pinflag=1;
				break;
			}
			  
			  
			  
		  }
		  if (1==pinflag)
		  {
			//  return returnvalue;
			  break;
			  
		  }
		  //active secand colum
		  
		  DIO_setpinValue(KPD_COLS_PORT,arrcol[columscounter],DIO_PIN_HIGH);
		}
		
	}
	
	else{
		
		
	//do no thing
		
	}
	
}