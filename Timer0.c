/*
 * Timer0.c
 *
 * Created: 27/10/2019 02:28:13 م
 *  Author: mohamed khaled
 */ 


#include "Timer0.h" 

struct sTimer0_Setting Timer0_configration ; 



extern void Timer_Init (struct sTimer0_Setting configration){
	
	configration = Timer0_configration; 
	
	//adjust mode 
	
	if (Timer0_configration.Timer_Mode=ctc)
	{ 
		TCCR0 &= ~(1<<WGM00 ) ; 
	}    TCCR0 |= (1<<WGM01) ;
	
	if (Timer0_configration.Timer_Mode=normal)
	{ 
		TCCR0 &= ~(1<<WGM00 | 1<<WGM01) ; 
	}  
	
	
	//adjust presacler  
	
	TCCR0 |= Timer0_configration.Timer0_PRESCALER ; 
	
	
	//interrupt enable normal mode  
	if (Timer0_configration.Timer_Ovfi == TOVFIE0_Enable)
	{ 
		TIFR |= (1<< TOIE0);
	} 
	else if (Timer0_configration.Timer_Ovfi == TOVFIE0_Disable)
	{ 
		TIFR &= ~(1<< TOIE0);
	} 
	
	//interrupt enable ctc mode  
	if (Timer0_configration.Timer_Ocie == OCMIE_Enable )
	{ 
		TIFR |= (1<< OCIE0);
	} 
	else if (Timer0_configration.Timer_Ocie == OCMIE_Disable )
	{ 
		TIFR &= ~(1<< OCIE0);
	}
	
}  



 extern void Read_Counter_Value (u8*ptrReadCounter) {
	 
	 *ptrReadCounter = TCNT0 ; 
 } 
 extern void Set_Compare_Value (u8 value){ 
	 TCCR0 = value ; 
	 
 } 
 extern void Set_Counter_Value (u8 value){
	 
	 TCNT0 = value ; 
	 
 }