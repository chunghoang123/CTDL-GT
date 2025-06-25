//
// Created by FPT on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luong ptu: ");
    scanf("%d", &n);
    int *arr = (int*)calloc(n, sizeof(int));
    printf("nhap phan tu: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i );
        scanf("%d",& arr[i]);
    }
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == min) {
            printf("%d",i);

        }
    }


free(arr);


    return 0;
}