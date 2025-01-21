#include "functions.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Paciente {
    int id;
    char cpf[15];
    char nome[50];
    int idade;
    char data_cadastro[11];
    struct Paciente *proximo;
} Paciente;

char *f_formataCPF(const char *cpf){ 
    static char cpfFormatado[15]; // Variável estática para armazenar o CPF formatado
    char cpf_block1[4], cpf_block2[4], cpf_block3[4], cpf_block4[3]; // Variáveis para os blocos do CPF

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

// void f_consultarPaciente(){ // Função para consultar um paciente 
//     char opcao;
//     do{
//     prinf("1 - Por nome\n2 - Por CPF\n3 - Retornar ao menu principal");
//     prinf("> ");
//     scanf("%c", &opcao);

//     switch(opcao){ // Switch case para escolher a opção de consulta
//         case '1': // Caso a opção seja 1, o usuário irá consultar o paciente por nome
//             char nome = NULL; // Variável para armazenar o nome do paciente
//             prinf("Digite o nome do paciente: \n");
//             prinf("> ");
//             scanf("%c", &nome); // Recebe o nome do paciente
//             break; 

//         case '2': // Caso a opção seja 2, o usuário irá consultar o paciente por CPF
//             int cpf = NULL; // Variável para armazenar o CPF do paciente
//             prinf("Digite o CPF do paciente(apenas digitos): ");
//             prinf("> ");
//             scanf("%i", &cpf);
//             cpf = f_formataCPF(cpf); // Armazena o CPF formatado na variável cpf
//             printf("CPF formatado: %s", cpf); // Imprime o CPF formatado
//             break;
//         case '3': // Caso a opção seja 3, o usuário irá retornar ao menu principal
//             printf("Retornando ao menu principal...");
//             break;
//     default: // Caso a opção seja diferente das opções acima, imprime que a opção é inválida
//         printf("Opção inválida\n");
//         break;
//     }
//     } while(opcao != '3'); // Enquanto a opção for diferente de 3, o usuário poderá escolher outra opção
    
// }

// void f_atualizarPaciente(){}

// void f_removerPaciente(){}
    
// void f_inserirPaciente(){}

// void f_imprimirLista(){}
