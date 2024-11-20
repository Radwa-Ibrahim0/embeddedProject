// temperature_sensor.c
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "temp.h"
#include "led.h"

// Initialize the temperature sensor and set up the ADC
void initializeTemperatureSensor()
{
    adc_gpio_init(TEMP_SENSOR_PIN);
    adc_select_input(1);
}

// Read the temperature value from the sensor
float readTemperature()
{
    uint16_t adcValue = adc_read(); // Read ADC value
    printf("Temp Level: %d\n", adcValue);
    return adcValue;
}

// Check the temperature and perform action if it exceeds the threshold
void checkTemperature(float temperature)
{
    if (temperature > TEMP_THRESHOLD)
    {
        printf("Warning: Temperature exceeded threshold! Current Temp: %.2f°C\n", temperature);
        turnOnTempLed();
    }
    else
    {
        turnOffTempLed();
    }
}
