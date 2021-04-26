#include "stm32f10x.h"//�������ڵ�ǰ����Ŀ¼��û�У���ôת����װ��Ŀ¼Ѱ��
#include "stm32f10x_gpio.h"

#define LED_G_GPIO_PORT          GPIOB
#define LED_G_GPIO_CLK_ENABLE    (RCC-> APB2ENR  |= ((1) << 3))   
#define LED_G_GPIO_PIN         	 GPIO_Pin_0

int main(void)
{
	//����LED��
	
	#if 0
	//��GPIOB�˿ڵ�ʱ��
	*(unsigned int *)0x40021018  |= (1 << 3);
	
	//����IO�����
	*(unsigned int *)0x40010c00  &= ~(0xF << (4*0));
  *(unsigned int *)0x40010C00  |= ( 1 << (4*0));//�˿�����ǰ��Ҫ�������ʹ��
	
	//����ODR�Ĵ���
	(unsigned int *)0x40010C0C &= ~(1 << 0);
	
	#elif 0
	
	//��GPIOB�˿ڵ�ʱ��
	RCC_APB2ENR |= (1 << 3);
	
	//���PB0�˿�λ
	GPIOB_CRL &= ~( 0x0F << (4 * 0)); 
	
	//����PB0Ϊͨ������������ٶ�Ϊ10M
	GPIOB_CRL |= (1 << 4 * 0);
	
	//PB0����͵�ƽ
	//GPIOB_ODR &= ~(1<< 0);
	
	#elif 1 
	
		//��GPIOB�˿ڵ�ʱ��
	RCC->APB2ENR |= (1 << 3);
	
	//���PB0�˿�λ
	GPIOB -> CRL &= ~( 0x0F << (4 * 0)); 
	
	//����PB0Ϊͨ������������ٶ�Ϊ10M
	GPIOB -> CRL |= (1 << 4 * 0);
	
	//PB0����͵�ƽ
	GPIOB -> ODR &= ~(1<< 0);
	//GPIOB -> ODR |= (1 << 0);
	
	
	#elif 1
	
	GPIO_InitTypeDef GPIO_InitStructure;//����ֲ�����Ӧ��������֮���ȶ����ʹ��
	
	//��GPIOB�˿ڵ�ʱ��
	//RCC->APB2ENR |= (1 << 3);
	
	LED_G_GPIO_CLK_ENABLE;
	
	GPIO_InitStructure.GPIO_Pin   =  LED_G_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//���PB0�˿�λ
	//GPIOB -> CRL &= ~( 0x0F << (4 * 0)); 
	
	//����PB0Ϊͨ������������ٶ�Ϊ10M
	//GPIOB -> CRL |= (1 << 4 * 0);
	
 GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
 GPIO_ResetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
 
 while(1)
 {
    GPIO_SetBits(LED_G_GPIO_PORT, LED_G_GPIO_PIN);
    Delay(0xFFFF);
	  GPIO_ResetBits(LED_G_GPIO_PORT, LEN_G_GPIO_PIN);
    Delay(0xFFFF);
 }
	#endif
}



void SystemInit(void)
{
 //������Ϊ�գ�Ŀ����Ϊ����������������
}
