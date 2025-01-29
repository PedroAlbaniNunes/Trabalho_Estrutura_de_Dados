#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void f_inicializarLista(LinkedList *lista) {
    lista->first = NULL;
    lista->tamanho = 0;
}

void f_adicionarNaLista(LinkedList *lista, Paciente *novoPaciente) { // Função para adicionar um paciente à lista
    // Aloca memória para o novo nó
    ListNode *novoNo = (ListNode *)malloc(sizeof(ListNode));
    if (!novoNo) { // Verifica se a alocação foi bem-sucedida
        perror("Erro ao alocar memória para o novo nó");
        exit(EXIT_FAILURE);
    }

    // Preenche os dados do novo nó
    novoNo->paciente = *novoPaciente;
    novoNo->next = NULL;

    // Verifica se a lista está vazia
    if (lista->first == NULL) {
        lista->first = novoNo; // O novo nó será o primeiro da lista
    } else {
        // Percorre a lista até encontrar o último nó
        ListNode *atual = lista->first;
        while (atual->next != NULL) {
            atual = atual->next;
        }
        atual->next = novoNo; // Adiciona o novo nó no final da lista
    }

    // Incrementa o tamanho da lista
    lista->tamanho++;
}

void f_imprimirLista(LinkedList *lista) {
    if (lista->first == NULL) { // Verifica se a lista está vazia
        printf("A lista está vazia.\n");
        return;
    }

    printf("ID\tCPF\t\t\tNome\t\tIdade\tData de Registro\n");
    printf("-------------------------------------------------------------\n");

    ListNode *atual = lista->first;

    while (atual != NULL) { // Percorre os nós da lista
        // Imprime os dados do paciente no nó atual
        printf("%d\t%s\t%s\t%d\t%s\n",
               atual->paciente.id,
               atual->paciente.cpf,
               atual->paciente.nome,
               atual->paciente.idade,
               atual->paciente.data_cadastro);
        atual = atual->next;
    }
}
