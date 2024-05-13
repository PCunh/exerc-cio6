#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

// Função para adicionar um novo registro
void adicionarRegistro(const char *filename) {
    FILE *arquivo = fopen(filename, "ab");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario novoFuncionario;

    printf("Digite o nome do funcionario: ");
    scanf("%s", novoFuncionario.nome);
    printf("Digite a idade do funcionario: ");
    scanf("%d", &novoFuncionario.idade);
    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);

    fwrite(&novoFuncionario, sizeof(Funcionario), 1, arquivo);

    fclose(arquivo);
}

// Função para listar todos os registros
void listarRegistros(const char *filename) {
    FILE *arquivo = fopen(filename, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionario;

    printf("Listagem de funcionarios:\n");
    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
    }

    fclose(arquivo);
}

// Função para buscar registros por nome
void buscarPorNome(const char *filename, const char *nome) {
    FILE *arquivo = fopen(filename, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Funcionario funcionario;
    int encontrados = 0;

    while (fread(&funcionario, sizeof(Funcionario), 1, arquivo) == 1) {
        if (strcmp(funcionario.nome, nome) == 0) {
            printf("Nome: %s, Idade: %d, Salario: %.2f\n", funcionario.nome, funcionario.idade, funcionario.salario);
            encontrados++;
        }
    }

    if (encontrados == 0) {
        printf("Nenhum funcionario encontrado com o nome %s.\n", nome);
    }

    fclose(arquivo);
}
