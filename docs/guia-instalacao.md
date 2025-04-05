# Guia de Instalação

## Sistema de Monitoramento Ambiental para Escolas Públicas

Este guia fornece instruções detalhadas para instalar, configurar e colocar em funcionamento o Sistema de Monitoramento Ambiental.

## Sumário

1. [Pré-requisitos](#pré-requisitos)
2. [Montagem do Hardware](#montagem-do-hardware)
3. [Configuração do Software](#configuração-do-software)
4. [Instalação Física](#instalação-física)
5. [Configuração de Rede](#configuração-de-rede)
6. [Verificação do Sistema](#verificação-do-sistema)
7. [Resolução de Problemas](#resolução-de-problemas)

## Pré-requisitos

### Ferramentas Necessárias

-   Chave de fenda Phillips pequena
-   Multímetro (para verificações)
-   Furadeira e buchas (para fixação na parede)
-   Computador com Arduino IDE instalado
-   Cabo USB (compatível com o microcontrolador)

### Materiais Adicionais

-   Fita dupla-face forte ou velcro
-   Abraçadeiras de nylon (zip ties)
-   Canaletas para organização de cabos
-   Extensão elétrica (se necessário)

### Conhecimentos Básicos

-   Noções básicas de conexões elétricas
-   Familiaridade com a Arduino IDE
-   Conhecimentos básicos de redes WiFi

## Montagem do Hardware

### 1. Preparação dos Componentes

-   Verifique todos os componentes conforme a [Lista de Componentes](../hardware/lista_componentes.md)
-   Teste individualmente cada sensor antes da montagem final
-   Certifique-se de que o cartão SD está formatado em FAT32

### 2. Conexão dos Sensores

Siga cuidadosamente o [Esquema de Conexões](../hardware/esquematicos/esquema_principal.pdf):

#### Sensor DHT22 (Temperatura e Umidade)

-   Pino VCC → 5V ou 3.3V do ESP32/Arduino
-   Pino DATA → Pino Digital 4
-   Pino GND → GND
-   Monte o resistor pull-up de 10K ohm entre VCC e DATA

#### Sensor MQ-135 (Qualidade do Ar)

-   Pino VCC → 5V
-   Pino AOUT → Pino Analógico A0
-   Pino GND → GND
-   **Importante**: O sensor MQ-135 precisa de pelo menos 24 horas de aquecimento para estabilização completa

#### Sensor KY-038 (Ruído)

-   Pino VCC → 5V
-   Pino AOUT → Pino Analógico A1
-   Pino GND → GND
-   Ajuste o potenciômetro para sensibilidade adequada

#### Módulo SD Card

-   Pino VCC → 5V ou 3.3V (verifique o módulo específico)
-   Pino GND → GND
-   Pino CS → Pino Digital 10
-   Pino MOSI → Pino MOSI (11 no Arduino, 23 no ESP32)
-   Pino MISO → Pino MISO (12 no Arduino, 19 no ESP32)
-   Pino SCK → Pino SCK (13 no Arduino, 18 no ESP32)

#### Display LCD I2C

-   Pino VCC → 5V
-   Pino GND → GND
-   Pino SDA → Pino SDA (A4 no Arduino, 21 no ESP32)
-   Pino SCL → Pino SCL (A5 no Arduino, 22 no ESP32)

### 3. Montagem na Caixa

-   Posicione todos os componentes dentro da caixa protetora
-   Fixe o microcontrolador com parafusos ou fita dupla-face
-   Organize os cabos com abraçadeiras
-   Faça aberturas para os sensores com exposição adequada ao ambiente
-   O sensor DHT22 deve ficar parcialmente exposto
-   O sensor MQ-135 deve ter boa circulação de ar
-   O display LCD deve ficar visível pela parte frontal

## Configuração do Software

### 1. Preparação do Ambiente de Desenvolvimento

-   Instale a [Arduino IDE](https://www.arduino.cc/en/software)
-   Adicione suporte ao ESP32 (se estiver usando):
    -   Abra Arduino IDE → Preferências → URLs Adicionais
    -   Adicione: `https://dl.espressif.com/dl/package_esp32_index.json`
    -   Ferramentas → Placa → Gerenciador de Placas → Instale "ESP32"

### 2. Instalação das Bibliotecas

Instale as seguintes bibliotecas via Arduino IDE (Sketch → Incluir Biblioteca → Gerenciar Bibliotecas):

-   DHT Sensor Library (por Adafruit)
-   Adafruit Unified Sensor
-   SD by Arduino
-   SPI (já incluída)
-   LiquidCrystal_I2C
-   WiFi (para ESP32) ou ESP8266WiFi (para Arduino + ESP8266)
-   ThingSpeak (se estiver usando armazenamento em nuvem)

### 3. Configuração do Código

-   Clone ou baixe este repositório
-   Abra o arquivo `firmware/sistema_monitoramento/sistema_monitoramento.ino`
-   Ajuste as configurações em `config.h`:
    -   Defina os pinos corretos para os sensores
    -   Configure os limites de alerta para cada parâmetro
    -   Ative ou desative a conexão WiFi
    -   Se estiver usando WiFi, ajuste as credenciais da rede

### 4. Upload do Código

-   Conecte o microcontrolador ao computador via USB
-   Selecione a placa correta em Ferramentas → Placa
-   Selecione a porta correta em Ferramentas → Porta
-   Clique em Verificar e depois em Fazer Upload
-   Aguarde a mensagem "Upload concluído"

## Instalação Física

### 1. Escolha do Local

-   Posicione a unidade a aproximadamente 1,5m do chão
-   Evite locais próximos a:
    -   Janelas com incidência direta de sol
    -   Saídas de ar-condicionado
    -   Fontes diretas de calor (lâmpadas, projetores)
    -   Áreas com fluxo de ar restrito
-   Certifique-se de que há uma tomada elétrica próxima

### 2. Fixação

-   Marque os pontos para furação usando o suporte como guia
-   Faça os furos com broca adequada para o tipo de parede
-   Insira as buchas e parafuse o suporte firmemente
-   Encaixe o sistema no suporte
-   Organize o cabo de alimentação de forma segura usando canaletas

### 3. Organização dos Cabos

-   Use canaletas para organizar o cabo de alimentação
-   Certifique-se de que os cabos não obstruem a circulação de ar nos sensores
-   Fixe os cabos com fita ou abraçadeiras para evitar desconexões acidentais

## Configuração de Rede

### 1. Conexão WiFi (se aplicável)

-   Após a primeira inicialização, o sistema exibirá "Configurando WiFi"
-   Se não conectar automaticamente:
    -   Verifique se as credenciais no código estão corretas
    -   Reinicie o sistema usando o botão de reset

### 2. Verificação da Conexão

-   Quando conectado, o display mostrará brevemente o endereço IP atribuído
-   Anote este endereço IP para acesso à interface web

### 3. Acesso à Interface Web

-   Em um computador ou smartphone conectado à mesma rede
-   Abra um navegador e digite o endereço IP anotado
-   Você deverá ver a página inicial do dashboard

## Verificação do Sistema

### 1. Teste dos Sensores

-   Após a inicialização completa, verifique se:
    -   O display LCD mostra os valores de temperatura e umidade
    -   Os valores são atualizados periodicamente
    -   O LED de status pisca indicando funcionamento normal

### 2. Verificação do Armazenamento

-   Após alguns minutos de funcionamento, desligue o sistema
-   Remova o cartão SD e insira-o em um computador
-   Verifique se o arquivo `dados_ambientais.csv` foi criado
-   Confirme se há dados sendo registrados corretamente

### 3. Teste de Alertas

-   Você pode testar os alertas aproximando uma fonte de calor do sensor de temperatura
-   Quando a temperatura exceder o limite configurado, o display deverá piscar

## Resolução de Problemas

### Problemas Comuns e Soluções

#### Sistema não liga

-   Verifique a conexão da fonte de alimentação
-   Teste a tomada com outro aparelho
-   Verifique se há curto-circuito nas conexões

#### Valores inconsistentes

-   Verifique se os sensores estão corretamente conectados
-   Aguarde o período de estabilização (especialmente para o MQ-135)
-   Certifique-se de que não há interferências ambientais imediatas

#### Falha na gravação de dados

-   Verifique se o cartão SD está corretamente formatado (FAT32)
-   Teste o cartão SD em um computador para garantir que funciona
-   Verifique se o módulo SD está corretamente conectado

#### Problemas de conexão WiFi

-   Verifique se o roteador está funcionando corretamente
-   Aproxime o sistema do roteador
-   Revise as credenciais de rede no código

#### Display não mostra informações

-   Verifique se o endereço I2C está correto (geralmente 0x27 ou 0x3F)
-   Teste a conexão dos cabos do display
-   Verifique se o contraste está ajustado corretamente

### Suporte Técnico

Para problemas não resolvidos, entre em contato:

-   Email: [seu-email@exemplo.com]
-   Repositório do projeto: [link-para-issues-do-github]
