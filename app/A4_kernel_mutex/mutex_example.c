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
#include <string.h>
#include <unistd.h>

#include "cmsis_os2.h"
#include "ohos_init.h"

osMutexId_t g_mutexId;

void HighPrioThread(void)
{
    // wait 1s until start actual work
    osDelay(100);

    while (1) {
        // try to acquire mutex
        osMutexAcquire(g_mutexId, osWaitForever);

        printf("HighPrioThread is running.\n");
        osDelay(300);
        osMutexRelease(g_mutexId);
    }
}

void MidPrioThread(void)
{
    // wait 1s until start actual work
    osDelay(100);

    while (1) {
        printf("MidPrioThread is running.\n");
        osDelay(100);
    }
}

void LowPrioThread(void)
{
    while (1) {
        osMutexAcquire(g_mutexId, osWaitForever);
        printf("LowPrioThread is running.\n");

        // block mutex for 3s
        osDelay(300);
        osMutexRelease(g_mutexId);
    }
}

/**
 * @brief Main Entry of the Mutex Example
 *
 */
void MutexExample(void)
{
    osThreadAttr_t attr;

    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
    attr.stack_size = 1024 * 4;

    attr.name = "HighPrioThread";
    attr.priority = 24;
    if (osThreadNew((osThreadFunc_t)HighPrioThread, NULL, &attr) == NULL) {
        printf("Failed to create HighPrioThread!\n");
    }

    attr.name = "MidPrioThread";
    attr.priority = 25;
    if (osThreadNew((osThreadFunc_t)MidPrioThread, NULL, &attr) == NULL) {
        printf("Failed to create MidPrioThread!\n");
    }

    attr.name = "LowPrioThread";
    attr.priority = 26;
    if (osThreadNew((osThreadFunc_t)LowPrioThread, NULL, &attr) == NULL) {
        printf("Failed to create LowPrioThread!\n");
    }

    g_mutexId = osMutexNew(NULL);
    if (g_mutexId == NULL) {
        printf("Failed to create Mutex!\n");
    }
}
APP_FEATURE_INIT(MutexExample);
