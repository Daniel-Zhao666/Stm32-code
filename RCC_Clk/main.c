
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_rcc_configue.h"

void Delay(uint32_t count)
{
   for(; count != 0; count--);
}
	

int main(void)
{
	//此时的系统时钟已经被设置为72M
	 HSI_SetSysClk(RCC_PLLMul_16);
	 MCO_GPIO_Config();//配置MCO对应的GPIO
	 //RCC_MCOConfig(RCC_MCO_SYSCLK);//配置RCC对应的MCO(以系统时钟作为形参：见stm32f10x_rcc.c的1275行)
	
	 //RCC_MCOConfig(RCC_MCO_HSE);//观测HSE作为输入时的效果
   RCC_MCOConfig(RCC_MCO_HSI);
	
	 LED_GPIO_Config();
	
	while(1)
	{
		
	 //GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	 LED_G(ON);
	 Delay(0xFFFFF);
	
	 //GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	 LED_G(OFF);
	 Delay(0xFFFFF);
	}
	 
}



