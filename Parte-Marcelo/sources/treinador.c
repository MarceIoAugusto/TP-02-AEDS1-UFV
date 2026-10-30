#include "treinador.h"

void InicializaTreinador(TipoTreinador *treinador, char *nomeTemp) {
    int caracter = 0;

    // Erros
    if (nomeTemp[0] == '\0') {
        printf("\nErro ao inicializar o treinador... Nome vazio\n");
        exit(EXIT_FAILURE);
    }
    // Nome
    while (nomeTemp[caracter] != '\0') {
        treinador->nome[caracter] = nomeTemp[caracter];
        caracter++;
    }
    treinador->nome[caracter] = '\0';

    // inicializando a pokelista de cada treinador
    InicializaLista(&treinador->pokelista);
    return;
}

int leTreinador(FILE *arqtreinador, TipoTreinador *treinador) {
    char nome[TAM_NOMET]; // 25 caracteres para o nome do treinador com espaço para o caractere nulo '\0'
    if (fscanf(arqtreinador, "%24s", nome) == 1) {
        InicializaTreinador(treinador, nome);
        return 1;
    }
    printf("\nErro ao ler o treinador do arquivo.\n");
    return ERRO;
}

char *getTreinadorNome(TipoTreinador *treinador) {
    return treinador->nome;
}

PokeLista *getPokelista(TipoTreinador *treinador){
    return &treinador->pokelista;
}