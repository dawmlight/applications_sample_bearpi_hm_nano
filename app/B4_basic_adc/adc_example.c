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

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "cmsis_os2.h"
#include "iot_adc.h"
#include "iot_errno.h"
#include "iot_gpio_ex.h"
#include "ohos_init.h"

#define ADC_TASK_STACK_SIZE 1024 * 8
#define ADC_TASK_PRIO 24

/**
 * @brief get ADC sampling value and convert it to voltage
 *
 */
static float GetVoltage(void)
{
    unsigned int ret;
    unsigned short data;

    ret = IoTAdcRead(5, &data, IOT_ADC_EQU_MODEL_8, IOT_ADC_CUR_BAIS_DEFAULT, 0xff);
    if (ret != IOT_SUCCESS) {
        printf("ADC Read Fail\n");
    }

    return (float)data * 1.8 * 4 / 4096.0;
}

/**
 * @brief Adc task get adc sampling voltage
 *
 */
static void AdcTask(void)
{
    float voltage;

    // set GPIO_11 to pull-up mode
    IoTGpioSetPull(11, IOT_GPIO_PULL_UP);
    while (1) {
        printf("=======================================\r\n");
        printf("***************ADC_example*************\r\n");
        printf("=======================================\r\n");

        // get adc sampling voltage
        voltage = GetVoltage();
        printf("vlt:%.3fV\n", voltage);

        // delay 1s
        usleep(1000000);
    }
}

/**
 * @brief Main Entry of the Adc Example
 *
 */
static void AdcExampleEntry(void)
{
    osThreadAttr_t attr;

    attr.name = "AdcTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = ADC_TASK_STACK_SIZE;
    attr.priority = ADC_TASK_PRIO;

    if (osThreadNew((osThreadFunc_t)AdcTask, NULL, &attr) == NULL) {
        printf("Failed to create AdcTask!\n");
    }
}

APP_FEATURE_INIT(AdcExampleEntry);