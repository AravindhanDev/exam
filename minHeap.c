#include "stdio.h"

int size = 0;
void swap(int*, int*);
void heapify(int*, int, int);
void insert(int*, int);
void delete(int*, int);
void printHeap(int*, int);

int main() {
    int array[10];

    insert(array, 3);
    insert(array, 4);
    insert(array, 9);
    insert(array, 5);
    insert(array, 2);

    printf("Min-Heap array: ");
    printHeap(array, size);

    delete(array, 4);

    printf("After deleting an element: ");

    printHeap(array, size);
}

void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int* array, int size, int i) {
    if (size == 1) {
        printf("One element in the heap");
        return;
    }
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] < array[smallest]) {
        smallest = l;
    }
    if (r <  size && array[r] < array[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(&array[i], &array[smallest]);
        heapify(array, size, smallest);
    }
}

void insert(int* array, int value) {
    if (size == 0) {
        array[0] = value;
        size++;
    } else {
        array[size] = value;
        size++;
        for (int i = size / 2 - 1; i >= 0; i--) {
            heapify(array, size, i);
        }
    }
}

void delete(int* array, int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (array[i] == value) {
            index = i;
            break;
        }
    }
    swap(&array[index], &array[size-1]);
    size--;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }   
}

void printHeap(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}