#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

// Función para imprimir un arreglo
void printArray(int arr[], int size) {
    int a;
    for (a = 0; a < size; a++) {
        printf("%d ", arr[a]);
    }
    printf("\n");
}

// Implementación de Insertion Sort
void insertionSort(int arr[], int n) {
    int a, key, b;
    for (a = 1; a < n; a++) {
        key = arr[a];
        b = a - 1;

        while (b >= 0 && arr[b] > key) {
            arr[b + 1] = arr[b];
            b = b - 1;
        }
        arr[b + 1] = key;
    }
}

// Implementación de Quick Sort
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int a = (low - 1);
    int b;
    for (b = low; b <= high - 1; b++) {
        if (arr[b] < pivot) {
            a++;
            swap(&arr[a], &arr[b]);
        }
    }
    swap(&arr[a + 1], &arr[high]);
    return (a + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Implementación de Bubble Sort
void bubbleSort(int arr[], int n) {
    int a, b;
    for (a = 0; a < n - 1; a++)
        for (b = 0; b < n - a - 1; b++)
            if (arr[b] > arr[b + 1])
                swap(&arr[b], &arr[b + 1]);
}

int main() {
    srand(time(NULL));
    int size = 10000;
    int a, b;

    int arr[size];
    for (a = 0; a < size; a++) {
        arr[a] = rand() % 100;
    }
    double total_time_insertion = 0.0, total_time_quick = 0.0, total_time_bubble = 0.0;
    double min_time_insertion = 1e9, min_time_quick = 1e9, min_time_bubble = 1e9;
    double max_time_insertion = 0.0, max_time_quick = 0.0, max_time_bubble = 0.0;

    clock_t start, end;
    double cpu_time_used;

    // Insertion Sort
    for (a = 0; a < 100; a++) {
        int tempArr[size];
        for (b = 0; b < size; b++) {
            tempArr[b] = arr[b];
        }

        start = clock();
        insertionSort(tempArr, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        total_time_insertion += cpu_time_used;
        if (cpu_time_used < min_time_insertion) min_time_insertion = cpu_time_used;
        if (cpu_time_used > max_time_insertion) max_time_insertion = cpu_time_used;
        printf("Insertion Sort - Tiempo de ejecucion %d: %f milisegundos\n", a + 1, cpu_time_used);
    }

    // Quick Sort
    for (a = 0; a < 100; a++) {
        int tempArr[size];
        for (b = 0; b < size; b++) {
            tempArr[b] = arr[b];
        }

        start = clock();
        quickSort(tempArr, 0, size - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        total_time_quick += cpu_time_used;
        if (cpu_time_used < min_time_quick) min_time_quick = cpu_time_used;
        if (cpu_time_used > max_time_quick) max_time_quick = cpu_time_used;
        printf("Quick Sort - Tiempo de ejecucion %d: %f milisegundos\n", a + 1, cpu_time_used);
    }

    // Bubble Sort
    for (a = 0; a < 100; a++) {
        int tempArr[size];
        for (b = 0; b < size; b++) {
            tempArr[b] = arr[b];
        }

        start = clock();
        bubbleSort(tempArr, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        total_time_bubble += cpu_time_used;
        if (cpu_time_used < min_time_bubble) min_time_bubble = cpu_time_used;
        if (cpu_time_used > max_time_bubble) max_time_bubble = cpu_time_used;
        printf("Bubble Sort - Tiempo de ejecucion %d: %f milisegundos\n", a + 1, cpu_time_used);
    }
     printf("\n\n--- Estadisticas Resumidas ---\n");
    printf("Insertion Sort\n - Tiempo Promedio: %f milisegundos \n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_insertion / 100, min_time_insertion, max_time_insertion);
    printf("Quick Sort\n - Tiempo Promedio: %f milisegundos\n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_quick / 100, min_time_quick, max_time_quick);
    printf("Bubble Sort\n - Tiempo Promedio: %f milisegundos\n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_bubble / 100, min_time_bubble, max_time_bubble);

    return 0;
}

