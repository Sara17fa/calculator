/*
 * DIO_FUNCTION.c
 *
 * Created: 9/27/2023 7:49:25 PM
 *  Author: Sara Fayed
 */ 
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "STD_TYPE.h"
#include <util/delay.h>
#include <stdlib.h>
#include <avr/io.h>


void DIO_setpinDirection(u8 Port_ID, u8 pin_ID,u8 pindirection){      //port_id (0..3)  pin_id(0...7) direction(0,1)
	switch(Port_ID){
	    case DIO_PORTA:
	       if(pindirection==DIO_PIN_OUTPUT)	{
			   SET_BIT(DDRA,pin_ID);
	     }
	        else{
				CLEAR_BIT(DDRA,pin_ID);
	     }
	            break;
	   
	    case DIO_PORTB:
	    if(pindirection==DIO_PIN_OUTPUT)	{
		    SET_BIT(DDRB,pin_ID);
	    }
	    else{
		    CLEAR_BIT(DDRB,pin_ID);
	    }
	    break;
		
		 case DIO_PORTC:
		 if(pindirection==DIO_PIN_OUTPUT)	{
			 SET_BIT(DDRC,pin_ID);
		 }
		 else{
			 CLEAR_BIT(DDRC,pin_ID);
		 }
		 break;
		 
		  case DIO_PORTD:
		  if(pindirection==DIO_PIN_OUTPUT)	{
			  SET_BIT(DDRD,pin_ID);
		  }
		  else{
			  CLEAR_BIT(DDRD,pin_ID);
		  }
		  break;
		
   }
		
}
void DIO_setpinValue(u8 Port_ID, u8 pin_ID,u8 pin_Value){
	if ((Port_ID<=3) &&  (pin_ID<=7) &&(pin_Value==DIO_PIN_OUTPUT||pin_Value==DIO_PIN_INTPUT))
	{
		switch(Port_ID){
			case DIO_PORTA:
			if(DIO_PIN_HIGH==pin_Value){
				SET_BIT(PORTA,pin_ID);
			}
			else{
				CLEAR_BIT(PORTA,pin_ID);
			}
			break;
			
			case DIO_PORTB:
			if(DIO_PIN_HIGH==pin_Value){
				SET_BIT(PORTB,pin_ID);
			}
			else{
				CLEAR_BIT(PORTB,pin_ID);
			} break;
			
			case DIO_PORTC:
			if(DIO_PIN_HIGH==pin_Value){
				SET_BIT(PORTC,pin_ID);
			}
			else{
				CLEAR_BIT(PORTC,pin_ID);
			} break;
			
			case DIO_PORTD:
			if(DIO_PIN_HIGH==pin_Value){
				SET_BIT(PORTD,pin_ID);
			}
			else{
				CLEAR_BIT(PORTD,pin_ID);
			} break;
			
			
		}
		
		
		
	}
	else{
		
		//no thing
	}
	
	
}


void DIO_togglepinValue(u8 potr_ID,u8 pin_ID){
	
	if((potr_ID<=3) &&  (pin_ID<=7))
	{
	    switch(potr_ID){
			case DIO_PORTA:
			TOGGLE_BIT(PORTA,pin_ID);
			 break;
		case DIO_PORTB:
		TOGGLE_BIT(PORTB,pin_ID);
		break;
		case DIO_PORTC:
		TOGGLE_BIT(PORTC,pin_ID);
		break;
		case DIO_PORTD:
		TOGGLE_BIT(PORTD,pin_ID);
		break;
	
			
		}
		
		
		
	}
	else{
		//do nothing
	}
	
	
	
}

void  DIO_GETPINVALUE(u8 port_id,u8 pin_ID,u8 *pin_Value){
	if ((port_id<=3) &&  (pin_ID<=7) &&(pin_Value!=NULL)){
		switch(port_id){
		case DIO_PORTA:
	*pin_Value	=GIT_BIT(PINA,pin_ID);
	break;
		case  DIO_PORTB:
		*pin_Value	=GIT_BIT(PINB,pin_ID);
		break;
		case  DIO_PORTC:
		*pin_Value	=GIT_BIT(PINC,pin_ID);
		break;
		case  DIO_PORTD:
		*pin_Value	=GIT_BIT(PIND,pin_ID);
		break;	
			
			
			
			
			
			
			
			
		}
		
		
	}
	
	
	else{
		//do nothing
	}
	
}

void DIO_activeportINpullURresistance(u8 port_ID,u8 pin_ID){
	if ((port_ID<=3) &&  (pin_ID<=7))
	{
		switch(port_ID){
		 case DIO_PORTA:
		  SET_BIT(PORTA,pin_ID);
		  break; 	
			
			 case DIO_PORTB:
			 SET_BIT(PORTB,pin_ID);
			 break;
			  case DIO_PORTC:
			  SET_BIT(PORTC,pin_ID);
			  break;
			  
			   case DIO_PORTD:
			   SET_BIT(PORTD,pin_ID);
			   break;
			
			
			
			
			
			
		}
	}
	
	else{
		//no thing
	}
	
	
	
}