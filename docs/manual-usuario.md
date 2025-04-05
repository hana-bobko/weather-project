# Manual do Usuário

## Sistema de Monitoramento Ambiental para Escolas Públicas

## Sumário

1. [Introdução](#introdução)
2. [Visão Geral do Sistema](#visão-geral-do-sistema)
3. [Instalação](#instalação)
4. [Inicialização](#inicialização)
5. [Interface de Usuário](#interface-de-usuário)
6. [Interpretação dos Dados](#interpretação-dos-dados)
7. [Alertas](#alertas)
8. [Manutenção](#manutenção)
9. [Solução de Problemas](#solução-de-problemas)
10. [Perguntas Frequentes](#perguntas-frequentes)

## Introdução

Bem-vindo ao Manual do Usuário do Sistema de Monitoramento Ambiental para Escolas Públicas. Este sistema foi desenvolvido para monitorar e registrar condições ambientais em salas de aula, fornecendo dados que podem auxiliar na melhoria do ambiente de aprendizagem.

O sistema monitora quatro parâmetros ambientais importantes:

-   Temperatura
-   Umidade
-   Qualidade do ar
-   Nível de ruído

Este manual foi elaborado para professores, funcionários e gestores escolares, não sendo necessário conhecimento técnico para operar o sistema.

## Visão Geral do Sistema

O sistema é composto por:

-   **Unidade principal**: Contém o microcontrolador e os sensores
-   **Display LCD**: Mostra os dados em tempo real
-   **Armazenamento local**: Cartão SD que registra todos os dados
-   **Interface web** (opcional): Acesso remoto às leituras e histórico

## Instalação

O sistema já vem montado e pronto para uso, necessitando apenas de alguns passos simples para instalação:

1. **Escolha do local**:

    - Posicione a unidade na parede a aproximadamente 1,5m do chão
    - Evite locais próximos a janelas, ar-condicionado, portas ou fontes de calor
    - Mantenha longe de áreas com incidência direta de sol

2. **Alimentação**:

    - Conecte o cabo de alimentação à tomada mais próxima
    - O sistema possui bateria interna para backup em caso de falha de energia

3. **Configuração de rede** (se aplicável):
    - Siga as instruções na tela para conectar à rede WiFi da escola
    - Anote o endereço IP exibido para acesso à interface web

## Inicialização

Ao ligar o sistema pela primeira vez:

1. Pressione o botão de liga/desliga localizado na lateral da unidade
2. Aguarde a sequência de inicialização (aproximadamente 30 segundos)
3. O display LCD irá mostrar "Sistema Pronto" quando estiver operacional
4. O sistema começará a coletar dados automaticamente

## Interface de Usuário

### Display LCD

O display LCD mostra informações alternando entre os diferentes parâmetros:

-   **Tela 1**: Temperatura (°C) e Umidade (%)
-   **Tela 2**: Qualidade do ar (ppm de CO2)
-   **Tela 3**: Nível de ruído (dB)

As telas alternam automaticamente a cada 3 segundos.

### Interface Web (opcional)

Se o sistema estiver conectado à rede WiFi, você pode acessar os dados pelo navegador:

1. Abra qualquer navegador web (Chrome, Firefox, etc.)
2. Digite o endereço IP fornecido durante a instalação
3. Use as credenciais padrão:
    - Usuário: `escola`
    - Senha: `ambiente123`

Na interface web você encontrará:

-   Dados em tempo real
-   Gráficos históricos
-   Opções para download dos dados
-   Configurações de alertas

## Interpretação dos Dados

### Temperatura

-   **Ideal**: 20°C a 26°C
-   **Aceitável**: 18°C a 30°C
-   **Ação recomendada quando fora da faixa**: Ajustar ar-condicionado, ventilação natural ou aquecedores

### Umidade

-   **Ideal**: 40% a 60%
-   **Aceitável**: 30% a 70%
-   **Ação recomendada quando fora da faixa**: Usar umidificadores ou desumidificadores, melhorar ventilação

### Qualidade do Ar (CO2)

-   **Ideal**: Abaixo de 800 ppm
-   **Aceitável**: Até 1000 ppm
-   **Preocupante**: Acima de 1000 ppm
-   **Ação recomendada quando alta**: Aumentar ventilação, abrir janelas, reduzir ocupação do espaço

### Nível de Ruído

-   **Ideal para sala de aula**: Abaixo de 50 dB
-   **Aceitável**: Até 70 dB
-   **Prejudicial para concentração**: Acima de 70 dB
-   **Ação recomendada quando alto**: Identificar e reduzir fontes de ruído, usar materiais absorventes acústicos

## Alertas

O sistema emite alertas quando os parâmetros estão fora dos limites recomendados:

-   **Alerta visual**: O display LCD piscará
-   **Alerta no sistema**: Registro no arquivo de log
-   **Alerta por e-mail** (opcional): Se configurado na interface web

## Manutenção

O sistema requer manutenção mínima:

-   **Limpeza**: Mensalmente, limpe os sensores com um pano macio e seco
-   **Verificação do cartão SD**: A cada 3 meses, verifique o espaço livre
-   **Calibração**: Anual, contate a equipe técnica para recalibração dos sensores
-   **Bateria**: Substitua a cada 2 anos (se aplicável)

## Solução de Problemas

| Problema               | Possível Causa                 | Solução                                   |
| ---------------------- | ------------------------------ | ----------------------------------------- |
| Display apagado        | Falta de energia               | Verifique a fonte de alimentação          |
| Valores inconsistentes | Sensor com poeira ou obstruído | Limpe cuidadosamente os sensores          |
| Falha na conexão WiFi  | Problema na rede               | Reinicie o sistema e o roteador           |
| Cartão SD cheio        | Muitos dados armazenados       | Faça backup e formate o cartão            |
| Sistema travado        | Falha de software              | Pressione o botão de reset por 5 segundos |

## Perguntas Frequentes

**P: Com que frequência os dados são coletados?**  
R: O sistema coleta dados a cada minuto e calcula médias a cada hora.

**P: É possível exportar os dados para análise externa?**  
R: Sim, através da interface web você pode exportar os dados em formato CSV ou Excel.

**P: O sistema funciona durante queda de energia?**  
R: Se equipado com bateria, o sistema pode operar por até 6 horas sem energia elétrica.

**P: Onde posso obter suporte técnico?**  
R: Entre em contato com a equipe desenvolvedora pelo e-mail [seu-email@exemplo.com].

---

Para mais informações ou assistência adicional, consulte a documentação completa do projeto disponível em nosso repositório GitHub: [github.com/seu-usuario/sistema-monitoramento-ambiental-escolar](https://github.com/seu-usuario/sistema-monitoramento-ambiental-escolar)
