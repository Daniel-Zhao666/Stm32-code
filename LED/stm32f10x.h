
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
#define GPIOB_CRL   *(unsigned int*)(GPIOB_BASE + 0X00)
#define GPIOB_CRH   *(unsigned int*)(GPIOB_BASE + 0X04)
#define GPIOB_IDR   *(unsigned int*)(GPIOB_BASE + 0X08)
#define GPIOB_ODR   *(unsigned int*)(GPIOB_BASE + 0X0C)
#define GPIOB_BSRR  *(unsigned int*)(GPIOB_BASE + 0X10)	
#define GPIOB_BRR   *(unsigned int*)(GPIOB_BASE + 0X14)
#define GPIOB_LCKL  *(unsigned int*)(GPIOB_BASE + 0X18)

