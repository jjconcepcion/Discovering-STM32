#ifndef UART_H
#define UART_H
int uart_open(USART_TypeDef *USARTx, uint32_t baud, uint32_t flags);

int uart_close(USART_TypeDef *USARTx);

int uart_putc(int c, USART_TypeDef *USARTx);

int uart_getc(USART_TypeDef *USARTx);
#endif
