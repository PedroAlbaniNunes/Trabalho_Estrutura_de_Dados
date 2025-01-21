#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Paciente Paciente;

void f_consultarPaciente();

void f_atualizarPaciente();

void f_removerPaciente();

void f_inserirPaciente();

void f_imprimirLista();

char *f_formataCPF(const char *cpf);

#endif