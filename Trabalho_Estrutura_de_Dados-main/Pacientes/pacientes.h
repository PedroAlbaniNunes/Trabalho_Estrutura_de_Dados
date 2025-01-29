#ifndef PACIENTE_H
#define PACIENTE_H

#include <stdio.h>
#include <string.h>

typedef struct list LinkedList;

typedef struct paciente {
    int id;
    char cpf[15];
    char nome[50];
    int idade;
    char data_cadastro[11];
} Paciente;

void f_printPaciente(Paciente *paciente);
void f_consultarPaciente(LinkedList *lista);
void f_atualizarPaciente(LinkedList *lista);
void f_inserirNovoPaciente(LinkedList *lista);
void f_imprimirLista(LinkedList *lista);
void f_removerPaciente(LinkedList *lista);
int maior_id(LinkedList *lista);

#endif
