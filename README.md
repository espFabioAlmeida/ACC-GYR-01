# ACC-GYR-01
Projeto Automasensor: ACC-GYR-01 <br>
# Escopo
Realiza leitura do acelerômetro e do gyroscópio e reporta via CAN. <br>
Possui uma entrada digital para endereçar o equipamento. Dessa forma pode ter 2 na mesma rede CAN. <br>
Há uma entrada digital avulsa. Por hora não possui função. <br>
# Pacote de dados CAN
ID: 0x06F8A776 <br>
<br>
BYTE 1: ACC X <br>
BYTE 2: ACC Y <br>
BYTE 3: ACC Z <br>
BYTE 4: GRYO X <br>
BYTE 5: GYRO Y <br>
BYTE 6: GYRO Z <br>
BYTE 7: SINAIS DADOS <br>
BYTE 8: LIVRE <br>
<br>
Os dados de ACC vão de 0 a 2.55 (255) <br>
Os dados de GYRO vão de 0 a 2550 (255), 1 é equivalente a 10, 100 = 1000. <br>
SINAIS DADOS: 1 valor do dado é negativo, e 0 positivo. <br>
BIT 0: ACC X <br>
BIT 1: ACC Y <br>
BIT 2: ACC Z <br>
BIT 3: GYRO X <br>
BIT 4: GYRO Y <br>
BIT 5: GYRO Z <br>
BIT 6: LIVRE <br>
BIT 7: LIVRE <br>
