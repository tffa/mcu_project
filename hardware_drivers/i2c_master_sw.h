#ifndef _I2C_MASTER_SW_H_
#define _I2C_MASTER_SW_H_

extern void i2c_master_sw_init(void);
extern tffa_bool i2c_master_sw_read(tffa_uint8 device_address,
										tffa_uint8 register_address,
										tffa_uint8 data_length,
										tffa_uint8* pdata);
extern tffa_bool i2c_master_sw_write(tffa_uint8 device_address,
										tffa_uint8 register_address,
										tffa_uint8 data_length,
										tffa_uint8* pdata);

#endif//_I2C_MASTER_SW_H_

