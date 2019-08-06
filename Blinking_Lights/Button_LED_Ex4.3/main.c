#include <stm32f10x.h>

int main(void)
{
	// enable clocks for port A and C
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	// configure LED (PC8) as general purpose output push-pull, 2MHz speed
	GPIOC->CRH &= ~GPIO_CRH_CNF8_1;
	GPIOC->CRH &= ~GPIO_CRH_CNF8_0;
	GPIOC->CRH |= GPIO_CRH_MODE8_1;
	GPIOC->CRH &= ~GPIO_CRH_MODE8_0;
	// configure User button (PA0) as input floating, 2MHz speed
	GPIOA->CRL &= ~GPIO_CRL_CNF0_1;
	GPIOA->CRL |= ~GPIO_CRL_CNF0_0;
	GPIOA->CRL |= GPIO_CRL_MODE0_1;
	GPIOA->CRL &= ~GPIO_CRL_MODE0_0;
	
	while (1) {
		// read button
		if (GPIOA->IDR & GPIO_IDR_IDR0)
			// led on
			GPIOC->ODR |= GPIO_ODR_ODR8;
		else
			// led off
			GPIOC->ODR &= ~GPIO_ODR_ODR8;
	}

	return 0;
}
