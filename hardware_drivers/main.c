#include "global.h"

void cpu_init(void)
{
}

#if (_MAIN_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	uart_init();
	i2c_init();	
	timer_init();
	watch_dog_init();

	ENABLE_GLOBAL_INTERRUPT();

	while(1)
	{
	}
}
#endif

