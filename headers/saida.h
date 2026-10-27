#ifndef SAIDA_H
#define SAIDA_H

#include "centropesquisa.h"
#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"
#include <stdio.h>
#include <stdlib.h>

void ImprimeInicioMissao(TipoTreinador *treinador, int numero_fugitivos);
void ImprimeAlvo(TipoTreinador *treinador, TipoPokemon *pokemon, int indice_treinador);
void ImprimeRetornoPC(TipoTreinador *treinador, int pokebolas_ganhas);
void ConclusaoDaMissao(TipoTreinador *treinador);

#endif
