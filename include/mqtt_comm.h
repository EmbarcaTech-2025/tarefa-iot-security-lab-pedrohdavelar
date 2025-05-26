#ifndef MQTT_COMM_H
#define MQTT_COMM_H

#include <stdint.h>
#include <stddef.h>
#include <string.h>



typedef struct Message {
    char message[128];
    char topic[128];
} messageStruct;


/**
 * @brief Sets up the MQTT client and connects to the broker
 * 
 * @param client_id Unique identifier for this client
 * @param broker_ip Broker IP address as string (e.g., "192.168.1.1")
 * @param user Username for authentication (can be NULL)
 * @param pass Password for authentication (can be NULL)
 */
void mqtt_setup(const char *client_id, const char *broker_ip, const char *user, const char *pass);

/**
 * @brief Publishes data to an MQTT topic
 * 
 * @param topic Topic name (e.g., "sensor/temperature")
 * @param data Message payload (bytes)
 * @param len Payload length
 */
void mqtt_comm_publish(const char *topic, const uint8_t *data, size_t len);

/**
 * @brief Inscreve o cliente MQTT em um tópico.
 *
 * Registra os callbacks para mensagens recebidas e realiza a inscrição no tópico fornecido.
 * A recepção de dados será tratada pelos callbacks internos definidos no arquivo .c.
 *
 * @param topic Nome do tópico MQTT para inscrição (por exemplo: "sensor/comando").
 */
void mqtt_comm_subscribe(const char *topic);


messageStruct get_message();

#endif // MQTT_COMM_H