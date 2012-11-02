#include "global.h"

#define I2C_MODULE_HARDWARE
//#define I2C_MODULE_SOFTWARE

void i2c_init(void)
{
#if (defined (I2C_MODULE_HARDWARE))
	i2c_master_hw_init();
#elif (defined (I2C_MODULE_SOFTWARE))
	i2c_master_sw_init();
#endif
}

tffa_bool i2c_read(tffa_uint8 device_address,
					tffa_uint8 register_address,
					tffa_uint8 data_length,
					tffa_uint8* pdata)
{
	tffa_bool ret = TFFA_FALSE;

#if (defined (I2C_MODULE_HARDWARE))
	ret = i2c_master_hw_read(device_address,register_address,data_length,pdata);
#elif (defined (I2C_MODULE_SOFTWARE))
	ret = i2c_master_sw_read(device_address,register_address,data_length,pdata);
#endif

	return ret;
}

tffa_bool i2c_write(tffa_uint8 device_address,
					tffa_uint8 register_address,
					tffa_uint8 data_length,
					tffa_uint8* pdata)
{
	tffa_bool ret = TFFA_FALSE;

#if (defined (I2C_MODULE_HARDWARE))
	ret = i2c_master_hw_write(device_address,register_address,data_length,pdata);
#elif (defined (I2C_MODULE_SOFTWARE))
	ret = i2c_master_sw_write(device_address,register_address,data_length,pdata);
#endif

	return ret;
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

