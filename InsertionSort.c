
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int *V, int TAM){
    int i, j, aux;

    for(i = 1; i < TAM; i++){                           //Percorre o vetor na posição 1 até Tam - 1
        
        aux = V[i];                                     //Move os valores maiores do que o valor na posição i
        
        for(j = i; (j > 0) && (aux < V[j - 1]); j--){   //Enquanto J for < 0 e o aux for menor que algum dos valores de J
                                                        //Volta o indíce J e copia os elementos para frente
            V[j] = V[j - 1];
        } 

        V[j] = aux;
    }
}

int main(void){
    
clock_t start, end;
double cpu_time_used;

start = clock();

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
end = clock();

cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTempo de execucao: %f segundos\n\n", cpu_time_used);
    
return 0;
}