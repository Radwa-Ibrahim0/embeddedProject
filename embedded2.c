// main.c
#include <stdio.h>
#include <stdint.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "hardware/pwm.h"
#include "gas.h"
#include "temp.h"
#include "DCfan.h"
#include "buzzer.h"
#include "led.h"
#include "flame.h"

// int main() {
//     stdio_init_all();
//     buzzer_init();
//     initLEDs();
//     initializeGasDetector();
//     initializeTemperatureSensor();
//     initDCFan();
//     initializeFlameDetector();

//     // Blink LED to indicate system is working
//     for (int i = 0; i < 3; i++) {
//         // turnOnGasLed();
//         // turnOnTempLed();
//         // turnOnFlameLed();
//         buzzer_on();
//         sleep_ms(300);
//         buzzer_off();
//         turnOffFlameLed();
//         turnOffTempLed();
//         turnOffGasLed();
//         sleep_ms(300);

//     }

//     while (1) {
//         // Read the gas level
//         uint16_t gasLevel = readGasLevel();

//         // Check the gas level and trigger alarms if necessary
//         checkGasLevel(gasLevel);

//         // Read the temperature from the temperature sensor
//         float temperature = readTemperature();

//         // Check the temperature and trigger actions if necessary
//         // checkTemperature(temperature);

//         // Read the flame level
//         uint16_t flameLevel = readFlameLevel();

//         // Check the flame level and trigger alarms if necessary
//         // checkFlameLevel(flameLevel);

//         // Increasing speed
//         // for (uint16_t speed = 0; speed <= 255; speed += 100) {
//         //     setFanSpeed(speed);
//         //     sleep_ms(5000);
//         // }
//          setFanSpeed(200, false);
//          sleep_ms(10000);
//          stopFan();
//          sleep_ms(10000);
//          turnOnFlameLed();
//          setFanSpeed(240, true);
//          sleep_ms(10000);
//          stopFan();
//          turnOffFlameLed();

//         // Ddecreasing speed
//         // for (uint16_t speed = 255; speed > 0; speed -= 100) {
//         //     setFanSpeed(speed);
//         //     sleep_ms(5000);
//         // }

//         // Stop fan
//         // stopFan();
//         sleep_ms(1000);
//     }
// }

// // int main() {
// // stdio_init_all();
// // while (1) {
// // printf("Hello, Pico!\n");
// // sleep_ms(1000); // Delay between prints
// // }
// // return 0;
// // }

int main()
{
    stdio_init_all();
    buzzer_init();
    initLEDs();
    adc_init();
    initializeTemperatureSensor();
    initDCFan();
    initializeFlameDetector();
    initializeGasDetector();

    uint slice_num = pwm_gpio_to_slice_num(21);
    gpio_init(17);
    gpio_set_dir(17, GPIO_OUT);
    gpio_init(18);
    gpio_set_dir(18, GPIO_OUT);
    initDCFan();

    // Blink LED to indicate system is working
    for (int i = 0; i < 3; i++)
    {
        turnOnGasLed();
        turnOnTempLed();
        turnOnFlameLed();
        buzzer_on();
        sleep_ms(300);
        buzzer_off();
        turnOffFlameLed();
        turnOffTempLed();
        turnOffGasLed();
        sleep_ms(300);
    }

    while (true)
    {
        // Read the gas level
        uint16_t gasLevel = readGasLevel();

        // Check the gas level and trigger alarms if necessary
        checkGasLevel(gasLevel);

        // Read the temperature from the temperature sensor
        float temperature = readTemperature();

        // Check the temperature and trigger actions if necessary
        checkTemperature(temperature);

        // Read the flame level
        uint16_t flameLevel = readFlameLevel();

        // Check the flame level and trigger alarms if necessary
        checkFlameLevel(flameLevel);

        // Increasing speed of the fan
        // for(int i = 0 ; i<255 ; i++){
        // setFanSpeed(i , true);
        // delay_ms(100);
        // if( i ==255){
        // i = 0 ;
        // }
        // }
        delay_ms(2000);
    }
    return 0;
}