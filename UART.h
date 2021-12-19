/*
 * UART.h
 *
 * Created: 13/11/2019 10:17:11 م
 *  Author: mohamed khaled
 */ 


#ifndef UART_H_
#define UART_H_
#include <avr/io.h>
#include <avr/interrupt.h>
//CONFIGRATION 

#define UART_BAUDRATE 1200ul 
#define	UART_FOSC 1000000ul 

enum uart_sync_mode {
	    UART_ASYNC = 0,
		UART_SYNC = (1<<6)
}; 

enum uart_speed_mode { 
	 
	UART_NORMAL_SPEED , 
	UART_DOBULE_SPEED  
};  

enum uart_transmit {
	  
	UART_TRANSMIT_DISABLE , 
	UART_TRANSMIT_ENABLE  
}; 

enum uart_recieve {
	
	UART_RECIEVE_DISABLE , 
	UART_RECIEVE_ENABLE 
}; 

enum char_size {
	UART_5_BIT_CHAR = (0b00<<1), 
	UART_6_BIT_CHAR = (0b01<<1),
 	UART_7_BIT_CHAR = (0b10<<1),
	UART_8_BIT_CHAR = (0b11<<1) , 
	UART_9_BIT_CHAR = (0b111<<1)
}; 

enum party_mode {
	PART_MODE_DISABLE = (0b00<<4),
	PARTY_ENEN_MODE = (0b10<<4), 
	PART_ODD_MODE = (0b11<<4)  
};

enum uart_stop_bit{
	UART_1_STOP_BIT = (0<<3), 
	UART_2_STOP_BIT = (1<<3)
};

enum uart_transmit_int {
 UART_TRANSMIT_INT_ENABLE = (1<<6),
 UART_TRANSMIT_INT_DISABLE = (0<<6)
}; 

enum uart_recieve_int {
 UART_RECIEVE_INT_ENABLE = (1<<7),
 UART_RECIEVE_INT_DISABLE = (0<<7)
};

 struct UART_CONFIG {
	 enum uart_sync_mode SYNC_MODE; 
	 enum uart_speed_mode SPEED_MODE;
	 enum uart_transmit TRANSMIT;
	 enum uart_recieve RECIEVE ; 
	 enum char_size CHAR_SIZE;
	 enum party_mode PARTY_MODE;
	 enum uart_stop_bit STOP_BIT;
	 enum uart_transmit_int TARNSMIT_INT;
	 enum uart_recieve_int RECIVE_INT;
 }; 
 //-------------------------------------------------------------------------------------------------------// 
 //APIS
   void UART_INIT (struct UART_CONFIG CONFIG); 
   void UART_TRANSMIT (unsigned short data);  
  unsigned char UART_RECIEVE (unsigned short *PTR_TO_VAL); 
 
 


#endif /* UART_H_ */