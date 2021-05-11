//bsp -- board support package(支持开发板的包)
//每新建一个文件（包含头文件），都应该关联头文件的路径

#include "bsp_led.h"

  
//GPIO的配置模块
void LED_GPIO_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;//初始化GPIO结构体
  RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);//开时钟，使能
 
  GPIO_InitStruct.GPIO_Pin   = LED_G_GPIO_PIN;  //设置引脚
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//设置输出模式为推挽
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//设置输出速率
	
  GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);

}
