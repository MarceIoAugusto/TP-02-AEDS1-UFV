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
    double pos[COORDENADAS];
    PokeLista pokelista;
    int pokebolas;
    double distancia;

} TipoTreinador;

void InicializaTreinador(TipoTreinador *treinador, int ID, char *nomeTemp, int pokebolTemp);
int leTreinador(FILE *arqtreinador, TipoTreinador *treinador, int id);
int Movimentacao(TipoPokemon *pokemon, TipoTreinador *treinador);
int CapturaPokemon(TipoPokemon *alvo, TipoTreinador *treinador, int indice);
int RemoverPokemonTreinador(TipoTreinador *treinador, TipoPokemon *PokemonRetirado);
void ImprimeTreinador(TipoTreinador treinador);
void RetornoTreinadorCP(TipoTreinador *treinador);

// Funçoes para receber os dados do Treinador
double *getTreinadorPos(TipoTreinador *treinador);
int getTreinadorID(TipoTreinador *treinador);
double getTreinadorDistancia(TipoTreinador *treinador);
char *getTreinadorNome(TipoTreinador *treinador);
int getTreinadorPokebolas(TipoTreinador *treinador);

// Funçoes para alterar os dados do Treinador
void setTreinadorPos(TipoTreinador *treinador, double *pos);
void setTreinadorPokebolas(TipoTreinador *treinador, int pokebolas);

#endif
