#include <stdio.h>
#include <stdlib.h>
#include "treinador.h"
#include <time.h>

// Lê o arquivo de entrada e inicializa treinadores, lista de Pokémon e limites da equipe.
void Ler_Entrada(FILE* entrada, TipoTreinador *treinadores, PokeLista *Lpokemons,int *energia_total, int *num_poke){
    char nome_treinador[TAM_NOMET];
    for(int i = 0; i < NUM_TREINADORES; i++){
        fscanf(entrada, "%s", nome_treinador);
        InicializaTreinador(&treinadores[i],i,nome_treinador);
    }

    //Numero de pokemons 
    fscanf(entrada, "%d",num_poke);
    
    //Energia total
    fscanf(entrada, "%d",energia_total);

    //Inicializando os pokemons
    TipoPokemon pokemon_temp;
    int pokdex; 
    char nome_poke[TAM_NOMEP];
    char tipo_poke[TAM_TIPO];
    int poder;
    int energia_gasta;
    for(int i = 0; i < *num_poke; i++){
        fscanf(entrada,"%d %s %s %d %d",&pokdex,nome_poke,tipo_poke,&poder,&energia_gasta);
        InicializaPokemon(&pokemon_temp,i,pokdex,nome_poke,tipo_poke,poder,energia_gasta);
        InserePokemon(Lpokemons,&pokemon_temp);
    }
    
    return;
}
// Aguarda o usuário antes de encerrar o programa.
void fechar(){
    char buffer;
    printf("\n\nPressione enter para encerrar o Programa: ");
    getchar();
    getchar();
    return;
}
// Gera combinações e mantém a equipe válida com maior poder.
void Combinacao(PokeLista *Lpokemons, int melhor_equipe[], TipoPokemon All_pokemons[], int n, int x, int inicio, int nivel,int energy_max, int combinacao[],int *power_melhor_equipe,int *contador,int *tamanho_melhor_equipe, int *energy_melhor_equipe) {
    // Caso base: combinação completa
    if (nivel == x) {
        int power = 0;
        int energy = 0;
        (*contador) ++;
        for (int i = 0; i < x; i++) {
            TipoPokemon poke_temp = All_pokemons[combinacao[i]];
            power += getPokePower(&poke_temp);
            energy += getPokeEnergy(&poke_temp);
        }
        if(energy > energy_max){
                return;
            }else if(power > *power_melhor_equipe){
                *power_melhor_equipe = power;
                *tamanho_melhor_equipe = x;
                *energy_melhor_equipe = energy;
                for(int i = 0; i < x; i++){
                    melhor_equipe[i] = combinacao[i];
                }
            }
        return;
    }

    // Escolher os próximos números
    for (int i = inicio; i < n; i++) {
        combinacao[nivel] = i;
        Combinacao(Lpokemons, melhor_equipe, All_pokemons, n, x, i + 1, nivel + 1, energy_max,combinacao, power_melhor_equipe,contador,tamanho_melhor_equipe, energy_melhor_equipe);
    }
}
int main(){
    // Abre o arquivo de dados utilizado pelo programa.
    FILE* entrada;
    entrada = fopen("C:/VscodeC/TP - Aeds/tp02-AEDS1-UFV/TP-02-AEDS1-UFV/Parte-Gustavo/TESTE/teste1.txt","r");
    if(entrada == NULL){
        printf("Erro!! arquivo nao conseguiu ser aberto!");
        return 1;
    }
    // Inicializa a estrutura que armazenará todos os Pokémon.
    PokeLista Lpokemons;
    InicializaLista(&Lpokemons);
    TipoTreinador treinadores[NUM_TREINADORES];    
    int energia_total;
    int numeros_pokemons;
    Ler_Entrada(entrada,treinadores,&Lpokemons,&energia_total,&numeros_pokemons);
    fclose(entrada);

    // Prepara vetores auxiliares para armazenar combinações e a melhor equipe.
    int *melhor_equipe = malloc(sizeof(int) * numeros_pokemons);
    int *combinacao = malloc(sizeof(int) * numeros_pokemons);
    int contador = 0;
    int power_melhor_equipe = 0;
    int energy_melhor_equipe = 0;
    int tamanho_melhor_equipe = 0;
    TipoPokemon *All_pokemons = malloc(sizeof(TipoPokemon) * numeros_pokemons);
    // Verifica se todas as alocações de memória foram realizadas.
    if(All_pokemons == NULL || melhor_equipe == NULL || combinacao == NULL){
        printf("\nErro ao alocar memoria!...");
        fechar();
        exit(1);
    }
    // Copia os Pokémon da lista para um vetor usado nas combinações.
    for(int i = 0; i < numeros_pokemons; i++){
        BuscaPokemon(&Lpokemons, i, &All_pokemons[i]); 
    }

    // Exibe os Pokémon carregados do arquivo.
    printf("=========== Pokemons Carregados ===========\n");
    for(int i = 0; i < numeros_pokemons; i++){
        int ID = getPokeId(&All_pokemons[i]);
        int poder = getPokePower(&All_pokemons[i]);
        int energy = getPokeEnergy(&All_pokemons[i]);
        char nome[TAM_NOMEP];
        getPokeNome(&All_pokemons[i],nome);
        char tipo[TAM_TIPO];
        getPokeTipo(&All_pokemons[i],tipo);

        printf("ID: %-4d | Nome: %-10s | Tipo: %-10s | Poder: %-3d | Energia: %-3d\n", ID, nome, tipo, poder, energy);
    }
    printf("\n=========== Executando Selecao de Pokemons ===========\n");

    // Testa todas as quantidades possíveis de Pokémon na equipe.
    clock_t inicio = clock();
    for(int i = 1; i <= numeros_pokemons; i++){
        Combinacao(&Lpokemons, melhor_equipe,All_pokemons,numeros_pokemons,i,0,0,energia_total,combinacao,&power_melhor_equipe,&contador,&tamanho_melhor_equipe, &energy_melhor_equipe);
    }
    clock_t fim = clock();
    printf("ETAPAS NECESSARIAS: %d\n",contador);
    double tempo = (double) (fim-inicio) / CLOCKS_PER_SEC;
    // Caso nenhuma equipe respeite o limite de energia, encerra o programa.
    if(tamanho_melhor_equipe <= 0){
        printf("Nenhuma equipe valida foi encontrada\n");
        fechar();
        exit(1);
    }
    int Tnum_pokes[NUM_TREINADORES] = {0};
    printf("\n=========== POKEMONS SELECIONADOS ===========\n");
    printf("Tempo de Execucao: %0.2f segundos ou (%0.3f ms)\n",tempo,tempo * 1000);
    printf("Energia total %d/%d | Poder da equipe: %d\n\n",energy_melhor_equipe,energia_total,power_melhor_equipe);
    // Distribui os Pokémon selecionados entre os treinadores.
    for(int i = 0; i < tamanho_melhor_equipe; i++){
        char nome_temp[TAM_NOMEP];
        TipoPokemon poke_temp;
        BuscaPokemon(&Lpokemons,melhor_equipe[i],&poke_temp);
        getPokeNome(&poke_temp,nome_temp);
        int id = getPokeNumero(&poke_temp);
        char tipo_temp[TAM_TIPO];
        getPokeTipo(&poke_temp,tipo_temp);
        int poder = getPokePower(&poke_temp);
        int energy = getPokeEnergy(&poke_temp);
        printf("ID: %-4d | Nome: %-10s | Tipo: %-10s | Poder: %-3d | Energia: %-3d\n",id,nome_temp,tipo_temp,poder,energy);
        AdicionaPokemonTreinador(&treinadores[i%NUM_TREINADORES],&poke_temp);
        Tnum_pokes[i%NUM_TREINADORES] ++;
    }
    printf("\n=========== EQUIPE DOS TREINADORES ===========\n");
    // Lista a equipe recebida por cada treinador.
    for(int i = 0; i < NUM_TREINADORES; i++){
        printf("Treinador %d: %s\n",i+1,getTreinadorNome(&treinadores[i]));
        for(int j = 0; j < Tnum_pokes[i]; j++){
            char nome_temp[TAM_NOMEP];
            TipoPokemon poke_temp;
            RemoverPokemonTreinador(&treinadores[i],&poke_temp);
            getPokeNome(&poke_temp,nome_temp);
            int id = getPokeNumero(&poke_temp);
            char tipo_temp[TAM_TIPO];
            getPokeTipo(&poke_temp,tipo_temp);
            int poder = getPokePower(&poke_temp);
            int energy = getPokeEnergy(&poke_temp);
            printf("ID: %-4d | Nome: %-10s | Tipo: %-10s | Poder: %-3d | Energia: %-3d\n",id,nome_temp,tipo_temp,poder,energy);
        }
        printf("\n");
    }
    // Libera as estruturas alocadas dinamicamente e encerra o programa.
    free(melhor_equipe);
    free(combinacao);
    free(All_pokemons);
    LiberaLista(&Lpokemons);
    for(int i = 0; i < NUM_TREINADORES; i++){
        LiberaTreinador(&treinadores[i]);
    }

    fechar();
    return 0;
}
