/******************** (C) COPYRIGHT 2011 迷你嵌入式开发工作室 ********************
 * 文件名  ：led.c
 * 描述    ：led 应用函数库
 *          
 * 实验平台：
 * 硬件连接：PC3 - LED1
 *           PC4 - LED2
 *           PC5 - LED3
 * 作者    ：mrt2  QQ: 313303034
 * 时间    ：2011-06-01
 * 版本    ：V1.0
**********************************************************************************/

#include "led.h"

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC, ENABLE);

  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;	
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;       
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_SetBits(GPIOC, GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5);	 // turn off all led
}


/******************* (C) COPYRIGHT 2011 迷你嵌入式开发工作室 *****END OF FILE****/
