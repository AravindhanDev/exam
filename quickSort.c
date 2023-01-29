#include "stdio.h"

void swap(int* array, int a, int b) {
    int temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

int partition(int* array, int lb, int ub) {
    int pivot = array[lb];
    int start = lb;
    int end = ub;

    while (start < end) {
        while (array[start] <= pivot) {
            start++;
        }
        while (array[end] > pivot) {
            end--;
        }
        if (start < end) {
            swap(array, start, end);
        }
    }
    swap(array, lb, end);
    return end;
}

void quickSort(int* array, int lb, int ub) {
    if (lb < ub) {
        int loc = partition(array, lb, ub);
        quickSort(array, lb, loc - 1);
        quickSort(array, loc + 1, ub);
    }
}

void main() {
    int array[9] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(array) / sizeof(int);
    quickSort(array, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
}