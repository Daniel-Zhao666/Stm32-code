#include "stm32f10x.h"//�������ڵ�ǰ����Ŀ¼��û�У���ôת����װ��Ŀ¼Ѱ��


int main(void)
{
	//����LED��
	
	#if 0
	//��GPIOB�˿ڵ�ʱ��
	*(unsigned int *)0x40021018  |= (1 << 3);
	
	//����IO�����
	*(unsigned int *)0x40010c00  &= ~(0xF << (4*0));
  *(unsigned int *)0x40010C00  |= ( 1 << (4*0));//�˿�����ǰ��Ҫ�������ʹ��
	
	//����ODR�Ĵ���
	(unsigned int *)0x40010C0C &= ~(1 << 0);
	#else
	
	//��GPIOB�˿ڵ�ʱ��
	RCC_APB2ENR |= (1 << 3);
	
	//���PB0�˿�λ
	GPIOB_CRL &= ~( 0x0F << (4 * 0)); 
	
	//����PB0Ϊͨ������������ٶ�Ϊ10M
	GPIOB_CRL |= (1 << 4 * 0);
	
	//PB0����͵�ƽ
	GPIOB_ODR &= ~(1<< 0);
	
	#endif
}


void SystemInit(void)
{
 //������Ϊ�գ�Ŀ����Ϊ����������������
}
