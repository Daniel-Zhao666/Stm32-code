#ifndef __STM32F10X_H
#define __STM32F10X_H


//Ƭ���������ַ
#define PERIPH_BASE      ((unsigned int)0x40000000)
#define APB1PERIPH_BASE    PERIPH_BASE

//���߻���ַ�� GPIO������APB2��
#define APB2PERIPH_BASE (PERIPH_BASE + 0X10000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0X20000)

//GPIOB�������ַ
#define GPIOB_BASE   (APB2PERIPH_BASE + 0X0C00)

//RCC�������ַ���������ù���APB2�ϵ������ʱ��
#define RCC_BASE   (AHBPERIPH_BASE + 0X1000)

//RCC��AHB1ʱ��ʹ�ܼĴ�����ַ(ʹ���źţ�����RCC)��ǿ������ת��Ϊָ��
#define RCC_APB2ENR  *(unsigned int*)(RCC_BASE + 0X18)
	
//GPIOB�ļĴ�����ַ��ǿ������ת��Ϊָ��
//#define GPIOB_CRL   *(unsigned int*)(GPIOB_BASE + 0X00)
//#define GPIOB_CRH   *(unsigned int*)(GPIOB_BASE + 0X04)
//#define GPIOB_IDR   *(unsigned int*)(GPIOB_BASE + 0X08)
//#define GPIOB_ODR   *(unsigned int*)(GPIOB_BASE + 0X0C)
//#define GPIOB_BSRR  *(unsigned int*)(GPIOB_BASE + 0X10)	
//#define GPIOB_BRR   *(unsigned int*)(GPIOB_BASE + 0X14)
//#define GPIOB_LCKL  *(unsigned int*)(GPIOB_BASE + 0X18)

//���ýṹ���װ�Ĵ�����Ϊ��ֹ��������û��ִ�г���ı��������Ż�
//����volatile��ֹ���������Ż�

#define  __IO    volatile
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

//����GPIO�Ĵ����Ľṹ��
typedef struct 
{
   __IO uint32_t CRL;     //ƫ�Ƶ�ַ0x00
   __IO uint32_t CRH;     //0x04
   __IO uint32_t IDR;     //0x08
   __IO uint32_t ODR;     //0x0c
   __IO uint32_t BSRR;    //0x10
	 __IO uint32_t BRR;     //0x14
   __IO uint32_t LCKR;    //0x18

}GPIO_TypeDef;


typedef struct
{
	uint32_t  CR;
  uint32_t  CFGR;
  uint32_t  CIR;
  uint32_t  APB2RSTR;
	uint32_t  APB1RSTR;
	uint32_t  AHBENR;
	uint32_t  APB2ENR;
	uint32_t  APB1ENR;
	uint32_t  BDCR;
	uint32_t  CSR;
	uint32_t  AHBRSTR;
	uint32_t  CFGR2;
}RCC_TypeDef;

#define GPIOB  ((GPIO_TypeDef*)GPIOB_BASE)
#define RCC    ((RCC_TypeDef *)RCC_BASE)

#endif /* __STM32F10X_H */
