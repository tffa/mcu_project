#ifndef _I2C_MASTER_HW_H_
#define _I2C_MASTER_HW_H_

extern void i2c_master_hw_init(void);
extern tffa_bool i2c_master_hw_read(tffa_uint8 device_address,
										tffa_uint8 register_address,
										tffa_uint8 data_length,
										tffa_uint8* pdata);
extern tffa_bool i2c_master_hw_write(tffa_uint8 device_address,
										tffa_uint8 register_address,
										tffa_uint8 data_length,
										tffa_uint8* pdata);

#endif//_I2C_MASTER_HW_H_

