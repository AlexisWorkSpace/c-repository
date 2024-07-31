#include <asf.h>
#include <stdio.h>
#include "dht22.h"

// Definiciones de pines
#define FAN_RELAY_PIN     PIN_PA02 // Pin para controlar el relé del ventilador
#define WATER_RELAY_PIN   PIN_PA03 // Pin para controlar el relé del sistema de riego
#define DHT22_PIN         PIN_PA04 // Pin al que está conectado el sensor DHT22

// Inicialización de UART para depuración
void configure_console(void) {
    const usart_serial_options_t uart_serial_options = {
        .baudrate = 115200,
        .charlength = US_MR_CHRL_8_BIT,
        .paritytype = US_MR_PAR_NO,
        .stopbits = US_MR_NBSTOP_1
    };
    stdio_serial_init(CONF_UART, &uart_serial_options);
    setbuf(stdout, NULL);
}

// Inicialización de pines de salida para los relés
void configure_relays(void) {
    ioport_set_pin_dir(FAN_RELAY_PIN, IOPORT_DIR_OUTPUT);
    ioport_set_pin_dir(WATER_RELAY_PIN, IOPORT_DIR_OUTPUT);
}

// Función para controlar los relés
void control_relay(uint32_t pin, bool state) {
    if (state) {
        ioport_set_pin_level(pin, IOPORT_PIN_LEVEL_HIGH);
    } else {
        ioport_set_pin_level(pin, IOPORT_PIN_LEVEL_LOW);
    }
}

int main(void) {
    // Inicialización del sistema
    sysclk_init();
    board_init();
    configure_console();
    configure_relays();
    dht22_init(DHT22_PIN);

    float temperature;
    float humidity;

    while (1) {
        // Leer el sensor DHT22
        if (dht22_read(&temperature, &humidity) == DHT22_OK) {
            // Imprimir los valores leídos en la consola UART
            printf("Temperatura: %.2f C, Humedad: %.2f %%\n", temperature, humidity);

            // Controlar el ventilador según la temperatura
            if (temperature > 25.0) {
                control_relay(FAN_RELAY_PIN, true);
            } else {
                control_relay(FAN_RELAY_PIN, false);
            }

            // Controlar el sistema de riego según la humedad
            if (humidity < 40.0) {
                control_relay(WATER_RELAY_PIN, true);
            } else {
                control_relay(WATER_RELAY_PIN, false);
            }
        } else {
            printf("Error al leer el sensor DHT22\n");
        }

        // Esperar 2 segundos antes de la siguiente lectura
        delay_s(2);
    }
}
