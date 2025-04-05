/**
 * Sistema de Monitoramento Ambiental para Escolas Públicas
 * Script principal do dashboard
 */

// Configurações do Dashboard
const dashboardConfig = {
    refreshInterval: 300, // Intervalo de atualização em segundos (padrão: 5 minutos)
    thingspeakChannel: 123456, // ID do canal ThingSpeak
    thingspeakReadAPIKey: "SUA_API_KEY_AQUI", // Chave de API do ThingSpeak
    chartPeriod: 24, // Período padrão para gráficos (em horas)
    alertsEnabled: true, // Exibição de alertas ativada por padrão
    rooms: [
        {
            id: 1,
            name: "Sala 1 - 5º Ano A",
            fieldMapping: {
                temperature: 1, // Campo do ThingSpeak para temperatura
                humidity: 2, // Campo do ThingSpeak para umidade
                airQuality: 3, // Campo do ThingSpeak para qualidade do ar
                noise: 4, // Campo do ThingSpeak para ruído
            },
        },
        {
            id: 2,
            name: "Sala 2 - 7º Ano B",
            fieldMapping: {
                temperature: 5,
                humidity: 6,
                airQuality: 7,
                noise: 8,
            },
        },
        {
            id: 3,
            name: "Sala 3 - Laboratório",
            fieldMapping: {
                temperature: 1, // Exemplo usando o mesmo feed (poderia ser diferente)
                humidity: 2,
                airQuality: 3,
                noise: 4,
            },
        },
    ],
    limits: {
        temperature: {
            min: 18.0,
            max: 30.0,
            idealMin: 20.0,
            idealMax: 40.0,
        },
    },
};
