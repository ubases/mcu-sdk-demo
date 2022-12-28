
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


static BOOL switch_status = FALSE;
static unsigned char mode_status = 0;
static unsigned char speed_status = 0;
static unsigned long temp_status = 0;
static unsigned long humidity_status = 0;
static unsigned long pm25_status = 0;
static unsigned long tvoc_status = 0;
static unsigned long eco2_status = 0;
static unsigned char air_quality_status = 0;
static unsigned long filter_status = 0;
static unsigned long filter_days_status = 0;
static BOOL filter_reset_status = FALSE;
static unsigned char fault_code_status = 0;
static unsigned char fault_type_status = 0;
static unsigned long total_time_status = 0;
static unsigned long total_pm_status = 0;
static unsigned char temp_unit_convert_status = 0;
static unsigned long methanal_status = 0;
static BOOL anion_status = FALSE;
static BOOL uv_status = FALSE;
static BOOL lock_status = FALSE;
static unsigned char light_status = 0;


const McuCmdInfo CmdInfoList[] = 
{
  {CMD_SWITCH, DATA_TYPE_BOOL},
  {CMD_MODE, DATA_TYPE_ENUM},
  {CMD_SPEED, DATA_TYPE_ENUM},
  {CMD_TEMP, DATA_TYPE_VALUE},
  {CMD_HUMIDITY, DATA_TYPE_VALUE},
  {CMD_PM25, DATA_TYPE_VALUE},
  {CMD_TVOC, DATA_TYPE_VALUE},
  {CMD_ECO2, DATA_TYPE_VALUE},
  {CMD_AIR_QUALITY, DATA_TYPE_ENUM},
  {CMD_FILTER, DATA_TYPE_VALUE},
  {CMD_FILTER_DAYS, DATA_TYPE_VALUE},
  {CMD_FILTER_RESET, DATA_TYPE_BOOL},
  {CMD_FAULT_CODE, DATA_TYPE_ENUM},
  {CMD_FAULT_TYPE, DATA_TYPE_ENUM},
  {CMD_TOTAL_TIME, DATA_TYPE_VALUE},
  {CMD_TOTAL_PM, DATA_TYPE_VALUE},
  {CMD_TEMP_UNIT_CONVERT, DATA_TYPE_ENUM},
  {CMD_METHANAL, DATA_TYPE_VALUE},
  {CMD_ANION, DATA_TYPE_BOOL},
  {CMD_UV, DATA_TYPE_BOOL},
  {CMD_LOCK, DATA_TYPE_BOOL},
  {CMD_LIGHT, DATA_TYPE_ENUM},
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
    
    UartReportBoolTypeData(CMD_SWITCH, switch_status);
    UartReportEnumTypeData(CMD_MODE, mode_status);
    UartReportEnumTypeData(CMD_SPEED, speed_status);
    UartReportValueTypeData(CMD_TEMP, temp_status);
    UartReportValueTypeData(CMD_HUMIDITY, humidity_status);
    UartReportValueTypeData(CMD_PM25, pm25_status);
    UartReportValueTypeData(CMD_TVOC, tvoc_status);
    UartReportValueTypeData(CMD_ECO2, eco2_status);
    UartReportEnumTypeData(CMD_AIR_QUALITY, air_quality_status);
    UartReportValueTypeData(CMD_FILTER, filter_status);
    UartReportValueTypeData(CMD_FILTER_DAYS, filter_days_status);
    UartReportBoolTypeData(CMD_FILTER_RESET, filter_reset_status);
    UartReportEnumTypeData(CMD_FAULT_CODE, fault_code_status);
    UartReportEnumTypeData(CMD_FAULT_TYPE, fault_type_status);
    UartReportValueTypeData(CMD_TOTAL_TIME, total_time_status);
    UartReportValueTypeData(CMD_TOTAL_PM, total_pm_status);
    UartReportEnumTypeData(CMD_TEMP_UNIT_CONVERT, temp_unit_convert_status);
    UartReportValueTypeData(CMD_METHANAL, methanal_status);
    UartReportBoolTypeData(CMD_ANION, anion_status);
    UartReportBoolTypeData(CMD_UV, uv_status);
    UartReportBoolTypeData(CMD_LOCK, lock_status);
    UartReportEnumTypeData(CMD_LIGHT, light_status);
}


