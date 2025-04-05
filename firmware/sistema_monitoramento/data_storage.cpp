#include "data_storage.h"
#include "config.h"
#include <SD.h>
#include <Arduino.h>

#ifdef USE_WIFI
  #include "wifi_manager.h"
  #include <ThingSpeak.h>
  WiFiClient client;
#endif

const char* dataFileName = "/dados_ambientais.csv";

void createDataFileIfNeeded() {
  if (!SD.exists(dataFileName)) {
    File dataFile = SD.open(dataFileName, FILE_WRITE);
    
    if (dataFile) {
      Serial.println("Criando novo arquivo de dados...");
      dataFile.println("timestamp,temperatura,umidade,qualidade_ar,ruido");
      dataFile.close();
      Serial.println("Arquivo criado com sucesso.");
    } else {
      Serial.println("Erro ao criar arquivo de dados!");
    }
  } else {
    Serial.println("Arquivo de dados já existe.");
  }
}

void saveDataToSD(SensorData *data) {
  File dataFile = SD.open(dataFileName, FILE_WRITE);
  
  if (dataFile) {
    String dataString = String(data->timestamp) + "," +
                        String(data->temperature) + "," +
                        String(data->humidity) + "," +
                        String(data->airQuality) + "," +
                        String(data->noiseLevel);
    
    dataFile.println(dataString);
    dataFile.close();
    
    Serial.println("Dados gravados no SD com sucesso.");
  } else {
    Serial.println("Erro ao abrir arquivo para escrita!");
  }
}

#ifdef USE_WIFI
  bool initCloudStorage() {
    ThingSpeak.begin(client);
    Serial.println("Armazenamento em nuvem inicializado.");
    return true;
  }
  
  void uploadDataToCloud(SensorData *data) {
    if (WiFi.status() != WL_CONNECTED) {
      Serial.println("WiFi desconectado. Tentando reconectar...");
      reconnectWifi();
      
      if (WiFi.status() != WL_CONNECTED) {
        Serial.println("Falha ao reconectar WiFi. Upload cancelado.");
        return;
      }
    }
    
    ThingSpeak.setField(1, data->temperature);
    ThingSpeak.setField(2, data->humidity);
    ThingSpeak.setField(3, data->airQuality);
    ThingSpeak.setField(4, data->noiseLevel);
    
    int httpCode = ThingSpeak.writeFields(THINGSPEAK_CHANNEL_ID, THINGSPEAK_API_KEY);
    
    if (httpCode == 200) {
      Serial.println("Dados enviados para o ThingSpeak com sucesso.");
    } else {
      Serial.print("Erro ao enviar dados para o ThingSpeak. Código HTTP: ");
      Serial.println(httpCode);
    }
  }
#endif