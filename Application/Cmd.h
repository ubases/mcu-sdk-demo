

#ifndef __CMD_H
#define	__CMD_H


 #include "stm32f10x.h"
#include "string.h"
#include "stdarg.h"
#include <stdio.h>
#include "stdint.h"
#include "ctype.h"
#include "math.h"


#define     USART_RX_BUFF_LEN                           200


#define CMD_ARGC_MAX    16

#define CMD_ENT_DEF(cmd, ent) \
    static CmdEntrance_t CmdEntrance_##cmd = {#cmd, ent, NULL}

#define CMD_ENT(cmd)  \
        &CmdEntrance_##cmd
		
#define ARGV_EQUAL(token)       (strcmp(argv[0], (char*)token) == 0)


typedef enum {false = 0, true =  1} bool;



/*环形队列类型*/
typedef struct
{
    uint16_t front;            /*头指针偏移量*/
    uint16_t rear;             /*尾指针偏移量*/
    uint16_t count;            /*元素计数器*/
    uint16_t lenth;            /*缓存长度*/
    char *pbuf;                /*缓存指针*/
} CirQueue_TypeDef;            /*环形队列缓存类型*/

/*命令处理回调函数指针*/
typedef void (*Cmd_CallBack)(int argc, char *argv[]);

/*命令处理入口*/
typedef struct CmdEntrance
{
    char const *cmd;
    Cmd_CallBack pCB;
    struct CmdEntrance *next;
} CmdEntrance_t;


typedef struct
{
    uint8_t *pBuffer;
    uint32_t sizeMask;
    uint32_t rpos;
    uint32_t wpos;
} FIFO_t;


bool Cmd_AddEntrance(CmdEntrance_t *pEnt);



#endif

