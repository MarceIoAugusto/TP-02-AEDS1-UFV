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

int getPokePower(TipoPokemon *pokemon){
    return pokemon->poder;
}

int getPokeEnergy(TipoPokemon *pokemon){
    return pokemon->energia_gasta;
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

/* ---------- LEITURA E INICIALIZACAO ---------- */

int InicializaPokemon(TipoPokemon *pokemon, int identrada, int numeroentrada, char *nomeentrada, char *tipoentrada, int poder, int energia_gasta) {
    setPokeId(pokemon, identrada);
    setPokeNumero(pokemon, numeroentrada);
    setPokeNome(pokemon, nomeentrada);
    setPokeTipo(pokemon, tipoentrada);
    pokemon->energia_gasta = energia_gasta;
    pokemon->poder = poder;
    return 1;
}

/* ---------- IMPRESSAO ---------- */

int ImprimePokemon(TipoPokemon *pokemon) {
    char PrintNome[TAM_NOMEP];
    char PrintTipo[TAM_TIPO];
    getPokeNome(pokemon, PrintNome);   
    getPokeTipo(pokemon, PrintTipo);   
    printf("\n########## Imprimindo informacoes do Pokemon ##########\n");
    printf("Id: %d\n", getPokeId(pokemon));
    printf("Nome: %s\n", PrintNome); // %s ja imprime a string inteira
    printf("Numero na Pokedex: %d\n", getPokeNumero(pokemon));
    printf("Tipo: %s\n", PrintTipo);
    printf("############### Fim de Impressão ###############\n");
    return 1; 
}
