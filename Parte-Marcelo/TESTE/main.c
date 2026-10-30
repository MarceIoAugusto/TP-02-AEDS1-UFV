 #include "pokelista.h"
 #include "pokemon.h"
 #include "treinador.h"
 #include "saida.h"

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>


 void CarregaDados(FILE* fptr, TipoTreinador *treinadores,TipoPokemon **listaarranjo,int *energia, int *quantidade){
    int cont=0;
    TipoPokemon temp; //variavel temporaria para armazenar o pokemon lido do arquivo
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
    
    while( (cont<*quantidade) && LePokemon(fptr,&temp)){ // cont<*quantidade impede estourar o vetor caso tenha mais pokemons que o informado
        (*listaarranjo)[cont]=temp;
        cont++;
    }
    if(*quantidade != cont){
        printf("\x1b[31mFLAG:ERRO AO LER POKEMONS.\nQUANTIDADE INFORMADA (%d) DIVERGE DA QUANTIDADE DE POKEMONS DISPONIVEIS PARA LEITURA.\x1b[0m\n", *quantidade);
        printf("\x1b[31mO programa ira continuar, mas a quantidade de pokemons lidos sera %d. \x1b[0m\n",cont);
        *quantidade = cont;
    }
}

 //calcula a proxima combinacao de k elementos de um conjunto de n elementos
 int ProximaCombinacao(int a[], int n, int k){
    // Adaptado do algoritmo 4.3 pag 58 do livro Combinatorial Generation
    // Autor: Frank Ruskey <- DISPONIVEL NA INTERNET
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

void DistribuiPokemons(TipoTreinador *treinadores, TipoPokemon *ListaArranjo, int *melhorequipe, int tamanho_melhor_equipe) {
    for(int i=0;i<tamanho_melhor_equipe;i++){
        int temp = i%NUM_TREINADORES;
        InserePokemon(getPokelista(&treinadores[temp]),&ListaArranjo[melhorequipe[i]]);
    }
}


void AvaliaCombinacao(int *melhorequipe, int *aux, int *energia, int *EnergiaDisponivel, int *energiaconsumida, int *poder, int *maiorpoder,int *tamanho_melhor_equipe,int *k){
    if((*energia<=*EnergiaDisponivel) && (*poder >*maiorpoder)){//em caso de empate no poder a atual melhor equipe é mantida
        *maiorpoder = *poder;
        *energiaconsumida=*energia;
        *tamanho_melhor_equipe = *k;
        for(int i=0; i<*k; i++){ // Entra no loop sse a combinação atual é melhor que a anterior
            melhorequipe[i] = aux[i];
        }
    }
}

int main(){

    clock_t inicio,fim,tempo;// Variaveis para medir o tempo de execução da operacao chave
    TipoTreinador treinadores[NUM_TREINADORES]; // Lista de treinadores
    TipoPokemon *ListaArranjo; // Lista de pokemons do arquivo
    ListaArranjo = NULL; // Inicializa o ponteiro como NULL
    int QuantidadePokemons = 0;
    int EnergiaDisponivel = 0;
    
    char nomearquivo[TAM_ARQUIVO]; // Nome do arquivo de entrada
    Menu();
    scanf("%s", nomearquivo);
    LimparTela();

    // Leitura dos dados do arquivo de entrada
    FILE *fptr = fopen(nomearquivo,"r");
    while(fptr == NULL){
        printf("Erro ao abrir o arquivo de entrada\nPossivel nome invalido, tente novamente.\n");
        printf("\nDigite o nome do arquivo de entrada (ex: teste1.txt): ");
        scanf("%s", nomearquivo);
        fptr = fopen(nomearquivo,"r");
        LimparTela();
    }
    CarregaDados(fptr,treinadores,&ListaArranjo,&EnergiaDisponivel,&QuantidadePokemons);
    fclose(fptr);
    
    
    
    
    //Variaveis auxiliares para a logica de combinacao e 
    int melhorequipe[QuantidadePokemons]; // Vetor para armazenar a melhor equipe encontrada(retem os indices dos pokemons na lista de pokemons)
    int maiorpoder =0;
    int energiaconsumida=0;
    int tamanho_melhor_equipe=0;

    inicio = clock(); // Inicia a contagem do tempo de execução(apenas para a geração de combinações e cálculo da melhor equipe)
    for(int k=1; k<=QuantidadePokemons;k++){// Geração de combinacoes das equipes e seleçcao da melhor equipe
        int aux[k];
        int poder=0;
        int energia=0;
        //inicializa a primeira combinação de tamanho k
        for(int i=0; i<k; i++){
            aux[i] = i;
            poder += getPokePoder(&ListaArranjo[aux[i]]);
            energia += getPokeEnergiaGasta(&ListaArranjo[aux[i]]);
        }
        // Analisa se a primeira combinação de tamanho k é a melhor até agora
        AvaliaCombinacao(melhorequipe,aux,&energia,&EnergiaDisponivel,&energiaconsumida,&poder,&maiorpoder,&tamanho_melhor_equipe,&k);
    
        while (ProximaCombinacao(aux, QuantidadePokemons, k)){
            poder=0;
            energia=0;
            for(int i=0;i<k;i++){
                poder += getPokePoder(&ListaArranjo[aux[i]]);
                energia += getPokeEnergiaGasta(&ListaArranjo[aux[i]]);
            }
            AvaliaCombinacao(melhorequipe,aux,&energia,&EnergiaDisponivel,&energiaconsumida,&poder,&maiorpoder,&tamanho_melhor_equipe,&k);
        }
    }
    fim = clock(); // Finaliza a contagem do tempo de execução(apenas para a geração de combinações e cálculo da melhor equipe)
    tempo = fim - inicio;
    
    
    
    ImprimePokemonsCarregados(ListaArranjo, QuantidadePokemons); //impressao dos pokemons carregados do arquivo
    ImprimeExecucao(); //impressao do inicio da execucao do algoritmo de selecao de pokemons
    ImprimeStatus(maiorpoder, energiaconsumida, EnergiaDisponivel, tempo); //imprime o status da melhor equipe encontrada
    ImprimeSelecionados(melhorequipe,ListaArranjo,tamanho_melhor_equipe); //imprime os pokemons selecionados para a melhor equipe 
    
    DistribuiPokemons(treinadores, ListaArranjo, melhorequipe, tamanho_melhor_equipe);//divide os pokemons entre os treinadores
    
    ImprimeTreinadores(treinadores);//imprime o a mochila de cada treinador
    //imprime a saida no arquivo saida.txt
    ImprimeSaida(ListaArranjo, treinadores, melhorequipe, maiorpoder, energiaconsumida,
                    EnergiaDisponivel, tempo, QuantidadePokemons, tamanho_melhor_equipe); 


    for(int i=0;i<NUM_TREINADORES;i++){
        LiberaLista(getPokelista(&treinadores[i])); // Libera a memória alocada para as listas de pokemons dos treinadores
    }
    free(ListaArranjo); // Libera a memória alocada para a lista de pokemons
    return 0; 
}
