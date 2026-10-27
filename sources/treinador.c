#include "treinador.h"

void InicializaTreinador(TipoTreinador *treinador, int ID, char *nomeTemp, int pokebolTemp) {
    int caracter = 0;

    // Erros
    if (ID < 0) {
        printf("\nErro ao inicializar o treinador... Id negativo\n");
        exit(EXIT_FAILURE);
    } else if (nomeTemp[0] == '\0') {
        printf("\nErro ao inicializar o treinador... Nome vazio\n");
        exit(EXIT_FAILURE);
    } else if (pokebolTemp < 0) {
        printf("\nErro ao inicializar o treinador... pokebolas iniciais negativas\n");
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

    // Pokebolas Iniciais
    treinador->pokebolas = pokebolTemp;

    // pos X e Y = (0,0)
    treinador->pos[X] = 0;
    treinador->pos[Y] = 0;

    treinador->distancia = 0;

    // inicializando a pokelista de cada treinador
    InicializaLista(&treinador->pokelista);
    return;
}

int leTreinador(FILE *arqtreinador, TipoTreinador *treinador, int id) {
    char nome[TAM_NOMET];
    int pokebolas;
    if (fscanf(arqtreinador, "%s %d", nome, &pokebolas) == 2) {
        InicializaTreinador(treinador, id, nome, pokebolas);
        return 1;
    }
    return ERRO;
}

// Calcula a distancia de cada treinador ate o pokemon, move o mais proximo ate ele
// e retorna o indice desse treinador que se moveu
int Movimentacao(TipoPokemon *pokemon, TipoTreinador *treinador) {
    float resX, resY;

    // Pegando as posicoes do pokemon alvo
    float pokepos[COORDENADAS];
    getPokeLocalizacao(pokemon, &pokepos[X], &pokepos[Y]);

    // calculando a distancia para cada treinador
    for (int i = 0; i < NUM_TREINADORES; i++) {
        resX = treinador[i].pos[X] - pokepos[X]; // (X1 - X2)
        resX = resX * resX;                      // (resultado)**2
        resY = treinador[i].pos[Y] - pokepos[Y]; // (Y1 - Y2)
        resY = resY * resY;                      // (resultado)**2

        treinador[i].distancia = sqrt(resX + resY);
    }

    // Verifica qual Treinador esta mais proximo do pokemon e retorna seu indice
    // Usa-se < e nao <= pois se os treinadores tiverem a mesma distancia do pokemon o primeiro sera escolhido
    int menor_indice = 0;
    for (int i = 1; i < NUM_TREINADORES; i++) {
        if (treinador[i].distancia < treinador[menor_indice].distancia) {
            menor_indice = i;
        }
    }

    // Movimenta o treinador escolhido ate o pokemon
    treinador[menor_indice].pos[X] = pokepos[X];
    treinador[menor_indice].pos[Y] = pokepos[Y];
    return menor_indice;
}

// Captura o pokemon e retorna 1 se as pokebolas do treinador acabaram
int CapturaPokemon(TipoPokemon *alvo, TipoTreinador *treinador, int indice) {

    // Retirando uma pokebola do Treinador
    treinador[indice].pokebolas--;

    // Insere o pokemon na "mochila" do Treinador
    InserePokemon(&treinador[indice].pokelista, alvo);

    // Verifica se as pokebolas do treinador acabaram
    if (treinador[indice].pokebolas <= 0) {
        return 1;
    }
    return 0;
}

int RemoverPokemonTreinador(TipoTreinador *treinador, TipoPokemon *PokemonRetirado) {
    // Remove um pokemon da lista do treinador, retornando o pokemon removido da funçao
    if (RemovePokemon(&treinador->pokelista, PokemonRetirado)) {
        // Conseguiu remover (return 1)
        return 1;
    }
    // A lista ja estava vazia (return 0)
    return 0;
}

void ImprimeTreinador(TipoTreinador treinador) {
    printf("\nO Treinador %s esta na posicao: (%.0f %.0f) | Pokebolas: %d\n", treinador.nome, treinador.pos[X], treinador.pos[Y], treinador.pokebolas);
}

int getTreinadorID(TipoTreinador *treinador) {
    return treinador->id;
}

// Agora retorna o array pos que ja esta dentro do treinador.
double *getTreinadorPos(TipoTreinador *treinador) {
    return treinador->pos;
}

char *getTreinadorNome(TipoTreinador *treinador) {
    return treinador->nome;
}

void setTreinadorPos(TipoTreinador *treinador, double *pos) {
    treinador->pos[X] = pos[X];
    treinador->pos[Y] = pos[Y];
    return;
}

void setTreinadorPokebolas(TipoTreinador *treinador, int pokebolas) {
    treinador->pokebolas = treinador->pokebolas + pokebolas;
    return;
}

double getTreinadorDistancia(TipoTreinador *treinador) {
    return treinador->distancia;
}

int getTreinadorPokebolas(TipoTreinador *treinador) {
    return treinador->pokebolas;
}

void RetornoTreinadorCP(TipoTreinador *treinador) {
    treinador->pos[X] = 0;
    treinador->pos[Y] = 0;
    return;
}
