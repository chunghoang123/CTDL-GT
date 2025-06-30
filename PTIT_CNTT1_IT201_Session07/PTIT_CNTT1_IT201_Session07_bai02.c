//
// Created by FPT on 6/30/2025.
//
#include<stdio.h>

void selection_sort(int arr[],int start, int n) {
    if(start > n -1) return;
    int min = start;
    for(int i = start + 1; i < n; i++) {
        if(arr[i] < arr[min]) {
            min = i;
        }
    }
    if(min != start) {
        int temp = arr[min];
        arr[min] = arr[start];
        arr[start] = temp;
    }
    selection_sort(arr, start + 1, n);

}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, 0, n);
    printf("mang da sap xep");
    for (int i = 0; i < n; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");



    return 0;
}