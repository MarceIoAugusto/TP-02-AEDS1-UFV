#ifndef TREINADOR_H
#define TREINADOR_H

#include "cabecalho.h"
#include "pokelista.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nome[TAM_NOMET];
    PokeLista pokelista;

} TipoTreinador;

void InicializaTreinador(TipoTreinador *treinador, int ID, char *nomeTemp);
int RemoverPokemonTreinador(TipoTreinador *treinador, TipoPokemon *PokemonRetirado);
void AdicionaPokemonTreinador(TipoTreinador *treinador, TipoPokemon *pokemon);
int BuscaPokemonTreinador(TipoTreinador *treinador, int posicao, TipoPokemon *pokemon);
// Funçoes para receber os dados do Treinador
int getTreinadorID(TipoTreinador *treinador);
char *getTreinadorNome(TipoTreinador *treinador);
void LiberaTreinador(TipoTreinador *treinador);
#endif
