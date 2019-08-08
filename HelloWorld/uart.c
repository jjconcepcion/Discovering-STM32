#include <stm32f10x.h>
#include <stm32f10x_rcc.h>
#include <stm32f10x_gpio.h>
#include <stm32f10x_usart.h>
#include "uart.h"

/* @brief Intializes and configures USART1 perifpherals according to specified
 *			parameters
 */
int uart_open(USART_TypeDef *USARTx, uint32_t baud, uint32_t flags)
{
	GPIO_InitTypeDef GPIO_InitStructure_Tx;
	GPIO_InitTypeDef GPIO_InitStructure_Rx;
	USART_InitTypeDef USART_InitStructure;

	assert_param(IS_USART_123_PERIPH(USARTx));
	assert_param(IS_USART_BAUDRATE(baud));

	if (USARTx == USART1) {
		// enable RCC for components required for utilizing USART1
		RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1 |
								RCC_APB2Periph_AFIO |
								RCC_APB2Periph_GPIOA, ENABLE);

		// Configure USART1_Tx pin
		GPIO_StructInit(&GPIO_InitStructure_Tx);
		GPIO_InitStructure_Tx.GPIO_Pin = GPIO_Pin_9;
		GPIO_InitStructure_Tx.GPIO_Speed = GPIO_Speed_50MHz;
		GPIO_InitStructure_Tx.GPIO_Mode = GPIO_Mode_AF_PP;
		GPIO_Init(GPIOA, &GPIO_InitStructure_Tx);

		// Configure USART1_Rx pin
		GPIO_StructInit(&GPIO_InitStructure_Rx);
		GPIO_InitStructure_Rx.GPIO_Pin = GPIO_Pin_10;
		GPIO_InitStructure_Rx.GPIO_Mode = GPIO_Mode_IN_FLOATING;
		GPIO_Init(GPIOA, &GPIO_InitStructure_Rx);

		// Configure USART
		USART_StructInit(&USART_InitStructure);
		USART_InitStructure.USART_BaudRate = baud;
		USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;
		USART_Init(USART1, &USART_InitStructure);
		USART_Cmd(USART1, ENABLE);
	}

	return 0;
}

int uart_close(USART_TypeDef *USARTx)
{
}

int uart_putc(int c, USART_TypeDef *USARTx)
{
}

int uart_getc(USART_TypeDef *USARTx)
{
}
