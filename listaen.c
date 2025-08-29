#include <stdio.h>
#include <stdlib.h>
#include "listaen.h"

struct elemento{

    struct elemento *prox;
    struct aluno dado;
};  

typedef struct elemento Elem;

Lista* cria_lista(){

    Lista* li = (Lista*)malloc(sizeof(Lista));
    if(li != NULL){

        *li = NULL;
    }

    return li;
}

void libera_lista(Lista* li){

    if(li == NULL){

        return 0;
    }

    Elem* no;
    while((*li) != NULL){

        no = *li;
        *li = (*li)->prox;
        free(no);
    }

    free(li);
}

int tamanho_lista(Lista *li){

    if(li == NULL){
        return 0;
    }

    Elem* no;
    int contador = 0;
    while(no != NULL){

        contador++;
        no = no->prox;
    }

    return contador;
}

int lista_cheia(Lista *li){

    return 0;
}

int lista_vazia(Lista *li){

    if(li == NULL){

        return 1;
    }
    
    if(*li == NULL){

        return 1;
    }

    return 0;
}

int remove_inicio(Lista *li, struct aluno valor){

    if(li == NULL || lista_vazia(li)){

        return 0;
    }

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){

        return 0;
    }

    no->dado = valor;
    no->prox = (*li);
    *li = no;
    
    return 1;
}

int insere_fim(Lista *li, struct aluno valor){

    if(li == NULL){

        return 0;
    }

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        
        return 0;
    }

    no->dado = valor;
    no->prox = NULL;

    if(*li == NULL){

        *li = no;
    }else{

        Elem *aux = *li;
        while(aux->prox != NULL){

            aux = aux->prox;
        }
        aux->prox = no;
    }

    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno valor){

    if(li == NULL){
        return 0;
    }

    Elem* no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL){
        
        return 0;
    }

    no->dado = valor;

    if(*li == NULL){

        no->prox= (*li);
        *li = no;
        
        return 1;
    }else{

        Elem *atual, *anterior = *li;
        while(atual != NULL && atual->dado.matricula < valor.matricula){

            anterior = atual;
            atual = atual->prox;
        }

        if(atual == *li){

            no->prox = (*li);
            *li = no;
        }else{
            
            no->prox = anterior->prox;
            anterior->prox = no;
        }
    }
}

int remove_inicio(Lista* li){

    if(li == NULL || lista_vazia(li)){

        return 0;
    }

    Elem* no = *li;

    *li = no->prox;
    free(no);
    
    return 1;
}

int remove_fim(Lista* li){

    if(li == NULL || lista_vazia(li)){

        return 0;
    }

    Elem* no, *anterior = *li;

    while(no != NULL){

        anterior = no;
        no = no->prox;
    }

    if(no == (*li)){

        no->prox = (*li);
        *li = no;
    }else{

    anterior->prox = no->prox;
    }
    
    free(no);
    return 1;
}

int remove_lista(Lista* li, int valor){

    if(li == NULL || lista_vazia(li)){

        return 0;
    }

    Elem *no, *ant = *li;
    while(no != NULL && no->dado.matricula != valor){

        ant = no;
        no = no->prox;
    }

    if(*li == NULL){

        no->prox = (*li);
        *li = no;
    }else{

        ant->prox = no->prox;
    }

    free(no);
    return 1;
}

