#include "stm32f10x.h"//编译器在当前工程目录下没有，那么转到安装根目录寻找
#include "stm32f10x_gpio.h"

#define LED_G_GPIO_PORT          GPIOB
#define LED_G_GPIO_CLK_ENABLE    (RCC-> APB2ENR  |= ((1) << 3))   
#define LED_G_GPIO_PIN         	 GPIO_Pin_0

int main(void)
{
	//点亮LED灯
	
	#if 0
	//打开GPIOB端口的时钟
	*(unsigned int *)0x40021018  |= (1 << 3);
	
	//配置IO口输出
	*(unsigned int *)0x40010c00  &= ~(0xF << (4*0));
  *(unsigned int *)0x40010C00  |= ( 1 << (4*0));//端口配置前需要先清零后使用
	
	//配置ODR寄存器
	(unsigned int *)0x40010C0C &= ~(1 << 0);
	
	#elif 0
	
	//打开GPIOB端口的时钟
	RCC_APB2ENR |= (1 << 3);
	
	//清空PB0端口位
	GPIOB_CRL &= ~( 0x0F << (4 * 0)); 
	
	//配置PB0为通用推挽输出，速度为10M
	GPIOB_CRL |= (1 << 4 * 0);
	
	//PB0输出低电平
	//GPIOB_ODR &= ~(1<< 0);
	
	#elif 1 
	
		//打开GPIOB端口的时钟
	RCC->APB2ENR |= (1 << 3);
	
	//清空PB0端口位
	GPIOB -> CRL &= ~( 0x0F << (4 * 0)); 
	
	//配置PB0为通用推挽输出，速度为10M
	GPIOB -> CRL |= (1 << 4 * 0);
	
	//PB0输出低电平
	GPIOB -> ODR &= ~(1<< 0);
	//GPIOB -> ODR |= (1 << 0);
	
	
	#elif 1
	
	GPIO_InitTypeDef GPIO_InitStructure;//定义局部变量应在主函数之后，先定义后使用
	
	//打开GPIOB端口的时钟
	//RCC->APB2ENR |= (1 << 3);
	
	LED_G_GPIO_CLK_ENABLE;
	
	GPIO_InitStructure.GPIO_Pin   =  LED_G_GPIO_PIN;
	GPIO_InitStructure.GPIO_Mode  =  GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed =  GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	//清空PB0端口位
	//GPIOB -> CRL &= ~( 0x0F << (4 * 0)); 
	
	//配置PB0为通用推挽输出，速度为10M
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
 //函数体为空，目的是为跳过编译器不报错
}
