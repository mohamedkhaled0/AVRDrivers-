/*
 * SPI.c
 *
 * Created: 18/11/2019 10:19:03 م
 *  Author: mohamed khaled
 */
#include "SPI.h" 
#include <util/delay.h>



void SPI_INIT_MASTER(void){ 
	

	DDRB |= (1<<5)|(1<<4) | (1<<7);
	DDRB &= ~(1<<6);
	
	// Setting clock polarity and clock mode and clock freq
	//SPCR &= ~(1<<CPOL) & ~(1<<CPHA) & ~(1<<SPR0 )  & ~(1<<SPR1);
	
	// MASTER MODE
	SPCR |= (1<<MSTR) | (1<<SPR0);
	// Enable SPI
	SPCR |= (1<<SPE);
	//Enable interrupts
	//SPCR |= (1<<SPIE);

} 


void SPI_INIT_SLAVE(void){
	
	DDRB |= (1<<6);
	DDRB &= ~(1<<4) & ~(1<<5) & ~(1<<7);
	
	// Setting clock polarity and clock mode and clock freq
	//SPCR &= ~(1<<CPOL) & ~(1<<CPHA) & ~(1<<SPR0 )  & ~(1<<SPR1);
	
	SPCR &=~ (1<<MSTR);
	// Enable SPI
	SPCR |= (1<<SPE);
	//Enable Interrupt
	SPCR |= (1<<SPIE);

}




void SPI_SEND_CHAR (unsigned char data){ 
	
	SPDR = data; 
	while (!(SPSR &(1<<SPIF)));  
}
	

unsigned char SPI_RECIEVE_CHAR(void){ 
	
	
	while (!(SPSR &(1<<SPIF))); 
	return SPDR ; 
	
}  




