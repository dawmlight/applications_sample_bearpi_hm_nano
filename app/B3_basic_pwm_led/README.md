# BearPi-HM_Nano开发板基础外设开发——PWM输出
本示例将演示如何在BearPi-HM_Nano开发板上使用GPIO的PWM功能实现呼吸灯的效果

![BearPi-HM_Nano](../../docs/figures/00_public/BearPi-HM_Nano.png)
## PWM API分析
本案例主要使用了以下几个API完成PWM功能实现呼吸灯功能
### IoTGpioInit()
```c
unsigned int IoTGpioInit(unsigned int id);
```
 **描述：**

初始化GPIO外设
### IoTGpioSetFunc()
```c
unsigned int IoTGpioSetFunc(unsigned int id, unsigned char val);
```
**描述：**

设置GPIO引脚复用功能

**参数：**

|名字|描述|
|:--|:------| 
| id | 表示GPIO引脚号.  |
| val | 表示GPIO复用功能 |

### IoTGpioSetDir()
```c
unsigned int IoTGpioSetDir(unsigned int id, IotGpioDir dir);
```
**描述：**

设置GPIO输出方向

**参数：**

|名字|描述|
|:--|:------| 
| id | 表示GPIO引脚号.  |
| dir | 表示GPIO输出方向.  |


### IoTPwmInit()
```c
unsigned int IoTPwmInit(unsigned int port);
```
**描述：**
初始化PWM功能

**参数：**

|名字|描述|
|:--|:------| 
| port | 表示PWM设备端口号.  |



## IoTPwmStart()
```c
unsigned int IoTPwmStart(unsigned int port, unsigned short duty, unsigned int freq);
```
**描述：**

根据输入参数输出PWM信号。

**参数：**

|名字|描述|
|:--|:------| 
| port | PWM端口号.  |
| duty| 占空比.  |
| freq| 分频倍数.  |


## 硬件设计
本案例将使用板载的LED来验证GPIO的PWM功能，在BearPi-HM_Nano开发板上LED的连接电路图如下图所示，LED的控制引脚与主控芯片的GPIO_2连接，所以需要编写软件去控制GPIO_2输出PWM波实现呼吸灯的效果。

![](../../docs/figures/B3_basic_pwm_led/LED灯电路.png "LED灯电路")

## 软件设计

**主要代码分析**

PWMTask()为PWM测试主任务，该任务先调用 IoTGpioInit()初始化GPIO，因为LED灯的控制引脚接在GPIO_2上，所以通过调用IoTGpioSetFunc()将GPIO_2复用为PWM功能，并通过IoTPwmInit()初始化PWM2端口，最后在死循环里面间隔10us输出不同占空比的PWM波，实现呼吸灯的效果
```c
/**
 * @brief pwm task output PWM with different duty cycle
 * 
 */
static void PwmTask(void)
{
    unsigned int i;

    //init gpio of LED
    IoTGpioInit(LED_GPIO);

    //set the GPIO_2 multiplexing function to PWM
    IoTGpioSetFunc(LED_GPIO, IOT_GPIO_FUNC_GPIO_2_PWM2_OUT);

    //set GPIO_2 is output mode
    IoTGpioSetDir(LED_GPIO, IOT_GPIO_DIR_OUT);

    //init PWM2 
    IoTPwmInit(LED_GPIO);

    while (1) {
        for (i = 0; i < 100; i ++)
        {
            //output PWM with different duty cycle
            IoTPwmStart(LED_GPIO, i, 40000);
            usleep(10);
        }
        i = 0;
    }
}
```

## 编译调试

### 修改 BUILD.gn 文件


修改`applications\sample\bearpi_hm_nano\app` 路径下 BUILD.gn 文件，指定 `pwm_example` 参与编译。

```r
#"B1_basic_led_blink:led_example",
#"B2_basic_button:button_example",
"B3_basic_pwm_led:pwm_example",
#"B4_basic_adc:adc_example",
#"B5_basic_i2c_nfc:i2c_example",
#"B6_basic_uart:uart_example",
```     


### 运行结果

示例代码编译烧录代码后，按下开发板的RESET按键，开发板开始正常工作，LED开始不断变化亮度，实现呼吸灯的效果。

