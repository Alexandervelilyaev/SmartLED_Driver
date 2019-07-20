/*
 * ws28128b_Led_Driver.c
 *
 * Created: 02.07.2019 23:11:23
 * Author: Alexander Velilyaev
 * Contact: Alexandervelilyaev@gmail.com
 */ 

#include "ws2812b.h"
#define N 100

uint8_t red = 0;
uint8_t green = 0;
uint8_t blue = 255;

int main(void)
{
	USART_Init(MYUBRR);
	initLEDs();

	while (1)
	{
		for (uint8_t i = 0; i < N; ++i)
		{
			setColor(red, green, blue);
		}

		flush();

		uint8_t data = USART_Receive();
		if (data == 14)
		{
			USART_Transmit(15);
			red = USART_Receive();
			green = USART_Receive();
			blue = USART_Receive();
		}
	}
}
