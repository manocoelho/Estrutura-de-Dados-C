#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct fila{
    
    int controle, inicio, fim;
    struct pessoa dados[TAM];
};

Fila* cria_fila(){

    Fila* fi = (Fila*)malloc(sizeof(struct fila));
    if(fi != NULL){
        
        fi->controle = 0;
        fi->inicio = 0;
        fi->fim = 0;
    }

    return 1;   
}

void libera_fila(Fila* fi){

    free(fi);
}

int tamanho_Fila(Fila* fi){
    
    if(fi == NULL){
        
        return -1;
    }
    
    return fi->controle;
}

int Fila_vazia(Fila* fi){

    if(fi == NULL){
        
        return -1;
    }

    if(fi->controle == 0){
        
        return 1;
    }else{

        return 0;
    }
}

int Fila_cheia(Fila* fi){

    if(fi == NULL){
        
        return -1;
    }

    if(fi->controle == TAM){

        return 1;
    }else{

        return 0;
    }
}

int insere_fila(Fila* fi, struct pessoa valor){

    if(fi == NULL){
        
        return 0;
    }

    if(fila_cheia(fi)){
        
        return 0;
    }

    fi->dados[fi->fim] = valor;
    fi->fim = (fi->fim) % TAM;
    fi->controle++;
}

int remove_fila(Fila* fi){

    if(fi == NULL){

        return 0;
    }

    if(fila_vazia(fi)){

        return 0;
    }

    fi->inicio = (fi->inicio + 1) % TAM;
    fi->controle++;

    return 1;
}

int consulta_Fila(Fila* fi, struct pessoa *valor){

    if(fi == NULL || Fila_vazia(fi)){

        return 0;
    }
        
    *valor = fi->dados[fi->inicio];
    return 1;
}
