#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H

#include <SD.h>
#include "sensors.h"

void createDataFileIfNeeded();
void saveDataToSD(SensorData *data);

#ifdef USE_WIFI
  void uploadDataToCloud(SensorData *data);
  bool initCloudStorage();
#endif

#endif 