//
// Created by FPT on 6/30/2025.
//
#include <stdio.h>

void insertion_sort(int arr[],int n) {
    int last =  arr[n-1];
    int j =n - 2;
    while (j >= 0 && arr[j] > last) {
        arr[j+1] = arr[j];
        j--;
    }
    arr[j+1] = last;
}
void print_selection_sort(int arr[],int n) {
    if (n <= 1) {
        return;
    }
    print_selection_sort(arr, n-1);

    insertion_sort(arr, n);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    print_selection_sort(arr, n);

    printf("mang dc sap xep");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");


    return 0;
}