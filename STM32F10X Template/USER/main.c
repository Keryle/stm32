#include "led.h"
#include "timer.h"
int main(void)
{
    SystemInit();
    Systick_Init();
    led_gpio_config();                   //配置GPIO
    //SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    while(1)
    {
        GPIO_SetBits(GPIOB, GPIO_Pin_15);    //将PB15设置成高电平
        delay_ms(1000);
        GPIO_ResetBits(GPIOB, GPIO_Pin_15);    //将PB15设置成低电平
        delay_ms(1000);                       //等待
        
    }

}