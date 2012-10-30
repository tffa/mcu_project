#ifndef _UART_H_
#define _UART_H_

enum
{
	UART_PORT0 = 0,
	UART_PORT1 = 1,
	UART_PORT_ERROR
};

enum
{
	UART_BAUDRATE_9600 = 0,
	UART_BAUDRATE_115200 = 1,
	UART_BAUDRATE_ERROR
};

extern void uart_init(void);

#endif//_UART_H_

