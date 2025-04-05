# Lista de Componentes - Sistema de Monitoramento Ambiental

## Componentes Principais

| Item                 | Quantidade | Descrição                                              | Função                                       | Preço Estimado (R$) |
| -------------------- | ---------- | ------------------------------------------------------ | -------------------------------------------- | ------------------- |
| ESP32 ou Arduino     | 1          | Microcontrolador ESP32 DevKit ou Arduino Uno + ESP8266 | Unidade central de processamento             | 60,00 - 100,00      |
| DHT22                | 1          | Sensor de temperatura e umidade                        | Mede temperatura (°C) e umidade relativa (%) | 25,00 - 40,00       |
| MQ-135               | 1          | Sensor de gás                                          | Mede qualidade do ar/níveis de CO2           | 20,00 - 30,00       |
| KY-038               | 1          | Sensor de som                                          | Mede níveis de ruído                         | 10,00 - 15,00       |
| Display LCD 16x2 I2C | 1          | Display de cristal líquido com adaptador I2C           | Exibição local dos dados                     | 25,00 - 35,00       |
| Módulo cartão SD     | 1          | Leitor/gravador de cartão SD                           | Armazenamento local de dados                 | 15,00 - 25,00       |
| Cartão SD            | 1          | Cartão de memória SD (8GB ou superior)                 | Mídia de armazenamento                       | 20,00 - 30,00       |

## Componentes Adicionais

| Item                       | Quantidade | Descrição                                     | Função                 | Preço Estimado (R$) |
| -------------------------- | ---------- | --------------------------------------------- | ---------------------- | ------------------- |
| Resistor 10K ohm           | 1          | Resistor pullup                               | Para o sensor DHT22    | 0,50                |
| Jumpers Macho-Macho        | 20         | Fios de conexão                               | Conectar componentes   | 15,00               |
| Jumpers Macho-Fêmea        | 10         | Fios de conexão                               | Conectar componentes   | 15,00               |
| Protoboard                 | 1          | Placa para protótipos                         | Montagem do circuito   | 20,00               |
| Fonte de alimentação 5V/2A | 1          | Fonte de alimentação com cabo micro USB ou DC | Alimentação do sistema | 25,00 - 40,00       |
| Caixa protetora            | 1          | Caixa de plástico ou acrílico                 | Proteção do circuito   | 30,00 - 50,00       |

## Ferramentas Necessárias

-   Multímetro
-   Ferro de solda e solda (para montagem final)
-   Computador com Arduino IDE instalado
-   Cabo USB adequado para o microcontrolador escolhido

## Opcionais

| Item          | Quantidade | Descrição                         | Função                                      | Preço Estimado (R$) |
| ------------- | ---------- | --------------------------------- | ------------------------------------------- | ------------------- |
| LED RGB       | 1          | LED de três cores                 | Indicação visual de alertas                 | 5,00                |
| Buzzer        | 1          | Emissor de som                    | Alerta sonoro                               | 5,00                |
| Bateria LiPo  | 1          | Bateria recarregável              | Alimentação portátil                        | 40,00 - 60,00       |
| Módulo TP4056 | 1          | Carregador de bateria LiPo        | Gerenciamento da bateria                    | 10,00               |
| MCP9808       | 1          | Sensor de temperatura de precisão | Medição mais precisa (alternativa ao DHT22) | 20,00 - 30,00       |

## Custo Total Estimado

-   **Configuração básica**: R$ 210,00 - R$ 310,00
-   **Configuração completa com opcionais**: R$ 290,00 - R$ 420,00

## Onde Comprar

Os componentes podem ser encontrados em:

-   Lojas de eletrônica especializadas
-   Marketplaces online (MercadoLivre, Amazon, AliExpress)
-   Fornecedores especializados em Arduino/ESP32:
    -   FilipeFlop
    -   Robocore
    -   Eletrogate
    -   Baú da Eletrônica

## Notas

1. Os preços são estimados e podem variar conforme a região e fornecedor.
2. É possível reduzir custos adquirindo kits que incluam vários componentes.
3. Para ambientes escolares, considere adquirir componentes extras para substituição em caso de danos.
4. Sensores de melhor qualidade podem aumentar a precisão do sistema, mas também o custo.
