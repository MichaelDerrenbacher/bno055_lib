/*
 * i2c.c
 *
 *  Created on: Sep 28, 2024
 *      Author: dbac
 */

#include "i2c.h"

I2C_HandleTypeDef hi2c1;


/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
void MX_I2C1_Init(void)
{
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
	  while (1)
	  {
	  }
  }
}

void I2C_READ(uint8_t dev_id, uint8_t addr, uint8_t* data) {
	HAL_I2C_Mem_Read(&hi2c1, dev_id, addr, I2C_MEMADD_SIZE_8BIT, data, 0x01, HAL_MAX_DELAY);
}

void I2C_WRITE(uint8_t dev_id, uint8_t addr, uint8_t* data) {
	HAL_I2C_Mem_Write(&hi2c1, dev_id, addr, I2C_MEMADD_SIZE_8BIT, data, 0x01, HAL_MAX_DELAY);
}
