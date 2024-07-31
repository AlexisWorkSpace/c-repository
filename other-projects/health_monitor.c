#include "sam.h"
#include <stdint.h>
#include <stdio.h>

// Definición de pines
#define TEMP_SENSOR_PIN   0 // Asignar al pin del sensor de temperatura
#define PULSE_SENSOR_PIN  1 // Asignar al pin del sensor de pulso

// Función para inicializar el sistema
void system_init(void) {
    // Configuración de los pines como entrada
    PORT->Group[0].DIRCLR.reg = (1 << TEMP_SENSOR_PIN) | (1 << PULSE_SENSOR_PIN);
    
    // Configuración de ADC
    ADC->CTRLA.bit.ENABLE = 1;  // Habilitar el ADC
    while (ADC->STATUS.bit.SYNCBUSY); // Esperar sincronización
}

// Función para leer el valor del ADC
uint16_t read_adc(uint8_t pin) {
    // Seleccionar canal
    ADC->INPUTCTRL.bit.MUXPOS = pin;
    while (ADC->STATUS.bit.SYNCBUSY); // Esperar sincronización
    
    // Iniciar conversión
    ADC->SWTRIG.bit.START = 1;
    while (!ADC->INTFLAG.bit.RESRDY); // Esperar a que la conversión esté lista
    
    // Leer el valor del ADC
    return ADC->RESULT.reg;
}

// Función para convertir el valor del ADC a temperatura (ejemplo simplificado)
float read_temperature(void) {
    uint16_t adc_value = read_adc(TEMP_SENSOR_PIN);
    // Convertir el valor del ADC a temperatura
    float temperature = (adc_value / 4095.0) * 100.0; // Ejemplo de conversión
    return temperature;
}

// Función para leer la frecuencia cardíaca (ejemplo simplificado)
int read_heart_rate(void) {
    uint16_t pulse_value = read_adc(PULSE_SENSOR_PIN);
    // Ejemplo simplificado: utilizar valor ADC directamente
    int heart_rate = pulse_value / 10; // Escalado simplificado
    return heart_rate;
}

int main(void) {
    // Inicializar el sistema
    system_init();
    
    while (1) {
        // Leer los datos del sensor
        float temperature = read_temperature();
        int heart_rate = read_heart_rate();
        
        // Imprimir o transmitir los datos (ejemplo simplificado con printf)
        printf("Temp: %.2f C, Heart Rate: %d BPM\n", temperature, heart_rate);
        
        // Agregar un retardo antes de la próxima lectura
        for (volatile int i = 0; i < 100000; i++);
    }
}
