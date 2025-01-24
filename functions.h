#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct paciente Paciente;
typedef struct list LinkedList;    
typedef struct list_node ListNode; 

void f_carregarDados(LinkedList *lista, const char *arquivo);

void f_salvarDados(LinkedList *lista, const char *arquivo);

void f_consultarPaciente(LinkedList *lista);

void f_atualizarPaciente(LinkedList *lista);

void f_removerPaciente(LinkedList *lista);

void f_inserirPaciente(LinkedList *lista, Paciente paciente);

void f_imprimirLista(Paciente paciente);

char *f_formataCPF(const char *cpf);

#endif