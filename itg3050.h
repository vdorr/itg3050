
//June 12 2012
//This program is given to you without any warranty.
//The author disclaims copyright to this source code.

//based on RM-ITG-3050.pdf
//Document Number: RM-ITG-3050-00
//Revision: 1.1
//Release Date: 05/19/2011

//interface
#define I2C_ADDRESS_0	0x68
#define I2C_ADDRESS_1	0x69

#define WHO_AM_I	0x0
#define X_OFFS_USRH	0x0c
#define X_OFFS_USRL	0x0d
#define Y_OFFS_USRH	0x0e
#define Y_OFFS_USRL	0x0f
#define Z_OFFS_USRH	0x10 
#define Z_OFFS_USRL	0x11
#define FIFO_EN		0x12
#define AUX_VDDIO	0x13
#define AUX_SLV_ADDR	0x14
#define SMPLRT_DIV	0x15
#define DLPF_FS_SYNC	0x16
#define INT_CFG		0x17
#define AUX_ADDR	0x18
#define INT_STATUS	0x1a
#define TEMP_OUT_H	0x1b
#define TEMP_OUT_L	0x1c
#define GYRO_XOUT_H	0x1d
#define GYRO_XOUT_L	0x1e
#define GYRO_YOUT_H	0x1f
#define GYRO_YOUT_L	0x20
#define GYRO_ZOUT_H	0x21
#define GYRO_ZOUT_L	0x22
#define AUX_XOUT_H	0x23
#define AUX_XOUT_L	0x24
#define AUX_YOUT_H	0x25
#define AUX_YOUT_L	0x26
#define AUX_ZOUT_H	0x27
#define AUX_ZOUT_L	0x28
#define FIFO_COUNTH	0x3a
#define FIFO_COUNTL	0x3b
#define FIFO_R		0x3c
#define USER_CTRL	0x3d
#define PWR_MGM		0x3e

//WHO_AM_I
#define I2C_IF_ DIS	7
#define ID_MASK		0x7e
#define ID_POS		1
#define ID_VALUE	0x68

//FIFO_EN
#define TEMP_OUT	7
#define GYRO_XOUT	6
#define GYRO_YOUT	5
#define GYRO_ZOUT	4
#define AUX_XOUT	3
#define AUX_YOUT	2
#define AUX_ZOUT	1
#define FIFO_FOOTER	0

//AUX_VDDIO
#define AUX_VDDIO	2

//AUX_SLV_ADDR
#define CLKOUT_EN	7
#define AUX_ID_MASK	0x7f

//DLPF_FS_SYNC
#define EXT_SYNC_SET2	7
#define EXT_SYNC_SET1	6
#define EXT_SYNC_SET0	5
#define FS_SEL1		4
#define FS_SEL0		3
#define DLPF_CFG2	2
#define DLPF_CFG1	1
#define DLPF_CFG0	0

//INT_CFG
#define ACTL			7
#define OPEN			6
#define LATCH_INT_EN		5
#define INT_ANYRD_2CLEAR	4
#define ITG_RDY_EN		2
#define RAW_RDY_EN		0

//INT_STATUS
#define ITG_RDY		2
#define RAW_DATA_RDY	0

//FIFO_COUNTH
#define FIFO_COUNT_H_MASK	0x03

//USER_CTRL
#define FIFO_ EN	6
#define AUX_IF_EN	5
#define AUX_IF_RST	3
#define FIFO_RST	1
#define GYRO_RST	0

//PWR_MGM
#define H_RESET		7
#define SLEEP		6
#define STBY_XG		5
#define STBY_YG		4
#define STBY_ZG		3
#define CLK_SEL2	2
#define CLK_SEL1	1
#define CLK_SEL0	0



