#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10000


void printData(int datt[], int size) {
    int a;
    for (a = 0; a < size; a++) {
        printf("%d ", datt[a]);
    }
    printf("\n");
}


void insertionSort(int datt[], int n) {
    int a, key, b;
    for (a = 1; a < n; a++) {
        key = datt[a];
        b = a - 1;

        while (b >= 0 && datt[b] > key) {
            datt[b + 1] = datt[b];
            b = b - 1;
        }
        datt[b + 1] = key;
    }
}


void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int datt[], int low, int high) {
    int pivot = datt[high];
    int a = (low - 1);
    int b;
    for (b = low; b <= high - 1; b++) {
        if (datt[b] < pivot) {
            a++;
            swap(&datt[a], &datt[b]);
        }
    }
    swap(&datt[a + 1], &datt[high]);
    return (a + 1);
}

void quickSort(int datt[], int low, int high) {
    if (low < high) {
        int pi = partition(datt, low, high);
        quickSort(datt, low, pi - 1);
        quickSort(datt, pi + 1, high);
    }
}


void bubbleSort(int datt[], int n) {
    int a, b;
    for (a = 0; a < n - 1; a++)
        for (b = 0; b < n - a - 1; b++)
            if (datt[b] > datt[b + 1])
                swap(&datt[b], &datt[b + 1]);
}

int main() {
    srand(time(NULL));
    int size = 10000;
    int a, b;

    int datt[size];
    for (a = 0; a < size; a++) {
        datt[a] = rand() % 100;
    }
    double total_time_insertion = 0.0, total_time_quick = 0.0, total_time_bubble = 0.0;
    double min_time_insertion = 1e9, min_time_quick = 1e9, min_time_bubble = 1e9;
    double max_time_insertion = 0.0, max_time_quick = 0.0, max_time_bubble = 0.0;

    clock_t start, end;
    double cpu_time_used;

    
    for (a = 0; a < 100; a++) {
        int tempdatt[size];
        for (b = 0; b < size; b++) {
            tempdatt[b] = datt[b];
        }

        start = clock();
        insertionSort(tempdatt, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        total_time_insertion += cpu_time_used;
        if (cpu_time_used < min_time_insertion) min_time_insertion = cpu_time_used;
        if (cpu_time_used > max_time_insertion) max_time_insertion = cpu_time_used;
        printf("Insertion Sort - Tiempo de ejecucion %d: %f milisegundos\n", a + 1, cpu_time_used);
    }


    for (a = 0; a < 100; a++) {
        int tempdatt[size];
        for (b = 0; b < size; b++) {
            tempdatt[b] = datt[b];
        }

        start = clock();
        quickSort(tempdatt, 0, size - 1);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
        total_time_quick += cpu_time_used;
        if (cpu_time_used < min_time_quick) min_time_quick = cpu_time_used;
        if (cpu_time_used > max_time_quick) max_time_quick = cpu_time_used;
        printf("Quick Sort - Tiempo de ejecucion %d: %f milisegundos\n", a + 1, cpu_time_used);
    }

   
    for (a = 0; a < 100; a++) {
        int tempdatt[size];
        for (b = 0; b < size; b++) {
            tempdatt[b] = datt[b];
        }

        start = clock();
        bubbleSort(tempdatt, size);
        end = clock();

        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

        total_time_bubble += cpu_time_used;
        if (cpu_time_used < min_time_bubble) min_time_bubble = cpu_time_used;
        if (cpu_time_used > max_time_bubble) max_time_bubble = cpu_time_used;
        printf("Bubble Sort - Tiempo %d: %f milisegundos\n", a + 1, cpu_time_used);
    }
     printf("\n\n--- Estadisticas Resumidas ---\n");
    printf("Insertion Sort\n - Tiempo Promedio: %f milisegundos \n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n ",
           total_time_insertion / 100, min_time_insertion, max_time_insertion);
    printf("Quick Sort\n - Tiempo Promedio: %f milisegundos\n - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n ",
           total_time_quick / 100, min_time_quick, max_time_quick);
    printf("Bubble Sort\n - Tiempo Promedio: %f milisegundos\n  - Tiempo Minimo: %f milisegundos\n - Tiempo Maximo: %f milisegundos\n",
           total_time_bubble / 100, min_time_bubble, max_time_bubble);

    return 0;
}

