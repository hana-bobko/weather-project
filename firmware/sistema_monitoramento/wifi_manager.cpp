#include "wifi_manager.h"
#include "config.h"

#ifdef USE_WIFI

const char* ssid = "SUA_REDE_WIFI";     
const char* password = "SUA_SENHA_WIFI"; 

const unsigned long WIFI_TIMEOUT = 20000;

bool setupWifi() {
  Serial.println();
  Serial.print("Conectando à rede WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  unsigned long startTime = millis();
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    
    if (millis() - startTime > WIFI_TIMEOUT) {
      Serial.println();
      Serial.println("Timeout ao conectar ao WiFi!");
      return false;
    }
  }
  
  Serial.println();
  Serial.println("WiFi conectado com sucesso!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());
  
  return true;
}

bool reconnectWifi() {
  if (WiFi.status() == WL_CONNECTED) {
    return true;
  }
  
  Serial.println("Tentando reconectar ao WiFi...");
  
  WiFi.disconnect();
  
  delay(1000);
  
  return setupWifi();
}

bool isWifiConnected() {
  return (WiFi.status() == WL_CONNECTED);
}

String getWifiStatus() {
  switch(WiFi.status()) {
    case WL_CONNECTED:
      return "Conectado a " + String(ssid);
    case WL_NO_SHIELD:
      return "Módulo WiFi não encontrado";
    case WL_IDLE_STATUS:
      return "WiFi ocioso";
    case WL_NO_SSID_AVAIL:
      return "SSID não disponível";
    case WL_SCAN_COMPLETED:
      return "Escaneamento completo";
    case WL_CONNECT_FAILED:
      return "Falha na conexão";
    case WL_CONNECTION_LOST:
      return "Conexão perdida";
    case WL_DISCONNECTED:
      return "Desconectado";
    default:
      return "Status desconhecido: " + String(WiFi.status());
  }
}

#endif 