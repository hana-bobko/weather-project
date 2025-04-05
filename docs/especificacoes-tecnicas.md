# Especificações Técnicas

## Sistema de Monitoramento Ambiental para Escolas Públicas

## Microcontrolador

### ESP32

-   **Modelo**: ESP32 DevKit V1 / NodeMCU-32S
-   **Processador**: Dual-core Xtensa LX6, até 240MHz
-   **Memória RAM**: 520 KB SRAM
-   **Armazenamento**: 4MB Flash
-   **Conectividade**: WiFi 2.4GHz + Bluetooth 4.2
-   **GPIO**: 36 pinos (alguns compartilhados)
-   **ADC**: 12-bit, 18 canais
-   **Alimentação**: 5V via USB, operação em 3.3V

### Arduino (alternativa)

-   **Modelo**: Arduino Uno R3
-   **Processador**: ATmega328P, 16MHz
-   **Memória RAM**: 2KB SRAM
-   **Armazenamento**: 32KB Flash
-   **GPIO**: 14 pinos digitais, 6 pinos analógicos
-   **ADC**: 10-bit, 6 canais
-   **Módulo WiFi**: ESP8266 (NodeMCU) como complemento

## Sensores

### DHT22 (Temperatura e Umidade)

-   **Faixa de medição de temperatura**: -40°C a 80°C
-   **Precisão de temperatura**: ±0.5°C
-   **Faixa de medição de umidade**: 0% a 100% RH
-   **Precisão de umidade**: ±2% RH
-   **Taxa de amostragem**: 0.5 Hz (uma leitura a cada 2 segundos)
-   **Alimentação**: 3.3V a 5V
-   **Protocolo**: Digital one-wire
-   **Pinagem**: VCC, DATA, GND

### MQ-135 (Qualidade do Ar)

-   **Gases detectáveis**: CO2, NH3, NOx, álcool, benzeno
-   **Faixa de medição**: 10 a 1000 ppm
-   **Tempo de aquecimento**: 24 horas (estabilização completa)
-   **Saída**: Analógica (0-1023) e Digital (ajustável por potenciômetro)
-   **Alimentação**: 5V
-   **Consumo**: ~150mA (necessita de período de aquecimento)
-   **Pinagem**: VCC, AOUT, DOUT, GND

### KY-038 (Sensor de Som/Ruído)

-   **Tipo**: Microfone de eletreto com amplificador
-   **Faixa de sensibilidade**: Ajustável via potenciômetro
-   **Saída**: Analógica (nível de som) e Digital (detecção de limiar)
-   **Alimentação**: 3.3V a 5V
-   **Pinagem**: VCC, AOUT, DOUT, GND
-   **Observações**: Calibração necessária para medição precisa em dB

## Armazenamento e Display

### Módulo SD Card

-   **Compatibilidade**: Cartões SD e microSD (com adaptador)
-   **Capacidade suportada**: Até 32GB (recomendado 8GB)
-   **Formato de arquivo**: FAT16/FAT32
-   **Interface**: SPI
-   **Alimentação**: 3.3V (alguns módulos possuem regulador para 5V)
-   **Pinagem**: VCC, GND, CS, MOSI, MISO, SCK

### Display LCD 16x2 com I2C

-   **Colunas x Linhas**: 16x2 caracteres
-   **Controlador**: HD44780 compatível
-   **Interface**: I2C (endereço padrão 0x27 ou 0x3F)
-   **Alimentação**: 5V
-   **Backlight**: LED azul (ajustável via software)
-   **Pinagem**: VCC, GND, SDA, SCL

## Comunicação e Conectividade

### WiFi (ESP32 interno ou ESP8266 para Arduino)

-   **Padrão**: IEEE 802.11 b/g/n
-   **Faixa de frequência**: 2.4GHz
-   **Segurança**: WPA/WPA2
-   **Modos**: Station e Access Point

### Interface Serial

-   **Baud rate padrão**: 115200 bps
-   **Porta**: USB (para programação e monitoramento)

## Armazenamento de Dados

### Local (SD Card)

-   **Formato do arquivo**: CSV
-   **Colunas**: timestamp, temperatura, umidade, qualidade_ar, ruido
-   **Intervalo de gravação**: 60 segundos (configurável)
-   **Tamanho estimado**: ~2MB por mês

### Nuvem (ThingSpeak)

-   **Intervalo de upload**: 5 minutos (limitação da API gratuita)
-   **Campos**: 4 (temperatura, umidade, qualidade do ar, ruído)
-   **Visualização**: Gráficos automáticos, exportação de dados

## Alimentação

### Fonte Principal

-   **Entrada**: 100-240V AC
-   **Saída**: 5V DC, mínimo 2A recomendado
-   **Conector**: Micro USB ou conector DC (dependendo da placa)

### Backup (opcional)

-   **Bateria**: LiPo 3.7V, 2000mAh
-   **Autonomia estimada**: 4-6 horas
-   **Controlador de carga**: TP4056 com proteção

## Consumo de Energia

-   **Normal**: ~200mA (todos os sensores ativos)
-   **Pico**: ~300mA (durante comunicação WiFi)
-   **Sleep mode**: ~20mA (apenas monitoramento básico)

## Precisão e Limites

### Precisão das Medições

-   **Temperatura**: ±0.5°C
-   **Umidade**: ±2%
-   **Qualidade do ar**: Indicativa (requer calibração para valores absolutos)
-   **Ruído**: ±3-5dB (após calibração)

### Limites Operacionais

-   **Temperatura de operação**: 0°C a 50°C
-   **Umidade de operação**: 10% a 90% (sem condensação)
-   **Altitude máxima**: 2000m

## Dimensões Físicas

-   **Unidade principal**: ~120mm x 80mm x 40mm
-   **Peso aproximado**: 150g
-   **Material da caixa**: ABS

## Requisitos de Software

### Desenvolvimento

-   **IDE**: Arduino IDE 1.8+ ou PlatformIO
-   **Bibliotecas principais**:
    -   DHT Sensor Library (Adafruit)
    -   SD Card Library
    -   LiquidCrystal_I2C
    -   WiFi (ESP32) ou ESP8266WiFi
    -   ThingSpeak (opcional)

### Dashboard Web

-   **Frontend**: HTML5, CSS3, JavaScript
-   **Bibliotecas JS**: Chart.js para visualização
-   **Compatibilidade**: Navegadores modernos (Chrome, Firefox, Edge)
-   **Responsividade**: Adaptação para desktop e dispositivos móveis

## Normas e Referências

-   **Qualidade do ar interior**: ANVISA RE nº 9/2003
-   **Níveis de ruído**: NBR 10152 - Níveis de ruído para conforto acústico
-   **Padrões de temperatura e umidade**: ASHRAE Standard 55
