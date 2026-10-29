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

void InicializaLista(PokeLista *Lista);// Inicializa a celula cabeça da lista encadeada
void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon);// Insere o Pokemon ao final da lista
int RemovePokemon(PokeLista *Lista, TipoPokemon *pokemon);// Remove o primeiro pokemon da lista e o retorna como parâmetro
void ImprimeLista(PokeLista *Lista); // Imprime a lista de pokemons na tela
void ImprimeListaFile(FILE *saida, PokeLista *Lista);// Imprime a lista de pokemons no arquivo de saida
TipoPokemon *getPrimeiroItem(PokeLista Lista);// Retorna o primeiro item da lista, sem removê-lo
int ListaEVazia(PokeLista *Lista);// Retorna 1 se a lista estiver vazia, 0 caso contrário
void LiberaLista(PokeLista *Lista);// Libera a memória alocada para a lista de pokemons

#endif
