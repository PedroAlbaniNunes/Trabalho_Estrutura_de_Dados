#include "pacientes.h"
#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *f_formataCPF(const char *cpf) {
  // DECLARAÇÃO DE VARIÁVEIS
  static char
      cpfFormatado[15]; // Variável estática para armazenar o CPF formatado
  char cpf_block1[4], cpf_block2[4], cpf_block3[4],
      cpf_block4[3]; // Variáveis para os blocos do CPF
  //==================================================================================================//
  
  // Divisão do CPF em blocos
  sscanf(cpf, "%3c", cpf_block1);
  cpf_block1[3] = '\0';
  sscanf(cpf + 3, "%3c", cpf_block2);
  cpf_block2[3] = '\0';
  sscanf(cpf + 6, "%3c", cpf_block3);
  cpf_block3[3] = '\0';
  sscanf(cpf + 9, "%2c", cpf_block4);
  cpf_block4[2] = '\0';

  sprintf(cpfFormatado, "%s.%s.%s-%s", cpf_block1, cpf_block2, cpf_block3,
          cpf_block4); // Formata o CPF e armazena na variável cpfFormatado

  return cpfFormatado; // Retorna o CPF formatado
}

void f_printPaciente(Paciente *paciente) { // Função para imprimir os dados de um paciente
  printf("ID: %d\n", paciente->id); // Imprime o ID do paciente
  printf("CPF: %s\n", paciente->cpf); // Imprime o CPF do paciente já formatado
  printf("Nome: %s\n", paciente->nome);   // Imprime o nome do paciente
  printf("Idade: %d\n", paciente->idade); // Imprime a idade do paciente
  printf("Data de cadastro: %s\n", paciente->data_cadastro); // Imprime a data de cadastro do paciente
}

void f_consultarPaciente(LinkedList *lista) {
  // Declaração de variáveis
  char opcao;          // Variável para armazenar a opção do usuário
  char termoBusca[50]; // Variável para armazenar o termo de busca de consulta
                       // ao paciente
  ListNode *atual;
  //==================================================================================================//

  do {
    // Exibe o menu de consulta
    printf("\n=== Consulta de Pacientes ===\n");
    printf("1 - Consultar por nome\n");
    printf("2 - Consultar por CPF\n");
    printf("3 - Retornar ao menu principal\n");
    printf("> ");
    scanf(" %c", &opcao); // Lê a opção do usuário

    switch (opcao) {
    case '1': { // Consulta por nome
      printf("Digite o nome ou parte do nome do paciente: ");
      scanf(" %[^\n]", termoBusca); // Lê o nome do paciente

      atual = lista->first; // Inicia a busca a partir do primeiro nó da lista
      int encontrado = 0; // Flag para verificar se algum paciente foi encontrado

      while (atual) { // Percorre a lista
        if (strstr(atual->paciente.nome, termoBusca)) { // Verifica se o nome contém o termo buscado
          f_printPaciente(&atual->paciente); // Imprime os dados do paciente encontrado
          encontrado = 1;
        }
        atual = atual->next; // Avança para o próximo nó
      }

      if (!encontrado) {
        printf("Nenhum paciente encontrado com o nome informado.\n");
      }
      break;
    }

    case '2': { // Consulta por CPF
      printf("Digite o CPF do paciente (apenas números): ");
      scanf(" %[^\n]", termoBusca); // Lê o CPF do paciente

      atual = lista->first; // Inicia a busca a partir do primeiro nó da lista
      int encontrado = 0; // Flag para verificar se algum paciente foi encontrado

      while (atual) { // Percorre a lista
        if (strcmp(atual->paciente.cpf, f_formataCPF(termoBusca)) ==
            0) { // Verifica se o CPF é igual ao buscado
          f_printPaciente(&atual->paciente); // Imprime os dados do paciente encontrado
          encontrado = 1;
          break; // Encerra a busca após encontrar o paciente
        }
        atual = atual->next; // Avança para o próximo nó
      }

      if (!encontrado) {
        printf("Nenhum paciente encontrado com o CPF informado.\n");
      }
      break;
    }

    case '3': { // Retorna ao menu principal
      printf("Retornando ao menu principal...\n");
      break;
    }

    default: { // Opção inválida
      printf("Opção inválida! Tente novamente.\n");
      break;
    }
    }
  } while (
      opcao !=
      '3'); // Repete enquanto o usuário não escolher retornar ao menu principal
}

