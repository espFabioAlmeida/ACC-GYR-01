/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define VERSAO_FIRMWARE 1

enum BOOL {
	false,
	true
};

#define TEMPO_LEITURA_MPU6050 5

typedef struct {
  int32_t accX;
  int32_t accY;
  int32_t accZ;
  int32_t gyroX;
  int32_t gyroY;
  int32_t gyroZ;
} Mpu6050TypeDef;

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;

extern CAN_TxHeaderTypeDef	canTxHeader;
extern CAN_RxHeaderTypeDef	canRxHeader;

extern Mpu6050TypeDef mpu6050Data;

extern uint8_t
	flagPacoteCAN,
	flagLedCOM,

	flagLeituraMpu6050,
	flagEndereco1;

extern uint8_t
	contaTempoLeituraMpu6050;

extern uint32_t
	canTxMailbox;

extern uint8_t
	canTxBuffer[8],
	canRxBuffer[8];

#endif /* INC_GLOBAL_H_ */
