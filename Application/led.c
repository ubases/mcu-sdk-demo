#include "led.h"
#include "stm32f10x.h"



void LedInit(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOC , ENABLE); 						 
	//=============================================================================
	//LED -> PC13
	//=============================================================================			 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

void LedTurnOn(void)
{
	GPIO_ResetBits(GPIOC , GPIO_Pin_13);
}

void LedTurnOff(void)
{
	GPIO_SetBits(GPIOC , GPIO_Pin_13);
}

void LedToggle(void)
{
	static uint8_t num = 0;
	
	if(num)
	{
		LedTurnOn();
		num = 0;
	}
	else
	{
		LedTurnOff();
		num = 1;
	}
}
