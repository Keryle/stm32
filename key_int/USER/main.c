#include "led.h"
#include "timer.h"
#include "key.h"
int main(void)
{
    SystemInit();
    led_gpio_config();                   //����GPIO
    key_gpio_config();
    //SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);
    while(1)
    {

    }

}
