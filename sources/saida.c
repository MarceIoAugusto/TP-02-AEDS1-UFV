#include "saida.h"
/**
void ImprimeInicioMissao(TipoTreinador *treinador, int numero_fugitivos) {
    // Variaveis
    double *pos;
    printf("========================================\n");
    printf("INICIO DA MISSAO\n");
    printf("========================================\n");
    for (int i = 0; i < NUM_TREINADORES; i++) {
        pos = getTreinadorPos(&treinador[i]);
        // %g imprime 0 em vez de 0.000000
        printf("Treinador(a) %s: posicao (%g,%g) | Pokebolas: %d\n",
               getTreinadorNome(&treinador[i]), pos[X], pos[Y], getTreinadorPokebolas(&treinador[i]));
    }
    printf("Pokemons fugitivos a serem resgatados: %d\n", numero_fugitivos);
    return;
}

// Imprime todo o bloco de uma captura
void ImprimeAlvo(TipoTreinador *treinador, TipoPokemon *pokemon, int indice_treinador) {
    // Variaveis
    char nomesaida[TAM_NOMEP];
    float x, y;
    // Entradas
    getPokeNome(pokemon, nomesaida);
    getPokeLocalizacao(pokemon, &x, &y);

    // Saida
    printf("----------------------------------------\n");
    printf("Pokemon alvo: %s\n", nomesaida);
    printf("Localizacao: (%g,%g)\n", x, y);
    for (int i = 0; i < NUM_TREINADORES; i++) {
        printf("Distancia Treinador(a) %s: %.2f\n", getTreinadorNome(&treinador[i]), getTreinadorDistancia(&treinador[i]));
    }
    printf("Missao atribuida ao Treinador(a) %s.\n", getTreinadorNome(&treinador[indice_treinador]));
    printf("Treinador(a) %s se movimentou para (%g,%g).\n", getTreinadorNome(&treinador[indice_treinador]), x, y);
    printf("%s capturado com sucesso!\n", nomesaida);
    printf("Pokebolas restantes para o Treinador(a) %s: %d\n", getTreinadorNome(&treinador[indice_treinador]), getTreinadorPokebolas(&treinador[indice_treinador]));
}

void ImprimeRetornoPC(TipoTreinador *treinador, int pokebolas_ganhas) {
    printf("========================================\n");
    printf("Treinador(a) %s SEM POKEBOLAS\n", getTreinadorNome(treinador));
    printf("========================================\n");
    printf("Treinador(a) %s retorna ao Centro de Pesquisa.\n", getTreinadorNome(treinador));
    printf("Entregando Pokemon ao Centro de Pesquisa.\n");
    printf("Treinador(a) %s recebeu %d Pokebolas.\n", getTreinadorNome(treinador), pokebolas_ganhas);
}

void ConclusaoDaMissao(TipoTreinador *treinador) {
    printf("========================================\n");
    printf("Todos Pokemons foram resgatados\n");
    printf("========================================\n");
    printf("Ambos treinadores retornam ao Centro de Pesquisa.\n");
    for (int i = 0; i < NUM_TREINADORES; i++) {
        printf("Treinador(a) %s devolve os Pokemon.\n", getTreinadorNome(&treinador[i]));
    }
    printf("========================================\n");
    printf("MISSAO CONCLUIDA\n");
    printf("========================================\n");
}
**/
