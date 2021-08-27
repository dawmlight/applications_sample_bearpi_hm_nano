# BearPi-HM_Nano_APP组件<a name="ZH-CN_TOPIC_0000001132694217"></a>

-   [简介](#section11660541593)
-   [目录](#section1464106163817)
-   [涉及仓](#section1718733212019)

## 简介<a name="section11660541593"></a>

BearPi-HM_Nano 提供的例程多达 29个，每个例程都有非常详细的注释，代码风格统一，按照基本例程到高级例程的方式编排，方便初学者由浅入深逐步学习。开发者拿到工程后经过简单的编译和下载即可看到实验现象。

这些例程包括四个类别：内核类、基本外设类、驱动类、物联网类。不仅包括了硬件资源的应用，更是提供了丰富的物联网领域的应用示例，帮助物联网开发者更好更快地进行开发。

例程列表如下所示：

| 编号 | 类别   | 例程名           | 说明                                                         |
| ---- | ------ | ---------------- | ------------------------------------------------------------ |
| A1   | 内核   | thread           |   [任务交替打印](app/A1_kernal_thread/README.md)  |
| A2   | 内核   | timer            |  [定时器  ](app/A2_kernel_timer/README.md)                                                      |
| A3   | 内核   | event            |   [事件](app/A3_kernel_event/README.md)|
| A4   | 内核   | mutex            |   [互斥锁](app/A4_kernel_mutex/README.md)|
| A5   | 内核   | semp             |   [信号量](app/A5_kernel_semaphore/README.md)|
| A6   | 内核   | message           |    [消息队列](app/A6_kernel_message/README.md)|
| B1   | 基础   | led_blink        |   [LED 不间断烁](app/B1_basic_led_blink/README.md)|
| B2   | 基础   | button           |   [按键控制LED灯亮灭](app/B2_basic_button/README.md)|
| B3   | 基础   | pwm_led          |   [LED 呼吸灯](app/B3_basic_pwm_led/README.md)|
| B4   | 基础   | adc_mq2          |   [ADC读取电压](app/B4_basic_adc/README.md)|
| B5   | 基础   | i2c_bh1750       |   [I2C读取NFC标签](app/B5_basic_i2c_nfc/README.md)|
| B6   | 基础   | basic_uart       |   [UART自发自收](app/B6_basic_uart/README.md)|
| C1   | E53传感器   | e53_sf1_example        |       [驱动烟雾传感器 MQ2](app/C1_e53_sf1_mq2/README.md)|
| C2   | E53传感器   | e53_ia1_example              |   [驱动温湿度传感器 SHT30](app/C2_e53_ia1_temp_humi_pls/README.md)|
| C3   | E53传感器   | e53_sc1_example             |   [驱动光强传感器 BH1750](app/C3_e53_sc1_pls/README.md)|
| C4   | E53传感器   | e53_sc2_example        |   [驱动 6 轴陀螺仪 MPU6050](app/C4_e53_sc2_axis/README.md)|
| C5   | E53传感器   | e53_is1_example              |   [驱动人体红外传感器](app/C5_e53_is1_infrared/README.md)|
| D1   | 物联网 | iot_wifi_ap        |   [Wifi热点创建](app/D1_iot_wifi_ap/README.md)|
| D2   | 物联网 | iot_wifi_sta_connect    |   [Wifi联网](app/D2_iot_wifi_sta_connect/README.md)|
| D3   | 物联网 | udp_client       |   [使用 Socket 实现 UDP 客户端](app/D3_iot_udp_client/README.md)|
| D4   | 物联网 | tcp_server       |   [使用 Socket 实现 TCP 服务端](app/D4_iot_tcp_server/README.md)|
| D5   | 物联网 | iot_mqtt             |   [使用 Paho-MQTT 软件包实现 MQTT 协议通信](app/D5_iot_mqtt/README.md)|
| D6   | 物联网 | iot_cloud_oc_sample     |  [接入华为IoT 云平台](app/D6_iot_cloud_oc/README.md)|
| D7   | 物联网 | iot_cloud_oc_smoke         |   [基于华为IoT平台的智慧烟感案例](app/D8_iot_cloud_oc_smoke/README.md)|  
| D8   | 物联网 | iot_cloud_oc_light         |   [基于华为IoT平台的智慧路灯案例](app/D9_iot_cloud_oc_light/README.md)|    
| D9   | 物联网 | iot_cloud_oc_manhole_cover         |   [基于华为IoT平台的智慧井盖案例](app/D10_iot_cloud_oc_manhole_cover/README.md)|  
| D10   | 物联网 | iot_cloud_oc_infrared         |   [基于华为IoT平台的智慧人体感应案例](app/D11_iot_cloud_oc_infrared/README.md)|  
| D11   | 物联网 | iot_cloud_oc_agriculture         |   [基于华为IoT平台的智慧农业案例](app/D12_iot_cloud_oc_agriculture/README.md)| 
| D12   | 物联网 | iot_cloud_oc_gps         |   [基于华为IoT平台的智慧物流案例](app/D13_iot_cloud_oc_gps/README.md)|    
||||

## 目录<a name="section1464106163817"></a>

```
applications/sample/bearpi_hm_nano/    # bearpi_hm_nano模块目录  

└── app         //示例代码
└── docs        //教程文档
```

## 涉及仓<a name="section1718733212019"></a>

applications_sample_bearpi_hm_nano

