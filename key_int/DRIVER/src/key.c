#include "key.h"

u8 keyFlag = 0;

void key_gpio_config(void)
{
  EXTI_InitTypeDef EXTI_InitStructure;
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOB, &GPIO_InitStructure);
  GPIO_EXTILineConfig(GPIO_PortSourceGPIOB, GPIO_PinSource14);

  EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStructure.EXTI_Line = EXTI_Line14;
  EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStructure.EXTI_LineCmd = ENABLE;
  EXTI_Init(&EXTI_InitStructure);

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_0);
  NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
void EXTI15_10_IRQHandler(void)
{
  u16 i,j;
  if(EXTI_GetFlagStatus(EXTI_Line14) != RESET){   /*下降沿触发，判断触发线
                                                   *set，reset并不代表高低电平
                                                   */
    for(i = 0; i < 100; i++)
      for(j = 0; j < 720; j++);                   //延时

    if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) == RESET){ //reset低电平
      keyFlag = keyFlag > 0 ? 0 : 1;
      if(keyFlag)
        GPIO_SetBits(GPIOB, GPIO_Pin_15);
      else
        GPIO_ResetBits(GPIOB, GPIO_Pin_15);
    }
    EXTI_ClearITPendingBit(EXTI_Line14);          //清除标志位
  }
  while(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14) != RESET){ //等待按键松开
  }
}
/*
 *
 *
 *
 *
 *
 *end
 */
