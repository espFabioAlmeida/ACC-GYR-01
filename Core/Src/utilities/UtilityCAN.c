///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityCAN
//AUTOR:      Fábio Almeida
//CRIADO:     04/08/2023
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES
==============================================================================*/
const uint32_t ACC_GYRO_ADDRESS = 0x06F8A776;
/*==============================================================================
RECEBE PACOTE CAN
==============================================================================*/
void recebePacoteCAN() {
	if(flagPacoteCAN) { //Não há dados a serem recebidos
		flagPacoteCAN = false;
		flagLedCOM = true;
	}
}
/*==============================================================================
ENVIA PACOTE CAN
==============================================================================*/
void enviaPacoteCAN() {
	uint8_t dado = 0;
	canTxHeader.ExtId = ACC_GYRO_ADDRESS + flagEndereco1;
	canTxHeader.RTR = CAN_RTR_DATA;
	canTxHeader.IDE = CAN_ID_EXT;
	canTxHeader.DLC = 8;
	canTxHeader.TransmitGlobalTime = DISABLE;

	dado = bitWrite(dado, 0, mpu6050Data.accXNegativo);
	dado = bitWrite(dado, 1, mpu6050Data.accYNegativo);
	dado = bitWrite(dado, 2, mpu6050Data.accZNegativo);
	dado = bitWrite(dado, 3, mpu6050Data.gyroXNegativo);
	dado = bitWrite(dado, 4, mpu6050Data.gyroYNegativo);
	dado = bitWrite(dado, 5, mpu6050Data.gyroZNegativo);

	canTxBuffer[0] = mpu6050Data.accX;
	canTxBuffer[1] = mpu6050Data.accY;
	canTxBuffer[2] = mpu6050Data.accZ;
	canTxBuffer[3] = mpu6050Data.gyroX;
	canTxBuffer[4] = mpu6050Data.gyroY;
	canTxBuffer[5] = mpu6050Data.gyroZ;
	canTxBuffer[6] = dado;
	canTxBuffer[7] = 0x00;

	if(HAL_CAN_AddTxMessage(&hcan, &canTxHeader, canTxBuffer, &canTxMailbox) != HAL_OK) {
	    Error_Handler();
	}

	while(HAL_CAN_GetTxMailboxesFreeLevel(&hcan) != 3) {
		//Aguarda fim da transmissão
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
