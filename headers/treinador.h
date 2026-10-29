#ifndef TREINADOR_H
#define TREINADOR_H

#include "cabecalho.h"
#include "pokelista.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[TAM_NOMET];
    PokeLista pokelista;
} TipoTreinador;

// Funções para inicializar e ler os dados do treinador
void InicializaTreinador(TipoTreinador *treinador, char *nomeTemp);
int leTreinador(FILE *arqtreinador, TipoTreinador *treinador);

// Funçoes para receber os dados do Treinador
char *getTreinadorNome(TipoTreinador *treinador);
PokeLista *getPokelista(TipoTreinador *treinador);

#endif
