/*
 * uart.h
 *
 * Created: 11.07.2019 22:55:29
 * Author: Alexander Velilyaev
 * Contact: Alexandervelilyaev@gmail.com
 */ 

#ifndef UART_H_
#define UART_H_

#include <avr/io.h>
#define FOSC 16000000 // Clock Speed
#define BAUD 9600
#define MYUBRR FOSC/16/BAUD-1

void USART_Init(unsigned int ubrr);

void USART_Transmit(uint8_t data);

uint8_t USART_Receive(void);

#endif /* UART_H_ */