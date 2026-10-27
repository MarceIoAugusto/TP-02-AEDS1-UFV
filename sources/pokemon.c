#include "pokemon.h"

/* ---------- GETS ---------- */

int getPokeId(TipoPokemon *pokemon) {
    if (pokemon->Id < MAX_ID) {
        return pokemon->Id;
    } else {
        printf("\nerro ao receber Id do pokemon.\n");
        return ERRO;
    }
}

int getPokeNumero(TipoPokemon *pokemon) {
    if ((pokemon->Numero > 0) && (pokemon->Numero <= MAX_POKEDEX)) { /*numero maximo de pokemon na pokedex*/
        return pokemon->Numero;
    } else {
        printf("\nerro ao receber Numero do pokemon.\n");
        return ERRO;
    }
}

int getPokeNome(TipoPokemon *pokemon, char *nomesaida) {
    if (pokemon->Nome[TAM_NOMEP - 1] == '\0') {
        for (int i = 0; i < TAM_NOMEP; i++) {
            nomesaida[i] = pokemon->Nome[i];
        }
    } else {
        printf("\nerro ao receber Nome do pokemon.\n");
        return ERRO;
    }
    return 1;
}

int getPokeTipo(TipoPokemon *pokemon, char *tiposaida) {
    if (pokemon->Tipo[TAM_TIPO - 1] == '\0') { // CORRECAO: era '/0'
        for (int i = 0; i < TAM_TIPO; i++) {
            tiposaida[i] = pokemon->Tipo[i];
        }
    } else {
        printf("\nerro ao receber Tipo do pokemon.\n");
        return ERRO;
    }
    return 1; // CORRECAO: faltava o return no caso de sucesso
}

int getPokeLocalizacao(TipoPokemon *pokemon, float *posX, float *posY) {
    *posX = pokemon->Localizacao[X];
    *posY = pokemon->Localizacao[Y];
    return 0;
}

/* ---------- SETS ---------- */

void setPokeId(TipoPokemon *pokemon, int identrada) {
    pokemon->Id = identrada;
    return;
}

void setPokeNumero(TipoPokemon *pokemon, int numeroentrada) {
    pokemon->Numero = numeroentrada;
    return;
}

void setPokeNome(TipoPokemon *pokemon, char *nomeentrada) {
    strncpy(pokemon->Nome, nomeentrada, sizeof(pokemon->Nome));
    return;
}

void setPokeTipo(TipoPokemon *pokemon, char *tipoentrada) {
    strncpy(pokemon->Tipo, tipoentrada, sizeof(pokemon->Tipo));
    return;
}

void setPokeLocalizacao(TipoPokemon *pokemon, float x, float y) {
    pokemon->Localizacao[X] = x;
    pokemon->Localizacao[Y] = y;
    return;
}

/* ---------- LEITURA E INICIALIZACAO ---------- */

// Le uma linha do arquivo: numero nome tipo x y
// Retorna 1 se leu tudo certo e ERRO se nao conseguiu
int LePokemon(FILE *arquivo, int id, TipoPokemon *saida) {
    int numero;
    char Nome[TAM_NOMEP];
    char Tipo[TAM_TIPO];
    float x, y;
    // %14s = no maximo 14 letras, deixando espaco para o '\0' pois o TAM_NOMEP = 15
    if (fscanf(arquivo, "%d %14s %14s %f %f", &numero, Nome, Tipo, &x, &y) == 5) {
        InicializaPokemon(saida, id, numero, Nome, Tipo, x, y);
        return 1;
    } else {
        return ERRO;
    }
}

int InicializaPokemon(TipoPokemon *pokemon, int identrada, int numeroentrada, 
                        char *nomeentrada, char *tipoentrada, float x, float y) {
    setPokeId(pokemon, identrada);
    setPokeNumero(pokemon, numeroentrada);
    setPokeNome(pokemon, nomeentrada);
    setPokeTipo(pokemon, tipoentrada);
    setPokeLocalizacao(pokemon, x, y);
    return 1;
}

/* ---------- IMPRESSAO ---------- */

int ImprimePokemon(TipoPokemon *pokemon) {
    char PrintNome[TAM_NOMEP];
    char PrintTipo[TAM_TIPO];
    float x, y;
    getPokeNome(pokemon, PrintNome);   
    getPokeTipo(pokemon, PrintTipo);   
    getPokeLocalizacao(pokemon, &x, &y); 
    printf("\n########## Imprimindo informacoes do Pokemon ##########\n");
    printf("Id: %d\n", getPokeId(pokemon));
    printf("Nome: %s\n", PrintNome); // %s ja imprime a string inteira
    printf("Numero na Pokedex: %d\n", getPokeNumero(pokemon));
    printf("Tipo: %s\n", PrintTipo);
    printf("Coordenadas de localizacao atual: X;%g __ Y;%g\n", x, y);
    printf("############### Fim de Impressão ###############\n");
    return 1; 
}
