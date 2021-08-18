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

#include <stdio.h>

#include <unistd.h>

#include "cmsis_os2.h"
#include "iot_gpio.h"
#include "iot_gpio_ex.h"
#include "iot_pwm.h"
#include "ohos_init.h"

#define LED_GPIO 2

/**
 * @brief pwm task output PWM with different duty cycle
 *
 */
static void PwmTask(void)
{
    unsigned int i;

    // init gpio of LED
    IoTGpioInit(LED_GPIO);

    // set the GPIO_2 multiplexing function to PWM
    IoTGpioSetFunc(LED_GPIO, IOT_GPIO_FUNC_GPIO_2_PWM2_OUT);

    // set GPIO_2 is output mode
    IoTGpioSetDir(LED_GPIO, IOT_GPIO_DIR_OUT);

    // init PWM2
    IoTPwmInit(LED_GPIO);

    while (1) {
        for (i = 0; i < 100; i++) {
            // output PWM with different duty cycle
            IoTPwmStart(LED_GPIO, i, 40000);
            usleep(10);
        }
        i = 0;
    }
}

/**
 * @brief Main Entry of the Pwm Example
 *
 */
static void PwmExampleEntry(void)
{
    osThreadAttr_t attr;

    attr.name = "PwmTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 1024 * 4;
    attr.priority = 25;

    if (osThreadNew((osThreadFunc_t)PwmTask, NULL, &attr) == NULL) {
        printf("Failed to create PwmTask!\n");
    }
}

APP_FEATURE_INIT(PwmExampleEntry);