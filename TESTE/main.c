 #include "pokelista.h"
 #include "pokemon.h"
 #include "treinador.h"
 #include "saida.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>


 void CarregaDados(FILE* fptr, TipoTreinador *treinadores,TipoPokemon **listaarranjo,int *energia, int *quantidade){
    for(int i=0; i<NUM_TREINADORES; i++){
        leTreinador(fptr,&treinadores[i]);
    }
    fscanf(fptr,"%d",quantidade);
    fscanf(fptr,"%d",energia);
    *listaarranjo = (TipoPokemon*)malloc(*quantidade * sizeof(TipoPokemon)); //o ponteiro agora aponta para um vetor de tipo TipoPokemon.
    if(*listaarranjo == NULL) {
        printf("Erro ao alocar memoria para a lista de pokemons.\n");
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<*quantidade;i++){
        TipoPokemon temp; //variavel temporaria para armazenar o pokemon lido do arquivo
        LePokemon(fptr,&temp);
        (*listaarranjo)[i]=temp;
    }     
 }

 //calcula a proxima combinacao de k elementos de um conjunto de n elementos
 int ProximaCombinacao(int a[], int n, int k){
    int j = k - 1;

    /* Procura a posição mais à direita que pode aumentar. */
    while (j >= 0 && a[j] == n - k + j) {
        j--;
    }

    /* Se nenhuma posição pode aumentar, terminou. */
    if (j < 0) {
        return 0;
    }

    /* Incrementa a posição encontrada. */
    a[j]++;

    /* Ajusta as posições seguintes. */
    for (int i = j + 1; i < k; i++) {
        a[i] = a[i - 1] + 1;
    }

    return 1;
}


 int main(){

    TipoTreinador treinadores[NUM_TREINADORES]; // Lista de treinadores
    TipoPokemon *ListaArranjo; // Lista de pokemons do arquivo
    ListaArranjo = NULL; // Inicializa o ponteiro como NULL
    int QuantidadePokemons = 0;
    int EnergiaDisponivel = 0;

    // Leitura dos dados do arquivo de entrada
    FILE *fptr = fopen("teste2.txt","r");
    if(fptr==NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    CarregaDados(fptr,treinadores,&ListaArranjo,&EnergiaDisponivel,&QuantidadePokemons);
    fclose(fptr);

    //Geracao de combinacoes de equipes

    /*int melhorequipe[QuantidadePokemons];*/

    for(int k=1; k<=QuantidadePokemons;k++){
        int aux[k];
        //inicializa a primeira combinação
        for(int i=0; i<k; i++){
            aux[i] = i;
        }
        // A primeira combinação já foi gerada, então imprimimos. alem de ser a entrada para o while.
        printf("========================Combinacoes de tamanho %d========================\n", k);
        for(int i=0; i<k; i++){
            ImprimePokemon(&ListaArranjo[aux[i]]);
        }
        printf("\n");
        while (ProximaCombinacao(aux, QuantidadePokemons, k)){
            for(int i=0; i<k; i++){
                ImprimePokemon(&ListaArranjo[aux[i]]);
            }
            printf("\n");
        }
    }


    free(ListaArranjo); // Libera a memória alocada para a lista de pokemons


    return 0; 
 }
