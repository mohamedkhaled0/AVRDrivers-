/*
 * SPI.h
 *
 * Created: 18/11/2019 10:18:49 م
 *  Author: mohamed khaled
 */ 
#include <avr/io.h>

#ifndef SPI_H_
#define SPI_H_

#define CS_High             PORTB |= (1 << SS);
#define CS_Low              PORTB &= ~(1 << SS);

#define SPI_DDR DDRB  
#define SS 4
#define CLK 7
#define MISO 6
#define MOSI 5


//---------------------------------------------------------------------------------------------------------
//APIS
void SPI_INIT_SLAVE(void); 
void SPI_INIT_MASTER(void); 
void SPI_SEND_CHAR (unsigned char data); 
unsigned char SPI_RECIEVE_CHAR(void); 


#endif /* SPI_H_ */