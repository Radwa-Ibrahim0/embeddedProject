// temperature_sensor.c
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temp.h"
#include "led.h"

// Initialize the temperature sensor and set up the ADC
void initializeTemperatureSensor() {
    adc_init();
    adc_gpio_init(TEMP_SENSOR_PIN); 
}

// Read the temperature value from the sensor
float readTemperature() {
    adc_select_input(1);  // Select ADC input 1 (for GPIO 16)
    uint16_t adcValue = adc_read();  // Read ADC value
    printf("ADC Value: %d\n", adcValue);
    return adcValue;
}

// Check the temperature and perform action if it exceeds the threshold
void checkTemperature(float temperature) {
    if (temperature > TEMP_THRESHOLD) {
        printf("Warning: Temperature exceeded threshold! Current Temp: %.2f°C\n", temperature);
        turnOnTempLed();
    } else {
        turnOffTempLed();
    }
}
