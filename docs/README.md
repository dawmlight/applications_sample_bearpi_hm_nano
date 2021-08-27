### 资料导航
| No | 类别 | 路径  |
| :----: | ---- |  ------------------------------------------------------------ |
| 1    | 开发板硬件资料 | [docs/board](board) |
| 2    | 快速上手教程 |  [docs/quick-start](quick-start/BearPi-HM_Nano十分钟上手.md) |
| 3    | 案例代码列表 |  [app](../app/README.md) |
| 4    | 视频学习地址 |  [B站](https://www.bilibili.com/video/BV1tv411b7SA?p=1) |
| 5    | 视频课程PPT |  [docs/board/课程配套PPT](board/%E8%AF%BE%E7%A8%8B%E9%85%8D%E5%A5%97PPT) |

## 一、BearPi-HM Nano 开发板介绍

小熊派·季[（BearPi-HM Nano）](https://item.taobao.com/item.htm?id=633296694816)是一款由小熊派专为OpenHarmony系统打造的开发板。

* 采用IoTCluB的E53接口标准，可接入所有的[E53案例扩展板](https://shop336827451.taobao.com/category-1488778768.htm)。
* 主控为WiFi SOC Hi3861，160MHz主频，SRAM 352KB、ROM 288KB、2M Flash。
* 板载NFC Forum Type 2 Tag芯片及天线，可实现OpenHarmony“碰一碰”功能。
* 一根TypeC USB线，即可实现供电、下载、调试等多种功能。


## 二、快速上手（十分钟上手）

如果您想快速的体验一下OpenHarmony的源码`[获取]`、`[编译]`、`[烧录]`过程，强烈建议您学习以下教程，这能让您在环境安装环节省下不少时间。


1、文档（Gitee）
* [VMware 镜像版本：十分钟上手体验](quick-start/BearPi-HM_Nano十分钟上手.md)

## 三、手把手教程系列

如果您想学习OpenHarmony系统的环境搭建，并想了解整个从0到1的过程，建议您跟着教程一步一步的学习。
需要告诉您的是，OpenHarmony系统的环境搭建所涉及的领域及组件会比较多，您需要严格按照教程执行每一步，否则可能会出现不能预知的错误。

**注：视频教程根据OpenHarmony 1.0.0版本录制，1.1.0版本后一些接口名字做了修改。开发者请灵活变通。**

1、视频系列（B站）[ 对应PPT地址 ](board/课程配套PPT)
* [P1. BearPi-HM Nano开发板介绍](https://www.bilibili.com/video/BV1tv411b7SA?p=1)
* [P2. 开发环境搭建(复杂)—编译环境搭建](https://www.bilibili.com/video/BV1tv411b7SA?p=3)
* [P3. 开发环境搭建(复杂)—源码获取](https://www.bilibili.com/video/BV1tv411b7SA?p=4)
* [P4. 开发环境搭建(复杂)—在Windows上打开源码](https://www.bilibili.com/video/BV1tv411b7SA?p=5)
* [P5. OpenHarmony快速入门：Hello_World](https://www.bilibili.com/video/BV1tv411b7SA?p=6)
* [P6. OpenHarmony快速入门：点亮LED](https://www.bilibili.com/video/BV1tv411b7SA?p=7)
* [P7. OpenHarmony编译构建介绍](https://www.bilibili.com/video/BV1tv411b7SA?p=8)
* [P8. OpenHarmony CMSIS接口简介](https://www.bilibili.com/video/BV1tv411b7SA?p=9)
* [P9. OpenHarmony内核开发—任务管理（上）](https://www.bilibili.com/video/BV1tv411b7SA?p=10)
* [P10. OpenHarmony内核开发—任务管理（下）](https://www.bilibili.com/video/BV1tv411b7SA?p=11)
* [P11. OpenHarmony内核开发—软件定时器](https://www.bilibili.com/video/BV1tv411b7SA?p=12)
* [P12. OpenHarmony内核开发—信号量](https://www.bilibili.com/video/BV1tv411b7SA?p=13)
* [P13. OpenHarmony内核开发—事件管理](https://www.bilibili.com/video/BV1tv411b7SA?p=14)
* [P14. OpenHarmony内核开发—互斥锁](https://www.bilibili.com/video/BV1tv411b7SA?p=15)
* [P15. OpenHarmony内核开发—消息队列](https://www.bilibili.com/video/BV1tv411b7SA?p=16)
* [P16. OpenHarmony驱动子系统开发—GPIO](https://www.bilibili.com/video/BV1tv411b7SA?p=17)
* [P17. OpenHarmony驱动子系统开发—GPIO中断](https://www.bilibili.com/video/BV1tv411b7SA?p=19)
* [P18. OpenHarmony驱动子系统开发—PWM](https://www.bilibili.com/video/BV1tv411b7SA?p=19)
* [P19. OpenHarmony驱动子系统开发—ADC](https://www.bilibili.com/video/BV1tv411b7SA?p=20)
* [P20. OpenHarmony驱动子系统开发—I2C](https://www.bilibili.com/video/BV1tv411b7SA?p=21)
* [P21. OpenHarmony驱动子系统开发—UART](https://www.bilibili.com/video/BV1tv411b7SA?p=22)
* [P22. OpenHarmony无线联网开发—WiFi AP热点](https://www.bilibili.com/video/BV1tv411b7SA?p=23)
* [P23. OpenHarmony无线联网开发—WiFi STA联网](https://www.bilibili.com/video/BV1tv411b7SA?p=24)
* [P24. OpenHarmony网络应用开发—UDP客户端](https://www.bilibili.com/video/BV1tv411b7SA?p=25)
* [P25. OpenHarmony网络应用开发—TCP服务端](https://www.bilibili.com/video/BV1tv411b7SA?p=26)
* [P26. OpenHarmony网络应用开发—TCP客户端](https://www.bilibili.com/video/BV1tv411b7SA?p=27)
* [P27. OpenHarmony网络应用开发—UDP服务端](https://www.bilibili.com/video/BV1tv411b7SA?p=28)
* [P28. OpenHarmony网络应用开发—MQTT客户端](https://www.bilibili.com/video/BV1tv411b7SA?p=29)
* [P29. OpenHarmony网络应用开发—对接华为IoT平台](https://www.bilibili.com/video/BV1tv411b7SA?p=30)
* [P30. OpenHarmony网络应用开发—对接OneNET平台](https://www.bilibili.com/video/BV1tv411b7SA?p=31)
* [更多: 陆续上传中...](https://www.bilibili.com/video/BV1tv411b7SA)

2、文档系列（Gitee）
-   [BearPi-HM_Nano 开发板介绍](quick-start/BearPi-HM_Nano开发板介绍.md)
-   [BearPi-HM_Nano 开发搭建环境](quick-start/BearPi-HM_Nano开发搭建环境.md)
-   [BearPi-HM_Nano 开发板源码获取](quick-start/源码获取.md)
-   [BearPi-HM_Nano 开发板如何烧录程序](quick-start/BearPi-HM_Nano开发板如何烧录程序.md)
-   [BearPi-HM_Nano 开发第一个示例程序](quick-start/BearPi-HM_Nano开发板第一个示例程序.md)
-   [BearPi-HM_Nano 案例开发](../app/README.md)


## 四、BearPi-HM_Nano 案例开发

BearPi-HM Nano提供多个案例，案例以A、B、C、D进行不同类别进行分级，方便初学者由浅入深逐步学习。您拿到工程后经过简单的编程和下载即可看到实验现象。下面依次对A/B/C/D类进行介绍：

* `A1 - A99`：内核类
* `B1 - B99`：基础外设类
* `C1 - C99`：E53传感器类
* `D1 - D99`：物联网类

例程列表如下所示：

| 编号 | 类别   | 例程名           | 说明                                                         |
| ---- | ------ | ---------------- | ------------------------------------------------------------ |
| A1   | 内核   | thread           |   [任务交替打印](../app/A1_kernal_thread/README.md)  |
| A2   | 内核   | timer            |  [定时器  ](../app/A2_kernel_timer/README.md)                                                      |
| A3   | 内核   | event            |   [事件](../app/A3_kernel_event/README.md)|
| A4   | 内核   | mutex            |   [互斥锁](../app/A4_kernel_mutex/README.md)|
| A5   | 内核   | semp             |   [信号量](../app/A5_kernel_semaphore/README.md)|
| A6   | 内核   | message           |    [消息队列](../app/A6_kernel_message/README.md)|
| B1   | 基础   | led_blink        |   [红色 LED 不间断烁](../app/B1_basic_led_blink/README.md)|
| B2   | 基础   | button           |   [按键控制LED灯亮灭](../app/B2_basic_button/README.md)|
| B3   | 基础   | pwm_led          |   [红色 LED 呼吸灯](../app/B3_basic_pwm_led/README.md)|
| B4   | 基础   | adc_mq2          |   [ADC读取电压](../app/B4_basic_adc/README.md)|
| B5   | 基础   | i2c_bh1750       |   [I2C读取NFC标签](../app/B5_basic_i2c_nfc/README.md)|
| B6   | 基础   | basic_uart       |   [UART自发自收](../app/B6_basic_uart/README.md)|
| C1   | E53传感器   | e53_sf1_example        |       [驱动烟雾传感器 MQ2](../app/C1_e53_sf1_mq2/README.md)|
| C2   | E53传感器   | e53_ia1_example              |   [驱动温湿度传感器 SHT30](../app/C2_e53_ia1_temp_humi_pls/README.md)|
| C3   | E53传感器   | e53_sc1_example             |   [驱动光强传感器 BH1750](../app/C3_e53_sc1_pls/README.md)|
| C4   | E53传感器   | e53_sc2_example        |   [驱动 6 轴陀螺仪 MPU6050](../app/C4_e53_sc2_axis/README.md)|
| C5   | E53传感器   | e53_is1_example              |   [驱动人体红外传感器](../app/C5_e53_is1_infrared/README.md)|
| D1   | 物联网 | iot_wifi_ap       |   [Wifi热点创建](../app/D1_iot_wifi_ap/README.md)|
| D2   | 物联网 | iot_wifi_sta_connect     |   [Wifi联网](../app/D2_iot_wifi_sta_connect/README.md)|
| D3   | 物联网 | udp_client       |   [使用 Socket 实现 UDP 客户端](../app/D3_iot_udp_client/README.md)|
| D4   | 物联网 | tcp_server       |   [使用 Socket 实现 TCP 服务端](../app/D4_iot_tcp_server/README.md)|
| D5   | 物联网 | iot_mqtt             |   [使用 Paho-MQTT 软件包实现 MQTT 协议通信](../app/D5_iot_mqtt/README.md)|
| D6   | 物联网 | iot_cloud_oc_sample     |  [接入华为IoT 云平台](../app/D6_iot_cloud_oc/README.md)|
| D7   | 物联网 | iot_cloud_oc_smoke         |   [基于华为IoT平台的智慧烟感案例](../app/D7_iot_cloud_oc_smoke/README.md)|  
| D8   | 物联网 | iot_cloud_oc_light         |   [基于华为IoT平台的智慧路灯案例](../app/D8_iot_cloud_oc_light/README.md)|    
| D9   | 物联网 | iot_cloud_oc_manhole_cover         |   [基于华为IoT平台的智慧井盖案例](../app/D9_iot_cloud_oc_manhole_cover/README.md)|  
| D10   | 物联网 | iot_cloud_oc_infrared         |   [基于华为IoT平台的智慧人体感应案例](../app/D10_iot_cloud_oc_infrared/README.md)|  
| D11   | 物联网 | iot_cloud_oc_agriculture         |   [基于华为IoT平台的智慧农业案例](../app/D11_iot_cloud_oc_agriculture/README.md)| 
| D12   | 物联网 | iot_cloud_oc_gps         |   [基于华为IoT平台的智慧物流案例](../app/D12_iot_cloud_oc_gps/README.md)|    
||||




## 五、开发板图片预览[（淘宝链接）](https://item.taobao.com/item.htm?id=633296694816)

[![](figures/00_public/BearPi-HM_Nano_Info.png)](https://item.taobao.com/item.htm?id=633296694816)


## 六、联系我们



![](figures/00_public/bearpi_club_wechat.jpg)

