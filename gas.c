// gas_detector.c
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "gas.h"
#include "buzzer.h"
#include "led.h"

// Initialize pins and indicate system start-up with LED blink
void initializeGasDetector()
{
    // Initialize ADC for reading the analog sensor
    adc_gpio_init(GAS_SENSOR_PIN); // Initialize the GPIO pin for ADC
    adc_select_input(0);
    // printf("Gas detector initialized.\n");
}

// Read the current gas level from the MQ-2 sensor
uint16_t readGasLevel()
{
    uint16_t gasLevel = adc_read(); // Read ADC value from the MQ-2 sensor
    printf("Gas Level: %u\n", gasLevel);
    return gasLevel;
}

// Check gas level and trigger alarm if threshold is exceeded
void checkGasLevel(uint16_t gasLevel)
{
    if (gasLevel > GAS_THRESHOLD)
    {
        // Turn on LED and buzzer
        turnOnGasLed();
        // buzzer_on();
        printf("Gas detected! Warning!\n");
    }
    else
    {
        // Turn off LED and buzzer
        turnOffGasLed();
        // buzzer_off();
    }
}
