/**
 * @file    usart.c
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
#include "usart.h"
#include "config.h"
#include "delay.h"

/**
 * @brief   串口1初始化，该串口用于打印日志
 * 
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-08-05
 */
void USART1_Config(void)
{	
	GPIO_InitTypeDef 			GPIO_InitStructure;	
	USART_InitTypeDef 			USART_InitStructure;  //定义串口初始化结构体
	NVIC_InitTypeDef     		NVIC_InitStructure;											//ÖÐ¶Ï½á¹¹Ìå¶¨Òå
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1,ENABLE);


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;	       //选中串口默认输出管脚         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //定义输出最大速率 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//定义管脚9的模式  
	GPIO_Init(GPIOA, &GPIO_InitStructure);           //调用函数，把结构体参数输入进行初始化		   
	/*  USART1_RX ->	PA10*/
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;	        
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 115200; //波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;		//校验位 无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//使能接收和发送引脚

	USART_Init(USART1, &USART_InitStructure); //将以上赋完值的结构体带入库函数USART_Init进行初始化
	USART_Cmd(USART1, ENABLE);//开启USART1，注意与上面RCC_APB2PeriphClockCmd()设置的区别
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);								
	USART_ClearFlag(USART1,USART_FLAG_TC);								
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);    
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 	   									
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 			
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			 					
	NVIC_Init(&NVIC_InitStructure);
}

//=============================================================================
//函数名称:fputc
//功能概要:重定向c库函数printf到USART
//参数说明:无
//函数返回:无
//注意   :由printf调用
//=============================================================================
int fputc(int ch, FILE *f)
{
//将Printf内容发往串口 
  USART_SendData(USART1, (unsigned char) ch);
  while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET); 
  return (ch);
}
//=============================================================================
//函数名称:USART1_Putc
//功能概要:将USART1_Putc（）内容打印到串口
//参数说明:无
//函数返回:无
//注意   :无
//=============================================================================
void USART1_Putc(unsigned char c)
{
    USART_SendData(USART1, c);
    while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET );
}

//=============================================================================
//函数名称:USART1_Putc
//功能概要:将USART1_Putc（）内容打印到串口
//参数说明:无
//函数返回:无
//注意    :无
//=============================================================================
void USART1_Puts(char *str, char len)
{
	for(char n = 0; n < len; n++)
	{
        USART_SendData(USART1, str[n]);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
	}
}


/**
 * @brief   串口2初始化，该串口用于打印日志
 * 
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-08-05
 */
void USART2_Config(void)
{	
	GPIO_InitTypeDef 			GPIO_InitStructure;	
	USART_InitTypeDef 			USART_InitStructure;  //定义串口初始化结构体
	NVIC_InitTypeDef     		NVIC_InitStructure;											//ÖÐ¶Ï½á¹¹Ìå¶¨Òå
	
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA,ENABLE);		
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);	 			


	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2;	       //选中串口默认输出管脚         
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //定义输出最大速率 
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;//定义管脚9的模式  
	GPIO_Init(GPIOA, &GPIO_InitStructure);           //调用函数，把结构体参数输入进行初始化		   

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;	        
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	USART_InitStructure.USART_BaudRate = 9600; //波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b; //数据位8位
	USART_InitStructure.USART_StopBits = USART_StopBits_1;	//停止位1位
	USART_InitStructure.USART_Parity = USART_Parity_No;		//校验位 无
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无流控制
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;		//使能接收和发送引脚

	USART_Init(USART2, &USART_InitStructure); //将以上赋完值的结构体带入库函数USART_Init进行初始化
	USART_Cmd(USART2, ENABLE);//开启USART1，注意与上面RCC_APB2PeriphClockCmd()设置的区别
	
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);								
	USART_ClearFlag(USART2,USART_FLAG_TC);								
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);    
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 	   									
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 	
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 			
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 			 					
	NVIC_Init(&NVIC_InitStructure);
}

void USART2SendByteData(unsigned char c)
{
    USART_SendData(USART2, c);
    while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET );
}


void USART2SendDatas(unsigned char *str, char len)
{
//	InfoLog("send data \r\n");
	for(char n = 0; n < len; n++)
	{
//		printf("0x%02x ", str[n]);
        USART_SendData(USART2, str[n]);
        while(USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET);
		
//		delay_us(500);
	}
//	printf("\r\n");
}

void USART2_IRQHandler(void)
{
	
	char buff = 0;

	if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
	{
		
		buff = USART_ReceiveData(USART2); 
//		USART2SendByteData(buff);
//		printf("0x%02x ", buff);
		UartRevOneByte(buff);
		USART_ClearITPendingBit(USART2, USART_IT_RXNE);
	}
	
}

