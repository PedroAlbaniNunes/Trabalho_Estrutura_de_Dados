#include "menu.h"
#include "arquivo.h"
#include "pacientes.h"
#include "lista.h"
#include <stdio.h>

void f_exibirMenu(LinkedList *lista) {
    char opcao; // Variável para armazenar a opção do usuário

    do { // Loop para exibir o menu até que o usuário escolha sair
        printf("\n=== Health Sys ===\n");
        printf("1 - Consultar paciente\n");
        printf("2 - Atualizar paciente\n");
        printf("3 - Remover paciente\n");
        printf("4 - Inserir paciente\n");
        printf("5 - Imprimir lista de pacientes\n");
        printf("Q - Sair\n> ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1': 
                f_consultarPaciente(lista);
                break;
            case '2': 
                f_atualizarPaciente(lista);
                break;
            case '3': 
                f_removerPaciente(lista);
                break;
            case '4': 
                f_inserirNovoPaciente(lista);
                break;
            case '5':
                f_imprimirLista(lista);
                break;
            case 'Q':
            case 'q':
                f_salvarDados(lista, "bd_paciente.csv");
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 'Q' && opcao != 'q'); // Repete até que o usuário escolha sair
}