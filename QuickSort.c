#include <stdio.h>

// Función para intercambiar dos elementos
void intercambiar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Función para ubicar el pivote en su posición correcta
int particion(int array[], int bajo, int alto) {
    int pivote = array[alto];  // Se elige el último elemento como pivote
    int i = (bajo - 1);  // Índice del elemento más pequeño

    for (int j = bajo; j <= alto - 1; j++) {
        // Si el elemento actual es menor o igual al pivote
        if (array[j] <= pivote) {
            i++;  // Incrementa el índice del elemento más pequeño
            intercambiar(&array[i], &array[j]);
        }
    }
    intercambiar(&array[i + 1], &array[alto]);
    return (i + 1);
}

// Función principal del QuickSort
void quickSort(int array[], int bajo, int alto) {
    if (bajo < alto) {
        // p es el índice de partición, array[p] está en la posición correcta
        int p = particion(array, bajo, alto);

        // Ordenar de manera recursiva las sublistas
        quickSort(array, bajo, p - 1);
        quickSort(array, p + 1, alto);
    }
}

// Función para imprimir el array
void imprimirArray(int array[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Función principal
int main() {
    int array[] = {10, 7, 8, 9, 1, 5};
    int tam = sizeof(array) / sizeof(array[0]);

    printf("Array original: \n");
    imprimirArray(array, tam);

    quickSort(array, 0, tam - 1);

    printf("\nArray ordenado: \n");
    imprimirArray(array, tam);
    return 0;
}
