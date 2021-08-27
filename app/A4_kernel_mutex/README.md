# BearPi-HM_Nano开发板OpnenHarmony内核编程开发——互斥锁
本示例将演示如何在BearPi-HM_Nano开发板上使用cmsis 2.0 接口使用互斥来同步任务


## Mutex API分析


### osMutexNew()

```c
osMutexId_t osMutexNew(const osMutexAttr_t *attr)
```
**描述：**

函数osMutexNew创建并初始化一个新的互斥锁对象，并返回指向互斥锁对象标识符的指针，如果出现错误则返回NULL可以在RTOS启动(调用 osKernelStart)之前安全地调用该函数，但不能在内核初始化 (调用 osKernelInitialize)之前调用该函数。
> **注意** :不能在中断服务调用该函数


**参数：**

|名字|描述|
|:--|:------| 
| attr |互斥对象的属性.  |

### osMutexAcquire()

```c
osStatus_t osMutexAcquire(osMutexId_t mutex_id,uint32_t timeout)
```
**描述：**
函数osMutexAcquire一直等待，直到参数mutex_id指定的互斥对象可用为止。如果没有其余线程获得互斥锁，该函数立即返回并阻塞互斥锁对象。

> **注意** :不能在中断服务调用该函数


**参数：**

|名字|描述|
|:--|:------| 
| mutex_id | 通过osMutexNew获得互斥锁ID.  |
| timeout | 超时值.  |

###  osMutexRelease()

```c
osStatus_t osMutexRelease(osMutexId_t mutex_id)
```
**描述：**
函数osMutexRelease释放一个由参数mutex_id指定的互斥量。当前等待这个互斥锁的其余线程将被置于就绪状态。

> **注意** :不能从中断服务例程调用此函数。


**参数：**

|名字|描述|
|:--|:------| 
| mutex_id | 通过osMutexNew获得互斥锁ID.  |


## 软件设计

**主要代码分析**

在MutexExample函数中，通过osMutexNew()函数创建了互斥锁ID，并创建的三个不同优先级的任务，在第一秒，高优先级和中优先级线程被延迟。因此，低优先级线程可以启动自己的工作，获得互斥锁并在持有它时延迟。在第一秒之后，高优先级和中优先级线程就准备好了。因此高优先级线程获得优先级并尝试获取互斥锁。因为互斥锁已经被低优先级线程所拥有，所以高优先级线程被阻塞，中间优先级线程被执行，并开始执行许多非阻塞的工作，3S后低优先级释放互斥锁，高优先级线程准备就绪并立即被调度。

```c
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
```

## 编译调试

### 修改 BUILD.gn 文件

修改 `applications\sample\bearpi_hm_nano\app`路径下 BUILD.gn 文件，指定 `mutex_example` 参与编译。

```r
#"A1_kernal_thread:thread_example",
#"A2_kernel_timer:timer_example",
#"A3_kernel_event:event_example",
"A4_kernel_mutex:mutex_example",
#"A5_kernel_semaphore:semaphore_example",
#"A6_kernel_message:message_example",
```
    


### 运行结果

示例代码编译烧录代码后，按下开发板的RESET按键，通过串口助手查看日志，中优先级任务一直正常运行，而高优先级和低优先级的任务因为互相抢占互斥锁，交替运行。
```c
LowPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
HighPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
LowPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
HighPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing.
MidPrioThread is runing
```
