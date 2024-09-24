// Ordenamiento de burbuja con números aleatorios
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){ // Corrección aquí
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n = 10; // Tamaño del arreglo
    int arr[n];

    // Inicialización de números aleatorios
    srand(time(0));

    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < n; i++){
        arr[i] = rand() % 100; // Números aleatorios entre 0 y 99
    }

    printf("Arreglo antes del ordenamiento:\n");
    for(int i = 0; i < n; i++){
        printf("[%d]: %d ",i,arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Arreglo después del ordenamiento:\n");
    for(int i = 0; i < n; i++){
        printf("[%d]: %d ",i,arr[i]);
    }
    printf("\n");

    return 0;
}
