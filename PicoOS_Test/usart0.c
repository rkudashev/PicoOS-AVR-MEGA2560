/*
 * usart0.c
 *
 * Created: 23.02.2023 14:16:40
 *  Author: Jack
 */ 
#include <avr/io.h>
#include "usart0.h"
#include <stdint.h>

#define F_CPU 16000000UL

#define BAUD 38400

#define UBRR_VALUE ((F_CPU/(16*BAUD))-1)


void usart0_char(void* p, uint8_t byte)
{
	while ( !( UCSR0A & (1<<UDRE0)) );
	UDR0 = byte;
}

void usart0_init(void)
{
	UBRR0H = (UBRR_VALUE>>8);
	UBRR0L = UBRR_VALUE;
	
	UCSR0A = 0x00;
	UCSR0B = (1<<TXEN0);
	UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
}