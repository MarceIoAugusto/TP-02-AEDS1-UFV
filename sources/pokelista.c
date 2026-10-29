#include "pokelista.h"

void InicializaLista(PokeLista *Lista) { /* Inicializa a celula cabeça da lista encadeada*/
    Lista->Primeiro = (PokeCelula *)malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Primeiro;
    Lista->Ultimo->Proximo = NULL;
}

void InserePokemon(PokeLista *Lista, TipoPokemon *pokemon) { /* Insere o Pokemon ao Final da Lista*/
    Lista->Ultimo->Proximo = (PokeCelula *)malloc(sizeof(PokeCelula));
    Lista->Ultimo = Lista->Ultimo->Proximo; /*Deste jeito permite a existencia de uma celula cabeça, ja que ele pula o primeiro e ja coloca no proximo dele*/
    Lista->Ultimo->Pokemon = *pokemon;
    Lista->Ultimo->Proximo = NULL;
}

int RemovePokemon(PokeLista *Lista, TipoPokemon *pokemon) { /* Remove o Primeiro pokemon da lista e o retorna como parâmetro*/
    PokeCelula *Auxiliar;
    if (Lista->Primeiro->Proximo == NULL) {
        // Lista vazia
        return 0;
    }

    Auxiliar = Lista->Primeiro->Proximo->Proximo;
    *pokemon = Lista->Primeiro->Proximo->Pokemon;

    if (Lista->Ultimo == Lista->Primeiro->Proximo) {
        Lista->Ultimo = Lista->Primeiro;
    }

    free(Lista->Primeiro->Proximo);
    Lista->Primeiro->Proximo = Auxiliar;

    return 1;
}

//Retorna o primeiro pokemon que está em "Primeiro->Proximo->Pokemon"
TipoPokemon *getPrimeiroItem(PokeLista Lista) {
    return &Lista.Primeiro->Proximo->Pokemon;
}

//Percorre a lista e Imprime todos os pokemons na tela
void ImprimeLista(PokeLista *Lista) {
    PokeCelula *curr;
    curr = Lista->Primeiro->Proximo; // pula a celula cabeca

    while (curr != NULL) {
        ImprimePokemon(&curr->Pokemon);
        curr = curr->Proximo;
    }
}

//Percorre a lista e Imprime todos os pokemons no arquivo de saida.txt
void ImprimeListaFile(FILE *saida, PokeLista *Lista) {
    PokeCelula *curr;
    curr = Lista->Primeiro->Proximo; // pula a celula cabeca

    while (curr != NULL) {
        ImprimePokemonFile(saida, &curr->Pokemon);
        curr = curr->Proximo;
    }
}

int ListaEVazia(PokeLista *Lista) {
    if (Lista->Primeiro->Proximo == NULL) {
        return 1;
    } else
        return 0;
}

// Libera todas as celulas 
void LiberaLista(PokeLista *Lista) {
    PokeCelula *atual = Lista->Primeiro;
    PokeCelula *proxima;
    while (atual != NULL) {
        proxima = atual->Proximo; // guarda o proximo antes de liberar
        free(atual);
        atual = proxima;
    }
    Lista->Primeiro = NULL;
    Lista->Ultimo = NULL;
}
