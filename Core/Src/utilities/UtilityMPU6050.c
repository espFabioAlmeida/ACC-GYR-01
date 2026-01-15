///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityMPU6050
//AUTOR:      Fábio Almeida
//CRIADO:     15/01/2026
//OBSERVAÇÕES:
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
FIM DO ARQUIVO
==============================================================================*/
