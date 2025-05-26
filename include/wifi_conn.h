#ifndef WIFI_CONN_H
#define WIFI_CONN_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Conecta o Raspberry Pi Pico W a uma rede Wi-Fi.
 *
 * Inicializa o chip Wi-Fi e tenta conectar à rede especificada pelo SSID e senha.
 *
 * @param ssid Nome da rede Wi-Fi (SSID)
 * @param password Senha da rede Wi-Fi
 */
void connect_to_wifi(const char *ssid, const char *password);

#ifdef __cplusplus
}
#endif

#endif // WIFI_CONN_H
