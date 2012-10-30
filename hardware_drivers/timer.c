#include "global.h"

static void timera_init(void);
static void timerb_init(void);
static void timerc_init(void);

void timer_init(void)
{
	timera_init();
	timerb_init();
	timerc_init();
}

static void timera_init(void)
{
}

static void timerb_init(void)
{
}

static void timerc_init(void)
{
}

void timera_isr(void)
{
}

void timerb_isr(void)
{
}

void timerc_isr(void)
{
}

#if (_TIMER_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	timer_init();

	ENABLE_GLOBAL_INTERRUPT();

	while(1)
	{
	}
}
#endif//_TIMER_DEBUG_

