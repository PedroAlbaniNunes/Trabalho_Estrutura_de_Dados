#include "functions.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct paciente {
    int id;
    char cpf[15];
    char nome[50];
    int idade;
    char data_cadastro[11];
};

typedef struct list_node {
    Paciente paciente;
    *next;
};

typedef struct list {
    ListNode *first;
    int tamanho;
};

void f_carregarDados(LinkedList *lista, const char *arquivo){
    FILE *arquivo = fopen("bd_paciente.csv", "r");
    if (!arquivo)
    {
        perror("Erro ao abrir arquivo");
        return EXIT_FAILURE;
    }
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivo)) {
        Paciente paciente;
        sscanf(linha, "%d,%[^,],%[^,],%d,%[^,\n]", &paciente.id, paciente.cpf, paciente.nome, &paciente.idade, paciente.data_cadastro);
        f_inserirPaciente(lista, paciente);
    }

    fclose(arquivo);
}

void f_salvarDados(LinkedList *lista, const char *arquivo){
    FILE *arquivo = fopen(arquivo, "w");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s para salvar os dados.\n", arquivo);
        return;
    }

    ListNode *atual = lista->first;
    while (atual) {
        fprintf(arquivo, "%d,%s,%s,%d,%s\n",
                atual->paciente.id, atual->paciente.cpf, atual->paciente.nome,
                atual->paciente.idade, atual->paciente.data_cadastro);
        atual = atual->next;
    }

    fclose(arquivo);
}

char *f_formataCPF(const char *cpf){ 
    // DECLARAÇÃO DE VARIÁVEIS
    static char cpfFormatado[15]; // Variável estática para armazenar o CPF formatado
    char cpf_block1[4], cpf_block2[4], cpf_block3[4], cpf_block4[3]; // Variáveis para os blocos do CPF
    //==================================================================================================

    if (strlen(cpf) != 11) { // Verifica se o CPF tem 11 dígitos
        printf("Erro: O CPF deve conter exatamente 11 dígitos.\n");
        return NULL; 
    }

    // Divisão do CPF em blocos
    sscanf(cpf, "%3c", cpf_block1); 
    cpf_block1[3] = '\0'; 
    sscanf(cpf + 3, "%3c", cpf_block2);
    cpf_block2[3] = '\0';
    sscanf(cpf + 6, "%3c", cpf_block3);
    cpf_block3[3] = '\0';
    sscanf(cpf + 9, "%2c", cpf_block4);
    cpf_block4[2] = '\0';

    sprintf(cpfFormatado, "%s.%s.%s-%s", cpf_block1, cpf_block2, cpf_block3, cpf_block4); // Formata o CPF e armazena na variável cpfFormatado

    return cpfFormatado; // Retorna o CPF formatado 
}

void f_printPaciente(Paciente *paciente){ // Função para imprimir os dados do paciente
    printf("ID: %d\n", paciente->id); 
    printf("CPF: %s\n", f_formataCPF(paciente->cpf)); 
    printf("Nome: %s\n", paciente->nome); 
    printf("Idade: %d\n", paciente->idade); 
    printf("Data de cadastro: %s\n", paciente->data_cadastro); 
}

