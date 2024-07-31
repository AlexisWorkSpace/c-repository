#include <asf.h>
#include <stdio.h>

// Definiciones de pines
#define PRESSURE_SENSOR_PIN  PIN_PA02 // Pin al que está conectado el sensor de presión
#define TEMPERATURE_SENSOR_PIN PIN_PA03 // Pin al que está conectado el sensor de temperatura
#define VIBRATION_SENSOR_PIN PIN_PA04 // Pin al que está conectado el sensor de vibración (acelerómetro)
#define ALARM_PIN            PIN_PA05 // Pin para controlar la alarma

// Límites seguros para los parámetros
#define MAX_PRESSURE 100.0 // Máxima presión permitida
#define MAX_TEMPERATURE 80.0 // Máxima temperatura permitida
#define MAX_VIBRATION 2.0 // Máxima vibración permitida (en g)

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

// Inicialización de ADC para leer los sensores
void configure_adc(void) {
    struct adc_config config_adc;
    adc_get_config_defaults(&config_adc);
    config_adc.resolution = ADC_RESOLUTION_12BIT;
    adc_init(ADC, &config_adc);
    adc_enable();
}

// Inicialización de pines de salida para la alarma
void configure_alarm(void) {
    ioport_set_pin_dir(ALARM_PIN, IOPORT_DIR_OUTPUT);
}

// Función para leer el valor del sensor
uint16_t read_sensor(uint32_t sensor_pin) {
    adc_set_positive_input(ADC, sensor_pin);
    adc_start_conversion(ADC);
    while (adc_get_status(ADC) != ADC_STATUS_RESULT_READY);
    return adc_get_result(ADC);
}

// Función para activar/desactivar la alarma
void control_alarm(bool state) {
    if (state) {
        ioport_set_pin_level(ALARM_PIN, IOPORT_PIN_LEVEL_HIGH);
    } else {
        ioport_set_pin_level(ALARM_PIN, IOPORT_PIN_LEVEL_LOW);
    }
}

int main(void) {
    // Inicialización del sistema
    sysclk_init();
    board_init();
    configure_console();
    configure_adc();
    configure_alarm();

    uint16_t pressure_value;
    uint16_t temperature_value;
    uint16_t vibration_value;
    float pressure;
    float temperature;
    float vibration;

    while (1) {
        // Leer los sensores
        pressure_value = read_sensor(PRESSURE_SENSOR_PIN);
        temperature_value = read_sensor(TEMPERATURE_SENSOR_PIN);
        vibration_value = read_sensor(VIBRATION_SENSOR_PIN);

        // Convertir los valores leídos a unidades físicas
        pressure = (pressure_value / 4096.0) * 150.0; // Ejemplo de conversión a presión
        temperature = (temperature_value / 4096.0) * 100.0; // Ejemplo de conversión a temperatura
        vibration = (vibration_value / 4096.0) * 3.3; // Ejemplo de conversión a vibración (en g)

        // Imprimir los valores leídos en la consola UART
        printf("Presión: %.2f kPa, Temperatura: %.2f °C, Vibración: %.2f g\n", pressure, temperature, vibration);

        // Verificar si algún parámetro excede los límites seguros
        if (pressure > MAX_PRESSURE || temperature > MAX_TEMPERATURE || vibration > MAX_VIBRATION) {
            control_alarm(true); // Activar la alarma
        } else {
            control_alarm(false); // Desactivar la alarma
        }

        // Esperar 1 segundo antes de la siguiente lectura
        delay_s(1);
    }
}
