#include "global.h"

void i2c_init(void)
{
}

#if (_I2C_DEBUG_)
void main(void)
{
	cpu_init();
	gpio_init();
	i2c_init();

	while(1)
	{
	}
}
#endif//_I2C_DEBUG_

