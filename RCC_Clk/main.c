
#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_rcc_configue.h"

void Delay(uint32_t count)
{
   for(; count != 0; count--);
}
	

int main(void)
{
	//��ʱ��ϵͳʱ���Ѿ�������Ϊ72M
	 HSI_SetSysClk(RCC_PLLMul_16);
	 MCO_GPIO_Config();//����MCO��Ӧ��GPIO
	 //RCC_MCOConfig(RCC_MCO_SYSCLK);//����RCC��Ӧ��MCO(��ϵͳʱ����Ϊ�βΣ���stm32f10x_rcc.c��1275��)
	
	 //RCC_MCOConfig(RCC_MCO_HSE);//�۲�HSE��Ϊ����ʱ��Ч��
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



