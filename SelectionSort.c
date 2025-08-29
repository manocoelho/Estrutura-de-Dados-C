
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int *V, int TAM){  // Procura o menor elemento em relação a "i"
    
    int i, j, menor, troca;         
    
    for(i = 0; i < TAM-1; i++){       
        menor = i;
        
        for(j = i+1; j < TAM; j++){
            
            if(V[j] < V[menor])     //Posição J é menor do que o menor valor? Se sim, atualiza o valor de menor.
                menor = j;
        }
        
        if(i != menor){             // Troca os valores da posição atual com o "menor"
            
            troca = V[i];
            V[i] = V[menor];
            V[menor] = troca;
        }
    }
}


int main(void){

clock_t start, end;
double cpu_time_used;

start = clock();

//    int vet[10] = {23,4,67,-8,54,90,21,14,-5,1};
//    int TAM = 10;

int vet[7] = {23,4,67,-8,90,54,21};
int TAM = 7;

//    int vet[7] = {23,4,67,-8,21};
//    int TAM = 5;

printf("\nVetor nao ordenado:\n");

for(int i=0; i<TAM; i++){

    printf("%d\n",vet[i]);
}

selectionSort(vet,TAM);
printf("\nVetor ordenado:\n");

for(int i=0; i<TAM; i++){

    printf("%d\n",vet[i]);
}
end = clock();

cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nTempo de execucao: %f segundos\n\n", cpu_time_used);
 
return 0;
}