void f_consultarPaciente(LinkedList *lista){ // Função para consultar um paciente 
    // DECLARAÇÃO DE VARIÁVEIS
    char opcao;
    //==================================================================================================

    do{
    prinf("1 - Por nome\n2 - Por CPF\n3 - Retornar ao menu principal");
    prinf("> ");
    scanf("%c", &opcao);
        switch(opcao){ // Switch case para escolher a opção de consulta
            case '1': // Caso a opção seja 1, o usuário irá consultar o paciente por nome
                char termoBusca[50]; // Variável para armazenar o termo de busca
                printf("Digite o nome: ");
                scanf(" %[^\n]", termoBusca); // Lê o nome do paciente
                ListNode *atual = lista->first; // Variável para percorrer a lista
                while (atual) { // Enquanto houver pacientes na lista
                    if (strstr(atual->paciente.nome, termoBusca)) { // Se o termo de busca for encontrado no nome do paciente
                        f_printPaciente(&atual->paciente); // Chama a função f_printPaciente() para imprimir os dados do paciente
                    }
                    else{
                        printf("Paciente não encontrado\n");
                    }
                    atual = atual->next; // Passa para o próximo paciente
                } 
                break;
                
            case '2': // Caso a opção seja 2, o usuário irá consultar o paciente por CPF
                printf("Digite o CPF: ");
                scanf(" %[^\n]", termoBusca); // Lê o CPF do paciente
                ListNode *atual = lista->first; // Variável para percorrer a lista
                while (atual) {  // Enquanto houver pacientes na lista
                    if (strcmp(atual->paciente.cpf, termoBusca) == 0) { // Se o CPF do paciente for igual ao termo de busca
                        f_printPaciente(&atual->paciente); // Chama a função f_printPaciente() para imprimir os dados do paciente
                    }
                    else{
                        printf("Paciente não encontrado\n");
                    }
                    atual = atual->next; // Passa para o próximo paciente
                }
                break;
                
            case '3': // Caso a opção seja 3, o usuário irá retornar ao menu principal
                printf("Retornando ao menu principal...");
                break;

        default: // Caso a opção seja diferente das opções acima, imprime que a opção é inválida
            printf("Opção inválida\n");
            break;
        }
    } while(opcao != '3'); // Enquanto a opção for diferente de 3, o usuário poderá escolher outra opção
}

void f_atualizarPaciente(LinkedList *lista){ // Função para atualizar um paciente
    // DECLARAÇÃO DE VARIÁVEIS
    int id, idadeAtualizada;
    char nomeAtualizado, data_registroAtualizada, cpfAtualizado, confirmacao;
    //==================================================================================================

    printf("Digite o ID do registro a ser atualizado: \n");
    scanf("%d", &id);
    
    ListNode *atual = lista->first; // Variável para percorrer a lista
    while(atual){ // Enquanto houver pacientes na lista
        if(atual->paciente.id == id){ // Se o ID do paciente for igual ao ID digitado
            printf("Paciente encontrado! Atualize os dados: \n");
            f_printPaciente(&atual->paciente); // Chama a função f_printPaciente() para imprimir os dados do paciente
            printf("Digite o novo valor para os campos CPF (apenas dígitos), Nome, Idade e Data_Cadastro (para manter o valor atual de um campo, digite ’-’):");
            
            printf("CPF atual: %s\n,  Digite o novo CPF: ", f_formataCPF(atual->paciente.cpf));
            scanf(" %[^\n]", cpfAtualizado); // Lê o novo CPF do paciente

            printf("Nome atual: %s\n,  Digite o novo Nome: ", atual->paciente.nome);
            scanf(" %[^\n]", nomeAtualizado); // Lê o novo nome do paciente

            printf("Idade atual: %d\n,  Digite a nova Idade: ", atual->paciente.idade);
            scanf(" %d", &idadeAtualizada); // Lê a nova idade do paciente

            printf("Data de cadastro atual: %s\n,  Digite a nova Data de Cadastro: ", atual->paciente.data_cadastro);
            scanf(" %[^\n]", data_registroAtualizada); // Lê a nova data de cadastro do paciente
        
            // Exibir os dados do paciente antes de confirmar a atualização
            printf("Os dados atualizados são: \n"); 
            printf("CPF: %s\n", f_formataCPF(cpfAtualizado));
            printf("Nome: %s\n", nomeAtualizado);
            printf("Idade: %d\n", idadeAtualizada);
            printf("Data de cadastro: %s\n", data_registroAtualizada);

            printf("Confirma a atualização? (S/N): "); // Pergunta se o usuário confirma a atualização
            scanf(" %c", &confirmacao);
            if(confirmacao == 'S' || confirmacao == 's'){ // Se a confirmação for 'S' ou 's', atualiza os dados do paciente
                if(cpfAtualizado != '-'){ // Se o novo CPF for diferente de '-', atualiza o CPF do paciente
                    strcpy(atual->paciente.cpf, cpfAtualizado); // Copia o novo CPF para o CPF do paciente
                }

                if(nomeAtualizado != '-'){ // Se o novo nome for diferente de '-', atualiza o nome do paciente
                    strcpy(atual->paciente.nome, nomeAtualizado); // Copia o novo nome para o nome do paciente
                }
                
                if(idadeAtualizada != '-'){ // Se a nova idade for diferente de '-', atualiza a idade do paciente
                    strcpy(atual->paciente.idade, idadeAtualizada); // Copia a nova idade para a idade do paciente
                }
                
                if(data_registroAtualizada != '-'){ // Se a nova data de cadastro for diferente de '-', atualiza a data de cadastro do paciente
                    strcpy(atual->paciente.data_cadastro, data_registroAtualizada); // Copia a nova data de cadastro para a data de cadastro do paciente
                }
            }
            else // Se a confirmação for diferente de 'S' ou 's', cancela a atualização
                printf("Atualização cancelada.");
        }
        else // Se o ID do paciente for diferente do ID digitado, imprime que o paciente não foi encontrado
            printf("Paciente com ID informado não encontrado\n");
            
        atual = atual->next; // Passa para o próximo paciente
    }
    printf("Registro atualizado com sucesso.");
}

