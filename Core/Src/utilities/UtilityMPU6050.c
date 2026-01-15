///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityMPU6050
//AUTOR:      Fábio Almeida
//CRIADO:     15/01/2026
//OBSERVAÇÕES:
//SEQUENCIA DE DADOS NA MEMÓRIA:
//ACCX_H ACCX_L ACCY_H ACCY_L ACCZ_H ACCZ_L
//TEMP_H TEMP_L
//GYROX_H GYROX_L GYROY_H GYROY_L GYROZ_H GYROZ_L
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES
==============================================================================*/
#define ENDERECO_MPU	0x68

#define GYRO_FUNDO_ESCALA_250   0b00000000 //dividir por 131
#define GYRO_FUNDO_ESCALA_500   0b00001000 //dividir por 65.6
#define GYRO_FUNDO_ESCALA_1000  0b00010000 //dividir por 32.8
#define GYRO_FUNDO_ESCALA_2000  0b00011000 //dividir por 16.4

#define GYRO_DIVISAO_250		1310
#define GYRO_DIVISAO_500		656
#define GYRO_DIVISAO_1000		328
#define GYRO_DIVISAO_2000		164

#define ACC_FUNDO_ESCALA_2G     0b00000000 //dividir por 16384
#define ACC_FUNDO_ESCALA_4G     0b00001000 //dividir por 8192
#define ACC_FUNDO_ESCALA_8G     0b00010000 //dividir por 4096
#define ACC_FUNDO_ESCALA_16G    0b00011000 //dividir por 2048

#define ACC_DIVISAO_2G			16384
#define ACC_DIVISAO_4G			8192
#define ACC_DIVISAO_8G			4096
#define ACC_DIVISAO_16G			2048
/*==============================================================================
MPU6050 INIT
==============================================================================*/
void mpu6050Init() {
	uint8_t pData[2];
	pData[0] = 0x6B; //endereço config
	pData[1] = 0x00; //configs
	HAL_I2C_Master_Transmit(&hi2c1, ENDERECO_MPU, &pData, 2, 100); //Inicializa módulo
	HAL_Delay(100);

	pData[0] = 0x1B; //endereço config GYRO
	pData[1] = GYRO_FUNDO_ESCALA_2000;
	HAL_I2C_Master_Transmit(&hi2c1, ENDERECO_MPU, &pData, 2, 100); //configura o GYRO
	HAL_Delay(100);


	pData[0] = 0x1C; //endereço config ACC
	pData[1] = ACC_FUNDO_ESCALA_16G;
	HAL_I2C_Master_Transmit(&hi2c1, ENDERECO_MPU, &pData, 2, 100); //configura o ACC
	HAL_Delay(100);
}
/*==============================================================================
LEITURA MPU6050
==============================================================================*/
void leituraMpu6050Init() {
	uint8_t pData;
	uint8_t bufferRx[14];

	pData = 0x3B; //endereço gyro
	HAL_I2C_Master_Transmit(&hi2c1, ENDERECO_MPU, &pData, 1, 100); //Posiciona o endereço
	HAL_Delay(10);

	HAL_I2C_Master_Receive(&hi2c1, ENDERECO_MPU, &bufferRx, 14, 100); //Busca todos os dados

	mpu6050Data.accX = make16(bufferRx[0], bufferRx[1]);
	mpu6050Data.accY = make16(bufferRx[2], bufferRx[3]);
	mpu6050Data.accZ = make16(bufferRx[4], bufferRx[5]);
	// dado 6 e 7 são a temperatura, ignorados
	mpu6050Data.gyroX = make16(bufferRx[8], bufferRx[9]);
	mpu6050Data.gyroY = make16(bufferRx[10], bufferRx[11]);
	mpu6050Data.gyroZ = make16(bufferRx[12], bufferRx[13]);

	mpu6050Data.accX *= 100; //desloca duas casas 1.53 = 153
	mpu6050Data.accX /= ACC_DIVISAO_16G;
	mpu6050Data.accY *= 100;
	mpu6050Data.accY /= ACC_DIVISAO_16G;
	mpu6050Data.accZ *= 100;
	mpu6050Data.accZ /= ACC_DIVISAO_16G;

	mpu6050Data.gyroX /= GYRO_DIVISAO_2000; //Dessa forma fica 10x menor
	mpu6050Data.gyroY /= GYRO_DIVISAO_2000;
	mpu6050Data.gyroZ /= GYRO_DIVISAO_2000;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
