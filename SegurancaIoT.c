#include <stdio.h>
#include "pico/stdlib.h"
#include "include/wifi_conn.h"
#include "include/mqtt_comm.h" 
#include "include/encrypt.h"    
#include <string.h>
#include <time.h>

#define WIFI_SSID "SSID"
#define WIFI_PASSWORD "Senha"
#define MQTT_ID "Bitdoglab"
#define MQTT_IP "Ip"
#define MQTT_USER "aluno"
#define MQTT_PASSWORD "senha123"
#define MQTT_SUBSCRIBE_TOPIC "escola/sala5/temperatura"
#define MQTT_PUBLISHER_TOPIC "escola/sala2/temperatura"

int main()
{

    messageStruct message;
    
    stdio_init_all();
    connect_to_wifi(WIFI_SSID, WIFI_PASSWORD);

    char buffer[128];

    mqtt_setup(MQTT_ID, MQTT_IP, MQTT_USER, MQTT_PASSWORD);
    mqtt_comm_subscribe(MQTT_SUBSCRIBE_TOPIC);
    while(1){
        sprintf(buffer, "{\"valor\":26.5,\"ts\":%lu}", time(NULL));;
        mqtt_comm_publish(MQTT_PUBLISHER_TOPIC,  buffer, strlen(buffer));
        sleep_ms(3000);
    }
}
