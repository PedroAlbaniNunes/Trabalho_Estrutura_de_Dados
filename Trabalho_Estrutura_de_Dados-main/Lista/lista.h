#ifndef LISTA_H
#define LISTA_H

#include "pacientes.h"

typedef struct list_node {
    Paciente paciente;
    struct list_node *next;
} ListNode;

typedef struct list {
    ListNode *first;
    int tamanho;
} LinkedList;


void f_inicializarLista(LinkedList *lista);
void f_adicionarNaLista(LinkedList *lista, Paciente *novoPaciente);
void f_imprimirLista(LinkedList *lista);

#endif
