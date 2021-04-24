#include "stm32f10x.h"//编译器在当前工程目录下没有，那么转到安装根目录寻找


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
	#else
	
	//打开GPIOB端口的时钟
	RCC_APB2ENR |= (1 << 3);
	
	//清空PB0端口位
	GPIOB_CRL &= ~( 0x0F << (4 * 0)); 
	
	//配置PB0为通用推挽输出，速度为10M
	GPIOB_CRL |= (1 << 4 * 0);
	
	//PB0输出低电平
	GPIOB_ODR &= ~(1<< 0);
	
	#endif
}


void SystemInit(void)
{
 //函数体为空，目的是为跳过编译器不报错
}
