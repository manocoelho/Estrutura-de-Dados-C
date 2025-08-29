#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct lista{

    int controle;
    int vetor[TAM];
};

Lista* cria_lista(){
    Lista* li;
    li = (Lista*) malloc(sizeof(struct lista));

    if(li != NULL){
        
        li->controle = 0;
        

    }else{

        printf("\nMemoria nao alocada!\n");
        return li;
    }
}

void libera_lista(Lista* li){

    free(li);

}

int tamanho_lista(Lista* li){

    if(li == NULL){

        return -1;

    }else{

        return li->controle;

    }
             
}

int lista_vazia(Lista* li){

    if(li == NULL){

        return -1;
        
    }else{

        printf("\nlista vazia\n");
        return (li->controle == 0);

    }
    
}

int lista_cheia(Lista* li){

    if(li == NULL){

        return -1;
        
    }else{

        printf("\nlista cheia!\n");
        return (li->controle == TAM);

    }

}

int insere_inicio(Lista* li, int valor){

    if(li == NULL){

        return 0;

    }
    
    if(lista_cheia(li)){
        
        return 0;

    }else{

        for(int i = li->controle-1; i >= 0; i--){

            li->vetor[i + 1] = li->vetor[i];

        }

        li->vetor[0] = valor;
        li->controle++;
        return 1;
    }

}

int insere_fim(Lista* li, int valor){

    if(li == NULL){

        return 0;

    }
    
    if(lista_cheia(li)){

        return 0;

    }else{

        li->vetor[li->controle] = valor;
        li->controle++;
        return 1;
        
    }


}

int remove_inicio(Lista* li){

    if(li == NULL){

        return 0;

    }

    if(lista_vazia(li)){

        return 0;

    }else{

        for(int i = 0; i > li->controle - 1; i++){

            li->vetor[i] = li->vetor[i + 1];

        }

        li->controle--;
        return 1;
    }

}

int remove_fim(Lista* li){

    if(li == NULL){
        
        return 0;

    }
    
    if(lista_vazia(li)){

        return 0;

    }else{

        li->controle--;
        return 1;
    }

}

int mostrar_lista(Lista *li){

    if(li == NULL){

        return 0;
    }

    if(lista_vazia(li)){

        return 0;

    }else{

        printf("Elementos presentes na lista: \n");

        for(int i = 0; i < li->controle; i++){

            printf("%d, ", li->vetor[i]);

        }

        return 1;

    }
    
}