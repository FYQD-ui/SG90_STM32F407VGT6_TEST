#ifndef __SG90_H
#define __SG90_H

#include "stm32f4xx_hal.h"

/**
  * @brief  初始化 SG90 舵机模块
  * @param  htim: 定时器句柄（例如：&htim3）
  * @param  channel: PWM 通道（例如：TIM_CHANNEL_1）
  * @retval None
  */
void SG90_Init(TIM_HandleTypeDef *htim, uint32_t channel);

/**
  * @brief  设置舵机转动到指定角度（0~180 度）
  * @param  angle: 目标角度（单位：度）
  * @retval None
  */
void SG90_SetAngle(uint8_t angle);

#endif /* __SG90_H */
