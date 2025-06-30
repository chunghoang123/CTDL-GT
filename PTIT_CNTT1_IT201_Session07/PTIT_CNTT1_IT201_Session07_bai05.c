//
// Created by FPT on 6/30/2025.
//
#include  <stdio.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int l,int r) {
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}


void quicksort(int a[], int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quicksort(a, l, pi-1);
        quicksort(a, pi+1, r);
    }
}

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");








    return 0;
}
