# Sistema de Monitoramento Ambiental para Escolas Públicas

![Status do Projeto](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)
![Licença](https://img.shields.io/badge/Licença-MIT-green)

## 📋 Descrição

Sistema de baixo custo baseado em microcontroladores para monitoramento de variáveis ambientais em escolas públicas. Este projeto foi desenvolvido como trabalho de extensão para a disciplina de Programação de Microcontroladores do curso de Ciência da Computação.

O sistema coleta dados de temperatura, umidade, qualidade do ar e níveis de ruído em salas de aula, permitindo análises sobre as condições ambientais que podem afetar o aprendizado e o bem-estar dos estudantes.

## 🎯 Objetivos

-   Monitorar condições ambientais em salas de aula (temperatura, umidade, CO2, ruído)
-   Fornecer uma interface simples para visualização dos dados
-   Capacitar a comunidade escolar para interpretar os dados coletados
-   Propor melhorias nas condições ambientais com base em evidências
-   Criar uma solução de baixo custo que possa ser replicada em outras escolas

## 🔧 Tecnologias Utilizadas

-   **Microcontrolador:** ESP32 (alternativa: Arduino Uno + módulo WiFi)
-   **Sensores:**
    -   DHT22 (temperatura e umidade)
    -   MQ-135 (qualidade do ar/CO2)
    -   KY-038 (nível de ruído)
-   **Armazenamento:** Cartão SD e/ou ThingSpeak (nuvem)
-   **Visualização:** Dashboard Web responsivo

## 📊 Funcionalidades

-   Coleta e armazenamento de dados ambientais
-   Alerta em tempo real quando parâmetros estão fora dos limites recomendados
-   Visualização de histórico de dados por período
-   Relatórios semanais/mensais
-   Interface amigável para uso por professores sem conhecimento técnico

## 🛠️ Instalação e Configuração

Consulte nosso [Guia de Instalação](docs/guia-instalacao.md) para instruções detalhadas sobre como montar e configurar o sistema.

## 📚 Documentação

-   [Especificações Técnicas](docs/especificacoes-tecnicas.md)
-   [Manual do Usuário](docs/manual-usuario.md)
-   [Esquema de Conexões](hardware/esquematicos/esquema_principal.pdf)
-   [Lista de Componentes](hardware/lista_componentes.md)

## 📷 Fotos e Evidências

Fotos do sistema implementado e das oficinas realizadas com a comunidade escolar podem ser encontradas na pasta [fotos-evidencias](fotos-evidencias/).

## 🤝 Como Contribuir

Contribuições são bem-vindas! Consulte [CONTRIBUTING.md](CONTRIBUTING.md) para saber como colaborar com este projeto.

## 📝 Projeto de Extensão

Este projeto foi desenvolvido como trabalho de extensão acadêmica. A documentação completa do projeto de extensão pode ser encontrada em:

-   [Diagnóstico e Teorização](docs/projeto-extensao/diagnostico.md)
-   [Planejamento do Projeto](docs/projeto-extensao/planejamento.md)
-   [Relatório Final](docs/projeto-extensao/relatorio-final.md)

## 📄 Licença

Este projeto está licenciado sob a Licença MIT - veja o arquivo [LICENSE](LICENSE) para detalhes.

## ✉️ Contato

[Seu Nome] - [Seu Email]

Link do projeto: [https://github.com/seu-usuario/sistema-monitoramento-ambiental-escolar](https://github.com/seu-usuario/sistema-monitoramento-ambiental-escolar)
