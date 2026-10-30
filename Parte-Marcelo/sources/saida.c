#include "saida.h"


void ImprimePokemonsCarregados(TipoPokemon *listapokemons, int quantidade){
    printf("--- Pokemons Carregados ---\n");
    for(int i=0;i<quantidade;i++){
          ImprimePokemon(&listapokemons[i]);
      }
}

void ImprimeExecucao(){
    printf("\n=== Executando Selecao de Pokemons (Forca Bruta) ===\n");
}

void ImprimeStatus(int poder_total, int energia_consumida,int energiadisponivel,clock_t tempo){
    double tempodeexecucao = (double)tempo / CLOCKS_PER_SEC;
    printf("\n=== Melhor Equipe Encontrada ===\n");
    printf("Poder Total: %d\n", poder_total);
    printf("Energia Total Consumida: %d / %d\n", energia_consumida, energiadisponivel);
    printf("Tempo de Execucao: %.6lf segundos (%.3lf ms)\n", tempodeexecucao, tempodeexecucao * 1000);
}

void ImprimeSelecionados(int *melhorequipe,TipoPokemon *lista, int tamanho){
    printf("\nPokemons Selecionados para a Equipe:\n");
    for(int i=0; i<tamanho; i++){
        ImprimePokemon(&lista[melhorequipe[i]]);
    }
}
void ImprimeTreinadores(TipoTreinador *treinadores){
    printf("\n=== Equipes dos Treinadores ===\n");
        for(int i=0;i<NUM_TREINADORES;i++){
            printf("Treinador %d: %s\n", i+1, getTreinadorNome(&treinadores[i]));
            printf("Mochila do Treinador:\n");
            ImprimeLista(getPokelista(&treinadores[i]));
            printf("\n");
    }
}


// Imprime saida faz a mesma impressão que as outras funcoes, mas no arquivo de saida.txt
void ImprimeSaida(TipoPokemon *listapokemons, TipoTreinador *treinadores, int *melhorequipe, int poder_total, int energia_consumida,
                    int energiadisponivel,clock_t tempo, int quantidade, int tamanho_melhor_equipe ){
    FILE *saida = fopen(NOME_SAIDA, "w");
    double tempodeexecucao = (double)tempo / CLOCKS_PER_SEC;

    
    if (saida == NULL) { // Verifica se o arquivo foi aberto corretamente
        printf("Erro ao abrir o arquivo de saída.\n");
        return;
    }
    // Imprime os pokemons carregados do arquivo
    fprintf(saida, "--- Pokemons Carregados ---\n");
    for(int i=0;i<quantidade;i++){
          ImprimePokemonFile(saida,&listapokemons[i]);
      }
    fprintf(saida, "\n=== Executando Selecao de Pokemons (Forca Bruta) ===\n");
    // Imprime o status da melhor equipe encontrada
    fprintf(saida, "\n=== Melhor Equipe Encontrada ===\n");
    fprintf(saida, "Poder Total: %d\n", poder_total);
    fprintf(saida, "Energia Total Consumida: %d / %d\n", energia_consumida, energiadisponivel);
    fprintf(saida, "Tempo de Execucao: %.6lf segundos (%.3lf ms)\n", tempodeexecucao, tempodeexecucao * 1000);
    // Imprime os pokemons selecionados para a melhor equipe
    fprintf(saida, "\nPokemons Selecionados para a Equipe:\n");
    for(int i=0; i<tamanho_melhor_equipe; i++){
        ImprimePokemonFile(saida,&listapokemons[melhorequipe[i]]);
    }
    // Imprime as equipes dos treinadores e suas mochilas
    fprintf(saida, "\n=== Equipes dos Treinadores ===\n");
        for(int i=0;i<NUM_TREINADORES;i++){
            fprintf(saida, "Treinador %d: %s\n", i+1, getTreinadorNome(&treinadores[i]));
            fprintf(saida, "Mochila do Treinador:\n");
            ImprimeListaFile(saida,getPokelista(&treinadores[i]));
            fprintf(saida, "\n");
    }
    fprintf(saida, "\n=== Fim da Execucao ===\n");
    fprintf(saida,"OBS: O arquivo de saída (saida.txt) sempre sobrescreve o conteúdo anterior.\n");
    
    fclose(saida);
}

void LimparTela() {
    // Limpa a tela do terminal
    #ifdef _WIN32 || _WIN64
        system("cls"); // Comando para Windows
    #else
        system("clear"); // Comando para Linux e macOS
    #endif
}
void Menu(){
    LimparTela();
    printf("TP2 - AEDS I - PROBLEMA DE SELECAO DE POKEMON\n");
    printf("AUTORES: Marcelo Augusto e Gustavo Spinola\n");
    printf("UFV - Universidade Federal de Vicosa\n");
    printf("A saida do programa sera impressa na tela e no arquivo %s\n", NOME_SAIDA);
    printf("\nDigite o nome do arquivo de entrada (ex: teste1.txt): ");
}
