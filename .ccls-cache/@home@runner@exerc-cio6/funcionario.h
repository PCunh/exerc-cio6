#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

// Definição da estrutura do funcionário
typedef struct {
    char nome[50];
    int idade;
    float salario;
} Funcionario;

// Protótipos das funções
void adicionarRegistro(const char *filename);
void listarRegistros(const char *filename);
void buscarPorNome(const char *filename, const char *nome);

#endif /* FUNCIONARIO_H */