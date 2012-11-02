#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include "data_types.h"
#include "gpio.h"
#include "timer.h"
#include "uart.h"
#include "i2c.h"
#include "i2c_master_hw.h"
#include "i2c_master_sw.h"
#include "i2c_slave.h"
#include "infrared.h"
#include "e2prom.h"
#include "ds18b20.h"
#include "adc.h"
#include "spi.h"
#include "watch_dog.h"

#define SOFTWARE_VERSION_MAJOR (0)
#define SOFTWARE_VERSION_MIDDLE (0)
#define SOFTWARE_VERSION_MINOR (0)

#define ENABLE_GLOBAL_INTERRUPT()
#define DISABLE_GLOBAL_INTERRUPT()

#define _TIMER_DEBUG_ (0)
#define _UART_DEBUG_ (0)
#define _GPIO_DEBUG_ (0)
#define _INFRARED_DEBUG_ (0)
#define _ADC_DEBUG_ (0)
#define _E2PROM_DEBUG_ (0)
#define _SPI_DEBUG_ (0)
#define _I2C_DEBUG_ (0)
#define _WATCH_DOG_DEBUG_ (0)

#if ((_TIMER_DEBUG_) || \
	(_UART_DEBUG_) || \
	(_GPIO_DEBUG_) || \
	(_INFRARED_DEBUG_) || \
	(_ADC_DEBUG_) || \
	(_E2PROM_DEBUG_) || \
	(_SPI_DEBUG_) || \
	(_I2C_DEBUG_)|| \
	(_WATCH_DOG_DEBUG_))
#define _MAIN_DEBUG_ (0)
#else
#define _MAIN_DEBUG_ (1)
#endif

extern void cpu_init(void);

#endif//_GLOBAL_H_

