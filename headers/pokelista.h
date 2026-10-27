#ifndef POKELISTA_H
#define POKELISTA_H

#include "pokemon.h"
#include <stdlib.h>

typedef struct PokeCelula {
    TipoPokemon Pokemon;
    struct PokeCelula *Proximo;
} PokeCelula;

typedef struct {
    PokeCelula *Primeiro, *Ultimo; //Celula cabeça
} PokeLista;

void InicializaLista(PokeLista *Lista);  
void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon); 
int RemovePokemon(PokeLista *Lista, TipoPokemon *pokemon);  
int BuscaPokemon(PokeLista *Lista, int id, TipoPokemon *pokemon);
void ImprimeLista(PokeLista *Lista);
TipoPokemon *getPrimeiroItem(PokeLista Lista);
int ListaEVazia(PokeLista *Lista);
void LiberaLista(PokeLista *Lista);

#endif
