#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>

void f_carregarDados(LinkedList *lista, const char *arquivo) { // Função para carregar os dados do arquivo
    FILE *fp = fopen(arquivo, "r"); // Abre o arquivo para leitura
    if (!fp) {
        perror("Erro ao abrir o arquivo"); 
        return;
    }

    char linha[256]; // Buffer para armazenar cada linha do arquivo
    while (fgets(linha, sizeof(linha), fp)) { // Lê cada linha do arquivo
        if (strlen(linha) <= 1) { // Ignora linhas em branco
            continue;
        }

        Paciente paciente;
        if (sscanf(linha, "%d,%14[^,],%49[^,],%d,%10[^\n]", 
                   &paciente.id,
                   paciente.cpf,
                   paciente.nome,
                   &paciente.idade, //
                   paciente.data_cadastro) == 5) { // Lê os dados da linha
            f_adicionarNaLista(lista, &paciente); // Adiciona o paciente à lista
        } else {
            fprintf(stderr, "Erro ao ler a linha: %s", linha);
        }
    }

    fclose(fp);
}

void f_salvarDados(LinkedList *lista, const char *arquivo) { // Função para salvar os dados no arquivo
    FILE *fp = fopen(arquivo, "w"); 
    if (!fp) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    ListNode *atual = lista->first; // Começa pelo primeiro nó da lista
    while (atual) {
        fprintf(fp, "%d,%s,%s,%d,%s\n",
                atual->paciente.id,
                atual->paciente.cpf,
                atual->paciente.nome,
                atual->paciente.idade,
                atual->paciente.data_cadastro); // Escreve os dados do paciente no arquivo
        atual = atual->next;
    }

    fclose(fp);
}
