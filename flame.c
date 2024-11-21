// flame_detector.c
#include <stdio.h>
#include <stdint.h> // Add this line
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "flame.h"
#include "buzzer.h"
#include "led.h"

// Initialize pins and indicate system start-up with LED blink
void initializeFlameDetector()
{
    adc_gpio_init(FLAME_SENSOR_PIN); // Initialize the GPIO pin for ADC
    adc_select_input(2);             // Select input channel 1
    // printf("Flame detector initialized.\n");
}

// Read the current flame level from the sensor
uint16_t readFlameLevel()
{
    uint16_t flameLevel = adc_read(); // Read ADC value from the flame sensor
    printf("Flame Level: %u\n", flameLevel);
    return flameLevel;
}

// Check flame level and trigger alarm if threshold is exceeded
void checkFlameLevel(uint16_t flameLevel)
{
    if (flameLevel > FLAME_THRESHOLD)
    {
        // Turn on LED and buzzer
        turnOnFlameLed();
        // buzzer_on();
        printf("Flame detected! Warning!\n");
    }
    else
    {
        // Turn off LED and buzzer
        turnOffFlameLed();
        buzzer_off();
    }
}
