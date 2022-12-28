
/**
 * @file    config.h
 * @brief   
 * 
 * @author  Ai-Thinker (zhuolm@tech-now.com)
 * @date    2022-06-22
 * 
 * @copyright Copyright (c) 2022  Personal
 * 
 * @par 修改日志
 * Date      |Version|Author          |Description
 * ----------|-------|----------------|--------------
 * 2022-06-22|1.0.0  |Ai-Thinker      |创建
 */
#ifndef __CONFIG_H
#define __CONFIG_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// #include <stdint.h>
// #include <stdbool.h>

#include "mcu_api.h"
#include "system.h"
#include "protocol.h"




/* 开发平台创建产品后生成的产品ID，用户可根据创建不同产品而获得不同的产品ID，可在该处进行修改*/
#define  PRODUCT_ID                         "EiI3goou"

/* 产品标识,该标识是用户在创建不同产品时将自定义的产品标识 */
#define  PRODUCT_FLAG                       "AIR"


//============================ 空净物模型数据定义 ==================================================


//开关(可下发可上报 rw)
//备注:
#define CMD_SWITCH              1
//模式(可下发可上报 rw)
//备注:
#define CMD_MODE              2
//风速(可下发可上报 rw)
//备注:
#define CMD_SPEED              3
//室内温度(只下发（wr）)
//备注:
#define CMD_TEMP              4
//室内湿度(只下发（wr）)
//备注:
#define CMD_HUMIDITY              5
//PM2.5(只下发（wr）)
//备注:
#define CMD_PM25              6
//TVOC(只下发（wr）)
//备注:
#define CMD_TVOC              7
//eCO2(只下发（wr）)
//备注:
#define CMD_ECO2              8
//空气质量(只下发（wr）)
//备注:
#define CMD_AIR_QUALITY              9
//滤芯使用率(只下发（wr）)
//备注:
#define CMD_FILTER              10
//滤芯剩余天数(只下发（wr）)
//备注:
#define CMD_FILTER_DAYS              11
//滤芯复位(只下发（wr）)
//备注:
#define CMD_FILTER_RESET              12
//故障告警(只下发（wr）)
//备注:
#define CMD_FAULT_CODE              13
//故障类型(只下发（wr）)
//备注:
#define CMD_FAULT_TYPE              14
//累计工作时间(只下发（wr）)
//备注:
#define CMD_TOTAL_TIME              15
//累计吸收颗粒(只下发（wr）)
//备注:
#define CMD_TOTAL_PM              16
//温标切换(可下发可上报 rw)
//备注:
#define CMD_TEMP_UNIT_CONVERT              17
//甲醛(只下发（wr）)
//备注:
#define CMD_METHANAL              18
//负离子(可下发可上报 rw)
//备注:
#define CMD_ANION              19
//UV杀菌(可下发可上报 rw)
//备注:
#define CMD_UV              20
//童锁(可下发可上报 rw)
//备注:
#define CMD_LOCK              21
//提示灯(可下发可上报 rw)
//备注:
#define CMD_LIGHT              22

#endif
