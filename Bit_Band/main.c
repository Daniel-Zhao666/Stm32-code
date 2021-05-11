#include "stm32f10x.h"
#include "bsp_led.h"
#include "bsp_key.h"

#define GPIOB_ODR_Addr  (GPIOB_BASE + 0X0C)
#define PBout(n)   *(unsigned int*)((GPIOB_ODR_Addr & 0xF0000000) + 0x02000000 + ((GPIOB_ODR_Addr & 0x00FFFFFF) << 5) + (n<<2))

#define GPIOA_IDR_Addr  (GPIOA_BASE + 0X08)
#define PAin(n)   *(unsigned int*)((GPIOA_IDR_Addr & 0xF0000000) + 0x02000000 + ((GPIOA_IDR_Addr & 0x00FFFFFF) << 5) + (n<<2))

#define GPIOC_IDR_Addr  (GPIOC_BASE + 0X08)
#define PCin(n)   *(unsigned int*)((GPIOC_IDR_Addr & 0xF0000000) + 0x02000000 + ((GPIOC_IDR_Addr & 0x00FFFFFF) << 5) + (n<<2))


void Delay(uint32_t count)
{
  for(; count!=0; count--);
}

//λ������ʵ��ODR�Ĵ������ƶ˿�
int main(void)
{
	//�������
	LED_GPIO_Config();
	KEY_GPIO_Config();
#if 0	
	while(1)
	{
	 //GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	 //LED_G(ON);
	 PBout(0) = 1;
	 Delay(0xFFFFF);
	
	 //GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
	 //LED_G(OFF);
	 PBout(0) = 0;	
	 Delay(0xFFFFF);
	}
#else	
	//�������
	while(1)
	{
		//�Ƶ�ѭ�����𣨰��������£�
		//����PA0���� 
	  if(PAin(0) == KEY_ON)
		{
			 while(PAin(0) == KEY_ON);
		   LED_G_TOGGLE;
		}
		//����PC13����
		if(PCin(13) == KEY_ON)
		{
       while(PCin(13) == KEY_ON);
       LED_G_TOGGLE;				 
		}
	}
#endif
}
