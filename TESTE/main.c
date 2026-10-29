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

    clock_t tempo;
    TipoTreinador treinadores[NUM_TREINADORES]; // Lista de treinadores
    TipoPokemon *ListaArranjo; // Lista de pokemons do arquivo
    ListaArranjo = NULL; // Inicializa o ponteiro como NULL
    int QuantidadePokemons = 0;
    int EnergiaDisponivel = 0;

    // Leitura dos dados do arquivo de entrada
    FILE *fptr = fopen("teste1.txt","r");
    if(fptr==NULL){
        printf("Erro ao abrir o arquivo de entrada.\n");
        return 1;
    }
    CarregaDados(fptr,treinadores,&ListaArranjo,&EnergiaDisponivel,&QuantidadePokemons);
    fclose(fptr);
    
    ImprimePokemonsCarregados(ListaArranjo, QuantidadePokemons); //impressao dos pokemons carregados do arquivo
    execucao(); //impressao do inicio da execucao do algoritmo de selecao de pokemons

    //Variaveis auxiliares
    int melhorequipe[QuantidadePokemons]; // Vetor para armazenar a melhor equipe encontrada(retem os indices dos pokemons na lista de pokemons)
    int maiorpoder =0;
    int energiaconsumida=0;
    int tamanho_melhor_equipe=0;
    tempo = clock(); // Inicia a contagem do tempo de execução(apenas para a geração de combinações e cálculo da melhor equipe)

    // Geração de combinacoes das equipes e seleçcao da melhor equipe
    for(int k=1; k<=QuantidadePokemons;k++){
        int aux[k];
        int poder=0;
        int energia=0;
        //inicializa a primeira combinação de tamanho k
        for(int i=0; i<k; i++){
            aux[i] = i;
            poder += ListaArranjo[aux[i]].Poder;
            energia += ListaArranjo[aux[i]].EnergiaGasta;
        }
        // Analisa se a primeira combinação de tamanho k é a melhor até agora
        if((energia<=EnergiaDisponivel) && (poder > maiorpoder)){
            maiorpoder = poder;
            energiaconsumida=energia;
            tamanho_melhor_equipe = k;
            for(int i=0; i<k; i++){ // Entra no loop sse a combinação atual é melhor que a anterior
                melhorequipe[i] = aux[i];
                if(i==k-1){
                    melhorequipe[i+1]=-1; // Marca o final da equipe com -1 (nao é um índice válido)    
                }
            }
        }
        while (ProximaCombinacao(aux, QuantidadePokemons, k)){
            poder=0;
            energia=0;
            for(int i=0;i<k;i++){
                poder += ListaArranjo[aux[i]].Poder;
                energia += ListaArranjo[aux[i]].EnergiaGasta;
            }
            if((energia<=EnergiaDisponivel) && (poder > maiorpoder)){
            maiorpoder = poder;
            energiaconsumida=energia;
            tamanho_melhor_equipe = k;
            for(int i=0; i<k; i++){ // Entra no loop sse a combinação atual é melhor que a anterior
                melhorequipe[i] = aux[i];
                if(i==k-1){
                    melhorequipe[i+1]=-1; // Marca o final da equipe com -1 (nao é um índice válido)    
                }
            }
        }
        tempo = clock() - tempo; // Finaliza a contagem do tempo de execução(apenas para a geração de combinações e cálculo da melhor equipe)

        }
    }

    ImprimeStatus(maiorpoder, energiaconsumida, EnergiaDisponivel, tempo); //imprime o status da melhor equipe encontrada
    ImprimeSelecionados(melhorequipe,ListaArranjo); //imprime os pokemons selecionados para a melhor equipe 
    
    
    //divide os pokemons entre os treinadores
    for(int i=0;i<tamanho_melhor_equipe;i++){
        int temp = i%NUM_TREINADORES;
        InserePokemon(getPokelista(&treinadores[temp]),&ListaArranjo[melhorequipe[i]]);
    }

    //imprime o a mochila de cada treinador
    printf("\n=== Equipes dos Treinadores ===\n");
    for(int i=0;i<NUM_TREINADORES;i++){
        printf("treinador 1: %s\n",getTreinadorNome(&treinadores[i]));
        ImprimeLista(getPokelista(&treinadores[i]));
    }

    free(ListaArranjo); // Libera a memória alocada para a lista de pokemons
    return 0; 
 }
