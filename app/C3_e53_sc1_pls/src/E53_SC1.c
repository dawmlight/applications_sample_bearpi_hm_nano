/*
 * Copyright (c) 2020 Nanjing Xiaoxiongpai Intelligent Technology Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "E53_SC1.h"
#include "cmsis_os2.h"
#include "iot_errno.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"
#include "iot_i2c.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define WIFI_IOT_IO_FUNC_GPIO_0_I2C1_SDA 6
#define WIFI_IOT_IO_FUNC_GPIO_1_I2C1_SCL 6
#define WIFI_IOT_IO_FUNC_GPIO_7_GPIO 0
#define WIFI_IOT_I2C_IDX_1 1

/***************************************************************
 * 函数名称: E53SC1IoInit
 * 说    明: E53_SC1 GPIO初始化
 * 参    数: 无
 * 返 回 值: 无
 ***************************************************************/
static void E53SC1IoInit(void)
{
    IoTGpioInit(7);
    IoTGpioSetFunc(7, WIFI_IOT_IO_FUNC_GPIO_7_GPIO);
    IoTGpioSetDir(7, IOT_GPIO_DIR_OUT); //设置GPIO_7为输出模式

    IoTGpioInit(0);
    IoTGpioSetFunc(0, WIFI_IOT_IO_FUNC_GPIO_0_I2C1_SDA); // GPIO_0复用为I2C1_SDA
    IoTGpioInit(1);
    IoTGpioSetFunc(1, WIFI_IOT_IO_FUNC_GPIO_1_I2C1_SCL); // GPIO_1复用为I2C1_SCL
    IoTI2cInit(WIFI_IOT_I2C_IDX_1, 400000);              /* baudrate: 400kbps */
}
/***************************************************************
 * 函数名称: Init_BH1750
 * 说    明: 写命令初始化BH1750
 * 参    数: 无
 * 返 回 值: 0 成功; -1 失败
 ***************************************************************/
static int InitBH1750(void)
{
    int ret;
    uint8_t send_data[1] = {0x01};
    ret = IoTI2cWrite(WIFI_IOT_I2C_IDX_1, (BH1750_ADDR << 1) | 0x00, send_data, 1);
    if (ret != 0) {
        printf("===== Error: I2C write ret = 0x%x! =====\r\n", ret);
        return -1;
    }
    return 0;
}

/***************************************************************
 * 函数名称: Start_BH1750
 * 说    明: 启动BH1750
 * 参    数: 无
 * 返 回 值: 0 成功; -1 失败
 ***************************************************************/
static int StartBH1750(void)
{
    int ret;
    uint8_t send_data[1] = {0x10};
    ret = IoTI2cWrite(WIFI_IOT_I2C_IDX_1, (BH1750_ADDR << 1) | 0x00, send_data, 1);
    if (ret != 0) {
        printf("===== Error: I2C write ret = 0x%x! =====\r\n", ret);
        return -1;
    }
    return 0;
}
/***************************************************************
 * 函数名称: E53SC1Init
 * 说    明: 初始化E53_SC1
 * 参    数: 无
 * 返 回 值: 0 成功; -1 失败
 ***************************************************************/
int E53SC1Init(void)
{
    int ret;
    E53SC1IoInit();
    ret = InitBH1750();
    if (ret != 0) {
        return -1;
    }
    return 0;
}
/***************************************************************
 * 函数名称: E53_SC1_Read_Data
 * 说    明: 测量光照强度
 * 参    数: data,光照强度数据指针
 * 返 回 值: 0 成功; -1 失败
 ***************************************************************/
int E53SC1ReadData(float* data)
{
    int ret;
    int result;
    ret = StartBH1750(); // 启动传感器采集数据
    if (ret != 0) {
        printf("Start BH1750 failed!\r\n");
        return -1;
    }
    usleep(180000);
    uint8_t recv_data[2] = {0};
    ret = IoTI2cRead(WIFI_IOT_I2C_IDX_1, (BH1750_ADDR << 1) | 0x01, recv_data, 2); // 读取传感器数据
    if (ret != 0) {
        return -1;
    }
    *data = (float)(((recv_data[0] << 8) + recv_data[1]) / 1.2); //合成数据，即光照数据
    return 0;
}
/***************************************************************
 * 函数名称: LightStatusSet
 * 说    明: 灯状态设置
 * 参    数: status,ENUM枚举的数据
 *									OFF,光灯
 *									ON,开灯
 * 返 回 值: 无
 ***************************************************************/
void LightStatusSet(E53SC1Status status)
{
    if (status == ON) {
        IoTGpioSetOutputVal(7, 1); //设置GPIO_7输出高电平点亮LED灯
    }

    if (status == OFF) {
        IoTGpioSetOutputVal(7, 0); //设置GPIO_7输出低电平点亮LED灯
    }
}
