//
// Created by FPT on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>


int main () {
    int n;
    printf("moi nhap so luong ptu: ");
    scanf("%d", &n);


    if (n == -1) {
        printf("So phan tu phan ko dc am\n");
    }else if (n == 0) {
        printf("So phan tu phai lon hon 0\n");
        return 0;
    }
    int *arr = (int*)malloc(n*sizeof(int));
    if (arr==NULL) {
        return 1;
    }
    printf("moi nhap cac luong ptu: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("max = %d",max);
    free(arr);

    return 0;
}