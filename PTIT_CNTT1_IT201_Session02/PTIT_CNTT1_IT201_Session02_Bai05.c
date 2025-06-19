//
// Created by FPT on 6/19/2025.
//
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("moi nhap so luong pt: ");
    scanf("%d",&n);
    if (1>n>=100) {
        printf("sai cu pham");
        return 1;
    }
    int *arr= (int*)malloc(n * sizeof(int));
    if (arr==NULL) {
        printf("ko du bo nho");
        return 1;
    }
    printf("moi nhap cac ptu\n ");
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    int pos;
    printf("moi nhap vi tri can xoá 0 - %d : ",n);
    scanf("%d",&pos);
    if (0>=pos>=n) {
        printf("sai cu pham");
        free(arr);
        return 1;
    }
    for (int i=pos;i<n-1;i++) {
        arr[i] = arr[i+1];
    }
    n--;
    printf("mang sau khi xoa: ");
    for (int i=0;i<n;i++) {
        printf("%d",arr[i]);
        if (i!=n-1) {
            printf(" ,");
        }
    }
    printf("\n");
    free(arr);




    return 0;
}