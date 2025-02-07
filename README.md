# **Simulação de Sistema de Gerenciamento de Dados de Paciente**

## **Descrição do Projeto**
Este repositório contém a implementação de estruturas de dados fundamentais para a disciplina de Estrutura de Dados, lecionada pelo Prof. Dr. Thiago Meireles Paixão. O objetivo é demonstrar o uso eficiente de Tipos Abstratos de Dados (TADs) para resolver problemas computacionais, garantindo modularidade, eficiência e boas práticas de programação.

## **Estrutura do Repositório**
A organização do projeto segue uma estrutura modular para facilitar a manutenção e a compreensão do código:

```
📂 Trabalho_Estrutura_de_Dados
│── 📂 ESPECIFICAÇÃO   # Documentação técnica e requisitos do projeto  
│── 📂 ARQUIVO         # Manipulação de arquivos  
│── 📂 LISTA           # Implementação de listas encadeadas e operações  
│── 📂 MENU            # Interface do menu do programa  
│── 📂 PACIENTES       # Gerenciamento de dados dos pacientes  
│── 📜 Makefile        # Arquivo para compilação automática do projeto  
│── 📜 README.md       # Documentação do projeto  
│── 📜 bd_pacientes.csv # Arquivo de dados dos pacientes utilizado pelo programa  
│── 📜 main.c          # Arquivo principal do programa  
```

## **Pacientes**

### **Estrutura Pacientes**
| Variável | Tipo  | Função |
|----------|------|--------|
| id  | int | Registrar o ID único e individual dos pacientes |
| cpf | char | Armazenar o CPF dos pacientes |
| nome | char | Armazenar o nome dos pacientes |
| idade | int | Registrar a idade dos pacientes |
| data_cadastro | char | Registrar a data de cadastro dos pacientes |

### **Funções do Paciente**
| Função | Descrição | Parâmetros | Retorna |
|--------|----------|------------|---------|
| f_printPaciente | Imprime o paciente | Paciente *paciente | void |
| f_consultarPaciente | Consulta um paciente na lista | LinkedList *lista | void |
| f_atualizarPaciente | Atualiza os dados de um paciente | LinkedList *lista | void |
| f_inserirNovoPaciente | Insere um novo paciente | LinkedList *lista | void |
| f_removerPaciente | Remove um paciente da lista | LinkedList *lista | void |
| maior_id | Verifica o maior id na lista | LinkedList *lista | int |
| f_formataCPF | Formata o CPF | const char *cpf | char |

## **Menu**
### **Funções do Menu**
| Função | Descrição | Parâmetros | Retorna |
|--------|----------|------------|---------|
| f_exibirMenu | Exibe o menu inicial | LinkedList *lista | void |

## **Lista**
### **Estrutura list_node**
| Variável | Tipo | Função |
|----------|------|--------|
| paciente | Paciente | Armazena os dados do paciente dentro do nó da lista |
| next | struct list_node * | Aponta para o próximo nó da lista |

### **Estrutura list**
| Variável | Tipo | Função |
|----------|------|--------|
| first | ListNode * | Aponta para o primeiro nó da lista encadeada |
| tamanho | int | Armazena o número de nós da lista |

### **Funções da Lista**
| Função | Descrição | Parâmetros | Retorna |
|--------|----------|------------|---------|
| f_inicializarLista | Inicializa a lista encadeada | LinkedList *lista | void |
| f_adicionarNaLista | Adiciona dados à lista encadeada | LinkedList *lista, Paciente *novoPaciente | void |
| f_imprimirLista | Imprime os dados da lista encadeada | LinkedList *lista | void |

## **Arquivo**
### **Funções do Arquivo**
| Função | Descrição | Parâmetros | Retorna |
|--------|----------|------------|---------|
| f_carregarDados | Carrega os dados do arquivo para o programa | LinkedList *lista, const char *arquivo | void |
| f_salvarDados | Salva os dados adicionados/alterados no arquivo | LinkedList *lista, const char *arquivo | void |

# **Tipos Abstratos de Dados (TADs) Utilizados**

## **1. TAD Lista Encadeada (`LinkedList` e `ListNode`)**
- **Finalidade**: Armazena e manipula dinamicamente os registros de pacientes.
- **Principais operações**:
  - Inserção e remoção de pacientes.
  - Busca de pacientes na lista.
  - Percorrer a lista para exibição ou modificação de dados.

## **2. TAD Paciente (`Paciente`)**
- **Finalidade**: Representa um paciente, armazenando seus dados pessoais.
- **Principais operações**:
  - Criação de novos pacientes.
  - Modificação e atualização de dados do paciente.
  - Exibição das informações cadastradas.

## **3. TAD Arquivo**
- **Finalidade**: Gerencia a persistência de dados dos pacientes em um arquivo `.csv`.
- **Principais operações**:
  - Salvar e carregar dados de pacientes.
  - Garantir que os registros sejam armazenados entre execuções do programa.

## **4. TAD Menu**
- **Finalidade**: Controla a interface de interação com o usuário.
- **Principais operações**:
  - Apresentar opções do sistema.
  - Capturar e processar comandos do usuário.
  - Direcionar para as operações correspondentes.

## **Integrantes do Projeto**

| Aluno | GitHub | LinkedIn |
|-------|--------|----------|
| Gustavo Saraiva Mariano | [![GitHub](https://img.shields.io/badge/github-black?style=for-the-badge&logo=github)](https://github.com/saraivagustavo) | [![LinkedIn](https://img.shields.io/badge/linkedin-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/gustavo-saraiva-mariano/) |
| Pedro Henrique Albani Nunes | [![GitHub](https://img.shields.io/badge/github-black?style=for-the-badge&logo=github)](https://github.com/PedroAlbaniNunes) | [![LinkedIn](https://img.shields.io/badge/linkedin-blue?style=for-the-badge&logo=linkedin)](https://www.linkedin.com/in/pedro-henrique-albani-nunes-33a729270/) |
