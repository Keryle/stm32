#include "led.h"
#include "timer.h"
int main(void)
{
    SystemInit();
    Systick_Init();
    led_gpio_config();                   //����GPIO
    //SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    while(1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_15);    //��PB15���óɸߵ�ƽ
        delay_ms(1000);
        GPIO_ResetBits(GPIOB, GPIO_Pin_15);    //��PB15���óɵ͵�ƽ
        delay_ms(1000);                       //�ȴ�
        
    }

}