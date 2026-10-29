#ifndef SAIDA_H
#define SAIDA_H

#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ImprimePokemonsCarregados(TipoPokemon *listapokemons, int quantidade);
void ImprimeStatus(int poder_total, int energia_consumida,int energiadisponivel,clock_t tempo);
void execucao();
void ImprimeSelecionados(int *melhorequipe,TipoPokemon *lista);

#endif
