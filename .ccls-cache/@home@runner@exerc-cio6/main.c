#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

int main() {
    char filename[] = "funcionarios.bin";
    int opcao;
    char nomeBusca[50];

    do {
        printf("\n1 - Adicionar novo registro\n");
        printf("2 - Listar todos os registros\n");
        printf("3 - Buscar por nome\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarRegistro(filename);
                break;
            case 2:
                listarRegistros(filename);
                break;
            case 3:
                printf("Digite o nome para buscar: ");
                scanf("%s", nomeBusca);
                buscarPorNome(filename, nomeBusca);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}