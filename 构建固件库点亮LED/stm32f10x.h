#ifndef __STM32F10X_H
#define __STM32F10X_H


//片上外设基地址
#define PERIPH_BASE      ((unsigned int)0x40000000)
#define APB1PERIPH_BASE    PERIPH_BASE

//总线基地址， GPIO都挂在APB2上
#define APB2PERIPH_BASE (PERIPH_BASE + 0X10000)
#define AHBPERIPH_BASE  (PERIPH_BASE + 0X20000)

//GPIOB外设基地址
#define GPIOB_BASE   (APB2PERIPH_BASE + 0X0C00)

//RCC外设基地址，用于设置挂在APB2上的外设的时钟
#define RCC_BASE   (AHBPERIPH_BASE + 0X1000)

//RCC的AHB1时钟使能寄存器地址(使能信号，控制RCC)，强制类型转换为指针
#define RCC_APB2ENR  *(unsigned int*)(RCC_BASE + 0X18)
	
//GPIOB的寄存器地址，强制类型转换为指针
//#define GPIOB_CRL   *(unsigned int*)(GPIOB_BASE + 0X00)
//#define GPIOB_CRH   *(unsigned int*)(GPIOB_BASE + 0X04)
//#define GPIOB_IDR   *(unsigned int*)(GPIOB_BASE + 0X08)
//#define GPIOB_ODR   *(unsigned int*)(GPIOB_BASE + 0X0C)
//#define GPIOB_BSRR  *(unsigned int*)(GPIOB_BASE + 0X10)	
//#define GPIOB_BRR   *(unsigned int*)(GPIOB_BASE + 0X14)
//#define GPIOB_LCKL  *(unsigned int*)(GPIOB_BASE + 0X18)

//采用结构体封装寄存器，为防止编译器对没有执行程序的变量进行优化
//定义volatile防止被编译器优化

#define  __IO    volatile
typedef unsigned int uint32_t;
typedef unsigned short uint16_t;

//定义GPIO寄存器的结构体
typedef struct 
{
   __IO uint32_t CRL;     //偏移地址0x00
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
