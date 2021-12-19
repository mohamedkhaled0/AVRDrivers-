/*
 * TIMER.h
 *
 * Created: 10/09/2019 07:41:58 م
 *  Author: mohamed khaled
 */ 

#include "DataType.h"

#ifndef TIMER_H_
#define TIMER_H_

enum Wave_Form_gen {
	ctc , normal
	};
enum TOVFIE0{
	TOVFIE0_Enable , TOVFIE0_Disable
	};

enum OCMIE{
	OCMIE_Enable , OCMIE_Disable
	};
	
	
enum Timer0_Prescaler {
	NO_CLK_SRC = 0, //Timer Disable
	NO_PRESCALING = 1,
	PRESCALING_CLK8 = 2,
	PRESCALING_CLK64 = 3,
	PRESCALING_CLK256 = 4,
	PRESCALING_CLK1024 = 5,
	EXT_CLK_FALLING=6,
	EXT_CLK_RISING = 7
	};
	
	struct sTimer0_Setting{
		enum TOVFIE0 Timer_Ovfi;
		enum OCMIE Timer_Ocie ; 
		enum Wave_Form_gen Timer_Mode;
		enum Timer0_Prescaler Timer0_PRESCALER;  
	};
		
		
		//EXT INT ISR
	//	#define ISR(vector, ...) \
	//	void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
	//	void vector(void) 
	
		
		
	//TMR0 Registers
		
	#define TCCR0 *((vu8*)(0x45))
	#define TCNT0 *((vu8*)(0x44))
	#define OCR0  *((vu8*)(0x43))
	#define TIMSK *((vu8*)(0x57))
    #define TIFR  *((vu8*)(0x56))
	
	
	//TCCR0 Registers
	#define FOC0 	7
	#define WGM00	6
	#define COM01 	5
	#define COM00	4
	#define WGM01	3
	#define CS02 	2
	#define CS01 	1
	#define CS00 	0
	
	//Enable TMR0 Pin/
	#define TOIE0	0
	#define OCIE0	1
	
	
	
	
	
	//TMR0 FUN
	extern void Timer_Init (struct sTimer0_Setting configration);
	extern void Read_Counter_Value (u8*ptrReadCounter); 
	extern void Set_Compare_Value (u8 value); 
	extern void Set_Counter_Value (u8 value); 


#endif /* TIMER_H_ */