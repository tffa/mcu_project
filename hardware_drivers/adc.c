#include "global.h"

void adc_init(void)
{
}

#if (_ADC_DEBUG_)
void main(void)
{
	cpu_init();
	adc_init();

	while(1)
	{
	}
}
#endif//_ADC_DEBUG_

