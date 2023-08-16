
#include "gpio.h"
#include "i2c.h"

#define WHO_I_AM 0x75
#define PWR_MGMT_1 0x6B
#define SMPRT_DIV 0x19
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40

#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48

#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42

// With AD0 set to 0
#define MPU6050_ADDR 0x68

typedef struct{
	int16_t raw_accel[3];
	int16_t raw_gyro[3];

	float accel[3];
	float gyro[3];
} MPU6050_DATA;


uint8_t MPU6050_Init(I2C_HandleTypeDef* i2c);
uint8_t MPU6050_ReadRawData(I2C_HandleTypeDef* i2c, MPU6050_DATA* data);
uint8_t MPU6050_ReadData(I2C_HandleTypeDef* i2c, MPU6050_DATA* data);