void f_atualizarPaciente(LinkedList *lista) {
  // DECLARAÇÃO DE VARIÁVEIS
  int id, idadeAtualizada;
  char cpfAtualizado[15], nomeAtualizado[50], data_registroAtualizada[11],
      confirmacao;
  //==================================================================================================//

  printf("Digite o ID do registro a ser atualizado: \n"); // Pede ao usuário
                                                          // para digitar o ID
                                                          // do paciente a ser
                                                          // atualizado
  scanf("%d", &id);

  ListNode *atual = lista->first; // Variável para percorrer a lista
  while (atual) {                 // Enquanto houver pacientes na lista
    if (atual->paciente.id == id) { // Se o ID do paciente for igual ao ID digitado
      printf("Paciente encontrado! Atualize os dados: \n");
      f_printPaciente(&atual->paciente); // Chama a função f_printPaciente()
                                         // para imprimir os dados do paciente

      printf("Digite o novo valor para os campos CPF (apenas dígitos), Nome, "
             "Idade e Data_Cadastro (para manter o valor atual de um campo, "
             "digite \'-\'):\n\n");

      printf("CPF atual: %s\nDigite o novo CPF: ", atual->paciente.cpf);
      scanf(" %[^\n]", cpfAtualizado); // Lê o novo CPF do paciente

      printf("\nNome atual: %s\nDigite o novo Nome: ", atual->paciente.nome);
      scanf(" %[^\n]", nomeAtualizado); // Lê o novo nome do paciente

      printf("\nIdade atual: %d\nDigite a nova Idade: ", atual->paciente.idade);
      scanf("%d", &idadeAtualizada); // Lê a nova idade do paciente

      printf("\nData de cadastro atual: %s\nDigite a nova Data de Cadastro: ",
             atual->paciente.data_cadastro);
      scanf(" %[^\n]",
            data_registroAtualizada); // Lê a nova data de cadastro do paciente

      // Exibir os dados do paciente antes de confirmar a atualização
      printf("\nOs dados atualizados são:\n");
      printf("CPF: %s\n", cpfAtualizado[0] == '-'
                              ? atual->paciente.cpf
                              : f_formataCPF(cpfAtualizado));
      printf("Nome: %s\n",
             nomeAtualizado[0] == '-' ? atual->paciente.nome : nomeAtualizado);
      printf("Idade: %d\n",
             idadeAtualizada == -1 ? atual->paciente.idade : idadeAtualizada);
      printf("Data de cadastro: %s\n", data_registroAtualizada[0] == '-'
                                           ? atual->paciente.data_cadastro
                                           : data_registroAtualizada);

      printf("\nConfirma a atualização? (S/N): "); // Pergunta se o usuário
                                                   // confirma a atualização
      scanf(" %c", &confirmacao);

      if (confirmacao == 'S' || confirmacao == 's') { // Se a confirmação for 'S' ou 's', atualiza os dados do paciente
        if (cpfAtualizado[0] != '-') { // Se o novo CPF for diferente de '-', atualiza o CPF do paciente
          strcpy(atual->paciente.cpf, cpfAtualizado);
        }

        if (nomeAtualizado[0] != '-') { // Se o novo nome for diferente de '-',  atualiza o nome do paciente
          strcpy(atual->paciente.nome, nomeAtualizado);
        }

        if (idadeAtualizada != -1) { // Se a nova idade for diferente de -1, atualiza a idade do paciente
          atual->paciente.idade = idadeAtualizada;
        }

        if (data_registroAtualizada[0] != '-') { // Se a nova data de cadastro for diferente de '-', atualiza a data de cadastro do paciente
          strcpy(atual->paciente.data_cadastro, data_registroAtualizada);
        }

        printf("Registro atualizado com sucesso.\n");
      } else {
        printf("Atualização cancelada.\n");
      }

      return; // Sai da função após encontrar e atualizar o registro
    }

    atual = atual->next; // Passa para o próximo paciente
  }

  printf("Paciente com ID informado não encontrado.\n");
}

