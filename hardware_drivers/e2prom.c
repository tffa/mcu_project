#include "global.h"

void e2prom_init(void)
{
}

#if (_E2PROM_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	e2prom_init();

	while(1)
	{
	}
}
#endif//_E2PROM_DEBUG_

