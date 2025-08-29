#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

struct elemento{

    int dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista(Lista* li){

    Lista* li = malloc(sizeof(Lista));
    if(li != NULL){
        
        *li = NULL;
    }

    return li;
}

void libera_lista(Lista* li){

    if(li != NULL){
        
        Elem* no;
        while((*li != NULL)){

            no = *li;
            *li = (*li)->prox;
            free(no);
        }

        free(li);
    }
}

int tamanho_lista(Lista* li){

    if(li == NULL){
        
        return 0;
    }

    Elem* no;
    no = *li;
    int contador = 0;

    while(no != NULL){

        contador++;
        no = no->prox;
    }

    return contador;
}

int lista_vazia(Lista* li){

    if(li == NULL){
        
        return 1;
    }else if(*li == NULL){
        
        return 1;
    }else{
        
        return 0;
    }
}

int insere_inicio(Lista* li, int valor){

    if(li == NULL){
        
        return 0;
    }

    Elem* no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){

        return 0;
    }

    no->dados = valor;
    no->prox = (*li);
    *li = no;
    
    return 1;
}

int insere_fim(Lista* li, int valor){

    if(li == NULL){

        return 0;
    }

    Elem* no= (Elem*) malloc(sizeof(Elem));
    if(no == NULL){

        return 0;
    }

    no->dados = valor;
    no->prox = NULL;

    if((*li) == NULL){

        *li = no;
    }else{

        Elem* aux = *li;
        while(aux->prox != NULL){
            
            aux = aux->prox;
        }

        aux->prox = no;
    }
}

int insere_ordenado(Lista* li, int valor){

    if(li == NULL){

        return 0;
    }

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){

        return 0;
    }

    no->dados = valor;

    if(lista_vazia(li)){
        no->prox = (*li);
        *li = no;

        return 1;
    }else{

        Elem *ant, *atual = *li;
        while(atual != NULL && atual->dados < valor){

            ant = atual;
            atual = atual->prox;
        }

        if(atual == *li){
            
            no->prox = (*li);
            *li = no;
        }else{

            no->prox = ant->prox;
            ant->prox = no;
        }
    }
}

int remove_inicio(Lista* li){

    if(li == NULL){
        
        return 0;
    }

    if(*li == NULL){

        return 0;
    }

    Elem* no = *li;
    *li = no->prox;
    free(no);
    
    return 1;
}

int remove_fim(Lista* li){

    if(li == NULL){
        
        return 0;
    }

    if(*li == NULL){

        return 0;
    }

    Elem *no, *ant = *li;
    while(no->prox != NULL){

        ant = no;
        no = no->prox;  
    }

    if(no == (*li)){
        
        *li = no->prox;
    }else{

        ant->prox = no->prox;
        free(no);
    }
    
    return 1;
}

int remove_elemento(Lista* li, int valor){

    if(li == NULL){
        
        return 0;
    }

    if(*li == NULL){

        return 0;
    }

    Elem *no, *ant = *li;
    while(no != NULL && no != valor){

        ant = no;
        no = no->prox;
    }

    if(no == NULL){ // valor não encontrado.

        return 0;
    }
    
    if(no == *li){

        *li = no->prox;
    }else{
        
        ant->prox = no->prox;   
    }
    
    free(no);
    return 1;
}
