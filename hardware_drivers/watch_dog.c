#include "global.h"

void watch_dog_init(void)
{
}

#if (_WATCH_DOG_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	timer_init();
	watch_dog_init();

	ENABLE_GLOBAL_INTERRUPT();

	while(1)
	{
	}
}
#endif//_WATCH_DOG_DEBUG_

