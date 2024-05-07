/*
 * usart0.h
 *
 * Created: 23.02.2023 14:16:59
 *  Author: Jack
 */ 


#ifndef USART0_H_
#define USART0_H_

#include <stdint.h>

void usart0_init(void);
void usart0_char(void* p, uint8_t byte);

#endif /* USART0_H_ */