#include "treinador.h"

void InicializaTreinador(TipoTreinador *treinador, int ID, char *nomeTemp) {
    int caracter = 0;

    // Erros
    if (ID < 0) {
        printf("\nErro ao inicializar o treinador... Id negativo\n");
        exit(EXIT_FAILURE);
    } else if (nomeTemp[0] == '\0') {
        printf("\nErro ao inicializar o treinador... Nome vazio\n");
        exit(EXIT_FAILURE);
    }

    // Preenchendo o ID
    treinador->id = ID;

    // Nome
    while (nomeTemp[caracter] != '\0') {
        treinador->nome[caracter] = nomeTemp[caracter];
        caracter++;
    }
    treinador->nome[caracter] = '\0';

    // inicializando a pokelista de cada treinador
    InicializaLista(&treinador->pokelista);
    return;
}

// Calcula a distancia de cada treinador ate o pokemon, move o mais proximo ate ele
// e retorna o indice desse treinador que se moveu

int RemoverPokemonTreinador(TipoTreinador *treinador, TipoPokemon *PokemonRetirado) {
    // Remove um pokemon da lista do treinador, retornando o pokemon removido da funçao
    if (RemovePokemon(&treinador->pokelista, PokemonRetirado)) {
        // Conseguiu remover (return 1)
        return 1;
    }
    // A lista ja estava vazia (return 0)
    return 0;
}
void AdicionaPokemonTreinador(TipoTreinador *treinador, TipoPokemon *pokemon){
    InserePokemon(&treinador->pokelista,pokemon);
}
int getTreinadorID(TipoTreinador *treinador) {
    return treinador->id;
}
void LiberaTreinador(TipoTreinador *treinador) {
    LiberaLista(&treinador->pokelista);
}
// Agora retorna o array pos que ja esta dentro do treinador.
char *getTreinadorNome(TipoTreinador *treinador) {
    return treinador->nome;
}

