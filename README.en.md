# BearPi-HM_Nano_APP<a name="EN-US_TOPIC_0000001132694217"></a>

-   [Introduction](#section11660541593)
-   [Directory Structure](#section1464106163817)
-   [Repositories Involved](#section1718733212019)

## Introduction<a name="section11660541593"></a>

BearPi-HM_Nano provides up to 29 routines. Each routine has very detailed comments. The code style is unified. It is arranged from basic routines to advanced routines, which is convenient for beginners to learn step by step from shallow to deep. After getting the project, the developer can see the experimental phenomenon through simple compilation and download.

These routines include four categories: kernel class, basic peripheral class, driver class and Internet of things class. It not only includes the application of hardware resources, but also provides rich application examples in the field of Internet of things to help Internet of things developers develop better and faster.

The list of routines is as follows:

| NO | category   | name           | illustrate                                                         |
| ---- | ------ | ---------------- | ------------------------------------------------------------ |
| A1   | kernel  | thread           |   [task alternate printing](app/A1_kernal_thread/README.md)  |
| A2   | kernel  | timer            |  [timer  ](app/A2_kernel_timer/README.md)                                                      |
| A3   | kernel  | event            |   [event](app/A3_kernel_event/README.md)|
| A4   | kernel  | mutex            |   [mutex](app/A4_kernel_mutex/README.md)|
| A5   | kernel  | semp             |   [semp](app/A5_kernel_semaphore/README.md)|
| A6   | kernel  | message           |    [message queue](app/A6_kernel_message/README.md)|
| B1   | basic  | led_blink        |   [ LED flashes continuously](app/B1_basic_led_blink/README.md)|
| B2   | basic  | button           |   [key control LED light on and off](app/B2_basic_button/README.md)|
| B3   | basic  | pwm_led          |   [Led breathing lamp](app/B3_basic_pwm_led/README.md)|
| B4   | basic  | adc_mq2          |   [ADC read voltage](app/B4_basic_adc/README.md)|
| B5   | basic  | i2c_bh1750       |   [I2C reads NFC Tags](app/B5_basic_i2c_nfc/README.md)|
| B6   | basic  | basic_uart       |   [UART spontaneous self collection](app/B6_basic_uart/README.md)|
| C1   | sensor   | e53_sf1_example        |       [smoke sensor MQ2](app/C1_e53_sf1_mq2/README.md)|
| C2   | sensor   | e53_ia1_example              |   [Temperature and humidity sensor SHT30](app/C2_e53_ia1_temp_humi_pls/README.md)|
| C3   | sensor   | e53_sc1_example             |   [Light intensity sensor BH1750](app/C3_e53_sc1_pls/README.md)|
| C4   | sensor   | e53_sc2_example        |   [6-axis gyroscope MPU6050](app/C4_e53_sc2_axis/README.md)|
| C5   | sensor   | e53_is1_example              |   [Human infrared induction sensor](app/C5_e53_is1_infrared/README.md)|
| D1   | IoT | iot_wifi_ap        |   [WiFi hotspot creation](app/D1_iot_wifi_ap/README.md)|
| D2   | IoT | iot_wifi_sta_connect    |   [WiFi STA](app/D2_iot_wifi_sta_connect/README.md)|
| D3   | IoT | udp_client       |   [Using socket to implement UDP client](app/D3_iot_udp_client/README.md)|
| D4   | IoT | tcp_server       |   [Using socket to implement TCP server](app/D4_iot_tcp_server/README.md)|
| D5   | IoT | iot_mqtt             |   [Using Paho-MQTTsoftware package to realize mqtt protocol communication](app/D5_iot_mqtt/README.md)|
| D6   | IoT | iot_cloud_oc_sample     |  [Access to Huawei IOT cloud platform](app/D6_iot_cloud_oc/README.md)|
| D7   | IoT | iot_cloud_oc_smoke         |   [Smart smoke detection case based on Huawei IOT platform](app/D8_iot_cloud_oc_smoke/README.md)|  
| D8   | IoT | iot_cloud_oc_light         |   [Smart street lamp case based on Huawei IOT platform](app/D9_iot_cloud_oc_light/README.md)|    
| D9   | IoT | iot_cloud_oc_manhole_cover         |   [Smart manhole cover case based on Huawei IOT platform](app/D10_iot_cloud_oc_manhole_cover/README.md)|  
| D10   | IoT | iot_cloud_oc_infrared         |   [Smart human sensing case based on Huawei IOT platform](app/D11_iot_cloud_oc_infrared/README.md)|  
| D11   | IoT | iot_cloud_oc_agriculture         |   [Smart agriculture case based on Huawei IOT platform](app/D12_iot_cloud_oc_agriculture/README.md)| 
| D12   | IoT | iot_cloud_oc_gps         |   [Smart logistics case based on Huawei IOT platform](app/D13_iot_cloud_oc_gps/README.md)|    
||||

## Directory Structure<a name="section1464106163817"></a>

```
applications/sample/bearpi_hm_nano/      # Sample code    

└── app         //Sample code  
└── docs        //doc
```

## Repositories Involved<a name="section1718733212019"></a>

applications_sample_bearpi_hm_nano


