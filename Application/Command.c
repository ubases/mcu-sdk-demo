
#include "command.h"
#include "config.h"





static void funSystem(int argc, char* argv[]) ;



/**
	* @brief  初始化命令处理.
	* @param  none.
	* @retval none
	*/
void Command_Init(void) 
{
	CMD_ENT_DEF(system, funSystem);
	Cmd_AddEntrance(CMD_ENT(system));


	printf("Command Init.\r\n");
}


static void funSystem(int argc, char* argv[]) 
{  
	if (ARGV_EQUAL("reset"))
	{
		printf("receive reset \r\n");
		NVIC_SystemReset(); 
	}
	
	if (ARGV_EQUAL("AT_RST"))
	{
		UartReportResetState();
		printf("AT+RST=OK! \r\n");
	}
	
	if (ARGV_EQUAL("AT_REP"))
	{
		ReportAllDeviceState();
		printf("report device status \r\n");
	}
	
	if (ARGV_EQUAL("AT_PRD"))
	{
//		UartSendProductInfo();
		printf("report product info \r\n");
	}
}


