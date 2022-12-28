
/**
 * @file    protocol.c
 * @brief   
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-28
 * 
 * @copyright Copyright (c) 2022  Personal
 * 
 * @par 修改日志
 * Date      |Version|Author          |Description
 * ----------|-------|----------------|--------------
 * 2022-06-28|1.0.0  |Ai-Thinker      |创建
 */
#include "config.h"
#include "usart.h"


static BOOL powerstate_status = FALSE;
static BOOL mode_switch_status = FALSE;
static unsigned char mode_status = 0;
static BOOL light_switch_status = FALSE;
static unsigned char light_mode_status = 0;


const McuCmdInfo CmdInfoList[] = 
{
  {CMD_POWERSTATE, DATA_TYPE_BOOL},
  {CMD_MODE_SWITCH, DATA_TYPE_BOOL},
  {CMD_MODE, DATA_TYPE_ENUM},
  {CMD_LIGHT_SWITCH, DATA_TYPE_BOOL},
  {CMD_LIGHT_MODE, DATA_TYPE_ENUM},
};




/*******************************************************************************************************
 *                                  1. 以下是由爱星云平台根据物模型选择自动生成具体用户函数
 *                                ** a. 以下是由云平台自动生成APP下发数据处理函数 **
 *                                ** b. 以下是由爱星云自动生成数据上报处理函数 **
 *                                ** c. ReportAllDeviceState这个函数不可修改，由SDK自动调用上报所有状态
 * ******************************************************************************************************/

/**
 * @brief   MCU向模组上报所有的状态数据
 * 
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
void ReportAllDeviceState(void)
{
    //#error "请在此处理可下发可上报数据及只上报数据示例,处理完成后删除该行"
    
    UartReportBoolTypeData(CMD_POWERSTATE, powerstate_status);
    UartReportBoolTypeData(CMD_MODE_SWITCH, mode_switch_status);
    UartReportEnumTypeData(CMD_MODE, mode_status);
    UartReportBoolTypeData(CMD_LIGHT_SWITCH, light_switch_status);
    UartReportEnumTypeData(CMD_LIGHT_MODE, light_mode_status);
}


/**
 * @brief   开关状态
 * 
 * @param[in]   value      开关状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlPowerstateState(unsigned char *value)
{
    powerstate_status = ProGetdpidValueBool(value);
    if(powerstate_status)    
    {
        // 开关开状态
    }
    else
    {
        // 开关关闭状态
    }

    UartReportBoolTypeData(CMD_POWERSTATE, powerstate_status);
}

/**
 * @brief   模式开关状态
 * 
 * @param[in]   value      模式开关状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlModeSwitchState(unsigned char *value)
{
    mode_switch_status = ProGetdpidValueBool(value);
    if(mode_switch_status)    
    {
        // 模式开关开状态
    }
    else
    {
        // 模式开关关闭状态
    }

    UartReportBoolTypeData(CMD_MODE_SWITCH, mode_switch_status);
}

/**
 * @brief   模式状态
 * 
 * @param[in]   value      模式状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlModeState(unsigned char *value)
{
    mode_status = ProGetdpidValueEnum(value);
    switch (mode_status)
    {
        
        case 1:
        {
        }
        break;
        
        case 2:
        {
        }
        break;
        
        case 3:
        {
        }
        break;
        
        default:
            break;
    }

    UartReportEnumTypeData(CMD_MODE, mode_status);
}

/**
 * @brief   灯开关状态
 * 
 * @param[in]   value      灯开关状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlLightSwitchState(unsigned char *value)
{
    light_switch_status = ProGetdpidValueBool(value);
    if(light_switch_status)    
    {
        // 灯开关开状态
    }
    else
    {
        // 灯开关关闭状态
    }

    UartReportBoolTypeData(CMD_LIGHT_SWITCH, light_switch_status);
}

/**
 * @brief   灯模式状态
 * 
 * @param[in]   value      灯模式状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlLightModeState(unsigned char *value)
{
    light_mode_status = ProGetdpidValueEnum(value);
    switch (light_mode_status)
    {
        
        case 1:
        {
        }
        break;
        
        case 2:
        {
        }
        break;
        
        default:
            break;
    }

    UartReportEnumTypeData(CMD_LIGHT_MODE, light_mode_status);
}


/*************************************************************************************************************
 *                              3. 以下函数主要是处理APP下发的数据
 *                      ** a. 该函数名不可修改，云平台根据不同物模型而进行自动生成处理事件 **
 *                      ** b. 云平台可根据不同物模型事件而进行自动补充调用自动生成的具体用户函数 **
 * ***********************************************************************************************************/
/**
 * @brief   处理待控制的物模型数据
 * 
 * @param[in]   cmd_id   数据id
 * @param[in]   FrameData     待控制的状态数据
 * @param[in]   data_len 数据长度
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
void ProcessDataCmd(unsigned char cmd_id, unsigned char *FrameData, unsigned short DataLen)
{
    switch (cmd_id)
    {
        
        case CMD_POWERSTATE:
        {
            // 开关处理函数
            
            ControlPowerstateState(FrameData);
        }
        break;
        
        case CMD_MODE_SWITCH:
        {
            // 模式开关处理函数
            
            ControlModeSwitchState(FrameData);
        }
        break;
        
        case CMD_MODE:
        {
            // 模式处理函数
            
            ControlModeState(FrameData);
        }
        break;
        
        case CMD_LIGHT_SWITCH:
        {
            // 灯开关处理函数
            
            ControlLightSwitchState(FrameData);
        }
        break;
        
        case CMD_LIGHT_MODE:
        {
            // 灯模式处理函数
            
            ControlLightModeState(FrameData);
        }
        break;
        
        default:
            break;
    }
}









/***********************************************************************************************************
 *                                      4. 以下代码为SDK内部调用代码
 *                              ** a. 以下代码由MCU SDK调用  **
 *                              ** b. 以下代码函数名不可修改，亦不可删除 **
 *                              ** c. 以下代码若是MCU开发者需调用，可自行补充内容，若不需要调用，可无需改动 **
 * *********************************************************************************************************/


/**
 * @brief   串口发送数据函数
 * 
 * @note    该函数需由客户适配好对于发送接口。即MCU_SDK调用该函数，即可将数据通过串口发送给模组
 * 
 * @param[in]   dataBuff        待发送的数据
 * @param[in]   dataLen         数据长度
 * @return  unsigned char            返回发送结果
 *          0：发送成功
 *          -1：发送失败
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-23
 */
char UartWriteData(unsigned char *dataBuff, unsigned char dataLen)
{
	//#error "请将MCU串口发送函数填入该函数,并删除该行"	
	USART2SendDatas(dataBuff, dataLen);
	return 0;
}


/**
 * @brief   根据数据Id获取序号
 * 
 * @param[in]   cmd_id   数据id
 * @return  unsigned char      返回序号
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-07-13
 */
unsigned char GetCmdIdIndex(unsigned char cmd_id)
{
    unsigned char total = (sizeof(CmdInfoList) / sizeof(CmdInfoList[0]));
    unsigned char index = 0;

    for(index = 0; index < total; index++)
    {
        if(CmdInfoList[index].cmd_id == cmd_id)
        {
            break;
        }
    }

    return index;
}