/**
 * @brief   开关状态
 * 
 * @param[in]   value      开关状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlSwitchState(unsigned char *value)
{
    switch_status = ProGetdpidValueBool(value);
    if(switch_status)    
    {
        // 开关开状态
    }
    else
    {
        // 开关关闭状态
    }

    UartReportBoolTypeData(CMD_SWITCH, switch_status);
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
        
        case 0:
        {
        }
        break;
        
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
 * @brief   风速状态
 * 
 * @param[in]   value      风速状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlSpeedState(unsigned char *value)
{
    speed_status = ProGetdpidValueEnum(value);
    switch (speed_status)
    {
        
        case 0:
        {
        }
        break;
        
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
        
        case 4:
        {
        }
        break;
        
        case 5:
        {
        }
        break;
        
        default:
            break;
    }

    UartReportEnumTypeData(CMD_SPEED, speed_status);
}

/**
 * @brief   温标切换状态
 * 
 * @param[in]   value      温标切换状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlTempUnitConvertState(unsigned char *value)
{
    temp_unit_convert_status = ProGetdpidValueEnum(value);
    switch (temp_unit_convert_status)
    {
        
        case 0:
        {
        }
        break;
        
        case 1:
        {
        }
        break;
        
        default:
            break;
    }

    UartReportEnumTypeData(CMD_TEMP_UNIT_CONVERT, temp_unit_convert_status);
}

/**
 * @brief   负离子状态
 * 
 * @param[in]   value      负离子状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlAnionState(unsigned char *value)
{
    anion_status = ProGetdpidValueBool(value);
    if(anion_status)    
    {
        // 负离子开状态
    }
    else
    {
        // 负离子关闭状态
    }

    UartReportBoolTypeData(CMD_ANION, anion_status);
}

/**
 * @brief   UV杀菌状态
 * 
 * @param[in]   value      UV杀菌状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlUvState(unsigned char *value)
{
    uv_status = ProGetdpidValueBool(value);
    if(uv_status)    
    {
        // UV杀菌开状态
    }
    else
    {
        // UV杀菌关闭状态
    }

    UartReportBoolTypeData(CMD_UV, uv_status);
}

/**
 * @brief   童锁状态
 * 
 * @param[in]   value      童锁状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlLockState(unsigned char *value)
{
    lock_status = ProGetdpidValueBool(value);
    if(lock_status)    
    {
        // 童锁开状态
    }
    else
    {
        // 童锁关闭状态
    }

    UartReportBoolTypeData(CMD_LOCK, lock_status);
}

/**
 * @brief   提示灯状态
 * 
 * @param[in]   value      提示灯状态数据
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-29
 */
static void ControlLightState(unsigned char *value)
{
    light_status = ProGetdpidValueEnum(value);
    switch (light_status)
    {
        
        case 0:
        {
        }
        break;
        
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

    UartReportEnumTypeData(CMD_LIGHT, light_status);
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
void ProcessDataCmd(unsigned char cmd_id, unsigned char *FrameData)
{
    switch (cmd_id)
    {
        
        case CMD_SWITCH:
        {
            // 开关处理函数
            ControlSwitchState(FrameData);
        }
        break;
        
        case CMD_MODE:
        {
            // 模式处理函数
            ControlModeState(FrameData);
        }
        break;
        
        case CMD_SPEED:
        {
            // 风速处理函数
            ControlSpeedState(FrameData);
        }
        break;
        
        case CMD_TEMP_UNIT_CONVERT:
        {
            // 温标切换处理函数
            ControlTempUnitConvertState(FrameData);
        }
        break;
        
        case CMD_ANION:
        {
            // 负离子处理函数
            ControlAnionState(FrameData);
        }
        break;
        
        case CMD_UV:
        {
            // UV杀菌处理函数
            ControlUvState(FrameData);
        }
        break;
        
        case CMD_LOCK:
        {
            // 童锁处理函数
            ControlLockState(FrameData);
        }
        break;
        
        case CMD_LIGHT:
        {
            // 提示灯处理函数
            ControlLightState(FrameData);
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
    USART2SendDatas((char *)dataBuff, dataLen);
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
