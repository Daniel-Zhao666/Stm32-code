#ifndef __STM32F10X_GPIO_H
#define __STM32F10X_GPIO_H

#include "stm32f10x.h"


//GPIO���ŵĺ궨�� 
#define GPIO_Pin_0      ((uint16_t)0x0001)  //����0
#define GPIO_Pin_1      ((uint16_t)0x0002)  //0000_0000_0000_0010
#define GPIO_Pin_2      ((uint16_t)0x0004)
#define GPIO_Pin_3      ((uint16_t)0x0008)
#define GPIO_Pin_4      ((uint16_t)0x0010)
#define GPIO_Pin_5      ((uint16_t)0x0020)
#define GPIO_Pin_6      ((uint16_t)0x0040)
#define GPIO_Pin_7      ((uint16_t)0x0080)

#define GPIO_Pin_8      ((uint16_t)0x0100)
#define GPIO_Pin_9      ((uint16_t)0x0200)
#define GPIO_Pin_10     ((uint16_t)0x0400)
#define GPIO_Pin_11     ((uint16_t)0x0800)
#define GPIO_Pin_12     ((uint16_t)0x1000)
#define GPIO_Pin_13     ((uint16_t)0x2000)
#define GPIO_Pin_14     ((uint16_t)0x4000)
#define GPIO_Pin_15     ((uint16_t)0x8000)
#define GPIO_Pin_All   ((uint16_t)0xFFFF) //ѡ��ȫ������

typedef struct
{
	//GPIO�ĳ�ʼ��
  uint16_t GPIO_Pin;			//ѡ��Ҫ���õ�GPIO����
  uint16_t GPIO_Speed;		//ѡ��GPIO���ŵ�����
  uint16_t GPIO_Mode;			//ѡ��GPIO�Ĺ���ģʽ

}GPIO_InitTypeDef;

//������ʵ�ö�ٶ���
typedef enum 
{
   GPIO_Speed_10MHz  = 1,
   GPIO_Speed_2MHz,
   GPIO_Speed_50MHz
}GPIO_Speed_TypeDef;
  
//GPIO����ģʽö�ٶ���
typedef enum
{
   GPIO_Mode_AIN = 0x0,							//ģ������
   GPIO_Mode_IN_FLOATING =  0x4, 		//�������롢
	 GPIO_Mode_IPD = 0x28,						//��������
	 GPIO_Mode_IPU = 0x48,						//��������
	
	 GPIO_Mode_Out_OD  = 0x14, 				//��©���
   GPIO_Mode_Out_PP  = 0x10, 				//�������
	 GPIO_Mode_AF_OD   = 0x1C,				//���ÿ�©���
	 GPIO_Mode_AF_PP   = 0x18					//�����������
}GPIOMode_TypeDef;

void GPIO_SetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_ReSetBits(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void GPIO_Init(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_InitStruct);

#endif /* __STM32F10X_H */

