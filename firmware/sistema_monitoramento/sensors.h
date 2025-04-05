
#ifndef SENSORS_H
#define SENSORS_H

#include <DHT.h>
#include "config.h"

typedef struct {
  float temperature;   
  float humidity;       
  int airQuality;       
  int noiseLevel;       
  unsigned long timestamp;  
} SensorData;

void initSensors();
void calibrateSensors();
void readAllSensors(SensorData *data);
void readTemperatureAndHumidity(SensorData *data);
void readAirQuality(SensorData *data);
void readNoiseLevel(SensorData *data);
void printSensorData(SensorData *data);

#endif 