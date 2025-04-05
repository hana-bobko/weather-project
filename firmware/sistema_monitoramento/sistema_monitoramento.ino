/*
 * Sistema de Monitoramento Ambiental para Escolas Públicas
 * Desenvolvido como trabalho de extensão para a disciplina de Programação de Microcontroladores
 * 
 * Este código realiza:
 * - Leitura de sensores (temperatura, umidade, qualidade do ar, ruído)
 * - Armazenamento dos dados (SD Card e/ou ThingSpeak)
 * - Exibição em display LCD local
 * - Transmissão via WiFi (se usar ESP32)
 * 
 * Hardware necessário:
 * - ESP32 (ou Arduino Uno + módulo WiFi)
 * - Sensor DHT22 (temperatura e umidade)
 * - Sensor MQ-135 (qualidade do ar)
 * - Sensor KY-038 (ruído)
 * - Módulo cartão SD
 * - Display LCD 16x2 com I2C
 */

#include "config.h"
#include "sensors.h"
#include "data_storage.h"

#ifdef USE_WIFI
  #include "wifi_manager.h"
#endif

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <SD.h>


#define DHTPIN 4       
#define MQ135PIN A0     
#define NOISEPIN A1    
#define SDPIN 10        


#define READ_INTERVAL 60000  


LiquidCrystal_I2C lcd(0x27, 16, 2);  
SensorData sensorData;      
File dataFile;              

unsigned long lastReadTime = 0;
unsigned long lastUploadTime = 0;
unsigned long lastDisplayUpdateTime = 0;

int displayState = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando Sistema de Monitoramento Ambiental...");
  
  initSensors();
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Monitoramento");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  
  Serial.print("Inicializando cartão SD...");
  if (!SD.begin(SDPIN)) {
    Serial.println("Falha na inicialização do cartão SD!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Erro no SD Card");
    delay(2000);
  } else {
    Serial.println("Cartão SD inicializado.");
    createDataFileIfNeeded();
  }
  
  #ifdef USE_WIFI
    setupWifi();
    
    initCloudStorage();
  #endif
  
  calibrateSensors();
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema Pronto");
  delay(1000);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastDisplayUpdateTime >= 3000) {
    updateDisplay();
    lastDisplayUpdateTime = currentMillis;
  }
  
  if (currentMillis - lastReadTime >= READ_INTERVAL) {
    readAllSensors(&sensorData);
    
    printSensorData(&sensorData);
    
    saveDataToSD(&sensorData);
    
    #ifdef USE_WIFI
      if (currentMillis - lastUploadTime >= UPLOAD_INTERVAL) {
        uploadDataToCloud(&sensorData);
        lastUploadTime = currentMillis;
      }
    #endif
    
    lastReadTime = currentMillis;
  }
  
  checkAlarmLimits(&sensorData);
  
  delay(100);
}

void updateDisplay() {
  displayState = (displayState + 1) % 3;
  
  lcd.clear();
  
  switch (displayState) {
    case 0:
      lcd.setCursor(0, 0);
      lcd.print("Temp: ");
      lcd.print(sensorData.temperature);
      lcd.print(" C");
      
      lcd.setCursor(0, 1);
      lcd.print("Umid: ");
      lcd.print(sensorData.humidity);
      lcd.print(" %");
      break;
      
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("Qualidade Ar:");
      
      lcd.setCursor(0, 1);
      lcd.print("CO2: ");
      lcd.print(sensorData.airQuality);
      lcd.print(" ppm");
      break;
      
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("Nivel Ruido:");
      
      lcd.setCursor(0, 1);
      lcd.print(sensorData.noiseLevel);
      lcd.print(" dB");
      break;
  }
}

void checkAlarmLimits(SensorData *data) {
  bool alarmTriggered = false;
  
  if (data->temperature > TEMP_MAX_LIMIT || data->temperature < TEMP_MIN_LIMIT) {
    alarmTriggered = true;
  }
  
  if (data->humidity > HUMIDITY_MAX_LIMIT || data->humidity < HUMIDITY_MIN_LIMIT) {
    alarmTriggered = true;
  }
  
  if (data->airQuality > AIR_QUALITY_LIMIT) {
    alarmTriggered = true;
  }
  
  if (data->noiseLevel > NOISE_LEVEL_LIMIT) {
    alarmTriggered = true;
  }
  
  if (alarmTriggered) {
    triggerAlarm();
  }
}

void triggerAlarm() {
  Serial.println("ALERTA: Valor fora dos limites!");
  
  for (int i = 0; i < 3; i++) {
    lcd.noBacklight();
    delay(200);
    lcd.backlight();
    delay(200);
  }
}