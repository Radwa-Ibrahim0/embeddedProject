// gas_detector.h

#ifndef GAS_DETECTOR_H
#define GAS_DETECTOR_H

// Pin definitions
#define GAS_SENSOR_PIN 28   

// Gas threshold value
#define GAS_THRESHOLD 4095     // Adjust this value as necessary (original:300)

// Function prototypes
void initializeGasDetector();
uint16_t readGasLevel();
void checkGasLevel(uint16_t gasLevel);

#endif
