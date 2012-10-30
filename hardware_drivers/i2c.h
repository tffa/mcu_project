#ifndef _I2C_H_
#define _I2C_H_

/*
* I2C bus control
*/
#define I2C_SET_I2C_CLK_OUTPUT		//
#define I2C_SET_I2C_CLK_INPUT		//
#define I2C_SET_I2C_DATA_OUTPUT	//
#define I2C_SET_I2C_DATA_INPUT		//
#define I2C_SET_I2C_CLK_HIGH		//
#define I2C_SET_I2C_CLK_LOW			//
#define I2C_SET_I2C_DATA_HIGH		//
#define I2C_SET_I2C_DATA_LOW		//
#define I2C_GET_I2C_DATA_BIT			//

#define DELAY_LOOP_START_SETUP 2
#define DELAY_LOOP_START_HOLD 2
#define DELAY_LOOP_SCL_LOW 2
#define DELAY_LOOP_SCL_HIGH 2
#define DELAY_LOOP_DATA_HOLD 2
#define DELAY_LOOP_DATA_SETUP 2
#define DELAY_LOOP_STOP_SETUP 2
#define DELAY_LOOP_BUS_FREE 2

/*
* macro function for i2c delay
*/
#define i2c_delay_loop(loop)	\
{	\
	volatile tffa_uint8 i;	\
	for (i=0; i<(loop); i++);	\
}

/*
* macro function for i2c start/restart
*/
#define i2c_start()	\
{	\
	I2C_SET_I2C_DATA_OUTPUT;	\
	I2C_SET_I2C_CLK_OUTPUT; 	\
	I2C_SET_I2C_DATA_HIGH;		\
	I2C_SET_I2C_CLK_HIGH;		\
	i2c_delay_loop(DELAY_LOOP_START_SETUP);	\
	I2C_SET_I2C_DATA_LOW;	\
	i2c_delay_loop(DELAY_LOOP_START_HOLD);	\
	I2C_SET_I2C_CLK_LOW;	\
}

/*
* macro function for i2c write
*/
#define i2c_write(data)	\
{	\
	tffa_int8 i;	\
	I2C_SET_I2C_DATA_OUTPUT;	\
	I2C_SET_I2C_CLK_LOW;	\
	for (i=7;i>=0;i--)	\
	{	\
		i2c_delay_loop(DELAY_LOOP_DATA_HOLD);		\
		if ((data) & (1<<i))	\
		{	\
			I2C_SET_I2C_DATA_HIGH;	\
		}	\
		else	\
		{	\
			I2C_SET_I2C_DATA_LOW;	\
		}	\
		i2c_delay_loop(DELAY_LOOP_DATA_SETUP);		\
		I2C_SET_I2C_CLK_HIGH;	\
		i2c_delay_loop(DELAY_LOOP_SCL_HIGH);		\
		I2C_SET_I2C_CLK_LOW;	\
	}	\
}

/*
* macro function for i2c read
*/
#define i2c_read(data)	\
{	\
	tffa_int8 i;	\
	(data) = 0;	\
	I2C_SET_I2C_CLK_LOW;	\
	I2C_SET_I2C_DATA_INPUT;	\
	for (i=7;i>=0;i--)	\
	{	\
		i2c_delay_loop(DELAY_LOOP_SCL_LOW);		\
		I2C_SET_I2C_CLK_HIGH;	\
		i2c_delay_loop(DELAY_LOOP_SCL_HIGH);		\
		if (I2C_GET_I2C_DATA_BIT)	\
		{	\
			(data) |= (1<<i);	\
		}	\
		I2C_SET_I2C_CLK_LOW;	\
	}	\
}

/*
* macro function for i2c slave acknowledge
*/
#define i2c_slave_ack(ack)	\
{	\
	I2C_SET_I2C_CLK_LOW;	\
	I2C_SET_I2C_DATA_INPUT;	\
	i2c_delay_loop(DELAY_LOOP_SCL_LOW);		\
	I2C_SET_I2C_CLK_HIGH;	\
	i2c_delay_loop(DELAY_LOOP_SCL_HIGH);		\
	(ack) = I2C_GET_I2C_DATA_BIT;	\
	I2C_SET_I2C_CLK_LOW;	\
}

/*
* macro function for master acknowledge
*/
#define i2c_master_ack()	\
{	\
	I2C_SET_I2C_CLK_LOW;	\
	I2C_SET_I2C_DATA_OUTPUT;	\
	i2c_delay_loop(DELAY_LOOP_DATA_HOLD);		\
	I2C_SET_I2C_DATA_LOW;	\
	i2c_delay_loop(DELAY_LOOP_DATA_SETUP);		\
	I2C_SET_I2C_CLK_HIGH;	\
	i2c_delay_loop(DELAY_LOOP_SCL_HIGH);		\
	I2C_SET_I2C_CLK_LOW;	\
}

/*
* macro function for master nacknowledge
*/
#define i2c_master_nack()	\
{	\
	I2C_SET_I2C_CLK_LOW;	\
	I2C_SET_I2C_DATA_OUTPUT;	\
	i2c_delay_loop(DELAY_LOOP_DATA_HOLD);		\
	I2C_SET_I2C_DATA_HIGH;	\
	i2c_delay_loop(DELAY_LOOP_DATA_SETUP);		\
	I2C_SET_I2C_CLK_HIGH;	\
	i2c_delay_loop(DELAY_LOOP_SCL_HIGH);		\
	I2C_SET_I2C_CLK_LOW;	\
}


/*
* macro function for i2c stop
*/
#define i2c_stop()	\
{	\
	I2C_SET_I2C_CLK_LOW;	\
	I2C_SET_I2C_DATA_OUTPUT;	\
	I2C_SET_I2C_DATA_LOW;	\
	i2c_delay_loop(DELAY_LOOP_SCL_LOW);		\
	I2C_SET_I2C_CLK_HIGH;	\
	i2c_delay_loop(DELAY_LOOP_STOP_SETUP);		\
	I2C_SET_I2C_DATA_HIGH;	\
}

extern void i2c_init(void);

#endif//_I2C_H_

