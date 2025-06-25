//
// Created by FPT on 6/25/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("nhap so luon pt: ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));

    printf("nhap pt: ");
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    int number;
    printf("nhap gt can tim: ");
    scanf("%d", &number);
    for (int i = n; i>0 ; i--) {
        if (arr[i]==number) {
            printf("vi tri %d",i);
            break;
        }

    }


free(arr);


    return 0;
}