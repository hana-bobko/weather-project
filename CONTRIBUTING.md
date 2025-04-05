# Contribuindo para o Sistema de Monitoramento Ambiental

Primeiramente, agradecemos pelo seu interesse em contribuir com nosso projeto! Este documento fornece diretrizes e instruções para quem deseja colaborar.

## Índice

-   [Código de Conduta](#código-de-conduta)
-   [Como Posso Contribuir?](#como-posso-contribuir)
    -   [Reportando Bugs](#reportando-bugs)
    -   [Sugerindo Melhorias](#sugerindo-melhorias)
    -   [Contribuindo com Código](#contribuindo-com-código)
    -   [Contribuindo com Documentação](#contribuindo-com-documentação)
-   [Guia de Estilo](#guia-de-estilo)
    -   [Mensagens de Commit](#mensagens-de-commit)
    -   [Estilo de Código](#estilo-de-código)
    -   [Documentação](#documentação)
-   [Processo de Pull Request](#processo-de-pull-request)
-   [Desenvolvimento Local](#desenvolvimento-local)

## Código de Conduta

Este projeto e todos os participantes estão sob um Código de Conduta que promove um ambiente aberto, acolhedor e inclusivo. Esperamos que todos os colaboradores ajam com respeito e empatia.

## Como Posso Contribuir?

### Reportando Bugs

Encontrou um bug? Por favor, crie uma issue no GitHub seguindo estas diretrizes:

1. **Use um título claro e descritivo** que identifique o problema
2. **Descreva os passos para reproduzir o bug** com o máximo de detalhes possível
3. **Forneça informações específicas** sobre o seu ambiente (sistema operacional, versão do Arduino IDE, hardware utilizado)
4. **Inclua logs ou capturas de tela** que possam ajudar a entender o problema
5. **Se possível, sugira uma correção** ou indique onde no código o problema pode estar

### Sugerindo Melhorias

Tem uma ideia para melhorar o projeto? Adoraríamos ouvir! Crie uma issue de "feature request" contendo:

1. **Descrição clara da melhoria** proposta
2. **Justificativa** explicando por que essa melhoria seria benéfica
3. **Possíveis implementações** ou ideias de como realizá-la
4. **Referências ou exemplos** de implementações similares, se aplicável

### Contribuindo com Código

Para contribuir com código:

1. **Faça um fork do repositório**
2. **Crie um branch para sua feature ou correção**:
    ```
    git checkout -b feature/nome-da-feature
    ```
    ou
    ```
    git checkout -b fix/nome-do-bug
    ```
3. **Desenvolva suas mudanças**
4. **Teste completamente** as alterações
5. **Faça commit das mudanças** seguindo as diretrizes de mensagem de commit
6. **Push para o seu fork**
7. **Submeta um Pull Request** para o branch main do nosso repositório

### Contribuindo com Documentação

A documentação é crucial para nosso projeto! Você pode contribuir:

1. **Corrigindo erros** na documentação existente
2. **Melhorando explicações** para torná-las mais claras
3. **Adicionando exemplos** de uso do sistema
4. **Criando tutoriais** para diferentes aspectos do projeto
5. **Traduzindo a documentação** para outros idiomas

## Guia de Estilo

### Mensagens de Commit

-   Use o tempo presente ("Adiciona feature" não "Adicionada feature")
-   Use o modo imperativo ("Muda..." não "Mudando...")
-   Limite a primeira linha a 72 caracteres
-   Inclua referências a issues ou pull requests quando relevante
-   Considere iniciar a mensagem de commit com um emoji que represente o tipo de mudança:
    -   ✨ (`:sparkles:`) para novas features
    -   🐛 (`:bug:`) para correções de bugs
    -   📚 (`:books:`) para documentação
    -   ♻️ (`:recycle:`) para refatoração de código
    -   🧪 (`:test_tube:`) para adicionar testes

### Estilo de Código

#### Para Arduino/C++:

-   Use indentação de 2 espaços (sem tabs)
-   Nomes de funções e variáveis em camelCase
-   Nomes de constantes em UPPER_CASE
-   Comentários em português, claros e significativos
-   Adicione comentários que expliquem "por quê", não apenas "o quê"
-   Evite linhas com mais de 80 caracteres

#### Para JavaScript/HTML/CSS:

-   Use indentação de 2 espaços (sem tabs)
-   Use ponto e vírgula no final das declarações JavaScript
-   Prefira aspas simples para strings em JavaScript
-   Mantenha o CSS organizado por componentes
-   Use nomes de classes significativos e em kebab-case

### Documentação

-   Escreva em português claro e acessível
-   Use Markdown para formatação
-   Inclua imagens e diagramas quando úteis para explicar conceitos
-   Mantenha a documentação atualizada com o código
-   Inclua exemplos de uso sempre que possível

## Processo de Pull Request

1. Verifique se seu código segue as diretrizes de estilo
2. Verifique se todos os testes passam
3. Atualize a documentação, se necessário
4. Certifique-se de que seu branch está atualizado com a branch main
5. Descreva claramente as mudanças no PR, incluindo capturas de tela se aplicável
6. Aguarde a revisão e esteja pronto para fazer ajustes conforme solicitado

## Desenvolvimento Local

Para configurar o ambiente de desenvolvimento local:

1. **Clone o repositório**:

    ```
    git clone https://github.com/seu-usuario/sistema-monitoramento-ambiental-escolar.git
    cd sistema-monitoramento-ambiental-escolar
    ```

2. **Configure o Arduino IDE**:

    - Instale a Arduino IDE 1.8+ ou PlatformIO
    - Adicione suporte para ESP32 (se estiver usando)
    - Instale as bibliotecas necessárias (listadas em [docs/especificacoes-tecnicas.md](docs/especificacoes-tecnicas.md))

3. **Teste o código**:

    - Conecte o hardware conforme documentado
    - Carregue o código para verificar seu funcionamento

4. **Para o dashboard web**:
    - Navegue até a pasta `dashboard/`
    - Abra os arquivos HTML em um navegador para testar localmente

---

Se você tiver dúvidas adicionais, não hesite em criar uma issue ou entrar em contato conosco. Obrigado por contribuir!
