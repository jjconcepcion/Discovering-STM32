#include <stm32f10x.h>
#include <stm32f10x_usart.h>
#include "uart.h"

int main(void) {
	return 0;
}

#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file, uint32_t line)
{
/* Infinite loop */
/* Use GDB to find out why we're here */
while (1);
}
#endif
