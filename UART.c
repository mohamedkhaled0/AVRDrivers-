/*
 * UART.c
 *
 * Created: 13/11/2019 10:16:52 م
 *  Author: mohamed khaled
 */ 
#include "UART.h" 


 
struct UART_CONFIG GLOBAL_CONFIG ;
extern void UART_INIT (struct UART_CONFIG CONFIG ){
	
	GLOBAL_CONFIG = CONFIG ; 
	unsigned long UBRRVAL ; 
	
	// SETBAUDRATE 
	if ((GLOBAL_CONFIG.SYNC_MODE == UART_ASYNC)&&(GLOBAL_CONFIG.SPEED_MODE == UART_NORMAL_SPEED))
	{
		UBRRVAL = (unsigned long) (UART_FOSC/((16*UART_BAUDRATE)-1)); 
	} 
	else if ((GLOBAL_CONFIG.SYNC_MODE == UART_ASYNC)&&(GLOBAL_CONFIG.SPEED_MODE == UART_DOBULE_SPEED))
	{ 
		UBRRVAL = (unsigned long) (UART_FOSC/((8*UART_BAUDRATE)-1));
	} 
	else if ((GLOBAL_CONFIG.SYNC_MODE == UART_SYNC))
	{
		UBRRVAL = (unsigned long) (UART_FOSC/((2*UART_BAUDRATE)-1)); 
	} 
	UBRRH = (unsigned char) (UBRRVAL>>8); 
	UBRRL = (unsigned char) (UBRRVAL);  
	
	//TransmitEnabele 
	if (GLOBAL_CONFIG.TRANSMIT==UART_TRANSMIT_ENABLE)
	{ 
		UCSRB |=(1<<TXEN); 
	} 
	else if (GLOBAL_CONFIG.TRANSMIT == UART_TRANSMIT_DISABLE)
	{ 
		UCSRB &= ~(1<<TXEN);
	} 
	
	//RecieveEnable 
	if (GLOBAL_CONFIG.RECIEVE==UART_RECIEVE_ENABLE)
	{ 
		UCSRB |=(1<<RXEN); 
	} 
	else if (GLOBAL_CONFIG.TRANSMIT == UART_RECIEVE_DISABLE)
	{ 
		UCSRB &= ~(1<<RXEN);
	} 
	
	//CharSize  
	if (GLOBAL_CONFIG.CHAR_SIZE != UART_9_BIT_CHAR) 
	{   
		 
		 UCSRC |=  ((1<<URSEL)| (GLOBAL_CONFIG.CHAR_SIZE)); 
	} 
	else if (GLOBAL_CONFIG.CHAR_SIZE == UART_9_BIT_CHAR)
	{ 
		UCSRC |=  ((1<<URSEL)| ((GLOBAL_CONFIG.CHAR_SIZE)&0b11)); 
		UCSRB |= (1<<2); 
	} 
	
	//SetSpeedMdoe 
	if (GLOBAL_CONFIG.SYNC_MODE == UART_DOBULE_SPEED)
	{ 
		UCSRA |= (1<<U2X) ; 
	} 
	
	
	//SetPartyMode 
	UCSRC |= (1<<URSEL) | (GLOBAL_CONFIG.PARTY_MODE) ; 
	//SetStopBit 
	UCSRC |= (1<<URSEL) | (GLOBAL_CONFIG.STOP_BIT) ; 
	//SEtMode 
	UCSRC |= (1<<URSEL) | (GLOBAL_CONFIG.SYNC_MODE);  
	//TransmitInt 
	UCSRB |= GLOBAL_CONFIG.TARNSMIT_INT ;
	//RecieveInt 
	UCSRB |= GLOBAL_CONFIG.RECIVE_INT;
	
} 


// UartTransmit
void UART_TRANSMIT (unsigned short data ){ 
	//polling
	while (!(UCSRA & (1<<UDRE))); 
	
	if (GLOBAL_CONFIG.CHAR_SIZE == UART_9_BIT_CHAR )
	{ 
		UCSRB |= ((data>>8) & 1); 
	}
	
		UDR = (unsigned char )data ; 
	
} 
 
 // UartRecieve 
 unsigned char UART_RECIEVE (unsigned short *PTR_TO_VAL){ 
	 if (GLOBAL_CONFIG.CHAR_SIZE == UART_9_BIT_CHAR)
	 { 
		 *PTR_TO_VAL = (((UCSRB>>1)&1)<<8); 
	 }
	  
	  while(!(UCSRA&(1<<RXC))); 
	  
	  *PTR_TO_VAL = UDR ;
 }




