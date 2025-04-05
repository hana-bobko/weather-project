
#include "sensors.h"
#include <Arduino.h>
#include <DHT.h>

DHT dht(DHTPIN, DHT22);

float mq135BaseLine = 0;
int calibrationSamples = 0;

void initSensors() {
  Serial.println("Inicializando sensores...");
  
  dht.begin();
  
  pinMode(MQ135PIN, INPUT);
  pinMode(NOISEPIN, INPUT);
  
  Serial.println("Sensores inicializados com sucesso.");
}

void calibrateSensors() {
  Serial.println("Iniciando calibração dos sensores...");
  Serial.println("Calibrando sensor MQ-135 (qualidade do ar)...");
    
  mq135BaseLine = 0;
  calibrationSamples = 0;
  
  for (int i = 0; i < 10; i++) {
    mq135BaseLine += analogRead(MQ135PIN);
    calibrationSamples++;
    delay(1000);  
  }
  
  if (calibrationSamples > 0) {
    mq135BaseLine /= calibrationSamples;
  }
  
  Serial.print("MQ-135 calibrado. Linha de base: ");
  Serial.println(mq135BaseLine);
    
  Serial.println("Calibração concluída.");
}

void readAllSensors(SensorData *data) {
  data->timestamp = millis();
  
  readTemperatureAndHumidity(data);
  
  readAirQuality(data);
  
  readNoiseLevel(data);
}

void readTemperatureAndHumidity(SensorData *data) {
  data->humidity = dht.readHumidity();
  data->temperature = dht.readTemperature();
  
  if (isnan(data->humidity) || isnan(data->temperature)) {
    Serial.println("Falha na leitura do sensor DHT22!");
    data->humidity = 50.0;  
    data->temperature = 25.0;  
  }
}

void readAirQuality(SensorData *data) {
  int rawValue = analogRead(MQ135PIN);
  
  float voltage = rawValue * (5.0 / 1023.0);
  
  data->airQuality = int(10 * pow(1.37 * voltage, 2));
  
  if (data->airQuality < 400) {
    data->airQuality = 400;
  }
}

void readNoiseLevel(SensorData *data) {

  int samples = 50;
  int maxValue = 0;
  
  for (int i = 0; i < samples; i++) {
    int value = analogRead(NOISEPIN);
    if (value > maxValue) {
      maxValue = value;
    }
    delayMicroseconds(200);  
  }
  
  data->noiseLevel = map(maxValue, 0, 1023, 30, 90);
}

void printSensorData(SensorData *data) {

  Serial.println("---------------------------------------");
  Serial.print("Timestamp: ");
  Serial.println(data->timestamp);
  
  Serial.print("Temperatura: ");
  Serial.print(data->temperature);
  Serial.println(" °C");
  
  Serial.print("Umidade: ");
  Serial.print(data->humidity);
  Serial.println(" %");
  
  Serial.print("Qualidade do Ar (CO2 eq): ");
  Serial.print(data->airQuality);
  Serial.println(" ppm");
  
  Serial.print("Nível de Ruído: ");
  Serial.print(data->noiseLevel);
  Serial.println(" dB");
  Serial.println("---------------------------------------");
}