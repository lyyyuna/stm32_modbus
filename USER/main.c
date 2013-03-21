#include <stdio.h>
#include "stm32f10x.h"
#include "mb.h"

void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);
}

int main(void)
{
    SystemInit();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
	NVIC_Configuration();
	
	eMBInit( MB_RTU, 0x01, 0, 9600, MB_PAR_NONE );
	
	/* Enable the Modbus Protocol Stack. */
	eMBEnable(  );
	
	for( ;; )
	{
	    ( void )eMBPoll(  );
	    /* Here we simply count the number of poll cycles. */
	}
}

eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
	static uint8_t flag = 0;
	
	flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_1) : GPIO_ResetBits(GPIOC,GPIO_Pin_1);  
	flag ^= 1;
    return eStatus;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
	eMBErrorCode    eStatus = MB_ENOERR;
	static uint8_t flag = 0;
	
	flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_2) : GPIO_ResetBits(GPIOC,GPIO_Pin_2);  
	flag ^= 1;
    return eStatus;
}

eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
    static uint8_t flag = 0;
	
	flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_3) : GPIO_ResetBits(GPIOC,GPIO_Pin_3);  
	flag ^= 1;
	return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    static uint8_t flag = 0;
	
	flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_4) : GPIO_ResetBits(GPIOC,GPIO_Pin_4);  
	flag ^= 1;
	return MB_ENOREG;
}