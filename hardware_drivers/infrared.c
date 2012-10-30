#include "global.h"

void infrared_init(void)
{
}

#if (_INFRARED_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	timer_init();

	while(1)
	{
	}
}
#endif//_INFRARED_DEBUG_

