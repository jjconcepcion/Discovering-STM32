#include <stm32f10x.h>
#include <stm32f10x_usart.h>
#include "uart.h"

void Delay(uint32_t nTime);

int main(void) {
	static const uint32_t baud = 9600;
	static const uint32_t flags = 0;
	static const char message[] = "Hello World!\n\r";
	static uint8_t i;

	// Configure the UART	
	uart_open(USART1, baud, flags);

	// Configure SysTick Timer
	if (SysTick_Config(SystemCoreClock / 1000))
		while (1);

	while (1) {
		// transmit hello world message
		for (i = 0; message[i]; i++)
			uart_putc(message[i], USART1);
				
		Delay(250);	// wait 250 ms
	}
	
	return 0;
}

// Timer code
static __IO uint32_t TimingDelay ;

void Delay(uint32_t nTime)
{
	TimingDelay = nTime ;
	while (TimingDelay != 0);
}

void SysTick_Handler(void)
{
	if (TimingDelay != 0x00)
	TimingDelay --;
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
/* Infinite loop */
/* Use GDB to find out why we're here */
while (1);
}
#endif
