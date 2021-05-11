#ifndef __BSP_RCC_CONFIGUE_H
#define __BSP_RCC_CONFIGUE_H

#include "stm32f10x.h"

void HSE_SetSysClk( uint32_t RCC_PLLMul_x);

void MCO_GPIO_Config(void);//顶层头文件申明必须加上void

void HSI_SetSysClk( uint32_t RCC_PLLMul_x);


#endif  /* __BSP_RCCCONFIGUE_H */

