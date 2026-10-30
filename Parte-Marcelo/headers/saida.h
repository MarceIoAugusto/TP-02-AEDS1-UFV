#ifndef SAIDA_H
#define SAIDA_H

#include "pokelista.h"
#include "pokemon.h"
#include "treinador.h"
#include "cabecalho.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void ImprimePokemonsCarregados(TipoPokemon *listapokemons, int quantidade);
void ImprimeStatus(int poder_total, int energia_consumida,int energiadisponivel,clock_t tempo);
void ImprimeExecucao();
void ImprimeSelecionados(int *melhorequipe,TipoPokemon *lista, int tamanho);
void ImprimeTreinadores(TipoTreinador *treinadores);
void ImprimeSaida(TipoPokemon *listapokemons, TipoTreinador *treinadores, int *melhorequipe, int poder_total, 
                    int energia_consumida,int energiadisponivel,clock_t tempo, int quantidade, int tamanho_melhor_equipe);

void LimparTela(); // Função para limpar a tela do terminal
void Menu(); // Função para exibir o menu do programa
#endif