void f_removerPaciente(LinkedList *lista) {
  // DECLARAÇÃO DE VARIÁVEIS
  int id;
  char confirmacao;
  //==================================================================================================//

  printf("Digite o ID do paciente a ser removido: ");
  scanf("%d", &id);

  ListNode *anterior = NULL;      // Variável para armazenar o nó anterior
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
        if (anterior) {
          // Se houver um nó anterior, o próximo nó do anterior será o próximo
          anterior->next = atual->next;
        } else {
          // Se não houver um nó anterior, o primeiro nó da lista será o próximo
          lista->first = atual->next;
        }
        free(atual);      // Libera a memória do nó atual
        lista->tamanho--; // Decrementa o tamanho da lista
        printf("Paciente removido com sucesso.\n");
        return; // Sai da função após remover o paciente
      } else {
        printf("Remoção cancelada.\n");
        return; // Sai da função sem remover o paciente
      }
    }
    anterior = atual;    // O nó anterior será o nó atual
    atual = atual->next; // O nó atual será o próximo nó
  }

  printf("Nenhum paciente encontrado com o ID fornecido.\n");
}

int maior_id(LinkedList *lista) {
  // DECLARAÇÃO DE VARIÁVEIS
  int maior_id = 0; // Inicializa o maior ID como 0
  //==================================================================================================//

  ListNode *atual = lista->first; // Começa pelo primeiro nó da lista

  while(atual != NULL) { // Percorre a lista encadeada
    if (atual->paciente.id > maior_id) {
      maior_id = atual->paciente.id; // Atualiza o maior ID se o ID atual for maior
    }
    atual = atual->next; // Avança para o próximo nó
  }

  return maior_id + 1; // Retorna o maior ID encontrado
}

void f_inserirNovoPaciente(LinkedList *lista) {
  // DECLARAÇÃO DE VARIÁVEIS
  char cpf[11], nome[50], data_de_registro[11], opcao;
  int idade;
  //==================================================================================================//

  printf("Para inserir um novo registro, digite os valores para os campos CPF (apenas dígitos), Nome, Idade e Data_Cadastro: \n");

  // Entrada de dados do usuário
  printf("CPF (apenas números): \n> ");
  scanf(" %[^\n]", cpf);

  
  while (strlen(cpf) != 11) { // Verifica se o CPF tem exatamente 11 dígitos
      printf("Tamanho de CPF inválido, tente novamente: \n> ");
      scanf(" %[^\n]", cpf);
  }

  printf("Nome: \n> ");
  scanf(" %[^\n]", nome);


  printf("Idade: \n> ");
  scanf("%d", &idade);
  while (idade < 0){ // Verifica se a idade digitada tem valor maior que 0
    printf("Idade inválida, tente novamente: \n> ");
    scanf("%d", &idade);
  }
  
  printf("Data de Registro (aaaa-mm-dd): \n> ");
  scanf(" %[^\n]", data_de_registro);

  // Confirmação do registro
  printf("Confirma a inserção dos registros acima? (S/N)\n");
  scanf(" %c", &opcao);

  if (opcao == 'S' || opcao == 's') { 
    Paciente novoPaciente; // Cria um novo paciente com os dados fornecidos
    novoPaciente.id = maior_id(lista);
    strcpy(novoPaciente.cpf, f_formataCPF(cpf));
    strcpy(novoPaciente.nome, nome);
    novoPaciente.idade = idade;
    strcpy(novoPaciente.data_cadastro, data_de_registro);
    f_adicionarNaLista(lista, &novoPaciente); // Adiciona o paciente à lista encadeada

    printf("O registro foi concluído com sucesso.\n");
  } else {
    printf("Registro cancelado.\n");
  }
}