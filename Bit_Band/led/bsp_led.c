//bsp -- board support package(֧�ֿ�����İ�)
//ÿ�½�һ���ļ�������ͷ�ļ�������Ӧ�ù���ͷ�ļ���·��

#include "bsp_led.h"

  
//GPIO������ģ��
void LED_GPIO_Config(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;//��ʼ��GPIO�ṹ��
  RCC_APB2PeriphClockCmd(LED_G_GPIO_CLK, ENABLE);//��ʱ�ӣ�ʹ��
 
  GPIO_InitStruct.GPIO_Pin   = LED_G_GPIO_PIN;  //��������
  GPIO_InitStruct.GPIO_Mode  = GPIO_Mode_Out_PP;//�������ģʽΪ����
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;//�����������
	
  GPIO_Init(LED_G_GPIO_PORT, &GPIO_InitStruct);

}
