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

typedef struct {
  uint32_t accX;
  uint32_t accY;
  uint32_t accZ;
  uint32_t gyroX;
  uint32_t gyroY;
  uint32_t gyroZ;
} Mpu6050TypeDef;

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;

extern CAN_TxHeaderTypeDef	canTxHeader;
extern CAN_RxHeaderTypeDef	canRxHeader;

extern Mpu6050TypeDef mpu6050Data;

extern uint8_t
	flagPacoteCAN,

	flagLedCOM;

extern uint32_t
	canTxMailbox;

extern uint8_t
	canTxBuffer[8],
	canRxBuffer[8];

#endif /* INC_GLOBAL_H_ */
