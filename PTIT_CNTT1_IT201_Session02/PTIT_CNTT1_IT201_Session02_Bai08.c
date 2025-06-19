//
// Created by FPT on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n ;
    printf("moi nhap so luong ptu:");
    scanf("%d",&n);
    if (1>n>=100) {
        printf("sai cu phap");
        return 1;
    }
    int *arr = (int *)malloc(n*sizeof(int));
    if (arr==NULL) {
        printf("ko du bo nho\n");
        return 1;
    }
    printf("moi nhap cac ptu trong mang");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
   int first = 1;
    for (int i = 0; i < n; i++) {
        int min = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i]<=arr[j]) {
                min = 0;
                break;
            }
        }
        if (min) {
            if (!first) printf(" ,");
                printf("%d ",arr[i]);
                first = 0;

        }
    }
    printf("\n");
    free(arr);

    return 0;
}