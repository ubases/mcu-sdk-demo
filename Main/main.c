/**
 * @file    main.c
 * @brief   
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-08-05
 * 
 * @copyright Copyright (c) 2022  Personal
 * 
 * @par 修改日志
 * Date      |Version|Author          |Description
 * ----------|-------|----------------|--------------
 * 2022-08-05|1.0.0  |Ai-Thinker      |创建
 */
#include "stm32f10x.h"
#include <stdio.h>
#include "usart.h"
#include "delay.h"
#include "command.h"
#include "config.h"
#include "led.h"



int main(void)
{
//	char str[] = "zhuolingmin\r\n";
//	static char count = 0;
	
	USART1_Config();
	USART2_Config();
	delay_init();
	Command_Init();
	UartProtocolInit();
	LedInit();
	
	printf("System start .... \r\n");
	while (1)
	{
		UartProcessPro();
//		USART2SendDatas(str, strlen(str));
		delay_ms(150);
	}
	
}


