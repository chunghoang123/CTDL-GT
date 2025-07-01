//
// Created by FPT on 7/1/2025.
//
#include <stdio.h>
void insertion(int arr[],int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("nhap arr[%d]: ", i);
        scanf("%d ", &arr[i]);
    }
    insertion(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d",arr[i]);
    }




    return 0;
}