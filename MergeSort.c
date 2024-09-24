#include <stdio.h>

// Función para fusionar dos subarrays
void fusionar(int array[], int izq, int medio, int der) {
    int n1 = medio - izq + 1;
    int n2 = der - medio;

    // Crear arrays temporales
    int L[n1], R[n2];

    // Copiar datos a los arrays temporales L[] y R[]
    for (int i = 0; i < n1; i++)
        L[i] = array[izq + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[medio + 1 + j];

    // Fusionar los arrays temporales de vuelta en array[]
    int i = 0, j = 0, k = izq;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort
void mergeSort(int array[], int izq, int der) {
    if (izq < der) {
        int medio = izq + (der - izq) / 2;

        // Ordenar la primera y segunda mitad
        mergeSort(array, izq, medio);
        mergeSort(array, medio + 1, der);

        // Fusionar las dos mitades
        fusionar(array, izq, medio, der);
    }
}

// Función para imprimir el array
void imprimirArray(int array[], int tam) {
    for (int i = 0; i < tam; i++)
        printf("%d ", array[i]);
    printf("\n");
}

// Función principal
int main() {
    int array[] = {12, 11, 13, 5, 6, 7};
    int tam = sizeof(array) / sizeof(array[0]);

    printf("Array original: \n");
    imprimirArray(array, tam);

    mergeSort(array, 0, tam - 1);

    printf("\nArray ordenado: \n");
    imprimirArray(array, tam);
    return 0;
}
