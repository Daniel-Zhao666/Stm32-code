
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
#define GPIOB_CRL   *(unsigned int*)(GPIOB_BASE + 0X00)
#define GPIOB_CRH   *(unsigned int*)(GPIOB_BASE + 0X04)
#define GPIOB_IDR   *(unsigned int*)(GPIOB_BASE + 0X08)
#define GPIOB_ODR   *(unsigned int*)(GPIOB_BASE + 0X0C)
#define GPIOB_BSRR  *(unsigned int*)(GPIOB_BASE + 0X10)	
#define GPIOB_BRR   *(unsigned int*)(GPIOB_BASE + 0X14)
#define GPIOB_LCKL  *(unsigned int*)(GPIOB_BASE + 0X18)

