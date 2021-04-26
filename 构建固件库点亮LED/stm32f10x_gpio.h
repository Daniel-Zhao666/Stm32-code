#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"


//GPIO引脚的宏定义 
#define GPIO_Pin_0      ((uint16_t)0x0001)  //引脚0
#define GPIO_Pin_1      ((uint16_t)0x0002)  //0000_0000_0000_0010
#define GPIO_Pin_2      ((uint16_t)0x0004)
#define GPIO_Pin_3      ((uint16_t)0x0008)
#define GPIO_Pin_4      ((uint16_t)0x0010)
#define GPIO_Pin_5      ((uint16_t)0x0020)
#define GPIO_Pin_6      ((uint16_t)0x0040)
#define GPIO_Pin_7      ((uint16_t)0x0080)

#define GPIO_Pin_8      ((uint16_t)0x0100)
#define GPIO_Pin_9      ((uint16_t)0x0200)
#define GPIO_Pin_10     ((uint16_t)0x0400)
#define GPIO_Pin_11     ((uint16_t)0x0800)
#define GPIO_Pin_12     ((uint16_t)0x1000)
#define GPIO_Pin_13     ((uint16_t)0x2000)
#define GPIO_Pin_14     ((uint16_t)0x4000)
#define GPIO_Pin_15     ((uint16_t)0x8000)
#define GPIO_Pin_All   ((uint16_t)0xFFFF) //选择全部引脚

typedef struct
{
	//GPIO的初始化
  uint16_t GPIO_Pin;			//选择要配置的GPIO引脚
  uint16_t GPIO_Speed;		//选择GPIO引脚的速率
  uint16_t GPIO_Mode;			//选择GPIO的工作模式

}GPIO_InitTypeDef;

//输出速率的枚举定义
typedef enum 
{
   GPIO_Speed_10MHz  = 1,
   GPIO_Speed_2MHz,
   GPIO_Speed_50MHz
}GPIO_Speed_TypeDef;
  
//GPIO工作模式枚举定义
typedef enum
{
   GPIO_Mode_AIN = 0x0,							//模拟输入
   GPIO_Mode_IN_FLOATING =  0x4, 		//浮空输入、
	 GPIO_Mode_IPD = 0x28,						//下拉输入
	 GPIO_Mode_IPU = 0x48,						//上拉输入
	
	 GPIO_Mode_Out_OD  = 0x14, 				//开漏输出
   GPIO_Mode_Out_PP  = 0x10, 				//推挽输出
	 GPIO_Mode_AF_OD   = 0x1C,				//复用开漏输出
	 GPIO_Mode_AF_PP   = 0x18					//复用推挽输出
}GPIOMode_TypeDef;

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ReSetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif /* __STM32F10X_H */

