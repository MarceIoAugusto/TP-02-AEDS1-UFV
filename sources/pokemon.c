#include "pokemon.h"

/* ---------- GETS ---------- */

int getPokeNumero(TipoPokemon *pokemon) {
    return pokemon->Numero;
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
int getPokePoder(TipoPokemon *pokemon){
    return pokemon->Poder;
}
int getPokeEnergiaGasta(TipoPokemon *pokemon){
    return pokemon->EnergiaGasta;
}

/* ---------- SETS ---------- */

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
void setPokePoder(TipoPokemon *pokemon, int poderentrada){
    pokemon->Poder = poderentrada;
}
void setPokeEnergiaGasta(TipoPokemon *pokemon, int energiagastaentrada){
    pokemon->EnergiaGasta = energiagastaentrada;
}
/* ---------- LEITURA E INICIALIZACAO ---------- */

// Le uma linha do arquivo: numero nome tipo...
// Retorna 1 se leu tudo certo e ERRO se nao conseguiu
int LePokemon(FILE *arquivo, TipoPokemon *saida) {
    int numero;
    char Nome[TAM_NOMEP];
    char Tipo[TAM_TIPO];
    int poder, energia;   
    // %14s = no maximo 14 letras, deixando espaco para o '\0' pois o TAM_NOMEP = 15
    if (fscanf(arquivo, "%d %14s %14s %d %d", &numero, Nome, Tipo, &poder, &energia) == 5) {
        InicializaPokemon(saida,numero, Nome, Tipo, poder, energia);
        return 1;
    } else {
        return ERRO;
    }
}

int InicializaPokemon(TipoPokemon *pokemon,int numeroentrada, 
                        char *nomeentrada, char *tipoentrada, int poderentrada, int energiaentrada) {
    setPokeNumero(pokemon, numeroentrada);
    setPokeNome(pokemon, nomeentrada);
    setPokeTipo(pokemon, tipoentrada);
    setPokePoder(pokemon, poderentrada);
    setPokeEnergiaGasta(pokemon,energiaentrada);

    return 1;
}

/* ---------- IMPRESSAO ---------- */

int ImprimePokemon(TipoPokemon *pokemon) {
    char PrintNome[TAM_NOMEP];
    char PrintTipo[TAM_TIPO];
    int numero, poder, energia;
    numero=getPokeNumero(pokemon);
    poder=getPokePoder(pokemon);
    energia=getPokeEnergiaGasta(pokemon);
    getPokeNome(pokemon, PrintNome);   
    getPokeTipo(pokemon, PrintTipo);   
    
    printf("ID: %-4d| Nome: %-15s| Tipo: %-15s | Poder: %-4d| Energia: %-4d\n",numero,PrintNome,PrintTipo,poder,energia);
    return 1; 
}


