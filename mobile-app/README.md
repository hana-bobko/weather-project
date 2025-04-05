# Aplicativo Móvel - Sistema de Monitoramento Ambiental

Este diretório contém o código-fonte para o aplicativo móvel do Sistema de Monitoramento Ambiental para Escolas Públicas.

> **Nota:** Este aplicativo é um recurso opcional e complementar ao sistema principal. A implementação completa está planejada para fases futuras do projeto.

## Visão Geral

O aplicativo móvel permite aos usuários (professores, gestores e funcionários da escola) acessar os dados ambientais coletados pelo sistema diretamente de seus smartphones, facilitando o monitoramento e a tomada de decisões em tempo real.

## Funcionalidades Planejadas

-   **Dashboard Móvel**: Visualização em tempo real dos dados de temperatura, umidade, qualidade do ar e ruído
-   **Notificações**: Alertas quando parâmetros estiverem fora dos limites recomendados
-   **Histórico**: Acesso a gráficos históricos dos dados ambientais
-   **Múltiplas Salas**: Navegação entre diferentes salas monitoradas
-   **Exportação**: Possibilidade de exportar relatórios em PDF ou CSV
-   **Configurações Remotas**: Ajustar configurações do sistema remotamente (para usuários autorizados)

## Tecnologias Previstas

-   **Framework**: Flutter para desenvolvimento multiplataforma (Android/iOS)
-   **Backend**: Conexão com API REST hospedada no servidor ou diretamente com ThingSpeak
-   **Autenticação**: Sistema simples de login para garantir acesso apenas a usuários autorizados
-   **Armazenamento**: Suporte a cache local para funcionamento offline

## Estrutura do Projeto

```
mobile-app/
├── assets/              # Recursos gráficos e fontes
├── lib/                 # Código-fonte Dart/Flutter
│   ├── api/             # Conexão com backend
│   ├── models/          # Modelos de dados
│   ├── screens/         # Telas do aplicativo
│   ├── utils/           # Funções utilitárias
│   └── widgets/         # Componentes de UI reutilizáveis
├── test/                # Testes automatizados
└── pubspec.yaml         # Dependências e configurações
```

## Instruções para Desenvolvimento

### Pré-requisitos

-   Flutter SDK 2.5.0 ou superior
-   Android Studio / VS Code com extensões Flutter e Dart
-   Git

### Configuração do Ambiente

1. Clone o repositório:

    ```
    git clone https://github.com/seu-usuario/sistema-monitoramento-ambiental-escolar.git
    ```

2. Navegue até o diretório do aplicativo:

    ```
    cd sistema-monitoramento-ambiental-escolar/mobile-app
    ```

3. Instale as dependências:

    ```
    flutter pub get
    ```

4. Configure a URL do backend no arquivo `lib/api/config.dart`

5. Execute o aplicativo em um emulador ou dispositivo:
    ```
    flutter run
    ```

## Roteiro de Implementação

### Fase 1: Protótipo Básico

-   Implementação do login básico
-   Dashboard com visualização de dados atuais
-   Navegação entre salas

### Fase 2: Recursos Avançados

-   Gráficos históricos
-   Sistema de notificações
-   Exportação de dados

### Fase 3: Refinamento

-   Melhorias de UI/UX
-   Suporte offline
-   Configurações remotas

## Implementação Atual

Atualmente, esta pasta contém apenas este README como placeholder para o desenvolvimento futuro do aplicativo móvel. A implementação será iniciada após a conclusão e validação do sistema principal de monitoramento.

## Contribuindo

Se você deseja contribuir com o desenvolvimento do aplicativo móvel, consulte nosso [CONTRIBUTING.md](../CONTRIBUTING.md) para diretrizes gerais e entre em contato com a equipe para discutir o escopo e planejamento da implementação.

## Recursos de Aprendizado

Para desenvolvedores que desejam se familiarizar com as tecnologias previstas:

-   [Flutter - Documentação Oficial](https://flutter.dev/docs)
-   [Dart - Tour pela Linguagem](https://dart.dev/guides/language/language-tour)
-   [ThingSpeak API](https://www.mathworks.com/help/thingspeak/rest-api.html)
-   [UI/UX para Visualização de Dados](https://material.io/design/communication/data-visualization.html)

## Contato

Para dúvidas ou sugestões sobre o desenvolvimento do aplicativo móvel, entre em contato:

-   Email: [seu-email@exemplo.com]
-   GitHub: Abra uma issue no repositório do projeto
