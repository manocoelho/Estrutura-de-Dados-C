#include <stdio.h>
#include <stdio.h>
#include <time.h>

void merge(int arr[], int left, int middle, int right) { // Função para mesclar dois subarrays ordenados em um único array ordenado
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];   // Cria arrays temporários

    for (i = 0; i < n1; i++)    // Copia os dados para os arrays temporários L[] e R[]
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[middle + 1 + j];

    // Mescla os arrays temporários de volta em arr[left..right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {    // Copia os elementos restantes de L[], se houver
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {    // Copia os elementos restantes de R[], se houver
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {    // Função principal para realizar a ordenação MergeSort em um array
    if (left < right) {
    
        int middle = left + (right - left) / 2; // Encontra o ponto médio do array

        mergeSort(arr, left, middle);   // Ordena a metade esquerda do array
        mergeSort(arr, middle + 1, right);  // Ordena a metade direita do array
        merge(arr, left, middle, right);    // Mescla as duas metades ordenadas
    }
}

int main(void){
    
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("\nArray desordenado:\n");
    for (int i = 0; i < arr_size; i++) {
        
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArray ordenado:\n");
    for (int i = 0; i < arr_size; i++) {
        
        printf("%d ", arr[i]);
    }
    
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTempo de execucao: %f segundos\n\n", cpu_time_used);
    
    return 0;
}