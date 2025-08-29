#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha{

    int controle;
    struct elemento dado[TAM];
};

Pilha* cria_pilha(){

    Pilha* pi = (Pilha*) malloc(sizeof(struct pilha));
    if(pi != NULL){

        pi->controle = 0;
    }
    
    return pi;
}

void libera_pilha(Pilha* pi){

    free(pi);
}

int tamanho_pilha(Pilha* pi){
    
    if(pi == NULL){

        return -1;
    }

    return pi->controle;
}

int pilha_vazia(Pilha* pi){

    if(pi == NULL){
        
        return -1;
    }

    if(pi->controle == 0){

        return 1;
    }
}

int pilha_cheia(Pilha* pi){

    if(pi == NULL){

        return -1;
    }

    if(pi->controle == TAM){

        return 1;
    }
}

int consulta_topo_Pilha(Pilha* pi, struct elemento *valor){

    if(pi == NULL || pilha_vazia(pi)){

        return 0;
    }

    *valor = pi->dado[pi->controle-1];

    return 1;
}

int insere_pilha(Pilha* pi, struct elemento valor){
    if(pi == NULL){

        return 0;
    }

    if(pilha_cheia(pi)){

        return 0;
    }

    pi->dado[pi->controle] = valor;
    pi->controle++;
    return 1;
}

int remove_pilha(Pilha* pi){

     if(pi == NULL){

        return 0;
    }

    if(pilha_vazia(pi)){

        return 0;
    }

    pi->controle--;

}