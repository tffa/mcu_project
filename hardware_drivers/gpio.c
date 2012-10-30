#include "global.h"

void gpio_init(void)
{
}

#if (_GPIO_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();

	while(1)
	{
	}
}
#endif//_GPIO_DEBUG_

