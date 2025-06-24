//
// Created by FPT on 6/20/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("moi nhap so luong ptu: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("so luong pt ko hop le\n");
        return 0;
    }
    int *arr = malloc(sizeof(int) * n);
    if (arr == NULL) {
        return 1;
    }
    printf("moi nhap cac ptu");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    int count =0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            count++;
            sum += arr[i];
        }

    }
    int average = sum / count;
    printf("average = %d", average);
    free(arr);


    return 0;
}