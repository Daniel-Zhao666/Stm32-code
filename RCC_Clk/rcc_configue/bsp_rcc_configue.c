#include "bsp_rcc_configue.h"

//void HSE_SetSysClk( uint32_t RCC_PLLMul_x)
//{
//	//预先定义等待HSE就绪的返回值
//	 ErrorStatus HSEStatus;//变量申明在主函数大括号之后
//	
//	 //初始化RCC -> 将RCC寄存器复位操作
//	 RCC_DeInit();
//	
//	 //使能HSE
//   RCC_HSEConfig(RCC_HSE_ON);//打开外部高速时钟（stm32f10x_rcc.c）
//	
//	 //等待HSE就绪
//   RCC_WaitForHSEStartUp();
//	if(HSEStatus  == SUCCESS)
//	{
//		//使能预取指
//	   FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
//		
//		//设置等待周期为2
//		 FLASH_SetLatency(FLASH_Latency_2);
//		
//		//设置HCLK  72M
//	   RCC_HCLKConfig(RCC_SYSCLK_Div1);
//	//设置PCLK1 72M
//   RCC_PCLK1Config(RCC_HCLK_Div1);
//	//设置PCLK2 36M
//   RCC_PCLK2Config(RCC_HCLK_Div2);
//
//	//配置锁相环PLL  HSE -> 72M = HSE * RCC_PLLMul_x 
//   RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
//	
//	//使能PLL
//	 RCC_PLLCmd(ENABLE);
//	
//	//等待PLL稳定
//	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)  == RESET )
//	{
//	}
//		
//		//选择PLLCLK作为系统时钟的来源
//		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
//		
//		//等待PLLCLK切换为系统时钟
//     while (RCC_GetSYSCLKSource()  != 0x08)
//		 {
//		 }
//		 
//	}
//	else
//	{
//	  /* 如果HSE 启动失败，用户可以在这里添加处理错误的代码 */
//	}
//} 


void HSI_SetSysClk( uint32_t RCC_PLLMul_x)
{
	//预先定义等待HSI就绪的返回值
	 __IO uint32_t HSIStatus = 0;//变量申明在主函数大括号之后(__IO为防止被优化)
	
	 //初始化RCC -> 将RCC寄存器复位操作
	 RCC_DeInit();
	
	 //使能HSI
   RCC_HSICmd(ENABLE);;//打开内部高速时钟（stm32f10x_rcc.c）
	
	 //等待HSI就绪,HSI没有对应的等待函数，所以直接操作其对应的寄存器
   HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	if(HSIStatus  == RCC_CR_HSIRDY)
	{
		//使能预取指
	   FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		//设置等待周期为2
		 FLASH_SetLatency(FLASH_Latency_2);
		
		//设置HCLK  72M
	   RCC_HCLKConfig(RCC_SYSCLK_Div1);
		//设置PCLK1 72M
     RCC_PCLK1Config(RCC_HCLK_Div1);
		//设置PCLK2 36M
     RCC_PCLK2Config(RCC_HCLK_Div2);
  
		//配置锁相环PLL  HSI -> HSI / 2 
     RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		
		//使能PLL
		 RCC_PLLCmd(ENABLE);
		
		//等待PLL稳定
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)  == RESET )
		{
		}
		
		//选择PLLCLK作为系统时钟的来源
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		//等待PLLCLK切换为系统时钟
     while (RCC_GetSYSCLKSource()  != 0x08)
		 {
		 }
		 
	}
	else
	{
	  /* 如果HSI 启动失败，用户可以在这里添加处理错误的代码 */
	}
} 
//配置MCO端口，以便通过示波器观测是否超频输出成功
void MCO_GPIO_Config()
{
  GPIO_InitTypeDef  GPIO_InitStruct;//初始化GPIO结构体
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//开时钟，使能引脚A（指南者（连接蜂鸣器）需要取下跳帽）
 
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_8;  //设置引脚为PA8
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//设置输出模式为推挽
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//设置输出速率
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);//PA8（对应指南者原理图）

}

