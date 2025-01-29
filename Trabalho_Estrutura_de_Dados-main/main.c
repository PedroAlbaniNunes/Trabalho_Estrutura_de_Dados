#include "menu.h"
#include "arquivo.h"
#include "pacientes.h"
#include "lista.h"

int main() {
    LinkedList listaPacientes; // Declara uma lista de pacientes

    f_inicializarLista(&listaPacientes);
    
    f_carregarDados(&listaPacientes, "bd_paciente.csv"); // Carrega os dados do arquivo

    f_imprimirLista(&listaPacientes); // Exibe a lista de pacientes

    f_exibirMenu(&listaPacientes); // Exibe o menu de opções

    return 0;
}
