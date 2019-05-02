#include "timer.h"
__IO uint32_t TimingDelay;

/*SystemCoreClock / 1000000  -------   1us*/
/*SystemCoreClock / 100000   -------   10us*/
/*SystemCoreClock / 10000    -------   100us*/
/*SystemCoreClock / 1000     -------   1ms*/

void Systick_Init(void)
{
    if (SysTick_Config(72000))
    { 
      /* Capture error */ 
      while (1);
    }
}
void TimingDelay_Decrement(void)
{
    if (TimingDelay != 0x00)
    {
        TimingDelay--;
    }
}

void delay_ms(__IO uint32_t nTime)//�ӳٺ���������Ϊ US
{
    TimingDelay = nTime;//ʱ�ӵδ���
    while(TimingDelay != 0);
}

void SysTick_Handler(void)
{
    TimingDelay_Decrement();
}