void f_removerPaciente(LinkedList *lista){
    // DECLARAÇÃO DE VARIÁVEIS
    int id; // Variável para armazenar o ID do paciente
    char confirmacao;  // Função para remover um paciente
    //==================================================================================================

    printf("Digite o ID do paciente a ser removido: ");
    scanf("%d", &id);

    ListNode *anterior = NULL; // Variável para armazenar o nó anterior
    ListNode *atual = lista->first; // Variável para percorrer a lista

    while (atual) { // Enquanto houver pacientes na lista
        if (atual->paciente.id == id) { // Se o ID do paciente for igual ao ID digitado
            // Exibir os dados do paciente antes de confirmar a remoção
            printf("\nPaciente encontrado:\n");
            printf("ID: %d\n", atual->paciente.id);
            printf("Nome: %s\n", atual->paciente.nome);
            printf("CPF: %s\n", atual->paciente.cpf);
            printf("Idade: %d\n", atual->paciente.idade);
            printf("Data de cadastro: %s\n", atual->paciente.data_cadastro);

            printf("\nDeseja realmente remover este paciente? (S/N): "); 
            scanf(" %c", &confirmacao);

            if (confirmacao == 'S' || confirmacao == 's') { // Se a confirmação for 'S' ou 's', remove o paciente
                if (anterior){ // Se houver um nó anterior, o próximo nó do anterior será o próximo nó do nó atual
                    anterior->next = atual->next; 
                } 
                else { // Se não houver um nó anterior, o primeiro nó da lista será o próximo nó do nó atual
                    lista->first = atual->next; 
                }
                free(atual); // Libera a memória do nó atual
                lista->tamanho--; // Decrementa o tamanho da lista
                printf("Paciente removido com sucesso.\n");
            } 
            else  // Se a confirmação for diferente de 'S' ou 's', cancela a remoção
                printf("Remoção cancelada.\n");
        }
        anterior = atual; // O nó anterior será o nó atual
        atual = atual->next; // O nó atual será o próximo nó
    }
    printf("Nenhum paciente encontrado com o ID fornecido.\n");
}
    
// void f_inserirPaciente(){}

void f_imprimirLista(LinkedList *lista){
    char linha[256];
    printf("ID/tCPF/t/tNome/t/tIdade/t/tData de Registro/n");
    printf("------------------------------------------------");
    while (fgets(linha, sizeof(linha), lista)){
        char id[10], cpf[14], nome[50], idade[5], data_registro[10];

        if (sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%s", id, cpf, nome, idade, data_registro) == 5){
            printf("%s\t%s\t%s\t%s\t%s\n", id, cpf, nome, idade, data_registro);
        }
        else{
            prinf("Linha faltando informação.");
        }
    }
}   
