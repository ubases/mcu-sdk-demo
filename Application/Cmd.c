
#include "cmd.h"
#include "usart.h"



static CmdEntrance_t *firstEnt = NULL;
 /***********************定义全局变量*************************/
static uint8_t    USART_RX_Buff[USART_RX_BUFF_LEN];
static uint16_t  RxCounter = 0;

 /***
* Description : 添加命令处理入口.
*******************************************************************************
*/
bool Cmd_AddEntrance(CmdEntrance_t *pEnt)
{
    bool r = false;
    CmdEntrance_t *p = NULL;

    if (pEnt != NULL && pEnt->cmd != NULL) 
	{
        if (firstEnt == NULL) 
		{
            firstEnt = pEnt;
        } 
		else 
		{
            p = firstEnt;
            while (p->next != NULL)
			{
                p = p->next;
            }
            p->next = pEnt;
        }
        r = true;
    }
    return r;
}

/***
* Description : 命令处理.
*******************************************************************************
*/
void Cmd_Handle(char *cmd)
{
    int argc = 0;
    char *argv[CMD_ARGC_MAX + 1], *p = NULL;
    CmdEntrance_t *pEnt = firstEnt;

	for (argc = 0; argc < CMD_ARGC_MAX; argc++) {
        argv[argc] = NULL;
	}
	while (*cmd && !isgraph(*cmd)) {
        cmd++;
    }
    argc = 1;
    argv[0] = cmd;
    p = cmd;
    /*去除非可显字符*/
    while (*p && argc < CMD_ARGC_MAX) {
        while (*p && isgraph(*p)) {
            p++;
        }
        while (*p && !isgraph(*p)) {
            *p = 0;
            p++;
        }
        if (*p) {
            argv[argc] = p;
            argc++;
        }
    }
    argv[argc] = NULL;
    /*回调*/
    while (pEnt != NULL) {
        if (argc > 0) {
            pEnt->pCB(argc, argv);
            break;
        }
        pEnt = pEnt->next;
    }
}





void USART1_IRQHandler(void)
{

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)
	{
		/* Read one byte from the receive data register */
		USART_RX_Buff[RxCounter] = USART_ReceiveData(USART1); 
		if(USART_RX_Buff[RxCounter] != '\n')
		{
//			USART1_Putc(USART_RX_Buff[RxCounter]);
			RxCounter++;
		}
		else
		{
			
			USART_RX_Buff[RxCounter] = '\0';
			printf("%s\r\n", USART_RX_Buff);
//			USART1_Puts((char *)USART_RX_Buff, RxCounter);
			Cmd_Handle((char *) USART_RX_Buff);
			memset(USART_RX_Buff, 0, sizeof(USART_RX_Buff));
			RxCounter = 0;
		}
		if(RxCounter >= USART_RX_BUFF_LEN)	RxCounter = 0;
		
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
	
}


