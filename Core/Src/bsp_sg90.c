#include "bsp_sg90.h"

/* 静态变量保存定时器句柄和 PWM 通道 */
static TIM_HandleTypeDef *servo_htim = NULL;
static uint32_t servo_channel = 0;

void SG90_Init(TIM_HandleTypeDef *htim, uint32_t channel)
{
    servo_htim = htim;
    servo_channel = channel;
    /* 启动 PWM 输出 */
    HAL_TIM_PWM_Start(servo_htim, servo_channel);
}

void SG90_SetAngle(uint8_t angle)
{
    if(angle > 180)
    {
        angle = 180;
    }
    /* 
     * 根据舵机控制要求：
     * 0° 对应 0.5ms，180° 对应 2.5ms
     * PWM 周期为 20ms，总计数为 200，每个计数 0.1ms
     * 因此：
     * 0°  -> 5 个计数, 180° -> 25 个计数
     * 计算公式：pulse = 5 + (angle * (25-5)) / 180 = 5 + (angle * 20) / 180
     */
    uint32_t pulse = 5 + ((uint32_t)angle * 20) / 180;
    __HAL_TIM_SET_COMPARE(servo_htim, servo_channel, pulse);
}
