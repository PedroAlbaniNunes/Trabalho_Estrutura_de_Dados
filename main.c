#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// #define MAX_LINHA 1024
int main(){
    char opcao;
    do {
        printf("\n=== Health Sys ===\n1 - Consultar paciente\n2 - Atualizar paciente\n3 - Remover paciente\n4 - Inserir paciente\n5 - Imprimir lista de pacientes\nQ - Sair \n");
        printf("> ");
        scanf(" %c", &opcao);

        switch(opcao) {
            case '1': // Caso a opção seja 1, chama a função de consultar paciente
                f_consultarPaciente();
                break;
            case '2': // Caso a opção seja 2, chama a função de atualizar paciente
                f_atualizarPaciente();
                break;
            case '3': // Caso a opção seja 3, chama a função de remover paciente
                f_removerPaciente();
                break;
            case '4': // Caso a opção seja 4, chama a função de inserir paciente
                f_inserirPaciente();
                break;
            case '5': // Caso a opção seja 5, chama a função de imprimir lista de pacientes
                f_imprimirLista();
                break;
            case 'Q': // Caso a opção seja Q, o programa encerra
            case 'q': // Caso a opção seja q, o programa encerra
                printf("Saindo...\n");
                break;
        default: // Caso a opção seja diferente das opções acima, imprime que a opção é inválida
            printf("Opção inválida\n");
            break;
        }
    } while (opcao != 'Q' && opcao != 'q'); // Enquanto a opção for diferente de Q ou q, o programa continua rodando

    return 0;
}