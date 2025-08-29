
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *V, int TAM){
    int i, j, aux;

    for(i = 1; i < TAM; i++){
        
        aux = V[i];
        
        for(j = i; (j > 0) && (aux < V[j - 1]); j--){

            V[j] = V[j - 1];
        } 

        V[j] = aux;
    }
}

int main(){
    int vet[10] = {23,4,67,-8,54,90,21,14,-5,1};
    int TAM = 10;

//    int vet[7] = {23,4,67,-8,90,54,21};
//    int TAM = 7;

//    int vet[7] = {23,4,67,-8,21};
//    int TAM = 5;

    printf("\nVetor nao ordenado:\n");
    
    for(int i=0; i<TAM; i++){

        printf("%d\n",vet[i]);
    }

    insertionSort(vet,TAM);
    
    printf("\nVetor ordenado:\n");

    for(int i=0; i<TAM; i++){

        printf("%d\n",vet[i]);
    }
       
    return 0;
}