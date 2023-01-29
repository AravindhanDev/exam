#include "stdio.h"

int size = 6;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int* array, int size, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest]) {
        largest = l;
    }
    if (r < size && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(array, size, largest);
    }
} 

void heapSort(int* array) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(array, size, i);
    }  
    for (int i = size - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}

void printHeap(int* arr) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void main() {
    int arr[] = {1, 12, 9, 5, 6, 10};
  
    heapSort(arr);
  
    printf("Sorted array is \n");
    printHeap(arr);
}