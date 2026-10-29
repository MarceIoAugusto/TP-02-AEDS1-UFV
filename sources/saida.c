#include "saida.h"


void ImprimePokemonsCarregados(TipoPokemon *listapokemons, int quantidade){
    printf("--- Pokemons Carregados ---\n");
    for(int i=0;i<quantidade;i++){
          ImprimePokemon(&listapokemons[i]);
      }
}

void execucao(){
    printf("\n=== Executando Selecao de Pokemons (Forca Bruta) ===\n");
}

void ImprimeStatus(int poder_total, int energia_consumida,int energiadisponivel,clock_t tempo){
    double tempodeexecucao = (double)tempo / CLOCKS_PER_SEC;
    printf("\n=== Melhor Equipe Encontrada ===\n");
    printf("Poder Total: %d\n", poder_total);
    printf("Energia Total Consumida: %d / %d\n", energia_consumida, energiadisponivel);
    printf("Tempo de Execucao: %.6lf segundos (%.3lf ms)\n", tempodeexecucao, tempodeexecucao * 1000);
}

void ImprimeSelecionados(int *melhorequipe,TipoPokemon *lista){
    printf("\nPokemons Selecionados para a Equipe:\n");
    int cont=0;
    while(melhorequipe[cont] != -1){
        ImprimePokemon(&lista[melhorequipe[cont]]);
        cont++;
    }
}