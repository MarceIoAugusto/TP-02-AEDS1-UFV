#ifndef POKEMON_H
#define POKEMON_H

#include "cabecalho.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    int Numero;                     /* Numero na pokedex */
    char Nome[TAM_NOMEP];           
    char Tipo[TAM_TIPO];           
    int Poder;
    int EnergiaGasta;

} TipoPokemon;

int LePokemon(FILE *arquivo, TipoPokemon *saida);
int InicializaPokemon(TipoPokemon *pokemon,int numeroentrada, 
                        char *nomeentrada, char *tipoentrada, int poder, int energia);
int getPokeNumero(TipoPokemon *pokemon);
int getPokeNome(TipoPokemon *pokemon, char *nomesaida);
int getPokeTipo(TipoPokemon *pokemon, char *tiposaida);
int getPokePoder(TipoPokemon *pokemon);
int getPokeEnergiaGasta(TipoPokemon *pokemon);
void setPokeNumero(TipoPokemon *pokemon, int numeroentrada);
void setPokeNome(TipoPokemon *pokemon, char *nomeentrada);
void setPokeTipo(TipoPokemon *pokemon, char *tipoentrada);
void setPokePoder(TipoPokemon *pokemon, int poderentrada);
void setPokeEnergiaGasta(TipoPokemon *pokemon, int energiagastaentrada);
int ImprimePokemon(TipoPokemon *pokemon);
int ImprimePokemonFile(FILE *saida, TipoPokemon *pokemon);
#endif
