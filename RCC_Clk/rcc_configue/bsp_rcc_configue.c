#include "bsp_rcc_configue.h"

//void HSE_SetSysClk( uint32_t RCC_PLLMul_x)
//{
//	//Ԥ�ȶ���ȴ�HSE�����ķ���ֵ
//	 ErrorStatus HSEStatus;//����������������������֮��
//	
//	 //��ʼ��RCC -> ��RCC�Ĵ�����λ����
//	 RCC_DeInit();
//	
//	 //ʹ��HSE
//   RCC_HSEConfig(RCC_HSE_ON);//���ⲿ����ʱ�ӣ�stm32f10x_rcc.c��
//	
//	 //�ȴ�HSE����
//   RCC_WaitForHSEStartUp();
//	if(HSEStatus  == SUCCESS)
//	{
//		//ʹ��Ԥȡָ
//	   FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
//		
//		//���õȴ�����Ϊ2
//		 FLASH_SetLatency(FLASH_Latency_2);
//		
//		//����HCLK  72M
//	   RCC_HCLKConfig(RCC_SYSCLK_Div1);
//	//����PCLK1 72M
//   RCC_PCLK1Config(RCC_HCLK_Div1);
//	//����PCLK2 36M
//   RCC_PCLK2Config(RCC_HCLK_Div2);
//
//	//�������໷PLL  HSE -> 72M = HSE * RCC_PLLMul_x 
//   RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul_x);
//	
//	//ʹ��PLL
//	 RCC_PLLCmd(ENABLE);
//	
//	//�ȴ�PLL�ȶ�
//	while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)  == RESET )
//	{
//	}
//		
//		//ѡ��PLLCLK��Ϊϵͳʱ�ӵ���Դ
//		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
//		
//		//�ȴ�PLLCLK�л�Ϊϵͳʱ��
//     while (RCC_GetSYSCLKSource()  != 0x08)
//		 {
//		 }
//		 
//	}
//	else
//	{
//	  /* ���HSE ����ʧ�ܣ��û�������������Ӵ������Ĵ��� */
//	}
//} 


void HSI_SetSysClk( uint32_t RCC_PLLMul_x)
{
	//Ԥ�ȶ���ȴ�HSI�����ķ���ֵ
	 __IO uint32_t HSIStatus = 0;//����������������������֮��(__IOΪ��ֹ���Ż�)
	
	 //��ʼ��RCC -> ��RCC�Ĵ�����λ����
	 RCC_DeInit();
	
	 //ʹ��HSI
   RCC_HSICmd(ENABLE);;//���ڲ�����ʱ�ӣ�stm32f10x_rcc.c��
	
	 //�ȴ�HSI����,HSIû�ж�Ӧ�ĵȴ�����������ֱ�Ӳ������Ӧ�ļĴ���
   HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	if(HSIStatus  == RCC_CR_HSIRDY)
	{
		//ʹ��Ԥȡָ
	   FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
		
		//���õȴ�����Ϊ2
		 FLASH_SetLatency(FLASH_Latency_2);
		
		//����HCLK  72M
	   RCC_HCLKConfig(RCC_SYSCLK_Div1);
		//����PCLK1 72M
     RCC_PCLK1Config(RCC_HCLK_Div1);
		//����PCLK2 36M
     RCC_PCLK2Config(RCC_HCLK_Div2);
  
		//�������໷PLL  HSI -> HSI / 2 
     RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_x);
		
		//ʹ��PLL
		 RCC_PLLCmd(ENABLE);
		
		//�ȴ�PLL�ȶ�
		while(RCC_GetFlagStatus(RCC_FLAG_PLLRDY)  == RESET )
		{
		}
		
		//ѡ��PLLCLK��Ϊϵͳʱ�ӵ���Դ
		 RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		//�ȴ�PLLCLK�л�Ϊϵͳʱ��
     while (RCC_GetSYSCLKSource()  != 0x08)
		 {
		 }
		 
	}
	else
	{
	  /* ���HSI ����ʧ�ܣ��û�������������Ӵ������Ĵ��� */
	}
} 
//����MCO�˿ڣ��Ա�ͨ��ʾ�����۲��Ƿ�Ƶ����ɹ�
void MCO_GPIO_Config()
{
  GPIO_InitTypeDef  GPIO_InitStruct;//��ʼ��GPIO�ṹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);//��ʱ�ӣ�ʹ������A��ָ���ߣ����ӷ���������Ҫȡ����ñ��
 
	GPIO_InitStruct.GPIO_Pin   = GPIO_Pin_8;  //��������ΪPA8
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//�������ģʽΪ����
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//�����������
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);//PA8����Ӧָ����ԭ��ͼ��

}

