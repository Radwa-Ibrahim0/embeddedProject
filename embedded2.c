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
int main(){
    
// Initialize the LED GPIO pin
// Set GPIO 25 to PWM function
// w  gpio_set_function(21, GPIO_FUNC_PWM);
// Get the PWM slice number for the chosen GPIO
 uint slice_num = pwm_gpio_to_slice_num(21);
// Set the PWM frequency
// Wrap value determines the frequency
// (along with clock divider)
 // wpwm_set_wrap(slice_num, 255);
// This sets TOP to 255, allowing a 256
//step PWM (8 bit //resolution)
// Set the clock divider to control PWM frequency
 // w pwm_set_clkdiv(slice_num, 4.0f);
// Divides the system clock,
//affecting PWM frequency
// Enable PWM on the specified slice
 // w pwm_set_enabled(slice_num, true);
 // w pwm_set_gpio_level(21,200) ; 
// Gradually increase and decrease brightness
gpio_init(17);
gpio_set_dir(17, GPIO_OUT);
gpio_init(18);
gpio_set_dir(18, GPIO_OUT);

//gpio_put(17, 1);
//gpio_put(18, 0);
initDCFan();
while(true) {
for(int i = 0 ; i<255 ; i++){
setFanSpeed(i , true);
delay_ms(100);
if( i ==255){
 i = 0 ; 
}

}


}








return 0 ; 
}