#define IO_USERNAME  "Angie2002"
#define IO_KEY       "aio_UvXm381hxTwTIz08ln4tZMVTFwLK"

//RED DEL WIFI
#define WIFI_SSID "HUAWEI"
#define WIFI_PASS "1121RAG31"

#include "AdafruitIO_Wifi.h"

#if defined(USE_AIRLIFT) || defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE) ||
    defined(ADAFRUIT_PYPORTAL)

//configurar los pins usados para el ESP32 concexión
#if !defined(SPIWIFI_SS) //if the wifi definition isnt in board variant

#define SPIWIFI SPI
#define SPIWIFI_SS 10 //chip select pin
#define SPIWIFI_ACK 9 //a.k.a BUSY or READY pin
#define ESP32_RESETN 6 //RESET pin
#define ESP32_GPIO0 -1 //Not connected
#endif
Adafruit_wifi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS, SPIWIFI_ss,
                 SPIWIFI_ACK,ESP32_RESETN,ESP32_GPIO0, &SPIWIFI);
